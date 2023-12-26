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
    ll n, s1, s2;
    cin >> n >> s1 >> s2;
    ll l = s1, r = s2;
    vector<int> id(n + 1), a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        id[i] = i;
    }
    sort(id.begin() + 1, id.end(), [&](int x, int y){
        return a[x] > a[y];
    });
    vector<int> res1, res2;
    for(int i = 1;i <= n;i ++){
        if(l > r){
            r += s2;
            res2.push_back(id[i]);
        }else{
            l += s1;
            res1.push_back(id[i]);
        }
    }
    cout << res1.size() << ' ';
    for(auto x:res1) cout << x << ' ';
    cout << endl;
    cout << res2.size() << ' ';
    for(auto x:res2) cout << x << ' ';
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