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
const int N = 210;
vector<int> son[N];
bool vis[N];
int n;
int cnt;
bool jiji;
int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a, b);
}
int dist;
void dfs(int now, int k){
    vis[now] = true;
    if(dist > 2*n){
        return;
    }
    if(now == k&&dist){
        cnt = dist;
        return;
    }
    for(auto x:son[now]){
        dist ++;
        dfs(x, k);
    }
}
void Solve(){
    cin >> n;
    rep(i, 1, n){
        int x;
        cin >> x;
        son[i].push_back(x);
    }
    vector<bool> vis(n + 1);
    int flag = false;
    vector<int> res;
    rep(i, 1, n){
        if(vis[i]) continue;
        cnt = 0; jiji = false;
        dist = 0;
        dfs(i, i);
        if(!cnt){
            // cout << i << endl;
            cout << -1 << endl;
            return;
        }
        
        if(cnt == 2) flag = true;
        else res.push_back(cnt);
    }    
    if(!res.size()&&flag){
        cout << 1 << endl;
        return;
    }
    int js = 0;
    for(auto x:res){
        js += x == 1;
    }
    if(js == res.size()&&flag){
        cout << 1 << endl;
        return;
    }
    int ans = res[0];
    rep(i, 1, siz(res) - 1){
        ans = lcm(ans, res[i]);
    }
    cout << ans << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}