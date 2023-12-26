/*
 * @Author: JorD
 * @Date: 2023-11-07 18:11:31
 * @LastEditTime: 2023-11-07 20:26:52
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
//O(7e8)
void Solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), md(n + 1), bit(n + 1), v;
    rep(i, 1, n){
        cin >> a[i];
        int x = a[i];
        int j = 0;
        while(x){
            v.push_back(x);
            x >>= 1;
            j ++;
        }
    }
    ll res = 1e18;
    sort(v.rbegin(), v.rend());
    for(auto x:v){
        vector<int> s;
        for(int i = 1;i <= n;i ++){
            if(x >= a[i]){
                s.push_back(x - a[i] + bit[i]);
            }else if(a[i] / 2){
                int l = a[i] - x, r = x - a[i] / 2 + 1;
                if(r < l){
                    a[i] >>= 1;
                    s.push_back(r + bit[i]);
                    bit[i] ++;
                }else{
                    s.push_back(l + bit[i]);
                }
            }else{
                s.push_back(a[i] - x + bit[i]);
            }
            
        }
        sort(s.begin(), s.end());
        ll sum = 0;
        for(int i = 0;i < n - m;i ++) sum += s[i];
        res = min(res, sum);
    }
    cout << res << endl;
    // cout << 10ll * 30 * 500 * 500 * 30 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}