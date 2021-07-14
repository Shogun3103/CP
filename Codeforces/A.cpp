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

struct Data
{
    int p, h;
};

bool cmp(Data a, Data b)
{
    return a.p < b.p;
}

const int N = 1e5 + 10, MOD = 1e9 + 7;
Data a[N];
int dp[N][3];

///0 không cắt
///1 đổ trái
///2 đổ phải

void solve()
{
    int n;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].p >> a[i].h;
    }

    a[0] = {-MOD, 0};
    a[n + 1] = {MOD, 0};

    int ans = 0;

    FOR(i, 1, n) {
        ///dp[i][0];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if(a[i - 1].p + a[i - 1].h < a[i].p)
            dp[i][0] = max(dp[i][0], dp[i - 1][2]);

        ///dp[i][1]
        if(a[i - 1].p < a[i].p - a[i].h)
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
        if(a[i - 1].p + a[i - 1].h < a[i].p - a[i].h)
            dp[i][1] = max(dp[i - 1][2] + 1, dp[i][1]);

        ///dp[i][2]
        dp[i][2] = max(dp[i - 1][0] + 1, dp[i][2]);
        if(a[i - 1].p + a[i - 1].h < a[i].p)
            dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
        dp[i][2] = max(dp[i][2], dp[i - 1][1] + 1);

        ans = max({ans, dp[i][1], dp[i][0], dp[i][2]});
    }

    cout << ans;
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

