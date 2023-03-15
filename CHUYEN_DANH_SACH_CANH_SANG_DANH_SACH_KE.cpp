#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int>adj[1005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (auto x : adj[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}