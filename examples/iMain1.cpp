#include "iGraphics.h"
Image fbg;

void loadResources()
{
    iLoadImage(&fbg, "assets/images/fbackground.jpg");
    iResizeImage(&fbg, 800, 800);
}

/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
    // place your drawing codes here
    iClear();
    //iShowLoadedImage(0, 0, &fbg);
    //iWrapImage(&fbg, -2);
    iSetColor(250, 20, 0); // Red
    iText(140, 180, "Hello World");
    iShowImage(0, 0, "assets/images/home01.jpg");
    //iPoint(120,120, 10);
    //iLine(400,0, 0, 400);
    //iFilledCircle(50, 50, 50, 9999);
    //iFilledRectangle(100, 100, 50, 30);
    //double xm[]={79, 150, 150, 79};
    //double ym[]={459, 459, 800, 800};
    //iFilledPolygon(xm, ym, 4);
    //double xc[]={79, 150, 150, 79};
    //double yc[]={0, 0, 300, 300};
    //iFilledPolygon(xc, yc, 4);

    //iSetLineWidth(5);
    //iText(50, 60, "This is a text", GLUT_BITMAP_HELVETICA_18);
    
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // place your codes here
   // printf("%d,%d\n", mx, my);
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
   // printf("%d,%d\n", mx, my);
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
        printf("%d,%d\n", mx, my);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
        printf("%d,%d\n", mx, my);
    }
}
/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
  //  printf("%d,%d\n%d\n", mx, my, dir);
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    switch (key)
    {
    case 'q':
        // do something with 'q'
       // printf("%d\n", key);
        break;
    case 'A':
        // do something with 'q'
       // printf("%d\n", key);
        break;
    // place your codes for other keys here
    default:
        break;
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
    switch (key)
    {
    case GLUT_KEY_END:
        // do something
        break;
    // place your codes for other keys here
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    loadResources();
    // place your own initialization codes here.
    iInitialize(800, 800, "demo");
    iDraw();
    return 0;
}