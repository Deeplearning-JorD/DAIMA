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
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int z1 = 1, z2 = 1, y1 = n, y2 = n;
    while(z1 < n && a[z1] <= a[z1 + 1]) z1 ++;
    while(z2 < n && a[z2] >= a[z2 + 1]) z2 ++;
    while(y1 > 1 && a[y1] <= a[y1 - 1]) y1 --;
    while(y2 > 1 && a[y2] >= a[y2 - 1]) y2 --;
    int res = -1;
    auto cc = [&](int mid){
        if(res == -1) res = mid;
        else res = min(res, mid);
    };
    if(z1 == n || y2 == 1)
        cc(0);
    if(z2 == n || y1 == 1)
        cc(1);
    if(y1 == z2 + 1 && a[n] >= a[1])
        cc(1 + min(n - y1 + 1,z2));
    if(y2 == z1 + 1 && a[n] <= a[1])
        cc(min(2 + z1, n - y2 + 1));
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}