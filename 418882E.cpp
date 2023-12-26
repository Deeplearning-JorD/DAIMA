/*
 * @Author: JorD
 * @LastEditTime: 2023-01-02 18:43:47
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
const int N = 1e5 + 10;
int a[N];
void Solve(){
    int n;
    scanf("%d", &n);
    rep(i, 1, n){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    rep(i, 1, n){
        if(a[i] & 1){
            if(i > 1 && a[i - 1] == a[i] - 1){
                puts("Yes");
                return;
            }
        }else{
            if(i < n && a[i + 1] == a[i] + 1){
                puts("Yes");
                return;
            }
        }
    }
    puts("No");
    return;
}
int main(){
    int t; scanf("%d",&t); while(t --)
    Solve();
    return 0;
}