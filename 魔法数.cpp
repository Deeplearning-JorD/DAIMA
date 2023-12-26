/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 16:41:33
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
unordered_map<ll,int> st;
bool stt[1004];
vector<ll> pri;
bool is(ll now){
    if(now<2) return false;
    for(int i=2;i<=now/i;i++){
        if(now%i==0) return false;
    }
    return true;
}
int get(ll now){
    int res=0;
    for(auto x:pri){
        if(x*x*x*x>now) break;
        res++;
    }return res;
}
void Solve(){
    ll l, r;
    cin >> l >> r;
    cout<<get(r)-get(l-1)<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(i,1,1e3+2){
        if(is(i)){
            pri.push_back(i);
        }
    }
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}