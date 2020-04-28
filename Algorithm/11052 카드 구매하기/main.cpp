#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001], cost[1001];

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cost[i];

	dp[0] = 0, dp[1] = cost[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = cost[i];
		for (int j = 1; j <= i; j++) 
			dp[i] = max(dp[i], dp[i - j] + dp[i - (i - j)]);
	}
	cout << dp[n];
	return 0;
}