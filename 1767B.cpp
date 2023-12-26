/*
 * @Author: JorD
 * @LastEditTime: 2022-12-16 22:54:26
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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 2, a.end());
    for(int i = 2;i <= n;i ++){
        if(a[i] <= a[1]) continue;
        ll now = a[i] - a[1] + 1 >> 1;
        a[1] += now;
        a[i] -= now;
    }
    cout << a[1] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}