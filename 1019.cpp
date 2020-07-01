#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int N;
int ans[10];

void CountForm(int hd, int exp)
{
    //printf("%d %d\n",hd, exp);
    // [hd * 10**exp , hd+1 * 10**exp)
    int size = pow(10, exp);
    if(exp != 0)
    {
        for(int i=0; i<10; i++)
        {
            ans[i] += exp * int(pow(10, exp-1));
        }
        if(hd == 0)
        {
            for(int i=0; i<=exp; i++)
            {
                ans[0] -= (exp - i) * (int(pow(10, i)) - int(pow(10,i-1)));
            }
        }    

        
    }

    if(hd != 0)
    {
        for(int i = hd; i>0; i/=10)
        {
            ans[i%10] += int(pow(10,exp));
        }   
    }
}

void input()
{
    scanf("%d",&N);
}

void solve()
{
    int n = N, exp = 0 , pow = 1;
    CountForm(n,0);
    while(n > 0)
    {
        while(n % (10 * pow) != 0)
        {
            CountForm(n/pow-1 , exp);
            n -= pow;
        }
        exp += 1;
        pow *= 10;
    }

    for(int i=0; i<10; i++)
    {
        printf("%d ",ans[i]);
    }
}

int main(){
    
    input();
    solve();

}