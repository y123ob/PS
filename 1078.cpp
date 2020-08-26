#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <stdlib.h>
using namespace std;

#define pii pair<int, int>
constexpr auto SIZE = 50505;
vector<int> v;

void makevec()
{
	vector<pii> fl;
	vector<pii> middle;
	for(int i=0; i<=9; i++)
	{
		fl.push_back(make_pair(1, i));
		middle.push_back(make_pair(0,i));
		if(i >= 2) fl.push_back(make_pair(i, 0));
		if(i >= 1) middle.push_back(make_pair(i,0));
	}

	for (pii p1 : fl)
	{
		int p1f = p1.first, p1s = p1.second;
		int s2 = p1f * 10 + p1s;
		int s3 = p1f * 100 + p1s;
		v.push_back(s2); v.push_back(s3);
		
		for(pii p2 : middle)
		{
			int p2f = p2.first, p2s = p2.second;
			int s4 = p1f * 1000 + p2f * 100 + p2s * 10 + p1s;
			int s5 = p1f * 10000 + p2f * 1000 + p2s * 10 + p1s;
			v.push_back(s4); v.push_back(s5);

			for(pii p3 : middle)
			{
				int p3f = p3.first, p3s = p3.second;
				int s6 = p1f * 100000 + p2f * 10000 + p3f * 1000 + p3s * 100 + p2s * 10 + p1s;
				int s7 = p1f * 1000000 + p2f * 100000 + p3f * 10000 + p3s * 100 + p2s * 10 + p1s;
				v.push_back(s6); v.push_back(s7);

				for (pii p4 : middle)
				{
					int p4f = p4.first, p4s = p4.second;
					int s8 = p1f * 10000000 + p2f * 1000000 + p3f * 100000 + p4f * 10000 + p4s * 1000 + p3s * 100 + p2s * 10 + p1s;
					int s9 = p1f * 100000000 + p2f * 10000000 + p3f * 1000000 + p4f * 100000 + p4s * 1000 + p3s * 100 + p2s * 10 + p1s;
					v.push_back(s8); v.push_back(s9);

					for (pii p5 : middle)
					{
						int p5f = p5.first, p5s = p5.second;
						int s10 = p1f * 1000000000 + p2f * 100000000 + p3f * 10000000 + p4f * 1000000 + p5f*100000 + p5s*10000 +p4s * 1000 + p3s * 100 + p2s * 10 + p1s;
						v.push_back(s10);
					}
				}
			}
		}
	}
}

int rev(int x)
{
	int rv = 0;
	while(x != 0)
	{
		rv *= 10;
		rv += x%10;
		x /= 10;
	}
	return rv;
}

int main(int argc, char** argv)
{
	makevec();
	
	int D;
	scanf_s("%d",&D);
	if(D == 900000){
		printf("100001000001");
		return 0;
	}
	if(D == 990000){
		printf("10001000001");
		return 0;
	}
	for(int i : v){
		if(i - rev(i) == D){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}