#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
constexpr int MAX = 100000;
constexpr long long INF = 9999999999999;

int n, m, d, e;
long long height[MAX], value[MAX];
vector<p> edge[MAX];
long long dist[2][MAX];

void calSp(int s, int type) {
	fill(dist[type], dist[type] + MAX, INF);
	priority_queue<p, vector<p>, greater<p>> pq;
	bool visited[MAX] = { false, };
	pq.push(p(0, s));
	dist[type][s] = 0;
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
			if ((dist[type][next] > dist[type][cur] + d) && (height[next] > height[cur])) {
				dist[type][next] = dist[type][cur] + d;
				pq.push(p(dist[type][next], next));
			}
		}
	}
}

void solve() {
	calSp(0, 0);
	calSp(n - 1, 1);
	
	fill(value, value + MAX, -INF);
	for (int i = 0; i < n; i++) {
		if (dist[0][i] == INF || dist[1][i] == INF) continue;
		value[i] = (height[i] * e) - ((dist[0][i] + dist[1][i]) * d);
	}

	long long max_value = -INF;
	for (int i = 1; i < n - 1; i++)
		max_value = max(max_value, value[i]);

	if (max_value == -INF) cout << "Impossible";
	else cout << max_value;
}

void input() {
	cin >> n >> m >> d >> e;
	for (int i = 0; i < n; i++) 
		cin >> height[i];
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a - 1].push_back(p(b - 1, c));
		edge[b - 1].push_back(p(a - 1, c));
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	solve();

	return 0;
}