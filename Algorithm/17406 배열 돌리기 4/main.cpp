#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int INF = 9999999;

struct op {
	int r, c, s;
};

int n, m, k;
int map[51][51];
int tmp_map[51][51];
vector<op> ops;
vector<int> order;

void copy_map() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			tmp_map[i][j] = map[i][j];
}

void move(op oper) {
	for (int i = 1; i <= oper.s; i++) {
		int r = oper.r - i;
		int c = oper.c - i;
		int tmp = tmp_map[r][c];
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < i * 2; k++) {
				switch (j) {
				case 0: tmp_map[r][c] = tmp_map[r + 1][c]; r++; break;
				case 1: tmp_map[r][c] = tmp_map[r][c + 1]; c++; break;
				case 2: tmp_map[r][c] = tmp_map[r - 1][c]; r--; break;
				case 3: tmp_map[r][c] = tmp_map[r][c - 1]; c--; break;
				}
			}
		}
		tmp_map[r][c + 1] = tmp;
	}
}

void rotate() {
	for (int i = 0; i < k; i++) {
		op oper = ops[order[i]];
		move(oper);
	}
}

int getMinColumn() {
	int minSum = INF;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) 
			sum += tmp_map[i][j];
		
		minSum = min(minSum, sum);
	}
	return minSum;
}

int solve(void) {
	int minAnswer = INF;
	do {
		copy_map();
		rotate();
		minAnswer = min(minAnswer, getMinColumn());
	} while (next_permutation(order.begin(), order.end()));

	return minAnswer;
}

void input(void) {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> map[i][j];

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		ops.push_back({ r,c,s });
		order.push_back(i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << solve();

	return 0;
}