#include <GL/glut.h>

void init();
void displayCallback();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	// Basic Setup
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Snake Game");
	// Callback Functions
	glutDisplayFunc(displayCallback);
	// Initializer Screen
	init();
	// Keeps the Screen Running
	glutMainLoop();
}

void displayCallback() {
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}
