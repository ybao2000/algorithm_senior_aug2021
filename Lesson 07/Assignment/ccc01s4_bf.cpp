#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
	double x, y;
};

// return square
double sqr(double a) {
	return a * a;
}

struct Circle {
	Point center;
	double radius;
};

double dist(Point p1, Point p2) {
	return sqrt(sqr(p2.x - p1.x) + sqr(p2.y - p1.y));
}


// return the radius
Circle circle_two(Point p1, Point p2) {
	Point center = { (p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0 };
	return { center, dist(center, p1) };
}

Circle circle_three(Point p1, Point p2, Point p3) {
	double a = p2.x - p1.x;
	double b = p2.y - p1.y;
	double c = (sqr(p2.x) + sqr(p2.y) - sqr(p1.x) - sqr(p1.y)) / 2.0;
	double d = p3.x - p1.x;
	double e = p3.y - p1.y;
	double f = (sqr(p3.x) + sqr(p3.y) - sqr(p1.x) - sqr(p1.y)) / 2.0;
	double det = a * e - b * d;
	double det_x = c * e - b * f;
	double det_y = a * f - d * c;
	double x = det_x / det;
	double y = det_y / det;
	Point center = { x, y };
	return { center, dist(center, p1) };
}


bool is_inside(Circle c, Point p) {
	double d = dist(c.center, p);
	return d < c.radius || abs(d - c.radius) < 1e-8;
}

int main() {
	int n;
	cin >> n;
	vector<Point> vp;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		vp.push_back({ x, y });
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	cout << fixed << setprecision(2);
	double radius = 1e18;
	// using 2 points as diameter
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			Circle c = circle_two(vp[i], vp[j]);
			bool all_in = true;
			for (int k = 0; k < n; k++) {
				if (!is_inside(c, vp[k])) {
					all_in = false;
				}
			}
			if(all_in)
				radius = min(radius, c.radius);
		}
	}
	if (n == 2) {
		cout << radius * 2.0 << endl;
		return 0;
	}

	// using 3 points as a circle
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				Circle c = circle_three(vp[i], vp[j], vp[k]);
				bool all_in = true;
				for (int l = 0; l < n; l++) {
					if (!is_inside(c, vp[l])) {
						all_in = false;
					}
				}
				if (all_in)
					radius = min(radius, c.radius);
			}
		}
	}

	cout << radius * 2.0 << endl;
}