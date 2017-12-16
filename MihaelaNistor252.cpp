/*
*
*
*
*	Nistor Mihaela Grupa 252 CTI
*
*	
*	Nume joc: Masinute
*	Scop: sa ajungi acasa (sus, stanga)
*	Taste :
*		w = sus
*		a = stanga
*		s = jos
*		d = dreapta
*
*		space = stai
*		y = restart joc (doar la finalul unui joc)
*
*		1 = schimba viteza masinilor
*		2 = schimba viteza masinilor
*		3 = schimba viteza masinilor
*
*
*/
#include <GL/freeglut.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

#include <iostream>
using namespace std;

struct Punct 
{

		GLint x, y;
};

int numar_vieti = 6;

void coord();

const double TWO_PI = 6.2831853;

static GLdouble i = 25.0,  j = 25.0;

static GLdouble yy = 0.0 ;

static GLdouble Oy = 0.0;

static GLdouble x1 = 250.0;
static GLdouble x2 = 550.0;
static GLdouble x3 = 300.0;
static GLdouble x4 = 600.0;
static GLdouble x5 = 150.0;
static GLdouble x6 = 500.0;
static GLdouble x7 = 100.0;
static GLdouble x8 = 500.0;
static GLdouble x9 = 250.0;
static GLdouble x10 = 650.0;
static GLdouble x11 = 400.0;
static GLdouble x12 = 720.0;

static GLdouble alpha = 1.1; 

static GLdouble alpha1 =1.2; 
static GLdouble alpha2 = -1.2; 

int dificultate = 2;

double x_mere[] = {500,150,650,400,250,100,440,650};
double y_mere[] = {40,60,180,240,300,485,420,520};

int mar[9];
int nr_mere = 8;
int puncte = 0;
int sfarsit = 0;
int joc_nou = 0;


void glPrintf(int x, int y, char * sir, int lungime)
{
	glColor3f(0,0,0);
	int i1;
	for(i1 = 0; i1 < lungime; i1++)
	{
		glRasterPos2i(x+i1*15, y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, sir[i1]);
	}
}
void init(void) 
{

	glClearColor(1.0, 1.0, 1.0, 0.0);

	gluOrtho2D(0.0, 800.0, 0.0, 600.0);

//	glShadeModel(GL_FLAT);

}
void desen(void)

{

	glClear(GL_COLOR_BUFFER_BIT); 


	Punct hexVertex;
	GLdouble hexTheta;
	GLint k;
	coord();
	switch(dificultate){
	case 1:
		alpha1 = 0.8;
		alpha2 = -0.8;
		break;
	case 2:
		alpha1 = 1.2;
		alpha2 = -1.2;
		break;
	case 3:
		alpha1 = 1.6;
		alpha2 = -1.6;
		break;
	default:
		dificultate = 2;
		alpha1 = 1.2;
		alpha2 = -1.2;
		break;
	}


								//FUNDAL	
	//poligon  gri

	glPolygonMode(GL_FRONT, GL_FILL);

	glBegin(GL_POLYGON);
	
		glColor3f(0.5,0.5,0.5);
		glVertex2i(-20, 60);
		glVertex2i(800, 60);
		glVertex2i(800, 480);
		glVertex2i(-20, 480);


	glEnd();
	//poligoane verzi
	glColor3f(0.4,0.7,0.0);
	
	glBegin(GL_POLYGON);
		glVertex2i(-20,240);
		glVertex2i(800,240);
		glVertex2i(800,300);
		glVertex2i(-20,300);

	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(-20,0);
		glVertex2i(800,0);
		glVertex2i(800,60);
		glVertex2i(-20,60);

	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(-20,480);
		glVertex2i(800,480);
		glVertex2i(800,600);
		glVertex2i(-20,600);

	glEnd();

	//linii cont

	glBegin(GL_LINES);
	
	{
		glColor3f(0.0,0.0,0.0);

		glVertex2i(-20,60);
		glVertex2i(800,60);
		
		glVertex2i(-20,240);
		glVertex2i(800,240);

		glVertex2i(-20,300);
		glVertex2i(800,300);

		glVertex2i(-20,480);
		glVertex2i(800,480);
	}

	glEnd();

	//linii intrerupte
	
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(50,0xAAAA);

	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		
		glVertex2i(-20,120);
		glVertex2i(800,120);
		
		glVertex2i(-20,180);
		glVertex2i(800,180);
		
		glVertex2i(-20,360);
		glVertex2i(800,360);
		
		glVertex2i(-20,420);
		glVertex2i(800,420);

	glEnd();
	glDisable(GL_LINE_STIPPLE);
	//ajutor	
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(735,10);
		glVertex2i(780,10);
		glVertex2i(780,55);
		glVertex2i(735,55);
		
	glEnd();
		glColor3f(1.0,0.0,0.0);
		glRecti(753,19,762,46);
		glRecti(744,28,771,37);
	// atinge patratel ajutor
	if(j+20 >= 735 && i - 20 <= 55)
	{
		alpha = 0;
		j = 713;
		i = 30;
	}
	//dreptunghi informatii
	glColor3f(1.0,1.0,1.0);
		glRecti(-20,550,780,600);


	glColor3f(0.0,0.0,0.0);
	switch(numar_vieti){
	case 0: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
		break;
	case 1: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		break;
	case 2: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		break;
	case 3: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		break;
	case 4: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
		break;
	case 5: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
		break;
	case 6: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '6');
		break;
	case 7: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '7');
		break;
	case 8: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '8');
		break;
	case 9: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '9');
		break;
	case 10: 
		glRasterPos2i(715,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		glRasterPos2i(722,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
		break;
	}

	//inima	
	glPushMatrix();
	Oy = 90;
	glTranslated( 750, 575 , 0.0);
	glScaled(0.6,0.6,0.6);

	glTranslated(-300,-200,0);
		
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);
			glVertex2i(300,210);
			glVertex2i(307,220);
			glVertex2i(320,220);
			glVertex2i(330,210);
			glVertex2i(325,195);
			glColor3f(0.9,0.1,0.0);
			glVertex2i(300,178);
			glVertex2i(275,195);
			glVertex2i(270,210);
			glColor3f(1.0,0.0,0.0);
			glVertex2i(280,220);
			glVertex2i(293,220);
		glEnd();
	

	glPopMatrix();

	glPushMatrix();
	Oy = 90;
	glTranslated( 6, 516 , 0.0);
	glScaled(0.8,0.8,0.8);

	glTranslated(-300,-200,0);
	
	//acoperis casa

	//jos
	glBegin(GL_TRIANGLES);
	glColor3f(0.7,0.4,0.0);
		glVertex2i(270,170);
		glVertex2i(330,170);
	glColor3f(0.5,0.2,0.0);
		glVertex2i(300,200);
	glEnd();

	//dreapta
	glBegin(GL_TRIANGLES);
	glColor3f(0.7,0.4,0.0);
		glVertex2i(330,170);
		glVertex2i(330,230);
	glColor3f(0.5,0.2,0.0);
		glVertex2i(300,200);
	glEnd();

	//sus
	glBegin(GL_TRIANGLES);
	glColor3f(0.7,0.4,0.0);
		glVertex2i(330,230);
		glVertex2i(270,230);
	glColor3f(0.5,0.2,0.0);
		glVertex2i(300,200);
	glEnd();

	//stanga
	glBegin(GL_TRIANGLES);
	glColor3f(0.7,0.4,0.0);
		glVertex2i(270,230);
		glVertex2i(270,170);
	glColor3f(0.5,0.2,0.0);
		glVertex2i(300,200);
	glEnd();

	//copac	
	glPointSize(12);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
		
	glColor3f(0.2,0.5,0.0);
		glVertex2i(340,228 );	
		glVertex2i(345,217 );	
	glColor3f(0.2,0.6,0.0);
		glVertex2i(353,236 );	
		glVertex2i(344,235 );	
	glColor3f(0.2,0.8,0.0);
		glVertex2i(361,224 );	
		glVertex2i(351,225 );	
	glColor3f(0.2,0.5,0.0);
		glVertex2i(361,231 );	
		glVertex2i(352,217 );	

	glEnd();
	glDisable(GL_POINT_SMOOTH);

	glPopMatrix();

	//ajung acasa
	if(i+20 >= 491 && j-20 <= 44)
		{
			j = 64;
			i = 508;
			alpha  = 0.0;
			alpha1 = 0.0;
			alpha2 = 0.0;
			sfarsit = 1;
		}

	//mere

	for(int indice = 0; indice < nr_mere; indice++)
		if(mar[indice] != 1){

			glPushMatrix();
			glTranslated( x_mere[indice], y_mere[indice] , 0.0);
			glScaled(0.5,0.5,0.5);

			glRotated(yy/2, 0.0, 0.0, 1.0);
			glTranslated(-300,-200,0);
		
			glColor3f(1.0,0.0,0.0);
		
			glBegin(GL_POLYGON);
				glVertex2i(300,214);
				glVertex2i(307,220);
				//rosu deschis
				glColor3f(1.0,0.5,0.0);
				glVertex2i(320,220);
				glVertex2i(327,210);
				glVertex2i(323,195);

				glColor3f(1.0,0.0,0.0);
				glVertex2i(315,185);
				glVertex2i(305,185);
				glVertex2i(300,187);
				glVertex2i(295,185);
				//rosu inchis
				glColor3f(0.9,0.1,0.0);
				glVertex2i(285,185);
				glVertex2i(277,195);
				glVertex2i(273,210);

				glColor3f(1.0,0.0,0.0);
				glVertex2i(280,220);
				glVertex2i(293,220);
			glEnd();
	
			glBegin(GL_POLYGON);

				glColor3f(0.4,0.6,0.2);
				glVertex2i(300,208);
				glVertex2i(298,223);

				glColor3f(0.0,1.0,0.0);
				glVertex2i(310,237);
				glVertex2i(310,219);
			
			glEnd();
	

			glPopMatrix();
		
			//conditie atinge mar indice
	if((i+20 >= y_mere[indice] - 18 && i + 20 <= y_mere[indice] + 18) || (i-20 >= y_mere[indice]-18 && i-20 <= y_mere[indice]+18))
		if((j-20 <= x_mere[indice]+27 && j-20 >= x_mere[indice]-27) || (j+20 >= x_mere[indice]-27 && j+20 <= x_mere[indice]+27))
		{
			mar[indice] = 1;
			puncte++;
		}

	
	}


	char sir[] = "Puncte:     din 8 ";
	glPrintf(0,570,sir,strlen(sir));

	switch(puncte){
	case 0: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
		break;
	case 1: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		break;
	case 2: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		break;
	case 3: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		break;
	case 4: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
		break;
	case 5: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
		break;
	case 6: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '6');
		break;
	case 7: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '7');
		break;
	case 8: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '8');
		break;
	case 9: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '9');
		break;
	case 10: 
		glRasterPos2i(130,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		glRasterPos2i(142,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
		break;
	}
	
	char dif[] = "Dificultate:";
	glPrintf(300,570,dif,strlen(dif));	
	switch(dificultate){
	case 1: 
		glColor3f(0.0,1.0,0.0);
		glRasterPos2i(480,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

		glColor3f(0.0,0.0,0.0);
		glRasterPos2i(510,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

		glRasterPos2i(540,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		break;
	case 2: 
		glColor3f(0.0,0.0,0.0);
		glRasterPos2i(480,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

		glColor3f(0.0,1.0,0.0);
		glRasterPos2i(510,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

		glColor3f(0.0,0.0,0.0);
		glRasterPos2i(540,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		break;
	case 3: 
		glColor3f(0.0,0.0,0.0);
		glRasterPos2i(480,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

		glColor3f(0.0,0.0,0.0);
		glRasterPos2i(510,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

		glColor3f(0.0,1.0,0.0);
		glRasterPos2i(540,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		break;
	default:
		dificultate = 2; 
		glColor3f(0.0,0.0,0.0);
		glRasterPos2i(480,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

		glColor3f(0.0,1.0,0.0);
		glRasterPos2i(510,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

		glColor3f(0.0,0.0,0.0);
		glRasterPos2i(540,570);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		break;
	}
	/////////////////////////////////////////////////////MASINUTE/////////////////////////////////////////////////////////

	glLineWidth(6.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			//CORP 1

	glPushMatrix();
	Oy = 90;
	glTranslated( x1, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(0.0,0.4,0.2);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();


	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x1+35 && j-20 >= x1-35) || (j+20 >= x1-35 && j+20 <= x1+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}

			//CORP 2


	glPushMatrix();
	Oy = 90;
	glTranslated( x2, Oy, 0.0);

	glScaled(0.5,0.5,0.5);


	glTranslated(-300,-200,0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(1.0,1.0,0.2);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,0.5,0.0);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();


	if((i+20 > Oy - 20 && i + 20 < Oy + 20) || (i-20 > Oy-20 && i-20 < Oy+20))
	{
		if((j-20 < x2+35 && j-20 > x2-35) || (j+20 > x2-35 && j+20 < x2+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}
	}
		//CORP 3

	glPushMatrix();
	Oy = 150;
	glTranslated(x3, Oy , 0.0);

	glScaled(0.5,0.5,0.5);


	glTranslated(-300,-200,0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(1.0,0.6,0.3);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta		
	glBegin(GL_POLYGON);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);


	glPopMatrix();
	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x3+35 && j-20 >= x3-35) || (j+20 >= x3-35 && j+20 <= x3+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}

			//CORP 4

	glPushMatrix();
	Oy = 150;
	glTranslated( x4, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(0.0,0.3,0.7);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();


	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x4+35 && j-20 >= x4-35) || (j+20 >= x4-35 && j+20 <= x4+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}
			//CORP 5

	glPushMatrix();
	Oy = 210;
	glTranslated( x5,Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(0.6,0.0,0.4);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();

	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x5+35 && j-20 >= x5-35) || (j+20 >= x5-35 && j+20 <= x5+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}

			//CORP 6

	glPushMatrix();
	Oy = 210;
	glTranslated( x6, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(1.0,0.2,0.3);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();

	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x6+35 && j-20 >= x6-35) || (j+20 >= x6-35 && j+20 <= x6+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}


			//CORP 7

	glPushMatrix();
	Oy = 330;
	glTranslated( x7, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(1.0,1.0,0.1);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,0.5,0.0);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();


	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x7+35 && j-20 >= x7-35) || (j+20 >= x7-35 && j+20 <= x7+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}
			//CORP 8

	glPushMatrix();
	Oy = 330;
	glTranslated( x8, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(0.2,0.8,0.0);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();

	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x8+35 && j-20 >= x8-35) || (j+20 >= x8-35 && j+20 <= x8+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}
			//CORP 9

	glPushMatrix();
	Oy = 390;
	glTranslated( x9, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(0.3,0.2,1.0);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();

	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x9+35 && j-20 >= x9-35) || (j+20 >= x9-35 && j+20 <= x9+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}

			//CORP 10

	glPushMatrix();
	Oy = 390;
	glTranslated( x10, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(1.0,0.5,0.0);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();

	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x10+35 && j-20 >= x10-35) || (j+20 >= x10-35 && j+20 <= x10+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}

			//CORP 11

	glPushMatrix();
	Oy = 450;
	glTranslated( x11, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(0.7,0.0,0.7);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();
	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x11+35 && j-20 >= x11-35) || (j+20 >= x11-35 && j+20 <= x11+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}


			//CORP 12

	glPushMatrix();
	Oy = 450;
	glTranslated( x12, Oy , 0.0);
	glScaled(0.5,0.5,0.5);

	glTranslated(-300,-200,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//masina
	glBegin(GL_POLYGON);

		glColor3f(0.9,0.1,0.0);
		glVertex2i(230,160);
		glVertex2i(370,160);
		glVertex2i(370,240);
		glVertex2i(230,240);

	glEnd();

	//geam stanga	
	glBegin(GL_POLYGON);
		
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,170);
		glColor3f(0.6,0.9,0.9);
		glVertex2i(260,185);
		glVertex2i(260,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(240,230);

	glEnd();

	//geam dreapta	
	glBegin(GL_POLYGON);

		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,170);
		glColor3f(0.6,0.9,0.9);
	      	glVertex2i(340,185);
      		glVertex2i(340,215);
		glColor3f(0.4,0.4,1.0);
		glVertex2i(360,230);

	glEnd();

	//faruri

	glColor3f(1.0,1.0,0.2);

	glRecti(230,160,235,170);
	glRecti(230,230,235,240);
	glRecti(365,160,370,170);
	glRecti(365,230,370,240);



	glPopMatrix();

	if((i+20 >= Oy - 20 && i + 20 <= Oy + 20) || (i-20 >= Oy-20 && i-20 <= Oy+20))
		if((j-20 <= x12+35 && j-20 >= x12-35) || (j+20 >= x12-35 && j+20 <= x12+35))
		{
			j = 713;
			i = 30;
			alpha  = 0.0;
			numar_vieti--;
		}

	if(numar_vieti == 0)
	{
		sfarsit = 1;
		alpha = 0.0;
		alpha1 = 0.0;
		alpha2 = 0.0;
	}

	

	////////////////////////////////////////////////////////jucator///////////////////////////////////////////////




	glPushMatrix();

	glTranslated(j, i, 0.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	
	//interior cos
	glBegin (GL_POLYGON);
		glColor3f(0.9, 0.1, 0.0);
		glVertex2i(-20,0);
	
		glColor3f(1.0, 0.4, 0.4);
		glVertex2i(20,0);

		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(20,20);

		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(-20,20);
	
	glEnd ( );
	//exterior cos
	glLineWidth(5);
	glColor3f(0.9, 0.5, 0.1);

	glBegin (GL_LINE_LOOP);
		glVertex2i(-19,0);
		glVertex2i(19,0);
		glVertex2i(19,19);
		glVertex2i(-19,19);
	glEnd ( );

	//omuleti
	glColor3f(0.7, 0.2, 1.0);
		glBegin (GL_POLYGON);
		for (k=0; k < 50; k++)
		{
			hexTheta = TWO_PI * k / 50;
			hexVertex.x = -11 + 7 * cos (hexTheta);
			hexVertex.y = -13 + 7 * sin (hexTheta);
			glVertex2i (hexVertex.x, hexVertex.y);
		}
		glEnd ( );
	glColor3f(1.0, 0.5, 0.0);
		glBegin (GL_POLYGON);
		for (k=0; k < 50; k++)
		{
			hexTheta = TWO_PI * k / 50;
			hexVertex.x = 11 + 7 * cos (hexTheta);
			hexVertex.y = -13 + 7 * sin (hexTheta);
			glVertex2i (hexVertex.x, hexVertex.y);
		}
		glEnd ( );
	//maini
	glColor3f(1.0,0.9,0.5);
	glLineWidth(4);	

	glBegin(GL_LINES);
		glVertex2i(-7,-8);
		glVertex2i(-4, 1);
		
		glVertex2i(-15,-8);
		glVertex2i(-16, 1);

		glColor3f(0.5,0.3,0.2);
		glVertex2i(7,-8);
		glVertex2i(4, 1);

		glVertex2i(15,-8);
		glVertex2i(16, 1);


	glEnd();	
	glPopMatrix();


char pierdut[] = "Ai murit!";
char castigat[] = "Ai ajuns acasa!";
char reincepe[] = "Restart joc: tasta y ";
	if(sfarsit == 1)
	{
		//dreptunghi
		glBegin(GL_POLYGON);
			glColor3f(1.0,0.9,0.8);
			glVertex2i(200,200);
			glColor3f(0.8,0.9,1.0);
			glVertex2i(560,200);
			glColor3f(1.0,0.9,0.8);
			glVertex2i(560,400);
			glColor3f(0.7,1.0,0.6);
			glVertex2i(200,400);
		glEnd();
		//contur
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(200,200);
			glVertex2i(560,200);
			glVertex2i(560,400);
			glVertex2i(200,400);

		glEnd();
		if(numar_vieti == 0)
		{
			glPrintf(320,350,pierdut,strlen(pierdut));		

		}
		else
		{
			glPrintf(270,350,castigat,strlen(castigat));
			
		}
		
			glPrintf(240,320,reincepe,strlen(reincepe));
			if(joc_nou == 1)
			{
				joc_nou = 0;
				sfarsit = 0;
				for(int h = 0; h < nr_mere; h++)
					mar[h] = 0;
				alpha1 = 1.2;
				alpha2 = -1.2;
				i = 25;
				j = 25;
				numar_vieti = 6;
				dificultate = 2;
				puncte = 0;
				glutPostRedisplay();
			}
	
	}
	glutSwapBuffers();
	glFlush();

}


void reshape(int w, int h)

{

	glViewport(0, 0,(GLsizei) w,(GLsizei) h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-20.0, 780.0, 0.0, 600.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

}
void coord()
{
//alpha 1 = +1 (dreapta)
//alpha 2 = -1 (stanga)

	x1 = x1 + alpha2;
	x2 = x2 + alpha2;
	x3 = x3 + alpha1;
	x4 = x4 + alpha1;
	x5 = x5 + alpha2;
	x6 = x6 + alpha2;
	x7 = x7 + alpha1;
	x8 = x8 + alpha1;
	x9 = x9 + alpha2;
	x10 = x10 + alpha2;
	x11 = x11 + alpha1;
	x12 = x12 + alpha1;




	if(x1 > 820.0)
		x1 = -40.0;

	else if(x1 < -40.0)
		x1 = 820.0;

	if(x2 > 820.0)
		x2 = -40.0;

	else if(x2 < -40.0)
		x2 = 820.0;

	if(x3 > 820.0)
		x3 = -40.0;

	else if(x3 < -40.0)
		x3 = 820.0;
	
	if(x4 > 820.0)
		x4 = -40.0;

	else if(x4 < -40.0)
		x4 = 820.0;

	if(x5 > 820.0)
		x5 = -40.0;

	else if(x5 < -40.0)
		x5 = 820.0;

	if(x6 > 820.0)
		x6 = -40.0;

	else if(x6 < -40.0)
		x6 = 820.0;

	if(x7 > 820.0)
		x7 = -40.0;

	else if(x7 < -40.0)
		x7 = 820.0;

	if(x8 > 820.0)
		x8 = -40.0;

	else if(x8 < -40.0)
		x8 = 820.0;

	if(x9 > 820.0)
		x9 = -40.0;

	else if(x9 < -40.0)
		x9 = 820.0;

	if(x10 > 820.0)
		x10 = -40.0;

	else if(x10 < -40.0)
		x10 = 820.0;

	if(x11 > 820.0)
		x11 = -40.0;

	else if(x11 < -40.0)
		x11 = 820.0;

	if(x12 > 820.0)
		x12 = -40.0;

	else if(x12 < -40.0)
		x12 = 820.0;
	yy++;
	if(yy == 720)
		yy = 0;
//	yy = yy-10;


	glutPostRedisplay();


}
void jos(void)
{

	i = i + alpha;

	if(i > 580.0)
		alpha = -1.1;

	else if(i < 20.0)
		alpha = 1.1;


	glutPostRedisplay();

}

void sus(void)
{   

	i = i + alpha;

	if(i < 20.0)
		alpha = 1.1;

	else if(i > 530.0)
		alpha = -1.1;

	glutPostRedisplay();

}

void dreapta(void)
{

	j = j + alpha;

	if(j > 760.0)
		alpha = -1.1;

	else if(j < 0.0)
		alpha = 1.1;

	glutPostRedisplay();

}

void stanga(void)
{   

	j = j + alpha;

	if(j < 0.0)
		alpha = 1.1;

	else if(j > 760.0)
		alpha = -1.1;

	glutPostRedisplay();

}
void tasten(unsigned char key, int xmouse, int ymouse)
{	
	switch(key){
		case 'a':
			alpha = -1.1; glutIdleFunc(stanga);
			break;

		case 'w':
			alpha = 1.1; glutIdleFunc(sus);
			break;

		case 's':
			alpha = -1.1; glutIdleFunc(jos);
			break;

		case 'd': 
			alpha = 1.1; glutIdleFunc(dreapta);
			break;
		case 32: 
			alpha = 0.0; 	glutPostRedisplay();
			break;

		case 'y':
			if(sfarsit == 1)
				joc_nou = 1;
			break;

		case 'n':
			joc_nou = 0;
			break;
		case '1':
			dificultate = 1;
			break;
		case '2':
			dificultate = 2;
			break;
		case '3':
			dificultate = 3;
			break;

		default:
			break;
	}
}





int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(1000, 800); 

	glutInitWindowPosition(100, 100);

	glutCreateWindow("Masinute");

	init();

	glutDisplayFunc(desen); 

	glutReshapeFunc(reshape); 
	glutKeyboardFunc(tasten);

	glutMainLoop();
	return 0;
}
