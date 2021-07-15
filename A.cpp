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
#define MOD (ll)1e9 + 7;

const int N = 1e5 + 1;
int low[N], num[N], tDfs, scc, comp[N], a[N], mini[N], cnt[N];
vt<int> g[N];
stack<int> st;

void tarjan(int u)
{
    low[u] = num[u] = ++tDfs;
    st.push(u);
    for(int v:g[u]) {
        if(num[v])
            low[u] = min(low[u], num[v]);
        else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == num[u]) {
        ++scc;
        int v;
        do {
            v = st.top();
            st.pop();
            low[v] = num[v] = MOD;
            comp[v] = scc;
        } while(u != v);
    }
}

void solve()
{
    int n, m;
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i];

    cin >> m;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }

    FOR(i, 1, n)
        if(!num[i])
            tarjan(i);

    FOR(i, 1, scc)
        mini[i] = 2 * MOD;

    FOR(i, 1, n) {
        int c = comp[i];
        int w = a[i];
        if(mini[c] > w) {
            mini[c] = w;
            cnt[c] = 1;
        } else if(mini[c] == w) {
            cnt[c]++;
        }
    }

    ll x = 0, y = 1;
    FOR(i, 1, scc) {
        x += mini[i];
        y *=(ll)cnt[i];
        y %= MOD;
    }

    cout << x << " " << y;
}

int main()
{
    faster;

    int t;
    t = 1;
    ///cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

