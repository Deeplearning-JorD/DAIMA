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
const int N = 5e6 + 10, p = 1e9 + 7;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll inv[N];
void Solve(){
    ll n, r1, r2, r, a, h;
    cin >> n >> r1 >> r2 >> r >> a >> h;
    ll k = (h + a - 1) / a;
    if(k > n){
        cout << 0 << endl;
        return;
    }
    
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    }
    ll num;
    if(r1 + r >= r2){
        cout << 1 << endl;
        return;
    }else num = fpow((r1 + r), 2, p) * fpow(fpow(r2, 2, p), p - 2, p) % p;
    ll num1 = ((1 - num + p) % p + p) % p;
    ll inum = fpow(num, p - 2, p);
    ll inum1 = fpow(num1, p - 2, p);
    ll sum = 0;
    ll now = fpow(num, k, p) * fpow(num1, n - k, p) % p;
    for(ll i = 1;i <= k;i ++){
        now = now * (n - i + 1) % p * inv[i] % p;        
    }
    sum += now;
    for(ll i = k + 1;i <= n;i ++){
        now = now * num % p * inum1 % p * (n - i + 1) % p * inv[i] % p;
        sum += now;
        sum %= p;
    }
    cout << sum;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}