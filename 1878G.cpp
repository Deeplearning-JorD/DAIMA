/*
 * @Author: JorD
 * @LastEditTime: 2023-10-11 02:47:25
 * tm的初始值应该是数值结果给他算了二进制下1的个数，吐血
 * how to Get
 */
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
int depth[N];
int fat[20][N], pre[20][N], w[N];
vector<vector<int>> son;
void dfs(int now, int fa){
    fat[0][now] = fa;
    depth[now] = depth[fa] + 1;
    pre[0][now] = w[now] | w[fa];
    for(int i = 1;i <= 19;i ++){
        int up = fat[i - 1][now];
        fat[i][now] = fat[i - 1][up];
        pre[i][now] = pre[i - 1][now] | pre[i - 1][up];
    }
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
    }
}
int lca(int x, int y){
    if(depth[x] > depth[y]) swap(x, y);
    for(int i = 19;i >= 0;i --)if(depth[x] <= depth[fat[i][y]]){
        y = fat[i][y];
    }
    if(x == y) return x;
    for(int i = 19;i >= 0;i --)if(fat[i][x] != fat[i][y]){
        x = fat[i][x];
        y = fat[i][y];
    }
    return fat[0][x];
}
int get(int now, int fa){
    if(depth[now] < depth[fa]) swap(now, fa);
    int res = w[now];
    for(int i = 19;i >= 0;i --)if(depth[fat[i][now]] >= depth[fa]){
        res |= pre[i][now];
        now = fat[i][now];
    }
    return res;
}
int lowbit(int x){return x & -x;}
int cc(int x){
    int cnt = 0;
    while(x){
        cnt ++;
        x -= lowbit(x);
    }
    return cnt;
}
void Solve(){   
    int n; cin >> n;
    son.resize(n + 1);
    rep(i, 1, n) cin >> w[i];
    rep(i, 2, n){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
    int m; cin >> m;
    while(m --){
        int x, y; cin >> x >> y;
        if(depth[x] > depth[y]) swap(x, y);
        int LCA = lca(x, y);
        int now = y, last = w[y];
        int res = cc(w[y]) + cc(get(y, x));
        if(LCA == x){
            while(now != x){
                int c = now;
                for(int i = 19;i >= 0;i --)if(depth[fat[i][c]] >= depth[LCA]){
                    if((last|pre[i][c]) <= last){
                        c = fat[i][c];
                    }
                }
                if((last|pre[0][c])==last||c == LCA)break;
                last |= pre[0][c];
                c = fat[0][c];
                res = max(res, cc(last) + cc(get(c, x)));
                now = c;
            }
            cout << res << ' ';
            continue;
        }
        res = max(cc(w[x]), cc(w[y])) + cc((get(x, LCA) | get(y, LCA)));
        now = x, last = (w[x]);
        while(now != LCA){
            int c = now;
            for(int i = 19;i >= 0;i --)if(depth[fat[i][c]] >= depth[LCA]){
                if((last|pre[i][c]) <= last){
                    c = fat[i][c];
                }
            }
            if((last|pre[0][c])==last||c == LCA)break;
            last |= pre[0][c];
            c = fat[0][c];
            res = max(res, cc(last) + cc((get(y, LCA) | get(c, LCA))));
            now = c;
        }
        now = y;
        last = (w[y]);
        while(now != LCA){
            int c = now;
            for(int i = 19;i >= 0;i --)if(depth[fat[i][c]] >= depth[LCA]){
                if((last|pre[i][c]) <= last){
                    c = fat[i][c];
                }
            }
            if((last|pre[0][c])==last||c == LCA)break;
            last |= pre[0][c];
            c = fat[0][c];
            res = max(res, cc(last) + cc((get(x, LCA) | get(c, LCA))));
            now = c;
        }
        cout << res << ' ';
    }
    cout << endl;
    son.clear();
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}