/*
 * @Author: JorD
 * @LastEditTime: 2022-09-19 22:52:28
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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> b(k + 1);
    rep(i, 1, n){
        int x; cin >> x;
        b[i % k].push_back(x);
    }
    rep(i, 0, k - 1) sort(b[i].begin(), b[i].end(),[](int x, int y){
        return x > y;
    });
    ll res = 0;
    rep(i, 0, k - 1){
        res += b[i][0];
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;

    while(t --)
    Solve();
    return 0;
}