#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int MAX = 500;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int map[MAX][MAX], result[MAX][MAX];
int r, c;
priority_queue<pair<int, pair<int, int>>> pq;
bool range(int x, int y) { return (x >= 0 && y >= 0 && x < r && y < c); }

void search() {
	while (!pq.empty()) {
		int x = pq.top().second.first, y = pq.top().second.second;
		pq.pop();
		
		int m_min = map[x][y], min_nx, min_ny;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (range(nx, ny) && (map[nx][ny] < m_min)) 
				m_min = map[nx][ny], min_nx = nx, min_ny = ny;
		}
		if (m_min < map[x][y]) {
			result[min_nx][min_ny] += result[x][y];
			result[x][y] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			pq.push({ map[i][j], {i,j} });
			result[i][j] = 1;
		}
	}
	search();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) 
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}