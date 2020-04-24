#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int, int> p;
constexpr int INF = 9999999;
constexpr int MAX_V = 20000;

int v, e, k;
vector<p> edge[MAX_V];
priority_queue<p, vector<p>, greater<p>> pq;
int dist[MAX_V];
bool visited[MAX_V];

void solve() {
	fill(dist, dist + MAX_V, INF);
	pq.push(p(0, k));
	dist[k] = 0;
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
	for (int i = 0; i < v; i++) {
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
}

void input() {
	cin >> v >> e >> k;
	k--;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u - 1].push_back(p(v - 1, w));
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	solve();

	return 0;
}