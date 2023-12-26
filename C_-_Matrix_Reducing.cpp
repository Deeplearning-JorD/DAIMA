/*
 * @Author: JorD
 * @LastEditTime: 2022-08-13 20:26:58
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
int f[N][N],g[N][N];
void Solve(){
    int n,m;
    cin>>n>>m;
    rep(i,0,n-1)rep(j,0,m-1) cin>>f[i][j];
    int nn,mm;
    cin>>nn>>mm;
    rep(i,0,nn-1)rep(j,0,mm-1) cin>>g[i][j];
    for(int ii=0;ii<1<<n;ii++){
        for(int jj=0;jj<1<<m;jj++){
            int l, r;
            l=r=-1;
            int js=0;
            for(int i=0;i<n;i++){
                if((1<<i)&ii) l++;
                else continue;
                r=-1;
                for(int j=0;j<m;j++){
                    if((1<<j)&jj) r++;
                    else continue;
                    if(g[l][r]==f[i][j])js++;
                }
            }
            if(js==nn*mm){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}
