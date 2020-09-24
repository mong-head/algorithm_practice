#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <queue>

using namespace std;

void dfs(int start, vector<int>* g, bool* visit);
void bfs(int start, vector<int>* g, bool* visit);

int main()
{
  //N : 정점 개수
  //M : 간선 개수
  //V : 탐색 시작 번호
  int N, M, V;

  cin >> N >> M >> V;
  V -= 1;

  //노드 방문 확인용
  bool visit_dfs[N] = {false};
  bool visit_bfs[N] = {false};

  //graph 만들기 - link로
  vector<int> graph[N+1];

  for(int i=0;i<M;i++)
  {
    int u,v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  //문제 제시 조건 중 다중 연결이면 가장 작은 수부터 방문이라해서 정렬함
  for(int i=0;i<=N;i++)
  {
    sort(graph[i].begin(),graph[i].end());
  }

  dfs(V,graph,visit_dfs);
  cout << '\n';

  bfs(V,graph,visit_bfs);

  return 0;
}

void dfs(int start, vector<int>* g, bool* visit )
{
  if(visit[start]) return;

  visit[start] = true;
  cout << start+1<<' ';

  for(int i=0;i< g[start].size(); i++)
  {
    int next = g[start][i]; //인접 먼저 : 정렬되어서 작은 수부터 됨
    dfs(next,g,visit);
  }
}

void bfs(int start, vector<int>* g, bool* visit)
{
  queue<int> q;

  q.push(start);
  visit[start] = true;

  while(!q.empty()){
    int tmp = q.front();
    q.pop();
    cout << tmp+1<<' ';
    for(int i=0; i<g[tmp].size();i++)
    {
      //not visit
      if(visit[g[tmp][i]] == false)
      {
        //queue에 넣고 방문했음으로 표시
        q.push(g[tmp][i]);
        visit[g[tmp][i]] = true;
      }
    }
  }
}
