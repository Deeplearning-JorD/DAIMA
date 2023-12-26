/*
 * @Author: JorD
 * @LastEditTime: 2022-08-27 23:17:49
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
    ll n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    ll len = abs(n - sx) + abs(m - sy);
    if(len <= d){
        cout << -1 << endl;
        return;
    }
    if(sx-d>1&&sy+d<m){
        cout << n + m - 2 << endl;
        return;
    }
    if(sx+d<n&&sy-d>1){
        cout << n + m - 2 << endl;
        return;
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}