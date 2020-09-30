#include <iostream> &
#include <vector>
using namespace std;

void print_stack(const vector<int>& stack);
int main()
{
  vector<int> v;
  print_stack(v);
  v.push_back(-1);
  print_stack(v);
  return 0;
}
void print_stack(const vector<int>& stack)
{
  for(auto& e:stack) cout << e <<" ";
  cout << endl;
}
