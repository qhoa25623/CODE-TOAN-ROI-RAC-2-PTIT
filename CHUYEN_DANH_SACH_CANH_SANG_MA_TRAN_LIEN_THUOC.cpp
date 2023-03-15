#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	int a[105][105];
	memset(a, 0, sizeof(0));
	pair<int, int>p[1005];
	for (int i = 1; i <= m; i++) {
		cin >> p[i].first >> p[i].second;
		a[p[i].first][i] = a[p[i].second][i] = 1;
	}
	int num = 1;
	cout << "   ";
	for (int i = 1; i <= m; i++) {
		cout << num << " ";
		num++;
		if (num > 9) num = 0;
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << i % 10 << "  ";
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}