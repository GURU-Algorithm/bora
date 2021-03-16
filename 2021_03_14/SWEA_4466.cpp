#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
		int n, k;
		cin >> n >> k;
		vector<int> score(n);
		for (int i = 0; i < n; i++)
			cin >> score[i];
		sort(score.begin(), score.end(), greater<int>()); // 내림차순 정렬
		int total = 0;
		for (int i = 0; i < k; i++)
			total += score[i];
		cout << "#" << testcase << " " << total << endl;
	}
}
