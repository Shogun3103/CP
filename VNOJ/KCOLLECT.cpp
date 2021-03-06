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

const int N = 1e6 + 10, INF = 1e9 + 7;
int m, n;
vt<int> g[N], h[N];
char a[N];
int val[N], total[N];
int root[N], low[N], num[N];
bool deleted[N];
int timeDfs = 0, scc = 0;
stack<int> st;

int get(int i, int j)
{
    return (i - 1) * n + j;
}

bool check(int i, int j)
{
    if(a[get(i, j)] == '#')
        return 0;
    return (i >= 1 && i <= m && j >= 1 && j <= n);
}

int f[N];

void dfs(int u)
{
    low[u] = num[u] = ++timeDfs;
    st.push(u);
    for(int v : g[u]) {
        if(deleted[v]) continue;
        if(!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if(low[u] == num[u]) {
        ++scc;
        int v;
        do {
            v = st.top();
            st.pop();
            deleted[v] = 1;
            total[scc] += val[v];
            root[v] = scc;
        } while(v != u);
    }
}

int solve(int u)
{
    if(h[u].empty()) return total[u];
    if(f[u] != -1) return f[u];
    int cur = -INF;
    for(int v : h[u])
        cur = max(cur, solve(v) + total[u]);
    return f[u] = cur;
}

void init()
{
    cin >> m >> n;

    FOR(i, 1, m) {
        FOR(j, 1, n) {
            int u = get(i, j);
            cin >> a[u];
            val[u] = (a[u] <= '9' && a[u] >= '0') ? a[u] - '0' : 0;
        }
    }

    FOR(i, 1, m) {
        FOR(j, 1, n) {
            int u = get(i, j);
            if(a[u] == '#') continue;
            if(check(i, j + 1))
                g[u].pb(get(i, j + 1));
            if(check(i + 1, j))
                g[u].pb(get(i + 1, j));

            if(a[u] == 'W' && check(i, j - 1))
                g[u].pb(get(i, j - 1));
            if(a[u] == 'N' && check(i - 1, j))
                g[u].pb(get(i - 1, j));
        }
    }

    FOR(i, 1, m) FOR(j, 1, n) {
        int u = get(i, j);
        if(!num[u] && check(i, j))
            dfs(u);
    }

    FOR(i, 1, m) FOR(j, 1, n) {
        if(!check(i, j)) continue;
        int u = get(i, j);
        int ru = root[u];
        for(int v : g[u]) {
            int rv = root[v];
            if(ru != rv)
                h[ru].pb(rv);
        }
    }
}

int main()
{
    faster;

    init();
    fill(f, f + m * n + 1, -1);
    cout << solve(root[get(1, 1)]);

    return 0;
}

