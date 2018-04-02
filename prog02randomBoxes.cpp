/*
Draw filled boxes randomly
Generate six random values, x1, y1, x2, y2, r, g, b
Box is drawn from (x1, y1) to (x2, y2) with color (r, g, b)
To visualize progress, box is drawn for each 0.1s
*/

#include <glut.h>
#include<stdlib.h >	
#include<time.h>

static int delay = 100; // milliseconds // 0.1초

void init();
void display();
void timer(int );

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog02: Random boxes");

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
	glClear(GL_COLOR_BUFFER_BIT); // clear background here
}

void display()
{
	int x1, y1, x2, y2, r, g, b;

	// get random position. (0~49 의 범위 안에서 랜덤하게 받기)
	x1 = rand() % 50; 
	y1 = rand() % 50; 
	x2 = rand() % 50; 
	y2 = rand() % 50; 


	// get random color. RGB 각각의 값을 0~255(8비트) 안에서 받기. (0.0.0)이면 검정색, (255.255.255)이면 흰색
	r = rand() % 256; 
	g = rand() % 256; 
	b = rand() % 256; 

	// set color. 
	// 255로 나눠서 정수값이 아닌 실수값으로 줌. (RGB 각 값을 0이상 1이하의 값으로 표현해야 하기 때문)
	glColor3f((GLfloat)r / 255, (GLfloat)g / 255, (GLfloat)b / 255); 

	glBegin(GL_POLYGON); // start to accept polygon(다각형)

	// draw vertices(꼭짓점)
	glVertex2f(x1, y1); glVertex2f(x1, y2); 
	glVertex2f(x2, y2); glVertex2f(x2, y1);

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


