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
    vector<ll> a(n + 1), pre(n + 1);
    ll mi = 0, sum = 0;
    rep(i, 1, n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        mi = max(mi, a[i]);
        sum += a[i];
    }
    ll res = n;
    rep(i, 1, n){
        ll mx = 0;
        if(sum % i) continue;
        ll now = sum / i;
        ll last = 0;
        ll ss = 0;
        rep(j, 1, n){
            ss += a[j];
            if(ss == now){
                mx = max(mx, j - last);
                last = j;
                ss = 0;
            }
        }
        if(ss) continue;
        res = min(res, mx);
    }
    cout << res << endl;
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