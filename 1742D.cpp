/*
 * @Author: JorD
 * @LastEditTime: 2022-10-13 22:55:15
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
const int N = 1010;
bool st[N][N];
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
vector<int> son[N];
void Solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    vector<bool> vis(1001);
    map<int,int> q;
    rep(i, 1, n){
        int x;
        cin >> x;
        vis[x] = 1;
        q[x] = i;
    }
    for(auto [x, y]:q){
        a.push_back({y, x});
    }
    int res = -1;
    for(auto [x, y]:a){
        for(auto u:son[y]){
            if(vis[u]){
                res = max(res, x + q[u]);
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(i, 1, 1000){
        rep(j, 1, 1000){
            if(gcd(i, j) == 1){
                son[i].push_back(j);
            }
        }
    }
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}