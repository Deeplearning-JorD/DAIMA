/*
 * @Author: JorD
 * @LastEditTime: 2023-01-04 17:47:51
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
const int N = 2e5 + 10;
int tr[N << 2];
int a[N],b[N];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = b[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = max(tr[p << 1], tr[p << 1|1]);
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res = query(cl, cr, l, mid, p << 1);
    if(cr > mid) res = max(res, query(cl, cr, mid + 1, r, p << 1|1));
    return res;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    build(1, n, 1);
    map<int, vector<int>> son;
    map<int,int> cnt;
    int m; cin >> m;
    while(m --){
        int x; cin >> x;
        cnt[x] ++;
    }
    rep(i, 1, n){
        if(a[i] < b[i]){
            cout << "NO\n";
            return;
        }
    }
    rep(i, 1, n){
        if(a[i] != b[i])
        son[b[i]].push_back(i);
    }
    for(auto [o, now]:son){
        m = now.size();
        int need = 1;
        int last = now[0];
        rep(i, 1, m - 1){
            if(query(last, now[i], 1, n, 1) > o){
                need ++;
                last = now[i];
            }
        }
        if(need > cnt[o]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}