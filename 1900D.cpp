/*
 * @Author: JorD
 * @Date: 2023-11-26 23:20:09
 * @LastEditTime: 2023-11-28 02:20:56
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
const int N = 1e5 + 10;
int cnt[N], nm[N];
vector<int> v[N];
void Solve(){
    memset(cnt, 0, sizeof cnt);
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll res = 0;
    for(int i = 1;i < n;i ++){
        for(auto x:v[a[i]]){
            int tt = cnt[x] + nm[x];
            res += 1ll * x * tt * (n - i);
            for(auto z:v[x]) nm[z] -= tt;
            cnt[x] ++;
            nm[x] = 0;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 1e5;i >= 1;i --){
        for(int j = i;j <= 1e5;j += i){
            v[j].push_back(i);
        }
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}