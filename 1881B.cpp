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
    vector<int> d(3);
    for(auto &x:d) cin >> x;
    sort(d.begin(), d.end());
    int a, b, c;
    int a1, b1, c1;
    rep(i, 0, 3){
        bool can = true;
        a1 = d[0] % (i + 1);
        a = d[0] / (i + 1);
        rep(j, 0, 3){
            b1 = d[1] % (j + 1);
            b = d[1] / (j + 1);
            rep(k, 0, 3){
                c1 = d[2] % (k + 1);
                c = d[2] / (k + 1);
                if(!a1 && !b1 && !c1 && i + j + k <= 3 && a == b && b == c){
                    cout << "YES\n";
                    return;
                }
            }
        }
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