/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 12:55:21
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
const int N = 5e5 + 10;
struct Trie{
    int id, cnt;
}tr[N * 35][2];
int root[N], idx;
int ver[N * 35];
void dfs(int i, ll x, int &clone, int p, int v){
    if(!clone) clone = ++ idx;
    if(i < 0){
        ver[clone] = v;
        return;
    }
    int c = x >> i & 1;
    tr[clone][!c] = tr[p][!c];
    tr[clone][c].cnt = tr[p][c].cnt + 1;
    tr[clone][c].id = ++ idx;
    dfs(i - 1, x, tr[clone][c].id, tr[p][c].id, v);
}
int query(int i, ll x, int L, int R){
    if(i < 0){
        return ver[R];
    }
    int c = x >> i & 1;
    int cnt = tr[R][!c].cnt - tr[L][!c].cnt;
    if(cnt > 0) return query(i - 1, x, tr[L][!c].id, tr[R][!c].id);
    return query(i - 1, x, tr[L][c].id, tr[R][c].id);
}
struct node{
    ll l, r, w, x, k;
    bool operator <(const node& ji) const{
        return ji.w > w;
    }
};
ll pre[N];
void Solve(){
    int n, t;
    cin >> n >> t;
    ll last = 0;
    dfs(33, 0, root[0], 0, 0);
    priority_queue<node> q;
    rep(i, 1, n){
        ll x; cin >> x;
        last ^= x;
        pre[i] = pre[i - 1] ^ x;
        dfs(33, last, root[i], root[i - 1], i);
        int k = query(33, last, 0, root[i - 1]);
        q.push({0, i - 1, last ^ pre[k], k, i});
    }
    ll sum = 0;
    while(t --){
        auto [l, r, w, L, R] = q.top(); q.pop();
        sum += w;
        if(L < r){
            ll k = query(33, pre[R], root[L], root[r]);
            q.push({L + 1, r, pre[k] ^ pre[R], k, R});
        }
        if(l < L){
            int dist = l?root[l - 1]:0;
            ll k = query(33, pre[R], dist, root[L - 1]);
            q.push({l, L - 1, pre[k] ^ pre[R], k, R});
        }
    }
    cout << sum;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}