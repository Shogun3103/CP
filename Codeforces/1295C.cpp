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

const int N = 1e5 + 1, MOD = 1e9 + 7;
int a[N], l[N], r[N];

void solve()
{
    int n;
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i];

    int ans = 2;

    if(n <= 2) {
        cout << n;
        return;
    }

    l[1] = 1;
    FOR(i, 1, n) {
        l[i]  = (a[i] > a[i - 1] ? l[i - 1] + 1 : 1);
        ans = max(ans, l[i - 1] + 1);
    }

    r[n] = 1;
    FOD(i, 1, n) {
        r[i] = (a[i] < a[i + 1] ? r[i + 1] + 1 : 1);
        ans = max(ans, r[i + 1] + 1);
    }

    FOR(i, 1, n) {
        if(a[i + 1] - a[i - 1] >= 2)
            ans = max(ans, l[i - 1] + r[i + 1] + 1);
    }

    cout << ans;
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

