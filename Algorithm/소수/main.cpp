#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
constexpr unsigned int MAX = (unsigned int)4294967295;

int n;
unsigned char sieve[536870913];

inline bool isPrime(int k) {
	return sieve[k >> 3] & (1 << (k & 7));
}

inline void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}

void erato(void) {
	memset(sieve, 255, sizeof(sieve));
	setComposite(0);
	setComposite(1);
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime(i)) 
			for (int j = i * i; j <= n; j += i) 
				setComposite(j);
	} 
}


int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	erato();
	int k;
	cin >> k;
	cout << isPrime(k) << endl;

	return 0;
}