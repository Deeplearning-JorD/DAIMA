/*
 * @Author: JorD
 * @LastEditTime: 2022-12-10 20:11:10
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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll sum = accumulate(all(a), 0ll);
    t %= sum;
    vector<ll> b = a;
    rep(i, 1, n) a[i] += a[i - 1];
    int l = 1, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] > t) r = mid;
        else l = mid + 1;
    }
    cout << l << ' ' << b[l] - a[l] + t << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}