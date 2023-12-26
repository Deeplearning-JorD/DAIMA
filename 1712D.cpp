/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 21:37:38
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
    vector<int> a(n+1);
    rep(i, 1, n) cin >> a[i];
    auto check = [&](int mid){
        int cnt = 0;
        vector<int> c(n+1);
        rep(i, 1, n) cnt += (2*a[i] < mid), c[i] = ((2*a[i]<mid) ? 1e9:a[i]);
        int res = 2;
        rep(i, 1, n-1){
            int now = 0;
            now += c[i] < mid;
            now += c[i+1] < mid;
            res = min(res, now);
        }
        return res + cnt <= k;
    };
    int l = 1, r = 1e9;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
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