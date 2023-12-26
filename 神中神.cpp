/*
 * @Author: JorD
 * @LastEditTime: 2022-11-27 15:30:07
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
ll a, b, k;
void Solve(){
    cin >> a >> b >> k;
    ll w = 0;
    if(k >= a&&k <= b) w ++;
    if(k > sqrt(b)||k > b / k||k >= 1e9){
        cout << w;
        return;
    }
    ll l = 0, r = b / k - k + 1;
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if(k * (k + mid) <= b) l = mid;
        else r = mid - 1;   
    }
    ll R = l;
    l = 0, r = b / k - k + 1;
    while(l < r){
        ll mid = l + r >> 1;
        if(k * (k + mid) >= a) r = mid;
        else l = mid + 1;   
    }
    cout << max(0ll, R - r + 1) + w;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}