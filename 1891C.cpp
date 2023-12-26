/*
 * @Author: JorD
 * @Date: 2023-10-30 22:48:01
 * @LastEditTime: 2023-10-30 23:39:39
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
void Solve(){
    int n; cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(all1(a));
    ll j = 1, res = 0, now = 0;
    for(int i = n;i >= j;i --){
        if(a[i] == 0) break;
        now = 0;
        for(;j < i;j ++){
            now += a[j];
            a[j] = 0;
            if(now >= a[i]){
                a[j] = now - a[i];
                now -= a[j];
                break;  
            }
        }
        now += a[i];
        res += min(now + 3 >> 1, now);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}