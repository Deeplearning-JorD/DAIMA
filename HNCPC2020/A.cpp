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
    vector<vector<pair<int,int>>> v(m + 1);
    rep(i, 1, n){
        int a, b;
        cin >> a >> b;
        v[a].push_back({b, i});
    }
    rep(i, 1, m){
        sort(v[i].begin(), v[i].end(), [](pair<int,int> a, pair<int,int> b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        cout << (*v[i].begin()).second << ' ';
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}