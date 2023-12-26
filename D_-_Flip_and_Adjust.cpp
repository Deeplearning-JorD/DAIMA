/*
 * @Author: JorD
 * @LastEditTime: 2022-10-01 21:26:28
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
const int N = 10010;
int f[210][N];
void Solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    int sum = 0;
    vector<bool> st(n + 1);
    rep(i, 1, n){
        cin >> a[i] >> b[i];
        c[i] = b[i] - a[i];
        if(c[i] < 0){
            st[i] = true;
            sum += b[i];
            c[i] = -c[i];
        }else{
            sum += a[i];
        }
    }
    int m = s - sum;
    for(int i=n;i>=1;i--)
        for(int j=0;j<=m;j++){
            f[i][j]=f[i+1][j];
            if(j>=c[i]) f[i][j]=max(f[i][j],f[i+1][j-c[i]]+c[i]);
        }
    for(int i=1;i<=n;i++){
        if(m>=c[i]&&f[i][m]==f[i+1][m-c[i]]+c[i]){
            st[i] = !st[i];
            m-=c[i];
        }
    }
    if(f[1][s - sum] == s - sum) cout << "Yes\n";
    else{
        cout << "No\n";
        return;
    }
    rep(i, 1, n) if(!st[i]) cout << "H"; else cout << "T"; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}