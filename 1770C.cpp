/*
 * @Author: JorD
 * @LastEditTime: 2022-12-31 00:14:54
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
void Solve(){
    int n; cin >> n;
    vector<ll> a(n + 1);
    map<ll, ll> q;
    rep(i, 1, n){
        cin >> a[i];
        q[a[i]] ++;
    }
    for(auto [x, y]:q){
        if(y > 1){
            cout << "NO\n";
            return;
        }
    }
    bool st = true;
    rep(mod, 2, n){
        vector<int> cnt(mod);
        rep(i, 1, n){
            cnt[a[i] % mod] ++;
        }
        int js = 0;
        for(auto x:cnt){
            if(x < 2) js ++;
        }
       if(!js) st = false;
    } 
    if(st) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}