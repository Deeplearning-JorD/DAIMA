/*
 * @Author: JorD
 * @LastEditTime: 2023-04-28 16:51:24
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
const int N = 15;
int n, m;
vector<string> son[N];
bool st[N];
int res;
vector<int> v;
void dfs(int depth){
    if(depth <= 0){
        int now = 0;
        map<string, int> q;
        for(auto i:v){
            int sum = 0;
            for(auto x:son[i]){
                int can = min(50 - q[x], 114 - sum);
                sum += can;
                now += can;
                q[x] += can;
            }
        }
        res = max(res, now);
        return;
    }
    rep(i, 1, n)if(!st[i]){
        st[i] = 1;
        v.push_back(i);
        dfs(depth - 1);
        v.pop_back();
        st[i] = 0;
    }
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n){
        int t;
        cin >> t;
        while(t --){
            string s; 
            cin >> s;
            son[i].push_back(s);
        }
        sort(son[i].begin(), son[i].end());
    }
    dfs(m);
    cout << res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}