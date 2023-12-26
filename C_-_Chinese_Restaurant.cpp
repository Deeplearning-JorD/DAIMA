#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    set<int> s;
    auto f = [&](int x,int i){
        if(x < i){
            return i - x;
        }else return n - (x - i);
    };
    map<int, int> q;
    rep(i, 0, n - 1){
        int x = ((a[i] - 1)%n + n)%n;
        int y = a[i];
        int z = (a[i] + 1) % n;
        q[f(x, i)] ++;
        q[f(y, i)] ++;
        q[f(z, i)] ++;
    }
    int res = 0;
    for(auto x:q) res = max(res, x.second);
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}