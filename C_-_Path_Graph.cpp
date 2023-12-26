/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 20:18:08
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
vector<int> son[N];
int d[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    if(n - 1 != m){
        cout << "No";
        return;
    }
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
        d[x] ++, d[y] ++;
    } 
    map<int,int>q;
    int root = -1;
    rep(i, 1, n){
        if(d[i] == 1) root = i;
    }
    if(root == -1){
        cout << "No\n";
        return;
    }
    function<void(int,int)> dfs = [&](int now, int fa){
        d[now] = -1;
        for(auto x:son[now])if(x != fa){
            dfs(x, now);
        }
    };
    dfs(root, 0);
    rep(i, 1, n){
        if(d[i] != -1){
            cout << "No";
            return;
        }
    }cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}