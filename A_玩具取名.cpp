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
const int N = 210;
int dp[N][N][10];
//dp[i][j][k]表示i-j这一段能不能变成k
int st[10][10][10];
string ch;
map<char,int> mp;
int dfs(int l, int r, int sk){
    if(dp[l][r][sk] != -1) return dp[l][r][sk];
    if(l == r){
        return dp[l][r][sk] = sk == mp[ch[l]];
    }
    if(l + 1 == r)
        return dp[l][r][sk] = st[mp[ch[l]]][mp[ch[r]]][sk];
    dp[l][r][sk] = 0;
    for(int i = l;i < r;i ++){
        for(int j = 1;j <= 4;j ++)
            for(int k = 1;k <= 4;k ++){
                int a = dfs(l, i, j), b = dfs(i + 1, r, k);
                if(a) a = j;
                else a = 0;
                if(b) b = k;
                else b = 0;
                dp[l][r][sk] |= st[a][b][sk];   
            }
    }
    return dp[l][r][sk];
}
void Solve(){
    int W, I, N, G;
    cin >> W >> I >> N >> G;
    rep(i, 1, W){
        string s; cin >> s;
        st[mp[s[0]]][mp[s[1]]][1] = 1;
    }  
    rep(i, 1, I){
        string s; cin >> s;
        st[mp[s[0]]][mp[s[1]]][2] = 1;
    }
    rep(i, 1, N){
        string s; cin >> s;
        st[mp[s[0]]][mp[s[1]]][3] = 1;
    }
    rep(i, 1, G){
        string s; cin >> s;
        st[mp[s[0]]][mp[s[1]]][4] = 1;
    }
    cin >> ch;
    memset(dp, -1, sizeof dp);
    int n = ch.size();
    ch = ' ' + ch;
    vector<char> res;
    if(dfs(1, n, 1)) res.push_back('W');
    if(dfs(1, n, 2)) res.push_back('I');
    if(dfs(1, n, 3)) res.push_back('N');
    if(dfs(1, n, 4)) res.push_back('G');
    for(auto x:res) cout << x;
    if(res.empty()) cout << "The name is wrong!";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    mp['W'] = 1;
    mp['I'] = 2;
    mp['N'] = 3; 
    mp['G'] = 4;
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}