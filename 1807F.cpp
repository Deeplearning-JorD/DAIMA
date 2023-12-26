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
map<string, int> mp;
void Solve(){
    int n, m, i1, j1, i2, j2;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    string s;
    cin >> s;
    int x = i1, y = j1;
    ll idx = 0;
    ll res = -1;
    int d = mp[s];
    auto jj = [&](int x, int y){
        return x * y > 0;
    };
    vector<vector<vector<bool>>> st(n + 1, vector<vector<bool>> (m + 1, vector<bool> (5)));
    do{
        if(x == i2 && y == j2){
            res = idx;
            break;
        }
        if(d == 1){
            ll l = 0, r = n * m;
            while(l < r){
                ll mid = l + r >> 1;
                if(x + mid >= n || y + mid >= m) r = mid;
                else l = mid + 1;
            }
            int sx = i2 - x, sy = j2 - y;
            ll lastx = x, lasty = y;
            x += l;
            y += l;
            if((- lasty + y) * sx == sy * (- lastx + x) && jj(sx, - lastx + x) && jj(sy, - lasty + y)){
                res = idx;
                break;
            }
            if(st[x][y][d]) break;
            st[x][y][d] = 1;
            if(x == n && y == m){
                d = 4;
            }else{
                if(x == n) d = 3;
                else d = 2;
            }
        }else if(d == 2){
            ll l = 0, r = n * m;
            while(l < r){
                ll mid = l + r >> 1;
                if(x + mid >= n || y - mid <= 1) r = mid;
                else l = mid + 1;
            }
            int sx = i2 - x, sy = j2 - y;
            ll lastx = x, lasty = y;
            x += l;
            y -= l;
            cout << lasty - y << endl;
            if((y - lasty) * sx == sy * (- lastx + x) && jj(sx, - lastx + x) && jj(sy, - lasty + y)){
                res = idx;
                break;
            }
            if(st[x][y][d]) break;
            st[x][y][d] = 1;
            if(x == n && y == 1){
                d = 3;
            }else{
                if(x == n) d = 4;
                else d = 1;
            }
        }else if(d == 3){
            ll l = 0, r = n * m;
            while(l < r){
                ll mid = l + r >> 1;
                if(x - mid <= 1 || y + mid >= m) r = mid;
                else l = mid + 1;
            }
            ll sx = i2 - x, sy = j2 - y;
            ll lastx = x, lasty = y;
            x -= l;
            y += l;
            if((- lasty + y) * sx == sy * (- lastx + x) && jj(sx, - lastx + x) && jj(sy, - lasty + y)){
                res = idx;
                break;
            }
            if(st[x][y][d]) break;
            st[x][y][d] = 1;
            if(x == 1 && y == m){
                d = 2;
            }else{
                if(x == 1) d = 1;
                else d = 4;
            }
        }else{
            ll l = 0, r = n * m;
            while(l < r){
                ll mid = l + r >> 1;
                if(x - mid <= 1 || y - mid <= 1) r = mid;
                else l = mid + 1;
            }
            int sx = i2 - x, sy = j2 - y;
            ll lastx = x, lasty = y;
            x -= l;
            y -= l;
            if((- lasty + y) * sx == sy * (- lastx + x) && jj(sx, - lastx + x) && jj(sy, - lasty + y)){
                res = idx;
                break;
            }
            if(st[x][y][d]) break;
            st[x][y][d] = 1;
            if(x == 1 && y == 1){
                d = 1;
            }else{
                if(x == 1) d = 2;
                else d = 3;
            }
        }
        if(x == i2 && y == j2){
            res = idx;
            break;
        }
        idx ++;
    }while(1);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    mp["DR"] = 1;
    mp["DL"] = 2;
    mp["UR"] = 3;
    mp["UL"] = 4;
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}