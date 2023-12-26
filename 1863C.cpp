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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    set<int> s;
    rep(i, 0, n) s.insert(i);
    rep(i, 1, n){
        cin >> a[i];
        s.erase(a[i]);
    }
    a[0] = *s.begin();
    n ++;
    int idx = ((n - k - 1) % n + n) % n;
    vector<int> res;
    for(int i = 1, j = idx;i < n;i ++, j --){
        if(j < 0) j = n - 1;
        res.push_back(a[j]);
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