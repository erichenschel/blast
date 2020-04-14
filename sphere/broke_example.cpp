#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159

class Sphere {
    float r;
    int lat=100, lng=100;
    int user_theta = 0;
    int user_height = 0;
    float direction [4] = {0.0f, 2.0f, -1.0f, 1.0f}; 
    float intensity [4] = {0.7f, 0.7f, 0.7f, 1.0f};
    float ambient_intensity [4]  = {0.3f, 0.3f, 0.3f, 1.0f};
    
    public:
        void initGL() {
            // Set 'clearing' or background color
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

            // set OpenGL parameters
            glEnable(GL_DEPTH_TEST);

            // Enable lighting
            glEnable(GL_LIGHTING);

            // Set light model
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);

            // Enable light number 0
            glEnable(GL_LIGHT0);

            // Set position and intensity of light
            glLightfv(GL_LIGHT0, GL_POSITION, direction);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, intensity);

            // Setup the material
            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        }

        void compute_location() {

            float x = 2 * cos(user_theta);
            float y = 2 * sin(user_theta);
            float z = user_height;
            float d = sqrt(x * x + y * y + z * z);

            // Set matrix mode
            glLoadIdentity();
            glFrustum(-d * 0.5f, d * 0.5f, -d * 0.5f, d * 0.5f, d - 1.1f, d + 1.1f);

            gluLookAt(x, y, z, 0, 0, 0, 0, 0, 1);
        }

        // Display the sphere
        void display () {
            
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            

            // Set color to white
            glColor3f(1.0, 1.0, 1.0);

            // Set shade model
            glShadeModel(GL_FLAT);

            draw();
            glutSwapBuffers();
        }

        void draw() {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

            for(int i; i < (20 + 1); i++) {
                float lat0 = PI * (-0.5f + (float) (i-1) / (float) (20 + 1));
                float z0 = sin(lat0);
                float zr0 = cos(lat0);

                float lat1 = PI * (-0.5f + (float) (i) / (float) (20 + 1));
                float z1 = sin(lat1);
                float zr1 = cos(lat1);

                glBegin(GL_QUAD_STRIP);

                for(int j; j < (20 + 1); j++) {
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

        void special (key, x, y) {
            // Scale the sphere up or down
            if(key == GLUT_KEY_UP) {
                user_height += 0.1f
            }
            if(key == GLUT_KEY_DOWN) {
                user_height -= 0.1f
            }

            // Rotate the cube
            if(key == GLUT_KEY_LEFT) {
                user_theta += 0.1f
            }
            if(key == GLUT_KEY_RIGHT) {
                user_theta -= 0.1f
            }

            // Toggle the surface
            if(key == GLUT_KEY_F1) {
                if(surface == GL_FLAT) {
                    surface = GL_SMOOTH;
                }
                else {
                    surface = GL_FLAT;
                }
            }
            glutPostRedisplay();
        }

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Sphere");
    glutDisplayFunc(draw());
    // initGL();
    glutMainLoop();
    return 0;
}
