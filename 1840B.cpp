#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N=1e5+10,mod=1e9+7;
typedef long long ll;
ll fact[N],infact[N];
int qmi(int a,int k,int p){
    int res=1;
    while(k){
        if(k&1) res=(ll)res*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}
ll C(int a, int b){
    return (ll)fact[a]*infact[b]%mod*infact[a-b]%mod;
}
void Solve(){
    ll n, k;
    cin >> n >> k;
    cout << min(n + 1, 1ll << min(30ll, k)) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=fact[i-1]*i%mod;
        infact[i]=(ll)infact[i - 1]*qmi(i,mod-2,mod)%mod;
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}