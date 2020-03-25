#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 9999999;
constexpr int MAX = 100;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int n, m;
int map[MAX][MAX];
int dist[MAX][MAX];

struct pos {
	int x, y;
};

// 다익스트라
void bfs(void) {
	queue<pos> q;
	q.push({ 0,0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (map[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
			}
			else if (map[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.push({ nx, ny });
				}
			}
		}
	}
}

void input(void) {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
			dist[i][j] = INF;
		}
	}
}

int solve(void) {
	input();
	bfs();
	
	return dist[n - 1][m - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solve();

	return 0;
}