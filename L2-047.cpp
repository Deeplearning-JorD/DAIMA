/*
 * @Author: JorD
 * @LastEditTime: 2023-04-24 19:30:51
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
const int N = 2e5 + 10;
int w[N << 2], f[N << 2];
int k;
int pos[N << 2];
void Solve(){
    cin >> k;
    rep(i, 1, k){
        int idx = 1 << (k - i);
        for(int j = 1;j <= 1 << (k - i);j ++){
            cin >> f[idx ++];
        }
    }
    cin >> w[0];
    for(int i = 1 << k, j = 1 << k;j >= 1;j --,i ++){
        pos[i] = i;
    }
    for(int i = 1;i <= k;i ++){
        for(int idx = 1, j = 1 << (k - i);idx <= 1 << (k - i);idx ++, j ++){
            int l = j << 1, r = j << 1|1;
            if(w[0] < f[1]){
                cout << "No Solution\n";
                exit(0);
            }
            if(f[j] > w[l]){
                w[pos[l]] = f[j];
                w[j] = max(f[j], w[r]);
                pos[j] = pos[r];
                continue;
            }
            if(f[j] >= w[r]){
                w[pos[r]] = f[j];
                w[j] = max(f[j], w[l]);
                pos[j] = pos[l];
                continue;
            }
            cout << "No Solution";
            exit(0);
        }
    }
    for(int i = 1 << k, j = 1 << k;j >= 1;j --,i ++){
        if(!w[i]) w[i] = w[0];
        cout << w[i] << " \n"[j == 1];
    }
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}