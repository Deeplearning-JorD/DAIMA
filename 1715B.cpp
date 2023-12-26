/*
 * @Author: JorD
 * @LastEditTime: 2022-08-20 23:02:30
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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if(k*(b + 1) -1 + (k - 1) * (n - 1) < s || k*b > s){
        cout << -1 << endl;
        return;
    }
    vector<ll> a(n + 1);
    if(s >= k*(b + 1) - 1){
        a[1] = k*(b + 1) - 1;
        s -= a[1];
    }else{
        a[1] = s;
        s = 0;
    }
    rep(i, 2, n){
        ll w = 0;
        if(s >= k - 1){
            w = k - 1;
        }else{
            w = s;
        }
        a[i] = w;
        s -= w;
    }
    rep(i, 1, n) cout << a[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}