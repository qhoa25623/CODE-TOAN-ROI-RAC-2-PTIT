#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);
		string tmp;
		stringstream ss(s);
		while (ss >> tmp)
		{
			int x = stoi(tmp);
			if (x > i)
				cout << i << " " << x << endl;
		}
	}
	return 0;
}