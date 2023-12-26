/*
 * @Author: JorD
 * @LastEditTime: 2022-11-26 18:15:03
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
const int N = 1e6 + 10;
struct node{
    int l, r, w;
};
ll tr[N << 2];
int lazy[N << 2];
void pushdown(int p, int l, int r){
    if(l == r) return (void)(lazy[p] = 0);
    int mid = l + r >> 1;
    tr[p << 1] += lazy[p];
    tr[p << 1|1] += lazy[p];
    lazy[p << 1] += lazy[p];
    lazy[p << 1|1] += lazy[p];
    lazy[p] = 0;
}
void update(int l, int r, int cl, int cr, int p, int k){
    if(cl <= l && r <= cr){
        tr[p] += k;
        lazy[p] += k;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= mid) update(l, mid, cl, cr, p << 1, k);
    if(cr > mid) update(mid + 1, r, cl, cr, p << 1|1, k);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<node> a(n + 1);
    rep(i, 1, n){
        int l, r, w;
        cin >> l >> r >> w;
        a[i] = {l, r, w};
    }
    sort(a.begin() + 1, a.end(), [](node a, node b){
        return a.w < b.w;
    });
    int res = 1e9, j = 1;
    for(int i = 1;i <= n;i ++){
        while(tr[1] <= 0&&j <= n){
            update(1, m - 1, a[j].l, a[j].r - 1, 1, 1);
            j ++;
        }
        if(tr[1] > 0)
        res = min(res, a[j - 1].w - a[i].w);
        update(1, m - 1, a[i].l, a[i].r - 1, 1, -1);       
    }
    cout << res << endl;
    return;
}
int main(){                                                                             
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}