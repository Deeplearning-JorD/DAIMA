/*
 * @Author: JorD
 * @LastEditTime: 2022-08-19 19:07:19
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
int get(ll x){
    if(x == 0) return 1;
    int js = 0;
    while(x){
        x >>= 1;
        js ++;
    }
    return js;
}
void Solve(){
    ll a, b;
    cin >> a >> b;
    ll now = 0;
    rep(i, 0, 62){
        ll x = 1ll << i;
        if((a&x) == (b&x)) now += x;
    }
    cout << now;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}