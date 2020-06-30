#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
struct Puzzle {
	int st[9];
	int space, len;
	bool operator < (const Puzzle& rhs) const {
		for (int i = 0; i < 9; i++) {
			if (st[i] == rhs.st[i]) continue;
			return st[i] < rhs.st[i];
		}
		return false;
	}
} in;
bool isTarget(Puzzle p) {
	for (int i = 0; i < 9; i++) {
		if (p.st[i] != i + 1) return false;
	}
	return true;
}
int bfs() {
	queue<Puzzle> q;
	set<Puzzle> s;
	q.push(in);
	s.insert(in);
	while (!q.empty()) {
		Puzzle u = q.front(), v;
		q.pop();
		if (isTarget(u)) return u.len;
		int sx = u.space / 3, sy = u.space % 3;
		for (int i = 0; i < 4; i++) {
			int tx = sx + dx[i], ty = sy + dy[i];
			if (tx < 0 || ty < 0 || tx >= 3 || ty >= 3) continue;
			v = u;
			v.space = tx * 3 + ty;
			v.len++;
			swap(v.st[u.space], v.st[v.space]);
			if (!s.count(v)) {
				s.insert(v);
				q.push(v);
			}
		}
	}
}
int main() {
    for (int i = 0; i < 9; i++) {
    	scanf("%d", &in.st[i]);
    	if (in.st[i] == 0) {
    		in.space = i;
    		in.st[i] = 9;
		}
	}
	in.len = 0;
	printf("%d\n", bfs());
	return 0;
}
