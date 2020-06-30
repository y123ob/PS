#include <stdlib.h>
#include <stack>
#include <stdio.h>

using namespace std;


int main()
{

    int i,j;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        scanf("%lld",&hist[i]);
    }
    
    long long int ans = 0, top = 0, stk[101010][2];

    stk[0][0] = 0, stk[0][1] = 1;

    for(i = 1; i <= N+1; i++)
    {
        int width = 1;
        while(top >= 0 && stk[top][0] > hist[i])
        {
            //printf("%d %d %d\n",top, stk[top][0], stk[top][1]);
            ans = max(ans, stk[top][0] * (stk[top][1] + width - 1));
            width += stk[top][1];
            top--;
        }


        if(stk[top][0] == hist[i])
        {
            stk[top][1] += width;
        }
        else if(stk[top][0] < hist[i])
        {
            stk[++top][0] = hist[i];
            stk[top][1] = width;
        }
    }
    

    printf("%d",ans);

}