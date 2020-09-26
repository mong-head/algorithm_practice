#include <iostream>

using namespace std;

int main()
{
        int N; //집의 수

        cin >> N;
        int cost[N+1][3]; //각각의 집 칠하는 비용 [집비용][r,g,b]
        int sub[N+1][3]; //전의 집 칠하는 비용 ~ 현재 집 비용

        for(int i=1; i<N+1; i++)
        {
                for(int j=0; j<3; j++)
                {
                        cin >> cost[i][j];
                }
        }
        for(int i=0;i<3;i++)
        {
          cost[0][i] = 0;
          sub[0][i] = 0;
        }

        for(int i=1; i<N+1; i++)
        {
                sub[i][0] = min(sub[i-1][1], sub[i-1][2])+cost[i][0];
                sub[i][1] = min(sub[i-1][0], sub[i-1][2])+cost[i][1];
                sub[i][2] = min(sub[i-1][0], sub[i-1][1])+cost[i][2];
        }

        int result = min(min(sub[N][0],sub[N][1]),sub[N][2]);

        cout <<result;

        return 0;
}
