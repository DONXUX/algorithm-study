#include <iostream>
#include <vector>
#include <string>
#define endl '\n';
using namespace std;
int n;
vector<int> arr1, arr2;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		int or_arr = arr1[i] | arr2[i];
		string s;
		for (int j = 0; j < n; j++) {
			char c = ((or_arr >> (n - j - 1)) & 1) + '0';
			s += c == '0' ? ' ' : '#';
		}
		answer.push_back(s);
	}
	return answer;
}

void input() {
	cin >> n;
	for (int i = 0; i < 5; i++) {
		int tmp;
		cin >> tmp;
		arr1.push_back(tmp);
	}
	for (int i = 0; i < 5; i++) {
		int tmp;
		cin >> tmp;
		arr2.push_back(tmp);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	vector<string> sol = solution(n, arr1, arr2);
	for (string s : sol) 
		cout << s << endl;
	
	return 0;
}