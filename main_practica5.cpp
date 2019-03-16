//Semestre 2019 - 2
//*************************************************************//
//*************************************************************//
//************* Alumno (s): Cedillo Nájera Eric Rodrigo *******//
//*************	Práctica No. 5 ******//
//*************	Visual Studio 2017 ******//
//*************	Ejercicio Clase 5 ******//
//* Este programa dibuja un brazo con movimientos *************//
//*************** y articulaciones ****************************//
//*************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float AnguloX = 0.0f;
float AnguloY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float rotx = 0.0;
float roty = 0.0;
float rotz = 0.0;
float rotx1 = 0.0;
float roty1 = 0.0;
float rotz1 = 0.0;
float rotx2 = 0.0;
float roty2 = 0.0;
float rotz2 = 0.0;
float rotx3 = 0.0;
float roty3 = 0.0;
float rotz3 = 0.0;
float rotx4 = 0.0;
float roty4 = 0.0;
float rotz4 = 0.0;
float rotx5 = 0.0;
float roty5 = 0.0;
float rotz5 = 0.0;
GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	/*glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);*/


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
		//glNormal3f( 0.0f, 0.0f, 1.0f);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	//glNormal3f( 1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	//glNormal3f( 0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	//glNormal3f( -1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.4, 0.2, 0.6);
	//glNormal3f( 0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	//glNormal3f( 0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Palma
	glPushMatrix(); // stack palma
	glTranslatef(0.0, 0.0, -5);
	glTranslatef(-2.0f, 0.0f, transZ); // Traslación para la palma
	glRotatef(roty4, 0, 1, 0);
	glRotatef(rotz4, 0, 0, 1);
	glPushMatrix();//nudillo1
	glTranslatef(1.5, 1.5, 0.0);
	glRotatef(rotx, 0, 1, 0);
	glPushMatrix(); //Falange 1
	glTranslatef(1.05f, 0.0f, 0.0f);//centro a centro
	glPushMatrix();//nudillo2
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(roty, 0, 1, 0);
	glPushMatrix();//falangina 1
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(rotz, 0, 1, 0);
	glPushMatrix();//falangeta 1
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, 0.5, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange 1
	glPopMatrix();//pop nudillo

	glPushMatrix();//nudillo1.1
	glTranslatef(1.5, .5, 0.0);
	glRotatef(rotx1, 0, 1, 0);
	glPushMatrix(); //Falange 2
	glTranslatef(1.05f, 0.0, 0.0f);
	glPushMatrix();//nudillo2.1
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(roty1, 0, 1, 0);
	glPushMatrix();//falangina 2
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3.1
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(rotz1, 0, 1, 0);
	glPushMatrix();//falangeta 2
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .5, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange2
	glPopMatrix();//pop nudillo 1

	glPushMatrix();//nudillo1.2
	glTranslatef(1.5, -0.5, 0.0);
	glRotatef(rotx2, 0, 1, 0);
	glPushMatrix(); //Falange 3
	glTranslatef(1.05f, 0.0f, 0.0f);
	glPushMatrix();//nudillo2.2
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(roty2, 0, 1, 0);
	glPushMatrix();//falangina 3
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3.2
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(rotz2, 0, 1, 0);
	glPushMatrix();//falangeta 3
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .5, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange3
	glPopMatrix();

	glPushMatrix();//nudillo1.3
	glTranslatef(1.5, -1.5, 0.0);
	glRotatef(rotx3, 0, 1, 0);
	glPushMatrix(); //Falange 4
	glTranslatef(1.05f, 0.0f, 0.0f);
	glPushMatrix();//nudillo2.3
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(roty3, 0, 1, 0);
	glPushMatrix();//falangina 4
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3.3
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(rotz3, 0, 1, 0);
	glPushMatrix();//falangeta 4
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .5, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange4
	glPopMatrix();

	glPushMatrix();//nudillo1.4
	glTranslatef(-1, .9, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(1.5, -1.5, 0.0);
	glRotatef(rotz5, 0, 0, 1);
	glRotatef(rotx5, 0, 1, 0);
	glPushMatrix(); //Falange 5
	glTranslatef(1.05f, 0.0f, 0.0f);
	glPushMatrix();//nudillo2.4
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(roty5, 0, 1, 0);
	glPushMatrix();//falangina 5
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .75, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange4
	glPopMatrix();


	glScalef(3, 5, 1);
	prisma();           // Dibujar palma
	glPopMatrix(); // Sale del stack de la palma 

	//			   //fin dibujo


	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 'z':
		rotx += 10.0f;
		break;
	case 'x':
		roty += 10.0f;
		break;
	case 'c':
		rotz += 10.0f;
		break;
	case 'v':
		rotx1 += 10.0f;
		break;
	case 'b':
		roty1 += 10.0f;
		break;
	case 'n':
		rotz1 += 10.0f;
		break;
	case 'f':
		rotx2 += 10.0f;
		break;
	case 'g':
		roty2 += 10.0f;
		break;
	case 'h':
		rotz2 += 10.0f;
		break;
	case 'j':
		rotx3 += 10.0f;
		break;
	case 'k':
		roty3 += 10.0f;
		break;
	case 'l':
		rotz3 += 10.0f;
		break;

	case 't':
		rotx4 += 90.0f;
		break;
	case 'y':
		roty4 += 90.0f;
		break;
	case 'u':
		rotz4 += 90.0f;
		break;

	case 'o':
		rotx5 += 10.0f;
		break;
	case 'p':
		roty5 += 10.0f;
		break;

	case 'i':
		rotz5 += 90.0f;
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		AnguloX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		AnguloX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		AnguloY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		AnguloY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}