/*
 * @Author: JorD
 * @LastEditTime: 2022-10-16 22:39:16
 */
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
    vector<int> a(n + 1);
    vector<vector<int>> son(51);
    rep(i, 1, n){
        cin >> a[i];
        son[a[i]].push_back(i);
    }
    string s;
    cin >> s;
    s = ' ' + s;
    rep(i, 1, 50){
        if(son[i].empty()) continue;
        char mb = s[son[i][0]];
        for(auto x:son[i]){
            if(s[x] != mb){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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