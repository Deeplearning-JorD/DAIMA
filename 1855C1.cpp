/*
 * @Author: JorD
 * @LastEditTime: 2023-07-29 22:59:09
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n;
    vector<ll> b(n + 1);
    vector<pair<ll,ll>> a(n + 1);
    vector<pair<ll,ll>> res;
    rep(i, 1, n){
        cin >> b[i];
        a[i] = {b[i], i};
    }
    sort(a.begin() + 1, a.end());
    if(a[n].first > 0){
        ll mx = 0;
        int j = a[n].second;
        while(b[j] <= 40){
            b[j] += b[j];
            res.push_back({j, j});
            mx = b[j];
        }
        rep(i, 2, n){
            while(b[i] < b[i - 1]){
                b[i] += b[j];
                res.push_back({i, j});
                if(b[i] > mx){
                    mx = b[i];
                    j = i;
                }
            }
        }
    }else if(a[1].first < 0){
        ll mx = 0;
        int j = a[1].second;
        while(b[j] >= -40){
            b[j] += b[j];
            res.push_back({j, j});
            mx = b[j];
        }
        per(i, n - 1, 1){
            while(b[i] > b[i + 1]){
                b[i] += b[j];
                res.push_back({i, j});
                if(b[i] < mx){
                    mx = b[i];
                    j = i;
                }
            }
        }
    }else{
        cout << 0 << endl;
        return;
    }
    cout << res.size() << endl;
    for(auto [x, y] : res) cout << x << ' ' << y << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}