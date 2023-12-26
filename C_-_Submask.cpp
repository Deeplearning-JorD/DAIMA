/*
 * @Author: JorD
 * @LastEditTime: 2022-09-17 20:27:19
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
#define rep(i, l, r) for (auto (i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    ll n;
    cin >> n;
    vector<ll> q;
    rep(i, 0, 63){
        if((1ll << i) & n) q.push_back(i);
    }
    vector<ll> res;
    rep(i, 0, (1 << siz(q)) - 1){
        ll now = 0;
        int idx = 0;
        for(auto x:q){
            ll p = 1ll << x;
            if((1ll << idx) & i){
                now += p;
            }
            idx ++;
        }
        res.push_back(now);
    }
    sort(res.begin(), res.end());
    for(auto x : res) cout << x << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}