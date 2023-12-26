/*
 * @Author: JorD
 * @LastEditTime: 2022-12-31 22:54:14
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
    ll a, b, c;
    cin >> a >> b >> c;
    map<ll, ll> q;
    for(int i = 2;i <= c / i;i ++){
        if(c % i == 0){
            q[i] ++;
            while(c % i == 0) c /= i;
        }
    }
    if(c > 1) q[c] ++;
    if(q[a] && q[b]) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}