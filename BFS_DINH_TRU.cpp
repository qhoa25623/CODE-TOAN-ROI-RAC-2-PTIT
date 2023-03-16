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
    int x = q.front();
    q.pop();
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

void BFS1(int u)
{
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  cout << u << "(0) ";
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
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
  // Dem so thanh phan lien thong
  int tplt = 0;
  cout << "BFS(" << 1 << ") = ";
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      tplt++;
      BFS1(i);
    }
  }
  cout << "\nTPLT=" << tplt << endl;
  cout << endl;
  memset(visited, false, sizeof(visited));
  for (int k = 1; k <= n; k++) {
    visited[k] = 1;
    cout << "Dinh " << k << ":\n";
    int l = 0;
    for (int i = 1; i <= n; ++i)
    {
      if (!visited[i])
      {
        l++;
        cout << "BFS(" << i << ") = ";
        BFS(i);
        cout << "\n";
      }
    }
    cout << "l = " << l << endl;
    if (l > tplt) cout << "YES\n\n"; else cout << "NO\n\n";
    memset(visited, false, sizeof(visited));
  }
  return 0;
}