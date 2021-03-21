#include <iostream>
#include <vector>
using namespace std;

string result(const vector<vector<int>> row, const vector<vector<int>> col, const vector<vector<int>> diagonal, const pair<int,int> T, int dotCnt) {
	for (int i = 0; i < 4; i++) {
		if (row[i][0] == 4 || (row[i][0] == 3 && T.first == i)) // 행 검색
			return "X won";
		if (row[i][1] == 4 || (row[i][1] == 3 && T.first == i))
			return "O won";
		if (col[i][0] == 4 || (col[i][0] == 3 && T.second == i)) // 열 검색
			return "X won";
		if (col[i][1] == 4 || (col[i][1] == 3 && T.second == i))
			return "O won";
	}
	if (diagonal[0][0] == 4 || (diagonal[0][0] == 3 && T.first == T.second)) // 좌상단시작 대각선 검색
		return "X won";
	if (diagonal[0][1] == 4 || (diagonal[0][1] == 3 && T.first == T.second))
		return "O won";
	if (diagonal[1][0] == 4 || (diagonal[1][0] == 3 && T.first + T.second == 3)) // 우상단시작 대각선 검색
		return "X won";
	if (diagonal[1][1] == 4 || (diagonal[1][1] == 3 && T.first + T.second == 3))
		return "O won";
	if (dotCnt == 0) return "Draw";
	return "Game has not completed";
}

int main()
{
	int tc;
	cin >> tc;
	for (int testcase = 1; testcase <= tc; testcase++) {
		// X가 0, O가 1
		vector<vector<int>> row(4, vector<int>(2)); // 각 행의 X와 O의 개수
		vector<vector<int>> col(4, vector<int>(2)); // 각 열의 X와 O의 개수
		vector<vector<int>> diagonal(2, vector<int>(2)); // 두 대각선의 X와 O의 개수
		pair<int, int> T = { 5, 8 }; // T의 위치
		int dotCnt = 0; // .의 개수

		string tmp;
		for (int i = 0; i < 4; i++) {
			cin >> tmp;
			for (int j = 0; j < 4; j++) {
				if (tmp[j] == 'X') {
					row[i][0]++;
					col[j][0]++;
					if (i == j) diagonal[0][0]++;
					if (i + j == 3) diagonal[1][0]++;
				}
				else if (tmp[j] == 'O') {
					row[i][1]++;
					col[j][1]++;
					if (i == j) diagonal[0][1]++;
					if (i + j == 3) diagonal[1][1]++;
				}
				else if (tmp[j] == 'T') T = { i, j };
				else dotCnt++;
			}
		}
		cout << "#" << testcase << " " << result(row, col, diagonal, T, dotCnt) << endl;
	}
}