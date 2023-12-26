/*
 * @Author: JorD
 * @LastEditTime: 2023-02-04 21:38:52
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
    int n, m, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    vector<ll> pre(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        if(i - k >= 0) pre[i] = pre[i - k] + a[i];
        else pre[i] += a[i];
    }
    cin >> m;
    while(m --){
        int l, r; cin >> l >> r;
        set<int> s;
        for(int i = r - k + 1;i <= r;i ++){
            ll x = pre[i];
            ll L = 0, R = n;
            while(L < R){
                ll mid = L + R  >> 1;
                if(i - k * mid < l){
                    R = mid;
                }
                else L = mid + 1; 
            }
            if(i - k * (L) >= 0) x -= pre[i - k * (L)];
            s.insert(x);
        }
        if(s.size() == 1) cout << "Yes\n";
        else cout << "No\n";
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}