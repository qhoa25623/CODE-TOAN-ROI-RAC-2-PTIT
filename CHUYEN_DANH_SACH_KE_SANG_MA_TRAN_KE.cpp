#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[1005][1005];
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
			a[i][stoi(tmp)] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}