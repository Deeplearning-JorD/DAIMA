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
    int n, a, q;
    cin >> n >> a >> q;
    string s; cin >> s;
    int mx = a, cnt = 0;
    for(auto x:s){
        if(a == n){
            cout << "YES\n";
            return;
        }
        if(x == '+') a ++, cnt ++;
        else a --;
    }
    if(a == n){
        cout << "YES\n";
        return;
    }
    if(mx + cnt >= n){
        cout << "MAYBE\n";
        return;
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}