#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[1001][1001];

int main()
{
	cin >> n >> m;
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tmp;
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + tmp;
		}
	}

	cout << dp[n][m];
}
