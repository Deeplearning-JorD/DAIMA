/*
 * @Author: JorD
 * @Date: 2023-11-28 12:45:41
 * @LastEditTime: 2023-11-28 12:54:40
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
int res;
bool st[1000004];
int p[10000004];
void is_prime(int x){
    for(int i=2;i<=x;i++){
        if(!st[i]) p[res++]=i;
        for(int j=0;p[j]<=x/i;j++){
            /*1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
            2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子*/
            st[p[j]*i]=true;
            //这句话保证了i*p[j]的最小质因子都是p[j]
            if(i%p[j]==0) break;   //p[j]一定是i的最小质因子
        }
    }
}
void Solve(){
    ll x; cin >> x;
    ll c = sqrt(x);
    if(c * c != x){
        cout << "NO\n";
        return;
    }
    if(!st[c] && c != x) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    is_prime(1000000);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}