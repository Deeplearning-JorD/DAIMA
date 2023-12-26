/*
 * @Author: JorD
 * @LastEditTime: 2023-03-27 19:51:46
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), c(n + 1), d(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        c[i] = a[i] - a[i - 1];
    }
    vector<ll> pre(k + 1),pre1(k + 1);
    rep(i, 1, n){
        pre[i % k] += c[i];
        pre1[i % k] += d[i];
    }
    for(int i = 1;i <= min(n, k);i ++){
        for(int j = i;j <= n;j += k){
            c[j] = 0;
        }
        c[i] = pre[i % k];
    }
    for(int i = 1;i <= min(n, k);i ++){
        for(int j = i;j <= n;j += k){
            if(j + k <= n) d[j] = 0;
            else d[j] = pre[i % k];    
        }
    }
    
    rep(i, 1, n) cout << c[i] << ' ';
    cout << endl;
    rep(i, 1, n) cout << d[i] << ' ';
    cout << endl;
    rep(i, 1, n) c[i] += c[i - 1];
    map<int,int> q;
    int mx;
    rep(i, 1, n){
        q[c[i]] ++;
        if(q[c[i]] > q[mx]) mx = c[i];
    }
    rep(i, 1, n) d[i] += d[i - 1];
    map<int,int> qq;
    int mxx;
    rep(i, 1, n){
        qq[d[i]] ++;
        if(qq[d[i]] > qq[mxx]) mxx = d[i];
    }
    int res = 0, ans = 0;
    rep(i, 1, n){
        res += c[i] != mx;
    }
    rep(i, 1, n){
        ans += d[i] != mxx;
    }
    rep(i, 1, n) cout << c[i] << ' ';
    cout << endl;
    rep(i, 1, n) cout << d[i] << ' ';
    cout << endl;
    cout << min(ans, res) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}