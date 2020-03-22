#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[100001];
int parent[100001];
vector<int> path;

int n, k, time;

void bfs(void) {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		// Disjoint Set
		// Path에 경로를 저장한다.
		if (x == k) {
			time = cnt;
			int idx = x;
			while (idx != n) {
				path.push_back(idx);
				idx = parent[idx];
			}
			path.push_back(idx);
			reverse(path.begin(), path.end());
			return;
		}

		for (int i = 0; i < 3; i++) {
			int nx;
			switch (i) {
			case 0: nx = x + 1; break;
			case 1: nx = x - 1; break;
			case 2: nx = 2 * x; break;
			}

			if (nx < 0 || nx >= 100001 || visited[nx]) continue;
			visited[nx] = true;
			parent[nx] = x;
			q.push({ nx, cnt + 1 });
		}

	}
}

void input() {
	cin >> n >> k;
}

void solve(void) {
	input();
	bfs();
	cout << time << '\n';
	for (int n : path) cout << n << ' ';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();

	return 0;
}