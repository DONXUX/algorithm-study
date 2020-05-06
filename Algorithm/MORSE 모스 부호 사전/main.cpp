#include <iostream>
#include <algorithm>
using namespace std;
constexpr int MAX = 1000000000 + 100;

int n, m, k, skip;
int bino[201][201];

void calcBino() {
	memset(bino, 0, sizeof(bino)); 
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = min(MAX, bino[i - 1][j] + bino[i - 1][j - 1]);
	}
	
}

void generate(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	// skip보다 경우의 수가 작거나 같으면 건너 뛴다. 이유 : 어차피 skip보다 같거나 작으면 그 경우의 수 중에 답이 없기때문. 
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	calcBino();
	while (c--) {
		cin >> n >> m >> k;
		skip = k - 1;
		string s = "";
		generate(n, m, s);
	}
	return 0;
}