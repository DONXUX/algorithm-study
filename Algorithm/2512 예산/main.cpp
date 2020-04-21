#include <iostream>
using namespace std;
 
int n, country;
int money[10000];

int solve() {
    
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> money[i];
    cin >> country;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout << solve();

    return 0;
}