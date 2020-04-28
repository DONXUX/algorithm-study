#include <iostream>
#include <algorithm>
using namespace std;
constexpr int INF = 999999999;

int N, K;
int dp[101][10001];
int cost[100];

int coin(int n, int k) {
    if (n < 0) return k == 0 ? 0 : INF;\
    if (dp[n][k] != -1) return dp[n][k];
    int ret = coin(n - 1, k);
    if(k >= cost[n]) ret = min(ret, coin(n, k - cost[n]) + 1);
    dp[n][k] = ret;
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> cost[i];

    fill(&dp[0][0], &dp[100][10001], -1);
    int ans = coin(N - 1, K);
    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}