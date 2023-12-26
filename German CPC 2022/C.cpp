/*
 * @Author: JorD
 * @LastEditTime: 2022-12-02 20:20:52
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
const int N = 1e5 + 10;
int n, q;
int tr[N << 2], lazy[N << 2];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void update(int l, int r, int cl, int cr, int p, int k){
    if(cl <= l && r <= cr){
        tr[p] += k;
        return;
    }
    int mid = l + r >> 1;
    if(cl <= mid) update(l, mid, cl, cr, p << 1, k);
    if(cr > mid) update(mid + 1, r, cl, cr, p << 1|1, k);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
int query(int l, int r, int cl, int cr, int p){
    if(cl > cr) return 1;
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res += query(l, mid, cl, cr, p << 1);
    if(cr > mid) res += query(mid + 1, r, cl, cr, p << 1|1);
    return res;
}
void Solve(){
    cin >> n >> q;
    // build(1, n, 1);
    while(q --){
        char op;
        int x, y;
        cin >> op;
        if(op == '+'){
            cin >> x;
            update(1, n, x, x, 1, 1);
        }else if(op == '-'){
            cin >> x;
            update(1, n, x, x, 1, -1);
        }else{
            cin >> x >> y;
            if(x > y) swap(x, y);
            if(!query(1, n, x, y, 1) || (!query(1, n, 1, x, 1)&&!query(1, n, y, n, 1))){
                cout << "possible\n";
            }else{
                cout << "impossible\n";
            }
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