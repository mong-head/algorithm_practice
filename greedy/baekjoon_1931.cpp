#include <iostream>
#include <algorithm>
using namespace std;

class Meeting{
public:
  int start_time;
  int end_time;
  Meeting(int start_time, int end_time){
    this->start_time = start_time;
    this->end_time = end_time;
  }
  Meeting(){
    start_time=end_time=0;
  }
  bool operator <(Meeting &m){
    if(this->end_time == m.end_time)
      return this->start_time < m.start_time;
    else
      return this->end_time < m.end_time;
  }
};

int main(){
  //inputs
  int n;
  cin >> n;
  Meeting meetings[n];
  for(int i=0;i<n;i++){
    cin >> meetings[i].start_time >> meetings[i].end_time;
  }

  sort(meetings,meetings+n);
  int end = 0;
  int num_meeting = 0;

  for(Meeting m : meetings){
    if(m.start_time>=end){
      end = m.end_time;
      num_meeting++;
    }
  }
  cout << num_meeting;
  return 0;
}
