
#include <glut.h>
#include<stdlib.h >	
#include<time.h>

static int delay = 1; //0.001s

void init();
void display();
void timer(int);

float x[3], y[3], xinc[3], yinc[3];

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog03: Bouncing pixel");

	glutDisplayFunc(display);

	//////////////
	glutTimerFunc(delay, timer, 0); //// set timer function which is called for each delay (ms) 

	init();
	glutMainLoop();
	return 0;
}

void init()
{
	srand(time(0)); // initialize seed for rand() (stdlib, time)

	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);	// 도화지 크기. set 2D coordinates (left, right, bottom, top)
	//glClear(GL_COLOR_BUFFER_BIT); // clear background here

	
	for (int i = 0; i < 3; i++)
	{
		x[i] = rand() % 50;
		y[i] = rand() % 50;

		// -0.1 <= xinc,yinc <= 0.1 
		xinc[i] = (rand() % 2) / 10 - 0.1;
		yinc[i] = (rand() % 2) / 10 - 0.1;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clear background here
	glColor3f(x[0] / 50, y[0] / 50, 0);

	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 3; i++)
	{
		glVertex2f(x[i], y[i]);

		if (x[i] + xinc[i] < 0 || x[i] + xinc[i] > 50)
			xinc[i] = -xinc[i];
		else if (y[i] + yinc[i] < 0 || y[i] + yinc[i] > 50)
			yinc[i] = -yinc[i];

		x[i] += xinc[i];	y[i] += yinc[i];

	}

	glEnd(); // finish polygon

	glFlush(); // finish any remaining drawings
}

void timer(int t)
{
	// glutPostRedisplay function is called to 'redraw graphics'
	// glutTimerFunc function is called to set timer function again

	glutPostRedisplay(); // redraw graphics (rather than calling display() itself)
	glutTimerFunc(delay, timer, t); // set timer function again
}


