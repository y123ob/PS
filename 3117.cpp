#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
//#include <stdlib.h>

constexpr auto SIZE = 101010;
constexpr auto MAXLEN = 30;

int sparse_table[SIZE][MAXLEN];
int first[SIZE];
int N, M, K;

void fill_sparse()
{
	for(int i=1; i < MAXLEN; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			sparse_table[j][i] = sparse_table[ sparse_table[j][i-1] ][i-1];
		}
	}
}

int query(int start, int step)
{
	if(step == 0) return start;
	int msb = (int)log2(step);
	return query(sparse_table[start][msb], step - (1<<msb));
}

int main()
{
	scanf_s("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; i++) scanf_s("%d", &first[i]);
	for(int i = 1; i <= M; i++) scanf_s("%d", &sparse_table[i]);
	fill_sparse();
	for(int i = 0; i < N; i++) printf("%d ",query(first[i], K-1));

	return 0;
}
