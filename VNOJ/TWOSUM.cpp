#include <bits/stdc++.h>

using namespace std;

//#define INF 1e12
#define ll long long
#define FOR(i,a,b) for(__typeof(b) i=a; i<=b; i++)
#define FOr(i,a,b) for(__typeof(b) i=a; i<b; i++)
#define FOD(i,a,b) for(__typeof(b) i=b; i>=a; i--)
#define FOd(i,a,b) for(__typeof(b) i=b; i>=a; i--)
#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define vt vector
#define ed '\n';
#define ii pair<int,int>
#define sx(a) sort(a+1, a+1+n, cmp)
#define v second

int n;
const int N = 5e3 + 1;
int a[N];
ll s[N];

void read()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i], s[i] = s[i-1] + a[i];
}


void solve()
{
    int ans = 0;

    FOR(i, 1, n) {
        int k = i;
        FOR(j, i+1, n) {
            if(k==j) break;
            while(k<j && 2*(s[k] - s[i-1]) < s[j] - s[i-1])
                ++k;
            if(2*(s[k] - s[i-1]) == s[j] - s[i-1])
                ans = max(ans, j-i+1);
        }
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
