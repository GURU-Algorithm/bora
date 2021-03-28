#include<iostream>
#include<stack>
using namespace std;

int nums[1000000];
int results[1000000];
stack<int> ch;
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	for (int i = n - 1; i >= 0; i--) {
		while (!ch.empty() && ch.top() <= nums[i]) 
			ch.pop(); // 어차피 해당 요소는 i번째 수보다 작거나 같으므로 이후 비교할때 필요하지 않음

		if (ch.empty()) results[i] = -1;
		else results[i] = ch.top();

		ch.push(nums[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << results[i] << " ";
	}
}
