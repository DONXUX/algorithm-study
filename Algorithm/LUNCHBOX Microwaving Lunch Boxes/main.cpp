#include <iostream>
#define endl '\n'
using namespace std;

int n;
int m[10000], e[10000];

int solve() {

}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> e[i];

		cout << solve() << endl;
	}

	return 0;
}