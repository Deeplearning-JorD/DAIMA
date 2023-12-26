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
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<vector<int>> pre(2, vector<int> (n + 2));
    rep(i, 2, n){
        pre[0][i] = pre[0][i - 1];
        pre[1][i] = pre[1][i - 1];
        if(a[i - 1] <= a[i]) pre[0][i] ++;
        if(a[i - 1] >= a[i]) pre[1][i] ++;
    }   
    pre[1][n + 1] = pre[1][n];
    int res = pre[1][n];
    for(int i = 1;i <= n;i ++){
        res = min(res, pre[0][i] + pre[1][n] - pre[1][i + 1] + 1);
    }
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