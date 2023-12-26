/*
 * @Author: JorD
 * @LastEditTime: 2022-08-19 19:14:22
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
ll f[100];
int n;
void Solve(){
    ll x; 
    cin >> x;
    int t = lower_bound(f+1, f+1+n, x) - f - 1;
    if(t == n) cout << t << endl;
    else{
        if(x - f[t] > f[t+1] - x){
            cout << t + 1 << endl;
        }else cout << t <<endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    f[1] = f[2] = 1;
    for(int i = 3;; i++ ){
        f[i] = f[i-1] + f[i-2];
        if(f[i] > 1e18){
            n = i;
            break;
        }
    }
    while(t --)
    Solve();
    rep(i,1,n) cout << f[i]<< ' '; 
    return 0;

}