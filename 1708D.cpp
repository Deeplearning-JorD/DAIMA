/*
 * @Author: JorD
 * @LastEditTime: 2022-08-11 19:28:13
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
map<int,int> q;
int n;
void dfs(int idx){
    if(idx == n) return;
    map<int,int> now;
    for(auto i = q.begin(); i != q.end(); i=next(i)){
        if(i->second > 1) now[0] += i->second - 1;
        auto j = i; j = next(j);
        if(j != q.end()) now[j->first - i->first]++;
    }
    q = now;
    dfs(idx+1);
} 
void Solve(){
    cin >> n;
    q.clear();
    rep(i,1,n){
        int x;
        cin>>x;
        q[x]++;
    }    
    dfs(1);
    cout<<q.begin()->first<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;

    while(t--)
    Solve();
    return 0;
}