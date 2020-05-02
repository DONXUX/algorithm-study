#include <iostream>
#define endl '\n'
using namespace std;

int n, d, p, t, q;
int mat[51][51], deg[51];
double cache[51][101];

double search(int here, int days) {
	if (days == 0) return (here == p ? 1.0 : 0.0);

	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < n; there++) 
		if (mat[here][there])
			ret += search(there, days - 1) / deg[there];
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	cout.precision(8);
	while (c--) {
		cin >> n >> d >> p;
		for (int i = 0; i < n; i++) deg[i] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= d; j++)
				cache[i][j] = -1.0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
				if (mat[i][j] == 1) deg[i]++;
			}
		}
		cin >> t;
		for (int i = 0; i < t; i++) {
			cin >> q;
			cout << search(q, d) << " ";
		}
		cout << endl;
	}

	return 0;
}