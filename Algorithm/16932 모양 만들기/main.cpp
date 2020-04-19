#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, tmp_cnt, shape_cnt = 1;
int map[1000][1000], shape[50000];
bool visited[1000][1000];

bool range(int x, int y) {
	return x >= 0 && y >= 0 && x < n&& y < m;
}

bool shapeVisited(int *v, int n) {
	for (int i = 0; i < 4; i++) 
		if (v[i] == n) return true;
	return false;
}

void dfs(int x, int y) {
	map[x][y] = shape_cnt;
	tmp_cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!range(nx, ny) || (map[nx][ny] !=  -1) || visited[nx][ny]) continue;
		visited[nx][ny] = true;
		dfs(nx, ny);
	}
}

int solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != -1) continue;
			tmp_cnt = 0;
			dfs(i, j);
			shape[shape_cnt++] = tmp_cnt;
		}
	}
	
	int max_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) continue;
			int cnt = 1;
			int shape_visited[4] = { 0,0,0,0 };
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (!range(nx, ny) || shapeVisited(shape_visited, map[nx][ny])) continue;
				shape_visited[k] = map[nx][ny];
				cnt += shape[map[nx][ny]];
			}
			max_cnt = max(max_cnt, cnt);
		}
	}
	return max_cnt;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}