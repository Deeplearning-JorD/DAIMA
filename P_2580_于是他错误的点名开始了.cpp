/*
 * @0uthor: JorD
 * @LastEditTime: 2023-01-25 13:46:47
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
const int N = 5e5 + 10;
int tr[N][30];
int cnt[N];
void Solve(){
    int n, m;
    cin >> n;
    int idx = 0;
    rep(i, 1, n){
        string s; cin >> s;
        int p = 0;
        for(auto x:s){
            int c = x - 'a';
            if(!tr[p][c]) tr[p][c] = ++ idx;
            p = tr[p][c];
        }
        cnt[p] = -1;
    }
    cin >> m;
    rep(i, 1, m){
        string s; cin >> s;
        int p = 0;
        string res = "WRONG";
        for(int i = 0;i < s.size();i ++){
            char x = s[i];
            int c = x - 'a';
            if(!tr[p][c]){
                break;
            }
            if(i == siz(s) - 1){
                if(cnt[tr[p][c]] == -1){
                    res = "OK";
                    cnt[tr[p][c]] = 1;
                }else if(cnt[tr[p][c]]) res = "REPEAT";
                else res = "WRONG";
            }
            p = tr[p][c];
        }
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}