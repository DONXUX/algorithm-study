#include <iostream>
#include <stack>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, fence[20002];

int solve() {
	int area = 0;
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n + 2; i++) {
		while (!s.empty() && (fence[s.top()] >= fence[i])) {
			int j = s.top();
			s.pop();
			int len = -1;
			if (!s.empty()) len = i - s.top() - 1;
			else len = i;
			area = max(area, len * fence[j]);
		}
		s.push(i);	
	}
	return area;
}

void input() {
	cin >> n;
	fence[0] = fence[n + 1] = 0;
	for (int i = 1; i <= n; i++) 
		cin >> fence[i];
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		input();
		cout << solve() << endl;
	}
	return 0;
}