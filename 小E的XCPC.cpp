/*
 * @Author: JorD
 * @LastEditTime: 2022-12-03 12:24:29
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
    int res = 0;
    int mx = 0;
    per(i, n, 1){
        if(a[i] == 1) res += 20;
        else if(a[i] == 2) res += 60;
        else continue;
        if(res <= 300) mx ++;
        else break;
    }
    int sum = 0;
    res = 0;
    rep(i, 1, n){
        if(a[i] == 1) res += 20;
        else if(a[i] == 2) res += 60;
        else continue;
        if(res <= 300) sum ++;
        else break;
    }
    cout << max(mx, sum) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}