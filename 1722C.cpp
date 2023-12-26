/*
 * @Author: JorD
 * @LastEditTime: 2022-08-30 23:14:07
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
set<string> sq[4];
void Solve(){
    int n;
    cin >> n;
    map<string, ll> q;
    map<string, ll> score;
    
    rep(j, 1, 3){
        sq[j].clear();
        rep(i, 1, n){
            string s;
            cin >> s;
            sq[j].insert(s);
        }
        for(auto x:sq[j]) q[x] ++;
    }
    for(auto x:q){
        if(x.second == 1) score[x.first] = 3;
        else if(x.second == 2) score[x.first] = 1;
    }
    rep(i, 1, 3){
        ll now = 0;
        for(auto x:sq[i]){
            if(!score[x]) continue;
            now += score[x];
        }cout << now << ' ';
    }cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}