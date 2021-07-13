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

const int N = 1e6 + 10, MOD = 1e9 + 7, M = 1e6;
int dp[N];
ii pos[N];

    //tính số beacon hủy ít nhất -> không bị hủy lớn nhất
    //dp[i] số beacon không bị hủy lớn nhất tại i

void solve()
{
    int n;
    cin >> n;
    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;
        pos[a].X = 1;
        pos[a].Y = b;
    }

    FOR(i, 0, 1000000) {
        if(i == 0) {
            if(pos[i].X) {
                if(pos[i + 1].X - pos[i + 1].Y - 1 <= pos[i].X)
                    dp[i] = 0;
                else
                    dp[i] = 1;
            }
        }
        if(!pos[i].X)
            dp[i] = dp[i - 1];
        else {
            if(i - 1 - pos[i].Y >= 0)
                dp[i] = dp[i - 1 - pos[i].Y] + 1;
            else
                dp[i] = 1;
        }
    }

    int ans = 0;

    FOR(i, 0, 1000000)
        ans = max(ans, dp[i]);

    cout << n - ans;
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

