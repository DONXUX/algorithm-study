#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
constexpr int INF = 999999999;
constexpr int MAX_V = 1000;

int n, m, s, e;
vector<p> edge[MAX_V];
priority_queue<p, vector<p>, greater<p>> pq;
int dist[MAX_V];
bool visited[MAX_V];

int solve() {
	fill(dist, dist + MAX_V, INF);
	pq.push(p(0, s));
	dist[s] = 0;
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);

		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& i : edge[cur]) {
			int next = i.first, d = i.second;
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push(p(dist[next], next));
			}
		}
	}

	return dist[e];
}

void input() {
	cin >> n >> m;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edge[a - 1].push_back(p(b - 1, w));
	}
	cin >> s >> e;
	s--, e--;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}