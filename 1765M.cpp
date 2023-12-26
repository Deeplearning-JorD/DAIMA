/*
 * @Author: JorD
 * @LastEditTime: 2022-11-29 23:29:13
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
    int n;
    cin >> n;
    vector<pair<int,int>> res;
    // if(n & 1){
    //     cout << 1 << ' ' << n - 1 << endl;
    // }else cout << n / 2 << ' ' << n / 2 << endl;
    rep(i, 1, n - 1){
        // cout << i << ' ' << i * (n - i) / __gcd(i, n - i) << endl;
        res.push_back({i * (n - i) / __gcd(i, n - i), i});
    }
    sort(all(res));
    for(auto [x, y]:res) cout << x << ' ' << y << endl;
    // cout << a << ' ' << b << endl; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}