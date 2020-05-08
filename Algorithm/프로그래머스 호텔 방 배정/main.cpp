#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

// 다음 배정될 방 찾기
long long find(long long u) {
	if (!m[u]) return u;
	return m[u] = find(m[u]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (long long n : room_number) {
		if (!m[n]) {
			answer.push_back(n);
			m[n] = find(n + 1);
		}
		else {
			long long next = find(n);
			answer.push_back(next);
			m[next] = find(next + 1);
		}
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	long long n, k;
	cin >> n >> k;
	vector<long long> room_number(n);
	for (int i = 0; i < n; i++) 
		cin >> room_number[i];

	vector<long long> result = solution(k, room_number);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	
	return 0;
}