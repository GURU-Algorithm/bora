#include<iostream>
using namespace std;

int n;
bool dp[100][100];
bool ch[100];
int result;

void dfs(int idx) {
	if (ch[idx]) return; // 이미 감염되었다면
	ch[idx] = true;
	result++;
	for (int i = 0; i < n; i++) {
		if (dp[idx][i])
			dfs(i);
	}
}

int main()
{
	int k;
	cin >> n >> k;
	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		dp[a][b] = true;
		dp[b][a] = true;
	}

	dfs(1);

	cout << result - 1;
}
