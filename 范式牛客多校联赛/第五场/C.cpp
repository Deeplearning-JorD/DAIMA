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
vector<int> son[6010];
void Solve(){
    int n; cin >> n;
    vector<int> cnt(2 * n + 1);
    rep(i, 1, n){
        int x = 0;
        for(int j = n + 1;j <= 2 * n;j ++){
            int w; cin >> w;
            x |= w;
            cnt[j] += w; 
        }
        cnt[i] += x;
    }
    int l = 0, r = 0;
    rep(i, 1, n) l += cnt[i] > 0?1:0;
    rep(i, n + 1, n + n) r += cnt[i] > 0?1:0;
    cout << l << ' ' << r << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}