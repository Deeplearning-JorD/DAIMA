/*
 * @Author: JorD
 * @LastEditTime: 2022-11-26 00:16:48
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
    ll n;
    cin >> n;
    if(n & 1){
        rep(i, 1, n) cout << 1 << " \n"[i == n];
        return;
    }
    if(n == 2){
        cout << 1 << ' ' << 3 << endl;
        return;
    }
    rep(i, 1, n - 4) cout << 2 * n << ' ';
    cout << 3 * n - 1 << ' ' << 3 * n - 1 << ' ';
    cout << 2 * n + 1 << ' ' << 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}