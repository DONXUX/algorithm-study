#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int n, m;
double cache[1001][2001];

double climb(int days, int climbed) {
	if (days == m) return n <= climbed ? 1 : 0;
	double& ret = cache[days][climbed];
	if (ret != -1) return cache[days][climbed];

	return ret = (0.25 * climb(days + 1, climbed + 1)) + (0.75 * climb(days + 1, climbed + 2));
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	cout.precision(10);
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < 2 * n; j++) 
				cache[i][j] = -1;

		cout << climb(0, 0) << endl;
	}

	return 0;
}