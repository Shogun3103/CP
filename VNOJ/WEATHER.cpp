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

const int N = 110;
int n, m;
vt<vt<int>> g;
int low[N], num[N], res = 0;
int timeDfs;
int f[N];

void dfs(int u, int pre)
{
    low[u] = num[u] = ++timeDfs;
    f[u] = 1;
    for(int v : g[u]) {
        if(v == pre) continue;
        if(num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        f[u] += f[v];
        if(num[v] == low[v])
            res += f[v] * (n - f[v]);
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0);
    cout << res;
}

int main()
{
    faster;

    solve();

    return 0;
}

