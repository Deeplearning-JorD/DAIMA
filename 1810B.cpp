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
    if(n % 2 == 0){
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    while(n != 1){
        if(((n + 1) / 2) & 1){
            res.push_back(1);
            n = n + 1 >> 1;
        }else{
            res.push_back(2);
            n = n - 1 >> 1;
        }
    }
    cout << res.size() << endl;
    reverse(res.begin(), res.end());
    for(auto x:res) cout << x << ' ';
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