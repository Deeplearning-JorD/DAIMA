/*
 * @Author: JorD
 * @LastEditTime: 2023-04-09 01:39:50
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
struct node{
    ll x, y;
};
struct cmp{
    bool operator()(const node& a,const node& b)const{
        return (a.x != b.x?a.x>b.x:a.y<b.y);
    }
};
set<node,cmp> son[N];
ll siz[N],sum[N],zson[N],fat[N];
void dfs(int now, int fa){
    siz[now] = 1;
    fat[now] = fa;
    vector<node> dabian;
    for(auto [v, x]:son[now])if(x != fa){
        dfs(x, now);
        dabian.push_back({siz[x], x});
        siz[now] += siz[x];
        sum[now] += sum[x];
    }
    son[now].clear();
    for(auto x:dabian) son[now].insert(x);
    if(siz[now] > 1) zson[now] = (*son[now].begin()).y;
}
void update(int x){
    int y = zson[x];
    int fa = fat[x];
    son[fa].erase({siz[x], x});
    son[x].erase({siz[y], y});
    sum[x] -= sum[y];
    sum[y] += sum[x];
    siz[x] -= siz[y];
    siz[y] += siz[x];
    son[y].insert({siz[x], x});
    if(son[x].begin() != son[x].end())
    zson[x] = (*son[x].begin()).y;
    else zson[x] = 0;
    son[fa].insert({siz[y], y});
    fat[x] = y;
    fat[y] = fa;
    zson[fa] = (*son[fa].begin()).y;
    zson[y] = (*son[y].begin()).y;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> sum[i];
    rep(i, 1, n - 1){
        int x, y;
        cin >> x >> y;
        son[x].insert({1, y});
        son[y].insert({1, x});
    }
    dfs(1, 0);
    while(m --){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            cout << sum[x] << endl;
        }else{
            if(!son[x].size()||!zson[x]||siz[x] == 1) continue;
            update(x);
        }
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