/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 01:23:01
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
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'.
const int N=5e2+10;
int a[N];
void Solve(){
    string s=" atcoder";
    map<char,int> get;
    for(int i=1;i<=7;i++) get[s[i]]=i;
    string p;
    cin>>p;
    int res=0;
    int idx=1;
    for(auto x:p)
        a[idx++]=(get[x]);
    for(int i=1;i<=7;i++){
        for(int j=1;j<i;j++) if(a[j]>a[i]) res++;
    }cout<<res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}