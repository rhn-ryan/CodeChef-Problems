#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n"
#define lcm(x, y) ((x)*(y))/(__gcd(x, y))
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void display(map<ll, vector<ll>> m)
{
    cout << "[ ";
    for (auto c : m)
    {
        cout << "{" << c.first << ", {";
        for (auto c1 : c.second)
            cout << c1 << " ";
        cout << "}  ";
    }
    cout << "]\n";
}

void display(map<ll, vector<ll>> m, ll k)
{
    cout << "{" << k << ", {";
    for (auto c : m[k])
        cout << c << " ";
    cout << "}\n";
}

ll solve ()
{
    ll N, K, cunt{};
    cin >> N >> K;
    vector<ll> v(N);
    map<ll, vector<ll>> m{};
    set<ll> t{};
    for (auto &c : v) {   
        cin >> c;
        m[c].push_back(cunt);
        cunt++;
        // t.insert(c);
    }
    display(m);
    if (m[0].empty())
        return 0;
    multiset<ll> s{};
    ll tc{};
    for (ll i{0}; i <=N+1; i++)
    {
        display (m, i);
        ll count{};
        for (auto c : m[i])
        {
            ll last{-1};
            c = c - last -1;
            count += c*(c+1)/2;
            last = c;
            if (c == m[i].back())
                count += (N-1-c)*(N-c)/2;
        }
        tc += count;
        cout << "tc: " << tc << endl;
        if (K <= tc && K > tc-count)
            return i;
    }
}

int main()
{
    fastio;
    ll T{}; cin >> T;
    while (T--)
    {
        cout << solve () << endl;
    }
    return 0;
}

/* 
3
3 4
1 0 2
3 2
2 1 3
3 6
0 1 2

*/