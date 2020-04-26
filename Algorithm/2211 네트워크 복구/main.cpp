#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int, int> p;
constexpr int INF = 999999999;
constexpr int MAX = 1000;

int n, m;
vector<p> edge[MAX];
priority_queue<p, vector<p>, greater<p>> pq;
int dist[MAX];
int previous[MAX] = { -1, };
bool visited[MAX];

void solve() {
	fill(dist, dist + MAX, INF);
	pq.push(p(0, 0));
	dist[0] = 0;
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
				previous[next] = cur;
				pq.push(p(dist[next], next));
			}
		}
	}
	cout << n - 1 << endl;
	for (int i = 1; i < n; i++) 
		cout << previous[i] + 1 << " " << i + 1 << endl;
}

void input() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a - 1].push_back(p(b - 1, c));
		edge[b - 1].push_back(p(a - 1, c));
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();

	return 0;
}