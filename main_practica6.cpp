//Semestre 2019 - 2
//*************************************************************//
//*************************************************************//
//************* Alumno (s): Cedillo Nájera Eric Rodrigo *******//
//*************	Práctica No. 6 ******//
//*************	Visual Studio 2017 ******//
//*************	Ejercicio Clase 6 ******//
//* Este programa dibuja un Sistema Solar *******//
//*  ***//
//*************************************************************//
#include "Main.h"

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

float sol, mercurio, venus, tierra, marte, jupiter, saturno, urano, luna1, luna2, luna3, anillo1, anillo2 = 0.0;//variables a utilizar


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f }; // Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f }; // Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)//Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Negro de fondo

	glClearDepth(1.0f); // Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST); // Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL); // Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display(void)//Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ); //camara
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0); //El Sol gira sobre su eje y queda fuera para que los para que los planetas giren en traslacion
	glPushMatrix();//Sol
	glColor3f(1.0, 1.0, 0.0); //Sol amarillo
	glutSolidSphere(1.9, 12, 12);//Draw Sun (radio,H,V); horizontal, vertical mientras mas vertices mas suave es la imagen:Esfera
	glPopMatrix();

	glPushMatrix();//Mercurio
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(3.2, 0, 0);//Traslación del pivote
	glRotatef(mercurio, 0, 1, 0);//Rotacion del planeta Mercurio
	glColor3f(0.5, 0.5, 0.5);//Color Gris
//glutSolidSphere(1.9, 12, 12);
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
	glColor3f(0.3, 0.1, 0.8);//Color Azul
	glutSolidSphere(0.7, 8, 8);//Radio del planeta

	glPushMatrix();//Luna
	glRotatef(tierra, 0, 1, 0);//Rotacion alrededor de la tierra
	glTranslatef(7.9, 0, 0);//Traslación del pivote
	glRotatef(luna1, 0, 1, 0);//Rotacion de la luna terrestre
	glColor3f(0.9, 1, 0.9);//Casi blanco
	glutSolidSphere(0.25, 8, 8);//radio de la luna

	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//Marte
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(10.5, 0, 0);//Traslación del pivote
	glRotatef(marte, 0, 1, 0);//Rotacion del planeta Marte
	glColor3f(0.9, 0.4, 0);//Color Rojo
	glutSolidSphere(0.4, 8, 8);//Radio del planeta

	glPushMatrix();//Luna1
	glRotatef(marte, 0, 1, 0);//Rotacion alrededor de Marte
	glTranslatef(10.5, 0, 0);//Traslación del pivote
	glRotatef(luna1, 0, 1, 0);//Rotacion de la luna1
	glColor3f(0.9, 1, 0.9);//Casi blanco
	glutSolidSphere(0.25, 8, 8);//radio de la luna

	glPopMatrix();
	glPushMatrix();//Luna2
	glRotatef(marte, 0, 1, 0);//Rotacion alrededor de Marte
	glTranslatef(11.5, 0, 0);//Traslación del pivote
	glRotatef(luna2, 0, 1, 0);//Rotacion de la luna terrestre
	glColor3f(0.9, 1, 0.9);//Casi blanco
	glutSolidSphere(0.25, 8, 8);//radio de la luna

	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//Júpiter
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(13.5, 0, 0);//Traslación del pivote
	glRotatef(jupiter, 0, 1, 0);//Rotacion del planeta Júpiter
	glColor3f(0.9, 0.5, 0.2);//Color Café claro
	glutSolidSphere(1, 8, 8);//Radio del planeta

	glPushMatrix();//Luna1
	glRotatef(jupiter, 0, 1, 0);//Rotacion alrededor de Marte
	glTranslatef(13.5, 0, 0);//Traslación del pivote
	glRotatef(luna1, 0, 1, 0);//Rotacion de la luna1
	glColor3f(0.9, 1, 0.9);//Casi blanco
	glutSolidSphere(0.35, 8, 8);//radio de la luna

	glPopMatrix();
	glPushMatrix();//Luna2
	glRotatef(jupiter, 0, 1, 0);//Rotacion alrededor de Marte
	glTranslatef(14.5, 0, 0);//Traslación del pivote
	glRotatef(luna2, 0, 1, 0);//Rotacion de la luna terrestre
	glColor3f(0.9, 1, 0.9);//Casi blanco
	glutSolidSphere(0.25, 8, 8);//radio de la luna

	glPopMatrix();
	glPushMatrix();//Luna3
	glRotatef(jupiter, 0, 1, 0);//Rotacion alrededor de Marte
	glTranslatef(15, 0, 0);//Traslación del pivote
	glRotatef(luna2, 0, 1, 0);//Rotacion de la luna terrestre
	glColor3f(0.9, 1, 0.9);//Casi blanco
	glutSolidSphere(0.25, 8, 8);//radio de la luna

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Saturno
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(18.5, 0, 0);//Traslación del pivote
	glRotatef(saturno, 0, 1, 0);//Rotacion del planeta Saturno
	glColor3f(0.9, 0.8, 0.4);//Color Café aún más claro
	glutSolidSphere(0.9, 8, 8);//Radio del planeta

	glPushMatrix();//Anillo1
	glRotatef(45, 1, 0, 0);//Angulo de rotación y  cambio de posición en el eje X
	glColor3f(0.9, 0.4, 0);//Color rojo
	glutSolidTorus(0.3, 0.8, 15, 15);//Toroide de :Radio interno 0.3, Radio externo 0.8
	glPopMatrix();
	glPushMatrix();//Anillo2
	glRotatef(45, 4, 0, 0);//Angulo de rotación y  cambio de posición en el eje X
	glColor3f(0.9, 0.5, 0.2);//Color rojo
	glutSolidTorus(0.4, 0.9, 15, 15);//Toroide de:Radio interno 0.4, Radio externo 0.9
	glPopMatrix();
	glPushMatrix();//Urano
	glRotatef(sol, 0, 1, 0);//Rotacion alrededor del sol
	glTranslatef(20.5, 0, 0);//Traslación del pivote
	glRotatef(urano, 0, 1, 0);//Rotacion del planeta Urano
	glColor3f(0.8, 1, 1);//Color Azul claro
	glutSolidSphere(0.8, 8, 8);//Radio del planeta
	glPopMatrix();

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
		sol = sol - (5 % 10) % 360;//%= modulo al llegar a los 360° se reinicia la var
		//Velocidad de rotacion de los planetas, sus lunas correspondientes y los anillos para el caso de Saturno
		mercurio = mercurio - (6 % 100) % 360;//No tiene lunas o anillos, se divide entre 100 para bajar la velocidad
		venus = venus - (15 % 100) % 360;//No tiene lunas o anillos, se divide entre 100 para bajar la velocidad
		tierra = tierra - (8 % 100) % 360;//se divide entre 100 para bajar la velocidad
		luna1 = luna1 - (8 % 100) % 360;//se divide entre 100 para bajar la velocidad
		marte = marte - (18 % 100) % 360;//se divide entre 100 para bajar la velocidad
		luna1 = luna1 - (18 % 100) % 360;//se divide entre 100 para bajar la velocidad
		luna2 = luna2 - (18 % 100) % 360;//se divide entre 100 para bajar la velocidad
		jupiter = jupiter - (13 % 100) % 360;//se divide entre 100 para bajar la velocidad
		luna1 = luna1 - (13 % 100) % 360;//se divide entre 100 para bajar la velocidad
		luna2 = luna2 - (13 % 100) % 360;//se divide entre 100 para bajar la velocidad
		luna3 = luna3 - (13 % 100) % 360;//se divide entre 100 para bajar la velocidad
		saturno = saturno - (12 % 100) % 360;//se divide entre 100 para bajar la velocidad
		anillo1 = anillo1 - (12 % 100) % 360;//se divide entre 100 para bajar la velocidad
		anillo2 = anillo2 - (12 % 100) % 360;//se divide entre 100 para bajar la velocidad
		urano = urano - (10 % 100) % 360;//No tiene lunas o anillos,//se divide entre 100 para bajar la velocidad
		//saturno = (saturno - 12) % 360;
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
	glutCreateWindow("Practica 6 - Sistema Solar hecho por Rodrigo"); // Nombre de la Ventana
	InitGL(); // Parametros iniciales de la aplicacion
	glutDisplayFunc(display);//Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape); //Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard); //Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys); //Otras
	glutIdleFunc(animacion);//Nos aseguramos que se actualice la variable 
	glutMainLoop();// 

	return 0;
}