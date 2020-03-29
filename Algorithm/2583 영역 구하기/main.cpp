#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct pos {
	int x, y;
};

int m, n, k, component, area = 0;
vector<pair<pos, pos>> vertexs;
vector<int> areas;
int map[101][101];

void fill(void) {
	for (pair<pos, pos> v : vertexs) {
		pos p1 = v.first; pos p2 = v.second;
		if (p1.x < p2.x) {
			for (int i = p1.x; i <= p2.x; i++) 
				for (int j = p1.y; j <= p2.y; j++) 
					map[i][j] = -1;
		}
		else {
			for (int i = p2.x; i <= p1.x; i++) 
				for (int j = p1.y; j <= p2.y; j++) 
					map[i][j] = -1;
		}
	}
}

void dfs(int x, int y, int cnt) {
	area++;
	map[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m|| map[nx][ny] != 0) continue;
		dfs(nx, ny, cnt + 1);
	}
}

void solve(void) {
	fill();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				dfs(i, j, 0);
				areas.push_back(area);
				area = 0;
				component++;
			}
		}
	}
	sort(areas.begin(), areas.end());
}

void input(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		pos p1, p2;
		cin >> p1.y >> p1.x >> p2.y >> p2.x;
		p2.x--, p2.y--;
		p1.x = (n - 1) - p1.x; 
		p2.x = (n - 1) - p2.x;
		vertexs.push_back({ p1,p2 });
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	cout << component << "\n";
	for (int a : areas) 
		cout << a << " ";

	return 0;
}