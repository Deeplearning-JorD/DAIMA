/*
 * @Author: JorD
 * @LastEditTime: 2022-12-12 23:15:00
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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void Solve(){
    int n;
    cin >> n;
    vector<vector<char>> f(2, vector<char> (n + 1));
    vector<vector<bool>> st(2, vector<bool> (n + 1));
    rep(i, 0, 1) rep(j ,1, n) cin >> f[i][j];
    int last = 2, dist = 0;
    rep(j, 1, n){
        if(f[0][j] == 'B' && f[1][j] == 'B'){
            continue;
        }else if(f[0][j] == 'B'){
            if((j - dist - 1) % 2 == 0){
                if(last == -1){
                    cout << "NO\n";
                    return;
                }
                if(last == 1){
                    cout << "NO\n";
                    return;
                } 
            }else{
                if(last == -1){
                    cout << "NO\n";
                    return;
                }
                if(last == 0){
                    cout << "NO\n";
                    return;
                } 
            }
            last = 0;
            dist = j;
        }else if(f[1][j] == 'B'){
            if((j - dist - 1) % 2 == 0){
                if(last == -1){
                    cout << "NO\n";
                    return;
                }
                if(last == 0){
                    cout << "NO\n";
                    return;
                } 
            }else{
                if(last == -1){
                    cout << "NO\n";
                    return;
                }
                if(last == 1){
                    cout << "NO\n";
                    return;
                } 
            }
            last = 1;
            dist = j;
        }else{
            if(last == 2) continue;
            last = -1;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}