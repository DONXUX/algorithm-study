#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<vector<int>> counter;
int order[3][20];

int solve(void) {
	
}

void input(void) {
	cin >> n >> k;
	counter.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int vs;
			cin >> vs;
			switch (vs) {
			case 0: counter[j].push_back(i); break;
			case 1: continue;
			case 2: counter[i].push_back(j); break;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << solve();

	return 0;
}