/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 19:26:42
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
const int N = 1e6 + 10;
char q[N];
void Solve(){
    string s;
    cin >> s;
    int idx = 0;
    for(auto x:s){
        q[++ idx] = x;
        while(idx >= 2&&q[idx] == q[idx - 1]){
            idx -= 2;
        }
    }
    while(idx >= 2&&q[idx] == q[idx - 1]){
        idx -= 2;
    }
    rep(i, 1, idx) cout << q[i];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}