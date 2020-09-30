#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves);

int main()
{
        vector<vector<int> > board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
        vector<int> moves = {1,5,3,5,1,2,1,4};
        int answer = solution(board,moves);
        cout << answer;

        return 0;
}

int solution(vector<vector<int> > board, vector<int> moves) {
        int answer = 0;
        int board_size = board[0].size();

        vector<vector<int> > board_stack;
        vector<int> stack; //뽑아서 담는 stack

        for(int i=0; i<board_size; i++)
        {
                vector<int> temp;
                for(int j=board_size-1; j>-1; j--)
                {
                        if(board[j][i]) temp.push_back(board[j][i]);
                }
                board_stack.push_back(temp);
        }

        stack.push_back(-1);
        for(auto& e: moves)
        {
                int bs_top, s_top;
                if(board_stack[e-1].empty() == 0)
                {
                        bs_top = board_stack[e-1].back();
                        s_top = stack.back();

                        board_stack[e-1].pop_back();
                        if(bs_top == s_top)
                        {
                          answer += 2;
                          stack.pop_back();
                        }
                        else
                          stack.push_back(bs_top);
                }
        }
        return answer;
}
