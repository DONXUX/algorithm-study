#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int n, alpha_num;
bool alpha[26];
string word[10];
vector<char> alphabet;
map<char, int, greater<int>> dict;

int solve() {
	for (int i = 0; i < alpha_num; i++)
		dict.insert({ alphabet[i], 0 });

	for (int i = 0; i < n; i++) {
		for (int j = word[i].length() - 1; j >= 0; j--) {
			int ten = pow(10, (word[i].length() - 1) - j);
			dict[word[i][j]] += ten;
		}
	}

	vector<int> val;
	for (int i = 0; i < alpha_num; i++) 
		val.push_back(dict[alphabet[i]]);
	sort(val.begin(), val.end(), greater<int>());

	int sum = 0, cnt = 9;
	for (int i = 0; i < alpha_num; i++) {
		sum += val[i] * cnt--;
	}
	
	return sum;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
		for (int j = 0; j < word[i].length(); j++) {
			if (!alpha[word[i][j] - 'A']) {
				alpha_num++;
				alpha[word[i][j] - 'A'] = true;
				alphabet.push_back(word[i][j]);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}