/*
 * @Author: JorD
 * @LastEditTime: 2022-11-23 00:38:18
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
const ll m = 998244353;
void Solve(){
    ll n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> b = a;
    sort(all1(b));
    if(b[n] - 2 >= b[n - 1]){
        cout << 0 << endl;
        return;
    }
    ll mm = 0;
    rep(i, 1, n) if(b[i] == b[n] - 1) mm ++;
    ll sum = 1;
    if(b[n] == b[n - 1]){
        rep(i, 1, n){
            sum *= i;
            sum %= m;
        }
        cout << sum << endl;
        return;
    }
    rep(i, 1, n){
        if(i == mm + 1) continue;
        sum *= i;
        sum %= m;
    }
    sum *= mm;
    cout << sum % m << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}