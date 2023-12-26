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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> pre(n + 1, vector<int> (2));
    vector<int> a(n + 1), pp(n + 1);
    rep(i, 1, n){
        ll x; cin >> x; 
        a[i] = x & 1;
        pre[i][0] = pre[i - 1][0] ^ a[i];
        pre[i][1] = pre[i - 1][1];
        if(pre[i][0] == 0) pre[i][1] ++;
    }
    while(m --){
        int l, r, k;
        cin >> l >> r >> k;
        int tot = pre[r][1] - pre[l - 1][1];
        if(pre[l-1][0]) tot = r - l + 1 - tot;
        if(pre[l-1][0] != pre[r][0]) tot = -1;
        if(tot >= k) cout << "YES\n";
        else cout << "NO\n";
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