/*
 * @Author: JorD
 * @Date: 2023-11-07 18:11:46
 * @LastEditTime: 2023-11-08 14:13:49
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
int m;
struct node{
    char op;
    int a, b;
};
void Solve(){
    int n, tot; 
    scanf("%d %d",&n,&tot);
    vector<array<int,3>> w;
    vector<node> v(m + 1);  
    rep(i, 1, m){
        string s; cin >> s;
        char c = s[0];
        v[i].op = c;
        if(c == '.') continue;
        else if(c == '-'){
            int x; scanf("%d", &x);
            v[i].a = x;
            continue;
        }else if(c == '+'){
            int a, b;
            scanf("%d/%d",&a,&b);
            n --;
            tot -= b + 20 * (a - 1);
            v[i].a = a;
            v[i].b = b;
        }else if(c == '?'){
            int a, b; scanf("%d%d", &a, &b);
            w.push_back({i, a, b});
            v[i].a = a;
            v[i].b = b;
        }
    }
    // for(int i = 1;i <= m;i ++){
    //     cout << i << ' ';
    //     cout << v[i].op << ' ' << v[i].a << ' ' << v[i].b << endl;
    // }
    if(tot < 0){
        cout << "No\n";
        return;
    }
    int len = w.size();
    for(int i = 0;i < (1 << len);i ++){
        ll tot2 = tot;
        int down = 0, up = 0, mx = 0;
        int sv = 0;
        for(int j = 0;j < len;j ++)if(i >> j & 1){
            auto [id, x, y] = w[j];
            down += 240 + 20 * (y - x);
            mx += x - 1;
            up += 299 + 20 * (y - 1);
            sv ++;
        }
        if(sv != n) continue;
        // cout << i << ' ' << down << ' ' << up << ' ' << tot << endl;
        if(tot < down || tot > up) continue;
        tot -= down;
        int need = min(mx, tot / 20);
        tot -= need * 20;
        vector<array<int, 3>> ls;
        for(int j = 0;j < len;j ++)if(i >> j & 1){
            auto [id, x, y] = w[j];
            int now = min(need, x - 1);
            need -= now;
            int now1 = min(tot, 59);
            tot -= now1;
            ls.push_back({id, now + y - x + 1, 240 + now1});
        }
        // if(need == 0 && tot == 0){
            cout << "Yes\n";
            for(auto [id, x, y] : ls){
                v[id].a = x;
                v[id].b = y;
                v[id].op = '+';
            }
            for(int j = 1;j <= m;j ++){
                if(v[j].op == '?') cout << "- " << v[j].b << endl;
                else if(v[j].op == '.'){
                    cout << v[j].op << endl;
                }else if(v[j].op == '-') cout << "- " << v[j].a << endl;
                else cout << v[j].op << ' ' << v[j].a << '/' << v[j].b << endl;
            }
            return;
        // }
        // tot = tot2;
    }
    cout << "No\n";
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    int t; scanf("%d%d",&t,&m); while(t --)
    Solve();
    return 0;
}