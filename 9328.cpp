#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define MAX 110

int TC, N, M;
char board[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int key, ans;

void input()
{
    scanf("%d",&TC);
}

void input_TC()
{
    scanf("%d %d",&N,&M);
    for(int i=0; i<=M+1; i++)
    {
        board[0][i] = '.';
        board[N+1][i] = '.';
    }
    for(int i=0; i<N; i++)
    {
        string in; cin >> in;
        board[i+1][0] = '.';
        for(int j=0; j<M; j++)
        {
            board[i+1][j+1] = in[j];
        }
        board[i+1][M+1] = '.';
    }
    string in_key; cin >> in_key;
    key = 0;
    if(in_key[0] == '0') return;
    for(int i=0; in_key[i]!='\0'; i++)
    {
        key = key | (1 << (in_key[i] - 'a'));
    }
}

void CleanVisit()
{
    for(int i=0; i<=N+1; i++)
        for(int j=0; j<=M+1; j++)
            visit[i][j] = false;
}


bool CanPassDoor(char door)
{
    return (key & (1<<(door - 'A'))) != 0;
}
bool ValidRange(int x, int y)
{
    return (x>=0) && (y>=0) && (x<=N+1) && (y<=M+1);
}

void DFS(int x, int y)
{
    if(visit[x][y] == true)
        return;
    
    if(board[x][y] == '*') return;
    else if(board[x][y] == '.')
    {
        visit[x][y] = true;
    }
    else if(board[x][y] == '$')
    {
        visit[x][y] = true;
        ans ++;
    }
    else if('a' <= board[x][y] && board[x][y] <= 'z')
    {
        visit[x][y] = true;
        int nextkey = key | (1<<(board[x][y]-'a'));
        if(nextkey != key)
        {
            key = nextkey;
            for(int i=0; i<=N+1; i++)
            {
                for(int j=0; j<=M+1; j++)
                {
                    if(board[i][j] == board[x][y] + 'A' - 'a')
                    {
                        for(int k=0; k<4; k++)
                        {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if(visit[ni][nj] == true)
                            {
                                if(visit[i][j] == false)
                                {
                                    DFS(i,j);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if('A' <= board[x][y] && board[x][y] <= 'Z')
    {
        if(CanPassDoor(board[x][y]))
        {
            visit[x][y] = true;
        }
        else
        {
            return;
        }
    }


    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ValidRange(nx, ny))
            DFS(nx, ny);
    }
}

void solve_TC()
{
    ans = 0;
    DFS(0,0);
    printf("%d\n",ans);
}

void solve()
{
    for(int i=0; i<TC; i++)
    {
        input_TC();
        CleanVisit();
        solve_TC();
    }
}

int main(){
    
    input();
    solve();

}