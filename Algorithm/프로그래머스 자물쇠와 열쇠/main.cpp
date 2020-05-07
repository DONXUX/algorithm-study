#include <iostream>
#include <vector>
#include <string>
using namespace std;

void rotation(int m, vector<vector<int>>& key) {
	vector<vector<int>> tmp(m);
	for (int i = 0; i < m; i++)
		tmp[i].resize(m);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			tmp[j][m - i - 1] = key[i][j];
	copy(tmp.begin(), tmp.end(), key.begin());
}

bool put(int x, int y, int m, int n, const vector<vector<int>>& key, vector<vector<int>> extend_lock) {
	for (int i = x; i < x + m; i++)
		for (int j = y; j < y + m; j++)
			extend_lock[i][j] += key[i - x][j - y];

	for (int i = m - 1; i < m - 1 + n; i++)
		for (int j = m - 1; j < m - 1 + n; j++)
			if (extend_lock[i][j] != 1) return false;

	return true;
}

bool compare(int n, int m, const vector<vector<int>>& key, const vector<vector<int>> lock) {
	int extend_m = n + (2 * (m - 1));
	vector<vector<int>> extend_lock(extend_m);
	for (int i = 0; i < extend_m; i++)
		extend_lock[i].resize(extend_m);
	copy(lock.begin(), lock.end(), extend_lock.begin());

	for (int i = 0; i < m + n - 1; i++)
		for (int j = 0; j < m + n - 1; j++)
			if (put(i, j, m, n, key, extend_lock)) return true;

	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	int m = key[0].size(), n = lock[0].size();
	int extend_m = n + (2 * (m - 1));

	// 자물쇠 공간 확장
	vector<vector<int>> extend_lock(extend_m);
	for (int i = 0; i < extend_m; i++)
		extend_lock[i].resize(extend_m, 0);

	for (int i = m - 1; i < m - 1 + n; i++)
		for (int j = m - 1; j < m - 1 + n; j++)
			extend_lock[i][j] = lock[i - (m - 1)][j - (m - 1)];


	for (int i = 0; i < 4; i++) {
		if (compare(n, m, key, extend_lock)) {
			answer = true; break;
		}
		rotation(m, key);
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> key(m), lock(n);
	for (int i = 0; i < m; i++) {
		key[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> key[i][j];
	}

	for (int i = 0; i < n; i++) {
		lock[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> lock[i][j];
	}

	cout << solution(key, lock);

	return 0;
}