#include <cstdio>
#include <cmath>
using namespace std;
const double PI=acos(-1);
int n;
void koch (int cur,double p1x,double p1y,double p2x,double p2y) {
	if (cur==n) return;
	double sx,sy,ux,uy,tx,ty;
	sx=(2*p1x+p2x)/3;
	sy=(2*p1y+p2y)/3;
	tx=(p1x+2*p2x)/3;
	ty=(p1y+2*p2y)/3;
	ux=(tx-sx)*cos(PI/3)-(ty-sy)*sin(PI/3)+sx;
	uy=(tx-sx)*sin(PI/3)+(ty-sy)*cos(PI/3)+sy;
	koch (++cur,p1x,p1y,sx,sy);
	printf ("%.8lf %.8lf\n",sx,sy);
	koch (cur,sx,sy,ux,uy);
	printf ("%.8lf %.8lf\n",ux,uy);
	koch (cur,ux,uy,tx,ty);
	printf ("%.8lf %.8lf\n",tx,ty);
	koch (cur,tx,ty,p2x,p2y);
}
int main () {
	scanf ("%d",&n);
	printf ("0.00000000 0.00000000\n");
	koch (0,0,0,100,0);
	printf ("100.00000000 0.00000000\n");
    return 0;
}
