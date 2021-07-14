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
#define MOD = (int)1000000000 + 7;

const int N = 2e5 + 1;
int a[N];

int c3(int a, int b, int c)
{
    if(a <= b && b <= c)
        return 0;
    if(a >= b && b >= c)
        return 0;
    return 1;
}

int c4(int a, int b, int c, int d)
{
    if(!c3(a, b, c))
        return 0;
    if(!c3(a, b, d))
        return 0;
    if(!c3(a, c, d))
        return 0;
    if(!c3(b, c, d))
        return 0;
    return 1;
}

void solve()
{
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int cnt = 0;

    for(int i=1; i<n; i++)
    {
        if(s[i]!=s[i-1])
        {
            cnt++;
        }
    }
    cout << max(a*n+b*n, a*n + ( (cnt+1)/2 + 1 )*b  ) << '\n';
    return;

}

int main()
{
    faster;

    int t;
    ///t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

