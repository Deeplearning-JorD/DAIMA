/*
 * @Author: JorD
 * @LastEditTime: 2022-10-21 21:26:05
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int M = 1e9 + 7;
void Solve(){
    string s;
    cin >> s;
    vector<vector<ll>> f(10, vector<ll>(10));
    vector<vector<ll>> pre(10, vector<ll>(10));
    for(auto x:s){
        rep(i, 1, 7){
            ll l = 0;
            if(i == 1){
                l = 1;
            }else if(i == 2||i == 4){
                per(j, x - '0' - 1, 0){
                    l += pre[i - 1][j];
                    l %= M;
                }
            }else{
                rep(j, x - '0' + 1, 9){
                    l += pre[i - 1][j];
                    l %= M;
                }
            }
            f[i][x - '0'] += l;
            f[i][x - '0'] %= M;
            pre[i][x - '0'] += l;
            pre[i][x - '0'] %= M;
        } 
    }
    ll res = 0;
    rep(i, 0, 9){
        res = (res + f[7][i])%M;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}