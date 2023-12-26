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
    int n; cin >> n;
    vector<int> c(n + 1);
    vector<pair<int,int>> a(n + 1), b(n + 1);
    rep(i, 1, n){
        cin >> c[i];
    }
    int idx = n;
    for(int i = 1;i <= n;i ++){
        int l = 1, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(c[mid] >= i) l = mid;
            else r = mid - 1;
        }
        if(c[i] == l) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}