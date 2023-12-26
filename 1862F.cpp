/*
 * @Author: JorD
 * @LastEditTime: 2023-08-25 19:26:23
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
const int N = 1e7 + 10;
bitset<N> A;
int pre[N];
void Solve(){
    ll w, f, n; cin >> w >> f >> n;
    A.reset();
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    A[0] = 1;
    ll sum = 0;
    for(int i = 1;i <= n;i ++){
        A |= A << a[i];
        sum += a[i];
    }
    for(int i = 0;i <= 1e7;i ++){
        if(A[i]) pre[i] = i;
        else pre[i] = pre[i - 1];
    }
    auto check = [&](ll mid){
        ll l = w * mid, r = f * mid;
        ll now = sum;
        now -= l; now -= r;
        if(now > 0) return false;
        if(r >= sum - pre[min(N - 10ll, l)]) return true;
        if(l >= sum - pre[min(N - 10ll, r)]) return true;
        return false;
    };
    ll l = 1, r = 1e7;
    while(l < r){
        ll mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}