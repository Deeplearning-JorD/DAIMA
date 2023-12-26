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
    vector<vector<int>> son(k);
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        son[i % k].push_back(a[i]);
    }
    rep(i, 0, k - 1) sort(son[i].begin(), son[i].end());
    vector<int> b(n + 1);
    rep(i, 0, k - 1){
        int j = i;
        if(i == 0) j = k;
        for(auto x:son[i]){
            b[j] = x;
            j += k;
        }
    }
    auto c = b;
    sort(c.begin() + 1, c.end());
    if(c == b){
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> ne(k);
    rep(i, 1, n){
        ne[i % k].push_back(c[i]);
    }
    int cnt = 0;
    rep(i, 0, k - 1){
        set<int> s;
        for(int j = 0;j < son[i].size();j ++){
            s.insert(ne[i][j]);
            s.insert(son[i][j]);
        }
        cnt += siz(s) - siz(son[i]);
    }
    if(cnt == 2){
        cout << 1 << endl;
        return;
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}