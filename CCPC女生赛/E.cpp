/*
 * @Author: JorD
 * @LastEditTime: 2022-12-01 00:04:16
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
const int N = 2e6 + 10;
ll a[N], pre[N];
ll tr[N << 2];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = pre[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = max(tr[p << 1], tr[p << 1|1]);
}
ll query(int l, int r, int cl, int cr, int p){
    if(cl > cr) return 2e18;
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    ll res = -1e18;
    if(cl <= mid) res = max(res, query(l, mid, cl, cr, p << 1));
    if(cr > mid) res = max(res, query(mid + 1, r, cl, cr, p << 1|1));
    return res;
}
void Solve(){
    ll x, t, k, n, d;
    cin >> x >> t >> k >> n >> d;
    rep(i, 1, n) cin >> a[i];
    for(int i = 1;i <= n;i ++){
        int w = 0;
        if(a[i] <= d) w = -1;
        else w = 1;
        pre[i] = pre[i - 1] + w;
    }
    if(pre[n] < 0){
        cout << "YES\n";
        return;
    }
    ll last = pre[n];
    rep(i, 1, n) pre[i] = x + pre[i];
    build(1, n, 1);
    if(last == 0){
        if(t >= n){
            if(query(1, n, 1, n, 1) <= k){
                cout << "YES\n";
                return;
            }
            cout << "NO\n";
            return;
        }
    }
    if(t >= n){
        ll tt = t % n;
        ll st = 0;
        ll kk = t / n;
        if(tt){
            if(query(1, n, 1, tt, 1) <= k - kk * last){
                st ++;
            }
            kk --;
            if(query(1, n, 1, n, 1) <= k - kk * last){
                st ++;
                return;
            }
            if(st == 2) cout << "YES\n";
            else   cout << "NO\n";    
            return;
        }else{
            if(query(1, n, 1, tt, 1) <= k - kk * last){
                cout << "YES\n";
                return;
            }
            cout << "NO\n";    
            return;
        }
        return;
    }
    rep(i, 1, n) pre[i] -= x;
    int j = 1;
    rep(i, n + 1, 2 * n){
        int w = 0;
        if(a[j ++] <= d) w = -1;
        else w = 1;
        pre[i] = pre[i - 1] + w;
    }
    n *= 2;
    rep(i, 1, n) pre[i] += x;
    build(1, n, 1);
    for(int i = 1;i <= n;i ++){
        if(i + t - 1 <= n){
            if(query(1, n, i, i + t - 1, 1) > k) continue;
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}