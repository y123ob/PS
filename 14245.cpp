#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
//#include <stdlib.h>

constexpr auto SIZE = 505050;

int value[SIZE];
int lazy[4 * SIZE];

void update(int root, int L, int R, int st, int ed, int value)
{
	//printf("%d %d %d %d %d %d   %d\n", root, L, R, st, ed, value, lazy[root]);
	if(R <= st || ed <= L) return;
	if(st <= L && R <= ed){
		lazy[root] ^= value;
		return;
	}
	int mid = (L + R) / 2;
	update(root * 2, L, mid, st, ed, value);
	update(root * 2 + 1, mid, R, st, ed, value);
}

void query(int root, int L, int R, int target)
{
	//printf("%d %d %d %d   %d\n",root, L, R, target,lazy[root]);
	if(target < L || R <= target) return;
	if(L + 1 == R)
	{
		value[target] ^= lazy[root];
		lazy[root] = 0;
		return;
	}
	int mid = (L + R) / 2;
	if(target < mid)
	{
		lazy[root * 2] ^= lazy[root];
		lazy[root * 2 + 1] ^= lazy[root];
		query(root * 2, L, mid, target);
		lazy[root] = 0;
	}
	else
	{
		lazy[root * 2] ^= lazy[root];
		lazy[root * 2 + 1] ^= lazy[root];
		query(root * 2 + 1, mid, R, target);
		lazy[root] = 0;
	}
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&value[i]);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int type;
		scanf("%d",&type);
		if(type == 1) // lazy
		{
			int st, ed, value;
			scanf("%d %d %d", &st, &ed, &value);
			update(1, 0, n, st, ed+1, value);
		}
		else // query
		{
			int target;
			scanf("%d", &target);
			query(1, 0, n, target);
			printf("%d\n",value[target]);
		}
		
	}

	return 0;
}
