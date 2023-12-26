/*
 * @Author: JorD
 * @LastEditTime: 2023-04-30 13:58:41
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
const int N = 5e6 + 10;
int idx;
bool st[N];
ll p[N];
void is_prime(ll x){
    for(ll i=2;i<=x;i++){
        if(!st[i]) p[idx++]=i;
        for(ll j=0;p[j]<=x/i;j++){
            /*1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
            2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子*/
            st[p[j]*i]=true;
            //这句话保证了i*p[j]的最小质因子都是p[j]
            if(i%p[j]==0) break;   //p[j]一定是i的最小质因子
        }
    }
}
void Solve(){
    is_prime(1e6 + 1000);
    ll n;
    cin >> n;
    ll res = 0;
    for(int i = 0;i < idx && p[i] <= sqrt(n / (p[i] * p[i]));i ++){
        ll now = p[i] * p[i];
        for(int j = i + 1;j < idx && (__int128)(p[i] * p[i] * p[j] * p[j] * p[j]) <= n;j ++){
            if(j >= idx) break;
            int l = j, r = idx;
            ll xz = n / now;
            xz /= p[j];
            while(l < r){
                ll mid = l + r + 1 >> 1;
                if(p[mid] * p[mid] <= xz) l = mid;
                else r = mid - 1;
            }
            res += l - j;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}