/*
 * @Author: JorD
 * @LastEditTime: 2022-10-20 22:59:16
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
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    ll res = accumulate(a.begin(), a.end(), 0ll);
    int l = 1, r = n;
    while(l < r){
        if(b[l] < b[r]){
            res += b[l];
            l ++;
        }else{
            res += b[r];
            r --;
        }
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