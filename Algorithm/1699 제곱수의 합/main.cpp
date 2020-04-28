#include <iostream>
#include <algorithm>
using namespace std;
constexpr int INF = 99999999;

int n;
int dp[100001];

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	dp[0] = 0;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		for (int j = 1; j <= n; j++) {
			if (i < j * j) break;
			if (dp[i] > dp[i - (j * j)] + 1) dp[i] = dp[i - (j * j)] + 1;
		}
	}
	cout << dp[n];

	return 0;
}