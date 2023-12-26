/*
 * @Author: JorD
 * @LastEditTime: 2022-10-11 16:29:31
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
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
void Solve(){   
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 2);
    rep(i, 1, n) cin >> a[i];
    b[1] = a[1];
    b[n + 1] = a[n];
    rep(i, 2, n){
        b[i] = lcm(a[i], a[i - 1]);
    }
    rep(i, 1, n){
        if(a[i] < gcd(b[i], b[i + 1])){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t -- )
    Solve();
    return 0;
}