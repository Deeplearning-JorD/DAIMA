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
    for(auto &x:a) cin >> x;
    ll res = 0;
    while(a.size() > 1){
        vector<int> b;
        int m = a.size();
        for(int i = 0;i < a.size();i += 2){
            if(a[i] > a[i + 1]) res ++;
            if(abs(a[i] - a[i + 1]) > 1){
                cout << -1 << endl;
                return;
            }
            b.push_back(min(a[i], a[i + 1]) >> 1);
        }
        swap(a, b);
        b.clear();
    }
    cout << res << endl;
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