/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 17:51:50
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
const int N = 2e5 + 10;
int pre[N];
bool prime(int x){
    if(x<2) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
void Solve(){
    int n, k; cin >> n >> k;
    int last = 0;
    ll mx = 0;
    rep(i, 1, n){
        pre[i] = pre[i - 1] + prime(i);
        if(prime(i)){
            // cout << i - last << endl;
            mx = max(i - last, mx);
            last = i;
        }
    }
    cout << mx << endl;
    ll res = 0;
    rep(i, k + 2, n) res ++;
    rep(i, 2, min(k + 1, n)){
        int l = i + k + 1, r = n;
        if(r >= l && pre[r] > pre[l - 1]){
            res ++;
            continue;
        }
        if(i + k + 1 > n){
            res += i;
            continue;
        }
        ll now = 1e18;
        rep(j, l, r){
            now = min(now, __gcd(j, i));
        }
        res += now;
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}