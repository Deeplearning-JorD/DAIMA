/*
 * @Author: JorD
 * @LastEditTime: 2022-08-18 22:26:14
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];
    sort(a.begin(), a.end(), [](int a, int b){
        return a > b;
    });
    cout << a[0] + a[1] - a[n-1] - a[n-2] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;

    while(t--)
    Solve();
    return 0;
}