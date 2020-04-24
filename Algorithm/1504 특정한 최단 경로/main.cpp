#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
constexpr int INF = 999999999;
constexpr int MAX_V = 800;

int n, e, v1, v2;
vector<p> edge[MAX_V];

int getSp(int start, int end) {
	priority_queue<p, vector<p>, greater<p>> pq;
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	bool visited[MAX_V] = { 0 };
	pq.push(p(0, start));
	dist[start] = 0;

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
	return dist[end];
}

int solve() {
	int r1 = getSp(0, v1);
	int r2 = getSp(v1, v2);
	int r3 = getSp(v2, n - 1);
	int r4 = getSp(0, v2);
	int r5 = getSp(v2, v1);
	int r6 = getSp(v1, n - 1);
	int ret1 = r1 + r2 + r3;
	int ret2 = r4 + r5 + r6;
	
	if (r1 == INF || r2 == INF || r3 == INF) ret1 = INF;
	if (r4 == INF || r5 == INF || r6 == INF) ret2 = INF;
	if (ret1 == INF && ret2 == INF) return -1;
	else return ret1 < ret2 ? ret1 : ret2;
}

void input() {
	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge[a - 1].push_back(p(b - 1, c));
		edge[b - 1].push_back(p(a - 1, c));
	}
	cin >> v1 >> v2;
	v1--, v2--;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}