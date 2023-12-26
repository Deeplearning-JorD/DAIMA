/*
 * @Author: JorD
 * @LastEditTime: 2022-11-22 00:33:19
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
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    auto get = [&](){
        ll res = 0;
        int idx = 0;
        rep(i, 1, n){
            if(!a[i]) res += idx;
            idx += a[i] == 1;
        }
        return res;
    };
    ll res = get();
    rep(i, 1, n){
        if(!a[i]){
            a[i] = 1;
            res = max(res, get());
            a[i] = 0;
            break;
        }
    }
    per(i, n, 1){
        if(a[i]){
            a[i] = 0;
            res = max(res, get());
            a[i] = 1;
            break;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}