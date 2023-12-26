/*
 * @Author: JorD
 * @LastEditTime: 2022-09-02 22:51:41
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
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
void Solve(){
    // int n;
    // cin >> n;
    int res = 0;
    // a * b <= 3 * gcd(a,b) * gcd(a,b);
    rep(n, 1, 100){
        res = 0;
    
    rep(i, 1, n){
        rep(j, 1, n){
            int gg = gcd(i, j);
            if(i * j <= 3*gg*gg){
                res++;
                // cout << i << ' ' << j << endl;
            }
        }
    }
    // cout << n << ' ' << res << endl;4
    cout << n << ' ';
    cout << (n)*2 - (n)/3*2 << ' ';
    cout << res - n << ' ';
    cout << (int)sqrt(n) << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t;
    // while(t--)
    Solve();
    return 0;
}