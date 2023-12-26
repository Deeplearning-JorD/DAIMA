/*
 * @Author: JorD
 * @LastEditTime: 2023-05-21 15:44:51
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
    ll x, y;
    cin >> x >> y;
    for(int i = 0;i <= x;i ++){
        ll now = 1000 * i;
        ll Y = y - now;
        if(Y < 0 || Y % 2500) continue;
        Y /= 2500;
        if(Y >= 0 && x - Y - i >= 0){
            cout << x - Y - i << ' ' << i << ' ' << Y << endl;
            return;
        }
    }
    cout << - 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}