#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
typedef pair<int, int> p;
constexpr int INF = 1e9;
constexpr int MAX = 500;

int n, m, s, d;
vector<p> edge[MAX], edge_r[MAX];
int dist[MAX];
bool check[MAX][MAX];

// BFS
void disableEdge() {
	queue<int> q;
	q.push(d);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == s) continue;
		for (auto &i : edge_r[cur]) {
			int previous = i.first, cost = i.second;
			if (dist[cur] == dist[previous] + cost) {
				check[previous][cur] = true;
				q.push(previous);
			}
		}
	}
}

// 다익스트라
void dijkstra() {
	priority_queue<p, vector<p>, greater<p>> pq;
	fill(dist, dist + MAX, INF);
	pq.push(p(0, s));
	bool visited[MAX] = { false };
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
			int next = i.first, ncost = i.second;
			if ((dist[next] > dist[cur] + ncost) && !check[cur][next]) {
				dist[next] = dist[cur] + ncost;
				pq.push(p(dist[next], next));
			}
		}
	}
}

int solve() {
	dijkstra();
	disableEdge();
	dijkstra();
	for (int i = 0; i < n; i++) {
		edge[i].clear();
		edge_r[i].clear();
	}
	memset(check, false, MAX * MAX);
	if (dist[d] == INF) return -1;
	else return dist[d];
}

bool input() {
	cin >> n >> m;
	if (n == 0 && m == 0) return false;
	cin >> s >> d;
	int u, v, d;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> d;
		edge[u].push_back(p(v, d));
		edge_r[v].push_back(p(u, d));
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	while (input()) 
		cout << solve() << endl;

	return 0;
}