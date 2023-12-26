/*
 * @Author: JorD
 * @LastEditTime: 2022-11-22 03:05:01
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
    ll m;
    vector<ll> a(3);
    for(auto &x:a) cin >> x;
    cin >> m;
    sort(a.begin(), a.end());
    if(a[0] + a[1] + a[2] - 3 < m){
        cout << "NO\n";
        return;
    }
    if(a[2] - m - 1 > a[0] + a[1])
        cout << "NO\n";
    else
        cout << "YES\n";
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