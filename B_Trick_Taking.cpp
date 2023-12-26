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
    int n, k;
    cin >> n >> k;
    map<int, vector<pair<int,int>>> q;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    int mx = 0, res = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(mx < x){
            mx =x;
            res = i;
        }
        q[a[i]].push_back({x,i});
    }
    if(!q[k].size())
        k = a[1];
    sort(q[k].begin(), q[k].end(), [](pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    });
    cout << q[k][0].second;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}