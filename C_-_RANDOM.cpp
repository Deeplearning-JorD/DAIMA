/*
 * @Author: JorD
 * @LastEditTime: 2022-11-26 20:11:21
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
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    vector<vector<char>> t(n + 1, vector<char> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    rep(i, 1, n) rep(j, 1, m) cin >> t[i][j];
    vector<string> v, vv;
    rep(j, 1, m){
        string now = "", noww = "";
        rep(i, 1, n){
            now += f[i][j];
            noww += t[i][j];
        }
        v.push_back(now);
        vv.push_back(noww);
    }
    sort(all(v));
    sort(all(vv));
    if(v == vv) cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}