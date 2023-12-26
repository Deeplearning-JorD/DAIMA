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
    cin >> n;
    map<char,int> q;
    rep(i, 1, n){
        char c; cin >> c;
        q[c] ++;
    }
    cin >> m;
    ll tot = 0;
    rep(i, 1, m){
        string s; cin >> s;
        for(auto x:s){
            if(x == 'O'){
                tot ++;
                continue;
            }
            q[x] --;
        }
    }
    for(auto [x, y]:q){
        if(y < 0){
            cout << "NO\n";
            return;
        }
        tot -= y;
    }
    if(!tot) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}