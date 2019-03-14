#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <cstdio>

float anz = 0;
float anx = 0;
float any = 0;
double tx = 0;
double ty = 0;
double tz = 0;
double sx = 1;

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


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(0.0,0.0,15,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// put the geometric transformations here
    printf("%f %f\n", anx, any);

// put drawing instructions here
    glPolygonMode(GL_FRONT,GL_FILL);
    glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);



    glRotatef(anx,1,0,0);
    glRotatef(any,0,1,0);
    glRotatef(anz,0,0,1);
    glScalef(sx,sx,sx);
    glTranslatef(tx,0,0);
    glTranslatef(0,ty,0);
    glTranslatef(0,0,tz);

    glBegin(GL_LINES);

    //x axe
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(5,0,0);

    //y axe
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(0,5,0);

    //z axe
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,5);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(0.0f, 3.0f, 0.0f);
    glVertex3f(3.0f,  0.0f, 0.0f);
    glVertex3f(0.0f, -3.0f, 0.0f);

    glColor3f(0.3,0.2,0.2);
    glVertex3f(0.0f, -3.0f, 0.0f);
    glVertex3f(-3.0f,  0.0f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.0f);

    glColor3f(0.1,0.1,0.1);
    glVertex3f(3.0f, 0.0f, 0.0f);
    glVertex3f(0.0f,  3.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);

    glColor3f(0.6,0.2,0.2);
    glVertex3f(0.0f, 3.0f, 0.0f);
    glVertex3f(-3.0f,  0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);

    glColor3f(0.5,0.5,0.5);
    glVertex3f(-3.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -3.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);

    glColor3f(0.7,0.7,0.7);
    glVertex3f(0.0f, -3.0f, 0.0f);
    glVertex3f(3.0f,  0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);

    glEnd();

	// End of frame
	glutSwapBuffers();
}


// write function to process keyboard events
void  rot(unsigned char key, int x, int y) {

    if (key == 'w') {
        anx -= 15;
    }if (key == 's'){
        anx += 15;
    }if(key == 'd') {
        any += 15;
    }if(key == 'a') {
        any -= 15;
    }if(key == 'q'){
        anz += 15;
    }if(key == 'e'){
        anz -= 15;
    }if(key == 'l'){
        tx += 1;
    }if(key == 'h'){
        tx -= 1;
    }if(key == 'k'){
        ty += 1;
    }if(key == 'j'){
        ty -= 1;
    }if(key == 'u'){
        tz += 1;
    }if(key == 'i'){
        tz -= 1;
    }if(key == '+'){
        sx += 1;
    }if(key == '-'){
        if(sx>0.5) sx -= 1;
    }

    glutPostRedisplay();
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
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks
    glutKeyboardFunc(rot);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
