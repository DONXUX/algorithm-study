#include <iostream>
#include <queue>
#include <vector>
using namespace std;
constexpr int INF = 99999999;
constexpr int MAX = 10000;
typedef long long ll;
typedef pair<ll, pair<int, int>> p;

int n, m, k;
vector<pair<int, int>> edge[MAX];
priority_queue<p, vector<p>, greater<p>> pq;
int dist[MAX], check[MAX];
bool visited[MAX];

int solve() {
	fill(dist, dist + MAX, INF);
	dist[0] = 0;
	pq.push(p(0, 0));
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
			if (dist[next] > dist[cur] + ncost) {
				if (ncost == 0 && (check[cur] < k)) check[next] = check[cur] + 1;
				else if (ncost == 0 && (check[cur] >= k)) continue;
				else check[next] = check[cur];
				dist[next] = dist[cur] + ncost;
				pq.push(p(dist[next], next));
			}
		}
	}

	return dist[n - 1];
}

void input() {
	cin >> n >> m >> k;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a - 1].push_back({ b - 1,c });
		edge[b - 1].push_back({ a - 1,c });
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}