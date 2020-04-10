#include <iostream>
#include <string>
using namespace std;

int n, m, kind, a, b;

int parents[1000001];
int ranks[1000001];

int findSet(int u) {
	// 루트노드이면
	if (parents[u] == u) return u;
	// 경로 압축
	return parents[u] = findSet(parents[u]);
}

string sameSet(void) {
	a = findSet(a), b = findSet(b);
	if (a == b) return "YES\n";
	else return "NO\n";
}

string unionSet(void) {
	a = findSet(a), b = findSet(b);
	
	if (a == b) return "";

	// 집합들의 높이가 다르면 rank가 높은 집합이 부모가 됨.
	if (ranks[a] > ranks[b]) swap(a, b);
	parents[a] = b;

	if (ranks[a] == ranks[b]) ranks[b]++;
	return "";
}

string solve(void) {
	switch (kind) {
	case 0: return unionSet(); break;
	case 1: return sameSet(); break;
	}
}

void input(void) {
	cin >> kind >> a >> b;
}

void init(void) {
	for (int i = 0; i <= n; i++) {
		parents[i] = i;
		ranks[i] = 1;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	init();
	while (m--) {
		input();
		cout << solve();
	}

	return 0;
}