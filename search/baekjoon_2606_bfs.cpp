#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int bfs(int start, vector<int>* graph,bool* visit);
int main()
{
  // N : the number of computers
  // M : the number of links
  int N,M;
  cin >> N >> M;

  //문제에서 주어진대로 node번호 0부터아니라 1부터하기 위함
  bool visit[N+1] = {false};
  vector<int> graph[N+1];

  for(int i=0;i<M;i++)
  {
    int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i=1;i<=N;i++)
  {
    sort(graph[i].begin(),graph[i].end());
  }

  //node 1에서 시작
  cout << bfs(1,graph,visit);

  return 0;
}

int bfs(int start, vector<int>* graph,bool* visit)
{
  queue<int> q;
  int virus = -1;
  q.push(start);
  visit[start] = true;

  while(!q.empty())
  {
    int tmp = q.front();
    q.pop();
    virus++;
    for(int i=0;i<graph[tmp].size();i++)
    {
      if(visit[graph[tmp][i]] == false)
      {
        q.push(graph[tmp][i]);
        visit[graph[tmp][i]] = true;
      }
    }
  }
  return virus;
}
