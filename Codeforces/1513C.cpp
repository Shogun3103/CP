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

const int N = 2e5 + 1, MOD = 1e9 + 7;
int dp[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;

    while(n > 0) {
        int x = n % 10;
        ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
        ans %= MOD;
        n /= 10;
    }
    cout << ans << ed;
}

int main()
{
    faster;

    FOR(i, 0, 8)
        dp[i] = 2;
    dp[9] = 3;
    FOR(i, 10, 200010)
        dp[i] = (dp[i-10] + dp[i-9]) % MOD;
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
