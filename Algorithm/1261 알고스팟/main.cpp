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
bool map[MAX][MAX];
bool visited[MAX][MAX][MAX];
int prev_cnt;
int min_wall = INF;

struct pos {
	int x, y, wall;
};

void bfs(void) {
	queue<pos> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		q.pop();

		if (x == n - 1 && y == m - 1)
			min_wall = min(min_wall, wall);

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nwall;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			nwall = wall + map[nx][ny];
			if (visited[nx][ny][nwall]) continue;
			visited[nx][ny][nwall] = true;
			q.push({ nx, ny, nwall });
		}
	}
}

void input(void) {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}
}

int solve(void) {
	input();
	bfs();
	
	return min_wall;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solve();

	return 0;
}