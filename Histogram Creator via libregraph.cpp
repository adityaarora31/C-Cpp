#include<iostream>
#include<cstdlib>
#include "graphics.h"
#define MAXARR 10
using namespace std;

class Shapes
{

public:

  static int xtop,ytop,xbottom,ybottom;

  void makeline();

  static void bar2d(int a,int b,int c,int d)
  {

    xbottom=xbottom+170;
    ybottom=d;
    xtop=xbottom-100;
    ytop=ybottom-b;
    bar(xtop,ytop,xbottom,ybottom);

  }
};


void Shapes::makeline()
{
  outtextxy(50,10,"X");
  outtextxy(700,410,"Y");
  outtextxy(50,410,"(0,0)");
  outtextxy(150,430,"Bar Graph");
  line(50,410,50,10);
  line(50,410,700,410);

}


int Shapes :: xtop = 0;
int Shapes :: ytop = 0 ;
int Shapes :: xbottom = 0;
int Shapes :: ybottom = 0;


int main(int argc, char *argv[])
{
  int gdriver,gmode;
  int items,i;
  int itemvalues[MAXARR];
  gdriver = VGA;
  gmode=VGAMAX;
  initgraph(&gdriver,&gmode,NULL);
  Shapes obj[5];
  Shapes line;
  printf("Enter the number of items (MAX -> 4) \n");
  scanf("%d", &items);
  printf("Enter the items one by one \n");
  for(i=0;i<items;i++)
  {
    scanf("%d",&itemvalues[i]);
  }
  cleardevice();
  line.makeline();
  for(int j=0;j<items;j++)
  {
  obj[j].bar2d(0,itemvalues[j],0,400);
  }



  getch();
	getchar();
  closegraph();
  return (0);
}
