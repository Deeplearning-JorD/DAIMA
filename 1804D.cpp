/*
 * @Author: JorD
 * @LastEditTime: 2023-03-13 21:02:44
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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    vector<int> L(n + 1), R(n + 1);
    int resl = 0, resr = 0;
    rep(i, 1, n){
        vector<int> st(m + 1);
        int js = 0;
        st[0] = 1;
        for(int j = 1;j <= m;j ++){
            if(f[i][j] == '0') continue;
            if(f[i][j] == '1' && !st[j - 1] && f[i][j - 1] == '1'){
                st[j] = st[j - 1] = 1;
                js ++;
                L[i] ++;
            }
            if(js == m / 4) break;
        }
        [1 2 3 0] [1 2 3 0] 1 2 3 0
        now  % n = n - ?
        (now + ?) % n = now % n + ? % n = 0
        now % n 
         1 + 2 * pre ) % n
        for(int j = 1;j <= m;j ++){
            if(!st[j] && f[i][j] == '1') L[i] ++;
        }
        resl += L[i];
    }
    rep(i, 1, n){
        vector<int> st(m + 1);
        st[0] = 1;
        int tot = 0;
        for(int j = 1;j <= m;j ++){
            tot += f[i][j] == '1';
        }
        int idx = 0, cnt = 0;
        for(int j = 1;j <= m;j ++){
            if(st[j - 1]) continue;
            if(!(f[i][j] == '1' && f[i][j - 1] == '1')){
                idx ++;
                st[j] = st[j - 1] = 1;
                cnt += (f[i][j] == '1') | (f[i][j - 1] == '1');
                if(idx > m / 4) break;
            }
        }
        if(idx >= m / 4){
            resr += tot;
            continue;
        }
        for(int j = 1;j <= m;j ++){
            if(st[j] || st[j - 1]) continue;
            if((f[i][j] == '1' && f[i][j - 1] == '1')){
                idx ++;
                st[j] = st[j - 1] = 1;
                cnt ++;
            }
            if(idx == m / 4) break;
        }
        for(int j = 1;j <= m;j ++){
            if(!st[j]) cnt += f[i][j] == '1';
        }   
        resr += cnt;
    }
    cout << resl << ' ' << resr << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}