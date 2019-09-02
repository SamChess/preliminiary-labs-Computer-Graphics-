# include <GL/glut.h>
#include <math.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);//set background color of the display window as white
	gluOrtho2D(-200, 200, -200, 200);
	
}

void outer_rectangle() {
	glClear(GL_COLOR_BUFFER_BIT); //assigned windowcolor displayed
	glColor3f(0.0, 1.0, 0.0); //set object color
	glLineWidth(1.0);//sets the width of the line 
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(-100, 20);
	glVertex2f(-40, 20);
	glVertex2f(-40, 80);
	glVertex2f(-100, 80);
	glEnd();
	glFlush();//enables fast execution of statements
}
void inner_rectangle() {

	glColor3f(0.0, 2.0, 0.0); //set object color
	glLineWidth(1.0);//sets the width of the line 
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(-80, 40);
	glVertex2f(-60, 40);
	glVertex2f(-60, 60);
	glVertex2f(-80, 60);
	glEnd();
	glFlush();//enables fast execution of statements
}

void uprightTriangle() {
	glColor3f(0.0, 2.0, 0.0); //set object color
	glLineWidth(1.0);//sets the width of the line 
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glVertex2f(40, 0);
	glVertex2f(0, 40);
	glVertex2f(80, 40);
	glEnd();
	glFlush();//enables fast execution of statements
}
void upsidedownTriangle() {
	glColor3f(0.0, 2.0, 0.0); //set object color
	glLineWidth(1.0);//sets the width of the line 
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 20);
	glVertex2f(80, 20);
	glVertex2f(40, 60);
	glEnd();
	glFlush();//enables fast execution of statements
}
void DrawCircle1(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments)
{
	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle);

	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);

		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
	glFlush();
}
void DrawCircle2(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments)
{
	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle);

	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);

		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
	glFlush();
}

void DrawCircle3(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments)
{
	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle);

	glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);

		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
	glFlush();
}
void arc(float cx, float cy, float r, int num_segments, float arc_length) {
	glLineWidth(2.0);
	glBegin(GL_LINE_STRIP);

	for (int ii = 0; ii < num_segments; ++ii) {
		float theta = arc_length * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);
	}
	glEnd();
	glFlush();
}

void display() {
	outer_rectangle();
	inner_rectangle();
	uprightTriangle();
	upsidedownTriangle();
	DrawCircle1(-80,-80,20,0,50,110);
	DrawCircle2(-60, -80, 20, 0, 50, 110);
	DrawCircle3(-60, -60, 20, 0, 50, 110);
	arc(-30,-30,20,1000,3);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500); 
	glutCreateWindow("Lab1");

	init();
	glutDisplayFunc(display);
  
	glutMainLoop();
	return 0;

}