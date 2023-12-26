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
    ll x, y;
    cin >> x >> y;
    ll res = 0;
    if(x > y) swap(x, y);
    auto dfs = [&](auto dfs, ll x, ll y){
        if(x == y){
            cout << res << endl;
            return;
        }    
        res += ((y - x) + x - 1) / x;
        y = (y - x) % x;
        if(y == 0){
            cout << res << endl;
            return;
        }
        if(x > y) swap(x, y);
        dfs(dfs, x, y);
    };
    dfs(dfs, x, y);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}