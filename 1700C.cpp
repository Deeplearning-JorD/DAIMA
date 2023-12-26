/*
 * @Author: JorD
 * @LastEditTime: 2022-09-26 21:14:26
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
    vector<ll> a(n + 1),c(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) 
    ll res = 0;
    rep(i, 1, n){
        c[i] = a[i] - a[i - 1];
    }
    ll res = 0;
    per(i, n, 2){
        if(c[i] > 0){
            res += c[i];
        }else{
            res -= c[i];
            c[1] += c[i];
        }
    }
    cout << res + abs(c[1]) << endl;
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