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
const int MOD=1e7+7;
void Solve(){
    int n; cin>>n;
    priq<int,vector<int>> q;
    rep(i,1,n){
        int x;
        cin>>x;
        q.push(x);
    }
    ll res=0;
    rep(i,2,n){
        if(q.size()<2) break;
        int a=q.top(); q.pop();
        int b=q.top(); q.pop();
        if(a+b>0){
            q.push(a+b);
            res+=a+b;
        }
        res%=MOD;
    }
    cout<<res<<endl;
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