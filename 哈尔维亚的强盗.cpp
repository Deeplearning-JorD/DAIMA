/*
 * @Author: JorD
 * @LastEditTime: 2022-11-27 14:08:29
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    int l = 1, r = 1;
    sort(all1(a));
    sort(all1(b));
    int res = 0;
    while(l <= n && r <= m){
        if(a[l] < b[r]) l ++;
        else l ++, r ++, res ++;
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}