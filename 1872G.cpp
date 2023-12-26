/*
 * @Author: JorD
 * @LastEditTime: 2023-09-08 23:38:19
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int l = 1, r = n;
    while(l <= n && a[l] == 1) l ++;
    while(r >= 1 && a[r] == 1) r --;
    if(l > r){
        cout << 1 << ' ' << 1 << endl;
        return;
    } 
    vector<ll> pre(n + 1), mul(n + 1);
    mul[0] = 1;
    vector<int> pos;
    rep(i, 1, n){
        pre[i] = pre[i - 1] + a[i];
        mul[i] = mul[i - 1] * a[i];
        if(a[i] > 1) pos.push_back(i);
        if(mul[i] > 1e9){
            cout << l << ' ' << r << endl;
            return;
        }
    }
    ll ansl = 1, ansr = 1, mx = 0;
    for(int i = 0;i < pos.size();i ++){
        for(int j = i + 1;j < pos.size();j ++){
            int l = pos[i], r = pos[j];
            if(mul[r] / mul[l - 1] - pre[r] + pre[l - 1] > mx){
                mx = mul[r] / mul[l - 1] - pre[r] + pre[l - 1];
                ansl = l, ansr = r;
            }
        }
    }
    cout << ansl << ' ' << ansr << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}