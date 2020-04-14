#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int dp[105][3], dist[105], workshop[105];
vector<int> v;

void find(int x) {
	if (x == dp[x][2]) return;
	v.push_back(x);
	find(dp[x][2]);
}

void solve() {
	dp[0][0] = 0, dp[0][1] = -1, dp[0][2] = 0;

	for (int i = 1; i < m + 2; i++) {
		int cnt = i - 1, min_time = 99999, min_idx = 0;
		while (cnt >= 0 && dist[cnt] >= dist[i] - n) {
			if (min_time > dp[cnt][0]) {
				min_time = dp[cnt][0];
				min_idx = cnt;
			}
			cnt--;
		}
		dp[i][0] = min_time + workshop[i];
		dp[i][1] = dp[min_idx][1] + 1;
		dp[i][2] = min_idx;
	}
	
	cout << dp[m + 1][0] << endl;
	cout << dp[m + 1][1] << endl;
	find(dp[m + 1][2]);
	reverse(v.begin(), v.end());
	for (int w : v) cout << w << " ";
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m + 1; i++) 
		cin >> dist[i];
	for (int i = 1; i <= m; i++)
		cin >> workshop[i];
	for (int i = 2; i <= m + 1; i++) 
		dist[i] += dist[i - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();

	return 0;
}