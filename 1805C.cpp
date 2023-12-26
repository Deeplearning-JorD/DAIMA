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
    vector<ll> line(n + 1);
    rep(i, 1, n) cin >> line[i];
    line[0] = -2e18;
    line.push_back(2e18);
    sort(all(line));
    rep(i, 1, m){
        ll a, b, c;
        cin >> a >> b >> c;
        ll date = 4 * a * c;
        ll l = 0, r = n + 1;
        while(l < r){
            ll mid = l + r >> 1;
            if(line[mid] >= b) r = mid;
            else l = mid + 1;
        }
        if(l != 0 && l != n + 1 && (b - line[l]) * (b - line[l]) < date){
            cout << "YES\n";
            cout << line[l] << endl;
            continue;
        }
        l = 0, r = n + 1;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(line[mid] <= b) l = mid;
            else r = mid - 1;
        }
        if(l != 0 && l != n + 1 && (b - line[l]) * (b - line[l]) < date){
            cout << "YES\n";
            cout << line[l] << endl;
            continue;
        }
        cout << "NO\n";
    }
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