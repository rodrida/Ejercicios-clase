//Semestre 2019 - 2
//************************************************************************//
//************************************************************************//
//************* Alumno (s): Cedillo Nájera Eric Rodrigo ******************//
//*************	Práctica No. 7 ******//
//*************	Visual Studio 2017 ******//
//*************	Ejercicio Clase 7 ******//
//* Este programa dibuja el Sistema Solar de la Práctica 6 ***************//
//* pero con la incorporación de iluminación y materiales (no terminado) *//
//************************************************************************//
#include "Main.h"

// Variables utilizadas para calcular cuadros por segundo: (Ventanas)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables usadas para crear el movimiento

float sol, mercurio, venus, tierra, marte= 0.0;//variables a utilizar

float camaraZ = 0.0;
float camaraX = 0.0;
GLfloat LuzAmbientalSol[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Diffuse Light Values
GLfloat LuzDifusaSol[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular Light Values
GLfloat LuzEspecularSol[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // Light Position
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position(X,Y,Z, )

GLfloat LuzAmbientalMercurio[] = { 0.25f, 0.25f, 0.25f, 1.0f };
GLfloat LuzDifusaMercurio[] = { 0.4f, 0.4f, 0.4f, 1.0f }; // Mercurio =Cromo
GLfloat LuzEspecularMercurio[] = { 0.774597, 0.774597, 0.774597, 1.0 };
GLfloat MercurioShininess[] = { 0.6 };

GLfloat LuzAmbientalTierra[] = { 0.0f, 0.05f, 0.05f, 1.0f };
GLfloat LuzDifusaTierra[] = { 0.4f, 0.5f, 0.5f, 1.0f }; // Tierra =cyan rubber
GLfloat LuzEspecularTierra[] = { 0.04, 0.7, 0.7, 1.0 };
GLfloat TierraShininess[] = { 0.078125 };

GLfloat LuzAmbientalLuna[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LuzDifusaLuna[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // Luna
GLfloat LuzEspecularLuna[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat LunaShininess[] = { 50.0 };

GLfloat LuzAmbientalMarte[] = { 0.1745f, 0.1745f, 0.1745f, 1.0f };
GLfloat LuzDifusaMarte[] = { 0.61424f, 0.04136f, 0.04136f, 1.0f }; // Marte =ruby
GLfloat LuzEspecularMarte[] = { 0.727811, 0.626959, 0.626959, 1.0 };
GLfloat MarteShininess[] = { 0.6 };


void InitGL(GLvoid)//Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Negro de fondo

	glClearDepth(1.0f); // Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST); // Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL); // Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LuzAmbientalSol);				// Setup The Ambient Light Se inicializa la var 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LuzDifusaSol);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LuzEspecularSol);				// Setup The Diffuse Light

	glEnable(GL_LIGHT1);

}

void display(void)//Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ); //camara
	glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0); //El Sol gira sobre su eje y queda fuera para que los para que los planetas giren en traslacion
	glDisable(GL_LIGHTING);
	glPushMatrix();//Sol
	glColor3f(1.0, 1.0, 0.0); //Sol amarillo
	glutSolidSphere(1.9, 12, 12);//Draw Sun (radio,H,V); horizontal, vertical mientras mas vertices mas suave es la imagen:Esfera
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//Mercurio
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(3.2, 0, 0);//Traslación del pivote
	glRotatef(mercurio, 0, 1, 0);//Rotacion del planeta Mercurio
								 //glColor3f(0.5, 0.5, 0.5);//Color Gris
								 //glutSolidSphere(1.9, 12, 12);
	glMaterialfv(GL_FRONT, GL_AMBIENT, LuzAmbientalMercurio);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaMercurio);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularMercurio);
	glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);



	glutSolidSphere(0.3, 8, 8);//Radio del plantea

	glPopMatrix();

	glPushMatrix();//Venus
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(5.7, 0, 0);//Traslación del pivote
	glRotatef(venus, 0, 1, 0);//Rotacion del planeta Venus
	glColor3f(0.6, 0.4, 0);//Color Café fuerte
	glutSolidSphere(0.5, 8, 8);//radio del planeta

	glPopMatrix();

	glPushMatrix();//Tierra
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(7.9, 0, 0);//Traslación del pivote
	glRotatef(tierra, 0, 1, 0);//Rotacion del planeta Tierra
							   //glColor3f(0.3, 0.1, 0.8);//Color Azul
	glMaterialfv(GL_FRONT, GL_AMBIENT, LuzAmbientalTierra);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaTierra);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularTierra);
	glMaterialfv(GL_FRONT, GL_SHININESS, TierraShininess);
	glutSolidSphere(0.7, 8, 8);//Radio del planeta

	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//Marte
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(10.5, 0, 0);//Traslación del pivote
	glRotatef(marte, 0, 1, 0);//Rotacion del planeta Marte
							  //glColor3f(0.9, 0.4, 0);//Color Rojo
	glMaterialfv(GL_FRONT, GL_AMBIENT, LuzAmbientalMarte);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaMarte);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularMarte);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarteShininess);
	glutSolidSphere(0.4, 8, 8);//Radio del planeta

	glPopMatrix();
	glutSwapBuffers();

}

void animacion()//Permite el efecto de girar
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)//tiempo final
	{
		sol = sol - (5 % 10) % 360;// %= modulo al llegar a los 360° se reinicia la variable
								   //Velocidad de rotacion de los planetas, sus lunas correspondientes y los anillos para el caso de Saturno
		mercurio = mercurio - (6 % 500) % 360;//No tiene lunas o anillos, se divide entre 500 para bajar la velocidad
		venus = venus - (15 % 500) % 360;//No tiene lunas o anillos, se divide entre 500 para bajar la velocidad
		tierra = tierra - (8 % 500) % 360;//se divide entre 500 para bajar la velocidad
		marte = marte - (18 % 500) % 360;//se divide entre 500 para bajar la velocidad
		
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();//Regreso a la parte donde se dibuja
}

void reshape(int width, int height)//Creamos funcion Reshape
{
	if (height == 0) // Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION); // Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW); // Seleccionamos Modelview Matrix
								//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)//Create Keyboard Function
{
	switch (key) {
		//Movimientos de camara
	case 'w':
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i': //Movimientos de Luz
	case 'I':
		break;
	case 'k':
	case 'K':
		break;
		//Activamos/desactivamos luz
	case 'l':
	case 'L':
		break;
		//Cuando Esc es presionado...
	case 27:
		//Salimos del programa
		exit(0);
		break;
		// Cualquier otra
	default:
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)// Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP://Presionamos tecla ARRIBA...
		break;
	case GLUT_KEY_DOWN://Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT://Presionams tecla IZQUIERDA
		break;
	case GLUT_KEY_RIGHT://Presionamos tecla DERECHA
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)// Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500); // Tamaño de la Ventana
	glutInitWindowPosition(20, 60); //Posicion de la Ventana
	glutCreateWindow("Practica 7"); // Nombre de la Ventana
	InitGL(); // Parametros iniciales de la aplicacion
	glutDisplayFunc(display);//Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape); //Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard); //Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys); //Otras
	glutIdleFunc(animacion);//Nos aseguramos que se actualice la variable 
	glutMainLoop();// 

	return 0;
}