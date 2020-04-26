#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct pos { int x, y; };
int n, m, value;
char map[102][102];
bool visited[102][102];
bool key[26];

bool range(int x, int y) { return x >= 0 && y >= 0 && x <= n + 1 && y <= m + 1; }

void bfs() {
	queue<pos> q;
	queue<pos> door[26];
	q.push({ 0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!range(nx, ny) || visited[nx][ny] || map[nx][ny] == '*') continue;
			visited[nx][ny] = true;
			if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
				if (!key[map[nx][ny] - 'A']) {
					door[map[nx][ny] - 'A'].push({ nx,ny });
					continue;
				}
			} else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
				key[map[nx][ny] - 'a'] = true;
				while (!door[map[nx][ny] - 'a'].empty()) {
					pos p = door[map[nx][ny] - 'a'].front();
					visited[p.x][p.y] = true;
					q.push({ p.x, p.y });
					door[map[nx][ny] - 'a'].pop();
				}
			} else if (map[nx][ny] == '$') value++;
			q.push({ nx, ny });
		}
	}
}

int solve() {
	bfs();
	return value;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			map[i][j] = '.';
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			map[i][j] = s[j - 1];
	}
	string keys;
	cin >> keys;
	if (keys != "0") {
		for (char k : keys)
			key[k - 'a'] = true;
	}
}

void init() {
	value = 0;
	memset(visited, false, 102 * 102);
	for (int i = 0; i < 26; i++) 
		key[i] = false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		init();
		input();
		cout << solve() << endl;
	}
	return 0;
}