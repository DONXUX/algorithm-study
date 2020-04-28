#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, seq[500], cache[500];

int maxLength(int x) {
	int maxLen = 0;
	int& ret = cache[x];
	if (ret != -1) return ret;
	for (int i = x + 1; i < n; i++) 
		if(seq[x] < seq[i])
			maxLen = max(maxLen, maxLength(i));
	
	return ret = maxLen + 1;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> seq[i];
			cache[i] = -1;
		}
		int maxLen = 0;
		for (int i = 0; i < n; i++) 
			maxLen = max(maxLen, maxLength(i));
		cout << maxLen << endl;
	}

	return 0;
}