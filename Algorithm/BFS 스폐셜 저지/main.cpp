#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int n;
vector<vector<int>> edge;
bool visited[100001];
int result[100001];
int idx = 1;

int bfs(void) {
	if (result[0] != 1) return 0;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		unordered_set<int> s;

		for (int next : edge[n]) {
			if (visited[next]) continue;
			visited[next] = true;
			s.insert(next);
		}
		for (int i = idx; i < idx + s.size(); i++) {
			if (s.count(result[i]) == 0) return 0;
			else q.push(result[i]);
		}
		idx += s.size();
	}
	return 1;
}

void input() {
	cin >> n;
	edge.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 0; i < n; i++) 
		cin >> result[i];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << bfs();

	return 0;
}