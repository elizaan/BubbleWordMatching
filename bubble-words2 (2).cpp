# include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>

bool musicOn=1,oo=1;
int x=0, y=0,r=0,g=0,b=0,inl=1,w;
float dx, dy,mx,my,dy1,dy2;
int letter[30][2];
int scr=0;
char sh[20],shcp[20],shcp1[30],sh1[30];

int t=0,tr=0,cup=0,cgo=0;
int mode=0;
int flag=0,flag1=0,flag2=0,flag3=1,flag4=0;
int soundon=1;
int pic_x=0, pic_y=0;
int ball;

/*
	function iDraw() is called again and again by the system.

*/
void rand_num()
{
    int i;
    if(inl==1)
    {
        for(i=0; i<26; i++)
        {
            letter[i][0]=rand()%910;
            letter[i][1]=rand()%5000;
        }
        inl=0;
    }
}
void score(int score)
{
    FILE *fp;
    char str[100];

    char file[]="highscore.txt";
    int sum=0;
    fp=fopen("highscore.txt","w");
    if (fp==NULL)
		printf("CAN not creat file.\n");
    else
    {
        sum=sum+score;
        fprintf(fp,"%d",sum);
        sprintf(str,"%d",sum);
        fclose(fp);
    }

    return ;
}


void iDraw()
{
    //place your drawing codes here

    int i,j,w=1100;
    char ch[2],sh[2];

    iClear();

	if(mode==0)//firstpage
	{
		iShowBMP(0,0,"sp.bmp");	
		iSetColor(255,255,255);
		iFilledRectangle(50,30,w,20);


	}
	if(mode==1)
		iShowBMP(0,0,"emainmenu.bmp");
	if(mode==43){
		iShowBMP(0,0,"143.bmp");
		char my_str[100];
			score(scr);
			FILE *fp;
			fp=fopen("highscore.txt","r");
			fscanf(fp,"%s",my_str);
			fclose(fp);
			iSetColor(136,0,21);
			iText(830,220,my_str,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mode==33){
		iShowBMP(0,0,"go.bmp");
		iSetColor(255,255,255);
		iText(990,585,"Back to Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(mode==5)
	{
		iShowBMP(0,0,"help.bmp");
		iSetColor(255,128,64);
		iText(346,54,"Back to Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if(mode==6)
	{
		iShowBMP(0,0,"settings.bmp");
		iSetColor(255,128,64);
		iText(346,54,"Back to Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	



    if(mode==2)
	{
		iShowBMP(0,0,"l1.bmp");


		 iSetColor(175, 237,196);
         iFilledCircle(x=150,y+150,17);
         iFilledCircle(x=700,y+50,9);
         iFilledCircle(x=200,y-50,6);
         iFilledCircle(x=425,y+150,8);
         iFilledCircle(x=75,y+250,10);
         iFilledCircle(x=600,y+75,5);
         iFilledCircle(x=500,y-80,15);
         iFilledCircle(x=1000,y+50,10);
         iSetColor(128,0,128);

         if(tr!=0)
		 {
			iText(950,200,shcp,GLUT_BITMAP_TIMES_ROMAN_24);

		 }




		if(flag2==1)
		{
			//printf("entrs\n");
			char my_str[100];
			score(scr);
			FILE *fp;
			fp=fopen("highscore.txt","r");
			fscanf(fp,"%s",my_str);
			fclose(fp);
			iText(955,105,my_str,GLUT_BITMAP_TIMES_ROMAN_24);
		}



		for(i=0; i<26; i++)
		{
			iSetColor(175, 237,196);
			iFilledCircle(letter[i][0],letter[i][1],30);
			iSetColor(128,0,128);
			ch[0]=i+65;
			ch[1]=0;
			iText(letter[i][0]-30/3.5,letter[i][1]-30/3.5,ch,GLUT_BITMAP_HELVETICA_18);

		}



		iSetColor(255,128,128);
		iFilledRectangle(950,490,100,35);
		iFilledRectangle(950,390,120,35);
		iFilledRectangle(950,290,80,35);



		iSetColor(255, 255, 255);
		iText(960,400, "RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(960,500, "PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(960,300, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(955,160,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(950,100,90,35);

		if(flag4!=0)
		{
			iSetColor(166, 0, 0);
			iLine(1050,135,1070,105);
			iLine(1070,135,1050,105);
			iText(1080,120, "wrong word",GLUT_BITMAP_TIMES_ROMAN_24);

		}

	}

	if(mode==3)
	{
		iShowBMP(0,0,"l2.bmp");


		 iSetColor(175, 237,196);
         iFilledCircle(x=150,y+150,17);
         iFilledCircle(x=700,y+50,9);
         iFilledCircle(x=200,y-50,6);
         iFilledCircle(x=425,y+150,8);
         iFilledCircle(x=75,y+250,10);
         iFilledCircle(x=600,y+75,5);
         iFilledCircle(x=500,y-80,15);
         iFilledCircle(x=1000,y+50,10);
         iSetColor(128,0,128);

         if(tr!=0)
		 {
			iText(950,200,shcp,GLUT_BITMAP_TIMES_ROMAN_24);

		 }




		if(flag2==1)
		{
			//printf("entrs\n");
			char my_str[100];
			score(scr);
			FILE *fp;
			fp=fopen("highscore.txt","r");
			fscanf(fp,"%s",my_str);
			fclose(fp);
			iText(955,105,my_str,GLUT_BITMAP_TIMES_ROMAN_24);
		}



		for(i=0; i<26; i++)
		{
			iSetColor(175, 237,196);
			iFilledCircle(letter[i][0],letter[i][1],30);
			iSetColor(128,0,128);
			ch[0]=i+65;
			ch[1]=0;
			iText(letter[i][0]-30/3.5,letter[i][1]-30/3.5,ch,GLUT_BITMAP_HELVETICA_18);

		}



		iSetColor(255,128,128);
		iFilledRectangle(950,490,100,35);
		iFilledRectangle(950,390,120,35);
		iFilledRectangle(950,290,80,35);



		iSetColor(255, 255, 255);
		iText(960,400, "RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(960,500, "PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(960,300, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(955,160,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(950,100,90,35);

		if(flag4!=0)
		{
			iSetColor(166, 0, 0);
			iLine(1050,135,1070,105);
			iLine(1070,135,1050,105);
			iText(1080,120, "wrong word",GLUT_BITMAP_TIMES_ROMAN_24);

		}


	}

	if(mode==4)
	{
		iShowBMP(0,0,"l3.bmp");


		 iSetColor(175, 237,196);
         iFilledCircle(x=150,y+150,17);
         iFilledCircle(x=700,y+50,9);
         iFilledCircle(x=200,y-50,6);
         iFilledCircle(x=425,y+150,8);
         iFilledCircle(x=75,y+250,10);
         iFilledCircle(x=600,y+75,5);
         iFilledCircle(x=500,y-80,15);
         iFilledCircle(x=1000,y+50,10);
         iSetColor(128,0,128);

         if(tr!=0)
		 {
			iText(950,200,shcp,GLUT_BITMAP_TIMES_ROMAN_24);

		 }




		if(flag2==1)
		{
			//printf("entrs\n");
			char my_str[100];
			score(scr);
			FILE *fp;
			fp=fopen("highscore.txt","r");
			fscanf(fp,"%s",my_str);
			fclose(fp);
			iText(955,105,my_str,GLUT_BITMAP_TIMES_ROMAN_24);
		}



		for(i=0; i<26; i++)
		{
			iSetColor(175, 237,196);
			iFilledCircle(letter[i][0],letter[i][1],30);
			iSetColor(128,0,128);
			ch[0]=i+65;
			ch[1]=0;
			iText(letter[i][0]-30/3.5,letter[i][1]-30/3.5,ch,GLUT_BITMAP_HELVETICA_18);

		}



		iSetColor(255,128,128);
		iFilledRectangle(950,490,100,35);
		iFilledRectangle(950,390,120,35);
		iFilledRectangle(950,290,80,35);



		iSetColor(255, 255, 255);
		iText(960,400, "RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(960,500, "PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(960,300, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(955,160,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(950,100,90,35);

		if(flag4!=0)
		{
			iSetColor(166, 0, 0);
			iLine(1050,135,1070,105);
			iLine(1070,135,1050,105);
			iText(1080,120, "wrong word",GLUT_BITMAP_TIMES_ROMAN_24);

		}

	}
    
}

void readword()
{
	int flag3=1;

	//printf("fun get csalld\n");
    FILE *pf;
    char line[100],sh[100];

    pf=fopen("new_dic.txt","r");
    if(pf==NULL)
    {
        printf("Unable to open the file.\n");
    }
    else
    {
    	int cnt = 0;
        while(!feof(pf))
        {
        	//printf("rte-%d\n", ++cnt);
            fgets(line,80,pf);

            line[strlen(line) - 1] = 0;
            //printf("[%s] - [%s]\n", line, shcp);
            if(strcmp(line,shcp) == 0)
            {
				flag3=0;
				cup++;

				if(strlen(shcp)==2)
				{
					scr=scr+1;
					score(scr);
					flag2=1;
					flag1=0;
				}

                if(strlen(shcp)==3)
                {
                    scr=scr+5;
                    score(scr);
                    flag2=1;
                    flag1=0;
                }
                if(strlen(shcp)==5)
                {
                    scr=scr+15;
                    score(scr);
                    flag1=0;
                    flag2=1;
                }
                if(strlen(shcp)==4)
                {
                    scr=scr+10;
                    score(scr);
                    flag1=0;
                    flag2=1;
                }
                if(strlen(shcp)==6)
                {
                    scr=scr+20;
                    score(scr);
                    flag1=0;
                    flag2=1;
                }
                if(strlen(shcp)==7)
                {
                    scr=scr+25;
                    score(scr);
                    flag1=0;
                    flag2=1;
                }
                if(strlen(shcp)==8)
                {
                    scr=scr+30;
                    score(scr);
                    flag1=0;
                    flag2=1;
                }
                if(strlen(shcp)==9)
                {
                    scr=scr+35;
                    score(scr);
                    flag1=0;
                    flag2=1;
                }
                if(strlen(shcp)==10)
                {
                    scr=scr+40;
                    score(scr);
                    flag1=0;
                    flag2=1;
                }
                if(strlen(shcp)==11)
                {
                    scr=scr+45;
                    score(scr);
                    flag1=0;
                    flag2=1;
					
                }
				if(strlen(shcp)==12)
                {
                    scr=scr+50;
                    score(scr);
                    flag1=0;
                    flag2=1;
					
                }
                

			
				break;

            }

			
		
        }
        fclose(pf);
			
				
		if(flag3==1)
		{
			cgo++;
			oo=0;
			if(oo==0)
				PlaySoundA("4.wav",NULL,SND_ASYNC);
			
			printf("\n%d\n",cgo);
			scr=scr+0;
            score(scr);
            flag1=0;
            flag2=1;
			flag4=1;
				
		}
		else
			flag3=1;
				
				
			

    }
		printf("%d %d",cgo,cup);
		if(cgo>=3 && flag3==1)
			mode=33;
		else if(cup== 6 && cgo<3){
			mode=3;
			cgo=0;}
		else if(cup== 14 && cgo<3){
			mode=4;
			cgo=0;}
		else if(cup== 24 && cgo<3){
			mode=43;
			cgo=0;}

		/*else
			mode=2;*/

	

}
void mm()
{
	int i;
	if(mode==0)
		w-=5;
	if(w<=0)
	{
		mode=1;
		w+=100000;

	}
	


}
void ballChange()
{

    int i;

   if(mode==2)
   {
	    for(i=0; i<26; i++)
		{


			letter[i][1]+=dy;

		}
		for(i=0; i<26; i++)
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
   if(mode==3)
   {
	    for(i=0; i<26; i++)
		{


			letter[i][1]+=dy1;

		}
		for(i=0; i<26; i++)
		{
			if(letter[i][1]>1020)
			{

				letter[i][1]*=(-.25);
			}
		}
    y+=dy1;
    if(y>1020)
        y*=(-.25);
   }
   if(mode==4)
   {
	    for(i=0; i<26; i++)
		{


			letter[i][1]+=dy2;

		}
		for(i=0; i<26; i++)
		{
			if(letter[i][1]>1020)
			{

				letter[i][1]*=(-.25);
			}
		}
    y+=dy2;
    if(y>1020)
        y*=(-.25);
   }




}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.

*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    	int i;
		flag4=0;

		if(mx>=0 && mx<=1200 && my>=0 && my<=650 )
			printf("%d% d ",mx,my);
		//if(mx>=0 && mx<=1200 && my>=0 && my<=650 && mode==0)
			//mode=1;//mainmenu
	    if(mx>=0 && mx<=275 && my>=377 && my<=619 && mode==1 && mode!=0)
			mode=2;//level1
		if(mx>=915 && mx<=1010 && my>=340 && my<=390 && mode==1)
			mode=5;//help
		if(mx>=615 && mx<=695 && my>=234 && my<=264 && mode==6){
			musicOn=1;
			if(musicOn==1)
				PlaySound("1.wav",NULL,SND_LOOP | SND_ASYNC);


		}
		
		if(mx>=615 && mx<=695 && my>=180 && my<=215 && mode==6){
			oo=2;
			musicOn=0;
			if(musicOn==0)
				PlaySound(0,0,0);
			
		}
		if(mx>=881 && mx<=1178 && my>=28 && my<=217 && mode==1)
			exit(0);//quitgame
		if(mx>=980 && mx<=980+230 && my>=580 && my<=580+50 && mode==33)
		{
			mode=1;
			cgo=0;
			cup=0;
			scr=0;
		}
		if(mx>=345 && mx<=560 && my>=54&& my<=84 && mode==5)
		{
			mode=1;
			cgo=0;
			cup=0;
			scr=0;
		}
		if(mx>=345 && mx<=560 && my>=54&& my<=84 && mode==6)
		{
			mode=1;
			cgo=0;
			cup=0;
			scr=0;
		}
			
		//if(mx>=1060 && mx<=(1060+80) && my>=290 && my<=(290+50) && mode==1)
			//exit(0);//quitgame

		if(mode==2 || mode==3 || mode==4)
		{
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
			{
				flag3=0;
				//checking for letter match
				for(i=0; i<26; ++i)
				{
					if(flag==0)
					{
						int temp = (mx-letter[i][0]) * (mx-letter[i][0]) + (my-letter[i][1]) * (my-letter[i][1]) - 30 * 30;
				

            			if(temp <=0)
						{
							letter[i][1] = -250;tr=1;
							sh[t]=i+65;
							if(strlen(sh)>12) 
							{
								flag4=1;
								break;
							}
							strcpy(shcp,sh);
							//printf("%s\n",sh);
							t++;
							break;
						}
					}


					// character string generatex
           
				}
				if(mx>=949 && mx<=1049 && my>=494 && my<=530)

				{
					musicOn=0;
					if(musicOn==0)
						PlaySound(0,0,0);
					iPauseTimer(0);

					flag=1;
				}

				if( mx>=949 && mx<=1069 && my>=393 && my<=429)
				{
					musicOn=1;
					if(musicOn==1)
						PlaySound("1.wav",NULL,SND_LOOP | SND_ASYNC);
					iResumeTimer(0);
					flag=0;
				}

				if( mx>=949 && mx<=1029 && my>=292 && my<=327)
				{
					mode=1;
				}

		

				//printf("%d %d\n",mx,my);
			}


			

			/*if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && mx>=1000 && mx<=1110 && my>=700 && my<=735)
			{


		
			}*/
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'p')
    {
        //do something with 'q'
		musicOn=0;
		if(musicOn==0)
			 PlaySound(0,0,0);
        iPauseTimer(0);
        flag=1;
    }
    if(key == 'r')
    {
		musicOn=1;
		if(musicOn==1)
			PlaySound("1.wav",NULL,SND_LOOP | SND_ASYNC);
        iResumeTimer(0);
		soundon=1;
    }
    if(key == '\b')
    {
        if(t > 0) t--;
        sh[t] = 0;
        strcpy(shcp, sh);
    }
    if(key=='\r' && flag1==0)
    {
        readword();
		int i;
		
		for(i=0;sh[i]!='\0';i++)
			sh[i]='\0';
		t=0;

		strcpy(shcp,sh);
	
		
		

    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
}



int main()
{
    sh[0] = 0;
    //place your own initialization codes here.
    iSetTimer(1, ballChange);
    iSetTimer(5,rand_num);
	iSetTimer(2000, mm);


	dy=2;
	dy1=4;
	dy2=6;
	if(musicOn==1)
		PlaySound("1.wav",NULL,SND_LOOP | SND_ASYNC);

    iInitialize(1200,650, "Bubble words");
	

    return 0;
}

