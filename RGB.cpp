/*
 * @Author: JorD
 * @LastEditTime: 2023-03-22 18:08:14
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
const int N = 2e5 + 10, mod = 1e9 + 7;
vector<int> st;
vector<int> v;
int n;
int calc(){
    int now = 1;
    int res = 0;
    for(auto x:v){
        res += x * now;
        now *= 3;
    }
    return res;
}
void dfs(int i){
    if(i == n){
        st.push_back(calc());
        return;
    }
    if(v.size()){
        int x = v.back();
        for(auto y:{0,1,2}){
            if(x == y) continue;
            v.push_back(y);
            dfs(i + 1);
            v.pop_back();
        }
    }else{
        for(auto y:{0,1,2}){;
            v.push_back(y);
            dfs(i + 1);
            v.pop_back();
        }
    }
}
bool check(int x, int y){
    for(int i = 0;i < n;i ++){
        int l = x % 3, r = y % 3;
        if(l == r) return false;
        x /= 3;
        y /= 3;
    }
    return true;
}
int js[N];
int idx; 
vector<vector<int>> son;
int tot;
void judge(int now){
    js[now] = idx ++;
    vector<int> ls;
    for(auto x:st){
        if(!check(x, now)) continue;
        ls.push_back(x);
    }
    tot += ls.size();
    son.push_back(ls);
}
void Solve(){
    int m;
    cin >> n >> m;
    dfs(0);
    for(auto x:st){
        judge(x);
    }
    vector<vector<int>> dp(2, vector<int> (idx + 1));
    rep(i, 0, idx - 1) dp[1][i]=1;
    for(int i = 2;i <= m;i ++){
        for(int j = 0;j < idx;j ++)
        for(auto x:son[j]){
            dp[i&1][j] += dp[(i + 1) & 1][js[x]];
            dp[i&1][j] %= mod;
        }
        for(int j = 0;j < idx;j ++)
        dp[(i + 1) & 1][j] = 0;
    }
    int res = 0;
    rep(i, 0, idx - 1) res = (res + dp[m&1][i]) % mod;
    cout << res << endl;
    cout << tot << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}