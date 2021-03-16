#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
		int n;
		cin >> n;
		vector<int> vec(n - 1);

		int prev, tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			if (i != 0) vec.push_back(tmp - prev);
			prev = tmp;
		}

		sort(vec.begin(), vec.end());
		int min = vec[0] < 0 ? -vec[0] : 0;
		int max = vec[vec.size() - 1] > 0 ? vec[vec.size() - 1] : 0;
		cout << "#" << testcase << " " << max << " " << min << endl;
	}
}
