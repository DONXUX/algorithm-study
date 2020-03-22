#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

constexpr int MAX = 500001;
int visited[MAX][2];
int n, k;

// 1. 수빈이는 bfs로 미리 짝수 최소시간, 홀수 최소시간을 기록.
// 2. 동생을 돌린다.

void bfs(void) {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited[n][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++) {
			int nx;
			switch (i) {
			case 0: nx = x + 1; break;
			case 1: nx = x - 1; break;
			case 2: nx = 2 * x; break;
			}

			if (nx < 0 || nx >= MAX || (visited[nx][(cnt + 1) % 2] != -1)) continue;
			visited[nx][(cnt + 1) % 2] = cnt + 1;
			q.push({ nx, cnt + 1 });
		}
	}
}

void input(void) {
	memset(visited, -1, sizeof visited);
	cin >> n >> k;
}

int solve(void) {
	input();
	bfs();
	int cnt = 0;
	while (k < MAX) {
		if ((visited[k][cnt % 2] != -1) && (cnt >= visited[k][cnt % 2]))
			return cnt;
		k += ++cnt;
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solve();
	return 0;
}