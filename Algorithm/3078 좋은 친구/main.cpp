#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> vec[21];
int n, k;

long long solve() {
	for (int i = 0; i < 21; i++)
		sort(vec[i].begin(), vec[i].end());

	long long ans = 0;
	for (int i = 0; i < 21; i++) {
		vec[i].push_back(1e9);
		for (int j = 0; j < vec[i].size() - 1; j++) {
			auto iter = upper_bound(vec[i].begin(), vec[i].end(), vec[i][j] + k); iter--;
			auto index = iter - vec[i].begin();
			ans += index - j;
		}
	}
	return ans;
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string input; cin >> input;
		vec[input.size()].push_back(i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	cout << solve();

	return 0;
}