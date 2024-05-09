#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int x,y,height=30,width=30,gameover,flag,i,j;

void setup()
{
  gameover=0;
  x=height/2;
  y=width/2;
}

void draw () 
{
  system("cls");
  for (i=0;i<height;i++)
  {
    for (j = 0; j<width; j++)
    {
      if (i==0 || i == width -1 || j == 0 || j == height -1)
      {
        printf("#");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void input ()
{
  if (kbhit())
  {
    switch(getch())
    {
      case 'a':
        flag=1;
        break;
      case 's':
        flag=2;
        break;
      case 'd':
        flag=3;
        break;
      case 'w':
        flag=4;
        break;
      case 'x':
        gameover=1;
        break;
    }
  }
}

void logic() 
{ 
  Sleep(0.1);
  switch (flag) { 
  case 1: 
      y--; 
      break; 
  case 2: 
      x++; 
      break; 
  case 3: 
      y++; 
      break; 
  case 4: 
      x--; 
      break; 
  default: 
      break; 
  }
  if (x<0)
    x++;
  if (x>width)
    x--;
  if (y<0)
    y++;
  if (y>height)
    y--;
}

int main()
{
  setup();
  while (!gameover)
  {
  draw();
  input();
  logic();
  }
}