//Atenção para as correções
//Include necessary header files
#include "glut.h"
#include <cstdlib>
#include <cmath>

//Link with necessary libraries.
//This need to be written in at least one .cpp file in the project
#pragma comment (lib, "glut32.lib")

class Planet
{
public:
	float x, y, z, size;
	float angle;
	float offset;
	Planet() {
		x = 0;
		y = 0;
		z = 0;
		angle = 0;
		draw(0, 0, 0, 0);
	}
	Planet(float X, float Y, float Z, float SIZE, float OFFSET, float r, float g, float b) {
		x = X;
		y = Y;
		z = Z;
		offset = OFFSET;
		size = SIZE;
		angle = rand() % 360 + 1;
		draw(size, r, g, b);
	}
	void draw(float SIZE, float r, float g, float b) {
        glTranslatef(x, y, 0);
        //glColor3f (r, g, b);
		float color[] = {r, g, b, 0.25f};
		//float specularColor[] = {1.0, 0.0f, 0.0f, 1.0f};
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
		glMaterialfv(GL_FRONT, GL_SPECULAR, color);
		glMateriali(GL_FRONT, GL_SHININESS, 120);
		//glutWireCube(size);
        glutSolidSphere(size, 360, 100);
	}
	void rotate(Planet orbital) {
		x = orbital.size*3.5 + offset;
		z = orbital.size*3.5 + offset;
		glRotatef(angle, 0, 1, 0);
		//glTranslatef(-orbital.x, 0, -orbital.z);
	}

private:

};

int x, y, z;

//Callback function prototypes
void render(void);
void onKeyboard(unsigned char, int, int);
void update(void);

#define ESC_ASCII 27

int g_Win;	//Stores window identifier (handle) returned by glutCreateWindow
			//We need this handle to terminate the window

float g_X = 0.0f, g_Theta = 0.0f, g_Z = -50.0f, g_Y = 0.0f;
float b_X = 0.0f, b_Z = 0.0f;
bool birdseye = false;
Planet sun = Planet(3,0,3,7, 0,1,1,0);
Planet moon = Planet(1,0,1,0.5, 0,1,1,1);
Planet earth = Planet(-5,0,-5,2, 2, 0,0.4,0.3);
Planet jupiter = Planet(0,0,0, 5, 15, 0.6,0, 0.1);
Planet uranus = Planet(0,0,0, 4, 30, 0, 0.8, 0.2);

int main(int argc, char **argv)
{


	jupiter.angle = 30;

	earth.angle = 10;
	//==========================================
	//Step 1: Initialize GLUT
	//==========================================
	glutInit(&argc, argv);

	//GLUT_RGBA: Red, Green, Blue, Alpha color representation.
	//GLUT_DOUBLE: Double buffering
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glClearDepth(0.0f);
	glDepthFunc(GL_LEQUAL);

	//Create Window
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	g_Win = glutCreateWindow("Solar System");
	glEnable(GL_DEPTH_TEST);
	//Set the color to be used to clear display buffer.
	//Try different values.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Set projection transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);

	//==========================================
	//Step 2: Register callback functions
	//==========================================
	glutDisplayFunc(render);
	glutKeyboardFunc(onKeyboard);
	glutIdleFunc(update);

	glEnable(GL_LIGHTING);	//Enable lighting
	glEnable(GL_SPECULAR);
	glEnable(GL_NORMALIZE);	//Enable auto-normalization of normal vectors
	float black[] = {0.0f, 0.0f, 0.0f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);	//Zero global ambient component
	glShadeModel(GL_SMOOTH);



	//Setup material


	//==========================================
	//Step 3: Enter main loop
	//==========================================
	glutMainLoop();
	return 0;
}

//Callback function definitions
void render(void)
{
	//Clear display buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw something
	glLoadIdentity();
	if(!birdseye)
	{
		gluLookAt(g_X, 0, g_Z, g_X+(1*-sinf(g_Theta)), 0.0, g_Z+(1*cosf(g_Theta)), 0, 1.0f, 0);
	}
	else
	{
		gluLookAt(b_X, 100 ,b_Z,b_X,0,b_Z, 0, 0.0f, 1.0f);
	}

	//Sunlight0
	float light0position[] = {0.0f,0.0f,0.0f,1.0f};
	float light0Ambient[] = {1.0f, 1.0f, 1.0f , 1.0f};
	float light0Diffuse[] = {1.0f, 1.0f, 1.0f};
	//float light0Specular[] = {1.0f, 1.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light0position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1f);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
	glEnable(GL_LIGHT0);	//Enable light source 0


	sun.draw(sun.size, 1, 1, 0);
	glPushMatrix();
		earth.rotate(sun);
		earth.draw(earth.size, 0, 0.4, 0.3);
		glPushMatrix();
			moon.rotate(earth);
			moon.draw(moon.size, 1,1,1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		jupiter.rotate(sun);
		jupiter.draw(jupiter.size, 0.7,0, 0.1);
	glPopMatrix();

	glPushMatrix();
		uranus.rotate(sun);
		uranus.draw(uranus.size, 0, 0.8, 0.2);
	glPopMatrix();




	//Output color buffer to screen
	glutSwapBuffers();
}

void update(void){

	float factor = 25;

	if(earth.angle<360)
	{
		earth.angle += factor*0.005f;
	}
	else
	{
		earth.angle = 0;
	}
	if(moon.angle<360)
	{
		moon.angle += factor*0.01f;
	}
	else
	{
		moon.angle = 0;
	}
	if(jupiter.angle<360)
	{
		jupiter.angle += factor*0.003f;
	}
	else
	{
		jupiter.angle = 0;
	}
	if(uranus.angle <360)
	{
		uranus.angle += factor*0.001f;
	}
	else
	{
		uranus.angle = 0;
	}

	glutPostRedisplay();
}

void onKeyboard(unsigned char key, int, int)
{
	switch(key)
	{
	case 'a':
		if(!birdseye)
		{
			g_X += 0.1f;
		}
		else
		{
			b_X += 1.0f;
		}
		break;

	case 'e':
		g_Theta += 0.1f;
		break;

	case 'd':
		if(!birdseye)
		{
			g_X -= 0.1f;
		}
		else
		{
			b_X -= 1.0f;
		}
		break;

	case 'q':
		g_Theta -= 0.1f;
		break;

	case 's':
		if(!birdseye)
		{
			g_Z -= 0.1f*cosf(g_Theta);
			g_X += 0.1f*sinf(g_Theta);
		}
		else
		{
			b_Z -= 1.0f;
		}
		break;

	case 'w':
		if(!birdseye)
		{
			g_Z += 0.1f*cosf(g_Theta);
			g_X -= 0.1f*sinf(g_Theta);
		}
		else
		{
			b_Z += 1.0f;
		}
		break;
	case 'z':
		g_Y+=0.1f;
		break;

	case 'x':
		g_Y-=0.1f;
		break;

	case 'b':
		if(birdseye)
		{
			birdseye = false;
		}
		else
		{
			birdseye = true;
		}
		break;

	}
	glutPostRedisplay();
}
