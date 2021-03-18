#include<iostream>
#include<string>
#include<math.h>
using namespace std;

// 왜 안될까.... 계속 고치는중
// 모음은 0 자음은 1으로 두고 풀기
string str;
int answer;

// 모음인가?
bool isVowel(char c) {
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == '0';
}

void dfs(int idx) {
	if (idx >= 3 && isVowel(str[idx - 3]) == isVowel(str[idx - 2]) && isVowel(str[idx - 2]) == isVowel(str[idx - 1])) return;
	if (idx == str.size()) { // 종료
		bool L = false;
		int cnt = 0; // 1의 개수
		int tmp = 1;
		for (char c : str) {
			if (c == 'L') L = true;
			else if (c == '0') tmp *= 5; // 모음
			else if (c == '1') cnt++; // 자음
		}
		if (!L && cnt > 0) {
			tmp *= cnt--;
			L = true;
		}
		tmp *= pow(21, cnt);
		if (L) answer += tmp;
		return;
	}
	if (str[idx] != '_') {
		dfs(idx + 1);
		return;
	}

	char origin = str[idx];
	str[idx] = '1';
	dfs(idx + 1);
	str[idx] = origin;

	str[idx] = '0';
	dfs(idx + 1);
	str[idx] = origin;
}

int main()
{
	cin >> str;
	dfs(0);
	cout << answer;
}
