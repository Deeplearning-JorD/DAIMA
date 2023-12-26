/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 00:33:57
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
int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,1,-1};
void Solve(){
    int n;
    cin >> n;
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    int x, y;
    cin >> x >> y;
    int sx, sy;
    vector<pair<int,int>> now;
    now.push_back({r1,c1});
    now.push_back({r2,c2});
    now.push_back({r3,c3});
    for(auto u:now){
        int idx = 0;
        for(auto uu:now){
            idx += abs(u.first - uu.first) + abs(u.second - uu.second);
        }
        if(idx == 2){
            r1 = u.first;
            c1 = u.second;
            break;
        }
    }
    if((r1 == 1&&c1 == 1)||(r1 == n&&c1 == 1)||(r1 == 1&&c1 == n)||(r1 == n&&c1 == n)){
        for(auto u:now){
            int nowx = abs(x - u.first);
            int nowy = abs(y - u.second);
            if(!nowx&&!nowy){
                cout << "YES\n";
                return;
            }
        }
        int nowx = abs(x - r1);
        int nowy = abs(y - c1);
        if((!nowx&&nowy)||(nowx&&!nowy)) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    rep(i, 0, 3){
        int ex = r1 + dx[i], ey = c1 + dy[i];
        if(ex>=1&&ex<=n&&ey<=n&&ey>=1){
            sx = ex;
            sy = ey;
            break;
        }
    }
    int nowx = abs(x - sx);
    int nowy = abs(y - sy);
    if(((nowx % 2 == 0)&&(nowy % 2 == 0))) cout << "NO\n";
    else cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}