/*
 * @Author: JorD
 * @LastEditTime: 2022-11-22 22:15:38
 */
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
    string s;
    cin >> s;
    s = ' ' + s;
    int cnt = 0;
    vector<int> son;
    rep(i, 1, n){
        if(s[i] == '2'){
            son.push_back(i);
        }
    }
    vector<vector<char>> f(n + 1, vector<char>(n + 1, '='));
    if(!son.empty()&&son.size() < 3){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int m = son.size();
    rep(i, 0, m - 1){
        f[son[i]][son[(i + 1)%m]] = '+';
        f[son[(i + 1)%m]][son[i]] = '-';
    }
    rep(i, 1, n){
        rep(j, 1, n)
            if(i == j) cout << "X";
            else cout << f[i][j];
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}