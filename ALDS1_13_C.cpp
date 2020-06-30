#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int LIMIT = 45;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int limit;
int MDT[16][16];
struct Puzzle {
	int st[16];
	int space, MD;
} in, cur;
int getAllMD(Puzzle p) {
	int sum = 0;
	for (int i = 0; i < 16; i++) {
		if (p.st[i] == 16) continue;
		sum += MDT[i][p.st[i] - 1];
	}
	return sum;
}
bool dfs(int dep, int prev) {
	if (cur.MD == 0) return true;
	if (dep + cur.MD > limit) return false;
	int sx = cur.space / 4, sy = cur.space % 4;
	Puzzle tmp;
	for (int i = 0; i < 4; i++) {
		int tx = sx + dx[i], ty = sy + dy[i];
		if (tx < 0 || ty < 0 || tx >= 4 || ty >= 4) continue;
		if (abs(i - prev) == 2) continue;
		tmp = cur;
		cur.MD -= MDT[tx * 4 + ty][cur.st[tx * 4 + ty] - 1];
		cur.MD += MDT[sx * 4 + sy][cur.st[tx * 4 + ty] - 1];
		swap(cur.st[tx * 4 + ty], cur.st[sx * 4 + sy]);
		cur.space = tx * 4 + ty;
		if (dfs(dep + 1, i)) return true;
		cur = tmp;
	}
	return false;
}
int iterative_deepening() {
	in.MD = getAllMD(in);
	for (limit = in.MD; limit <= LIMIT; limit++) {
		cur = in;
		if (dfs(0, 10)) return limit;
	}
}
int main() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			MDT[i][j] = abs(i / 4 - j / 4) + abs(i % 4 - j % 4);
		}
	}
    for (int i = 0; i < 16; i++) {
    	scanf("%d", &in.st[i]);
    	if (in.st[i] == 0) {
    		in.space = i;
    		in.st[i] = 16;
		}
	}
	printf("%d\n", iterative_deepening());
	return 0;
}
