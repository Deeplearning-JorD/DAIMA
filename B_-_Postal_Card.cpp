/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 20:05:36
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
    vector<string> a(n);
    for(auto &x:a) cin >> x;
    set<string> s;
    rep(i, 1, m){
        string ji; cin >> ji;
        s.insert(ji);
    }
    int res = 0;
    for(auto x:a){
        string now = x.substr(3, 3);
        for(auto y:s){
            if(now == y){
                res ++;
                break;
            }
        }
    }cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}