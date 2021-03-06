#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujarTriangulos() {

	 glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0);

	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex3f(0, 0, 0);

	glColor3f(1, 1, 0);
	glVertex3f(0, -.5, 0);

	glColor3f(1, 0, 0);
	glVertex3f(-1, 0, 0);

	glColor3f(0, 0, 1);
	glVertex3f(-1, .5, 0);


	glEnd();

}

void dibujarPuntos() {
	glBegin(GL_POINTS);

	glColor3f(1, 1, 1);
	glVertex3f(0.5f, 0.1f, 0.0f);

	glColor3f(0, 0, 0);
	glVertex3f(0.55f, 0.1f, 0.0f);

	glEnd();


}

void dibujarLineas() {
	glBegin(GL_LINES);

	glColor3f(1, 1, 1);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.4f, 0.0f);
	glVertex3f(0.0f, 0.4f, 0.0);

	glColor3f(2, 0, 1);
	glVertex3f(0.2f, 0.5f, 0.0f);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-0.2f, 0.5f, 0.0f);


	glEnd();

}

void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP);

	glColor3f(0, 0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);

	glVertex3f(0, -0.2, 0);
	glVertex3f(0.3, -0.2, 0);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0, 0, 0);



	glColor3f(0, 0, 0);
	glVertex3f(0, 0, 0);
	
	glEnd();
}

void dibujarTringuloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1, 1, 1);
	glVertex3f(0, 0, 0);

	glVertex3f(-0.2, -0.2, 0);
	glVertex3f(0.2, 0.2, 0);
	glVertex3f(0.1, 0.0, 0.1);
	glVertex3f(0.0, 0.0, 0.0);

	glEnd();

}

void dibujarPoligono() {
	glBegin(GL_POLYGON);
	glColor3f(1, 0.8, 0);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159/180.0) - 0.7,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0) ;
	}

	glEnd();

	//NUBE 1
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.1,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.0,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	//NUBE 2

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.4,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.5,
			0.1*sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();


	/*
	glColor3f(0, 0, 0);
	glVertex3f(-0.8, 0.7, 0);
	glVertex3f(-0.8, 0.7, 0);
	glVertex3f(-0.5, 0.9, 0);
	glVertex3f(0.5, 0.9, 0);
	*/
	glEnd();

}

void dibujar() {
	//dibujarTriangulos();
	//dibujarPuntos();
	//dibujarLineas();
	//dibujarLineaContinua();
	//dibujarTringuloContinuo();
	dibujarPoligono();
}



void actualizar() {

}

int main()
{
	//Creamos una ventana
	GLFWwindow *window;

	//Si no se puede inicializar glfw
	//Iniciamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamosla ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	//Si nopodemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//ciclode dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(0, 181, 252, 0);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}