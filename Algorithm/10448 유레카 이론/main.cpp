#include <iostream>
#define endl '\n'
using namespace std;

int tri[45];
bool arr[4000];

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i < 45; i++) 
		tri[i] = i * (i + 1) / 2;
	for (int i = 1; i < 45; i++)
		for (int j = 1; j < 45; j++)
			for (int k = 1; k < 45; k++)
				arr[tri[i] + tri[j] + tri[k]] = true;
	while (t--) {
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}

	return 0;
}