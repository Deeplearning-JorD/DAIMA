/*
 * @Author: JorD
 * @LastEditTime: 2023-01-26 11:15:45
 */
#include <iostream>
using namespace std;
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void ask(int x){
    cout << "- " << x << endl;
}
void out(int x){
    cout << "! " << x << endl;
}
void Solve(){
    int cnt; cin >> cnt;
    int res = 0, now = 1, last = 0;
    int t = cnt;
    while(t){
        ask(now);
        int x; cin >> x;
        x = x - t + 1;
        res += 1 << x;
        now = 1 << x;
        t --;
    }
    out(res);
    return;
}
int main(){
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}