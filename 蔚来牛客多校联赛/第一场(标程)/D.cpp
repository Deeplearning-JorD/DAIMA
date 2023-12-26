#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
const double pi=acos(-1.0L);
#define pb push_back
#define eps 1e-11
int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
double cmp(double a,double b){return sgn(a-b);}
double sqr(double x){return x*x;}
double inmid(double x,double l,double r){return sgn(x-l)>=0&&sgn(r-x)>=0;}
struct Point{
    double x,y;
    Point(){}
    Point(double xx,double yy){x=xx;y=yy;}
    void input(){scanf("%Lf %Lf",&x,&y);}
    void output(){printf("%.0f %.0f\n",x,y);}
    bool operator ==(const Point &p)const{return sgn(x-p.x)==0&&sgn(y-p.y)==0;}
    bool operator !=(const Point &p)const{return sgn(x-p.x)!=0||sgn(y-p.y)!=0;}
    bool operator < (const Point &p)const{
        return sgn(x-p.x)<0||(sgn(x-p.x)==0&&sgn(y-p.y)<0);
    }
    Point operator + (const Point &p)const{
        return {x+p.x,y+p.y};
    }
    Point operator - (const Point &p)const{
        return {x-p.x,y-p.y};
    }
    Point operator * (double k)const{
        return {x*k,y*k};
    }
    Point operator / (const double &k)const{
        return {x/k,y/k};
    }
    double dot(Point p) const{return p.x*x+p.y*y;}
    double cross(Point p) const {return x * p.y - y * p.x;}
     double dis(Point p) const {return sqrt(sqr(x - p.x) + sqr(y - p.y));}
    double abs() const{return hypot(x,y);}
    double abs2() const{return sqr(x)+sqr(y);}
    double rad(Point a,Point b)const{
        Point k1=a-(*this),k2=b-(*this);
        return atan2l(k1.cross(k2), k1.dot(k2));
    }
};
inline int read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}
int main(){
    
        
    int t=read();
    while(t--){
        Point ini={0,0};
        double r=read();
        Point q;
        q.x=read();q.y=read();
        double d=read();
        double x=q.dis(ini);
        double lx=x-d,rx=x+d;
        double ly=sqrt(r*r-lx*lx),ry=sqrt(r*r-rx*rx);
        Point lp={lx,ly},rp={rx,ry};
        double rad=fabs(ini.rad(lp,rp));
        rad*=r;
        printf("%.21Lf\n",rad);
    }
}