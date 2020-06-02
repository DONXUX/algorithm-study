#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 99999999;

int n, m;
int min_dist[101][101];

void solve() {
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				min_dist[i][j] = min(min_dist[i][j], min_dist[i][k] + min_dist[k][j]);
}

void input() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			min_dist[i][j] = INF;
			if (i == j) min_dist[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(min_dist[a][b] > c)
			min_dist[a][b] = c;
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	solve();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (min_dist[i][j] == INF) cout << 0 << " ";
			else cout << min_dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}