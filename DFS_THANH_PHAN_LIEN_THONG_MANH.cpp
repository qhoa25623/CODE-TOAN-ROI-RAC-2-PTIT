#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, m, s;
vector<int> ke[1005];
bool visited[1005];

void DFS(int u)
{
  visited[u] = 1;
  sort(ke[u].begin(), ke[u].end());
  for(int v : ke[u])
  {
    if(!visited[v])
    {
      cout << u << "->" << v << endl;
      DFS(v);
    }
  }
}

int main(int argc, char **argv)
{
  cin >> n >> m;
  for(int i = 1; i <= m; ++i)
  {
    int x, y; cin >> x >> y; 
    ke[x].push_back(y);
  }
  for(int i = 1; i <= n; ++i)
  {
    memset(visited, 0, sizeof(visited));
    cout << endl << i << endl;
    DFS(i);
    cout << endl;
  }
}