#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const double EPS = 1e-10;
const int COUNTER_CLOCKWISE = 1, CLOCKWISE = -1, ONLINE_BACK = 2, ONLINE_FRONT = -2, ON_SEGMENT = 0;
const int IN = 2, ON = 1, OUT = 0;
const int BOTTOM = 0, LEFT = 1, RIGHT = 2, TOP = 3;
const int MAXN = 1e5 + 7;
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
struct EndPoint {
	Point p;
	int seg, st;
	EndPoint() {}
	EndPoint(Point p, int seg, int st) :p(p), seg(seg), st(st) {}
	bool operator < (const EndPoint& rhs) const {
		if (p.y == rhs.p.y) return st < rhs.st;
		else return p.y < rhs.p.y;
	}
};
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
int contains(Point p, Polygon g) {
	int n = g.size();
	bool flag = false;
	for (int i = 0; i < n; i++) {
		Vector a = g[i] - p, b = g[(i + 1) % n] - p;
		if (fabs(cross(a, b)) < EPS && dot(a, b) < EPS) return ON;
		if (a.y > b.y) swap(a, b);
		if (a.y < EPS && b.y > EPS && cross(a, b) > EPS) flag = !flag;
	}
	return flag ? IN : OUT;
}
Polygon andrewScan(Polygon s) {
	int n = s.size();
	if (n < 3) return s;
	Polygon u, l;
	sort(s.begin(), s.end());
	u.push_back(s[0]);
	u.push_back(s[1]);
	l.push_back(s[n - 1]);
	l.push_back(s[n - 2]);
	for (int i = 2; i < n; i++) {
		for (int j = u.size(); j >= 2 && ccw(u[j - 2], u[j - 1], s[i]) == COUNTER_CLOCKWISE; j--) {
			u.pop_back();
		}
		u.push_back(s[i]);
	}
	for (int i = n - 3; i >= 0; i--) {
		for (int j = l.size(); j >= 2 && ccw(l[j - 2], l[j - 1], s[i]) == COUNTER_CLOCKWISE; j--) {
			l.pop_back();
		}
		l.push_back(s[i]);
	}
	reverse(l.begin(), l.end());
	for (int i = u.size() - 2; i >= 1; i--) {
		l.push_back(u[i]);
	}
	return l;
}
EndPoint EP[2 * MAXN];
int manhattanIntersection(vector<Segment> s) {
	int n = s.size();
	for (int i = 0, k = 0; i < n; i++) {
		if (s[i].p1.y == s[i].p2.y) {
			if (s[i].p1.x > s[i].p2.x) swap(s[i].p1, s[i].p2);
		}
		else if (s[i].p1.y > s[i].p2.y) swap(s[i].p1, s[i].p2);
		if (s[i].p1.y == s[i].p2.y) {
			EP[k++] = EndPoint(s[i].p1, i, LEFT);
			EP[k++] = EndPoint(s[i].p2, i, RIGHT);
		}
		else {
			EP[k++] = EndPoint(s[i].p1, i, BOTTOM);
			EP[k++] = EndPoint(s[i].p2, i, TOP);
		}
	}
	sort(EP, EP + 2 * n);
	set<int> BT;
	BT.insert(1e9 + 7);
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (EP[i].st == TOP) BT.erase(EP[i].p.x);
		else if (EP[i].st == BOTTOM) BT.insert(EP[i].p.x);
		else if (EP[i].st == LEFT) {
			set<int> :: iterator b = BT.lower_bound(s[EP[i].seg].p1.x), e = BT.upper_bound(s[EP[i].seg].p2.x);
			cnt += distance(b, e);
		}
	}
	return cnt;
}
int main() {
    
	return 0;
}
