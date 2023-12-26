/*
 * @Author: JorD
 * @Date: 2023-12-18 22:47:41
 * @LastEditTime: 2023-12-18 22:56:28
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
ll cnt[31];
void Solve(){   
    int op, x; cin >> op >> x;
    if(op == 1){
        cnt[x] ++;
        return;
    }
    ll can = 0;
    for(int i = 0;i <= 30;i ++){
        can += cnt[i];
        if(x >> i & 1){
            if(can >= 1){
                can --;
            }else{
                cout << "NO\n";
                return;
            }  
        }
        can /= 2;
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}