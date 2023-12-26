/*
 * @Author: JorD
 * @LastEditTime: 2022-12-17 19:18:36
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
    string s;
    int n;
    cin >> n;
    cin >> s;
    s = ' ' + s;
    int res = 0;
    for(int i = 1;i <= n;i ++){
        int j = i;
        if(s[i] == 'R'){
            for(;j <= n;j ++){
                if(s[j] == 'L') break;
            }
            if(j <= n && s[j] == 'L' && (j - i + 1) % 2 == 1){
                res ++;
            }
            for(int k = i;k <= j;k ++) s[k] = '0';
            i = j;
        }
    }
    for(int i = n;i >= 1;i --){
        if(s[i] == '0') continue;
        if(s[i] == 'L')
        for(int j = i;j >= 1;j --){
            s[j] = '0';
        }
    }
    for(int i = 1;i <= n;i ++){
        if(s[i] == '.') res ++;
    }
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