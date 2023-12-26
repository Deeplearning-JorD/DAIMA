/*
 * @Author: JorD
 * @LastEditTime: 2023-08-24 23:41:38
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
void Solve(){
    ll n, d, m;
    cin >> n >> m >> d;
    ll res = 0, idx = 0, sum = 0;
    multiset<ll> s;
    rep(i, 1, n){
        ll x; cin >> x;
        if(x >= 0){
            if(idx == m){
                auto p = s.begin();
                if(*p <= x){
                    sum += x - *p;
                    res = max(res, sum - d * i);
                    s.erase(p);
                    s.insert(x);
                }
            }else{
                sum += x;
                idx ++;
                res = max(res, sum - d * i);
                s.insert(x);
            }   
        }
        res = max(res, sum - d * i);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}