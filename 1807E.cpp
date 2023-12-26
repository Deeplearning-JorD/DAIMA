/*
 * @Author: JorD
 * @LastEditTime: 2023-03-20 00:26:32
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
// #define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<ll> pre(n + 1);
    rep(i, 1, n){
        pre[i] = pre[i - 1] + a[i];
    }
    if(n == 1){
        cout << "! " << 1 << endl;
        return;
    }
    auto dfs = [&](auto dfs, int l, int r, int fl, int fr){
        cout << "? " << r - l + 1 << ' ';
        rep(i, l, r) cout << i << ' ';
        cout << endl;
        ll x; cin >> x;
        if(x == pre[r] - pre[l - 1]){
            if(fl == fr){
                cout << "! " << fl << endl;
                return; 
            }
            int mid = fl + fr >> 1;
            dfs(dfs, fl, mid, mid + 1, fr);
        }else{
            if(l == r){
                cout << "! " << l << endl;
                return;
            }
            int mid = l + r >> 1;
            dfs(dfs, l, mid, mid + 1, r);
        }
    };
    dfs(dfs, 1, n / 2, n / 2 + 1, n);
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}