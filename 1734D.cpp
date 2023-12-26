/*
 * @Author: JorD
 * @LastEditTime: 2022-09-23 21:52:23
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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    vector<ll> w(n + 1);
    vector<ll> mxl(n + 2), mxr(n + 2);
    rep(i, 1, n) cin >> a[i];
    ll sum = 0;
    rep(i, k + 1, n){
        sum += a[i];
        w[i] = sum;
        mxr[i] = max(mxr[i - 1], w[i]);
    }sum = 0;
    per(i, k - 1, 1){
        sum += a[i];
        w[i] = sum;
        mxl[i] = max(mxl[i + 1], w[i]);
    }
    bool res = false;
    int l = k - 1, r = k + 1;
    rep(i, 1, 2 * n){
        ll nowr, nowl;
        if(k + 1 != r) nowr = mxr[r - 1];
        else nowr = 0;
        if(k - 1 != l) nowl = mxl[l + 1];
        else nowl = 0;
        if(a[k] + nowr + w[l] >= 0) l --;
        if(a[k] + nowl + w[r] >= 0) r ++;
        if(l <= 0 || r >= n + 1)  break;
    }
    if(l <= 0 || r >= n + 1) res = true;
    if(res) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}