#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

int m, q, n;
string words[501];
double start[501], T[501][501], M[501][501], cache[102][502];
int choice[102][502], R[101];

double recongize(int s, int p) {
	if (s == n) return 0;
	double& ret = cache[s][p];
	if (ret != 1.0) return ret;
	ret = -1e200;

	int& choose = choice[s][p];
	for (int i = 1; i <= m; i++) {
		double cand = T[p][i] + M[i][R[s]] + recongize(s + 1, i);
		if (ret < cand) {
			ret = cand;
			choose = i;
		}
	}
	return ret;
}

string reconstruct(int s, int p) {
	int choose = choice[s][p];
	string ret = words[choose];
	if (s < n - 1)
		ret = ret + " " + reconstruct(s + 1, choose);
	return ret;
}

string solve() {
	recongize(0, 0);
	return reconstruct(0, 0);
}

void input() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			if (words[j] == s) {
				R[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= m; j++) 
			cache[i][j] = 1.0;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> m >> q;
	for (int i = 1; i <= m; i++)
		cin >> words[i];
	for (int i = 1; i <= m; i++)
		cin >> start[i];
	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 0) T[i][j] = log(start[j]);
			else  cin >> T[i][j], T[i][j] = log(T[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> M[i][j], M[i][j] = log(M[i][j]);

	while (q--) {
		input();
		cout << solve() << endl;
	}

	return 0;
}