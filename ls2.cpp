/*
 * @Author: JorD
 * @Date: 2023-10-20 17:54:17
 * @LastEditTime: 2023-10-25 11:55:03
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 2e6 + 10;
int a[N];
struct edge{
    int l, r, x;
    bool operator<(const edge& ji)const{
        if(l == ji.l) return r < ji.r;
        return l > ji.l;
    }
};
int lowbit(int x){return x & -x;}
int tr[N], n, q;
void mx(int i, int x){
    for(;i <= n;i += lowbit(i)) tr[i] = max(tr[i], x);
}
int query(int i){
    int res = 0;
    for(;i;i -= lowbit(i))res = max(res, tr[i]);
    return res;
}
edge e[30000005];
vector<int> son[1000005];
vector<pair<int,int>> ne[1000005];
void Solve(){
    cin >> n >> q;
    rep(j, 1, n){
        int x; cin >> x;
        a[j] = x;
        for(int i = 1;i <= x / i;i ++){
            if(x % i == 0){
                son[i].emplace_back(j);
                if(x / i != i) son[x / i].emplace_back(j);
            }
        }
    }
    int cnt = 0;
    rep(o, 1, 1e6){
        int m = son[o].size(), top = m - 1;
         int z=son[o].size()-1;
        for(int i = m - 3;i >= 0;i --){
            int l = son[o][i], r = son[o][i + 1], nw = son[o][top];
            while(top > i + 1 && son[o][top] - r >= r - l) top --;
            if(top < m - 1 && son[o][top + 1] - r >= r - l){
                ne[l].emplace_back(son[o][top + 1], o);
            }
        }
    }
    int idx = 0;
    vector<vector<pair<int,int>>> ask(n + 1);
    rep(i, 1, q){
        int l, r; cin >> l >> r;
        ask[l].emplace_back(r, i);
    }
    vector<int> res(q + 1);
    for(int i = n;i >= 1;i --){
        for(auto [r, x]:ne[i]){
            mx(r, x);
        }
        for(auto &[r, x]:ask[i]){
            res[x] = query(r);
        }
    }
    rep(i, 1, q) cout << res[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}