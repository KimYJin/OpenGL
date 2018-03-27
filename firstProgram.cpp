#include <glut.h>

void init();
void display();

int main(int argc,char* argv[])
{
	//�Ʒ� glut�� �����ϴ� �Լ����� glut.h�� �ִ� �Լ���
	glutInit(&argc, (char**)argv);	// �ϳ��� �����츦 �ʱ�ȭ��Ű�� �Լ�. //// initialize GLUT engine
	glutInitWindowSize(500, 500);	//������ ������.
	glutCreateWindow("Prog01:first OpenGL program");	//Ÿ��Ʋ

	glutDisplayFunc(display);	// �߿�. ������� ������â�ȿ� openGL���̺귯���� ���� �׸��ڴٰ� �������ִ°�.
	init();	//// initialize OpenGL parameters
	glutMainLoop();	// ����ڰ� �ִ� �̺�Ʈ�� �޾Ƽ� ó���Ǵ� ���α׷��̹Ƿ� �̸�ɾ���� �̺�Ʈ������ ����. // run main loop of GLUT

	return 0;
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // set background color.(red, green, blue,����). ���⼭�� �� 1�� �� -> �������� ��� ����.
	glColor3f(1.0, 0.0, 0.0);	// RGB : 1,0,0 �� ������
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);	// ��ȭ�� ũ���� 2D��ǥ ����. // set 2D coordinates (left, right, bottom, top)
}

// display�Լ��ȿ� �׷����͵��� ����.
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);// clear background // glClearColor���� �����س��� ���� ���������� ����ȴ�.
	glBegin(GL_POINTS);	//���� ��ڴ�. //// start to accept multiple points

	for (double f = 10; f<40; f += 0.1)
	{
		//�簢���� �׸��� ���� ������
		// draw points
		glVertex2f(f, 10);//(10,10)~(40,10)����
		glVertex2f(f, 40);//(10,40)~(40,40)����
		glVertex2f(10, f);//(10,10)~(10,40)����
		glVertex2f(40, f);//(40,10)~(40,40)����
	}
	glEnd();	// end to accept multiple points
	glFlush();	// finish any remaining drawings
}