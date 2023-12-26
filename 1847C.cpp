/*
 * @Author: JorD
 * @LastEditTime: 2023-07-06 23:18:45
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
    int res = 0;
    vector<int> pre(n + 1);
    vector<bool> st(1 << 8);
    st[0] = 1;
    rep(i, 1, n){
        int x; cin >> x;
        pre[i] = pre[i - 1] ^ x;
        st[pre[i]] = 1;
    }
    for(int mb = 0;mb < (1 << 8);mb ++){
        rep(i, 1, n){
            if(st[mb ^ pre[i]]){
                res = mb;
                break;
            }
        }
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