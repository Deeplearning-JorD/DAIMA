/*
 * @Author: JorD
 * @LastEditTime: 2022-12-06 01:44:33
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> pre(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n){
        pre[i] = pre[i - 1] + a[i];
    }
    vector<ll> v;
    v.push_back(1);
    rep(i, 2, n){
        if(pre[v.back()] < pre[i]){
            v.push_back(i);
        }
    }
    while(m --){
        ll x;
        cin >> x;
        if(pre[n] <= 0){
            if(pre[v.back()] < x) cout << -1 << ' ';
            else{
                int l = 0, r = v.size() - 1;
                while(l < r){
                    ll mid = l + r >> 1;
                    if(pre[v[mid]] >= x) r = mid;
                    else l = mid + 1;
                }
                cout << v[r] - 1 << ' ';
            }
            continue;
        }
        ll l = 0, r = 2e9;
        ll mx = pre[v.back()];
        if(mx >= x){
            l = 0, r = v.size() - 1;
            while(l < r){
                ll mid = l + r >> 1;
                if(pre[v[mid]] >= x) r = mid;
                else l = mid + 1;
            }
            cout << v[r] - 1 << ' ';
            continue;
        }
        ll s1 = x - pre[v.back()];
        ll rr = s1 / pre[n] + (s1 % pre[n] != 0ll);
        l = 0, r = v.size() - 1;
        while(l < r){
            ll mid = l + r >> 1;
            if(rr * pre[n] + pre[v[mid]] >= x) r = mid;
            else l = mid + 1;
        }
        cout << rr * n + v[r] - 1 << ' ';
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}