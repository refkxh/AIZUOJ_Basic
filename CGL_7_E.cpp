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
pair<Point, Point> getCrossPoints(Line l, Circle c) {
	Point pr = project(c.c, l);
	Vector e = (l.p2 - l.p1) * (1 / (l.p2 - l.p1).abs());
	double base = sqrt(c.r * c.r - (pr - c.c).norm());
	if (e.x > EPS || (fabs(e.x) < EPS && e.y > EPS)) return make_pair(pr - e * base, pr + e * base);
	else return make_pair(pr + e * base, pr - e * base);
}
double arg(Vector v) {
	return atan2(v.y, v.x);
}
Vector polar(double r, double theta) {
	return Vector(r * cos(theta), r * sin(theta));
}
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
	double d = (c1.c - c2.c).abs(), phi = acos((c1.r * c1.r + d * d - c2.r * c2.r) * (1 / (2 * c1.r * d)));
	double theta = arg(c2.c - c1.c);
	if (polar(c1.r, theta + phi).x > polar(c1.r, theta - phi).x || (equals(polar(c1.r, theta + phi).x, polar(c1.r, theta - phi).x) && polar(c1.r, theta + phi).y > polar(c1.r, theta - phi).y)) return make_pair(c1.c + polar(c1.r, theta - phi), c1.c + polar(c1.r, theta + phi));
	else return make_pair(c1.c + polar(c1.r, theta + phi), c1.c + polar(c1.r, theta - phi));
}
int main() {
    int x, y, r;
    scanf("%d%d%d", &x, &y, &r);
    Circle c1 = Circle(Point(x, y), r);
    scanf("%d%d%d", &x, &y, &r);
    Circle c2 = Circle(Point(x, y), r);
    pair<Point, Point> ans = getCrossPoints(c1, c2);
    printf("%.08lf %.08lf %.08lf %.08lf\n", ans.first.x, ans.first.y, ans.second.x, ans.second.y);
	return 0;
}
