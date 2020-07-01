#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define MAX 101010

int blk = (int)(pow(2,ceil(log2(MAX))));

int G,P;
int arrive[MAX * 4];


void settree(int size)
{
    for(int i=0; i<=size; i++)
    {
        arrive[blk + i] = i;
    }
    for(int i=blk-1; i>0; i--)
    {
        arrive[i] = max(arrive[2*i], arrive[2*i+1]);
    }
}

int search(int x, int root, int st, int ed)
{
    if(st>=ed) return 0;
    if(x < st) return 0;
    if(x >= ed) return arrive[root];
    if(st+1 == ed) return arrive[root]; 
    return max(search(x, root*2, st, (st+ed)/2),
                search(x, root*2+1, (st+ed)/2, ed));   
}

void update(int x)
{
    int idx = blk + x;
    arrive[idx] = 0;
    idx /= 2;
    while(idx > 0)
    {
        arrive[idx] = max(arrive[idx*2] , arrive[idx*2+1]);
        idx /= 2;
    }

}

void solve()
{
    scanf("%d %d",&G,&P);
    settree(G);
    int ans = 0;
    for(int i=0; i<P; i++)
    {
        int x,y;
        scanf("%d", &x);
        y = search(x, 1, 0, blk);
        if(y > 0)
        {
            update(y);
            ans ++;
        }
        else break;
    }
    printf("%d",ans);
}

int main(){
    
    solve();

}