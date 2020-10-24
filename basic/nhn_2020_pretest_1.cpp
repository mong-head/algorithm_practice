/*
<수건돌리기>
6명이 있을때, A,B,C,D,E,F 이 6명이서 수건돌리기게임함
이때, A는 항상 처음부터 술래이고, 처음 자리는 5명이서 B~F순서대로 시계방향으로 앉음
달리기가 빨라서 술래가 되지 않는 사람도 주어짐(namesofquickplayers)
각 사람마다 움직인 칸 수가 주어짐. 둥글게 앉아 있는데 그만큼 움직이면 됨.(-도 있음)
출력은 현재 앉아있는 사람순서대로 사람 이름과 술래 걸린 횟수.
마지막 출력은 현재 술래인 사람의 이름과 술래 걸린 횟수.

--> 주의해야 할 점 : 나는 배열을 사용하였는데, 배열의 크기가 넘어갈 때만 조심하면 된다.
*/

#include <iostream>
#include <sstream>

using namespace std;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	int num_play[numOfAllPlayers] = {0}; //각 사람마다 걸린 횟수 저장
	char position[numOfAllPlayers-1]; //게임테이블 위치
	for(int i=0;i<numOfAllPlayers;i++){
		position[i] = char('B'+i);
	}
	int flag = 0; // quick선수인지
	int position_player = 0; //B에서 시작, 현재 술래 위치
	char player = 'A';
	num_play[0] = 1; //A는 처음 술래
	for(int i=0;i<numOfGames;i++){
		flag = 0;
		int move = numOfMovesPerGame[i]%(numOfAllPlayers-1);
		position_player += move;
		if(position_player>0) position_player %= (numOfAllPlayers-1);
		else position_player += 16;
		int size_quick = sizeof(namesOfQuickPlayers);
		for(int j=0;j<size_quick;j++){
			if(position[position_player] == namesOfQuickPlayers[j]){
				flag = 1;
				num_play[player-'A']++;
			}
		}

		if(flag == 0){
			char tmp = player;
			player = position[position_player];
			position[position_player] = tmp;
			num_play[player-'A']++;
		}
	}

	//출력
	for(auto& participant : position){
		cout << participant << ' '<< num_play[participant-'A']<<endl;
	}
	cout << player << ' '<< num_play[player-'A']<<endl;
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}
