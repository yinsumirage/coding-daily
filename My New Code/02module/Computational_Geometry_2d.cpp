#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//acos����0~pi��asin����-pi/2~pi/2��axxϵ�о��Ȳ��ã�����
namespace geo_2d{
const double eps=1e-9, INF=1e18, PI=3.14159265358979323846;
struct V{  //�������������Ǽ��λ�������Ҳ������������ʾ
    double x, y;
    V():x(0),y(0){}
    V(const V &a){ *this=a; }
    V(const double &a, const double &b):x(a),y(b){}
    void read(){ scanf("%lf%lf", &x, &y); }
    void print(){ printf("%.9lf %.9lf\n", x, y); }  //λ���ྫ�ȸ�
    void print_space(){ printf("%.9lf %.9lf ", x, y); }
    void print_int(){ printf("%d %d\n", (int)x, (int)y); }
}O, corner(-1e6-PI, -1e6-2*PI);  //����vector����abc��ʾ��aΪ����Ľ�bac/cab
int pre(int i, int n){ return i==0?n-1:i-1; }
int nxt(int i, int n){ return i==n-1?0:i+1; }
/*
template <typename Iterator, typename Container>
Iterator pri(Iterator a, Container &S){
    return a==S.begin()?S.end():--a;
}
template <typename Iterator, typename Container>
Iterator nxt(Iterator a, Container &S){
    return ++a==S.end()?S.end():a;
}
*/
inline double sqr(const double &x){ return x*x; }
inline bool zero(const double &x){ return abs(x)<eps; }
inline bool equal(const double &a, const double &b){ return zero(a-b); }
inline bool less(const double &a, const double &b){ return a<b-eps; }  //���ϸ�
inline bool greater(const double &a, const double &b){ return a>b+eps; }
inline bool in(const double &a, const double &b, const double &c){
    if (b<c) return !geo_2d::less(a, b)&&!geo_2d::greater(a, c);
    else return !geo_2d::greater(a, b)&&!geo_2d::less(a, c);
}
inline bool cmp1(const V &a, const V &b){ return a.x<b.x; }
inline bool cmp2(const V &a, const V &b){ return a.y<b.y; }
inline bool cmp3(const V &a, const V &b){ return a.x>b.x||equal(a.x, b.x)&&a.y<b.y; }   //��x��y��������
inline bool cmp4(const V &a, const V &b){ return a.x<b.x||equal(a.x, b.x)&&a.y>b.y; }   //��x��y��������
struct cmp5{
    bool operator()(const V &a, const V &b){ return cmp3(a, b); }
};
struct cmp6{
    bool operator()(const V &a, const V &b){ return cmp4(a, b); }
};
inline V operator-(const V &a){ return V(-a.x, -a.y); }
inline V operator+(const V &a, const V &b){ return V(a.x+b.x, a.y+b.y); }
inline V operator-(const V &a, const V &b){ return V(a.x-b.x, a.y-b.y); }
inline V operator*(const double &x, const V &a){ return V(a.x*x, a.y*x); }
inline V operator*(const V &a, const double &x){ return V(a.x*x, a.y*x); }
inline V operator/(const V &a, const double &x){ return V(a.x/x, a.y/x); }
inline bool operator==(const V &a, const V &b){ return equal(a.x, b.x)&&equal(a.y, b.y);}
inline bool operator!=(const V &a, const V &b){ return !(a==b); }
inline double operator*(const V &a, const V &b){ return a.x*b.x+a.y*b.y; }
inline double operator^(const V &a, const V &b){ return a.x*b.y-a.y*b.x; }
inline double len(const V &a){ return sqrt(a.x*a.x+a.y*a.y); }
inline double dis(const V &a, const V &b){ return len(a-b); }
inline V mid(const V &a, const V &b){ return V((a.x+b.x)/2, (a.y+b.y)/2); }
inline V c_wise(const V &a){ return V(a.y, -a.x); }
inline V unit(const V &a){ return a/len(a); }
inline double S_tri(const V &a, const V &b, const V &c){ return abs((b-a)^(c-a))/2; }
inline double S_iso(const double &l, const double &theta){ return 0.5*l*l*sin(theta); }
inline double S_roundtable(const double &r, const double &R, const double &h){  //Բ̨���
    return PI*h*(sqr(r)+r*R+sqr(R))/3;
}
inline double slope(const V &a, const V &b){ return (a.y-b.y)/(a.x-b.x); }
bool equal_sign(double a, double b){
    return greater(a, 0)&&greater(b, 0)||less(a, 0)&&less(b, 0);
}
bool contra_sign(double a, double b){
    return greater(a, 0)&&less(b, 0)||less(a, 0)&&greater(b, 0);
}
inline bool operator<(const V &a, const V&b){  //��Ԫ������
    return less(a.x, b.x)||(equal(a.x, b.x)&&less(a.y, b.y));
}
inline int quadrant(const V &a){
    return a.x>=0?(a.y>=0?1:4):(a.y>=0?2:3);
}
inline double angle(const double &a, const double &b, const double &c){  //���Ҷ���aΪ���
    return acos((sqr(b)+sqr(c)-sqr(a))/(2*b*c));
}
inline double angle(const V &a, const V &b){  //�����н�1
    if (zero(a^b)) return 0;
    return acos(a*b/len(a)/len(b));
}  //0~pi
inline double angle2(const V &a, const V &b){  //�����н�2-pi~pi����˾������ţ�������˳���й�
    return (a^b)>=0?angle(a, b):-angle(a, b);
}
inline bool obtuse(const V &a, const V &b, const V &c){ return less((b-a)*(c-a), 0); }
inline bool acute(const V &a, const V &b, const V &c){ return greater((b-a)*(c-a), 0); }
inline bool right(const V &a, const V &b, const V &c){ return zero((b-a)*(c-a)); }
inline V rotate(const V &a, double theta){
    double s=sin(theta), c=cos(theta);
    return V(a.x*c-a.y*s, a.x*s+a.y*c);
}
struct L{  //��¼��λ��������+���㣬Ҳ����������ʾ�߶�
    V d, a, b;
    L(){}
    L(const V &x1, const V &x2, const V &x3):d(x1),a(x2),b(x3){}
    L(const V &x, const V &y){ *this=L(y-x, x, y); }
    L(const V &d){ *this=L(d, V(0,0), d); }
    void print(){ d.print_space(); a.print_space(); b.print_space(); puts("");}
};
inline L get_L(const V &d, const V &p){ return L(d, p, p+d); }
inline double angle(const V &v){  //��x�Ὺʼ���2pi��Χ�Ƕ�
    double tmp=atan2(v.y, v.x);
    return tmp>=0?tmp:tmp+2*PI;
}
inline double angle(const L &l){
    return angle(l.d);
}
inline V priject(const V &p, const L &l){
    return l.a+((p-l.a)*unit(l.d))*unit(l.d);
}
inline V reflect(const V &p, const L &l){
    return 2*priject(p, l)-p;
}
inline bool on_line(const V &p, const L &l){
    return zero(l.d^(p-l.a));
}
inline bool on_seg(const V &p, const L &l){
    return zero(dis(p, l.a)+dis(p, l.b)-dis(l.a, l.b));
}
inline double dis(const V &p, const L &l){
    return abs((p-l.a)^(p-l.b))/dis(l.a, l.b);
}
inline double dis2(const V &p, const L &l){  //�����ž���
    return ((p-l.a)^(p-l.b))/dis(l.a, l.b);
}
inline bool collinear(const V &a, const V &b){ return zero(a^b); }
inline bool orthogonal(const V &a, const V &b){ return zero(a*b); }
inline bool parallel(const L &l1, const L &l2){ return zero(l1.d^l2.d); }
inline bool orthogonal(const L &l1, const L &l2){ return zero(l1.d*l2.d); }
inline bool straddle(const L &l1, const L &l2){  //l1������l2��
    double f1=(l1.a-l2.a)^l2.d;
    double f2=(l1.b-l2.a)^l2.d;
    if (f1*f2<eps) return true;
    else return false;
}
inline bool is_intersect2(const L &l1, const L &l2){  //�����߶��ཻ��l1Ϊ��
    double a=(l2.a-l1.a)^l1.d, b=(l2.b-l1.a)^l1.d;
    if (!less(a, 0)&&!greater(b, 0)) return true;
    if (!greater(a, 0)&&!less(b, 0)) return true;
    return false;
}
inline bool is_intersect(const L &l1, const L &l2){  //�߶��ཻ
    if (greater(min(l1.a.x, l1.b.x), max(l2.a.x, l2.b.x))||
        less(max(l1.a.x, l1.b.x), min(l2.a.x, l2.b.x))||
        greater(min(l1.a.y, l1.b.y), max(l2.a.y, l2.b.y))||
        less(max(l1.a.y, l1.b.y), min(l2.a.y, l2.b.y)))
            return false;
    //�����ǿ����ų�
    return straddle(l1, l2)&&straddle(l2, l1);
}  //�ȿ���l1������l2�ϣ��ٿ���l2������l1��
inline V intersection(const L &l1, const L &l2){
    double k=((l2.a-l1.a)^l2.d)/(l1.d^l2.d);
    return l1.a+k*l1.d;
}
inline L bisector(const V &a, const V &b, const V &c){  //angleBAC
    V d1=(b-a)/len(b-a), d2=(c-a)/len(c-a);
    V d=(d1+d2)/len(d1+d2);
    return L(d, a, a+d);
}
inline L perpendicular(const V &a, const V &b){
    V x=mid(a, b), d=c_wise(b-a);
    return L(d, x, x+d);
}
//Ϊ�������ֱ�Ӵ����飬��OΪԭ��
inline double L_polygon(const V *a, const int &n){
    double res=0;
    for (int i=0; i<n; ++i) res+=dis(a[i], a[(i+1)%n]);
    return res;
}
inline double S_polygon(const V *a, const int &n){
    double res=0;
    for (int i=0; i<n; ++i) res+=(a[i]^a[(i+1)%n]);
    return res/2;
}
inline void read_polygon(V *a, int &n, bool with_n){
    if (with_n) scanf("%d", &n);
    for (int i=0; i<n; ++i) a[i].read();
}
inline void print_polygon(V *a, int &n, bool with_n){
    if (with_n) printf("%d\n", n);
    for (int i=0; i<n; ++i) a[i].print_int();
}
inline bool is_convex(const V *a, const int &n){
    int j, k, d=0, nd; double o;
    for (int i=0; i<n; ++i){
        j=(i+1)%n, k=(i+2)%n;
        o=(a[j]-a[i])^(a[k]-a[j]);
        if (zero(o)) continue;
        nd=less(o, 0)?-1:1;
        if (!d) d=nd;
        else if (d!=nd) return false;
    }
    return true;
}
inline bool cmp(const V &a, const V &b){  //С�ں����������ڰ�ƽ��
    double dot=(a-O)^(b-O);
    if (greater(dot, 0)) return true;
    return false;
}
inline bool Cmp(const V &a, const V &b){  //С�ں�������������ƽ��
    int quada=quadrant(a), quadb=quadrant(b);
    if (quada!=quadb) return quada<quadb;
    return (a^b)>0;
}
inline int rshort(const V &a, const V &b){  //��������(����ȷ�Ļ�׼���Լ���Ϊָ�����򣩱ȽϺ���
    double dot=(a-O)^(b-O);
    if (greater(dot, 0)) return 2;  //�󷵻�0���ȷ���1���ҷ���2
    if (equal(dot, 0)) return less(dis(a, O), dis(b, O));  //ȫ�������
    return 0;
}
inline int lshort(const V &a, const V &b){  //����a�Ƿ���b���
    double dot=(a-O)^(b-O);
    if (greater(dot, 0)) return 0;  //�󷵻�2���ȷ���1���ҷ���0
    if (equal(dot, 0)) return less(dis(a, O), dis(b, O));
    return 2;
}
inline bool in_poly(const V &p, const V *a, const int &n){
    double x; int j, res=0;
    for (int i=0; i<n; ++i){
        j=(i+1)%n;
        if (equal(a[i].y, a[j].y)) continue;
        if (less(max(a[i].y, a[j].y), p.y)) continue;
        if (!less(min(a[i].y, a[j].y), p.y)) continue;
        x=a[i].x+(p.y-a[i].y)/(a[j].y-a[i].y)*(a[j].x-a[i].x);
        if (x<p.x) res^=1;
    }
    return res?true:false;
}
inline int in_convex(const V &p, const V *a, const int &n){  //�Ѿ�ȥ�߽缫����������a[0]�����·�
    O=a[0];  //��ԭ��
    if (lshort(a[1], p)||rshort(a[n-1], p)) return 0;
    int x=upper_bound(a+1, a+n, p, cmp)-a-1;
    O=a[x];  //2���� 1�ڱ��� 0��͹����
    return lshort(p, a[(x+1)%n]);
}
inline void adjust_lowest(V *a, const int &n){  //��ʱ��͹������Ϊ��ʼ��Ϊ��͵� 
	int id=0;
    for (int i=0; i<n; ++i)
        if (less(a[i].y, a[id].y)||
                equal(a[i].y, a[id].y)&&less(a[i].x, a[id].x)) id=i;
    V *b=new V[n];
    for (int i=0; i<n; ++i) b[i]=a[(i+id)%n];
    for (int i=0; i<n; ++i) a[i]=b[i];
    delete []b;
}
inline V find_lowest(V *a, const int &n){
    int id=0;
    for (int i=0; i<n; ++i)
        if (less(a[i].y, a[id].y)||
                equal(a[i].y, a[id].y)&&less(a[i].x, a[id].x)) id=i;
    return a[id];
}
inline void polar_sort(V *a, const int &n, const V &origin){  //����͹����Ե�㼫������
    O=origin;
    sort(a, a+n, rshort);  //�����Ҳ���߹����Ҿ���СΪС
    int m;  //���Ĺ��߲���Ҫ��ת���Ա���ϵ�Ҫ���������
    for (m=n-1; m>=0; --m) if (!zero((a[m]-a[0])^(a[n-1]-a[0]))) break;
    if (~m) reverse(a+m+1, a+n);  //�����һ��ֱ�߾Ͳ��÷�ת��
    O=V(0, 0);
}
inline bool turn_right(const V &p1, const V &p2, const V &p3){  //p1ָ��p2��p2ָ��p3��ǰ��˺���
    return less((p2-p1)^(p3-p2), 0);
}
inline bool turn_left(const V &p1, const V &p2, const V &p3){
    return greater((p2-p1)^(p3-p2), 0);
}
inline void graham(V *a, int &n, bool include_on_edge){
    int cnt=0, id1, id2;
    int *s=new int[n];
    for (int i=0; i<=n; ++i){
        while (cnt>=2){
            id1=s[cnt-1]; id2=s[cnt-2];
            if (include_on_edge){
                if (a[id1]!=a[i%n]&&!turn_right(a[id2], a[id1], a[i%n])) break;
            } else if (turn_left(a[id2], a[id1], a[i%n])) break;
            if (i==n&&cnt==2) break;  //���е㶼��һ��ֱ���ϵ����
            --cnt;
        }
        if (i<n) s[cnt++]=i;
    }
    //if (a[s[0]]==a[s[cnt-1]]) cnt=1;  //����ֻ��һ�����������������ظ���
    n=cnt;
    for (int i=0; i<n; ++i) a[i]=a[s[i]];
    delete []s;
}
inline void andrew(V *a, int &n, bool include_on_edge){
    int cnt=0, id1, id2;
    int *s=new int[n];
    for (int i=0; i<n; ++i){
        while (cnt>=2){
            id1=s[cnt-1]; id2=s[cnt-2];
            if (include_on_edge){
                if (!turn_right(a[id2], a[id1], a[i%n])) break;
            } else if (turn_left(a[id2], a[id1], a[i%n])) break;
            --cnt;
        }
        if (i<n) s[cnt++]=i;
    }
    n=cnt;
    for (int i=0; i<n; ++i) a[i]=a[s[i]];
    delete []s;
}
inline void merge_2(V *a, int &n, V *b, int &m, V *c, int &N){
    N=0;
    for (int i=0; i<n; ++i) c[N++]=a[i];
    for (int i=1; i<m-1; ++i) c[N++]=b[i];
}
inline void merge_convex(V *a, int &n, V *b, int &m, V *c, int &N, bool include_on_edge, bool (*cmp)(const V &a, const V &b)){
    int cnta=0, cntb=0; N=0;
    while (N<n+m){
        while ((cntb==m||cmp(a[cnta], b[cntb]))&&cnta<n) c[N++]=a[cnta++];
        while ((cnta==n||!cmp(a[cnta], b[cntb]))&&cntb<m) c[N++]=b[cntb++];
    }
    andrew(c, N, include_on_edge);
}
template <typename cmp> using Iter=typename multiset<V, cmp>::iterator;
template <typename cmp, typename Iter>
inline bool in_dynavex(Iter iter, multiset<V, cmp> &S){
    if (iter==S.begin()||iter==--S.end()) return false;
    if (!turn_left(*pri(iter, S), *iter, *nxt(iter, S))) return true;
    return false;
}
template <typename cmp>
inline bool in_dynavex(V &p, multiset<V, cmp>&S){
    auto iter=S.find(p);
    if (iter!=S.end()) return true;
    iter=S.insert(p);
    bool flag=in_dynavex(iter, S);
    S.erase(iter);
    return flag;
}
template <typename maintain_type>  //�Թ��ڱߵ����ݽ��ж�̬ά��
inline void maintain1(maintain_type &obj, const V &a, const V &b){  //�ӱ�
    obj+=dis(a, b);
}
template <typename maintain_type>
inline void maintain2(maintain_type &obj, const V &a, const V &b){  //ɾ��
    obj-=dis(a, b);
}
template <typename cmp, typename maintain_type>
inline void dynavex_insert(const V &p, multiset<V, cmp> &S, maintain_type &obj){
    auto iter=S.insert(p);
    if (S.size()==2) maintain1(obj, *S.begin(), *++S.begin());
    if (S.size()<3) return;
    if (in_dynavex(iter, S)){
        S.erase(iter);
        return;
    }
    if (iter!=S.begin()&&iter!=--S.end())
        maintain2(obj, *pri(iter, S), *nxt(iter, S));
    if (iter!=S.begin()){
        maintain1(obj, *pri(iter, S), *iter);
        while (pri(iter, S)!=S.begin()){
            auto iter2=pri(iter, S);
            auto iter3=pri(iter2, S);
            if (!turn_left(*iter3, *iter2, *iter)){
                maintain2(obj, *iter2, *iter3);
                maintain2(obj, *iter2, *iter);
                maintain1(obj, *iter3, *iter);
                S.erase(iter2);
            }
            else break;
        }
    }
    if (iter!=--S.end()){
        maintain1(obj, *nxt(iter, S), *iter);
        while (++nxt(iter, S)!=S.end()){
            auto iter2=nxt(iter, S);
            auto iter3=nxt(iter2, S);
            if (!turn_left(*iter, *iter2, *iter3)){
                maintain2(obj, *iter2, *iter3);
                maintain2(obj, *iter2, *iter);
                maintain1(obj, *iter3, *iter);
                S.erase(iter2);
            }
            else break;
        }
    }
}
template <typename maintain_type>
struct Dynavex{
    multiset<V, cmp5> upper;
    multiset<V, cmp6> lower;
    inline void insert(const V &p, maintain_type &obj){
        dynavex_insert(p, upper, obj);
        dynavex_insert(p, lower, obj);
    }
    inline bool inside(const V &p){
        return in_dynavex(p, upper)&&in_dynavex(p, lower);
    }
};
double height(const V &a, const V &b1, const V &b2){
    return S_tri(a, b1, b2)/dis(b1, b2);
}
inline double diameter(const V *a, const int &n){
    double ans=0; int j=0;
    for (int i=0; i<n; ++i){  //ö�ٶ��㣬������ƽ����
        while (less(height(a[i], a[j], a[(j+1)%n]), height(a[i], a[(j+1)%n], a[(j+2)%n])))
            j=(j+1)%n;  //����less�����С�������µĴ���ǰ��
        ans=max(ans, dis(a[i], a[j]));
        ans=max(ans, dis(a[i], a[(j+1)%n]));
    }
    return ans;
}
inline V get_centroid(const V &a, const V &b, const V &c){
    return V(a.x+b.x+c.x, a.y+b.y+c.y)/3;
}
inline V get_centroid_p(V *a, int &n){
    V res(0, 0);
    for (int i=0; i<n; ++i) res=res+a[i];
    return res/n;
}
inline V get_centroid(V *a, int &n){
    V res(0, 0);
    for (int i=0; i<n; ++i) res=res+(a[i]^a[(i+1)%n])/2
        *get_centroid(a[i], a[(i+1)%n], V(0, 0));
    return res/S_polygon(a, n);
}
vector<V> get_intersection(V *a, int &n, const L &l){  //�������ν���
    L seg; vector<V> res;
    for (int i=0; i<n; ++i){
        seg=L(a[nxt(i, n)], a[i]);
        if (is_intersect2(l, seg)){
            if (parallel(l, seg)){
                res.push_back(seg.a);
                res.push_back(seg.b);
            }
            else res.push_back(intersection(l, seg));
        }
    }
    return res;
}
bool collide(V *a, int &n, V *b, int &m, V &v, const double &t){  //a���ٶ�v�˶�t��ʱ�ܷ�ײ��b
    for (int i=0; i<n; ++i)
        if (in_convex(a[i]+v*t, b, m)) return true;
    return false;
}
double max_dis(V *a, int &n){  //������ԣ�ֱ����
    graham(a, n, false);
    return diameter(a, n);
}
inline double area(const V *a, const int &n){
    double ans=0;
    for (int i=0; i<n; ++i) ans+=a[i]^a[(i+1)%n];
    return ans/2;
}
void convex_tangent(const V *a, const int &n, const V &p, int &p1, int &p2){  //͹�����е�
	if (n==1){
		p1=p2=0;
		return;
	}
    for (int i=0; i<n; ++i){
        if (((a[i]-a[pre(i, n)])^(p-a[i]))>=0&&((p-a[i])^(a[nxt(i, n)]-a[i]))>0) p1=i;
        if (((a[i]-a[pre(i, n)])^(p-a[i]))<0&&((p-a[i])^(a[nxt(i, n)]-a[i]))<=0) p2=i;  //�Ҳ��
    }
}
void convex_cut(const V *a, V *b, const int &n, int &m, const L &l){  //��ƽ�������
    V p[2]; int id[2], cnt=0;
    for (int i=0; i<n; ++i){
        if (straddle(L(a[i], a[(i+1)%n]), l)){
            if (on_line(a[(i+1)%n], l)) continue;
            id[cnt]=i;
            p[cnt]=intersection(L(a[i], a[(i+1)%n]), l);
            ++cnt;
        }
    }
    if (cnt<2){  //cutδ�γɸ���
        bool flag=false;
        for (int i=0; i<n; ++i){
            if (greater(l.d^(a[i]-l.a), 0)) flag=true;
            if (less(l.d^(a[i]-l.a), 0)) flag=false;
            b[i]=a[i];
        }
        m=(flag?n:0);
        return;
    }
    if (less(l.d*(p[1]-p[0]), 0)){  //��������
        swap(p[0], p[1]);
        swap(id[0], id[1]);
    }
    cnt=0;
    b[cnt++]=p[0]; b[cnt++]=p[1];
    for (int i=(id[1]+1)%n; i!=(id[0]+1)%n; i=(i+1)%n)
        b[cnt++]=a[i];
    m=cnt;
}
double min_dis(V *a, V *b, const int &l, const int &r){  //���ŷ��ν��У���bҪ��y����
    if (l+1==r) return INF;
    int m=(l+r)>>1;
    double D=min(min_dis(a, b, l, m), min_dis(a, b, m, r));
    V *c=(V*)malloc(sizeof(V)*(r-l));
    V *d=(V*)malloc(sizeof(V)*(r-l));
    int i=l, j=m, cnt=0;
    while (i<m||j<r){  //�鲢
        if (j==r||i<m&&b[i].y<b[j].y) c[cnt++]=b[i++];
        else c[cnt++]=b[j++];
    } cnt=0;
    L seperator(a[m], V(a[m].x, a[m].y+1));
    for (i=0; i<r-l; ++i) if (dis(c[i], seperator)<D) d[cnt++]=c[i];
    for (i=0; i<cnt-2; ++i)  //����ָ�����d�ڵĵ㣬��y�������ö������
        D=min(D, min(dis(d[i], d[i+1]), dis(d[i], d[i+2])));
    D=min(D, dis(d[cnt-2], d[cnt-1]));
    memcpy(b+l, c, sizeof(V)*(r-l));
    free(c); free(d);
    return D;
}
double min_dis(V *a, const int &n){  //��̾�����
    sort(a, a+n, cmp1);
    V *b=(V*)malloc(sizeof(V)*n);
    memcpy(b, a, sizeof(V)*n);
    double ans=min_dis(a, b, 0, n);
    free(b);
    return ans;
}
struct C{
    V o;
    double r;
    C(const V &o1, double r1):o(o1), r(r1){}
    C(double a=0, double b=0, double c=0):o(a, b), r(c){}
    C(const V &a, const V &b, const V &c){
        o=intersection(perpendicular(a, b), perpendicular(a, c));
        r=dis(o, a);
    }
    void read(){
        o.read();
        scanf("%lf", &r);
    }
    void print(){
        printf("%.9lf %.9lf %.9lf\n", o.x, o.y, r);
    }
};
inline bool in_cir(const V &p, const C &c){ return less(dis(c.o, p), c.r); }
inline bool on_cir(const V &p, const C &c){ return equal(dis(c.o, p), c.r); }
inline bool out_cir(const V &p, const C &c){ return greater(dis(c.o, p), c.r); }
inline double dis(const L &l, const C &c){ return dis(c.o, l); }
inline double dis(const C &c1, const C &c2){ return dis(c1.o, c2.o); }
inline double rela(const L &l, const C &c){
    double d=dis(l, c);
    if (less(d, c.r)) return -1;  //intersect
    else if (equal(d, c.r)) return 0;  //tangent
    else return 1;  //seperate
}
inline int rela(const C &c1, const C &c2){  //���ص��ǹ���������
    double d=dis(c1, c2);
    if (greater(d, c1.r+c2.r)) return 4;  //seperate
    else if (equal(d, c1.r+c2.r)) return 3;  //circumscribed
    else if (less(max(c1.r, c2.r), min(c1.r, c2.r)+d)) return 2;  //intersect
    else if (equal(abs(c1.r-c2.r), d)) return 1;  //inscribed
    else return 0;  //include
}
inline C incircle(const V &a, const V &b, const V &c){  //�ڽ�Բ
    V o=intersection(bisector(a, b, c), bisector(b, a, c));
    return C(o, dis(o, L(a, b)));
}
inline C excircle(const V &a, const V &b, const V &c){
    V o=intersection(perpendicular(a, b), perpendicular(a, c));
    return C(o, dis(o, a));
}
inline void get_intersection(const C &c, V &a, V &b){  //Բ��ֱ�߽���
    L l=L(a, b);
    V p=priject(c.o, l);
    double d=sqrt(sqr(c.r)-sqr(dis(c.o, l)));
    a=p+unit(l.d)*d;
    b=p-unit(l.d)*d;
    if (cmp3(b, a)) swap(a, b);
}
inline void get_intersection(const C &c1, const C &c2, V &a, V &b){  //Բ��Բ����
    double d=dis(c1, c2);
    double theta=acos((sqr(c1.r)+sqr(d)-sqr(c2.r))/(2*c1.r*d));
    a=c1.o+c1.r*cos(theta)*unit(c2.o-c1.o);
    b=a+c_wise(c2.o-c1.o);
    get_intersection(c1, a, b);
}
inline void get_tangent(const C &c, const V &p, V &a, V &b){  //ע��p������c��
    C c2=C((c.o+p)/2, dis(c.o, p)/2);
    get_intersection(c, c2, a, b);
}
inline void get_circumscribe(const C &c1, const C &c2, V *v, int &cnt){  //��Բ������
    int rel=rela(c1, c2);
    if (rel<1) return;
    double theta=acos((c2.r-c1.r)/dis(c1, c2));
    V v1=rotate(c1.o-c2.o, theta), v2=rotate(c1.o-c2.o, -theta);
    v[cnt++]=c1.o+unit(v1)*c1.r;
    v[cnt++]=c2.o+unit(v1)*c2.r;
    v[cnt++]=c1.o+unit(v2)*c1.r;
    v[cnt++]=c2.o+unit(v2)*c2.r;
}
inline void get_inscribe(const C &c1, const C &c2, V *v, int &cnt){  //��Բ������
    int rel=rela(c1, c2);
    if (rel<3) return;
    double theta=acos((c1.r+c2.r)/dis(c1, c2));
    V v1=rotate(c2.o-c1.o, theta), v2=rotate(c2.o-c1.o, -theta);
    v[cnt++]=c1.o+unit(v1)*c1.r;
    //v[cnt++]=c2.o+unit(v1)*c2.r;
    if (rel!=3) v[cnt++]=c1.o+unit(v2)*c1.r;
    //v[cnt++]=c2.o+unit(v2)*c2.r;
}
inline double S(const C &c){ return PI*c.r*c.r; }
inline double S_sector(const C &c, double theta){
    return theta/2*c.r*c.r;
}
inline double S_sector(const C &c, const V &a, const V &b){  //a c.o bȷ���ĽǸ�����������
    double theta=angle(a-c.o, b-c.o);
    return S_sector(c, theta);
}
inline double S_arc(const C &c, const V &a, const V &b){
    return S_sector(c, a, b)-S_tri(c.o, a, b);
}
double S_intersection(const V &a, const V &b, const C &c){  //Բ�������κ�Բ�������
    L l(a, b);
    double d=dis(c.o, l);
    if (!less(d, c.r)) return S_sector(c, a, b);
    if (in_cir(a, c)&&in_cir(b, c)) return S_tri(a, b, c.o);
    V P=a, P2=b, A=a, B=b;
    get_intersection(c, P, P2);
    if ((!in_cir(a, c))&&(!in_cir(b, c))){  //���߶���Բ��
        if (!on_seg(P, l)) return S_sector(c, a, b);
        return S_sector(c, a, b)-S_arc(c, P, P2);
    }
    if (!in_cir(A, c)) swap(A, B);
    if (!on_seg(P, l)) swap(P, P2);
    return S_tri(A, P, c.o)+S_sector(c, B, P);
}
double S_intersection(const V *a, const int &n, C &c){  //Բ�����ε������
    double ans=0, dir=0;
    for (int i=0; i<n; ++i){
        int j=(i+1)%n;
        dir=((a[j]-a[i])^(c.o-a[j]));
        dir=(dir>0?1:-1);
        ans+=dir*S_intersection(a[i], a[j], c);
    }
    return abs(ans);
}
double S_intersection(const C &c1, const C &c2){  //Բ��Բ�������(���ǲ������Ļ���һ�¾�����)
    int rel=rela(c1, c2);
    if (rel>=3) return 0;
    if (rel<=1) return min(S(c1), S(c2));
    double d=dis(c1, c2);
    double alpha=angle(c2.r, c1.r, d)*2;
    double beta=angle(c1.r, c2.r, d)*2;
    double S1=S_sector(c1, alpha)-S_iso(c1.r, alpha);
    double S2=S_sector(c2, beta)-S_iso(c2.r, beta);
    return S1+S2;
}
inline bool in_hplane(const V &p, const L &l){  //�����������
    return less((p-l.a)^l.d, 0);
}
inline bool out_hplane(const V &p, const L &l){  //���������Ҳ�
    return greater((p-l.a)^l.d, 0);
}
inline bool on_right(const L &a, const L &b, const L &c){  //a��b�Ľ�����c�Ҳ��c��
    if (parallel(a, b)) return true;
    return !in_hplane(intersection(a, b), c);
}
inline bool cmp_angle(const V &a, const V &b){
    return angle(a)<angle(b);
}
struct cmpA{
    bool operator()(const V &a, const V &b){
        return cmp_angle(a, b);
    }
};
inline bool cmpL(const L &a, const L &b){
    double anga=angle(a), angb=angle(b);
    if (equal(anga, angb)) return in_hplane(a.a, b);
    return anga<angb;
}
void hplane_intersection(L *a, int &n){  //�����д����Ӧ�������߶εı��
    sort(a, a+n, cmpL);
    int *q=new int[n], h=0, t=0;
    for (int i=0; i<n; ++i){
        while (h<t-1&&on_right(a[q[t-2]], a[q[t-1]], a[i])) --t;
        while (h<t-1&&on_right(a[q[h]], a[q[h+1]], a[i])) ++h;
        q[t++]=i;
    }
    while (h<t-1&&on_right(a[q[t-1]], a[q[t-2]], a[q[h]])) --t;
    n=t-h;
    for (int i=h; i<t; ++i) a[i-h]=a[q[i]];  //����ɾ����������
}
bool build_convex(L *a, int &n, V *v){
    if (n<3) return false;
    for (int i=0; i<n; ++i)
        v[i]=intersection(a[i], a[(i+1)%n]);
    return true;
}
void Minkowski_sum(V *a, int n, V *b, int m, V *c, int &N){  //Ҫ��͹����ʼ��Ϊ��͵㣬����ʱ������ 
    V *l=(V*)malloc((n+m)*sizeof(V)); N=0;
    int cnta=0, cntb=0;
    V pa, pb;
    while (cnta<n||cntb<m){
        if (n) pa=a[(cnta+1)%n]-a[cnta];
        if (m) pb=b[(cntb+1)%m]-b[cntb];
        if (cnta==n){
            l[N++]=pb; cntb++;
            continue;
        }
        if (cntb==m){
            l[N++]=pa; cnta++;
            continue;
        }
        if (greater(pa^pb, 0)) l[N++]=pa, cnta++;
        else if (equal(pa^pb, 0)) l[N++]=pa+pb, cnta++, cntb++;
        else l[N++]=pb, cntb++;
    }
    if (!m) c[0]=a[0];
    else if (!n) c[0]=b[0];
    else c[0]=a[0]+b[0];  //������ĵ㣬һ��������������  //��������һ��
    for (int i=0; i<N; ++i)
        c[i+1]=c[i]+l[i];  //������ʼ��Ϊ��͵㣬����ʱ�������͹�� 
    free(l);
}
C min_coverage(V *a, const int &n){  //�������O(n)����СԲ���ǣ����ڳ�Բ�µ�һ������Բ��
    C c=C(a[0], 0);
    for (int i=1; i<n; ++i)
    if (out_cir(a[i], c)){
        c=C(a[i], 0);
        for (int j=0; j<i; ++j)
        if (out_cir(a[j], c)){
            c=C((a[i]+a[j])/2, dis(a[i], a[j])/2);
            for (int k=0; k<j; ++k)
            if (out_cir(a[k], c)){
                c=C(a[i], a[j], a[k]);
            }
        }
    }
    return c;
}
bool convex_symmetric(V *a, const int &n, L &l, int p1, int p2){  //lΪ�Գ��ᣬp1��p2Ϊ�����
    int cnt=0;
    while (cnt<=n/2){
        if (reflect(a[p1], l)!=a[p2]) return false;
        p1=pre(p1, n);  //ע��p1�Ĵ�����p2֮ǰ��p1������p2˳����
        p2=nxt(p2, n);
        ++cnt;
    }
    return true;
}
bool edge_point(V *a, const int &n, int p, const L &l){  //�жϵ�a[p]�Ƿ�����l��͹������ƽ��ĽӴ���
    return !out_hplane(a[pre(p, n)], l)&&!out_hplane(a[nxt(p, n)], l);
}
vector<L> fast_symmetric(V *a, const int &n){
    double *s=new double[n*4];
    for (int i=0; i<n; ++i){
        s[i*2]=(a[i]-a[pre(i, n)])^(a[nxt(i, n)]-a[i]);  //��
        s[i*2+1]=dis(a[i], a[nxt(i, n)]);  //��
    }
    for (int i=0; i<2*n-2; ++i) s[i+2*n]=s[i];
    int *p=new int[n*4], pos, R, ans;
	pos=R=ans=0; memset(p, 0, sizeof(int)*n*4);
	for (int i=1; i<4*n-2; ++i){
		if (i<R) p[i]=min(p[pos*2-i], R-i); else p[i]=1;
		for (; i-p[i]>=0&&equal(s[i+p[i]], s[i-p[i]]); ++p[i]);
		if (p[i]+i>R) R=p[i]+i, pos=i;
	}
    vector<L> sym; int id1, id2; V p1, p2;
    for (int i=0; i<4*n-2; ++i){
        if (p[i]<n) continue;
        id1=i%(2*n); id2=(i+n)%(2*n);
        if (id1&1) p1=mid(a[id1/2], a[nxt(id1/2, n)]);
        else p1=a[id1/2];
        if (id2&1) p2=mid(a[id2/2], a[nxt(id2/2, n)]);
        else p2=a[id2/2];
        sym.push_back(L(p1, p2));
    }
    delete[] s; delete[] p;
    return sym;
}
double Simpson(double (*F)(double), double a, double b){
    double c=(a+b)/2;
    return (b-a)*(F(a)+4*F(c)+F(b))/6;
}
double Romberg(double (*F)(double), double a, double b, double prians){  //Romberg����
    double c=(a+b)/2;
    double l=Simpson(F, a, c), r=Simpson(F, c, b);
    if (equal(l+r, prians)) return l+r;
    else return Romberg(F, a, c, l)+Romberg(F, c, b, r);
}
inline double calc1(const C &c, const double &theta){  //���ֹ�ʽ���Բ������
    double x=c.o.x, r=c.r;
    return x*r*sin(theta)+sqr(r)/4*sin(2*theta)+sqr(r)/2*theta;
}
double CircleUnion(const C *a, const int &n){
    bool *skip=new bool[n]();
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (i!=j&&rela(a[i], a[j])<=1){
                if (a[i].r<a[j].r) skip[i]=true;
                if (equal(a[i].r, a[j].r)&&i<j) skip[i]=true;
            }
    double a1, a2, l, r, ans=0; int cnt=0, t;
    pair<double, int> *mark=new pair<double, int>[2*n+10]();
    for (int i=0; i<n; ++i){  //i��Ϊ�����串�ǵ�Բ
        if (skip[i]) continue;
        t=0, cnt=0;
        mark[t++]=make_pair(0, 0);
        for (int j=0; j<n; ++j){
            if (skip[j]) continue;
            if (i==j) continue;
            if (rela(a[i], a[j])>=3) continue;
            a1=angle(a[j].o-a[i].o);
            a2=angle(a[j].r, a[i].r, dis(a[i].o, a[j].o));
            l=a1-a2, r=a1+a2;;
            if (l<0) l+=2*PI;
            if (r>2*PI) r-=2*PI;  //��һ�в���д���ڣ���Ȼ�·�j=0�Ͳ��ǳ�����(0,0)��cnt��Ӵ�
            if (l>r) ++cnt;
            mark[t++]=make_pair(l, 1);
            mark[t++]=make_pair(r, -1);
        }
        mark[t++]=make_pair(2*PI, 0);
        sort(mark, mark+t);
        for (int j=1; j<t; ++j){  //here
            if (!cnt) ans+=calc1(a[i], mark[j].first)-calc1(a[i], mark[j-1].first);
            cnt+=mark[j].second;
        }
    }
    delete[] skip; delete[] mark;
    return ans;
}
struct Dynaseg{  //��̬�߶β�/���֤���ص�
    using pdd=pair<double, double>;
    using iter=set<pdd>::iterator;
    set<pdd> s;
    static double ans;
    C obj;
    void insert(double l, double r){
        if (l>r){
            insert(l, 2*PI); insert(0, r);
            return;
        }
        iter it(s.lower_bound(make_pair(l, 0)));
        auto tmp=it;
        if (it!=s.begin()&&(--tmp)->second>l) --it;
        for (; it!=s.end()&&it->first<r; s.erase(it++)){
            ans-=calc1(obj, it->second)-calc1(obj, it->first);
            if (it->second>r) ans+=calc1(obj, it->second)-calc1(obj, r), 
                s.insert(make_pair(r, it->second));
            if (it->first<l) ans+=calc1(obj, l)-calc1(obj, it->first), 
                s.insert(make_pair(it->first, l));
        }  //��֤������[l,r]��
        //res+=calc1(obj, r)-calc1(obj, l);  //�����̬�߶β���Ҫ��,��ü�
    }
};
}
using namespace geo_2d;

const int maxn=505;
int T, n, m, tangent[maxn], farest[maxn], vis[maxn];
V a[maxn] , b[maxn];

int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		read_polygon(a, n, false);
		read_polygon(b, m, false);
		polar_sort(a, n, find_lowest(a, n));
		polar_sort(b, m, find_lowest(b, m));
		graham(a, n, false);
		graham(b, m, false);
		bool flag=true;
		for (int i=0; i<m; ++i){
			if (in_convex(b[i], a, n)<2){
				flag=false;
				break;
			}
		}
		if (!flag){
			puts("-1");
			continue;
		}
		int t, t2; V p; 
		for (int i=0; i<n; ++i){
			convex_tangent(b, m, a[i], t, tangent[i]);  //�����͹�������͹���е��� 
			p=b[tangent[i]];
			for (int j=i+1; j!=i; j=nxt(j, n))
				if (turn_right(a[i], p, a[j])) farest[i]=j;  //�����͹����ĳ�㲻�ཻ��͹����Զ�ܵ���ĵ�
				else break; 
		}
		memset(vis, 0, sizeof(vis));
		int ans=1e9, cnt;
		for (int i=0; i<n; ++i){
			if (vis[i]) continue;
			cnt=0; t=i;
			while (t-i<n){
				cnt++;
				vis[t%n]=true;
				t2=farest[t%n];
				while (t2<t) t2+=n;
				t=t2;
			}
			ans=min(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}
