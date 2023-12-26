/*
 * @Author: JorD
 * @LastEditTime: 2022-07-25 12:48:17
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
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
vector<string> q;
void Solve(){
    int n;
    cin>>n;
    rep(i,1,n){
        string s;cin>>s;
        q.emplace_back(s);
    }
    sort(q.begin(),q.end(),[](string &s1,string &s2){
        return s1+s2<s2+s1;
    });
    for(auto x:q) cout<<x;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}