#include <bits/stdc++.h>

using namespace std;
#define int long long
#define maxn 100005
int f[maxn][20];
vector<int> vec[maxn];
int dep[maxn], dfn[maxn], sum[maxn], val[maxn], rak[maxn];
int n, m, q, t, cnt;
int ans = 0;
set<int> S;
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    sum[u] = sum[fa] + val[u];
    for (int i = 0; i < 19; i++)
        f[u][i + 1] = f[f[u][i]][i];
    dfn[++cnt] = u;
    rak[u] = cnt;
    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i];
        if (v == fa)
            continue;
        f[v][0] = u;
        dfs(v, u);
    }
}
int lca(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (dep[f[x][i]] >= dep[y]) {
            x = f[x][i];
        }
        if (x == y)
            return x;
    }
    for (int i = 19; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int getdist(int x, int y) {
    int fa = lca(x, y);
    return sum[x] + sum[y] - 2 * sum[fa];
}
void ins(int a) {
    if (S.count(rak[a]))
        printf("error");
    if (S.size() > 0) {
        auto it1 = S.lower_bound(rak[a]), it2 = it1;
        if (it2 == S.end())
            it2 = S.begin();
        if (it1 == S.begin())
            it1 = S.end();
        it1--;
        ans += getdist(dfn[*it1], a) + getdist(a, dfn[*it2]) - getdist(dfn[*it1], dfn[*it2]) >> 1;
    }
    S.insert(rak[a]);
}
void del(int a) {
    if(S.count(rak[a])==0)
        printf("error 2\n");
    S.erase(rak[a]);
    if (S.size() > 0) {
        auto it1 = S.lower_bound(rak[a]), it2 = it1;
        if (it2 == S.end())
            it2 = S.begin();
        if (it1 == S.begin())
            it1 = S.end();
        it1--;
        ans += getdist(dfn[*it1], dfn[*it2]) - (getdist(dfn[*it1], a) + getdist(a, dfn[*it2])) >> 1;
    }
}
int getfa() {
    if (S.size() > 0) {
        auto it1 = S.begin(), it2 = S.end();
        it2--;
        return val[lca(dfn[*it1], dfn[*it2])];
    } else
        return 0;
}
signed main() {
    scanf("%lld", &t);
    while (t--) {
        ans = 0;
        cnt = 0;
        S.clear();
        scanf("%lld%lld%lld", &n, &m, &q);
        for (int i = 1; i <= n; i++) {
            vec[i].clear();
        }
        for (int i = 1; i <= n; i++){
            scanf("%lld", &val[i]);
            if(val[i]==0)
            return 0;
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%lld%lld", &a, &b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        dfs(1, 0);
        for (int i = 1; i <= m; i++) {
            int a;
            scanf("%lld", &a);
            ins(a);
        }
        while (q--) {
            int op, u;
            scanf("%lld%lld", &op, &u);
            if (op == 1)
                ins(u);
            else
                del(u);
            printf("%lld\n", ans + getfa());
        }
    }
    return 0;
}