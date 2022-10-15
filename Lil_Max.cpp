#include <bits/stdc++.h>
typedef long long ll;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{
    fastio;
    ll T{}; cin >> T;
    while (T--)
    {
        ll N; cin >> N;
        if (N <= 2)
        {
            cout << "1\n";
            continue;
        }
        ll t = 2, maxi = INT_MIN;
        for (ll i{2}; i <= N;)
        {
            if (i*2 <= N) {
                i*=2;
                maxi = max(maxi, i-i/2);
            }
            else {
                maxi = max(maxi, N-i+1);
                i*=2;
            }
        }
        cout << maxi << endl;
    }
    return 0;
}