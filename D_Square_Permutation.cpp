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
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(10);
    for(auto x:s) cnt[x - '0'] ++;
    int res = 0;
    for(ll i = 0;i <= 10000000;i ++){
        ll now = i * i;
        vector<int> use(10);
        bool can = true;
        for(int j = 1;j <= n;j ++){
            int x = now % 10;
            use[x] ++;
            if(use[x] > cnt[x]) can = false;
            now /= 10;
        }
        if(now) can = false;
        if(can) res ++;
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}