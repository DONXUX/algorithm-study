#include <iostream>
#define endl "\n"
using namespace std;
struct pos {
	int x, y;
};
constexpr int MAX = 500;
int dr[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dc[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

int r, c;
int map[MAX][MAX];
int marble[MAX][MAX];
int parents[300001];
pos poss[300001];

int find(int n) {
	if (parents[n] == n) return n;
	return parents[n] = find(parents[n]);
}

void solve() {
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++)
			parents[map[i][j]] = map[i][j], poss[map[i][j]] = { i,j };
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int min_num = map[i][j], min_nr = -1, min_nc = -1;
			for (int k = 0; k < 8; k++) {
				int nr = i + dr[k], nc = j + dc[k];
				if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
				if (min_num > map[nr][nc]) 
					min_num = map[nr][nc], min_nr = nr, min_nc = nc;
			}
			if (min_nr != -1 && min_nc != -1) 
				parents[map[i][j]] = map[min_nr][min_nc];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int p = find(parents[map[i][j]]);
			marble[poss[p].x][poss[p].y]++;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) 
			cout << marble[i][j] << " ";
		cout << endl;
	}
}

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++)
			cin >> map[i][j];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();

	return 0;
}