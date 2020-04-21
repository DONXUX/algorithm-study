#include <iostream>
#include <stack>
using namespace std;

stack<char> s;

string solve() {
	string str, result = "";
	cin >> str;
	for (char c : str) {
		switch (c) {
		case '+': 
			while (!s.empty() && s.top() != '(')
				result += s.top(), s.pop();
			s.push(c);
			break;
		case '-': 
			while (!s.empty() && s.top() != '(')
				result += s.top(), s.pop();
			s.push(c);
			break;
		case '*': 
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
				result += s.top(), s.pop();
			s.push(c);
			break;
		case '/': 
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
				result += s.top(), s.pop();
			s.push(c);
			break;
		case '(': 
			s.push(c);  
			break;
		case ')': 
			while (s.top() != '(') 
				result += s.top(), s.pop();
			s.pop();
			break;
		default:
			result += c;
		}
	}

	while (!s.empty()) 
		result += s.top(), s.pop();
	
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << solve();

	return 0;
}