/*
 * @Author: JorD
 * @Date: 2023-12-06 13:48:27
 * @LastEditTime: 2023-12-06 13:54:48
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    ll n; cin >> n;
    int res = 0;
    if(((n - 1) & 1) == 0){
        cout << 0 << endl;
        return;
    }
    for(int i = 1;i <= n;i ++){
        int x; cin >> x;
        res ^= x;
    }
    cout << res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}