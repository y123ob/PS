#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX 4040404


int N;
int isprime[MAX];
long long primesum[MAX];
int prime_cnt;

void get_prime(){
    for(int i=2; i<MAX; i++){
        if(isprime[i] == -1) continue;
        isprime[i] = 1;
        
        prime_cnt ++;
        primesum[prime_cnt] = primesum[prime_cnt-1] + i;

        for(int j=i ; (long long)j*i < MAX; j++){
            isprime[i * j] = -1;
        }
    }
}

int solve()
{
    int left = 0, right = 1, ans = 0;
    while(right <= prime_cnt){
        if(primesum[right] - primesum[left] == N) ans++;
        if(primesum[right] - primesum[left] < N) right ++;
        else left ++;
    }
    return ans;
}

int main()
{
    
    scanf("%d",&N);
    get_prime();
    printf("%d\n", solve());

}