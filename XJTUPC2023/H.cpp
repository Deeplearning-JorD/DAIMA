/*
 * @Author: JorD
 * @LastEditTime: 2023-05-07 20:48:59
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
    vector<vector<int>> cnt(n + 1, vector<int> (26));
    set<char> res;
    rep(i, 1, n){
        string s;
        cin >> s;
        for(auto x:s){
            cnt[i][x - 'a'] ++;
            res.insert(x);
        }
    }
    char c;
    bool st = true;
    for(int i = 0;i < 26;i ++){
        int sum = 0;
        c = (char)('a' + i);
        int last = 0;
        set<int> s;
        for(int j = 1;j <= n;j ++)
            s.insert(cnt[j][i]);
        if(s.size() == n){
            cout << "YES\n";
            res.erase(c);
            for(auto x:res) cout << x;
            cout << c;
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}