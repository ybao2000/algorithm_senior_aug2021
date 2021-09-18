#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>
using namespace  std;

double closest(double x, double y, vector<pair<double, double>> pts){
  double d2_min = 1e18;
  for(auto pt: pts){
    double dx = pt.first-x;
    double dy = pt.second-y;
    double d2 = dx*dx+dy*dy;
    if(d2 < d2_min){
      d2_min = d2;
    }
  }
  return d2_min;
}

int main(){
  double x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  // step 1: find the center
  double a = 2.0*(x2-x1);
  double b = 2.0*(y2-y1);
  double c = 2.0*(x3-x1);
  double d = 2.0*(y3-y1);
  double m = x2*x2+y2*y2-x1*x1-y1*y1;
  double n = x3*x3+y3*y3-x1*x1-y1*y1;
  double det = a*d-b*c;
  double det1 = m*d-b*n;
  double det2 = a*n-c*m;
  double ox = det1/det;
  double oy = det2/det;
  // cout << ox << " " << oy << endl;
  double oax = x1-ox;
  double oay = y1-oy;
  double r = sqrt(oax*oax+oay*oay);
  double d_min = 1e18;  // these will be the answer
  int num_min = 0;
  // cout << r << endl;
  double alpha = 0;
  if (abs(oax) < 1e-8){
    alpha = oay > 0 ? M_PI/2.0 : -M_PI/2.0;
  }
  else {
    alpha = oax > 0 ? atan(oay/oax) : M_PI + atan(oay/oax);
  }
  // step 2: 
  for (int num=3; num<=100; num++){
    vector<pair<double, double>> pts;
    for(int i=1; i<num; i++){
        double theta = i * 2.0 * M_PI/num;
        double angle = theta + alpha;
        double tx = ox + r * cos(angle);
        double ty = oy + r * sin(angle);
        pts.push_back(pair<double, double>(tx, ty));
    }
    double s2 = closest(x2, y2, pts);
    double s3 = closest(x3, y3, pts);
    double s = s2 + s3;
    if (s < d_min - 1e-8){  // this trick is to prevent big num replace the small num
      d_min = s;
      num_min = num;
    }
  }
  double beta = 2.0*M_PI/num_min;
  double area = num_min * r * r * sin(beta)/2.0;
  cout << fixed << setprecision(8) << area << endl;
}