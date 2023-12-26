/*
 * @Author: JorD
 * @Date: 2023-12-02 17:11:59
 * @LastEditTime: 2023-12-02 20:29:32
 * 线段树点开四倍，二分区间1-n
 */
 #include <bits/stdc++.h>
 using namespace std;
 using ll = long long;
 #define endl '\n'
 #define PII pair<ll, ll>
 #define siz(s) (ll)(s.size())
 #define all(a) a.begin(), a.end()
 #define all1(a) a.begin() + 1, a.end()
 #define SPO(n) fixed << setprecision(n)
 #define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
 #define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
 const int N = 6e5 + 10;
 vector<vector<int>> son;
 int dfn[N], low[N], idx;
 int sta[N], in[N], top;
 int id[N], scc_cnt;
 int n, m;
 void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ top] = now, in[now] = 1;
    for(auto x:son[now]){
        if(!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }else if(in[x]) low[now] = min(low[now], dfn[x]);
    }
    if(low[now] == dfn[now]){
        int y;
        scc_cnt ++;
        do{
            y = sta[top --];
            in[y] = 0;
            id[y] = scc_cnt;
        }while(y != now);
    }
 }
 pair<int,int> e[N];
 void build(int l, int r, int p){
    rep(i, l, r) son[2 * n + p].push_back(i + n);
    if(l == r) return;
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
 }
 vector<int> ls;
 void con(int cl, int cr, int l, int r, int p, int fa){
    if(cl > cr) return;
    if(cl > r || cr < l) return;
    if(cl <= l && r <= cr){
        son[fa].push_back(2 * n + p);
        ls.push_back(fa);
        return;
    }
    int mid = l + r >> 1;
    if(cl <= mid) con(cl, cr, l, mid, p << 1, fa);
    if(cr > mid) con(cl, cr, mid + 1, r, p << 1|1, fa);
 }
 bool check(int mid){
    idx = 0; scc_cnt = 0;
    rep(i, 1, 6 * n){
        dfn[i] = 0;
    }
    rep(i, 1, n){
        con(i - mid + 1, i - 1, 1, n, 1, i);
        con(i + 1, i + mid - 1, 1, n, 1, i);
    }
    rep(i, 1, 6 * n)if(!dfn[i])tarjan(i);
    while(ls.size()){
        son[ls.back()].pop_back();
        ls.pop_back();
    }
    rep(i, 1, n)if(id[i] == id[i + n]){
        return false;
    }
    return true;
 }
 void Solve(){  
    cin >> n >> m;
    son.clear(); son.resize(6 * n + 1);
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        e[i] = {x, y};
        son[x + n].push_back(y);
        son[y + n].push_back(x);
    }
    build(1, n, 1);
    int l = 1, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
    return;
 }
 int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
 }