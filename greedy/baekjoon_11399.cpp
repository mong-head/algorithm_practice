#include <iostream>
#include <stdlib.h>

using namespace std;

void quick_sort(int arr[], int size);

int main(){
  int N = 0;
  int sum = 0; // result

  cin >> N;
  //동적할당
  int* cost = new int[N];
  for(int i=0;i<N;i++)
  {
    cin >> cost[i];
  }

  quick_sort(cost,N);

  for(int i=0;i<N;i++)
  {
    sum += cost[i]*(N-i);
  }

  cout <<sum;

  delete[] cost;
  //system("pause > nul");
  return 0;
}

void quick_sort(int arr[], int size)
{
  int pivot = arr[0];
  int cursor = 0;

  for(int i=1;i<size;i++){
    if(pivot > arr[i]){
      cursor++;
      swap(arr[cursor],arr[i]);
    }
  }
  swap(arr[0], arr[cursor]);

  if(cursor > 0){
    quick_sort(arr, cursor);
  }

  if(cursor+1 < size-1){
    quick_sort(arr+cursor+1,size-cursor-1);
  }
}
