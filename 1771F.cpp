/*
 * @Author: JorD
 * @LastEditTime: 2023-01-17 13:01:50
 */
#include<bits/stdc++.h>
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
const int N = 2e5 + 10, inf = 2e9;
mt19937 rad(random_device{}());
map<int,int> st;
struct Segtree{
    int l, r, val;
}tr[N << 5];
int root[N], idx;
void pushup(int p){
    tr[p].val = tr[tr[p].l].val ^ tr[tr[p].r].val;
}
void update(int pos, int l, int r, int &clone, int p, int k){
    clone = ++ idx;
    tr[clone] = tr[p];
    if(l == r){
        tr[clone].val ^= k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) update(pos, l, mid, tr[clone].l, tr[p].l, k);
    else update(pos, mid + 1, r, tr[clone].r, tr[p].r, k);
    pushup(clone);
}  
int query(int l, int r, int L, int R){
    if(!L && !R) return 0;
    if(l == r) return l;
    int mid = l + r >> 1;
    int now = tr[tr[L].l].val ^ tr[tr[R].l].val;
    if(!now) return query(mid + 1, r, tr[L].r, tr[R].r);
    else return query(l, mid, tr[L].l, tr[R].l);
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        if(!st[x]) st[x] = rad();
        update(x, 0, inf, root[i], root[i - 1], st[x]);
    }
    int lastans = 0;
    int m; cin >> m;
    while(m --){
        int l, r;
        cin >> l >> r;
        l ^= lastans; r ^= lastans;
        lastans = query(0, inf, root[l - 1], root[r]);
        cout << lastans << endl;
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