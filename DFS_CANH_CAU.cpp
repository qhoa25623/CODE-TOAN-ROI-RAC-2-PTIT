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
      cout << v << "(" << v << ") ";
      DFS(v);
    }
  }
}

void DFS2(int u, int s, int t)
{
  visited[u] = 1;
  sort(ke[u].begin(), ke[u].end());
  for (int v : ke[u])
  {
    if ((v == s && u == t) || (v == t && u == s)) continue;
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
  pair<int, int>p[1005];
  for (int i = 1; i <= m; ++i)
  {
    cin >> p[i].first >> p[i].second;
    ke[p[i].first].push_back(p[i].second);
    ke[p[i].second].push_back(p[i].first);
  }
  int tplt = 0;
  cout << "DFS(1) = ";
  for (int i = 1; i <= n; ++i)
  {
    if (!visited[i])
    {
      tplt++;
      DFS(i);
    }
  }
  memset(visited, false, sizeof(visited));
  cout << "\nTPLT = " << tplt << endl;
  cout << endl;
  for (int j = 1; j <= m; j++) {
    int l = 0;
    cout << "Canh (" << p[j].first << " , " << p[j].second << "):\n";
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        l++;
        cout << "DFS(" << i << ") = ";
        DFS2(i, p[j].first, p[j].second);
        cout << endl;
      }
    }
    memset(visited, false, sizeof(visited));
    if (l > tplt) cout << "YES\n\n"; else cout << "NO\n\n";
  }
}