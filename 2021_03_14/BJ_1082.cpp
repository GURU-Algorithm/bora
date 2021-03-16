#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 숫자가 크려면 
// 1.최대한 자릿수가 커야함
// 2.앞자리수부터 최대한 숫자가 커야함
// -> 탐욕법

int cost[10]; // 가격 배열
int main() {
	int n; // 문방구에서 파는 숫자의 개수
	cin >> n;
	vector<pair<int, int>> vec(n); // <가격, 숫자> 정렬을 위한 벡터

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec[i] = make_pair(tmp, i);
		cost[i] = tmp;
	}
	sort(vec.begin(), vec.end()); // 가격 기준 오름차순 정렬

	int money = 0;
	cin >> money; // 가지고 있는 돈
	string result = "";

	if (n == 1) {
		cout << 0;
		return 0;
	}

	// 1. 가장 싼 숫자를 사서 가능한 최대로 자릿수 늘리기 -> 자릿수부터 결정
	int cur = 0;
	if (vec[cur].second == 0) cur++; // 제일 앞 숫자는 0이면 안됨
	if (money < vec[cur].first) {
		cout << 0;
		return 0;
	}
	result += char(vec[cur].second + '0'); 
	money -= vec[cur].first;
	while (money >= vec[0].first)
	{
		result += char(vec[0].second + '0');
		money -= vec[0].first;
	}

	// 2. 남은 돈을 사용해 가장 앞자리부터 최대한 큰 숫자로 바꾸기
	for (int i = 0; i < result.size(); i++) {
		for (int j = n - 1; j > 0; j--) {
			int plus = cost[j] - cost[result[i] - '0']; // 추가로 내야하는 돈
			if (money >= plus && j > result[i] - '0') {
				result[i] = char(j + '0');
				money -= plus;
				break;
			}
		}
	}

	cout << result;
}