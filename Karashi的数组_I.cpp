/*
 * @Author: JorD
 * @LastEditTime: 2022-12-30 20:38:11
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
int tr[N << 2], a[N];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l] == 0;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] = k == 0;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    pushup(p);
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1, res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    int n, m, len;
    cin >> n >> m >> len;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    int cf = 0;
    rep(i, 1, n - len - 1){
        int L = query(i, i, 1, n, 1);
        int R = query(i + len + 1, i + len + 1, 1, n, 1);
        if(L && L == R) cf ++;
    }
    auto check = [&](int x){
        if(x < 1 || x > n) return 0;
        return query(x, x, 1, n, 1);
    };
    while(m --){
        int x, y;
        cin >> x >> y;
        if(y){
            int L = check(x - 1 - len), mid = check(x), R = check(x + 1 + len);
            modify(x, 1, n, 1, y);
            int now = check(x);
            if(L && mid == L && now != L) cf --;
            if(R && mid == R && now != R) cf --; 
        }else{
            int L = check(x - 1 - len), mid = check(x), R = check(x + 1 + len);
            modify(x, 1, n, 1, y);
            int now = check(x);
            if(L && mid != L && now == L) cf ++;
            if(R && mid != R && now == R) cf ++; 
        }
        cout << query(1, n - len - 1, 1, n, 1) + query(len + 2, n, 1, n, 1) - cf << endl;
        // cout << "cf " << cf << endl;
        // rep(i, 1, n){
        //     cout << query(i, i, 1, n, 1) << ' ';
        // } cout << endl;
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