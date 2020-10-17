#include <iostream>
#include <vector>
#include <string>
using namespace std;

class parent{
public:
  void one(){
    cout << 1 ;
    two();
  }
  void two(){
    cout << 2;
  }
}
class child : public  parent{
public:
  void one(){
    cout << 3;
  }
  void two(){
    cout <<4;
  }
}
int main()
{
  child a = new child;

  return 0;
}
