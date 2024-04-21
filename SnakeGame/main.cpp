#include <GL/glut.h>

void init();
void displayCallback();
void reshapeCallback(int w, int h);

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
	// Initializer Screen
	init();
	// Keeps the Screen Running
	glutMainLoop();
}

void displayCallback() {
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void reshapeCallback(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}
