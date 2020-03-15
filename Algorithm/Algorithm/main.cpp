#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct pos {
	int s, x, y;
};

const int INF = 99999999;

int n, t, m;
int map[1000][1000];
pos citys[1000];
pair<int, int> cmd[1000];
int a, b, result = INF;

int Dist(int x, int y, int xx, int yy) {
	return (abs(x - xx) + abs(y - yy));
}

void Input() {
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		citys[i].s = s;
		citys[i].x = x - 1; 
		citys[i].y = y - 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cmd[i] = { a, b };
	}
}

void Solve() {
	for (int i = 0; i < n; i++) {
		int x = citys[i].x;
		int y = citys[i].y;
		int s = citys[i].s;
		
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int dist;
			int xx = citys[j].x;
			int yy = citys[j].y;
			int ss = citys[j].s;
			
			dist = Dist(x, y, xx, yy);
			if (s == 1 && ss == 1) if (dist > t) dist = t;
			map[i][j] = dist;
		}
	}

	// 플로이드 워샬 알고리즘
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if (map[i][j] > map[i][k] + map[k][j]) map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int pos = cmd[i].first;
		int pos2 = cmd[i].second;

		cout << map[pos][pos2] << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Input();
	Solve();

	return 0;
}