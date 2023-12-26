/*
 * @Author: JorD
 * @LastEditTime: 2022-08-19 14:06:39
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
#define rep(i, l, r) for (auto(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;                                               
    vector<int> a(n+1);
    vector<int> f(n+1, 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n){
        rep(j, i + 1, min(n, i+400)){
            if((a[i] ^ (j - 1)) < (a[j] ^ (i - 1))) f[j] = max(f[i] + 1, f[j]);
        }
    }
    cout << *max_element(f.begin(), f.end()) << endl;
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