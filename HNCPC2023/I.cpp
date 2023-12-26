/*
 * @Author: JorD
 * @LastEditTime: 2023-05-23 23:26:47
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
const int N = 4e5 + 10;
struct node{
    int y, l, r;
    bool operator <(node const& ji)const{
        return r > ji.r;
    }
}Y[N];
struct noji{
    int x, d, u;
}X[N];
int tr[N << 2];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void update(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) update(pos, l, mid, p << 1, k);
    else update(pos, mid + 1, r, p << 1|1, k);
    pushup(p);
}
ll query(int l, int r, int cl, int cr, int p){
    if(cl <= l && r <= cr){
        return tr[p]; 
    }
    int mid = l + r >> 1;
    ll res = 0;
    if(cl <= mid) res += query(l, mid, cl, cr, p << 1);
    if(cr > mid) res += query(mid + 1, r, cl, cr, p << 1|1);
    return res;
}
void Solve(){
    int n; cin >> n;
    rep(i, 1, n){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        Y[i*2 - 1] = {sy, sx, ex};
        Y[i*2] = {ey, sx, ex};
        X[i*2 - 1] = {sx, sy, ey};
        X[i*2] = {ex, sy, ey};
    }
    n <<= 1;
    sort(Y + 1, Y + 1 +n, [](node x, node y){
        return x.l < y.l;
    });
    priority_queue<node> q;
    sort(X + 1, X + 1 + n, [](noji a, noji b){
        return a.x < b.x;
    });
    ll res = 0;
    int idx = 1, idx2 = 1;
    for(int i = 1;i <=  n;i ++){
        auto [x, d, u] = X[i];
        while(idx <= n){
            if(x >= Y[idx].l){
                update(Y[idx].y, 1, n, 1, 1);
                q.push(Y[idx ++]);
            }else break;
        }
        while(q.size()){
            auto [y, l, r] = q.top();
            if(r < x){
                update(y, 1, n, 1, 0);
                q.pop();
            }else break;
        }
        res += query(1, n, d, u, 1);
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i ++){
        auto [x, d, u] = X[i];
        auto [y, l, r] = Y[i];
        cnt += u - d + 1;
        cnt += r - l + 1;
    }
    cnt -= res;
    cout << 1ll * n * n - cnt << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}