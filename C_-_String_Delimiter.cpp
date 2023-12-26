/*
 * @Author: JorD
 * @LastEditTime: 2022-12-17 20:11:39
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<bool> st(n + 1);
    for(int i = 1;i <= n;i ++){
        int j = i + 1;
        if(st[i]) continue;
        if(s[i] == '"'){
            st[i] = true;
            for(;j <= n;j ++){
                st[j] = true;
                if(s[j] == '"') break;
            }
            i = j;
        }
    }
    rep(i, 1, n){
        if(s[i] == ',' && !st[i]) s[i] = '.';
    }
    rep(i, 1, n) cout << s[i];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}