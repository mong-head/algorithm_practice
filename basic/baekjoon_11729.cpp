#include <stdio.h>
#include <cmath>
using namespace std;

void hanoi(int N, int start, int end, int by);
int main()
{
  int N;
  scanf("%d",&N);
  printf("%d\n", (int)pow(2,N)-1);
  hanoi(N,1,3,2);

  return 0;
}
void hanoi(int N, int start, int end, int by)
{
  if(N == 1){
    printf("%d %d\n",start,end);
    return;
  }

  hanoi(N-1,start,by,end);
  printf("%d %d\n",start,end); //N을 start에서 end로 옮긴 것.
  hanoi(N-1,by,end,start);
}
