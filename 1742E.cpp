/*
 * @Author: JorD
 * @LastEditTime: 2022-10-13 23:23:31
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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n + 1);
    ll sum = 0;
    ll mx = 0;
    map<ll,ll> q; 
    vector<ll> res;
    rep(i, 1, n){
        ll x;
        cin >> x;
        sum += x;
        if(x > mx){
            res.push_back(mx);
            q[mx] = sum - x;
            mx = x;
        }
    }
    ll x = 2e9;
    sum += x;
    if(x > mx){
        res.push_back(mx);
        q[mx] = sum - x;
        mx = x;
    }
    sum -= x;
    res.push_back(1e10);
    while(t --){
        ll x;
        cin >> x;
        auto ans = lower_bound(res.begin(), res.end(), x);
        if(*ans == x){
            cout << q[*ans] << ' ';
            continue;
        }
        if(ans != res.begin()){
            ans --;
            cout << q[*ans] << ' ';
        }else cout << 0 << ' ';
    }
    cout << '\n';
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