/*
 * @Author: JorD
 * @LastEditTime: 2022-08-12 14:44:37
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
void Solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<bool> st(n);
    map<int,int> q;
    int l,r;
    rep(i,0,n-1){
        cin>>a[i];
        q[a[i]]=i;
        if(a[i]==1){
            l=i,r=i;
            // cout<<i<<endl;
        }
    }
    rep(i,0,n-1){
        int need=q[i+1];
        if(need>r) r=need;
        else if(need<l) l=need;
        if(r-l==i) st[i]=true;
        // cout<<l<<' '<<r<<endl;
    }
    for(auto x:st) cout<<x;
    cout<<endl;
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