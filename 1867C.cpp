#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
// #define endl '\n'
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
    vector<int> a(n + 10);
    rep(i, 1, n){
        int x; cin >> x;
        if(x <= n) a[x] = 1;
    }
    int id = -1;
    rep(i, 0, n){
        if(i) a[i] += a[i - 1];
        if(a[i] == i + 1) id = i;
    }
    int last = id + 1;
    while(1){
        cout << last << endl;
        int k; cin >> k;
        if(k < 0) break;
        last = k;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}