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
const int N = 2e6 + 10;
ll jw[N];
void Solve(){
    ll n, m;
    cin >> n >> m;
    memset(jw, 0, sizeof jw); 
    rep(i, 1, n){
        ll x;
        cin >> x;
        jw[x] ++; 
    }
    rep(i, 1, m){
        // cout << i << ' ' << jw[i] << endl; 
        jw[i + 1] += jw[i] / (1 + i);
        jw[i] %= i + 1;
        // cout << i << ' ' << jw[i] << endl; 
    }
    rep(i, 1, m - 1){
        // cout << i << ' ' << jw[i] << endl; 
        if(jw[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}