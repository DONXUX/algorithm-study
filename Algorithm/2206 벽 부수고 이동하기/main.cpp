#include <iostream>
#include <queue>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int n, m;
bool map[1000][1000];
bool visited[1000][1000][2];

struct pos {
	int x, y, cnt;
	bool broke;
};

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}
}

int bfs(void) {
	queue<pos> q;
	q.push({ 0, 0, 1, false });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		bool broke = q.front().broke;
		q.pop();

		if (map[x][y]) broke = true;
		if (x == n - 1 && y == m - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny][broke] || (broke && map[nx][ny])) continue;
			visited[nx][ny][broke] = true;
			q.push({ nx, ny, cnt + 1, broke });
		}
	}
	return -1;
}

int solve() {
	return bfs();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << solve();

	return 0;
}