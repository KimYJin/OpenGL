
#include <glut.h>

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
	glVertex2fv(a); glVertex2fv(b); glVertex2fv(c);
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c,int k)
{
	GLfloat ab[2], bc[2], ac[2];

	if (k > 0)
	{
		for (int i = 0; i < 2; i++) ab[i] = (a[i] + b[i]) / 2;
		for (int i = 0; i < 2; i++) bc[i] = (b[i] + c[i]) / 2;
		for (int i = 0; i < 2; i++) ac[i] = (a[i] + c[i]) / 2;

		divide_triangle(a, ab, ac, k - 1);
		divide_triangle(b, ab, bc, k - 1);
		divide_triangle(c, ac, bc, k - 1);
	}
	else
	{
		triangle(a, b, c);
	}

}

void display()
{
	GLfloat v[3][2] = { { 0.0, 0.0 },{ 25.0, 50.0 },{ 50.0, 0.0 } };

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	
	divide_triangle(v[0], v[1], v[2], 5);
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog04: recursive triangles");
	glutDisplayFunc(display);

	init();
	glutMainLoop();

	return 0;
}

