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
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    sort(ke[x].begin(), ke[x].end());
    for(int y : ke[x])
    {
      if(!visited[y])
      {
        cout << x << "->" << y << endl;
        q.push(y);
        visited[y] = 1;
      }
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
  }for(int i = 1; i <= n; ++i)
  {
    memset(visited, 0, sizeof(visited));
    cout << endl << i << endl;
    BFS(i);
    cout << endl;
  }

}