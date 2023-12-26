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
    ll n, m, k;
    cin >> n >> k >> m;
    while(m --){
        ll x;
        cin >> x;
        ll now = x;
        ll dep = 0;
        if(k == 1){
            cout << n - x << endl;
            continue;
        }
        while(now <= n - 1){
            now *= k;
            now ++;
            dep ++;
        }
        if(now > n - 1) dep --;
        now = x;
        ll pre = 1, res = 1;
        rep(i, 1, dep){
            pre *= k;
            res += pre;
            now *= k;
            now += k; 
        }
        res -= max(0ll, now - n + 1);
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}