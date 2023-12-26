/*
 * @Author: JorD
 * @LastEditTime: 2022-10-16 22:46:13
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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n + 1);
    ll idx0 = 0, idx1 = 0, sum = 0;
    rep(i, 1, n){
        cin >> a[i];
        if(a[i]&1) idx1 ++;
        else idx0 ++;
        sum += a[i];
    }
    while(t --){
        ll op, x;
        cin >> op >> x;
        if(op == 1){
            sum += idx1 * x;
            if(x & 1){
                idx0 += idx1; 
                idx1 = 0;
            }
        }else{
            sum += idx0 * x;
            if(x & 1){
                idx1 += idx0;
                idx0 = 0;
            }
        }
        cout << sum << endl;
    }
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