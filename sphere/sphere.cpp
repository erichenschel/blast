#include <iostream>
#include <GL/glut.h>
using namespace std;

#define PI 3.14159

class Sphere {

    public:

        void display() {
        
            //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            //glColor3f(1.0, 1.0, 1.0);

            //glShadeModel(GL_FLAT);

            //getPoints();
            glutSwapBuffers();

        }

};

int main (int argc, char **argv) {
    printf("\nmade it this far\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Sphere");

    glutDisplayFunc(display);

    //s.initGL();
    glutMainLoop();
    return 0;
}

