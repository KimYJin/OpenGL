
#include <glut.h>
#include<stdlib.h >	
#include<time.h>

static int delay = 1; //0.001s

void init();
void display();
void timer(int );

float x, y, xinc, yinc;

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
	gluOrtho2D(0.0, 50.0, 0.0, 60.0);	// 도화지 크기. set 2D coordinates (left, right, bottom, top)
	glClear(GL_COLOR_BUFFER_BIT); // clear background here

	// get random position.
	x = rand() % 50;
	y = rand() % 60;

	// -0.1 <= xinc,yinc <= 0.1 
	xinc = (rand() % 2) / 10 - 0.1;
	yinc = (rand() % 2) / 10 - 0.1;

}

void display()
{
	glColor3f(x / 50, y / 60, 0);

	glBegin(GL_POINTS);

	glVertex2f(x, y);
	
	if (x+xinc < 0 || x + xinc > 50)
		xinc = -xinc;
	else if(y+yinc < 0 || y + yinc > 60)
		yinc = -yinc;
	
	x += xinc;	y += yinc;


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


