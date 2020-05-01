#include <iostream>
#include <algorithm>
using namespace std;
constexpr int INF = 999999999;

int n, s;
int arr[101], pSum[101], ppSum[101], cache[100][11];

int minError(int a, int b) {
	int sum = pSum[b] - (a == 0 ? 0 : pSum[a - 1]);
	int sqSum = ppSum[b] - (a == 0 ?  0 : ppSum[a - 1]);
	int m = int(0.5  + (double)sum / (b - a + 1));
	return sqSum - 2 * m * sum + m * m * (b - a + 1);
}

int quantization(int a, int parts) {
	if (a == n) return 0;
	if (parts == 0) return INF;
	int& ret = cache[a][parts];
	if (ret != -1) return ret;
	ret = INF;

	for (int partSize = 1; a + partSize <= n; partSize++)
		ret = min(ret, quantization(a + partSize, parts - 1) + minError(a, a + partSize - 1));
	
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> s;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		pSum[0] = arr[0];
		ppSum[0] = arr[0] * arr[0];
		for (int i = 1; i < n; i++) {
			pSum[i] = pSum[i - 1] + arr[i];
			ppSum[i] = ppSum[i - 1] + (arr[i] * arr[i]);
		}
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < 11; j++) 
				cache[i][j] = -1;
		cout << quantization(0, s) << endl;
	}

	return 0;
}