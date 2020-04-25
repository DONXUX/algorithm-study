#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<double, int> p;
constexpr int MAX = 100;
constexpr int INF = 99999999;

double ax, ay, bx, by;
int n;
pair<double, double> canons[MAX];
priority_queue<p, vector<p>, greater<p>> pq;
vector<p> edge[MAX + 2];
double dist[MAX + 2];
bool visited[MAX + 2];

double getSp() {
	fill(dist, dist + MAX + 2, INF);
	pq.push(p(0.0, n));
	dist[n] = 0.0;
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;

		for (auto& i : edge[cur]) {
			int next = i.second;
			double d = i.first;
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push(p(dist[next], next));
			}
		}
	}

	return dist[n + 1];
}

double getWeight(int type, double x1, double y1, double x2, double y2) {
	double d = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
	if (type == 0) return d / 5.0;
	else return 2.0 + (abs(d - 50.0) / 5.0);
}

void makeGraph() {
	// a -> b
	edge[n].push_back(p(getWeight(0, ax, ay, bx, by), n + 1));
	// a -> 대포들
	for (int i = 0; i < n; i++) 
		edge[n].push_back(p(getWeight(0, ax, ay, canons[i].first, canons[i].second), i));
	// 대포들 - > b
	for (int i = 0;  i < n; i++) 
		edge[i].push_back(p(getWeight(1, canons[i].first, canons[i].second, bx, by), n + 1));
	// 대포 -> 대포
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			edge[i].push_back(p(getWeight(1, canons[i].first, canons[i].second, canons[j].first, canons[j].second), j));
		}
	}
}

double solve() {
	makeGraph();
	return getSp();
}

void input() {
	cin >> ax >> ay >> bx >> by;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> canons[i].first >> canons[i].second;
}


int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}