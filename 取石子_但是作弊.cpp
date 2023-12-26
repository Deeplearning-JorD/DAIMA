/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 14:07:55
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
    vector<int> a(n+1);
    int XOR = 0;
    rep(i,1,n){
        cin>>a[i];
        XOR^=a[i];
    }
    ll res=a[1];
    rep(i,1,a[1]-1){
        rep(j,2,n){
            if(0==(XOR^a[1]^a[j]^(a[1]-i)^(a[j]+i)))
                res=min(i,res);
        }
    }
    if(res==a[1]) cout<<-1<<endl;
    else cout<<res<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}