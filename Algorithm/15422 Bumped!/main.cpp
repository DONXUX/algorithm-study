#include <iostream>
#include <queue>
#include <vector>
using namespace std;
constexpr long long INF = 9999999999999;
constexpr int MAX = 50000;
typedef pair <long long, long long> p;

int n, m, f, s, t;
vector<p> edge[MAX];
priority_queue <p, vector<p>, greater<p>> pq;
long long dist[MAX];
bool flight[MAX];
bool visited[MAX];

long long solve() {
	fill(dist, dist + MAX, INF);
	pq.push({ 0,s });
	dist[s] = 0;
	while (!pq.empty()) {
		long long cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& i : edge[cur]) {
			long long next = i.first, ncost = i.second;
			if (dist[next] > dist[cur] + ncost) {
				dist[next] = dist[cur] + ncost;
				if (ncost == 0 && !flight[cur]) flight[next] = true;
				else if (ncost == 0 && flight[cur]) continue;
				else flight[next] = flight[cur];
				pq.push(p(dist[next], next));
			}
		}
	}

	return dist[t];
}

void input() {
	cin >> n >> m >> f >> s >> t;
	int x, y, c;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c;
		edge[x].push_back(p(y, c));
		edge[y].push_back(p(x, c));
	}
	int u, v;
	for (int i = 0; i < f; i++) {
		cin >> u >> v;
		edge[u].push_back(p(v, 0));
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}