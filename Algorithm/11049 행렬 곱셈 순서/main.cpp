#include <iostream>
#include <algorithm>
using namespace std;
constexpr int R = 0, C = 1, INF = 999999999;

int n, mat[510][2], dp[510][510];

int solve() {
	for (int d = 2; d <= n; d++) {
		for (int i = 0; i <= n - d; i++) {
			dp[i][i + d] = INF;
			for (int j = i + 1; j < i + d; j++) 
				dp[i][i + d] = min(dp[i][i + d], dp[i][j] + dp[j][i + d] + mat[i][R] * mat[j][R] * mat[i + d - 1][C]);
		}
	}
	return dp[0][n];
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		mat[i][R] = r, mat[i][C] = c;
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}