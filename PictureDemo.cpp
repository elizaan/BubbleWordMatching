# include "iGraphics.h"
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# define widdth 10
# define scrnwdth 1280
# define scrnht 600

void Snakemove();
void snakeinitialize();

FILE *fpl,*fps,*fpcamp;
int game=3,size=50,i,state=0,speed =10,used=0,end=0,spd=150,mazeno=0,level=3,signal=2,foodeaten=0,j=0,p=0,z;
char name[50]="snigdho";
char str[100],str1[100], str2[100];
int n=4,randm=234,exfood=0,extime,prsnttime,temppp=0;
int foodx=640,foody=300,exfoodx,exfoody;
int x[6000],y[6000],len;//x y hocche snake er body r protita square er left bottom corner er co-ordinate


struct highscore{//structure to save highscore classic mode
		int lvl;
		int score;
		char player[50];
	} hgh[5],hghd[5];

void highscorefit(int levelnow,int scorenow,char *player){//update highscore after game

	FILE *fphigh,*fpcamp;
	int po;

	fphigh=fopen("highscores.txt","r");
	for(po=0;po<3;po++){
		fscanf(fphigh,"%d %d %s",&(hgh[po].lvl),&(hgh[po].score),hgh[po].player);
	}

	fclose(fphigh);

	fphigh=fopen("highscores.txt","w");

	for(po=0;po<3;po++){
		if(hgh[po].lvl==levelnow){
			if(hgh[po].score<scorenow){
				hgh[po].score=scorenow;
				strcpy(hgh[po].player,player);
			}
		}
			fprintf(fphigh,"%d %d %s\n",hgh[po].lvl,hgh[po].score,hgh[po].player);
	}

	fclose(fphigh);
	
}

void hsreturn(){//read classic highscore
	FILE *fphigh;
	int a,b;
	char player[50];
	fphigh=fopen("highscores.txt","r");
	for(i=0;i<3;i++){
		fscanf(fphigh,"%d%d%s",&(hghd[i].lvl),&(hghd[i].score),hghd[i].player);
	}
	fclose(fphigh);

}
/*void loadgame(){//load the whole game
	//fflush(stdin);
	temppp=0;
	fpl=fopen("sav2.txt","r");
	if(fpl!=NULL){
	fscanf(fpl,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %s ",&game,&size,&i,&state,&speed,&used,&end,&spd,&mazeno,&level,&signal,&foodeaten,&j,&p,&z,name);
	fscanf(fpl,"%d %d %d %d %d ",&n,&randm,&exfood,&extime,&prsnttime);
	fscanf(fpl,"%d %d %d %d ",&foodx,&foody,&exfoodx,&exfoody);
	game = 0;
	for(i=0;i<size;i++){
		fscanf(fpl,"%d ",&x[i]);
	}
	for(i=0;i<size;i++){
		fscanf(fpl,"%d ",&y[i]);
	}
	}
	if(fpl!=NULL)
	fclose(fpl);
	iResumeTimer(0);
}
*/


void savegame(){//save the whole game if user wishes to
	fps=fopen("sav2.txt","w");
	fprintf(fps,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %s ",game,size,i,state,speed,used,end,spd,mazeno,level,signal,foodeaten,j,p,z,name);
	fprintf(fps,"%d %d %d %d %d ",n,randm,exfood,extime,prsnttime);
	fprintf(fps,"%d %d %d %d ",foodx,foody,exfoodx,exfoody);
	for(i=0;i<size;i++){
		fprintf(fps,"%d ",x[i]);
	}
	for(i=0;i<size;i++){
		fprintf(fps,"%d ",y[i]);
	}
	fclose(fps);
}


void random(){//random number generator for food coordinates
	randm+=491;
	randm%=37983;
}


void statecheck()
{//snake moving update
	int temp,temp1;
	for(i=size-1;i>0;i--)
	{
		x[i]=x[i-1];
		y[i]=y[i-1];
	}

	if(state==0)//snake moving left
	{
		x[0]-=speed;
		if(x[0]<0)
			x[0]=scrnwdth-widdth;
	}

	else if(state==1)//up
	{
		y[0]+=speed;
		if((y[0]+widdth)>scrnht)
			y[0]=0;
	}

	else if(state==2)//down
	{
		y[0]-=speed;
		if(y[0]<0)
			y[0]=scrnht-widdth;
	}

	else if(state==3)//snake moving right
	{
		x[0]+=speed;
		if((x[0]+widdth)>scrnwdth)
			x[0]=0;
	}
	if(z==1){//z=1 campaign, z=0 classic mode play
		if((level==1 && foodeaten==10)||(level==2 && foodeaten==12)||(level==3 && foodeaten==15)){
			temp=p;
			temp1=level;
			snakeinitialize();
			iPauseTimer(0);
			iPauseTimer(1);
			p=temp;
			level=temp1+1;
			game=9;


		}
		}
	Snakemove();
	j++;
	}


void genfood(){//generate normal food
	if(signal == 1){

	srand(time(NULL));
	foodx = ((((rand()*7)+85+randm+21*(int)foodx+56)%(scrnwdth-widdth))/widdth)*widdth;
	foody = ((((rand()*2)+12+randm+65*(int)foody+67)%(scrnht-widdth))/widdth)*widdth;
	for(i=size-1;i>=0;i--)
		if(x[i] == foodx && y[i] == foody){//if food falls in snake body, generate again
			genfood();
		}
	signal = 0;
}
}

void genfood2(){//generate extra food for bonus, comes after eating 5 general food
	if(exfood == 0){
	srand(time(NULL));
	exfoodx = ((((rand()*6)+67+randm+19*(int)exfoodx+67)%(scrnwdth-widdth))/widdth)*widdth;
	exfoody = ((((rand()*9)+23+randm+7*(int)exfoody+10)%(scrnht-widdth))/widdth)*widdth;
	for(i=size-1;i>=0;i--)
		if(x[i] == exfoodx && y[i] == exfoody){//if food falls on body
			genfood2();

		}
		exfood = 1;
	}

}

void drawex(){//draw bonus food, why the color change just play and find out yourself! :p
	static int rr=25,gg=135,bb=210;
	rr+=80;
	rr%=255;
	gg+=40;
	gg%=255;
	bb+=79;
	bb%=255;
	iSetColor(rr,gg,bb);
	iFilledRectangle(exfoodx,exfoody,widdth,widdth);
	iSetColor(0,0,0);
	iRectangle(exfoodx,exfoody,widdth,widdth);
}

void drawfood(){//draw general food
	if(level==1){
		iSetColor(255,0,0);
	}
	else if(level==2){
		iSetColor(255,255,255);
	}
	else if(level==3){
		iSetColor(253,67,53);
	}
	iFilledRectangle(foodx,foody,widdth,widdth);
	iSetColor(0,0,0);
	iRectangle(foodx,foody,widdth,widdth);
}

void inctime(){
	prsnttime+=1;
}

void extrafood(){//determine some variables(how much time bonus food will last) and call drawex

	if(prsnttime >= extime ){
		prsnttime=0;
		exfood=2;
	}
	else{
		if(exfood!=1){
		genfood2();
		}
		drawex();
	}
}


void isdead()
{//check if snake is dead
	for(i=size-1;i>1;i--){//if snake bit itself
		if(x[0]==x[i] && ( y[0] == y[i]))
			end=1;
	}
	if(x[0]== foodx && y[0] == foody){//if snake ate a general food
		if(exfood!=1){
		prsnttime = 0;
		exfood=0;
		}
		foodeaten++;
		signal=1;
		genfood();
		for(i=-1;i<2;i++){//increase size of snake
			x[size+i+1]=x[size+i];
			y[size+i+1]=y[size+i];
		}
		size+=3;

		p+=level*4;	//p is point, increase point
	}


	if(exfood == 1){//if snake ate bonus food
        if(x[0]== exfoodx && y[0] == exfoody){
            p+=10*level*(extime-prsnttime)/extime;
            exfood = 2;
            prsnttime = 0;

        }
	}

}

void mazedead(double mazex[],double mazey[],double mazedx[],double mazedy[]){
	for(i=0;i<mazeno;i++){
		if((x[0]+widdth)>mazex[i] && (x[0]<(mazex[i]+mazedx[i])) && (y[0]+widdth)>mazey[i] && (y[0]<(mazey[i]+mazedy[i])))
			end=1;//if snake hit maze
		if((foodx+widdth)>mazex[i] && (foodx<(mazex[i]+mazedx[i])) && (foody+widdth)>mazey[i] && (foody<(mazey[i]+mazedy[i]))){
			signal = 1;//if normal food fell in maze
			genfood();
		}
		if(exfood == 1){
		if((exfoodx+widdth)>mazex[i] && (exfoodx<(mazex[i]+mazedx[i])) && (exfoody+widdth)>mazey[i] && (exfoody<(mazey[i]+mazedy[i]))){
			exfood=0;//if bonus food fell in maze
			genfood2();

		}

	}
}
}

void scoreshow(){//show score and food eaten in top of screen while playing
	int now,temp=p;
	iShowBMP(scrnwdth-200,scrnht+40,"SCORE.bmp");
	iSetColor(0,0,0);
	iRectangle(scrnwdth-200,scrnht+40,200,40);
	for(i=1;i<=5;i++){
		now=temp%10;
		if(now==0){
		iShowBMP(scrnwdth-40*i,scrnht,"zero.bmp");
		}
		else if(now==1){
			iShowBMP(scrnwdth-40*i,scrnht,"one.bmp");
		}
		else if(now==2){
			iShowBMP(scrnwdth-40*i,scrnht,"two.bmp");
		}
		else if(now==3){
			iShowBMP(scrnwdth-40*i,scrnht,"three.bmp");
		}
		else if(now==4){
			iShowBMP(scrnwdth-40*i,scrnht,"four.bmp");
		}
		else if(now==5){
			iShowBMP(scrnwdth-40*i,scrnht,"five.bmp");
		}
		else if(now==6){
			iShowBMP(scrnwdth-40*i,scrnht,"six.bmp");
		}
		else if(now==7){
			iShowBMP(scrnwdth-40*i,scrnht,"seven.bmp");
		}
		else if(now==8){
			iShowBMP(scrnwdth-40*i,scrnht,"eight.bmp");
		}
		else if(now==9){
			iShowBMP(scrnwdth-40*i,scrnht,"nine.bmp");
		}

		temp=temp/10;

		iSetColor(0,0,0);
		iRectangle(scrnwdth-40*i,scrnht,40,40);
	}
	if(z==0){
		iShowBMP(0,scrnht+40,"foodeaten.bmp");
	}
	iSetColor(0,0,0);
	iRectangle(0,scrnht+40,120,40);
	if(z==0){
		temp=foodeaten;
	}
	else{
		if(level==1){
			temp=10-foodeaten;
		}
		else if(level==2){
			temp=12-foodeaten;
		}
		else if(level==3){
			temp=15-foodeaten;
		}
	}

	for(i=1;i<=3;i++){
		now=temp%10;
		if(now==0){
		iShowBMP(120-40*i,scrnht,"zero.bmp");
		}
		else if(now==1){
			iShowBMP(120-40*i,scrnht,"one.bmp");
		}
		else if(now==2){
			iShowBMP(120-40*i,scrnht,"two.bmp");
		}
		else if(now==3){
			iShowBMP(120-40*i,scrnht,"three.bmp");
		}
		else if(now==4){
			iShowBMP(120-40*i,scrnht,"four.bmp");
		}
		else if(now==5){
			iShowBMP(120-40*i,scrnht,"five.bmp");
		}
		else if(now==6){
			iShowBMP(120-40*i,scrnht,"six.bmp");
		}
		else if(now==7){
			iShowBMP(120-40*i,scrnht,"seven.bmp");
		}
		else if(now==8){
			iShowBMP(120-40*i,scrnht,"eight.bmp");
		}
		else if(now==9){
			iShowBMP(120-40*i,scrnht,"nine.bmp");
		}

		temp=temp/10;

		iSetColor(0,0,0);
		iRectangle(120-40*i,scrnht,40,40);
	}

	iSetColor(247,148,28);
	iFilledRectangle(120,scrnht,scrnwdth-320,80);
}



void Snakemove()
{//draw snake
	if(level==1){
		iSetColor(236,0,140);
	}
	else if(level==2){
	iSetColor(255,0,0);
	}
	else if(level==3){
		iSetColor(97,92,91);
	}
	isdead();

	for(i=size-1;i>=0;i--)
	{
		if(i==0){
				if(level==1){
					iSetColor(6,0,236);
				}
				else if(level==2){
					iSetColor(155,155,0);
				}
				else if(level==3){
					iSetColor(255,0,0);
				}
		}
		iFilledRectangle(x[i],y[i],widdth,widdth);

	}
	iSetColor(0,0,0);
	for(i=size-1;i>=0;i--){
		iRectangle(x[i],y[i],widdth,widdth);
	}
	if(end==1){//if game is over
		 iPauseTimer(0);
		 iPauseTimer(1);
		 game=1;
	}
}


void maze_level_01(){//maze draw level 1
	//iShowBMP(0,0,"mazelevel01.bmp");
	iSetColor(15,211,29);
	iFilledRectangle(0,0,1280,600);
	extime=60;
}

void maze_level_02(){//maze draw level 2
	 double mazex[]={0,0,0,scrnwdth-20};//4 rectangles
	 double mazey[]={0,0,scrnht-20,20};
	 double mazedx[]={scrnwdth,20,scrnwdth-20,20};
	 double mazedy[]={20,scrnht-20,20,scrnht-20};
	 extime = 60;
	 mazeno=4;
	 //iShowBMP(0,0,"mazelevel02.bmp");
	 iSetColor(27,121,211);
	 iFilledRectangle(0,0,1280,600);
	  iSetColor(36,202,13);
	 for(i=0;i<mazeno;i++){
		 iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
	}
	mazedead(mazex,mazey,mazedx,mazedy);
}

void maze_level_03(){//maze draw level 3
	double mazex[]={((scrnwdth/3)),0,scrnwdth/1.5,scrnwdth/2};//4 rectangles
	double mazey[]={scrnht/3,scrnht/6,0,scrnht/1.2};
	double mazedx[]={20,scrnwdth/2,20,scrnwdth/2};
	double mazedy[]={scrnht/1.5,20,scrnht/1.5,20};
	//iShowBMP(0,0,"mazelevel03.bmp");
	iSetColor(254,213,69);
	iFilledRectangle(0,0,1280,600);
	extime = 60;

	mazeno=4;
	iSetColor(42,90,201);
	for(i=0;i<mazeno;i++){
		iFilledRectangle(mazex[i],mazey[i],mazedx[i],mazedy[i]);
	}
	mazedead(mazex,mazey,mazedx,mazedy);
}

void highshow(){//high score classic show
	hsreturn();
	iShowBMP(290,scrnht-160,"halloffame.bmp");
	iSetColor(0,0,0);
	iFilledRectangle(100,80,1150-80,340);
	iSetColor(255,255,0);
	iText(440,320+60,"LEVEL            NAME                           SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
	for(i=0;i<3;i++){
		sprintf(str,"%3d                %-15s                %5d",hghd[i].lvl,hghd[i].player,hghd[i].score);
		iSetColor(255,255,255);
		iText(440,300+80-30*(i+2),str);
	}
}

void snakeinitialize(){//initialize snake in new level/start of game
			temppp=0;
			foodeaten=0;
			p=0;
			for(i=0;i<size;i++){
				x[i]=200+speed*(i);
				y[i]=150;
			}
			size=50;
			state=0;
			speed=10;
			used=0;
			end=0;
			spd=150;
			signal=2;
			randm=234;
			exfood=0;
			iResumeTimer(0);
			iResumeTimer(1);

}

void iDraw()
{//game variable corresponds to each screen view the game can show , e.g. the menu screen, playing screen, high score showing screen etc.
	iClear();
	if(game ==0){// While playing the game
		if(level==1){
			maze_level_01();
		}
		else if(level==2){
			maze_level_02();
		}
		else if(level==3){
			maze_level_03();
		}
		if(foodeaten%5 == 0 && exfood!=2 &&foodeaten!=0){
			extrafood();
		}

		drawfood();
		Snakemove();


		iSetColor(0,0,0);
		iRectangle(0,0,scrnwdth,scrnht);


		scoreshow();
		iSetColor(0,0,0);
		iText(620,640,name,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(game == 1)//Gameover interface
	{
        if(z==0){
			highscorefit(level,p,name);//classic highscore update here
		}
		iClear();
		iShowBMP(0,0,"Gameover.bmp");
		iSetColor(0,0,0);
		iRectangle(0,0,scrnwdth,scrnht);
		scoreshow();
		iShowBMP(0,0,"backtomenu.bmp");
		iShowBMP(980,0,"exit.bmp");
		iSetColor(0,0,0);
		iText(620,640,name,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if ( game == 2)//Pause menu
	{
		iClear();
		iSetColor(255,50,0);
		iFilledRectangle(0,0,scrnwdth,scrnht);
		iShowBMP(scrnwdth/2-150,scrnht/2-150,"Pause.bmp");
		iShowBMP(scrnwdth/2+40-150,scrnht/2-150+32,"pExit.bmp");
		iShowBMP(scrnwdth/2+40-150,scrnht/2-150+98,"Save.bmp");
		iShowBMP(scrnwdth/2+40-150,scrnht/2-150+163,"Resume.bmp");
		scoreshow();
		iSetColor(0,0,0);
		iText(620,640,name,GLUT_BITMAP_TIMES_ROMAN_24);

	}

	else if(game==3){//main menu
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(80,scrnht-150,"name.bmp");
		iShowBMP(40,70,"exit.bmp");
		iShowBMP(40,140,"instructions.bmp");
		iShowBMP(40,210,"highscores.bmp");
		//iShowBMP(40,280,"loadgame.bmp");
		iShowBMP(40,350,"newgame.bmp");
	}

	else if(game == 4){//Instructions
		iShowBMP(0,0,"maininstructions.bmp");
		iShowBMP(0,0,"backtomenu.bmp");
	}

	else if(game==5){//Highscore select mode: classic or campaign
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(490,350,"classic.bmp");
		iShowBMP(0,0,"backtomenu.bmp");
	}
	else if(game==6){//Classic mode select level
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(290,scrnht-160,"selectlevel.bmp");
		iShowBMP(490,210,"level3.bmp");
		iShowBMP(490,280,"level2.bmp");
		iShowBMP(490,350,"level1.bmp");
		iShowBMP(0,0,"back.bmp");
	}
	else if(game==7){//Highscore display
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(0,0,"back.bmp");
		if(z==0){
		highshow();
		}

	}
	else if(game==8){//select mode for new game
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(490,350,"classic.bmp");
		iShowBMP(0,0,"backtomenu.bmp");
	}
	else if(game==9){//Level up display
		iShowBMP(0,0,"levelup.bmp");
		iShowBMP(340,50,"nextlevel.bmp");
	}
	else if(game == 11){//enter your name
		iShowBMP(0,0,"mainmenu.bmp");
		iShowBMP(340,scrnht-150,"entername.bmp");
		iShowBMP(340,150,"pressenter.bmp");
		iSetColor(149,149,149);
		iFilledRectangle(470,295,340,90);
		iSetColor(255, 255, 255);
		iFilledRectangle(490,315,300,50);
		iSetColor(0,0,0);
		iText(510, 335, str1,GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP(0,0,"backtomenu.bmp");
}
}

void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	//pause menu
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(game==2){
			if((mx>=scrnwdth/2-150+40 && mx<=(scrnwdth/2-150+297))){//ei area r moddhe mouse click porle eita koro emne kaj korse
			if(my>=scrnht/2-150+32 && my<= scrnht/2-150+32+52)
				game = 3;
			else if(my>=scrnht/2-150+98 && my<= scrnht/2-150+98+51)
				savegame();
			else if(my>=scrnht/2-150+163 && my<= scrnht/2-150+163+52){
				game = 0;
				iResumeTimer(0);
			}
		}
		}
		else if(game==3){
			if(mx>=40 && mx<=340){
				if(my>=70 && my<=120){
					exit(0);
				}
				else if(my>=140 && my<=190){
					game=4;
				}
				else if(my>=210 && my<=260){
					game=5;
				}
				else if(my>=280 && my<=330){
					//loadgame();
				}
				else if(my>=350 && my<=400){
					game=11;//take name updating
				}
			}
		}
		else if(game == 6){
			snakeinitialize();
			if(mx>=490 && mx<=790){

                if(my>=210 && my<=260){
					level=3;
					game=0;
				}
				else if(my>=280 && my<=330){
					level=2;
					game=0;
				}
				else if(my>=350 && my<=400){
					level=1;
					game=0;
				}
			}
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=8;
			}
		}
		else if(game==1){
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
			else if((mx>= 980 && mx<=1280) && (my>=0 && my<=50)){
				exit(0);
			}
		}

		else if(game==4){
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
		}

		else if(game==5){
			if(mx>=490 && mx<=790){
				if(my>=280 && my<=330){
					z=1;
					game=7;
				}
				else if(my>=350 && my<=400){
					z=0;
					game=7;
				}
			}
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
		}
		else if(game==7){
			if(mx>=0 && mx<=300){
				if(my>=0 && my<=50){
					game=5;
				}
			}
		}

		else if(game==8){
			if(mx>=490 && my<=790){
				if(my>=280 && my<=330){
					//z=1;
					//snakeinitialize();
					//level=1;
					//game=0;
				}
				else if(my>=350 && my<=400){
					z=0;
					game=6;
				}
			}

			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}
		}
		else if(game==9){
			if((mx>=340 && mx<=940) && (my>=50 && my<=100)){
				game=0;
				iResumeTimer(0);
				iResumeTimer(1);
			}
		}
		else if(game==10 || game==11){
			if((mx>=0 && mx<=300) && (my>=0 && my<=50)){
				game=3;
			}

		}

	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}


//1-up,2-down , 3- right,0- left
void iKeyboard(unsigned char key)
{
	if(game==0){// w,a,s,d die snake operate korbe
	if(key == 'a')
	{
		if(state!=3 && state!= 0){
		state=0;
		statecheck();
		isdead();
		}
	}
	else if( key == 'w')
		{

		if(state!=2 && state!=1){
		state = 1;
		statecheck();
		isdead();

		}
	}
	else if( key == 's')
		{
		if(state!=1 && state!=2){
		state = 2;
		statecheck();
		isdead();

	}
	}
	else if( key == 'd')
		{if(state!=0 && state!=3){
		state = 3;
		statecheck();
		isdead();

	}
	}
	if(key == ';' && exfood == 1){
		/*p+=10*level*(extime-prsnttime)/extime;
		exfood = 2;
		prsnttime = 0;*/

	}

	if(key == 'l'){
		//loadgame();
	}
	if(key =='g'){
		savegame();
	}
	if(key == 'p')
	{
		if(game==0){
		iPauseTimer(0);
		game = 2;
		}
	}


	if(key == 'c'){
		prsnttime = 0;
		exfood=0;
		foodeaten++;
		signal=1;
		genfood();
		for(i=-1;i<2;i++){
			x[size+i+1]=x[size+i];
			y[size+i+1]=y[size+i];
		}
		size+=3;
		p+=level*4;
	}
}
	else if(game==2){
	if(key == 'r'){
			game=0;
			iResumeTimer(0);
	}
	}

	else if(game == 11)

	{//enter your name er jnno , normal character hoile seita string e input nibe, enter dile khela shuru, \b ba bckspace marle character delete hbe
        if(key == '\r')
		{
			game = 8;
			strcpy(name,str1);
			for(i = 0; i < len; i++)
				str1[i] = 0;
			len = 0;
		}

		else if(key == '\b'){
			if(len>0)
		{
			str1[len-1]=0;
			len--;
		}
		}

		else
		{
			str1[len] = key;
			len++;
		}
	}

}

void iSpecialKeyboard(unsigned char key)
{
	if(game==0){//up down left right arrow diyeo snake operate korbe

	if(key == GLUT_KEY_UP)
	{
		if(state!=2 && state!=1){
		state = 1;
		i = 1;
		statecheck();
		isdead();

		}
	}
	else if(key== GLUT_KEY_DOWN)
	{
		if(state!=1 && state!=2){
		state = 2;
		i = 1;
		statecheck();
		isdead();
		}
	}
	else if(key== GLUT_KEY_LEFT)
	{
		if(state!=3 && state!= 0){
		state=0;
		statecheck();
		isdead();
		}

	}
	else if(key== GLUT_KEY_RIGHT)
	{
		if(state!=0 && state!=3){
		state = 3;
		i = 1;
		statecheck();
		isdead();
		}
	}
	}
}
int main()
{
	for(i=0;i<size;i++)
	{
		x[i]=200+speed*(i);
		y[i]=150;
	}
	genfood();
	genfood2();
	iSetTimer(60,statecheck);
	iSetTimer(1,random);
	iSetTimer(500,inctime);
	iInitialize(scrnwdth,scrnht+80,"Ultimate Snake Game!");

}