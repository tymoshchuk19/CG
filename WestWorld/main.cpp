#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

float alfa = 90.0f, beta = -60.0f, radius = 200.0f;
float camX, camY, camZ;

float r = 50, ri = 35, rc = 15;
float andistbg = 360/16;
float andistgg = 360/8;
float anframe = 0;

void spherical2Cartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void drawCar(void){

    glScalef(5,5,5);
    glBegin(GL_QUADS);                /* OBJECT MODULE*/

    /* top of cube*/
    //************************FRONT BODY****************************************
    glColor3f(0.7,0.0,0.0);
    glVertex3f( 0.2, 0.4,0.6);
    glVertex3f(0.6, 0.5,0.6);
    glVertex3f(0.6, 0.5,0.2);
    glVertex3f( 0.2,0.4,0.2);

    /* bottom of cube*/
    glVertex3f( 0.2,0.4,0.6);
    glVertex3f(0.6,0.2,0.6);
    glVertex3f(0.6,0.2,0.2);
    glVertex3f( 0.2,0.2,0.2);

    /* front of cube*/
    glVertex3f( 0.2,0.2,0.6);
    glVertex3f(0.2, 0.4,0.6);
    glVertex3f(0.2,0.4,0.2);
    glVertex3f( 0.2,0.2,0.2);

    /* back of cube.*/
    glVertex3f(0.6,0.2,0.6);
    glVertex3f(0.6,0.5,0.6);
    glVertex3f(0.6,0.5,0.2);
    glVertex3f( 0.6,0.2,0.2);

    /* left of cube*/
    glVertex3f(0.2,0.2,0.6);
    glVertex3f(0.6,0.2,0.6);
    glVertex3f(0.6,0.5,0.6);
    glVertex3f(0.2,0.4,0.6);

    /* Right of cube */
    glVertex3f(0.2,0.2,0.2);
    glVertex3f( 0.6,0.2,0.2);
    glVertex3f( 0.6,0.5,0.2);
    glVertex3f( 0.2,0.4,0.2);
//****************************************************************************
    glVertex3f(0.7,0.65,0.6);
    glVertex3f(0.7,0.65,0.2);
    glVertex3f(1.7,0.65,0.2);        //top cover
    glVertex3f(1.7,0.65,0.6);
//***************************back guard******************************
    glColor3f(0.7,0.0,0.0);            /* Set The Color To Blue*/
    glVertex3f( 1.8, 0.5,0.6);
    glVertex3f(1.8, 0.5,0.2);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1,0.4,0.6);

    /* bottom of cube*/
    glVertex3f( 2.1,0.2,0.6);
    glVertex3f(2.1,0.2,0.2);
    glVertex3f(1.8,0.2,0.6);
    glVertex3f( 1.8,0.2,0.6);

    /* back of cube.*/
    glVertex3f(2.1,0.4,0.6);
    glVertex3f(2.1,0.4,0.2);
    glVertex3f(2.1,0.2,0.2);
    glVertex3f(2.1,0.2,0.6);

    /* left of cube*/
    glVertex3f(1.8,0.2,0.2);
    glVertex3f(1.8,0.5,0.2);
    glVertex3f(2.1,0.4,0.2);
    glVertex3f(2.1,0.2,0.2);

    /* Right of cube */
    glVertex3f(1.8,0.2,0.6);
    glVertex3f(1.8,0.5,0.6);
    glVertex3f(2.1,0.4,0.6);
    glVertex3f(2.1,0.2,0.6);
//******************MIDDLE BODY************************************
    glVertex3f( 0.6, 0.5,0.6);
    glVertex3f(0.6, 0.2,0.6);
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8,0.5,0.6);

    /* bottom of cube*/
    glVertex3f( 0.6,0.2,0.6);
    glVertex3f(0.6,0.2,0.2);
    glVertex3f(1.8,0.2,0.2);
    glVertex3f( 1.8,0.2,0.6);

    /* back of cube.*/
    glVertex3f(0.6,0.5,0.2);
    glVertex3f(0.6,0.2,0.2);
    glVertex3f(1.8,0.2,0.2);
    glVertex3f(1.8,0.5,0.2);
//*********************ENTER WINDOW**********************************
    glColor3f(0.1,0.0,0.0);
    glVertex3f( 0.77, 0.63,0.2);
    glVertex3f(0.75, 0.5,0.2);        //quad front window
    glVertex3f(1.2, 0.5, 0.2);
    glVertex3f( 1.22,0.63,0.2);

    glVertex3f(1.27,0.63,.2);
    glVertex3f(1.25,0.5,0.2);        //quad back window
    glVertex3f(1.65,0.5,0.2);
    glVertex3f(1.67,0.63,0.2);

    glColor3f(0.7,0.0,0.0);
    glVertex3f(0.7,0.65,0.2);
    glVertex3f(0.7,0.5,.2);       //first separation
    glVertex3f(0.75,0.5,0.2);
    glVertex3f(0.77,0.65,0.2);

    glVertex3f(1.2,0.65,0.2);
    glVertex3f(1.2,0.5,.2);       //second separation
    glVertex3f(1.25,0.5,0.2);
    glVertex3f(1.27,0.65,0.2);

    glVertex3f(1.65,0.65,0.2);
    glVertex3f(1.65,0.5,.2);     //3d separation
    glVertex3f(1.7,0.5,0.2);
    glVertex3f(1.7,0.65,0.2);

    glVertex3f( 0.75, 0.65,0.2);
    glVertex3f(0.75, 0.63,0.2);        //line strip
    glVertex3f(1.7, 0.63, 0.2);
    glVertex3f( 1.7,0.65,0.2);

    glVertex3f( 0.75, 0.65,0.6);
    glVertex3f(0.75, 0.63,0.6);        //line strip
    glVertex3f(1.7, 0.63, 0.6);
    glVertex3f( 1.7,0.65,0.6);

    glColor3f(0.1,0.0,0.0);
    glVertex3f( 0.77, 0.63,0.6);
    glVertex3f(0.75, 0.5,0.6);        //quad front window
    glVertex3f(1.2, 0.5, 0.6);
    glVertex3f( 1.22,0.63,0.6);

    glVertex3f(1.27,0.63,.6);
    glVertex3f(1.25,0.5,0.6);        //quad back window
    glVertex3f(1.65,0.5,0.6);
    glVertex3f(1.67,0.63,0.6);

    glColor3f(0.7,0.0,0.0);
    glVertex3f(0.7,0.65,0.6);
    glVertex3f(0.7,0.5,.6);       //first separation
    glVertex3f(0.75,0.5,0.6);
    glVertex3f(0.77,0.65,0.6);

    glVertex3f(1.2,0.65,0.6);
    glVertex3f(1.2,0.5,.6);       //second separation
    glVertex3f(1.25,0.5,0.6);
    glVertex3f(1.27,0.65,0.6);

    glVertex3f(1.65,0.65,0.6);
    glVertex3f(1.65,0.5,.6);
    glVertex3f(1.7,0.5,0.6);
    glVertex3f(1.7,0.65,0.6);
    glEnd();
}

void drawTorus(float size) {
    glTranslatef(0,1,0);
    glRotatef(90,1,0,0);
    glutSolidTorus(size, 2, 20, 20);
}

void drawGoodGuys(void) {
    glRotatef(-anframe,0,1,0);
    glColor3f(0.0, 0.0, 0.7);
    for(int i = 0;i<8;i++) {
        glPushMatrix();
        glTranslatef( rc, 1, 0);
        glutSolidTeapot(1);
        glPopMatrix();
        glRotatef(andistgg,0,1,0);
    }
}

void drawBadGuys(void) {
    glRotatef(anframe,0,1,0);
    glColor3f(0.9,0.0,0.0);
    for(int i = 0; i<16; i++){
        glPushMatrix();
        glTranslatef( ri, 1, 0);
        glRotatef(90,0,1,0);
        glutSolidTeapot(1);
        glPopMatrix();
        glRotatef(andistbg,0,1,0);
    }
}

void drawTrees(void) {

    float rx,rz;
    srand((unsigned int)0);

    for(int i = 0; i<500; i++){
        do{
            rx = ((float)rand()/(float)(RAND_MAX) * 200)-100;
            rz = ((float)rand()/(float)(RAND_MAX) * 200)-100;
        }while(rx<sqrt(r*r-rz*rz) && rz<sqrt(r*r-rx*rx) && -rz<sqrt(r*r-rx*rx));
        glPushMatrix();
        glTranslatef(rx,0,rz);

        //Cone baixo
        glPushMatrix();
        glTranslatef(0,0.1,0);
        glRotatef(-90,1,0,0);
        glColor3f(0.6,0.3,0.0);
        glutSolidCone(1,2, 15,15);
        glPopMatrix();

        //Cone cima
        glPushMatrix();
        glTranslatef(0,2,0);
        glRotatef(-90,1,0,0);
        glColor3f(0.0,0.9,0.3);
        glutSolidCone(2,8, 15,15);
        glPopMatrix();
        glPopMatrix();
    }
}


void drawSnowMan(void){
    glTranslatef(0,1,0);
    glutSolidSphere(2,20,20);
    glTranslatef(0,2.9,0);
    glutSolidSphere(1,20,20);
    glPushMatrix();
    glRotatef(15,1,0,0);
    glTranslatef(0,0,1);
    glColor3f(0.7,0.0,0.0);
    glutSolidCone(0.17,1.2,15,15);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-10,1,0,0);
    glRotatef(30,0,1,0);
    glTranslatef(0,0,1);
    glColor3f(0.1,0.0,0.0);
    glutSolidSphere(0.25,15,15);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-10,1,0,0);
    glRotatef(-30,0,1,0);
    glTranslatef(0,0,1);
    glColor3f(0.1,0.0,0.0);
    glutSolidSphere(0.25,15,15);
    glPopMatrix();

}



void renderScene(void) {


	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();

    glPushMatrix();
    glColor4f(1, 1, 1,.3);
    glTranslatef(-6,5,-20);
    glRotatef(30,0,1,0);
    glScalef(0.5,0.5,0.5);
    drawSnowMan();
    glPopMatrix();

	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	glColor3f(0.2f, 0.8f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);

		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);
		glVertex3f(100.0f, 0, 100.0f);
	glEnd();

    anframe+=M_PI/2;


    glPushMatrix();
    glColor3f(0.7,0.0,0.3);
    drawTorus(1);
    glPopMatrix();

    glPushMatrix();
    drawGoodGuys();
    glPopMatrix();

    glPushMatrix();
    drawBadGuys();
    glPopMatrix();

    glPushMatrix();
    drawTrees();
    glPopMatrix();

    glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

// put code to process regular keys in here

}


void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		alfa -= 0.1; break;

	case GLUT_KEY_LEFT:
		alfa += 0.1; break;

	case GLUT_KEY_UP:
		beta += 0.1f;
		if (beta > 1.5f)
			beta = 1.5f;
		break;

	case GLUT_KEY_DOWN:
		beta -= 0.1f;
		if (beta < -1.5f)
			beta = -1.5f;
		break;

	case GLUT_KEY_PAGE_DOWN: radius -= 5.0f;
		if (radius < 1.0f)
			radius = 1.0f;
		break;

	case GLUT_KEY_PAGE_UP: radius += 5.0f; break;
	}
	spherical2Cartesian();
	glutPostRedisplay();

}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));

	printf("\nUse Arrows to move the camera up/down and left/right\n");
	printf("Home and End control the distance from the camera to the origin");
}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	spherical2Cartesian();

	printInfo();

// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
