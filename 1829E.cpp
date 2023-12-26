/*
 * @Author: JorD
 * @LastEditTime: 2023-05-06 23:12:36
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
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    vector<int> a(n * m + 1);
    auto get = [&](int i, int j){
        return (i - 1) * m + j;
    };
    rep(i, 0, n * m) a[i] = i;
    function<int(int)> find = [&](int x){
        if(x != a[x]) a[x] = find(a[x]);
        return a[x];
    };
    rep(i, 1, n){
        rep(j, 1, m)if(f[i][j]){
            if(i > 1 && f[i - 1][j]) a[find(get(i, j))] = find(get(i - 1, j));
            if(j > 1 && f[i][j - 1]) a[find(get(i, j))] = find(get(i, j - 1));
        }
    }
    vector<ll> cnt(n * m + 1);
    rep(i, 1, n) rep(j, 1, m) if(f[i][j]){
        cnt[find(get(i, j))] += f[i][j];
    }
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}