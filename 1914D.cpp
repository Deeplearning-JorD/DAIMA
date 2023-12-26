/*
 * @Author: JorD
 * @Date: 2023-12-19 22:55:44
 * @LastEditTime: 2023-12-20 02:43:40
 * how to Get
 */
#include <bits/stdc++.h>
#include<numeric>
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
    vector<int> a(n + 1), b(n + 1), c(n + 1), id(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) cin >> c[i];
    // rep(i, 1, n) id[i] = i;
    iota(id.begin(), id.end(), 0);
    set<int> s;
    sort(id.begin() + 1, id.end(), [&](int i, int j){
        return a[i] > a[j];
    });
    rep(i, 1, 3) s.insert(id[i]);
    sort(id.begin() + 1, id.end(), [&](int i, int j){
        return b[i] > b[j];
    });
    rep(i, 1, 3) s.insert(id[i]);
    sort(id.begin() + 1, id.end(), [&](int i, int j){
        return c[i] > c[j];
    });
    rep(i, 1, 3) s.insert(id[i]);
    vector<int> v;
    int res = 0;
    for(auto x:s) v.push_back(x);
    for(int i = 0;i < v.size();i ++){
        for(int j = 0;j < v.size();j ++)if(i != j){
            for(int k = 0;k < v.size();k ++)if(j != k && k != i){
                res = max(res, a[v[i]] + b[v[j]] + c[v[k]]);
            }
        }
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