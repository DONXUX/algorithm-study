#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
constexpr int INF = 9999999;

// 오른쪽 왼쪽 위 아래
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int n, m, min_cnt = INF, point_cnt = 0, wall_cnt = 1;
char map[32][32];

void back(int x, int y, int cnt) {
	if (min_cnt <= cnt) return;
	bool move = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		while (map[nx][ny] != '*') {
			map[nx][ny] = '*';
			nx += dx[i], ny += dy[i];
			wall_cnt++;
		}
		nx -= dx[i], ny -= dy[i];

		if (nx == x && ny == y) continue;
		move = true;
		back(nx, ny, cnt + 1);
		
		while (nx != x || ny != y) {
			map[nx][ny] = '.';
			wall_cnt--;
			nx -= dx[i], ny -= dy[i];
		}
	}

	if (!move && (wall_cnt == point_cnt)) min_cnt = min(min_cnt, cnt);
}

int solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '.') {
				map[i][j] = '*';
				back(i, j, 0);
				map[i][j] = '.';
			}
		}
	}
	return min_cnt;
}

void input() {
	for (int i = 0; i <= n + 1; i++) 
		for (int j = 0; j <= m + 1; j++) 
			map[i][j] = '*';
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j - 1];
			if (map[i][j] == '.') point_cnt++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t = 1;
	while (cin >> n >> m) {
		input();
		int result = solve();
		cout << "Case " << t++ << ": ";
		if (result == INF) cout << -1 << endl;
		else  cout << result << endl;
		point_cnt = 0;
		min_cnt = INF;
	}
	return 0;
}