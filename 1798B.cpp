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
    vector<vector<int>> a(n + 1);
    rep(i, 1, n){
        int m;
        cin >> m;
        a[i].resize(m + 1);
        rep(j, 1, m){
            cin >> a[i][j];
        }
        a[i][0] = m;
    }
    vector<vector<int>> res(n + 1);
    set<int> s;
    vector<int> id(n + 1);
    per(i, n, 1){
        for(int j = 1;j <= a[i][0];j ++){
            if(!s.count(a[i][j])){
                res[i].push_back(a[i][j]);
            }
            s.insert(a[i][j]);
        }
        id[i] = i;
    }
    sort(id.begin() + 1, id.end(), [&](int a, int b){
        return res[a].size() < res[b].size();
    });
    vector<int> ans(n + 1, -1);
    set<int> ss;
    for(int i = 1;i <= n;i ++){
        for(auto x:res[id[i]]){
            if(ss.count(x)) continue;
            ss.insert(x);
            ans[id[i]] = x;
            break;
        }
    }
    rep(i, 1, n) if(ans[i] == -1){
        cout << -1 << endl;
        return;
    }
    rep(i, 1, n) cout << ans[i] << ' ';
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