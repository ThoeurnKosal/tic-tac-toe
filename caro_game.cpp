#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#define num 5
#define PL2 COLOR(255,0,0)//red
#define PL1 COLOR(0,0,255)//blue
#define PL3 COLOR(28,255,85)//white green
#define PL4 COLOR(193,0,193)//sky
#define PL5 COLOR (255,0,128)//pink
#define PL6 COLOR (0,0,0)//black
#define PL7 COLOR (40,148,255)//pen
int player=0;
int board[700][500];
int I,J,a,b;
int x1, y1, x2, y2;
void resetboard()
{
   for(int i=0;i<500;i++)
   for(int j=0;j<700;j++)
   board[j][i]=0;
}
void gamecaro()
{
    const int DELAY = 50;
    int x, y;
    int c;
    settextstyle(0,0,2);
    do
    {
      c=0;
      clearmouseclick(WM_LBUTTONDOWN);
       while (!ismouseclick(WM_LBUTTONDOWN))
       delay(DELAY);
      getmouseclick(WM_LBUTTONDOWN, x, y);
      for(int j=110;j<480;j+=25)
      {
         for(int i=110;i<685;i+=25)
         {
            if((x>i && x<i+25)&&(y>j && y<j+25))
            if(board[i][j]!=2 && board[i][j]!=1)
            {
               setcolor((player==0)?PL1:PL2);//set color X and O
               (player==0)?outtextxy(i+5,j+5,"X"):outtextxy(i+5,j+5,"O");
               board[i][j]=(player==0)?1:2;
               player=(player==0)?1:0; //click for player X and then click for Player O
               c=1;
               PlaySound(TEXT("clickt.wav"), NULL, SND_ASYNC|SND_FILENAME);//sound when click
               break;
            }

        }
        if(c==1)
        break;
    }

    printf("%d",getpixel(118,126));
    for(I=0 ; I<15 ; I++){
    for (J=0 ; J<23 ; J++){
        if (getpixel(118+25*J,126+25*I)==PL1){
            x1 = 122+25*J;
            y1 = 122+25*I;
            for ( a=1;a<=num-1;a++){
                if (getpixel(118+25*J+25*a,126+25*I)!=PL1) break;
            }
                if (a==num){
                    x2 = 122+25*J+25*(a-1);
                    y2 = 122+25*I;
                    break;
                }
                for ( a=1;a<=num-1;a++){
                    if (getpixel(118+25*J,126+25*I+25*a)!=PL1)break;
                }
                    if (a==num){
                        x2 = 122+25*J;
                        y2 = 122+25*I+25*(a-1);
                        break;
                    }
                for ( a=1,b=1;a<=num-1,b<=num-1;a++,b++){
                    if (getpixel(118+25*J+25*a,126+25*I+b*25)!=PL1)break;
                }
                    if (a==num){
                        x2 = 122+25*J+25*(a-1);
                        y2 = 122+25*I+(b-1)*25;
                        break;
                    }
                for ( a=1,b=1;a<=num-1,b<=num-1;a++,b++){
                    if (getpixel(118+25*J-25*a,126+25*I+b*25)!=PL1)break;
                }
                    if (a==num){
                        x2 = 122+25*J-25*(a-1);
                        y2 = 122+25*I+(b-1)*25;
                        break;
                    }
            }

            else if (getpixel(118+25*J,126+25*I)==PL2){
                x1 = 122+25*J;
                y1 = 122+25*I;
                for ( a=1;a<=num-1;a++){
                    if (getpixel(118+25*J+25*a,126+25*I)!=PL2) break;
                }
                    if (a==num){
                        x2 = 122+25*J+25*(a-1);
                        y2 = 122+25*I;
                        break;
                    }
                for ( a=1;a<=num-1;a++){
                    if (getpixel(118+25*J,126+25*I+25*a)!=PL2)break;
                }
                    if (a==num){
                        x2 = 122+25*J;
                        y2 = 122+25*I+25*(a-1);
                        break;
                    }
                for ( a=1,b=1;a<=num-1,b<=num-1;a++,b++){
                    if (getpixel(118+25*J+25*a,126+25*I+b*25)!=PL2)break;
                }
                    if (a==num){
                        x2 = 122+25*J+25*(a-1);
                        y2 = 122+25*I+(b-1)*25;
                        break;
                    }
                for ( a=1,b=1;a<=num-1,b<=num-1;a++,b++){
                    if (getpixel(118+25*J-25*a,126+25*I+b*25)!=PL2)break;
                }
                    if (a==num){
                        x2 = 122+25*J-25*(a-1);
                        y2 = 122+25*I+(b-1)*25;
                        break;
                    }
            }
        }
        if(a==num) break;
        }
        printf("\na=%d\n",a);
        if(a==num) break;
    }while(1);
    a = 0;
    line(x1,y1,x2,y2);
    settextstyle(9,0,11);
    outtextxy(110,90,"''Press  Any  Key  To  Play  Again''");
    if(getpixel(118+25*J,126+25*I)==PL2) outtextxy(110,70,"''Player  O  Win  This  Game''");
    else outtextxy(110,70,"''Player  X  Win  This  Game''");
    PlaySound(TEXT("win.wav"), NULL, SND_ASYNC|SND_FILENAME);//sound when win
}
int main()
{
    int n=1;
    int a=0;
    initwindow(800,600,"CARO GAME",350,10);//WINDOW 800x600
    setactivepage(1);
    setvisualpage(1);
    setbkcolor(WHITE);
    setcolor(RED);
    do{
        while(n==1){
        readimagefile("bk.jpg",0,0,800,600);
        if(ismouseclick(WM_LBUTTONDOWN)){
            if((mousex()>305&&mousex()<498)&&(mousey()>135&&mousey()<195)){
                n=2;
            }
            if((mousex()>305&&mousex()<498)&&(mousey()>260&&mousey()<305)){
                n=3;
            }
                if((mousex()>305&&mousex()<498)&&(mousey()>360&&mousey()<412)){
                n=4;
            }
                if((mousex()>305&&mousex()<498)&&(mousey()>470&&mousey()<530)){
                n=5;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        }
        if(n==2) break;
            while (n==3){
            readimagefile("HELP.jpg",0,0,800,600);
            if(ismouseclick(WM_LBUTTONDOWN)){
                if((mousex()>305&&mousex()<495)&&(mousey()>505&&mousey()<550)){
                    n=1; clearmouseclick(WM_LBUTTONDOWN); continue;
                }
            }
         }

        while (n==4){
               readimagefile("ABOUT.jpg",0,0,800,600);
               if(ismouseclick(WM_LBUTTONDOWN)){
                if((mousex()>300&&mousex()<500)&&(mousey()>480&&mousey()<530)){
                n=1; clearmouseclick(WM_LBUTTONDOWN); continue;
            }
            }
        }
        while (n==5){
            readimagefile("exit.jpg",0,0,800,600);
            if(ismouseclick(WM_LBUTTONDOWN)){
                if((mousex()>100&&mousex()<255)&&(mousey()>420&&mousey()<470)){
                    exit(1);
                }

                if(ismouseclick(WM_LBUTTONDOWN)){
                    if((mousex()>540&&mousex()<695)&&(mousey()>420&&mousey()<470)){
                        n=1; clearmouseclick(WM_LBUTTONDOWN); continue;

                    }
                }
            }
        }
    }while(1);

    PlaySound(TEXT("slogan.wav"), NULL, SND_ASYNC|SND_FILENAME);
    setactivepage(1);

    while(n=2){
        cleardevice();
        settextstyle(0,0,3);  //Style for text
        setcolor(PL3);  //text color
        outtextxy(180,15,"Welcome To The Game");  //on the screen do x,y  x=180 y=20
        setcolor(PL4);
        outtextxy(165,45,"Game For Two Players");
        setcolor(PL6);
        for(int i=0;i<600;i+=25)
        line(110+i,485,110+i,110);
        for(int i=0;i<400;i+=25)
        line(110,110+i,685,110+i);//board
        settextstyle(0,0,5);
        setcolor(PL5);
        outtextxy(208,500,"Good Luck!");
        settextstyle(0,0,5);
        setcolor(PL7);
        outtextxy(208,540,"Thank You!");
        gamecaro();
        clearmouseclick(WM_LBUTTONUP);
        while(!ismouseclick(WM_LBUTTONUP)){getch();}
        clearmouseclick(WM_LBUTTONUP);
        for(int j=110;j<480;j+=25){
            for(int i=110;i<685;i+=25){
                board[i][j] = 0;
            }
        }
    }
    getch();
    closegraph();
    return 0 ;

}
