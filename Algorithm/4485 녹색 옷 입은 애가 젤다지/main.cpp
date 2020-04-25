#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int dx[] = { 0,0,1,-1 };
constexpr int dy[] = { 1,-1,0,0 };
constexpr int INF = 9999999;
constexpr int MAX = 125;
typedef pair<int, int> p;
typedef pair<int, p> pip;

struct pos { int w, x, y; };

int n;
int map[MAX][MAX];

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int solve() {
	priority_queue<pip, vector<pip>, greater<pip>> pq;
	int dist[MAX][MAX];
	bool visited[MAX][MAX] = { 0 };
	fill(&dist[0][0], &dist[MAX - 1][MAX], INF);
	dist[0][0] = map[0][0];
	pq.push(pip(map[0][0], p(0, 0)));
	while (!pq.empty()) {
		int x, y;
		do {
			x = pq.top().second.first, y = pq.top().second.second;
			pq.pop();
		} while (!pq.empty() && visited[x][y]);
		if (visited[x][y]) break;
		visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!range(nx, ny)) continue;
			if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				pq.push(pip(dist[nx][ny], p(nx, ny)));
			}
		}
	}
	return dist[n - 1][n - 1];
}

bool input() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> map[i][j];
	return n != 0;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int cnt = 1;
	while (input()) 
		cout << "Problem " << cnt++ << ": " << solve() << endl;

	return 0;
}