/*
 * @Author: JorD
 * @LastEditTime: 2022-08-13 20:07:36
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
const int N=20;
int f[N][N];
void Solve(){
    int x,y;
    cin>>x>>y;
    if(f[x][y]) cout<<"black";
    else cout<<"white";
    return;
}
void ranse(int x,int y){
    for(int i=x;i<=16-y;i++) f[x][i]=1,f[16-x][i]=1,f[i][y]=1,f[i][16-y]=1;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    for(int i=1;i<=15;i+=2){
        ranse(i,i);
    }
    // rep(i,1,15){
    //     rep(j,1,15)if(f[i][j]) cout<<0;else cout<<' ';
    //     cout<<endl;
    // }
    Solve();
    return 0;
}