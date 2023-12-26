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
    int mx = 0;
    for(int i = 0;i < 31;i ++){
        if(n >> i & 1) mx = i;
    }
    vector<int> res;
    for(int i = 1,j = 0;j <= mx;j ++, i <<= 1){
        res.push_back(i);
    }
    int now = 1 << mx;
    for(int i = mx - 1;i >= 0;i --){
        if(n >> i & 1){
            now |= 1 << i;
            res.push_back(now);
        }
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
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