#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define int long long
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
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    int last = 0, num = 0;
    int res = 0;
    map<int,int> q;
    rep(i, 1, n){
        int x; cin >> x;
        q[x + w] ++;
    }
    for(auto &[x, y]:q){
        if(x - last > d){
            if(x - w - last <= d){
                int c = min(y, num);
                y -= c;
                num -= c;
            }else num = 0;
        }
        else{
            int c = min(y, num);
            y -= c;
            num -= c;
        }
        if(y){
            int c = (y + k - 1) / k;
            last = x;
            res += c;
            num = c * k - y;
        }
    }
    cout << res << endl;
    return;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}