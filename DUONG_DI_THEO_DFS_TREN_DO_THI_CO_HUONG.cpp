#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int v, e, s, t;
int parent[1005];
vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
	visited[u] = true;
	cout << u << "(" << parent[u] << ") ";
	for (auto x : adj[u])
	{
		if (!visited[x])
		{
			parent[x] = u;
			DFS(x);
		}
	}
}

void findPath(int s, int t)
{
	if (!visited[t])
		cout << -1;
	else
	{
		vector<int> res;
		while (t != s)
		{
			res.push_back(t);
			t = parent[t];
		}
		res.push_back(s);
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << " ";
			if (i != res.size() - 1) {
				cout << "<- ";
			}
		}
	}
	cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> v >> e >> s >> t;
	for (int i = 1; i <= e; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	DFS(s);
	cout << endl;
	findPath(s, t);
	return 0;
}