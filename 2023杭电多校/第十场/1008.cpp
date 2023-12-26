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
    vector<int> a((1 << n)-1);
    for(auto &x:a) cin >> x;
    sort(a.begin(), a.end());
    ll c = 0, x = 1;
    vector<int> res, ls;
    while(c < siz(a)){
        res.push_back(a[c]);
        c += x;
        x *= 2;
    }
    for(int i = 1;i < (1 << n);i ++){
        int sum = 0;
        for(int j = 0;j < n;j ++){
            if(i >> j & 1) sum ^= res[j];
        }
        ls.push_back(sum);
    }
    sort(ls.begin(), ls.end());
    if(ls != a){
        cout << -1 << endl;
        return;
    }
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