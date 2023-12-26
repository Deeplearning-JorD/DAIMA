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
    cin >> n >> m;
    map<int, vector<int> > mp;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = x;
        mp[x].push_back(0);
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        if (a[x] == y) continue;
        mp[a[x]].push_back(i);
        a[x] = y;
        mp[a[x]].push_back(i);
    }
    ll ans = 0;
    for(auto &[x, v] : mp){
        ans += 1LL * (m + 1) * m / 2;
        if (v.size() % 2 == 1) v.push_back(m + 1);
        int last = 0, len = 0;
        for(int i = 0; i < v.size(); i += 2){
            len += v[i] - last;
            last = v[i + 1];
        }
        len += m - last + 1;
        cout << x << ' ' << len << endl;
        ans -= 1LL * len * (len - 1) / 2;
    }
    cout << ans << '\n';
return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}