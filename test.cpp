#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string s = "a123";
  for(auto& s : s){
    cout << s<<endl;
  }

  return 0;
}
