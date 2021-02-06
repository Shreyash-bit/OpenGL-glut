#include<stdio.h>
#include<GL/glut.h>
#include <string.h>
#include <string>
using namespace std;

void bus();
void road();
void signal();
void car();
void car2();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void control();
void helpscreen();
GLint a = 300, b = -300, flag = 0, traffic_regulator = 1, control_keyl, control_keyr;
GLfloat red = 0, blue = 1, green = .3;

GLfloat p = 0, q = 0, r = 0;
//-----------
void* currentfont;

void setFont(void* font)
{
	currentfont = font;
}

void drawstring(float x, float y, float z, string str)
{
	int i;
	glRasterPos3f(x, y, z);

	for (i = 0; i < str.length(); i++)
	{
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(currentfont, str.at(i));
	}
}
void frontscreen(void)
{
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glClearColor(0.15, 0.1, 0.01, 0);/*background for cover page*/
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	drawstring(450.0, 700.0, 0.0, "PUNE INSTITUTE OF TECHNOLOGY ");
	glColor3f(0.7, 0, 1);
	drawstring(330, 650, 0.0, "DEPARTMENT OF COMPUTER ENGINEERING");
	glColor3f(1, 0.5, 0);
	drawstring(530, 600, 0.0, "MINI PROJECT");
	glColor3f(1, 0, 0);
	drawstring(360, 500, 0.0, "---------------------------------------------------");
	glColor3f(1, 0.5, 0);
	drawstring(200, 400, 0.0, "BY:");
	glColor3f(1, 1, 1);
	drawstring(100, 320, 0.0, "CHINMAY AMBEKAR - 21403");
	glColor3f(1, 1, 1);
	drawstring(100, 270, 0.0, "SHREYASH DHANE - 21415");
	glColor3f(1, 1, 1);
	drawstring(100, 200, 0.0, "AKASH CHEKE  - 21411");
	glColor3f(1, 1, 1);
	drawstring(100, 240, 0.0, "ADHISH CHINDHADE - 21412");
	glColor3f(1, 0.1, 1);
	drawstring(700, 300, 0.0, "PRESS ENTER TO START");
	glFlush();
}
void helpscreen()
{
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glClearColor(0, 0, 0, 0);/*background for cover page*/
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	drawstring(550.0, 700.0, 0.0, "TIPS");
	glColor3f(1, 0, 0);
	drawstring(650.0, 700.0, 0.0, "AND");
	glColor3f(0, 0, 1);
	drawstring(750.0, 700.0, 0.0, "TRICKS");
	glColor3f(0.5, 0.1, 0.2);
	drawstring(350.0, 640.0, 0.0, "Stop the traffic (Red Light)                                  MOUSE LEFT CLICK");
	glColor3f(0.5, 0.1, 0.3);
	drawstring(350.0, 540.0, 0.0, "Yellow Signal                                                        MOUSE RIGHT BUTTON (HOLD ON)");
	glColor3f(0.5, 0.1, 0.4);
	drawstring(350.0, 440.0, 0.0, "Green Signal                                                         MOUSE RIGHT BUTTON (RELEASE)");
	glColor3f(0.5, 0.1, 0.7);
	drawstring(350.0, 140.0, 0.0, "Speed up the vehicles                                           PRESS 'S'");
	glColor3f(0.5, 0.1, 0.8);
	drawstring(350.0, 90.0, 0.0, "Help                                                                      PRESS 'H'");
	glColor3f(0.5, 0.1, 0.9);
	drawstring(350.0, 40.0, 0.0, "Escape                                                                  PRESS 'ENTER'");
	glFlush();
}
void control()
{
	if (control_keyl != 'l' || control_keyr != 'r')
	{
		if (control_keyl == 'l')
			a = a + 6;
		if (control_keyr == 'r')
			b = b - 6;
	}

}
void myKeyboard(unsigned char key, int x, int y)

{
	switch (key)
	{
	case 13:
		if (flag == 1)
		{
			flag = 2;
			mydisplay();
		}
		if (flag == 0) //Ascii of 'enter' key is 13
		{
			flag = 1; mydisplay();
		}

		break;
	case 'l':control_keyl = key;
		p = 0; q = 0; r = 1;
		break;
	case 'r':control_keyr = key;
		p = 0; q = 0; r = 1;
		break;
	case 's':mydisplay();
		break;
	case 'h':flag = 1; mydisplay();
		break;
	default:break;
	}

}
void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		traffic_regulator = 0;
		p = 1;
		q = 0;
		r = 0;
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		traffic_regulator = 0;
		p = 0;
		q = 1;
		r = 0;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		traffic_regulator = 1;
		p = 0;
		q = 0;
		r = 1;
	}
	glutPostRedisplay();
}
void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (flag == 0)
		frontscreen();
	if (flag == 1)
		helpscreen();
	if (flag == 2)
		display();
	glutSwapBuffers();
}
void update(int value)
{
	a = a - 6;
	b = b + 6;
	control();
	/*making day to night*/
	if (blue != 0 && green != 0)
	{
		blue -= .004; green -= .004;
	}
	glutPostRedisplay();
}
/////////////////////////////////////--------------------------------------///////////////////////////////////////
void display(void)
{
	if (traffic_regulator)
		glutTimerFunc(50, update, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(red, green, blue, 0);/*back ground for sky*/
	road();
	bus();
	signal();
	car();
	car2();

	glFlush();
}
void road()
{
	glPushMatrix();
	glScaled(40.0, 40.0, 0.0);
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
	//straight road
	glVertex2f(0, 5);
	glVertex2f(40, 5);
	glVertex2f(40, 10);
	glVertex2f(0, 10);
	glEnd();
	//green edge
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.3, 0.1);
	glVertex2f(0, 5);
	glVertex2f(40, 5);
	glVertex2f(40, 4);
	glVertex2f(0, 4);
	glEnd();
	glPopMatrix();
}
void signal()
{
	glPushMatrix();
	glScaled(40.0, 40.0, 0.0);
	//stand
	glColor3f(0.1, 0.2, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(15, 7);
	glVertex2f(15, 8);
	glVertex2f(18, 8);
	glVertex2f(18, 7);
	glEnd();
	//pole
	glBegin(GL_POLYGON);
	glVertex2f(16, 7);
	glVertex2f(17, 8);
	glVertex2f(17, 15);
	glVertex2f(16, 15);
	glEnd();
	//board
	glBegin(GL_POLYGON);
	glVertex2f(15.5, 15);
	glVertex2f(17.5, 15);
	glVertex2f(17.5, 10);
	glVertex2f(15.5, 10);
	glEnd();
	//red
	glColor3f(p, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(16, 14.5);
	glVertex2f(17, 14.5);
	glVertex2f(17, 14);
	glVertex2f(16, 14);
	glEnd();
	//yellow
	glColor3f(q, q, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(16, 13.5);
	glVertex2f(17, 13.5);
	glVertex2f(17, 13);
	glVertex2f(16, 13);
	glEnd();
	//green
	glColor3f(0.0, r, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(16, 12.5);
	glVertex2f(17, 12.5);
	glVertex2f(17, 12);
	glVertex2f(16, 12);
	glEnd();
	glPopMatrix();
}
void bus()
{
	glPushMatrix();
	glTranslated(a, 50.0, 0.0);
	glScaled(40.0, 40.0, 0.0);
	glColor3f(0.5, 0.0, 0.0);
	//bus out line
	glBegin(GL_POLYGON);
	glVertex2f(25, 8);
	glVertex2f(25, 9.5);
	glVertex2f(26, 11);
	glVertex2f(32, 11);
	glVertex2f(32, 8);
	glEnd();
	//window frame
	glColor3f(0, 0.1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(26.1, 9.5);
	glVertex2f(26.1, 10.5);
	glVertex2f(31.8, 10.5);
	glVertex2f(31.8, 9.5);
	glEnd();
	//Doors
	glColor3f(0, 0.8, 1);
	glBegin(GL_POLYGON);
	glVertex2f(26.2, 9);
	glVertex2f(26.2, 10.4);
	glVertex2f(27.7, 10.4);
	glVertex2f(27.7, 9);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(27, 8.4);
	glVertex2f(27, 10.4);
	glVertex2f(27.7, 10.4);
	glVertex2f(27.7, 8.4);
	glEnd();
	//small windows
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(27.8, 9.6);
	glVertex2f(27.8, 10.4);
	glVertex2f(29, 10.4);
	glVertex2f(29, 9.6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(29.1, 9.6);
	glVertex2f(29.1, 10.4);
	glVertex2f(30.2, 10.4);
	glVertex2f(30.2, 9.6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(30.3, 9.6);
	glVertex2f(30.3, 10.4);
	glVertex2f(31.7, 10.4);
	glVertex2f(31.7, 9.6);
	glEnd();

	//driver window
	glColor3f(0, 0.8, 1);
	glBegin(GL_POLYGON);
	glVertex2f(25, 9.5);
	glVertex2f(26, 11);
	glVertex2f(26, 9.5);
	glEnd();
	glPopMatrix();
	//tyre
	glPushMatrix();//front tyre
	glTranslated(a + 970, 320, 0.0);
	glScaled(20.0, 20.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON); //drawing a back tyre
	float theta3;
	for (int i = 0; i < 360; i++) {
		theta3 = i * 3.142 / 180;
		glVertex2f(13 + 2 * cos(theta3), 1.5 + 2 * sin(theta3));
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();//back tyre
	glTranslated(a + 1140, 320, 0.0);
	glScaled(20.0, 20.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON); //drawing front tyre
	float theta2;
	for (int i = 0; i < 360; i++) {
		theta2 = i * 3.142 / 180;
		glVertex2f(-3 + 2 * cos(theta2), 1.5 + 2 * sin(theta2));
	}
	glEnd();
	glPopMatrix();
}

void car()
{
	glPushMatrix(); //making color for outer line
	glTranslated(b, 190.0, 0.0);
	glScaled(20.0, 20.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2.5, 2.5);
	glVertex2f(1, 4);
	glVertex2f(3.4, 7.4);
	glVertex2f(13, 7.4);
	glVertex2f(14, 6);
	glVertex2f(21, 5);
	glVertex2f(21, 2.5);
	glVertex2f(2.5, 2.5);
	glEnd();

	glColor3f(1.0, 1.0, 1.0); //color for outer window
	glBegin(GL_POLYGON);
	glVertex2f(5.0, 5.0);
	glVertex2f(14.0, 5.0);
	glVertex2f(11.5, 6.5);
	glVertex2f(10.5, 6.75);
	glVertex2f(7.0, 6.75);
	glEnd();

	glBegin(GL_LINES); //connecting outer line
	glVertex2d(7.0, 5.0);
	glVertex2d(15.0, 5.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0); //connecting outer line
	glBegin(GL_LINES);
	glVertex2d(12.0, 5.0);
	glVertex2d(12.0, 6.2);
	glEnd();

	glColor3f(0.0, 0.0, 0.0); //connecting outer line
	glBegin(GL_LINES);
	glVertex2d(7.0, 5.0);
	glVertex2d(7.0, 6.7);
	glEnd();

	glBegin(GL_POLYGON); //drawing a back tyre
	float theta2;
	for (int i = 0; i < 360; i++) {
		theta2 = i * 3.142 / 180;
		glVertex2f(3.7 + 2 * cos(theta2), 1.7 + 2 * sin(theta2));
	}
	glEnd();

	glBegin(GL_POLYGON); //drawing front tyre
	float theta3;
	for (int i = 0; i < 360; i++) {
		theta3 = i * 3.142 / 180;
		glVertex2f(18.5 + 2 * cos(theta3), 1.7 + 2 * sin(theta3));
	}
	glEnd();
	glPopMatrix();
}
void car2()
{
	glPushMatrix(); //making color for outer line
	glTranslated(b - 2000, 190.0, 0.0);
	glScaled(20.0, 20.0, 0.0);
	glColor3f(1.0, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(2.5, 2.5);
	glVertex2f(1, 4);
	glVertex2f(3.4, 7.4);
	glVertex2f(13, 7.4);
	glVertex2f(14, 6);
	glVertex2f(21, 5);
	glVertex2f(21, 2.5);
	glVertex2f(2.5, 2.5);
	glEnd();

	glColor3f(1.0, 1.0, 1.0); //color for outer window
	glBegin(GL_POLYGON);
	glVertex2f(5.0, 5.0);
	glVertex2f(14.0, 5.0);
	glVertex2f(11.5, 6.5);
	glVertex2f(10.5, 6.75);
	glVertex2f(7.0, 6.75);
	glEnd();

	glBegin(GL_LINES); //connecting outer line
	glVertex2d(7.0, 5.0);
	glVertex2d(15.0, 5.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0); //connecting outer line
	glBegin(GL_LINES);
	glVertex2d(12.0, 5.0);
	glVertex2d(12.0, 6.2);
	glEnd();

	glColor3f(0.0, 0.0, 0.0); //connecting outer line
	glBegin(GL_LINES);
	glVertex2d(7.0, 5.0);
	glVertex2d(7.0, 6.7);
	glEnd();

	glBegin(GL_POLYGON); //drawing a back tyre
	float theta2;
	for (int i = 0; i < 360; i++) {
		theta2 = i * 3.142 / 180;
		glVertex2f(3.7 + 2 * cos(theta2), 1.7 + 2 * sin(theta2));
	}
	glEnd();

	glBegin(GL_POLYGON); //drawing front tyre
	float theta3;
	for (int i = 0; i < 360; i++) {
		theta3 = i * 3.142 / 180;
		glVertex2f(18.5 + 2 * cos(theta3), 1.7 + 2 * sin(theta3));
	}
	glEnd();
	glPopMatrix();
}
/////////////////////////////////////--------------------------------------/////////////////////////////////////
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1346.0, 0.0, 728.0);
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1346, 728);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MINI PROJECT");

	/*call back functions*/
	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(myMouse);

	myinit();
	glutMainLoop();
}
