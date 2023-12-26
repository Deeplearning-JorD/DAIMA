/*
 * @Author: JorD
 * @LastEditTime: 2023-01-29 23:06:45
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
const int N = 6e5 + 10;
int wu;
bool st[N];
int p[N];
int dist[N];
void is_prime(){
    int x = 4e5;
    for(int i=2;i<=x;i++){
        if(!st[i]) p[wu++]=i;
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
    ll n;
    cin >> n;
    ll res = 0;
    map<ll,ll> q;
    for(int i = 0;i < wu;i ++){
        int now = p[i];
        if(now > n / now) break;
        if(n % now == 0){
            int js = 0;
            while(n % now == 0){
                n /= now;
                js ++;
                if(!q[js]) q[js] = now;
                else q[js] *= now;
            }
        }
    }
    if(n > 1){
        if(!q[1]) q[1] = n;
        else q[1] *= n;
    }
    for(auto [x, y]:q){
        res += y;
    }
    cout << res << endl;
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