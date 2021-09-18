#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
 
using namespace std;
 
int main() {
    int n;
    double R, r;
    cin >> n >> R >> r;
    if (r > R){
        cout << "NO" << endl;
    }
    else if (r > R/2) {
        if (n>1){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    else {
        double theta = 2.0 * asin(r / (R-r));
        // cout << 2.0* M_PI << " " << n * theta << " " << theta << endl;
        double diff = 2.0*M_PI - n * theta;
        if (diff >= 0){
            cout << "YES" << endl;
        }
        else {
            if(abs(diff) < 1e-8){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}