#include <iostream>
using namespace std;

// 유니콘 뿔 1개
// 트윈혼 뿔 2개
int main()
{
	int tc;
	cin >> tc;
	for (int testcase = 1; testcase <= tc; testcase++) {
		int n, m;
		cin >> n >> m;
		int y = n - m; // 트윈혼의 수
		int x = m - y; // 유니콘의 수
		cout << "#" << testcase << " " << x << " " << y << endl;
	}
}
