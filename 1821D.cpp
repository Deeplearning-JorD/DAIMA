/*
 * @Author: JorD
 * @LastEditTime: 2023-04-20 23:37:28
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
    ll n, k;
    cin >> n >> k;
    vector<ll> L(n + 1), R(n + 1);
    rep(i, 1, n) cin >> L[i];
    rep(i, 1, n) cin >> R[i];
    ll res = 0, sum = 0, now = 2e18, cnt = 0;
    for(int i = 1;i <= n;i ++){
        int l = L[i], r = R[i];
        if(r - l + 1 >= 2){
            res += 2;
            sum += r - l + 1;
            if(sum >= k){
                ll z = l, y = r;
                sum -= r - l + 1;
                while(z < y){
                    ll mid = z + y >> 1;
                    if(sum + mid - l + 1 >= k) y = mid;
                    else z = mid + 1;
                }
                now = min(now, res + y);
                sum += r - l + 1;
            }else{
                if(sum + cnt >= k){
                    ll ji = k - sum;
                    now = min(now, ji * 2 + res + r);
                }
            }
        }else{
            cnt += 1;
            if(sum + cnt >= k){
                ll ji = max(k - sum, 0ll);
                now = min(now, ji * 2 + r + res);
            }
        }
    }
    if(now == 2e18) now = -1;
    cout << now << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}