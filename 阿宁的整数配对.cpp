/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 13:53:05
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
const int N = 2e5 + 10, c = 100;
ll a[N];
void Solve(){
    ll n, k;
    cin >> n >> k;
    rep(i, 1, n){
        cin >> a[i];
    }
    int l = 1, r = n;
    vector<PII> q;
    while(l < r){
        q.push_back({a[l] * a[l + 1], 1});
        q.push_back({a[r] * a[r - 1], 1});
        l += 2, r -= 2;
    }
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    ll res = 0;    
    for(auto [w, num]:q){
        if(k <= 0) break;
        res += min(num, k) * w;
        k -= min(num, k);
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