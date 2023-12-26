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
vector<char> stk, c;
vector<double> v;
vector<pair<double, double>> ck;
double sx, sy;
double calc(){
    int idx = stk.size();
    idx --;
    double sum = 0;
    while(idx >= 0){
        if(stk[idx] == 'x'){
            v.push_back(sx);
        }else{
            c.push_back(stk[idx]);
        }
        while(1){
            if(!c.size()) break;
            auto now = c.back();
            if(now == '+'){
                if(v.size() >= 2){
                    double x = v.back();
                    v.pop_back();
                    double y = v.back();
                    v.pop_back();
                    v.push_back(x + y);
                }else break;
            }else if(now == '-'){
                if(v.size() >= 2){
                    double x = v.back();
                    v.pop_back();
                    double y = v.back();
                    v.pop_back();
                    v.push_back(y - x);
                }else break;
            }else if(now == '*'){
                if(v.size() >= 2){
                    double x = v.back();
                    v.pop_back();
                    double y = v.back();
                    v.pop_back();
                    v.push_back(x * y);
                }else break;
            }else if(now == '/'){
                if(v.size() >= 2){
                    double x = v.back();
                    v.pop_back();
                    double y = v.back();
                    v.pop_back();
                    v.push_back(y / x);
                }else break;
            }else if(now == 's'){
                if(v.size() >= 1){
                    double x = v.back();
                    v.pop_back();
                    v.push_back(sin(x));
                }else break;
            }else if(now == 'c'){
                if(v.size() >= 1){
                    double x = v.back();
                    v.pop_back();
                    v.push_back(cos(x));
                }else break;
            }
        }
    }
    double x = v.back(); v.pop_back();
    return x;
}
bool check(){
    for(auto [xx, yy]:ck){
        sx = xx, sy = yy;
        if(fabs(calc() - sy) > 1e-5) return false;
    }
    return true;
}
int id;
void out(){
    id--;
    cout << '(';
    auto x = stk[id];
    if(x == 'x'){
        cout << x;
        return;
    }else if(x == 's' || x == 'c'){
        if(x == 's'){
            cout << "sin";
        }else cout << "cos";
        cout << "(";
        out();
        cout << ")";
    }else{
        out();
        cout << x;
        out();
    }
    cout << ')';
}
void dfs(int cnt, int dep){
    if(dep < 0 || cnt <= 0){
        return;
    }
    if(dep == 0 && cnt == 1){
        if(check()){
            id = siz(stk);
            out();
            exit(0);
        }
        return;
    }
    
    stk.push_back('x');
    dfs(cnt + 1, dep - 2);
    stk.pop_back();

    stk.push_back('s');
    dfs(cnt, dep - 1);
    stk.pop_back();
 
    stk.push_back('c');
    dfs(cnt, dep - 1);
    stk.pop_back();

    stk.push_back('+');
    dfs(cnt - 1, dep);
    stk.pop_back();

    stk.push_back('-');
    dfs(cnt - 1, dep);
    stk.pop_back();

    stk.push_back('*');
    dfs(cnt - 1, dep);
    stk.pop_back();

    stk.push_back('/');
    dfs(cnt - 1, dep);
    stk.pop_back();
}
void Solve(){
    stk.push_back('x');
    int n; cin >> n;
    rep(i, 1, n){
        double x, y;
        cin >> x >> y;
        ck.push_back({x, y});
    }
    dfs(1,1);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}