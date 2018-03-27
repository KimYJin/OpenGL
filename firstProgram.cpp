#include <glut.h>

void init();
void display();

int main(int argc,char* argv[])
{
	//아래 glut로 시작하는 함수들은 glut.h에 있는 함수들
	glutInit(&argc, (char**)argv);	// 하나의 윈도우를 초기화시키는 함수. //// initialize GLUT engine
	glutInitWindowSize(500, 500);	//윈도우 사이즈.
	glutCreateWindow("Prog01:first OpenGL program");	//타이틀

	glutDisplayFunc(display);	// 중요. 윈도우와 윈도우창안에 openGL라이브러리로 무언가 그리겠다고 연결해주는것.
	init();	//// initialize OpenGL parameters
	glutMainLoop();	// 사용자가 주는 이벤트를 받아서 처리되는 프로그램이므로 이명령어부터 이벤트루프의 시작. // run main loop of GLUT

	return 0;
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // set background color.(red, green, blue,투명도). 여기서는 다 1로 둠 -> 불투명한 흰색 바탕.
	glColor3f(1.0, 0.0, 0.0);	// RGB : 1,0,0 은 빨간색
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);	// 도화지 크기의 2D좌표 설정. // set 2D coordinates (left, right, bottom, top)
}

// display함수안에 그려질것들이 있음.
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);// clear background // glClearColor에서 설정해놓은 색이 바탕색으로 적용된다.
	glBegin(GL_POINTS);	//점을 찍겠다. //// start to accept multiple points

	for (double f = 10; f<40; f += 0.1)
	{
		//사각형을 그리기 위한 정점들
		// draw points
		glVertex2f(f, 10);//(10,10)~(40,10)까지
		glVertex2f(f, 40);//(10,40)~(40,40)까지
		glVertex2f(10, f);//(10,10)~(10,40)까지
		glVertex2f(40, f);//(40,10)~(40,40)까지
	}
	glEnd();	// end to accept multiple points
	glFlush();	// finish any remaining drawings
}