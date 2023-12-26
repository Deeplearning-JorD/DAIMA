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
    vector<int> c(n + 1), mi(n + 2, 1e9);
    rep(i, 1, n) cin >> c[i];
    int k; cin >> k;
    per(i, n, 1) mi[i] = min(mi[i + 1], c[i]);
    int last = 1e9;
    mi[0] = 0;
    for(int i = 1;i <= n;i ++){
        int now = mi[i] - mi[i - 1];
        if(now == 0){
            cout << last << ' ';
            continue;
        }
        if(k / now <= last){
            last = k / now;
            k %= now;
        }else last -= now * last;
        cout << last << ' ';
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