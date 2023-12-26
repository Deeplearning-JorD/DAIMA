/*
 * @Author: JorD
 * @LastEditTime: 2022-12-18 00:21:27
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
    cin >> n >> m >> k;
    int mx = 0;
    vector<int> v;
    rep(i, 1, m){
        int x; cin >> x;
        mx = max(mx, x);
        v.push_back(x);
    }
    sort(all(v));
    reverse(all(v));
    if(k == 1){
        cout << "YES\n";
        return;
    }
    if(k > m){
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    for(auto &x:v){
        if(x == n / k + 1) cnt ++;
        if(cnt > n % k||x > n / k + 1){
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
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}