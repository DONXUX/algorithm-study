#include <iostream>
#include <string>
#include <queue>
using namespace std;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0 ,-1, 1 };

struct pos {
	int x, y, cnt;
};

const int BLANK = 0;
const int R		= 1;
const int G		= 2;
const int B		= 3;
const int P		= 4;
const int Y		= 5;

int map[12][6];
bool visited[12][6];
vector<pair<int, int>> route;

bool compare(const int &a, const int &b) {
	if (a == BLANK)
		return a < b;
	if (b == BLANK)
		return b < a;
}

void down() {
	for (int i = 0; i < 6; i++) {
		int tmp[12];
		for (int j = 11; j >= 0; j--) {
			if (map[j][i] == BLANK) {
				continue;
			}
			for (int k = 11; k >= j; k--) {
				if (map[k][i] != BLANK) continue;
				map[k][i] = map[j][i];
				map[j][i] = BLANK;
				break;
			}
		}
	}
}


bool bomb(int x, int y, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < route.size(); i++) 
			map[route[i].first][route[i].second] = BLANK;
		return true;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6
			|| visited[nx][ny] || map[nx][ny] != map[x][y]) continue;
		visited[nx][ny] = true;
		route.push_back({ nx, ny });
		bool isBomb = bomb( nx, ny, cnt + 1 );
		visited[nx][ny] = false;
		route.pop_back();
		if (isBomb) return true;
	}
	return false;
}

bool cycle() {
	int bombCnt = 0;
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == BLANK) continue;
			route.push_back({ i, j });
			visited[i][j] = true;
			if(bomb(i, j, 0)) bombCnt++;
			route.pop_back();
			visited[i][j] = false;
		}
	}
	if (bombCnt) down();
	return bombCnt;
}

int solve() {
	int cnt = 0;
	while (cycle()) cnt++;
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			switch (s[j]) {
			case '.': map[i][j] = BLANK; break;
			case 'R': map[i][j] = R; break;
			case 'G': map[i][j] = G; break;
			case 'B': map[i][j] = B; break;
			case 'P': map[i][j] = P; break;
			case 'Y': map[i][j] = Y; break;
			}
		}
	}
	
	cout << solve() << '\n';

	return 0;
}