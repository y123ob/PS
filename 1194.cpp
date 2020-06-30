#include <stdlib.h>
#include <stack>
#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>

#define MAX 50

using namespace std;

char MAP[MAX][MAX];
bool visit[MAX][MAX][1<<6];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int N,M;

pair<int, int> st;
vector<pair<int, int>> ed;

void input(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
    {
        string inp; cin >> inp;
        for(int j=0; j<M; j++)
        {
            MAP[i][j] = inp[j];
            if(MAP[i][j] == '0')
            {
                st.first = i;
                st.second = j;
                MAP[i][j] = '.';
            }
            else if(MAP[i][j] == '1')
            {
                ed.push_back(make_pair(i,j));
            }
        }
    }
}

bool CanPassDoor(int key_bit, char door)
{
    //printf("%d %c %d %d\n",key_bit,door, (1<<(int(door) - 'A')) , key_bit & (1<<(int(door) - 'A')));
    return (key_bit & (1<<(int(door) - 'A'))) != 0;
}

bool fair(int x, int y)
{
    if(x >= 0 && y >= 0 && x < N && y < M)
        return true;
    return false;
}

int BFS()
{
    // x, y, dist, key
    queue< pair< pair<int,int>, pair<int,int>>> Q;
    Q.push(make_pair( make_pair(st.first, st.second) ,make_pair(0, 0)));
    visit[st.first][st.second][0] = true;
    
    while(!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int dist = Q.front().second.first;
        int key = Q.front().second.second;
        Q.pop();
        //printf("%d %d %d %d\n",x,y,dist,key);

        if(MAP[x][y] == '1') return dist;

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(fair(nx, ny))
            {
                if(visit[nx][ny][key] == false)
                {
                    switch(MAP[nx][ny])
                    {
                        case '.' :
                        case '1' :
                            Q.push(make_pair(make_pair(nx,ny), make_pair(dist+1, key)));
                            visit[nx][ny][key] = true;
                            break;
                        case 'a'...'f' :
                            Q.push(make_pair(make_pair(nx,ny), make_pair(dist+1, key | (1<<(int(MAP[nx][ny])-'a')))));
                            visit[nx][ny][key | (1<<(int(MAP[nx][ny])-'a'))] = true;
                            break;
                        case 'A'...'F' :
                            if(CanPassDoor(key, MAP[nx][ny]))
                            {
                                Q.push(make_pair(make_pair(nx,ny), make_pair(dist+1, key)));
                                visit[nx][ny][key] = true;
                            }
                            break;
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    input();
    int ans = BFS();
    printf("%d",ans);

}