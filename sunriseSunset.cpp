
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<cmath>

using namespace std;

void display();
void reshape(int, int);
void timer(int);

void init()
{
	glClearColor(0.3, 0.0, 0.9, 1.0);
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(200, 100);
	glutInitWindowSize(1000, 1000);

	glutCreateWindow("Window 1");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	init();

	glutMainLoop();

	//return 0;
}

float X_position = -10.0;
float Y_position = -2.0;

float r = 1;
float g = 0.2;
float b = 0;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	float theta;

	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
		for (int i = 0; i < 360; i++) {

		theta = i*3.142/180;

		glVertex2f(X_position + 1.5*cos(theta), Y_position + 1.5*sin(theta));
}
	glEnd();

	float theta2;
	glBegin(GL_POLYGON);
	glColor3f(0.5, 1, 0.2);
	for (int i = 0; i < 360; i++) {

		theta2 = i * 3.142 / 180;

		glVertex2f(-7 + 7 * cos(theta2), -8 + 5 * sin(theta2));
	}
	glEnd();

	float theta4;
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.6, 0.2);
	for (int i = 0; i < 360; i++) {

		theta4 = i * 3.142 / 180;

		glVertex2f(7 + 7 * cos(theta4), -4 + 5 * sin(theta4));
	}
	glEnd();

	float theta3;
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.2);
	for (int i = 0; i < 360; i++) {

		theta3 = i * 3.142 / 180;

		glVertex2f(2 + 7 * cos(theta3), -9 + 5 * sin(theta3));
	}
	glEnd();


	glutSwapBuffers();
	//glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	if (X_position < 10) {
		X_position += 0.01;
	}

	if (X_position > -4 && X_position < 1) {
		//r -= 0.005;
		g += 0.007;
	}
	if(X_position > 1){
		r += 0.015;
		g -= 0.01;
	}

	float theta5;
	if (X_position < 0) {
		for (int i = 90+50; i < 180+60; i++) {
			theta5 = i * 3.142 / 180;
		}
		Y_position = Y_position - 0.01 * sin(theta5);
	}
	if (X_position > 0) {
		for (int i = 90 + 50; i < 180 + 60; i++) {
			theta5 = i * 3.142 / 180;
		}
		Y_position = Y_position + 0.014 * sin(theta5);
	}
}
