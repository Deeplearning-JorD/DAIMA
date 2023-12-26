/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 13:45:27
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
    ll n, L, v;
    cin >> n >> L >> v;
    ll yT = (L + v - 1) / v;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    rep(i, 1, n) a[i] += a[i - 1];
    int t; cin >> t;
    while(t --){
        ll T;
        cin >> T;
        int l = 0, r = n;
        if((L + a[n] + v - 1) / v <= T){
            cout << -1 << endl;
            continue;
        }
        while(l < r){
            int mid = l + r >> 1;
            if((L + a[mid] + v - 1) / v > T) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}