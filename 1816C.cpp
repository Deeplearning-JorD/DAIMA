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
    int n;
    cin >> n;
    ll odd = 0, even = 0, last = -1e18;
    rep(i, 1, n){
        ll x;
        cin >> x;
        if(i & 1) odd += x - last;
        else even += x - last;
        last = x;
    }
    if(n & 1) even = 0;
    else odd = 0;
    if(odd >= 0 && even >= 0) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}