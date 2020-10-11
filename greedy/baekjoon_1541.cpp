#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(){
  string expression;
  cin >> expression;

  bool op = false; // +있을때까지
  int sum = 0;
  string num;
  for(auto& ex : expression){
    if(isdigit(ex)) num+=ex;
    else{
      int now = stoi(num);
      num = "";
      switch(op){
        case false :
          sum += now;
          break;
        case true :
          sum -= now;
          break;
      }
      if(ex == '-') op = true;
    }
  }

  cout << sum;

  return 0;
}
