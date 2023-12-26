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
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> mi, mx;
    mi.push_back(0);
    mx.push_back(1e9);
    for(int i = 2;i <= n;i ++){
        auto x = a[i - 1], y = a[i];
        if(x < y){
            ll mid = x + y >> 1;
            mx.push_back(mid);
        }else if(x > y){
            ll mid = x + y + 1 >> 1;
            mi.push_back(mid);
        }
    }
    sort(all(mi));
    reverse(all(mi));
    sort(all(mx));
    if(*mi.begin() > *mx.begin()){
        cout << -1 << endl;
        return;
    }
    cout << *mx.begin() << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}