/*
 * @Author: JorD
 * @LastEditTime: 2023-07-01 20:17:00
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
    vector<string> c(n + 1);
    rep(i, 1, n) cin >> c[i];
    map<string, int> q;
    string p0;
    rep(i, 1, m){
        string x; cin >> x;
        q[x] = i;
    } 
    int res = 0;
    vector<int> p(m + 1);
    rep(i, 0, m) cin >> p[i];
    rep(i, 1, n){
        if(q.count(c[i])){
            res += p[q[c[i]]];
        }else res += p[0];
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}