#include<bits/stdc++.h>
using namespace std;

namespace geo_3d{
const double eps=1e-9, INF=1e9, PI=3.14159265358979323846;
struct V{  //向量及其运算是几何基础，点也可以用向量表示
    double x, y, z;
    V():x(0),y(0),z(0){}
    V(const V &a){ *this=a; }
    V(const double &a, const double &b, const double &c):x(a),y(b),z(c){}
    void read(){ scanf("%lf%lf%lf", &x, &y, &z); }
    void print(){ printf("%.9lf %.9lf %.9lf\n", x, y, z); }  //位数多精度高
    void print_space(){ printf("%.9lf %.9lf %.9lf ", x, y, z); }
    void print_int(){ printf("%d %d %d\n", (int)x, (int)y, (int)z); }
}O;  //三个vector参数abc表示以a为顶点的角bac/cab

//三种定义方式 一种read()读取 三种输出

inline double sqr(const double &x){return x*x;}
inline bool zero(const double &x){return abs(x)<eps;}
//科学的方式验证  double 一般不会等于0
inline bool zero(const V &p){return zero(p.x)&&zero(p.y)&&zero(p.z);}
//三个点都是 0 向量才是0
inline bool equal(const double &a, const double &b){ return zero(a-b); }
inline bool less(const double &a, const double &b){ return a<b-eps; }
inline bool greater(const double &a, const double &b){ return a>b+eps; }
inline bool cmp1(const V &a, const V &b){ return a.x<b.x; }
inline bool cmp2(const V &a, const V &b){ return a.y<b.y; }
inline bool cmp3(const V &a, const V &b){ return a.z<b.z; }
inline V operator+(const V &a, const V &b){ return V(a.x+b.x, a.y+b.y, a.z+b.z); }
inline V operator-(const V &a, const V &b){ return V(a.x-b.x, a.y-b.y, a.z-b.z); }
inline V operator*(const double &x, const V &a){ return V(a.x*x, a.y*x, a.z*x); }
inline V operator*(const V &a, const double &x){ return V(a.x*x, a.y*x, a.z*x); }
//两种点乘
inline V operator/(const V &a, const double &x){ return V(a.x/x, a.y/x, a.z/x); }
inline bool operator==(const V &a, const V &b){ return equal(a.x, b.x)&&equal(a.y, b.y)&&equal(a.x, b.z);}
//三维都相等
inline bool operator!=(const V &a, const V &b){ return !(a==b); }
inline double operator*(const V &a, const V &b){ return a.x*b.x+a.y*b.y+a.z*b.z; }
//叉乘
inline V operator^(const V &a, const V &b){
    return V(a.y*b.z-b.y*a.z, b.x*a.z-a.x*b.z, a.x*b.y-b.x*a.y);
}
//这是叉积 得到新的向量
inline double len(const V &a){ return sqrt(a.x*a.x+a.y*a.y+a.z*a.z); }
//长度
inline double dis(const V &a, const V &b){ return len(a-b); }
//向量间的距离
inline V mid(const V &a, const V &b){ return V((a.x+b.x)/2, (a.y+b.y)/2, (a.z+b.z)/2); }
inline V unit(const V &a){ return a/len(a); }


}