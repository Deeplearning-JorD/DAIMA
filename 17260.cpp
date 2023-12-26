/*
 * @Author: JorD
 * @LastEditTime: 2022-09-06 22:46:40
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
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    int res = max(a[n] - a[1], 0);
    int maxn = a[n];
    res = max(0, res);
    rep(i, 2, n){
        maxn = max(maxn, a[i]);
    }
    res = max(res, maxn - a[1]);
    rep(i, 1, n - 1){
        res = max(res, a[i] - a[i+1]);
    }
    int minn = a[1];
    rep(i, 1, n - 1) minn = min(minn, a[i]);
    cout << max(res, a[n] - minn) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}