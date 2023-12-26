/*
 * @Author: JorD
 * @LastEditTime: 2023-03-27 12:55:21
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
    ll mx = *max_element(a.begin() + 1, a.end()) - *min_element(a.begin() + 1, a.end());
    sort(a.begin() + 1, a.end());
    int l = 1, r = n;
    vector<ll> res(n + 1);
    ll now = 0;
    if(a == vector<int> (n + 1, 0)){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    rep(i, 1, n){
        if(now <= 0){
            now += a[r];
            cout << a[r --] << ' ';
        }else{
            now += a[l];
            cout << a[l ++] << ' ';
        }
    }
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