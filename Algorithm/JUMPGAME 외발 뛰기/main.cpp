#include <iostream>
#define endl '\n'
using namespace std;

int n, map[100][100];
int dp[100][100];

int jump(int x, int y) {
	if (x >= n || y >= n) return 0;
	else if (x == n - 1 && y == n - 1) return 1;

	int& ret = dp[x][y];
	if (ret != -1) return ret;

	int size = map[x][y];
	return ret = (jump(x + size, y) || jump(x, y + size));
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				cin >> map[i][j];

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				dp[i][j] = -1;

		int ans = jump(0, 0);
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}