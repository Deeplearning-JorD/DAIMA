/*
 * @Author: JorD
 * @LastEditTime: 2022-12-12 02:37:23
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
bool st[1000004];
int p[10000004];
void is_prime(){
    int x = 1e6;
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
void Solve(){
    int n;
    cin >> n;
    map<int,int> q;
    string res = "NO";
    auto prime = [&](int x){
        for(int i = 0;i < idx;i ++){
            int j = p[i];
            if(j > x / j)
            if(x % j == 0){
                if(q[j]) res = "YES";
                q[j] = 1;
                while(x % j == 0) x /= j;
            }
        }
        if(x > 1){
            if(q[x]) res = "YES";
            q[x] ++;
        }
    };
    rep(i, 1, n){
        int x; cin >> x;
        prime(x);
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