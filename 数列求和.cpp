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
const ll mod = 1e11+3;
const int N=1e7+5;
ll f[N];
void Solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    ll pre=4;
    f[1]=1;f[2]=3;
    rep(i,3,n){
        f[i]=(f[i-1]+f[i-2])%mod;
        pre=(pre+f[i])%mod;
    }
    cout<<pre;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}