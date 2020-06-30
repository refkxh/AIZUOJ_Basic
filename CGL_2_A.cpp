#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const double EPS = 1e-10;
bool equals(double a, double b) {
	return fabs(a - b) < EPS;
}
struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
	Point operator + (Point rhs) {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator - (Point rhs) {
		return Point(x - rhs.x, y - rhs.y);
	}
	Point operator * (double k) {
		return Point(k * x, k * y);
	}
	bool operator < (const Point& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	bool operator == (const Point& rhs) const {
		return equals(x, rhs.x) && equals(y, rhs.y);
	}
	double norm() {
		return x * x + y * y;
	}
	double abs() {
		return sqrt(norm());
	}
};
typedef Point Vector;
struct Segment {
	Point p1, p2;
	Segment(Point p1 = Point(), Point p2 = Point()) :p1(p1), p2(p2) {}
};
typedef Segment Line;
struct Circle {
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0) :c(c), r(r) {}
};
typedef vector<Point> Polygon;
double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}
double cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}
bool isOrthogonal(Vector a, Vector b) {
	return equals(dot(a, b), 0);
}
bool isOrthogonal(Segment a, Segment b) {
	return isOrthogonal(Vector(a.p2.x - a.p1.x, a.p2.y - a.p1.y), Vector(b.p2.x - b.p1.x, b.p2.y - b.p1.y));
}
bool isParallel(Vector a, Vector b) {
	return equals(cross(a, b), 0);
}
bool isParallel(Segment a, Segment b) {
	return isParallel(Vector(a.p2.x - a.p1.x, a.p2.y - a.p1.y), Vector(b.p2.x - b.p1.x, b.p2.y - b.p1.y));
}
int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
    	double x0, y0, x1, y1;
    	scanf("%lf%lf%lf%lf", &x0, &y0, &x1, &y1);
    	Segment t1 = Segment(Point(x0, y0), Point(x1, y1));
    	scanf("%lf%lf%lf%lf", &x0, &y0, &x1, &y1);
    	Segment t2 = Segment(Point(x0, y0), Point(x1, y1));
    	if (isParallel(t1, t2)) printf("2\n");
    	else if (isOrthogonal(t1, t2)) printf("1\n");
    	else printf("0\n");
	}
	return 0;
}
