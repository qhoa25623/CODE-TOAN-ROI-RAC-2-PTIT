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
  for (int v : ke[u])
  {
    if (!visited[v])
    {
      cout << v << "(" << u << ") ";
      DFS(v);
    }
  }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    int x, y; cin >> x >> y;
    ke[x].push_back(y);
    ke[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
  {
    if (!visited[i])
    {
      cout << endl;
      cout << i << endl;
      cout << i << "(0) ";
      DFS(i);
      cout << endl;
    }
  }
}