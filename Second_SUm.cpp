#include <bits/stdc++.h>
typedef long long ll;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll solve ()
{
    string N; char D;
    cin >> N >> D;
    ll l = N.length();
    if (N.find(D) >= l || N.find(D) < 0)
        return 0;
    ll sum {}, p = N.find(D);
    while (p < l && p >=0) {
        ll num = stoi(N), temp;
        if (p == l-1)
            temp = 1;
        else
            temp = pow(10, l-1-p) - stoi(N.substr(p+1));
        sum += temp;
        num += temp;
        N = to_string(num);
        p = N.find(D);
    }
    return sum;
}

int main()
{
    fastio;
    ll T{}; cin >> T;
    while (T--) {
        cout << solve() << "\n"; 
    }
    return 0;
}