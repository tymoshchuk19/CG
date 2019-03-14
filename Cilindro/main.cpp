#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

double radius = 5;
double alfa = 0;
double beta = 0;

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


void drawCylinder(float radius, float height, int slices) {


    double start = 0;
    double alfa = 2*M_PI/slices;

// put code to draw cylinder in here

    for(int i = 0;i<slices;i++){
        glBegin(GL_TRIANGLES);
        glColor3f(1,0.2,0.1);
        glVertex3f(radius*cos(start), height/2, radius*sin(start));
        glVertex3f(0.0f, height/2, 0.0f);
        glVertex3f(radius*cos(start+alfa), height/2, radius*sin(start+alfa));


        glColor3f(1,4,1);
        glVertex3f(radius*cos(start), height/2, radius*sin(start));
        glVertex3f(radius*cos(start+alfa), height/2, radius*sin(start+alfa));
        glVertex3f(radius*cos(start), -height/2, radius*sin(start));

        glColor3f(1,0.5,1);
        glVertex3f(radius*cos(start+alfa), -height/2, radius*sin(start+alfa));
        glVertex3f(radius*cos(start), -height/2, radius*sin(start));
        glVertex3f(radius*cos(start+alfa), height/2, radius*sin(start+alfa));

        glColor3f(1,0.4,1);
        glVertex3f(radius*cos(start), -height/2, radius*sin(start));
        glVertex3f(radius*cos(start+alfa), -height/2, radius*sin(start+alfa));
        glVertex3f(0.0f, -height/2, 0.0f);
        glEnd();
        start+=alfa;
    }

}

void plane(float x, float z) {
    x /= 2;
    z /= 2;

    glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.2,0.3);
    glVertex3f(x,0,0);
    glVertex3f(-x,0,0);
    glVertex3f(0,0,z);


    glColor3f(0.5,0.9,0.7);
    glVertex3f(-x,0,0);
    glVertex3f(x,0,0);
    glVertex3f(0,0,-z);
    glEnd();

}

void box(float x, float y, float z, int divs){
    float cc = x/divs;
    float ac = y/divs;
    float lc = z/divs;

    x /= 2;
    y /= 2;
    z /= 2;

    //faces x
    for(int i = 0; i<divs; i++){

        float tempY = -y + (ac * i);

        for(int j = 0; j < divs; j++){

            float tempZ = -z + (lc * j);

            float proxY = tempY + ac;
            float proxZ = tempZ + lc;

            glBegin(GL_TRIANGLES);
            glColor3f(0.1,0.2,0.3);
            //face x positiva
            glVertex3f(x,tempY,tempZ);
            glVertex3f(x,proxY,proxZ);
            glVertex3f(x,tempY,proxZ);

            glColor3f(0.3,0.2,0.1);
            glVertex3f(x,tempY,tempZ);
            glVertex3f(x,proxY,tempZ);
            glVertex3f(x,proxY,proxZ);


            glColor3f(0.3,0.2,0.1);
            //face x negativa
            glVertex3f(-x,tempY,tempZ);
            glVertex3f(-x,proxY,proxZ);
            glVertex3f(-x,proxY,tempZ);

            glColor3f(0.1,0.2,0.3);
            glVertex3f(-x,tempY,tempZ);
            glVertex3f(-x,tempY,proxZ);
            glVertex3f(-x,proxY,proxZ);
            glEnd();
        }
    }

    //faces y
    for(int i = 0; i<divs; i++){

        float tempX = -x + (cc * i);

        for(int j = 0; j < divs; j++){

            float tempZ = -z + (lc * j);

            float proxX = tempX + cc;
            float proxZ = tempZ + lc;

            glBegin(GL_TRIANGLES);
            glColor3f(0.4,0.2,0.3);
            //face y positiva
            glVertex3f(tempX,y,tempZ);
            glVertex3f(tempX,y,proxZ);
            glVertex3f(proxX,y,proxZ);


            glColor3f(0.3,0.2,0.4);
            glVertex3f(tempX,y,tempZ);
            glVertex3f(proxX,y,proxZ);
            glVertex3f(proxX,y,tempZ);

            glColor3f(0.3,0.2,0.4);
            //face y negativa
            glVertex3f(tempX,-y,tempZ);
            glVertex3f(proxX,-y,tempZ);
            glVertex3f(proxX,-y,proxZ);

            glColor3f(0.4,0.2,0.3);
            glVertex3f(tempX,-y,tempZ);
            glVertex3f(proxX,-y,proxZ);
            glVertex3f(tempX,-y,proxZ);
            glEnd();
        }
    }

    //faces z
    for(int i = 0; i<divs; i++){

        float tempX = -x + (cc * i);

        for(int j = 0; j < divs; j++){

            float tempY = -y + (ac * j);

            float proxX = tempX + cc;
            float proxY = tempY + ac;

            glBegin(GL_TRIANGLES);

            glColor3f(0.1,0.5,0.3);
            //face z positiva
            glVertex3f(tempX,tempY,z);
            glVertex3f(proxX,proxY,z);
            glVertex3f(tempX,proxY,z);


            glColor3f(0.5,0.2,0.3);
            glVertex3f(tempX,tempY,z);
            glVertex3f(proxX,tempY,z);
            glVertex3f(proxX,proxY,z);


            glColor3f(0.5,0.2,0.3);
            //face z negativa
            glVertex3f(tempX,tempY,-z);
            glVertex3f(tempX,proxY,-z);
            glVertex3f(proxX,proxY,-z);


            glColor3f(0.1,0.5,0.3);
            glVertex3f(tempX,tempY,-z);
            glVertex3f(proxX,proxY,-z);
            glVertex3f(proxX,tempY,-z);
            glEnd();
        }
    }

}



void sphere(float radius, int slices, int stacks){

    float x1,y1,z1;
    float x2,y2,z2;
    float x3,y3,z3;
    float x4,y4,z4;


    float rotS = (2*M_PI)/slices;
    float rotC = M_PI/stacks;

    float somaC = 0;
    float somaS = 0;

    for(int i = 0; i < stacks*2 ; i++){
        somaC = rotC * i;
        for(int j = 0; j < slices ; j++){
            somaS = rotS * j;

            x1 = radius*cos(somaS)*cos(somaC);
            y1 = radius*sin(somaC);
            z1 = radius*cos(somaC)*sin(somaS);

            x2 = radius*cos(somaS+rotS)*cos(somaC);
            y2 = radius*sin(somaC);
            z2 = radius*cos(somaC)*sin(somaS+rotS);

            x3 = radius*cos(somaS+rotS)*cos(somaC+rotC);
            y3 = radius*sin(somaC+rotC);
            z3 = radius*cos(somaC+rotC)*sin(somaS+rotS);

            x4 = radius*cos(somaS)*cos(somaC+rotC);
            y4 = radius*sin(somaC+rotC);
            z4 = radius*cos(somaC+rotC)*sin(somaS);

            glBegin(GL_TRIANGLES);
            glColor3f(0.5,0.2,0.3);
            glVertex3f(x1,y1,z1);
            glVertex3f(x2,y2,z2);
            glVertex3f(x3,y3,z3);


            glColor3f(0.5,0.9,0.7);
            glVertex3f(x1,y1,z1);
            glVertex3f(x3,y3,z3);
            glVertex3f(x4,y4,z4);
            glEnd();
        }
    }

}

void cone(float raio,float altura, int slices, int stacks){

    float rotS= 2*M_PI/slices;
    float sub = altura/stacks;
    float dim = raio/stacks;

    float h0, h1;
    float r0, r1;
    float somaR;


    float x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4;

    for(int i = 0; i < slices; i++ ){
        x1 = raio*sin(rotS*i);
        y1 = (-altura/2);
        z1 = raio*cos(rotS*i);

        x2 = raio*sin(rotS*i+rotS);
        y2 = (-altura/2);
        z2 = raio*cos(rotS*i+rotS);

        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.2,0.8);
        glVertex3f(x1,y1,z1);
        glVertex3f(0,-altura/2,0);
        glVertex3f(x2,y2,z2);
        glEnd();
    }

    for(int i = 0; i < stacks; i++ ){
        h0 = (-altura/2)+i*sub;
        h1 = (-altura/2)+(i+1)*sub;

        r0 = raio-(dim*i);
        r1 = raio-(dim*(i+1));

        for(int j = 0; j< slices; j++){
            somaR = rotS*j;

            x1 = (r0)*sin(somaR);
            y1 = h0;
            z1 = (r0)*cos(somaR);

            x2 = r0*sin(somaR+rotS);
            y2 = h0;
            z2 = (r0)*cos(somaR+rotS);

            x3 = r1*sin(somaR+rotS);
            y3 = h1;
            z3 = r1*cos(somaR+rotS);

            x4 = r1*sin(somaR);
            y4 = h1;
            z4 = r1*cos(somaR);

            glBegin(GL_TRIANGLES);
            glColor3f(0.5,0.2,0.3);
            glVertex3f(x1,y1,z1);
            glVertex3f(x2,y2,z2);
            glVertex3f(x3,y3,z3);

            glColor3f(0.5,0.7,0.3);
            glVertex3f(x1,y1,z1);
            glVertex3f(x3,y3,z3);
            glVertex3f(x4,y4,z4);
            glEnd();
        }
    }
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(radius*cos(beta)*cos(alfa),radius*sin(beta),radius*cos(beta)*sin(alfa),
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(3,0,0);

    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,3,0);


    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,3);
    glEnd();


    //drawCylinder(1,2,10);
    //plane(2, 2);
	//box(2,1,3,5);
    sphere(1, 45, 45);
    //cone(1,3,40,16);

	// End of frame
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

    double radius = 5;

// put code to process regular keys in here
    if (c == 'w') {
        beta += M_PI/12;
    }if (c == 's'){
        beta -= M_PI/12;
    }if(c == 'd') {
        alfa += M_PI/12;
    }if(c == 'a') {
        alfa -= M_PI/12;
    }if(c == 'q'){
        beta += M_PI/12;
        alfa += M_PI/12;
    }if(c == 'e') {
        beta -= M_PI/12;
        alfa -= M_PI/12;
    }

    glutPostRedisplay();
}


void processSpecialKeys(int key, int xx, int yy) {

// put code to process special keys in here

}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
	//glPolygonMode(GL_FRONT,GL_LINE);
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
