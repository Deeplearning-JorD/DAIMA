/*
 * @Author: JorD
 * @LastEditTime: 2022-11-22 01:21:24
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
const string INF = "Infinity";
const string NO = "Impossible";
void Solve(){
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    for(auto &x:a) cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    if(d * a[0] < c){
        cout << NO << endl;
        return;
    }
    ll l = 0, r = d;
    vector<ll> pre(n + 1, 0);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i - 1];
    if(pre[min(n, d)] >= c){
        cout << INF << endl;
        return;
    }
    auto check = [&](ll k){
        k ++;
        ll dd = d / k, kk = d % k;
        ll res = pre[min(n, k)] * dd;
        res += pre[min(n, kk)];
        return res >= c;
    };
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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