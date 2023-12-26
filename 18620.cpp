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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cnt(m, vector<int> (26));
    rep(i, 1, n){
        string s; cin >> s;
        for(int j = 0;j < m;j ++){
            cnt[j][s[j]-'a'] = 1;
        }
    }
    string mb = "vika";
    int idx = 0;
    for(int i = 0;i < m;i ++){
        if(cnt[i][mb[idx]-'a']){
            idx ++;
        }
        if(idx == 4){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}