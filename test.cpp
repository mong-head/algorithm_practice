#include <iostream>
using namespace std;

int main()
{
  int st[4];
  fill_n(st,4,1);
  for(int i : st) cout << i <<' ';

  return 0;
}
