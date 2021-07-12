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

const int N = 101;
int n;
int a[N];

void read()
{
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i];
}

int dp[N][4];

void solve()
{
    int ans = 0;
    FOR(i, 1, n) {
        if(!a[i])
            ++ans;
        else
        if(a[i]==1||a[i]==2) {
            if(i>1 && a[i-1]==a[i]) {
                a[i] = 0;
                ++ans;
            }
        } else if (i>1 && i<n && a[i-1] > 0 && a[i-1] < 3)
            a[i] = (a[i-1]==1) ? 2 : 1;
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
        read();
        solve();
    }

    return 0;
}
