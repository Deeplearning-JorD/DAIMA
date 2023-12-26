/*
 * @Author: JorD
 * @LastEditTime: 2023-04-28 16:15:31
 */
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
int w[N];
vector<int> son[N];
int siz[N], root[N], id[N], cnt, idx;
struct Tire{
    int id, cnt;
}tr[2][N * 33];
void add(int i, int p, int &clone, int now){
    if(!clone) clone = ++ idx;
    if(i < 0){
        return;
    }
    int c = now >> i & 1;
    tr[!c][clone] = tr[!c][p];
    tr[c][clone].cnt = tr[c][p].cnt + 1;
    tr[c][clone].id = ++ idx;
    add(i - 1, tr[c][p].id, tr[c][clone].id, now);
}
int idd;
void dfs(int now, int fa){
    siz[now] = 1;
    id[now] = ++ idd;
    add(30, root[idd - 1], root[idd], w[now]);
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        siz[now] += siz[x];
    }
}
int query(int L, int R, int now, int i){
    if(i < 0) return 0;
    int c = now >> i & 1;
    c ^= 1;
    if(tr[c][R].cnt - tr[c][L].cnt > 0) return ((1 << i) | query(tr[c][L].id, tr[c][R].id, now, i - 1));
    return query(tr[!c][L].id, tr[!c][R].id, now, i - 1);
}   
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> w[i];
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
    int m;
    cin >> m;
    while(m --){
        int u, v;
        cin >> u >> v;
        cout << query(root[id[v] - 1], root[id[v] + siz[v] - 1], w[u], 30) << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}