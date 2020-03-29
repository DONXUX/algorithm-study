#include <iostream>
#include <vector>
using namespace	std;

struct OptimizedDisjointSet {
	vector<int> parent, rank;
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) 
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u); v = find(v);

		if (u == v) return;

		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;

		// 두 트리의 높이가 같은 경우에는 결과 트리를 rank을 1 높여준다.
		if (rank[u] == rank[v]) ++rank[v];
	}
};

struct NaiveDisjointSet {
	vector<int> parent;
	NaiveDisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; i++) 
			parent[i] = i;
	}

	int find(int u) const {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u); v = find(v);

		if (u == v) return;
		parent[u] = v;
	}
};

int main(void) {
	OptimizedDisjointSet set1(10);
	cout << set1.find(5) << endl;
	set1.merge(5, 6);
	set1.merge(5, 1);
	cout << set1.find(6) << endl;
	cout << set1.find(1) << endl;
	cout << set1.find(5) << endl;

	return 0;
}