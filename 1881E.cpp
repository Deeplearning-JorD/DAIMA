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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
void Solve(){
    int n; cin >> n;
    vector<int> a(n + 1), d(n + 2);
    rep(i, 1, n) cin >> a[i];
    for(int i = 1;i <= n;i ++){
        d[i] = max(d[i], d[i - 1]);
        int j = i + a[i] + 1;
        if(j <= n + 1){
            d[j] = max(d[j], d[i] + a[i] + 1);
        }
    }
    int res = n;
    rep(i, 1, n + 1) res = min(res, n - d[i]);
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