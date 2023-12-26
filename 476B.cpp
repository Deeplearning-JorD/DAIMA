/*
 * @Author: JorD
 * @Date: 2023-11-29 23:29:19
 * @LastEditTime: 2023-11-29 23:48:35
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    string s; cin >> s;
    int mb = 0;
    for(auto x:s) if(x == '+') mb ++;
    else mb --;
    cin >> s;
    int now = 0, cnt = 0;
    for(auto x:s){
        if(x == '+') now ++;
        else if(x == '-') now --;
        else cnt ++;
    }
    mb = abs(mb - now);
    if(mb <= cnt && (cnt - mb) % 2 == 0){
        double res = 1;
        mb += (cnt - mb) / 2;
        for(int i = 1;i <= cnt;i ++){
            res *= i;
            res /= 2;
        }
        for(int i = 1;i <= mb;i ++){
            res /= i;
        }
        for(int i = 1;i <= cnt - mb;i ++){
            res /= i;
        }
        cout << SPO(10) << res << endl;
        return;
    }
    cout << 0 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}