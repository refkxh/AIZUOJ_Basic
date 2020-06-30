#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const double EPS = 1e-10;
const int COUNTER_CLOCKWISE = 1, CLOCKWISE = -1, ONLINE_BACK = 2, ONLINE_FRONT = -2, ON_SEGMENT = 0;
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
Point project(Point p, Segment s) {
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + (base * r);
}
Point reflect(Point p, Segment s) {
	return p + (project(p, s) - p) * 2;
}
int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	else if (cross(a, b) < -EPS) return CLOCKWISE;
	else if (dot(a, b) < -EPS) return ONLINE_BACK;
	else if (a.norm() < b.norm()) return ONLINE_FRONT;
	return ON_SEGMENT;
}
bool intersect(Segment s1, Segment s2) {
	return (ccw(s1.p1, s1.p2, s2.p1) * ccw(s1.p1, s1.p2, s2.p2) <= 0 && ccw(s2.p1, s2.p2, s1.p1) * ccw(s2.p1, s2.p2, s1.p2) <= 0); 
}
double getDistance(Point a, Point b) {
	return (b - a).abs();
}
double getDistancePL(Point p, Line l) {
	return fabs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}
double getDistancePS(Point p, Segment s) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0) return (p - s.p1).abs();
	else if (dot(s.p1 - s.p2, p - s.p2) < 0) return (p - s.p2).abs();
	else return getDistancePL(p, s);
}
double getDistance(Segment s1, Segment s2) {
	if (intersect(s1, s2)) return 0;
	return min(min(getDistancePS(s2.p1, s1), getDistancePS(s2.p2, s1)), min(getDistancePS(s1.p1, s2), getDistancePS(s1.p2, s2)));
}
Point getCrossPoint(Segment s1, Segment s2) {
	Vector base = s2.p2 - s2.p1;
	double d1 = fabs(cross(base, s1.p1 - s2.p1)), d2 = fabs(cross(base, s1.p2 - s2.p1));
	double t = d1 / (d1 + d2);
	return s1.p1 + (s1.p2 - s1.p1) * t;
} 
int main() {
    int q; 
    scanf("%d", &q);
    while (q--) {
    	double x0, y0, x1, y1;
    	scanf("%lf%lf%lf%lf", &x0, &y0, &x1, &y1);
    	Segment s1 = Segment(Point(x0, y0), Point(x1, y1));
    	scanf("%lf%lf%lf%lf", &x0, &y0, &x1, &y1);
    	Segment s2 = Segment(Point(x0, y0), Point(x1, y1));
    	Point ans = getCrossPoint(s1, s2);
    	printf("%.010lf %.010lf\n", ans.x, ans.y);
	}
	return 0;
}
