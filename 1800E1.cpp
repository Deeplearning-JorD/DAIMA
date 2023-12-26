/*
 * @Author: JorD
 * @LastEditTime: 2023-03-03 00:45:29
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
const int N = 2e5 + 10;
int f[N], ff[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> idx(n + 1, vector<int> (26));
    vector<vector<int>> cnt(n + 1, vector<int> (26));
    string s, t;
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 0;i <= n;i ++){
        f[i] = i;
    }
    for(int i = 1;i <= n;i ++){
        if(i + k <= n){
            f[find(i)] = find(i + k);
        }
        if(i + k + 1 <= n){
            f[find(i)] = find(i + k + 1);
        }
    }
    set<int> se;
    for(int i = 1;i <= n;i ++){
        int now = find(i);
        idx[now][s[i] - 'a'] ++; 
        cnt[now][t[i] - 'a'] ++;
        se.insert(now);
    }
    bool flag = true;
    for(auto x:se){
        for(int i = 0;i < 26;i ++){
            if(idx[x][i] != cnt[x][i]){
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
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}