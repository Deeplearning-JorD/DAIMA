/*
 * @Author: JorD
 * @LastEditTime: 2023-05-25 12:23:35
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
struct Tag{
    unsigned add, hadd, tim;
    void merge(Tag tmp){
        hadd += tmp.hadd + add * tmp.tim;
        add += tmp.add;
        tim += tmp.tim;
    }
};
struct Segtree{
    unsigned sum, hsum;
    Tag tag;
    void update(int len, Tag u){
        tag.merge(u);
        hsum += u.hadd * len + u.tim * sum;
        sum += u.add * len;
    }
}tr[N << 2];
void pushdown(int l, int r,int p){
    int mid = l + r >> 1;
    tr[p << 1].update(mid - l + 1, tr[p].tag);
    tr[p << 1|1].update(r - mid, tr[p].tag);
    tr[p].tag = {0, 0, 0};
}
void update(int cl, int cr, int l, int r, int p, Tag t){
    if(l > cr || r < cl) return;
    if(cl <= l && r <= cr){
        tr[p].update(r - l + 1, t);
        return;
    }
    int mid = l + r >> 1;
    pushdown(l, r, p);
    update(cl, cr, l, mid, p << 1, t);
    update(cl, cr, mid + 1, r, p << 1|1, t);
    tr[p].sum = tr[p << 1].sum + tr[p << 1|1].sum;
    tr[p].hsum = tr[p << 1].hsum + tr[p << 1|1].hsum;
}
unsigned query(int cl, int cr, int l, int r, int p){
    if(l > cr || r < cl) return 0;
    if(cl <= l && r <= cr){
        return tr[p].hsum;
    }
    int mid = l + r >> 1;
    pushdown(l, r, p);
    return query(cl, cr, l, mid, p << 1) + query(cl, cr, mid + 1, r, p << 1|1);
}
void build(int l, int r, int p){
    tr[p] = {0, 0, {0,0,0}};
    if(l == r) return;
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
}
int last[N], id[N], a[N];
void Solve(){
    int n, m; cin >> n >> m;
    rep(i, 1, n){
        int x; cin >> x;
        a[i] = x;
        last[i] = id[x];
        id[x] = i;
    }
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, m){
        int l, r; cin >> l >> r;
        son[r].push_back({l, i});
    }
    build(1, n, 1);
    vector<unsigned> res(m + 1);
    rep(r, 1, n){
        update(last[r] + 1, r, 1, n, 1, {1, 0, 0});
        update(1, n, 1, n, 1, {0, 0, 1});
        for(auto [l, i] : son[r]){
            res[i] = query(l, r, 1, n, 1);
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