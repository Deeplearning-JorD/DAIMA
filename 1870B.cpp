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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    int mb = 0, nm = 0;
    rep(i, 1, n) mb ^= a[i];
    rep(i, 1, m) nm |= b[i];
    int l = mb, r = mb;
    m ++;
    b.push_back(nm);
    for(int i = 1;i <= m;i ++){
        int now = 0;
        for(int j = 30;j >= 0;j --){
            if((b[i] >> j & 1) & 1){
                if(n & 1) now += 1 << j;
            }else{
                now += ((mb >> j & 1)?1:0) << j;
            }
        }
        l = min(l, now);
        r = max(r, now);
    }
    cout << l << ' ' << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}