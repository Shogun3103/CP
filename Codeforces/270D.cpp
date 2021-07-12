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
#define sx(a) sort(a+1, a+1+n, cmp)
#define X first
#define Y second
#define fill(a, b) memset(a, b, sizeof(a))
#define ed "\n"
#define INF 1e9+7

const int N = 5e3 + 1;
int n, m;
int a[N];

void read()
{
    cin >> n >> m;
    FOR(i, 1, n) {
        double x;
        cin >> a[i] >> x;
    }
}

int dp[N];

void solve()
{
    int ans = 0;
    FOR(i, 1, n) {
        int j = a[i];
        FOD(k, 1, j)
            dp[j] = max(dp[j], dp[k] + 1);
    }
    FOR(i, 1, n)
        ans = max(ans, dp[i]);
    cout << n - ans;
}

int main()
{
    faster;

    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        read();
        solve();
    }

    return 0;
}
