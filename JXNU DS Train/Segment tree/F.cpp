/*
 * @Author: JorD
 * @LastEditTime: 2022-12-21 15:46:43
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 5e5 + 10;
int a[N];
int n, m;
int tr[N << 2];
void pushup(int p){
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = 1e9;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void midofy(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] = min(tr[p], k);
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) midofy(pos, l, mid, p << 1, k);
    if(pos > mid) midofy(pos, mid + 1, r, p << 1|1, k);
    pushup(p);
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1, res = 1e9;
    if(cl <= mid) res = min(res, query(cl, cr, l, mid, p << 1));
    if(cr > mid) res = min(res, query(cl, cr, mid + 1, r, p << 1|1));
    return res;
}
struct node{
    int l, r, id;
};
void Solve(){
    cin >> n >> m;
    vector<int> res(m + 1);
    rep(i, 1, n) cin >> a[i];
    map<int, int> last;
    vector<int> pre(n + 1);
    rep(i, 1, n){
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    build(1, n, 1);
    vector<node> ask;
    rep(i, 1, m){
        int l, r;
        cin >> l >> r;
        ask.push_back((node){l, r, i});
    }
    sort(ask.begin(), ask.end(), [](node a, node b){
        if(a.r != b.r) return a.r < b.r;
        return a.l < b.l;
    });
    int idx = 1;
    for(auto [x, y, z]:ask){
        while(idx <= y){
            if(pre[idx]){
                midofy(pre[idx], 1, n, 1, idx - pre[idx]);
            }
            idx ++;
        }
        res[z] = query(x, y, 1, n, 1);
        if(res[z] == 1e9) res[z] = -1;
    }
    rep(i, 1, m) cout << res[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}