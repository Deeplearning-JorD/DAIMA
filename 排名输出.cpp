/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 13:23:39
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 1e5 + 10;
struct node{
    int AC, T, id;
}stu[N];
int rak[N];
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        cin >> stu[i].AC >> stu[i].T;
        stu[i].id = i;
    }
    sort(stu + 1, stu + 1 + n, [&](node a, node b){
        if(a.AC == b.AC) return a.T < b.T;
        return a.AC > b.AC;
    });
    int last = 1, rk = 1;
    stu[0] = stu[1];
    for(int i = 1;i <= n;i ++){
        if(stu[i].AC == stu[i - 1].AC&&stu[i].T == stu[i - 1].T){
            rak[stu[i].id] = last;
        }else{
            rak[stu[i].id] = rk;
            last = rk;
        }
        rk ++;
    }
    int t;  cin >> t;
    while(t --){
        int id;
        cin >> id;
        cout << rak[id] << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}