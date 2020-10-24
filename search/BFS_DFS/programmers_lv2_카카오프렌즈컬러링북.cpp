#include <vector>
#include <string.h>

using namespace std;

int visited[101][101];
int M,N;
int size_;

void dfs(int x, int y, long pic_n, vector<vector<int>>& picture){
    visited[x][y] = 1;
    int dir[2][4] = {{0,0,-1,1},{1,-1,0,0}};
    size_++;
    int next_x,next_y;
    for(int i=0;i<4;i++){
        next_x = x + dir[0][i];
        next_y = y + dir[1][i];
        if(-1<next_x&&next_x<M && -1<next_y&&next_y<N){
            if(!visited[next_x][next_y] && picture[next_x][next_y]==pic_n){
                dfs(next_x,next_y,pic_n,picture);
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M=m;
    N=n;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j] && !visited[i][j]){
                size_ = 0;
                dfs(i,j,picture[i][j],picture);
                number_of_area++;
                if(max_size_of_one_area < size_) max_size_of_one_area = size_;
            }
            visited[i][j] = 1;
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
