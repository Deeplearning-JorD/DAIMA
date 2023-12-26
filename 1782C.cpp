/*
 * @Author: JorD
 * @LastEditTime: 2023-01-15 22:35:53
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
const int N = 1e5 + 10;
int wu;
bool st[N];
int p[N];
int dist[N];
void is_prime(){
    int x = 1e5;
    for(int i=2;i<=x;i++){
        if(!st[i]) p[wu++]=i;
        for(int j=0;p[j]<=x/i;j++){
            /*1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
            2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子*/
            st[p[j]*i]=true;
            //这句话保证了i*p[j]的最小质因子都是p[j]
            if(i%p[j]==0) break;   //p[j]一定是i的最小质因子
        }
    }
}
void Solve(){
    int n;
    cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    vector<vector<int>> son(26);
    vector<pair<int,int>> js(26);
    rep(i, 0, 26) js[i].first = i;
    // set<char> sett;
    rep(i, 1, n){
        son[s[i] - 'a'].push_back(i);
        js[s[i] - 'a'].second ++;
        // sett.insert(s[i]);
    }
    sort(js.begin(), js.end(), [](pair<int,int> a,pair<int,int> b){
        return a.second > b.second; 
    });
    string res = s;
    int mx = 1e9;
    int id = 0;
    for(int o = 1;o <= 26;o ++){
        if(n % o) continue;
        // cout <<"<<<<<<<<<<<<<<<<<<\n" << o << endl;
        vector<int> use(26, - 1);
        int lim = n / o;
        int w = 0, idx = 0;
        auto ss = s;
        queue<pair<char,int>> qq;
        int up = 0, down = 0;
        for(int i = 0;i < 26;i ++){
            auto &a = son[js[i].first];
            int len = js[i].second;
            if(!len) continue;
            idx ++;
            if(idx > o) break;
            int ii = js[i].first;
            use[ii] = 0;
            char c = (char)(ii + 'a');
            if(len < lim){
                // use[ii] = lim - len;
                down += lim - len;
                // cout << "use:" << use[ii] << endl;
            }else{
                up += len - lim;
            }        
        }
        // cout << idx <<  "idx\n";
        w = up + down;
        rep(i, idx + 1, 25){
            w += js[i].second;
        }
        
        if(mx > w){
            mx = w;
            id = o;
        }
    }
    int lim = n / id;
    vector<int> use(26, - 1);
    queue<pair<char,int>> qq;
    for(int i = 0;i < id;i ++){
        auto &a = son[js[i].first];
        auto [j, len] = js[i];
        if(!len) continue;
        int c = (char)('a' + j);
        if(len > lim){
            int now = 0;
            for(auto x:a){
                if(now == lim){
                    qq.push({c, x});
                    // cout << x << "x\n";
                    continue;
                }
                now ++;
            }
        }else{
            use[j] += lim - len;
        }
    }
    for(int i = id;i < 26;i ++){
        auto [j, len] = js[i];
        auto& a = son[j];
        int c = (char)('a' + j);
        for(auto x:a){
            qq.push({c, x});
        }
    }
    for(int i = 0;i < 26;i ++){
        auto [j, len] = js[i];
        auto &a = son[j];
        if(use[j] <= 0) continue;
        while(use[j] --){
            auto [y, yy] = qq.front(); qq.pop();
            s[yy] = (char)('a' + j);
        }
    }
    // if(idx < o){
        //     w = up + down;
        //     for(int i = 0;i < 26;i ++){
        //         if(qq.empty()) break;
        //         char c = (char)('a' + i);
        //         rep(jj, 1, use[i]){
        //             auto [L, R] = qq.front(); qq.pop();
        //             ss[R] = c; 
        //         }
        //     }
        //     for(int i = 0;i < 26;i ++){
        //         if(qq.empty()) break;
        //         if(use[i] == 0) continue;
        //         char c = (char)('a' + i);
        //         rep(jj, 1, use[i]){
        //             auto [L, R] = qq.front(); qq.pop();
        //             ss[R] = c; 
        //         }
        //     }
        // }else w = 2 * down - up;
    cout << mx << endl;
    rep(i, 1, n) cout << s[i];
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}