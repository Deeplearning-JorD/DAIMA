/*
 * @Author: JorD
 * @LastEditTime: 2022-12-15 22:40:10
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
void Solve(){  
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll sum = accumulate(all(a), 0ll);
    if(sum % 2 == 0){
        cout << 0 << endl;
        return;
    }
    int res = 1e9;
    rep(i, 1, n){
        int cnt = 0;
        if(a[i] & 1){
            while(a[i] & 1){
                a[i] >>= 1;
                cnt ++;
            }
        }else{
            while(a[i] && a[i] % 2 == 0){
                a[i] >>= 1;
                cnt ++;
            }
        }
        res = min(res, cnt);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}