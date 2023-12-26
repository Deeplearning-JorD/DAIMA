/*
 * @Author: JorD
 * @LastEditTime: 2023-03-17 18:06:34
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
const int N = 5e5 + 10, M = 5050;
string mb;
int tr1[N][26], tr[N][26], idx, cnt;
int A[N], B[N];
int dp[M][2];
void build(string &s){
    int p = 0;
    for(int i = 0;i < s.size();i ++){
        int c = s[i] - 'a';
        if(!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
    }
    A[p] ++;
}
void build1(string &s)  {
    int p = 0;
    for(int i = 0;i < s.size();i ++){
        int c = s[i] - 'a';
        if(!tr1[p][c]) tr1[p][c] = ++ cnt;
        p = tr1[p][c];
    }
    B[p] ++;
}
bool st = false;
int len, now;
void find(int i, int p, int up){
    if(i == 0) return;
    int c = mb[i] - 'a';
    if(tr[p][c]){
        if(A[tr[p][c]]) dp[up][0] = min(dp[up][0], dp[i - 1][1] + 1);
        find(i - 1, tr[p][c], up);
    }
    return;
}
void find1(int i, int p, int up){
    if(i == 0) return;
    int c = mb[i] - 'a';
    if(tr1[p][c]){
        if(B[tr1[p][c]]) dp[up][1] = min(dp[up][1], dp[i - 1][0] + 1);
        find1(i - 1, tr1[p][c], up);
    }
    return;
}
void Solve(){
    int n, m;
    cin >> n;
    rep(i, 1, n){
        string s; cin >> s;
        reverse(all(s));
        build(s);
    }
    cin >> m;
    rep(i, 1, m){
        string s; cin >> s;
        reverse(all(s));
        build1(s);
    }
    cin >> mb;
    len = mb.size();
    mb = ' ' + mb;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1;i <= len;i ++){
        find(i, 0, i); find1(i, 0, i);
    }
    ll res = min(dp[len][0], dp[len][1]);
    if(res == 0x3f3f3f3f) res = -1;
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}