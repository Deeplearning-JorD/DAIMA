/*
 * @Author: JorD
 * @Date: 2023-11-25 20:01:16
 * @LastEditTime: 2023-11-25 20:11:03
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
    int n, l, r; cin >> n >> l >> r;
    rep(i, 1, n){
        int x; cin >> x;
        if(x <= l) cout << l << ' ';
        else if(x >= r) cout << r << ' ';
        else cout << x << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}