/*
 * @Author: JorD
 * @LastEditTime: 2023-01-07 20:37:27
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
int idx;
bool st[10000004];
int p[10000004];
void is_prime(){
    int x = 4e6;
    for(int i=2;i<=x;i++){
        if(!st[i]) p[idx++]=i;
        for(int j=0;p[j]<=x/i;j++){
            /*1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
            2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子*/
            st[p[j]*i]=true;
            //这句话保证了i*p[j]的最小质因子都是p[j]
            if(i%p[j]==0) break;   //p[j]一定是i的最小质因子
        }
    }
}
bool prime(ll x){
    if(x<2) return false;
    for(ll i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
void Solve(){
    ll x;
    cin >> x;
    for(int i = 0;i < idx;i ++){
        ll j = p[i];
        if(x % j == 0){
            x /= j;
            if(x % j == 0){
                x /= j;
                if(j == x){
                    x *= j;
                    x *= j;
                    continue;
                }
                cout << j << ' ' << x << endl;
            }else{
                ll now = sqrt(x);
                if(now == j || now * now != x){
                    x *= j;
                    continue;
                }
                cout << now << ' ' << j << endl;
            }
            return;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    is_prime();
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}