/*
 * @Author: JorD
 * @LastEditTime: 2023-08-07 23:03:50
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
    vector<int> res(n + 1), a(n * (n - 1) / 2 + 1);
    rep(i, 1, n * (n - 1) / 2) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int idx = 0;
    for(int i = 1, j = n - 1;i < n;i ++, j --){
        int m = j;
        while(m --) idx ++;
        res[i] = a[idx];
    }
    res[n] = res[n - 1];
    rep(i, 1, n) cout << res[i] << ' ';
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