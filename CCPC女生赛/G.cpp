/*
 * @Author: JorD
 * @LastEditTime: 2022-11-30 17:46:02
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
    ll T, num;
    cin >> T >> num;
    ll m, k;
    cin >> m >> k;
    vector<pair<ll,ll>> a(m);
    for(auto &[x, y]:a) cin >> x >> y;
    sort(all(a));
    ll sum = 0, idx = 0;
    ll wait = 1e18, miu = 0;
    ll can = 0, last = 0;
    for(auto [t, x]:a){
        if(t < T){
            sum -= min(sum, (t - last - 1) * k);
            sum += x;
            sum -= min(sum, k);
            last = t;
            continue;
        }
        ll b = sum;
        if(!idx)
        sum -= min(sum, (T - last - 1) * k);
        if(!idx &&sum != num){
            cout << "Wrong Record\n";
            return;
        }
        if(!idx) sum = b - min(b, (t - last - 1) * k);
        if(idx) sum -= min(sum, (t - last - 1) * k);
        idx = 1;
        sum += x;
        if(sum > 0 && (sum + 1 + k - 1) / k <= wait){
            wait = (sum + 1 + k - 1) / k;
            miu = t;
        }
        sum -= min(sum, k);
        last = t;
    }
    cout << miu << ' ' << wait;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}