/*
 * @Author: JorD
 * @LastEditTime: 2023-03-04 22:37:42
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
ll n, k;
ll res = 1e18;
void dfs(ll x, ll js){
    ll mx = 0;
    ll now = x, len = 0;
    set<int> s;
    while(now){
        s.insert(now % 10);
        now /= 10;
        len ++;
    }
    if(n - len + js >= res) return;
    if(len == n){
        res = min(res, js);
        return;
    }
    s.erase(1);
    s.erase(0);
    vector<int> v;
    for(auto x:s) v.push_back(x);
    reverse(v.begin(), v.end());
    for(auto ji:v){
        dfs(ji * x, js + 1);
    }
}
void Solve(){
    cin >> n >> k;
    dfs(k, 0);
    if(res == 1e18) res = -1;
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}