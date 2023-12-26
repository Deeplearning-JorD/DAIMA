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
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
ll a[N];
void Solve(){
    int n;
    cin >> n;
    ll now = 0;
    int idx = 1;
    int l = 1, r = n;
    vector<int> res;
    while(l < r){
        a[l] = idx ++;
        a[r] = idx ++;
        l ++, r --;
    }
    if(l == r) a[l] = idx;
    rep(i, 1, n) res.push_back(a[i]);
    per(j, n - 1, 1){
        rep(i, 1, j){
            a[i] += a[i + 1];
            a[i] %= mod;
        }
    }
    cout << a[1] << endl;
    for(auto x:res) cout << x << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}