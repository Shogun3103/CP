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

int n;
string st;
const int N = 1e5 + 1;
ll dp[N][2];

void solve()
{
    cin >> n >> st;
    st = '.' + st;

    /*FOR(i, 1, n) {
        if(st[i]=='1')
            dp[i][0] = dp[i-1][0] + dp[i-1][1] + 1;
        else dp[i][1] = dp[i-1][1] + dp[i-1][0] + 1;
    }

    cout << max(dp[n][0], dp[n][1]);*/
    int ans = 1;
    FOR(i, 2, n) {
        ans += (st[i-1]!=st[i]);
    }
    cout << min(ans + 2, n);
}

int main()
{
    faster;

    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
