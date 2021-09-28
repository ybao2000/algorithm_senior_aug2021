#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double INF = 1e18;
struct Point {
    double X, Y;
};
struct Circle {
    Point C;
    double R;
};

double sqr(double x){
    return x*x;
}

double dist(Point a, Point b){
    return sqrt(sqr(a.X-b.X)+sqr(a.Y-b.Y));
}

double is_inside(Circle c, Point p) {
    return dist(c.C, p) <= c.R;
}

Point get_circle_center(double bx, double by, double cx, double cy){
    double B = bx*bx+by*by;
    double C = cx*cx+cy*cy;
    double D = bx*cy-by*cx;
    return {
        (cy*B-by*C)/(2*D),
        (bx*C-cx*B)/(2*D)
    };
}

Circle circle_from(Point A, Point B, Point C){
    Point I = get_circle_center(B.X-A.X, B.Y-A.Y, C.X-A.X, C.Y-A.Y);
    I.X += A.X;
    I.Y += A.Y;
    return {I, dist(I, A)};
}

Circle circle_from(Point A, Point B){
    Point C = {
        (A.X+B.X)/2.0,
        (A.Y+B.Y)/2.0
    };
    return {C, dist(A, B)/2.0};
}

bool is_valid_circle(Circle c, vector<Point> P){
    for(Point p: P){
        if(!is_inside(c, p)){
            return false;
        }
    }
    return true;
}

Circle min_circle_trivial(vector<Point> P){
    if(P.empty()) {
        return {{0, 0}, 0};
    }
    else if(P.size() == 1){
        return {P[0], 0};
    }
    else if(P.size() == 2){
        return circle_from(P[0], P[1]);        
    }
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            Circle c = circle_from(P[i], P[j]);
            if(is_valid_circle(c, P)){
                return c;
            }
        }
    }
    return circle_from(P[0], P[1], P[2]);
}

Circle welzl_iter(vector<Point> P, vector<Point> R, int n){
    if (n==0 || R.size() == 3){
        return min_circle_trivial(R);
    }
    int idx = rand() % n;
    Point p = P[idx];
    swap(P[idx], P[n-1]);
    Circle d = welzl_iter(P, R, n-1);
    if (is_inside(d, p)) return d;
    R.push_back(p);
    return welzl_iter(P, R, n-1);
}

Circle welzl(vector<Point> P){
    vector<Point> P_copy = P;
    random_shuffle(P_copy.begin(), P_copy.end());
    return welzl_iter(P_copy, {}, P_copy.size());
}

int main(){
    int n;
    cin >> n;
    vector<Point> vp;
    for(int i=0; i<n; i++){
        double x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    Circle circle = welzl(vp);
    cout << fixed << setprecision(2) << circle.R *2.0<< endl;
}