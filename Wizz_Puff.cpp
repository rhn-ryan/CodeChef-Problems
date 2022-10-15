#include <bits/stdc++.h>
typedef long long ll;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll solve ()
{
    ll X; cin >> X;
    if (X <= 1)
        return X+1;
    if (ceil(log2(X)) == floor(log2(X)))
        return X;
    ll t = 2;
    while (t*2 < X)
        t *= 2;
    if (X  == t*2-1)
        return t*2;
    return t;
}

int main()
{
    fastio;
    ll T{}; cin >> T;
    while (T--) {
        cout << solve () << "\n";
    }
    return 0;
}

/* 
4
6
7
8
9

*/