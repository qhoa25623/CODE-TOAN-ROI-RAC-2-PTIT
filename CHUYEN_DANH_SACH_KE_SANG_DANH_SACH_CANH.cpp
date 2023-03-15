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
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		while (ss >> tmp)
		{
			adj[i].push_back(stoi(tmp));
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
		for (auto x : adj[i])
		{
			if (x > i)
				cout << i << " " << x << endl;
		}
	}
	return 0;
}