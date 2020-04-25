#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
constexpr int INF = 99999999;
constexpr int MAX = 1000;
typedef pair<int, int> p;

int n, m, x;
vector<p> edge[2][MAX];
int dist[3][MAX];

void getSp(int type) {
	priority_queue<p, vector<p>, greater<p>> pq;
	fill(dist[type], dist[type] + MAX, INF);
	bool visited[MAX] = { 0 };
	pq.push(p(0, x));
	dist[type][x] = 0;
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& i : edge[type][cur]) {
			int next = i.first, d = i.second;
			if (dist[type][next] > dist[type][cur] + d) {
				dist[type][next] = dist[type][cur] + d;
				pq.push(p(dist[type][next], next));
			}
		}
	}
}

int solve() {
	getSp(0), getSp(1);
	for (int i = 0; i < n; i++)
		dist[2][i] = dist[0][i] + dist[1][i];
	sort(dist[2], dist[2] + n);

	return dist[2][n - 1];
}

void input() {
	cin >> n >> m >> x;
	x--;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edge[0][b - 1].push_back(p(a - 1, w));
		edge[1][a - 1].push_back(p(b - 1, w));
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}