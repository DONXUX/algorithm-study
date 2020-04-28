#include <iostream>
using namespace std;
constexpr int MOD = 1000000000;

long long dp[101][10]; // dp[숫자 길이][마지막 숫자]

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n;
	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) 
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % MOD;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % MOD;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % MOD;
		}
	}
	long long ret = 0;
	for (int i = 0; i < 10; i++)
		ret += dp[n][i];
	cout << ret % MOD;

	return 0;
}