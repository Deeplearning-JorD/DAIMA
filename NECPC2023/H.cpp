/*
 * @Author: JorD
 **  O(1)你也超时？
 * @LastEditTime: 2023-05-19 15:57:56
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
const double sq = sqrt(2);
inline double calc(double d, double r){
    return 1.0 * d / (r * r);
}
void Solve(){
    double n, k, d;
    scanf("%lf%lf%lf", &n, &k, &d);
    if(k == 1){
        printf("%.6lf\n", calc(d, n / 2));
        return;
    }
    double up = sq * n;
    double down = 1 + (k - 1) * sq;
    double x = up / down;
    double res = calc(2 * d, x / 2);
    printf("%.6lf\n", res);
    return;
}
int main(){
    int t; scanf("%d",&t); while(t --)
    Solve();
    return 0;
}