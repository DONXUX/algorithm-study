#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int n, w, cnt;
string name[105], picked[105];
int volume[105], need[105], cache[1005][105];

int packing(int capacity, int item) {
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return cache[capacity][item];
	
	if (capacity >= volume[item]) 
		ret = packing(capacity - volume[item], item + 1) + need[item];
	return ret = max(ret, packing(capacity, item + 1));
}

void reconstruct(int capacity, int item) {
	if (item == n) return;
	if (packing(capacity, item) == packing(capacity, item + 1)) 
		reconstruct(capacity, item + 1);
	else {
		picked[cnt++] = name[item];
		reconstruct(capacity - volume[item], item + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> w;
		for (int i = 0; i < n; i++) 
			cin >> name[i] >> volume[i] >> need[i];
		for (int i = 0; i <= w; i++) 
			for (int j = 0; j < n; j++) 
				cache[i][j] = -1;

		reconstruct(w, 0);
		cout << packing(w, 0) << " " << cnt << endl;
		for (int i = 0; i < cnt; i++) cout << picked[i] << endl;
		cnt = 0;
	}

	return 0;
}