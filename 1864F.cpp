/*
 * @Author: JorD
 * @Date: 2023-12-03 00:16:02
 * @LastEditTime: 2023-12-03 00:47:06
 * how to Get
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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 1e6 + 10;
int tree[N];
int n, m;
int lowbit(int x){return x & -x;}
void add(int i, int x){
    for(;i <= n;i += lowbit(i)) tree[i] += x;
}
int sum(int i){
    int res = 0;
    for(;i;i -= lowbit(i)) res += tree[i];
    return res;
}
int tr[N << 2];
void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    tr[p] = max(tr[p << 1], tr[p << 1|1]);
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1, res = 0;
    if(cl <= mid) res = query(cl, cr, l, mid, p << 1);
    if(cr > mid) res = max(res, query(cl, cr, mid + 1, r, p << 1|1));
    return res;
}
void Solve(){
    cin >> n >> m;
    vector<vector<pair<int,int>>> q(n + 1);
    vector<vector<int>> son(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        son[x].push_back(i);
    }
    rep(i, 1, m){
        int l, r; cin >> l >> r;
        q[r].push_back({l, i});
    }
    vector<int> res(m + 1);
    vector<int> pre(n + 1);
    for(int i = 1;i <= n;i ++){
        pre[i] = pre[i - 1];
        if(son[i].size()){
            pre[i] ++;
            modify(son[i][0], 1, n, 1, i);
            for(int j = 1;j < son[i].size();j ++){
                int l = son[i][j - 1] + 1, r = son[i][j] - 1;
                if(l <= r){
                    int p = query(l, r, 1, n, 1);
                    //tree[i]代表的就是i这个l需要多贡献几次
                    add(1, 1);
                    add(p + 1, -1);
                }
                modify(son[i][j], 1, n, 1, i);
            }
        }
        for(auto [l, id] : q[i]){
            res[id] = pre[i] - pre[l - 1] + sum(l); 
        }
    }
    rep(i, 1, m) cout << res[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}