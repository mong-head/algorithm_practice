#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count = 0;
void sequence(int idx,int* list,int n, int m);
int main(){

  int n,m;
  cin >> n >> m;

  int list[n];
  for(int i=1;i<=n;i++) list[i-1] = i;
  sequence(0,list,n,m);

  return 0;
}

void sequence(int idx,int* list,int n, int m){
  if(idx >= n || count >= m){
    cout << endl;
    return;
  }
  if(list[idx] && count < m){
    cout << list[idx] << ' ';
    list[idx] = 0;
    count++;
    sequence(idx+1,list,m,n);
  }
}
