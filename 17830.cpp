/*
 * @Author: JorD
 * @LastEditTime: 2023-01-08 22:40:08
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
    sort(a.begin() + 1, a.end());
    int last = 0;
    int l = 1, r = n;
    vector<int> res(n + 1);
    rep(i, 1, n){
        if(a[r] == last){
            res[i] = a[l ++];
        }else{
            res[i] = a[r --];
        }
        last = res[i];
    }
    ll sum = 0;
    rep(i, 1, n){
        if(sum == res[i]){
            cout << "NO\n";
            return;
        }
        sum += res[i];
    }
    cout << "YES\n";
    rep(i, 1, n) cout << res[i] << ' ';
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