#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(i,a,b) for(__typeof(b) i=a; i<=b; i++)
#define FOr(i,a,b) for(__typeof(b) i=a; i<b; i++)
#define FOD(i,a,b) for(__typeof(b) i=b; i>=a; i--)
#define FOd(i,a,b) for(__typeof(b) i=b; i>=a; i--)
#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define vt vector
#define ii pair<int,int>
#define X first
#define Y second
//#define fill(a, b) memset(a, b, sizeof(a))
#define ed "\n"

const int N = 1e5 + 1;
int a[N];
ll s[N];

void solve()
{
    int n;
    cin >> n;
    FOR(i, 1, n) {
        char x;
        cin >> x;
        a[i] = x - '0';
        s[i] = s[i - 1] + a[i];
    }

    ll ans = 0;

    map<int, int> mp;

    mp[1]++;
    FOR(i, 1, n) {
        ans += mp[s[i] - i + 1];
        ++mp[s[i] - i + 1];
    }

    cout << ans << ed;
}

int main()
{
    faster;

    int t;
    //t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

