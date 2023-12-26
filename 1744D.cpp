/*
 * @Author: JorD
 * @LastEditTime: 2022-10-16 23:57:35
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
// map<int,int> q
void Solve(){
    int n;
    cin >> n;
    bool st = true;
    ll res = 0;
    ll w = 0;
    vector<ll> val;
    rep(i, 1, n){
        ll x;
        cin >> x;
        if(x % 2 == 0){
            int cnt = 0;
            while(x&&x % 2 == 0){
                cnt ++;
                x >>= 1;
            }
            res += cnt;
        }
        x = i;
        if(x % 2 == 0){
            int cnt = 0;
            while(x&&x % 2 == 0){
                cnt ++;
                x >>= 1;
            }
            w += cnt;
            val.push_back(cnt);
        }
    }
    if(res + w < n){
        cout << -1 << endl;
        return;
    }
    if(res >= n){
        cout << 0 << endl;
        return;
    }
    ll need = res / n;
    ll k = res % n;
    ll ans = 0;
    k = n - k;
    sort(val.begin(), val.end());
    reverse(val.begin(), val.end());
    for(auto x:val){
        if(k - x >= 0){
            k -= x;
            ans ++;
        }
        if(k == 0) break;
    }
    cout << ans << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    // vector<ll> val;
    // rep(i, 1, 100){
    //     int x = i;
    //     if(x % 2 == 0){
    //         int cnt = 0;
    //         while(x&&x % 2 == 0){
    //             cnt ++;
    //             x >>= 1;
    //         }
    //         val.push_back(cnt);
    //     }
    // }
    // sort(val.begin(), val.end());
    // reverse(val.begin(), val.end());
    // for(auto x:val) cout << x << ' ' ;
    return 0;
}