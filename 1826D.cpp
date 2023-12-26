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
#define per(i, r, l) for (int(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    vector<int> w(n + 1), pre(n + 1), last(n + 2);
    rep(i, 1, n) cin >> w[i];
    pre[1] = w[1] + 1;
    rep(i, 2, n) pre[i] = max(pre[i - 1], w[i] + i);
    last[n] = w[n] - n;
    per(i, n - 1, 1) last[i] = max(last[i + 1], w[i] - i);
    int res = 0;
    rep(i, 2, n-1) res = max(res, pre[i - 1] + w[i] + last[i + 1]);
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