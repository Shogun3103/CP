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

const int N = 101, INF = 1e9 + 7;
int dp[N][2];

void add(int &a, int b)
{
    a += b;
    if(a >= INF)
        a -= INF;
}

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;

    //dp[n][1];

    dp[0][0] = 1;
    dp[0][1] = 0;

    FOR(i, 1, n) {
        dp[i][0] = dp[i][1] = 0;
        FOR(j, 1, k) {
            if(i - j < 0)
                break;
            if(j < d) {
                add(dp[i][0], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            } else {
                add(dp[i][1], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
        }
    }

    cout << dp[n][1];
}

int main()
{
    faster;

    int t;
    t = 1;
    //cin >> t;
    while(t--)
    solve();

    return 0;
}
