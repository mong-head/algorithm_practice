#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector<int> u={1};
  if(u.front()==1) cout << u.front()<<endl;
  else cout <<'n';

  u.erase(u.begin());

  cout << *u.begin()<<endl;
  // if(u[0]==1) cout << u[0]<<endl;
  // else cout <<'n';
  //
  // cout <<u.front();
  // u.erase(u.begin());
  // if(u.front()==1) cout << "y";
  // else cout <<'n';


  return 0;
}
