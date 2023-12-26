/*
 * @Author: JorD
 * @LastEditTime: 2023-05-05 21:32:18
 */
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
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0; 
        return a;
    }
    int x1,y1,gcd;
    gcd = exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1; 
    return gcd;
}
void Solve(){
    int a, b, n, l, r;
    cin >> a >> b >> n >> l >> r;
    if(n % __gcd(a, b)){
        cout << "NO\n";
        return;
    }
    int d = exgcd(a, b, x, y);
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}