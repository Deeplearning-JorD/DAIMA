/*
 * @Author: JorD
 * @LastEditTime: 2023-03-11 14:14:30
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
    int Ae, Be, Ce, Ar, Br, Cr;
    cin >> Ae >> Be >> Ce >> Ar >> Br >> Cr;
    vector<int> D(4);
    auto f = [&](double a, double b, double c, double x, double y){
        if(b){
            double k = - 1.0 * a / b, bb = - 1.0 * c / b;
            double Y = k * x + bb;
            return Y >= y;
        }
        else{
            double k = - 1.0 * b / a, bb = - 1.0 * c / a;
            double Y = k * y + bb;
            return Y >= x;
        }
    };
    while(n --){
        int x, y;
        cin >> x >> y;
        int l = f(Ae, Be, Ce, x, y), r = f(Ar, Br, Cr, x, y);
        if(l == 0){
            if(r == 1) D[1] ++;
            else D[0] ++;
        }else{
            if(r == 1) D[3] ++;
            else D[2] ++;
        }
    }
    sort(all(D));
    for(auto x:D) cout << x << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}