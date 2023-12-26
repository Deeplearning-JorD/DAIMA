/*
 * @Author: JorD
 * @LastEditTime: 2023-10-14 01:58:27
 * how to Get
 */
#pragma GCC optimize(2)
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
const int N = 2e5 + 10, mod = 26;
struct Segtree{
    ll x, tag;
}tr[N << 2];
int n, m;
string s;
void build(int l, int r, int p){
    tr[p].tag = 0;
    if(l == r){
        tr[p].x = s[l] - 'a';
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
}
void pushdown(int p){
    if(!tr[p].tag) return;
    tr[p << 1].x += tr[p].tag;
    tr[p << 1|1].x += tr[p].tag;
    tr[p << 1].tag += tr[p].tag;
    tr[p << 1|1].tag += tr[p].tag;
    tr[p].tag = 0;
}
int find(int pos, int l = 1, int r = n, int p = 1){
    if(l == r) return tr[p].x % mod;
    int mid = l + r >> 1;
    pushdown(p);
    if(pos <= mid) return find(pos, l, mid, p << 1);
    return find(pos, mid + 1, r, p << 1|1);
}
void update(int cl, int cr, int l, int r, int p, int x){
    if(cl <= l && r <= cr){
        tr[p].tag += x;
        tr[p].x += x;
        return;
    }
    int mid = l + r >> 1;
    pushdown(p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, x);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, x);
}
void Solve(){
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    build(1, n, 1);
    set<int> s2, s3;
    rep(i, 1, n){
        if(i + 1 <= n && s[i] == s[i + 1]) s2.insert(i);
        if(i + 2 <= n && s[i] == s[i + 2]) s3.insert(i);
    }
    while(m --){
        int op, l, r, x;
        cin >> op >> l >> r;
        if(op == 1){
            cin >> x;
            update(l, r, 1, n, 1, x);
            for(auto i : {l - 2, l - 1, r - 1, r})if(i >= 1){
                s2.erase(i);
                s3.erase(i);
                if(i + 1 <= n){
                    int l = find(i), r = find(i + 1);
                    if(l == r) s2.insert(i);
                }
                if(i + 2 <= n){
                    int l = find(i), r = find(i + 2);
                    if(l == r) s3.insert(i);
                }
            }
        }else{
            bool res = true;
            auto p = s2.lower_bound(l);
            if(p != s2.end()){
                if(*p + 1 <= r) res = false;
            }
            p = s3.lower_bound(l);
            if(p != s3.end()){
                if(*p + 2 <= r) res = false;
            }
            if(res) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}