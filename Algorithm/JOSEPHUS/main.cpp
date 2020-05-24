#include <iostream>
#include <list>
using namespace std;

int n, k;

void input(void) {
	cin >> n >> k;
}

void solve() {
	list<int> survivors;
	for (int i = 1; i <= n; i++) survivors.push_back(i);
	
	list<int>::iterator kill = survivors.begin();
	while (n > 2) {
		kill = survivors.erase(kill);
		if (kill == survivors.end()) kill = survivors.begin();
		n--;
		for (int i = 0; i < k - 1; i++) {
			kill++;
			if (kill == survivors.end())kill = survivors.begin();
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		input();
		solve();
	}

	return 0;
}