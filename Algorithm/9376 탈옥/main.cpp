#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int INF = 99999999;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct pos {
	int x, y, d;
};

int h, w;
vector<pos> p;
char map[102][102];
int result[102][102][3];

void bfs(pos p, int cnt) {
	queue<pos> q;
	q.push({ p.x, p.y, p.d });
	result[p.x][p.y][cnt] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1 || map[nx][ny] == '*' || result[nx][ny][cnt] <= d) continue;
			if (map[nx][ny] == '#') {
				if (result[nx][ny][cnt] <= d + 1) continue;
				q.push({ nx, ny, d + 1 });
				result[nx][ny][cnt] = d + 1;
			}
			else {
				q.push({ nx, ny, d });
				result[nx][ny][cnt] = d;
			}
		}
	}
}

int solve(void) {
	for (int i = 0; i <= h + 1; i++) 
		for (int j = 0; j <= w + 1; j++) 
			for (int k = 0; k < 3; k++) 
				result[i][j][k] = INF;

	bfs(p[0], 0);
	bfs(p[1], 1);
	bfs({ 0, 0 }, 2);

	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			if (map[i][j] == '*') continue;
			result[i][j][0] = result[i][j][0] + result[i][j][1] + result[i][j][2];
			if (map[i][j] == '#') 
				result[i][j][0] -= 2;
		}
	}
		
	int min_d = INF;
	for (int i = 0; i <= h + 1; i++) 
		for (int j = 0; j <= w + 1; j++) 
			min_d = min(min_d, result[i][j][0]);

	return min_d;
}

void input(void) {
	for (int i = 0; i <= h + 1; i++)
		for (int j = 0; j <= w + 1; j++)
			map[i][j] = '.';
	p.clear();
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '$') p.push_back({ i, j + 1 });
			map[i][j + 1] = s[j];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		input();
		cout << solve() << '\n';
	}
	
	return 0;
}