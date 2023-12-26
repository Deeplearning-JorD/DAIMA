/*
 * @Author: JorD
 * @LastEditTime: 2023-05-23 21:18:25
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
const int N = 1e6 + 10;
int mx[23][N];
int mi[23][N];
int lg[N];
inline int find1(int l, int r){
    int mid = lg[r - l + 1];
    return max(mx[mid][l], mx[mid][r - (1 << mid) + 1]);
}
inline int find0(int l, int r){
    int mid = lg[r - l + 1];
    return min(mi[mid][l], mi[mid][r - (1 << mid) + 1]);
}
void Solve(){
    int n; scanf("%d",&n);
    lg[1] = 0, lg[2] = 1;
    for(int i = 3;i <= n;i ++){
        lg[i] = lg[i / 2] + 1;
    }
    int x;
    rep(i, 1, n){
        scanf("%d",&x);
        mx[0][i] = x;
        mi[0][i] = x;
    }
    for(int k = 1;1<<k <= n;k ++){
        for(int i = 1;i + (1 << k) - 1 <= n;i ++){
            int j = i + (1 << k - 1);
            mx[k][i] = max(mx[k - 1][i], mx[k - 1][j]);
            mi[k][i] = min(mi[k - 1][i], mi[k - 1][j]);
        }
    }
    int res = 0;
    for(int k = 1;k <= n;k ++){
        int last = 0;
        bool st = true;
        for(int i = 1;i <= n;i += k){
            int j = min(n, i + k - 1);
            if(find0(i, j) < last){
                st = false;
                break;
            }
            last = find1(i, j);
        }
        res += st;
    }
    printf("%d",res);
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    // //int t; cin>>t; while(t --)
    Solve();
    return 0;
}