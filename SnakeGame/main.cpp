#include <GL/glut.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

int index=0;

void init();
void timerCallback(int);
void displayCallback();
void reshapeCallback(GLsizei w, GLsizei h);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	// Basic Setup
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Snake Game");
	// Callback Functions
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutTimerFunc(0, timerCallback, 0);
	// Initializer Screen
	init();
	// Keeps the Screen Running
	glutMainLoop();
}

void displayCallback() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	glRectd(index, 20, index+2, 22);
	index++;

	if (index > 40) {
		index = 0;
	}

	glutSwapBuffers();
}

void reshapeCallback(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timerCallback(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timerCallback, 0);
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);
}
