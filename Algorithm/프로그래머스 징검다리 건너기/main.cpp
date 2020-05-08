#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool calc(vector<int>& stones, int x, int k) {
	int con_zero = 0;
	for (int i = 0; i < stones.size(); i++) {
		stones[i] -= x;
		if (stones[i] <= 0) con_zero++;
		else con_zero = 0;
		stones[i] += x;

		if (con_zero >= k)
			return false;
	}
	return true;
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	int lo = 0, hi = 200000000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (calc(stones, mid, k)) lo = mid;
		else hi = mid;
	}
	answer = hi;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> stones(n);
	for (int i = 0; i < n; i++) 
		cin >> stones[i];

	cout << solution(stones, k);
	return 0;
}