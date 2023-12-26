/*
 * @Author: JorD
 * @LastEditTime: 2023-02-01 14:32:26
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
const int N = 1e5 + 10;
ll a[N], pre[N];
void Solve(){   
    int n, q;
    cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
    while(q --){
        ll k, x; cin >> k >> x;
        if(a[1] > x){
            cout << 0 << endl;
            continue;
        }
        ll l = 1, r = n;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(a[mid] <= x) l = mid;
            else r = mid - 1;
        }
        cout << pre[l] - pre[max(0ll, l - k)] << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}