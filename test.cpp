#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int a = 100;
  char c = 'z';
  switch(a/10){
    case 10:
    case 9: c = 'A';
    case 8 : c = "B";
    default c = "F";
  }
  c

  return 0;
}
