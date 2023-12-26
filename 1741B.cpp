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
    if(n%2 == 0){
        per(i, n, 1) cout << i << " ";
        cout << endl;
        return;
    }
    if(n <= 3){
        cout << -1 << endl;
        return;
    }
    int idx = 1;
    vector<int> res(n + 1);
    rep(i, n/2+1, n){
        res[i] = idx;
        idx ++;
    }
    rep(i, 1, n/2) res[i] = idx ++;
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}