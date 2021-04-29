# include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>

int y=0,x1=0,r=0,g=0,b=0,inl=1;
int dx, dy,mx,my;
int letter[30][2];
char sh[30],shcp[30],shcp1[30],sh1[30];
int t=0,tr=0;
int mode=0;
int flag=0;
int pic_x=0, pic_y=0;
int ball;


void rand_num()
{
	int i;
	if(inl==1){
		for(i=0;i<26;i++)
		{
			letter[i][0]=rand()%800;
			letter[i][1]=rand()%15000;
		}
		inl=0;
	}
}


void iDraw()
{


	int i,j;
	char ch[2],sh[2];
	iClear();

	if(mode==0)//firstpage
		iShowBMP(0,0,"sp.bmp");	
	if(mode==1)
		iShowBMP(0,0,"emainmenu.bmp");
	
	if(mode==2)
	{

		iShowBMP(0,0,"l1.bmp");


		iSetColor(175, 237,196);
		iFilledCircle(150,y+150,17);
		iFilledCircle(700,y+50,9);
		iFilledCircle(200,y-50,6);
		iFilledCircle(425,y+150,8);
		iFilledCircle(75,y+250,10);
		iFilledCircle(600,y+75,5);
		iFilledCircle(500,y-80,15);
		iFilledCircle(1000,y+50,10);
		iSetColor(255,255,255);
	

		if(tr!=0)
		{
			iText(950,200,shcp,GLUT_BITMAP_TIMES_ROMAN_24);

		}




		for(i=0;i<26;i++)
		{
		iSetColor(175, 237,196);
		iFilledCircle(letter[i][0],letter[i][1],30);
		iSetColor(128,0,128);
		ch[0]=i+65;
		iText(letter[i][0]-30/3.5,letter[i][1]-30/3.5,ch,GLUT_BITMAP_HELVETICA_18);

		}
	iSetColor(100,0,100);
	iFilledRectangle(950,490,100,35);
	iFilledRectangle(950,390,120,35);
	iFilledRectangle(950,290,80,35);

	iSetColor(255,255,255);
	iText(960,400, "RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(960,500, "PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(960,300, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(mode==3)
	{

		iShowBMP(0,0,"l2.bmp");


		iSetColor(175, 237,196);
		iFilledCircle(150,y+150,17);
		iFilledCircle(700,y+50,9);
		iFilledCircle(200,y-50,6);
		iFilledCircle(425,y+150,8);
		iFilledCircle(75,y+250,10);
		iFilledCircle(600,y+75,5);
		iFilledCircle(500,y-80,15);
		iFilledCircle(1000,y+50,10);
		iSetColor(255,255,255);
	

		if(tr!=0)
		{
			iText(950,200,shcp,GLUT_BITMAP_TIMES_ROMAN_24);

		}




		for(i=0;i<26;i++)
		{
		iSetColor(175, 237,196);
		iFilledCircle(letter[i][0],letter[i][1],30);
		iSetColor(128,0,128);
		ch[0]=i+65;
		iText(letter[i][0]-30/3.5,letter[i][1]-30/3.5,ch,GLUT_BITMAP_HELVETICA_18);

		}
	iSetColor(100,0,100);
	iFilledRectangle(950,490,100,35);
	iFilledRectangle(950,390,120,35);
	iFilledRectangle(950,290,80,35);

	iSetColor(255,255,255);
	iText(960,400, "RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(960,500, "PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(960,300, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(mode==4)
	{

		iShowBMP(0,0,"l3.bmp");


		iSetColor(175, 237,196);
		iFilledCircle(150,y+150,17);
		iFilledCircle(700,y+50,9);
		iFilledCircle(200,y-50,6);
		iFilledCircle(425,y+150,8);
		iFilledCircle(75,y+250,10);
		iFilledCircle(600,y+75,5);
		iFilledCircle(500,y-80,15);
		iFilledCircle(1000,y+50,10);
		iSetColor(255,255,255);
	

		if(tr!=0)
		{
			iText(950,200,shcp,GLUT_BITMAP_TIMES_ROMAN_24);

		}




		for(i=0;i<26;i++)
		{
		iSetColor(175, 237,196);
		iFilledCircle(letter[i][0],letter[i][1],30);
		iSetColor(128,0,128);
		ch[0]=i+65;
		iText(letter[i][0]-30/3.5,letter[i][1]-30/3.5,ch,GLUT_BITMAP_HELVETICA_18);

		}
	iSetColor(100,0,100);
	iFilledRectangle(950,490,100,35);
	iFilledRectangle(950,390,120,35);
	iFilledRectangle(950,290,80,35);

	iSetColor(255,255,255);
	iText(960,400, "RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(960,500, "PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(960,300, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	}

}
void ballChange(){

	int i;

		for(i=0;i<26;i++)
		{


			letter[i][1]+=dy;

		}
		for(i=0;i<26;i++)
		{
			if(letter[i][1]>1020)
			{

			letter[i][1]*=(-.25);
			}
		}
		y+=dy;
		if(y>1020)
			y*=(-.25);


}


void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	
	int i;

	if(mode==0)
	{	if(mx>=0 && mx<=1200 && my>=0 && my<=650)
			mode=1;//mainmenu
	}

	if(mode==1)
	{
		if(mx>=0 && mx<=275 && my>=377 && my<=619)
			mode=2;//level1
		if(mx>=884 && mx<=1056 && my>=436 && my<=299)
			mode=5;//help
		if(mx>=77 && mx<=289 && my>=58 && my<=235)
			mode=6;//settings
		if(mx>=881 && mx<=1178 && my>=28 && my<=217)
			mode=7;//high scores
		
		if(mx>=0 && mx<=1200 && my>=0 && my<=650)
			printf(" %d %d",mx,my);
	}

	if(mode==2)
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
		{
		
			for(i=0; i<26; ++i)
			{
				if(flag==0)
				{
					int temp = (mx-letter[i][0]) * (mx-letter[i][0]) + (my-letter[i][1]) * (my-letter[i][1]) - 30 * 30;
			

            		if(temp <=0)
					{
						letter[i][1] = -250;tr=1;
						sh[t]=i+65;
						strcpy(shcp,sh);
						printf("%s\n",sh);
						t++;
						break;
					}
				}



           
			}
			if(mx>=949 && mx<=1049 && my>=494 && my<=530)

			{
				iPauseTimer(0);

				flag=1;
			}

			if( mx>=949 && mx<=1069 && my>=393 && my<=429)
			{
				iResumeTimer(0);
				flag=0;
			}

			if( mx>=949 && mx<=1029 && my>=292 && my<=327)
			{
				exit(0);
			}

	

			printf("%d %d\n",mx,my);
		}


		

		/*if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && mx>=1000 && mx<=1110 && my>=700 && my<=735)
		{


	
		}*/
	}
}


void iKeyboard(unsigned char key)
{
	

}


void iSpecialKeyboard(unsigned char key)
{

	
	
}



int main()
{

	iSetTimer(5, ballChange);
	iSetTimer(5,rand_num);

	dy = 1;
	iInitialize(1200,650, "Bubble words");


	return 0;
}

