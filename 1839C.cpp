/*
 * @Author: JorD
 * @LastEditTime: 2023-06-04 17:04:53
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
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    if(a[n]){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int i = 1;
    vector<int> res;
    while(i <= n){
        int j = i;
        while(j <= n && a[j] == 1) j ++;
        res.push_back(j - i);
        rep(k, 1, j - i){
            res.push_back(0);
        }
        i = j + 1;
    }
    reverse(res.begin(), res.end());
    for(auto x:res) cout << x << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}