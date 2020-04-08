#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
vector<int> edge[100001];
bool visited[100001];
int result[100001];
int idx = 0;
int sol = 1;

void dfs(int now) {
	if (visited[now]) return;
	visited[now] = true;
	unordered_set<int> s;

	for (int next : edge[now]) {
		if (visited[next]) continue;
		s.insert(next);
	}

	for (int i = 0; i < s.size(); i++) {
		if (s.count(result[idx + 1]) == 0) {
			sol = 0;
			return;
		}
		dfs(result[++idx]);
	}
}

int solve() {
	dfs(1);
	return sol;
}

void input() {
	cin >> n;
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
	cout << solve();

	return 0;
}