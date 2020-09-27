#include <iostream>

using namespace std;

int main()
{
  int box = 0;
  int N;
  cin >> N;

  while(N > 0)
  {
    if(N%5 == 0)
    {
      box += N/5;
      break;
    }
    N -= 3;
    box += 1;
  }

  if(N < 0) box = -1;
  cout << box;
  return 0;
}

//참고 : https://gabii.tistory.com/entry/BaekJoonC-%EB%B0%B1%EC%A4%80-2839%EB%B2%88-%EC%84%A4%ED%83%95%EB%B0%B0%EB%8B%AC
