#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    double n; cin >> n;
    double d1 = 0, d2 = 0;
    for(int i = 1;i <= n;i ++){
        double dd1 = d1;
        d1 = d1 + (n / i);
        d2 = (2 * (n - i) / i) * d1 + d2 + 2 * dd1 + (n / i);
    }
    cout << SPO(2) << ((d1 + d2) / 2);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}