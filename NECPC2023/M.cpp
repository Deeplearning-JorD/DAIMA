/*
 * @Author: JorD
 * @LastEditTime: 2023-05-19 14:38:09
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
const int N = 1e7 + 10;
bool isp[N];
int p[664589];
int ans[N];
int pl=0;
void init(){
    for(int i=2;i<N;i++){
        if(!isp[i]){
            p[pl++]=i;
            ans[i]=ans[i-1]+1;
        }else if(!isp[i-2]||i%2==0){
            ans[i]=ans[i-1]+2;
        }else
            ans[i]=ans[i-1]+3;
        for(int j=0;j<pl&&p[j]*i<N;j++){
            isp[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
void Solve(){
    int n;cin>>n;
    cout<<ans[n]<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}