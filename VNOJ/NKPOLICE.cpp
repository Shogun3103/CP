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

const int N = 1e5 + 10;
int timeDFS, n, m;
int low[N], tail[N], num[N], depth[N], p[N][20];
bool joint[N];
vt<int> g[N];

int findP(int u, int par)
{
    FOD(i, 0, 19) {
        if(depth[p[u][i]] > depth[par])
            u = p[u][i];
    }
    return u;
}

bool check(int u, int root)
{
    return num[root] <= num[u] && num[u] <= tail[root];
}

void dfs(int u, int pre)
{
    int child = 0;
    low[u] = num[u] = ++timeDFS;
    for(int v:g[u]) {
        if(v == pre)
            continue;
        if(!num[v]) {
            ++child;
            p[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(u == pre) {
                if(child > 1)
                    joint[u] = 1;
            } else if(low[v] >= num[u]) joint[u] = 1;
        }
        else low[u] = min(low[u], num[v]);
    }
    tail[u] = timeDFS;
}

bool sub1(int a, int b, int g1, int g2)
{
    if(num[g1] > num[g2])
        swap(g1, g2);
    if(num[g2] != low[g2])
        return 1;
    if(check(b, g2) && !check(a, g2))
        return 0;
    if(check(a, g2) && !check(b, g2))
        return 0;
    return 1;
}

bool sub2(int a, int b, int c)
{
    if(!joint[c])
        return 1;
    int pa = 0, pb = 0;
    if(check(a, c))
        pa = findP(a, c);
    if(check(b, c))
        pb = findP(b, c);
    if(!pa && !pb)
        return 1;
    if(pa == pb)
        return 1;
    if(!pa && low[pb] < num[c])
        return 1;
    if(!pb && low[pa] < num[c])
        return 1;
    if(pa && pb && low[pa] < num[c] && low[pb] < num[c])
        return 1;
    return 0;

}

void calc()
{
    p[1][0] = 1;
    FOR(j, 1, 19) FOR(i, 1, n)
        p[i][j] = p[p[i][j-1]][j-1];
}

int main()
{
    faster;

    cin >> n >> m;
    for(int i=1, u, v; i<=m; ++i) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    depth[1] = 1;
    dfs(1, 1);
    calc();

    int q;
    cin >> q;
    while(q--) {
        int k, a, b, c, g1, g2;
        cin >> k;
        if(k==1) {
            cin >> a >> b >> g1 >> g2;
            cout << (sub1(a, b, g1, g2) ? "yes\n" : "no\n");
        } else {
            cin >> a >> b >> c;
            cout << (sub2(a, b, c) ? "yes\n" : "no\n");
        }
    }

    return 0;
}
