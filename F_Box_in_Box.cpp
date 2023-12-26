/*
 * @Author: JorD
 * @LastEditTime: 2023-07-09 21:21:52
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
#define ls tr[p].l
#define rs tr[p].r
const int N = 4e5 + 10, inf = 2e9;
struct node{
    int a, b, c;
    bool operator <(const node &ji)const{
        if(a == ji.a){
            if(b == ji.b) return c < ji.c;
            return b < ji.b;
        }
        return a < ji.a;
    }
}v[N];
int idx, root;
struct Segtree{
    int l, r, x;
}tr[N * 80];
void clone(int &p){
    p = ++ idx;
    tr[p].x = inf;
}
void pushup(int p){
    if(!tr[p].l) clone(tr[p].l);
    if(!tr[p].r) clone(tr[p].r);
    tr[p].x = min(tr[ls].x, tr[rs].x);
}
void modify(int pos, int l, int r, int &p, int k){
    if(!p) clone(p);
    if(l == r){
        tr[p].x = min(tr[p].x, k);
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l, k);
    else modify(pos, mid + 1, r, tr[p].r, k);
    pushup(p);
}
int query(int cl, int cr, int l, int r, int &p){
    if(cl > cr) return inf;
    if(!p) clone(p);
    if(cl <= l && r <= cr){
        return tr[p].x;
    }
    int mid = l + r >> 1;
    int L = inf, R = inf;
    if(cl <= mid) L = query(cl, cr, l, mid, ls);
    if(cr > mid) R = query(cl, cr, mid + 1, r, rs);
    return min(L, R);
}
void Solve(){
    int n;
    cin >> n;
    map<int,int> cnt;
    rep(i, 1, n){
        vector<int> a(3);
        for(auto &x:a) cin >> x;
        sort(a.begin(), a.end());
        v[i] = {a[0],a[1],a[2]};
        cnt[a[0]] ++;
    }
    sort(v + 1, v + 1 + n);
    queue<int> q;
    rep(i, 1, n){
        auto [a, b, c] = v[i];
        q.push(i);
        cnt[a] --;
        if(c > query(1, b - 1, 1, inf, root)){
            cout << "Yes\n";
            return;
        }
        while(!cnt[a] && q.size()){
            auto t = q.front(); q.pop();
            modify(v[t].b, 1, inf, root, v[t].c);
        }
    }
    cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}