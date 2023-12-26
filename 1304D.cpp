/*
 * @Author: JorD
 * @LastEditTime: 2023-05-01 02:21:37
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
    s = "  " + s;
    vector<int> res(n + 1);
    for(int i = 1, j = n;i <= n;j --, i ++) res[i] = j;
    for(int i = 2;i <= n;i ++){
        if(s[i] == '>') continue;
        int j = i - 1;
        while(i <= n && s[i] == '<') i ++;
        reverse(res.begin() + j, res.begin() + i);
        i --;
    }
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;    
    for(int i = 1;i <= n;i ++) res[i] = i;
    for(int i = 2;i <= n;i ++){
        if(s[i] == '<') continue;
        int j = i - 1;
        while(i <= n && s[i] == '>') i ++;
        reverse(res.begin()  + j, res.begin() + i);
        i --;
    }
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}