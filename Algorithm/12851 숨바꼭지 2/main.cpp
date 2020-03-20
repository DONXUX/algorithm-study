#include <iostream>
#include <queue>
using namespace std;

const int INF = 99999999;

bool visited[100001];
vector<int> visited_v;
int n, k, min_cnt = INF, prev_cnt, time, num;

void bfs(void) {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited_v.push_back(n);
	prev_cnt = -1;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		// cnt 값이 바뀌었을 때 한 층에 저장했던 방문노드 정보들을 모두 한꺼번에 방문처리 합니다.
		if (cnt > prev_cnt) {
			for (int v : visited_v) {
				visited[v] = true;
				if (v == k) time = cnt, num++;
			}
			visited_v.clear();
			prev_cnt = cnt;

			// 방문노드들중 k 값이 존재할 경우 bfs를 끝냅니다.
			if (num > 0) return;
		}

		for (int i = 0; i < 3; i++) {
			int nx;
			switch (i) {
			case 0: nx = x + 1; break;
			case 1: nx = x - 1; break;
			case 2: nx = 2 * x; break;
			}

			if (nx < 0 || nx >= 100001 || visited[nx]) continue;
			// 한 층의 방문노드들을 바로 방문처리 하지않고 임시로 저장합니다.
			visited_v.push_back(nx);
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
	cout << time << '\n' << num;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();

	return 0;
} 