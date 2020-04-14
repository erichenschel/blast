#include <stdio.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <math.h>

#define PI 3.14159

class Sphere {

    int lat=100, lng=100;
    float direction [4] = {0.0f, 2.0f, -1.0f, 1.0f};
    float intensity [4] = {0.7f, 0.7f, 0.7f, 1.0f};
    float ambient_intensity [4] = {0.3f, 0.3f, 0.3f, 1.0f};
    public:

        void initGL() {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

            glEnable(GL_DEPTH_TEST);

            glEnable(GL_LIGHTING);

            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);

            glEnable(GL_LIGHT0);
            

            glLightfv(GL_LIGHT0, GL_POSITION, direction);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, intensity);

            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


        }
        void display() {
        
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glColor3f(1.0, 1.0, 1.0);

            glShadeModel(GL_FLAT);

            getPoints();
            glutSwapBuffers();

        }

        void getPoints() {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

            for(int i=0; i < lat; i++) {
                float lat0 = PI * (-0.5f + (float) (i-1) / (float) (lat));
                float z0 = sin(lat0);
                float zr0 = cos(lat0);
                
                float lat1 = PI * (-0.5f + (float) (i) / (float) (lat));
                float z1 = sin(lat1);
                float zr1 = cos(lat1);
            
                glBegin(GL_QUAD_STRIP);
                
                for(int j=0; j < lng; j++) {
                    float lng = 2 * PI * ((float) (j - 1) / (float) (20 + 1));
                    float x = cos(lng);
                    float y = sin(lng);
                    glNormal3f(x * zr0, y * zr0, z0);
                    glVertex3f(x * zr0, y * zr0, z0);
                    glNormal3f(x * zr1, y * zr1, z1);
                    glVertex3f(x * zr1, y * zr1, z1);
                }

                glEnd();
            }
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

