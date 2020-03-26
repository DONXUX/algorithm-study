#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[1000][1000];
int dp[1000][1000];

void input(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
	dp[0][0] = map[0][0];
}

int solve(void) {
	for (int i = 1; i < m; i++) 
		dp[0][i] = dp[0][i - 1] + map[0][i];
	
	for (int i = 1; i < n; i++) {
		int tmp_dp[1000][2];

		tmp_dp[0][0] = dp[i - 1][0] + map[i][0];
		for (int j = 1; j < m; j++) 
			tmp_dp[j][0] = max(dp[i - 1][j], tmp_dp[j - 1][0]) + map[i][j];
		

		tmp_dp[m - 1][1] = dp[i - 1][m - 1] + map[i][m - 1];
		for (int j = m - 2; j >= 0; j--) 
			tmp_dp[j][1] = max(dp[i - 1][j], tmp_dp[j + 1][1]) + map[i][j];
		

		for (int j = 0; j < m; j++) 
			dp[i][j] = max(tmp_dp[j][0], tmp_dp[j][1]);
	}

	return dp[n - 1][m - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << solve();

	return 0;
}