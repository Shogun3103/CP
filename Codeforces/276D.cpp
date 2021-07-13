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

ll dp[70][2][2][2][2];
string s1, s2;

ll calc(int p, int l1, int l2, int r1, int r2)
{
    if(p == sz(s1))
        return 0;
    if(dp[p][l1][l2][r1][r2] != -1)
        return dp[p][l1][l2][r1][r2];
    int min1 = 0, max1 = 1;

    if ((l1==0) && (s1[p]=='1'))
        min1=1;
    if ((l2==0) && (s2[p]=='0'))
        max1=0;
    int min2=0,max2=1;
    if ((r1==0) && (s1[p]=='1'))
        min2=1;
    if ((r2==0) && (s2[p]=='0'))
        max2=0;
    ll res=0;
    FOR(i,min1,max1)
        FOR(j,min2,max2)
        {
            int v=(i^j);
            ll toadd=0;
            if (v==1)
            {
                int step=s1.size()-p-1;
                toadd=(1ll<<step);
            }
            int nfl1=l1,nfl2=l2,nfr1=r1,nfr2=r2;
            if (i>s1[p]-'0')
                nfl1=1;
            if (i<s2[p]-'0')
                nfl2=1;
            if (j>s1[p]-'0')
                nfr1=1;
            if (j<s2[p]-'0')
                nfr2=1;
            res=max(res,toadd+calc(p+1,nfl1,nfl2,nfr1,nfr2));
        }
    return dp[p][l1][l2][r1][r2] = res;
}

string getbit(ll n)
{
    string res = "";
    while(n) {
        res += ((n & 1) + '0');
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve(ll l, ll r)
{
    s1 = getbit(l);
    s2 = getbit(r);
    while(sz(s1) < sz(s2))
        s1 = '0' + s1;
    fill(dp, -1);
    ll res = calc(0, 0, 0, 0, 0);
    cout << res;
}

int main()
{
    faster;

    int t;
    t = 1;
    ll l, r;
    cin >> l >> r;
    //cin >> t >> k;
    while(t--) {
        solve(l, r);
    }

    return 0;
}

