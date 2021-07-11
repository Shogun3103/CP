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

const int N = 2e5 + 10;
vector<int> a[N];
vector<set<int>> vc(N);
int n, ans[N];

void dfs(int u, int par)
{
    int sz = 0, big = 0;
    for(auto v : a[u]) {
        if(v == par) continue;
        dfs(v, u);

        if(sz < vc[v].size()) {
            sz = vc[v].size();
            big = v;
        }
    }

    if(big)
        swap(vc[u], vc[big]);

    for(auto v : a[u]) {
        if(v == par) continue;
        vc[u].insert(vc[v].begin(), vc[v].end());
    }

    ans[u] = vc[u].size();
}

void solve()
{
    cin >> n;
    FOR(i, 2, n) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    FOR(i, 1, n) {
        int x;
        cin >> x;
        vc[i].insert(x);
    }

    dfs(1, 0);

    FOR(i, 1, n)
        cout << ans[i] << ' ';
}

int main()
{
    faster;

    solve();

    return 0;
}

