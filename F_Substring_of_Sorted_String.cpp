/*
 * @Author: JorD
 * @LastEditTime: 2023-04-26 19:33:58
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
string s;
struct Segtree{
    int l, r;
    bool cnt;
}tr[N << 2];
Segtree operator + (Segtree L, Segtree R){
    Segtree now = {L.l, R.r, 0};
    if(L.cnt && R.cnt && L.r <= R.l)
        now.cnt = 1;
    return now;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {s[l] - 'a', s[l] - 'a', 1};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return;
}
void modify(int pos, int l, int r, int p){
    if(l == r){
        tr[p] = {s[l] - 'a', s[l] - 'a', 1};
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1);
    else modify(pos, mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return;
}
Segtree query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    auto L = query(cl, cr, l, mid, p << 1), R = query(cl, cr, mid + 1, r, p << 1|1);
    return L + R;
}
int te[26][N];
int lowbit(int x){
    return x & - x;
}
int n;
void add(int o, int i, int x){
    for(;i <= n;i += lowbit(i)){
        te[o][i] += x;
    }
}
int query(int o, int i){
    int res = 0;
    for(;i;i -= lowbit(i)) res += te[o][i];
    return res;
}
void Solve(){
    cin >> n;
    cin >> s;
    s = ' ' + s;
    build(1, n, 1);
    for(int i = 1;i <= n;i ++){
        int now = s[i] - 'a';
        add(now, i, 1);
    }
    int m;
    cin >> m;
    while(m -- ){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            char c;
            cin >> x >> c;
            add(s[x] - 'a', x, -1);
            s[x] = c;
            add(s[x] - 'a', x, 1);
            modify(x, 1, n, 1);
        }else{
            int l, r;
            cin >> l >> r;
            bool T = query(l, r, 1, n, 1).cnt;
            for(int i = s[l] - 'a' + 1;i < s[r] - 'a';i ++){
                int y = query(i, r), zz = query(i, n), z = query(i, l - 1);
                if(y - z != zz) T = false;
            }
            if(T) cout << "Yes\n";
            else cout << "No\n";
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