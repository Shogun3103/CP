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
#define fill(a, b) memset(a, b, sizeof(a))
#define ed "\n"

const int N = 1e5 + 1, MOD = 1e9 + 7, M = 1e6;
ll dp[N];
int k;
ll s[N];
int a, b;

void solve()
{
    cin >> a >> b;

    int ans = s[b] - s[a - 1];
    ans = (ans + MOD) % MOD;

    cout << ans << ed;

}

void init()
{
    //đúng
    FOR(i, 1, k - 1)
        dp[i] = 1;

    //đúng
    dp[0] = 0;
    dp[k] = 2;

    //sai
    FOR(i, k + 1, 100000) {
        dp[i] = dp[i - 1] + dp[i - k];
        dp[i] %= MOD;
    }

    FOR(i, 1, 100000) {
        s[i] = s[i - 1] + dp[i];
        s[i] %= MOD;
    }
}

int main()
{
    faster;

    int t;
    //t = 1;
    cin >> t >> k;
    init();
    while(t--) {
        solve();
    }

    return 0;
}

