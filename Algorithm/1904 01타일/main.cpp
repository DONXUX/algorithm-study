#include <iostream>
using namespace std;

int dp[1000001];

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n;
	cin >> n;
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	cout << dp[n];
	return 0;
}