/*
 * @Author: JorD
 * @LastEditTime: 2022-10-07 21:30:26
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 1e5 + 10;
struct SegTree{
    int sum, lazy = -1;
}tr[26][N << 2];
int n, m;
string s;
inline void push_down(int l, int r, int p, int k){
    int L = p << 1, R = p << 1|1;
    if(tr[k][p].lazy < 0) return;
    int w = tr[k][p].lazy;
    int mid = l + r >> 1;
    tr[k][L].sum = (mid - l + 1) * w;
    tr[k][R].sum = (r - mid) * w;
    tr[k][R].lazy = tr[k][L].lazy = w;
    tr[k][p].lazy = -1;
    return;
}
inline void build(int l, int r, int p, int k){
    if(l == r){
        tr[k][p].sum = (s[l] - 'a') == k;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1, k);
    build(mid + 1, r, p << 1|1, k);
    tr[k][p].sum = tr[k][p << 1].sum + tr[k][p << 1|1].sum;
}
inline int query(int l, int r, int cl, int cr, int p, int k){
    if(cl <= l && r <= cr){
        return tr[k][p].sum;
    }
    push_down(l, r, p, k);
    int mid = l + r >> 1, res = 0;
    if(cl <= mid) res += query(l, mid, cl, cr, p << 1, k);
    if(cr > mid) res += query(mid + 1, r, cl, cr, p << 1|1, k);
    tr[k][p].sum = tr[k][p << 1].sum + tr[k][p << 1|1].sum;
    return res;
}
inline void modify(int l, int r, int cl, int cr, int p, int k, int w){
    if(cl <= l && r <= cr){
        tr[k][p].sum = (r - l + 1) * w;
        tr[k][p].lazy = w;
        return;
    }
    push_down(l, r, p, k);
    int mid = l + r >> 1;
    if(cl <= mid) modify(l, mid, cl, cr, p << 1, k, w);
    if(cr > mid) modify(mid + 1, r, cl, cr, p << 1|1, k, w);
    tr[k][p].sum = tr[k][p << 1].sum + tr[k][p << 1|1].sum;
}
void Solve(){
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    rep(i, 0, 25)   build(1, n, 1, i);
    while(m -- ){
        int l, r, op;
        cin >> l >> r >> op;
        vector<int> js(26);
        rep(i, 0, 25){
            js[i] = query(1, n, l, r, 1, i);
            modify(1, n, l, r, 1, i, 0);
        }
        int L = l;
        if(op){
            rep(i, 0, 25){
                if(!js[i]) continue;
                modify(1, n, L, L + js[i] - 1, 1, i, 1);
                L += js[i];
            }
        }else{
            per(i, 25, 0){
                if(!js[i]) continue;
                modify(1, n, L, L + js[i] - 1, 1, i, 1);
                L += js[i];
            }
        }
    }
    rep(i, 1, n){
        rep(j, 0, 25){
            if(!query(1, n, i, i, 1, j)) continue;
            cout << (char)('a' + j);
            break;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}