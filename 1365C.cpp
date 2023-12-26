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
    vector<int> id(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        id[x] = i;
    }
    vector<int> cnt(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        if(i >= id[x]){
            cnt[i - id[x]] ++;
        }else{
            cnt[n - (id[x] - i)] ++;
        }
    }
    int res = 0;
    rep(i, 0, n) res = max(res, cnt[i]);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}