#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, m, s;
vector<int> ke[1005];
bool visited[1005];

void BFS(int u)
{
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  cout << u << "(0) ";
  while (!q.empty())
  {
    int x = q.front(); q.pop();
    sort(ke[x].begin(), ke[x].end());
    for (int y : ke[x])
    {
      if (!visited[y])
      {
        cout << y << "(" << x << ") ";
        q.push(y);
        visited[y] = 1;
      }
    }
  }
}

void BFS2(int u, int s, int t)
{
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  cout << u << "(0) ";
  while (!q.empty())
  {
    int x = q.front(); q.pop();
    sort(ke[x].begin(), ke[x].end());
    for (int y : ke[x])
    {
      if ((y == s && x == t) || (y == t && x == s)) continue;
      if (!visited[y])
      {
        cout << y << "(" << x << ") ";
        q.push(y);
        visited[y] = 1;
      }
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
  for (int i = 1; i <= n; ++i)
  {
    if (!visited[i])
    {
      tplt++;
      cout << "BFS(" << i << ") = ";
      BFS(i);
      cout << endl;
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
        cout << "BFS(" << i << ") = ";
        BFS2(i, p[j].first, p[j].second);
        cout << endl;
      }
    }
    memset(visited, false, sizeof(visited));
    cout << "l = " << l << endl;
    if (l > tplt) cout << "YES\n\n"; else cout << "NO\n\n";
  }
}