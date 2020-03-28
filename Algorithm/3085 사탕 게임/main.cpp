#include <iostream>
#include <algorithm>
using namespace std;

int n;
char map[50][50];

void rotateMap() {
	char tmp_map[50][50];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			tmp_map[i][j] = map[i][j];

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			map[n - j - 1][i] = tmp_map[i][j];
}

int getConCnt(int i, int j) {
	int cnt = 1;
	int max_cnt = 1;
	char prev_candy = map[i][0];
	for (int k = 1; k < n; k++) {
		if (prev_candy == map[i][k]) max_cnt = max(max_cnt, ++cnt);
		else cnt = 1, prev_candy = map[i][k];
	}
	cnt = 1;
	prev_candy = map[0][j];
	for (int k = 1; k < n; k++) {
		if (prev_candy == map[k][j]) max_cnt = max(max_cnt, ++cnt);
		else cnt = 1, prev_candy = map[k][j];
	}
	if (j != 0) {
		cnt = 1;
		prev_candy = map[0][j - 1];
		for (int k = 1; k < n; k++) {
			if (prev_candy == map[k][j - 1]) max_cnt = max(max_cnt, ++cnt);
			else cnt = 1, prev_candy = map[k][j - 1];
		}
	}
	return max_cnt;
}

void swap(int i, int j) {
	char tmp;
	tmp = map[i][j];
	map[i][j] = map[i][j-1];
	map[i][j-1] = tmp;
}

int solve(void) {
	int max_con = 1;
	for (int m = 0; m < 2; m++) {
		for (int i = 0; i < n; i++) {
			max_con = max(max_con, getConCnt(i, 0));
			for (int j = 1; j < n; j++) {
				max_con = max(max_con, getConCnt(i, j));
				swap(i, j);
				max_con = max(max_con, getConCnt(i, j));
				swap(i, j);
			}
		}
		rotateMap();
	}
	return max_con;
}

void input(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) 
			map[i][j] = s[j];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << solve();

	return 0;
}