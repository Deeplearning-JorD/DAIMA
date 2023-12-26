/*
 * @Author: JorD
 * @LastEditTime: 2023-04-12 19:33:20
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
    set<int> s;
    s.insert(1);
    rep(i, 1, 10){
        vector<int> v;
        for(auto x:{9,99,999,9999}){
            for(auto u:s){
                v.push_back(u + x);
            }
        }
        for(auto x:v) s.insert(x);
    }
    // % 9  i ,  
    // cout << 21 % 9 << endl;
    for(auto x:s) cout << x << ' ' << x % 9 << ' ' << x / 9 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}