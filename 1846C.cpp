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
    ll n, m, h;
    cin >> n >> m >> h;
    vector<pair<ll,ll>> v(n + 1);
    vector<ll> id(n + 1);
    rep(i, 1, n){
        vector<ll> ls(m + 1);
        rep(j, 1, m){
            cin >> ls[j];
        }  
        sort(ls.begin() + 1, ls.end());
        ll l = 0, r = 0;
        ll now = 0, tot = 0;
        rep(j, 1, m){
            tot += ls[j];
            now += tot;
            if(tot <= h){
                l = j;
                r = now;
            }
        }
        v[i] = {l, r};
        id[i] = i;
    }
    sort(id.begin() + 1, id.end(), [&](int i, int j){
        if(v[i].first == v[j].first){
            if(v[i].second == v[j].second) return i < j;
            else return v[i].second < v[j].second;
        }else return v[i].first > v[j].first;
    });
    rep(i, 1, n) if(1 == id[i]) cout << i << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}