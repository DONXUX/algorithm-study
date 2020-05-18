#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
int n, k;

int waysToBuy(const vector<int>& psum, int k) {
    const int MOD = 20091101;
    int ret = 0;
    vector<long long> count(k, 0);
    for (int i = 0; i < psum.size(); i++)
        count[psum[i]]++;
    for (int i = 0; i < k; i++)
        if (count[i] >= 2)
            ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
    return ret;
}

int maxBuys(const vector<int>& psum, int k) {
    vector<int> ret(psum.size(), 0), prev(k, -1);
    for (int i = 0; i < psum.size(); i++) {
        if (i > 0) ret[i] = ret[i - 1];
        else ret[i] = 0;
        int loc = prev[psum[i]];
        if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
        prev[psum[i]] = i;
    }
    return ret.back();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> psum(n + 1);
        psum[0] = 0;
        for (int i = 1; i <= n; i++)
            psum[i] = (psum[i - 1] + v[i - 1]) % k;

        cout << waysToBuy(psum, k) << " " << maxBuys(psum, k) << endl;
    }
    return 0;
}
