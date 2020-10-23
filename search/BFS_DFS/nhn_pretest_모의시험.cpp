#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
int visited[11][11];
int dir[2][4] = {{0,0,1,-1},{-1,1,0,0}};
int size_;
void dfs(int x,int y, int** matrix,int sizeOfMatrix){
	size_++;
	visited[x][y]=1;
	int next_x,next_y;
	for(int i=0;i<4;i++){
		next_x = x+dir[0][i];
		next_y = y+dir[1][i];
		if(-1<next_x&&next_x<sizeOfMatrix && -1<next_y&&next_y<sizeOfMatrix){
			if(!visited[next_x][next_y] && matrix[next_x][next_y]){
				dfs(next_x,next_y,matrix,sizeOfMatrix);
			}
		}
	}
}
void solution(int sizeOfMatrix, int **matrix) {
	int domain_num = 0;
	vector<int> sizes;
  for(int i=0;i<sizeOfMatrix;i++){
		for(int j=0;j<sizeOfMatrix;j++){
			if(matrix[i][j] && !visited[i][j]){
				size_ = 0;
				dfs(i,j,matrix,sizeOfMatrix);
				domain_num++;
				sizes.push_back(size_);
			}
			visited[i][j] = 1;
		}
	}
	sort(sizes.begin(),sizes.end());
	cout << domain_num <<endl;
	for(auto& s : sizes){
		cout << s << ' ';
	}
}

struct input_data {
  int sizeOfMatrix;
  int **matrix;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.sizeOfMatrix;

  inputData.matrix = new int*[inputData.sizeOfMatrix];
  for (int i = 0; i < inputData.sizeOfMatrix; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.matrix[i] = new int[inputData.sizeOfMatrix];
    for (int j = 0; j < inputData.sizeOfMatrix; j++) {
      iss >> inputData.matrix[i][j];
    }
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.sizeOfMatrix, inputData.matrix);
  return 0;
}
