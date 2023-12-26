/*
 * @Author: JorD
 * @LastEditTime: 2023-06-05 20:00:01
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
bool prime(int x){
    if(x<2) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int> (m + 1));
    vector<int> a(m + 1);
    a[1] = 1;
    rep(i, 2, m) a[i] = a[i - 1] + n;
    int idx, l, r;
    if(m & 1) l = m;
    else l = m - 1;
    if(m & 1) r = m - 1;
    else r = m;
    idx = l;
    rep(i, 1, m){
        if(idx < 1) idx = r;
        f[1][i] = a[idx];
        idx -= 2;
    }
    rep(i, 2, n)
    rep(j, 1, m)
    f[i][j] = f[i - 1][j] + 1;
    rep(i, 1, n){
        rep(j, 1, m)
            cout << f[i][j] << ' ';
        cout << endl;
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