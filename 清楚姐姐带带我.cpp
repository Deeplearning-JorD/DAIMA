/*
 * @Author: JorD
 * @LastEditTime: 2022-09-02 19:32:32
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
const ll MOD = 19980829;
void Solve(){
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    rep(i, 1, n)    cin >> a[i] >> b[i];
    ll now = 0;
    bool st = false;
    rep(i, 1, n){
        ll last = now;
        now *= b[i];
        last += a[i];
        if(st){
            if(b[i] >= 2) now %= MOD;
            else now = last % MOD;
            continue;
        }
        if(last >= 1e9 || now >= 1e9){
            st = true;
            now = max(now, last) % MOD;
        }else now = max(now, last);
    }
    cout << now % MOD << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}