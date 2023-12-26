/*
 * @Author: JorD
 * @LastEditTime: 2023-04-26 00:03:51
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
ll g(ll x){
    return x * (x - 1) * (x - 2);
}
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int,int> q;
    int mx = 0;
    rep(i, 1, n){
        cin >> a[i];
        q[a[i]] ++;
        mx = max(a[i], mx);
    }
    ll res = 0;
    for(auto [x, y]:q){
        res += g(y);
        for(ll i = 2;i * x <= mx && i <= x;i ++){
            if(x % i == 0 && q.count(x / i) && q.count(x * i)){
                res += 1ll * q[x / i] * q[x * i] * y;                
            }
        }
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