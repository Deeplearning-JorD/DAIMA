/*
 * @Author: JorD
 * @LastEditTime: 2023-08-16 00:33:44
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
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(m + 2);
    rep(i, 1, m) cin >> a[i];
    ll res = 0, id = 1;
    a[0] = 1, a[m + 1] = n;
    ll last = 0;
    vector<ll> pre(m + 2), suf(m + 2);
    rep(i, 1, m){
        pre[i] = pre[i - 1];
        ll now = a[i] - last;
        if(i == 1){
            now = a[i] - 1;
            if(now % d == 0) now /= d;
            else now = now / d + 1;
            pre[i] += now + 1;
            last = a[i];
            continue;
        }
        if(now % d == 0) now /= d;
        else now = now / d + 1;
        pre[i] += now;
        last = a[i];
    }
    last = n + 1;
    per(i, m, 1){
        suf[i] = suf[i + 1];
        ll now = last - a[i];
        if(i == m){
            now = n - a[i];
            now = now / d + 1;
            suf[i] += now;
            last = a[i];
            continue;
        }
        if(now % d == 0) now /= d;
        else now = now / d + 1;
        suf[i] += now;
        last = a[i];
    }
    pre[0] = 1;
    map<ll, ll> cnt;
    ll ans = 1e18, mi = 1e18;
    rep(i, 1, m){
        mi = min(mi, ans);
        // if(a[i] == 1){
        //     ans = suf[1];
        //     cnt[ans] ++;
        //     mi = min(ans, mi);
        //     continue;
        // }
        // if(a[i] == n){
        //     ans = pre[i] - 1;
        //     cnt[ans] ++;
        //     mi = min(ans, mi);
        //     continue;
        // }
        if(i == 1){
            ans = suf[i + 1];
            ll now = a[i + 1] - 1;
            if(now % d == 0) now = now / d - 1;
            else now /= d;
            now ++;
            ans += now;
            mi = min(mi, ans);
            cnt[ans] ++;
            continue;
        }
        if(i == m){
            ans = pre[i - 1];
            ll now = n - a[i - 1];
            now /= d;
            ans += now;
            mi = min(ans, mi);
            cnt[ans] ++;
            continue;
        }
        ans = pre[i - 1] + suf[i + 1];
        ll now = a[i + 1] - a[i - 1];
        if(now % d == 0) now = now / d - 1;
        else now /= d;
        ans += now;
        mi = min(ans, mi);
        cnt[ans] ++;
    }
    mi = min(mi, ans);
    cout << mi << ' ' << cnt[mi] << endl;
    return;
}   
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}