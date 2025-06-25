#include "iGraphics.h"
#include <iostream>
#include "iSound.h"
using namespace std;

int bgSoundIdx = -1;
int ball_x = 300;
int ball_y = 300;
int velocity_y = 0;
int gravity = 1;
int thrust = -11;
int r, g, b;
int height1 = 120, gap = 150, height2 = 160;
int wall_x = 600, velocity_wall = -5, delay = 200;
int coll = 0;
int home = 1, start = 0, gover = 0, inst = 0;
int pause = 0;
Image heli;

void gamelogic();
void instruction();
void homepage()
{
    iShowImage(0, 0, "assets/images/homepage.png");
}

void startpage()
{
    iShowImage(0, 0, "assets/images/back.png");
    iShowLoadedImage(ball_x - 20, ball_y - 30, &heli);

    iSetColor(128, 78, 41);
    // wall_set01
    iFilledRectangle(wall_x, height1 + gap, 50, 600 - gap - height1);
    iFilledRectangle(wall_x, 0, 50, height1);
    // wall_set02
    iFilledRectangle(wall_x + delay, height2 + gap, 50, 600 - gap - height2);
    iFilledRectangle(wall_x + delay, 0, 50, height2);

    // sneaky trick
    iSetColor(0, 0, 0);
    iFilledRectangle(600, 0, 400, 600);

    if (coll >= 1 || ball_y + 40 > 600 || ball_y + 5 < 0)
    {
        gover = 1;
        start = 0;
        ball_x = 300;
        ball_y = 300;
        velocity_y = 0;
        gravity = 1;
        thrust = -10;
        height1 = 120;
        gap = 150;
        height2 = 160;
        wall_x = 600;
        velocity_wall = -5;
        delay = 200;
        coll = 0;
    }
}

int collision(int x1, int y1, int dx1, int dy1, int x2, int y2, int dx2, int dy2)
{
    if (x1 > x2 + dx2 || x1 + dx1 < x2 || y1 > y2 + dy2 || y1 + dy1 < y2)
        return 0;
    else
        return 1;
}

void gamelogic()
{
    if (start == 1)
    {
        // ball control
        velocity_y += gravity;
        ball_y -= velocity_y;

        // wall set movement

        wall_x += velocity_wall;

        // colission detection
        coll = 0;
        coll += collision(ball_x, ball_y, 70, 40, wall_x, height1 + gap, 50, 600 - gap - height1);
        coll += collision(ball_x, ball_y, 70, 40, wall_x, 0, 50, height1);
        coll += collision(ball_x, ball_y, 70, 40, wall_x + delay, height2 + gap, 50, 600 - gap - height2);
        coll += collision(ball_x, ball_y, 70, 40, wall_x + delay, 0, 50, height2);

        // scoring system

        // wall set renewal
        if (wall_x + 50 + delay <= 0)
        {
            wall_x = 600;
            height1 = rand() % (400 - 100 + 1) + 100;
            gap = rand() % (150 - 120 + 1) + 120;

            wall_x = 600;
            delay = rand() % (300 - 200 + 1) + 200;
            height2 = rand() % (400 - 100 + 1) + 100;
        }
    }
}

void iDraw()
{

    iClear();
    if (home == 1)
    {
        homepage();
    }
    else if (start == 1)
    {
        startpage();
    }
    else if (gover == 1)
    {
        iShowImage(0, 0, "assets/images/gameover.png");
    }
    else if (inst == 1)
    {
        iShowImage(0, 0, "assets/images/instruction.png");
    }
}

/*
    function iMouseMove() is called when the user presses and drags the mouse.
    (mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
    function iMouseMove() is called automatically when the mouse pointer is in motion
*/
void iMouseMove(int mx, int my)
{
    // place your code here
}
void iMouseWheel(int dir, int mx, int my)
{
}

/*
    function iMouse() is called when the user presses/releases the mouse.
    (mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    // printf("%d %d\n", mx, my);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (start == 1)
            velocity_y = thrust;

        if (home == 1 && (mx > 185 && mx < 415) && (my > 261 && my < 326))
        {
            home = 0;
            start = 1;
        }

        else if (start == 0 && (mx > 175 && mx < 427) && (my > 257 && my < 324))
        {
            gover = 0;
            start = 1;
        }
        else if (gover == 1 && (mx > 177 && mx < 421) && (my > 148 && my < 202))
        {
            gover = 0;
            home = 1;
        }
        else if (home == 1 && (mx > 185 && mx < 415) && (my > 68 && my < 105))
        {
            home = 0;
            inst = 1;
        }
        else if (inst == 1 && (mx > 7 && mx < 55) && (my > 555 && my < 590))
        {
            home = 1;
            inst = 0;
        }
    }
    if (start == 1 && pause == 0 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        iPauseTimer(0);
        pause = 1;
    }
    else if (start == 1 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && pause == 1)
    {
        iResumeTimer(0);
        pause = 0;
    }
}

/*
    function iKeyboard() is called whenever the user hits a key in keyboard.
    key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if (key == 'p')
    {
        // do something with 'q'
    }
    if (key == 'r')
    {
    }
    // place your codes for other keys here
}

/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F100, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    // place your codes for other keys here
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    iLoadImage(&heli, "assets/images/helisprite.png");

    iSetTimer(20, gamelogic);

    iInitialize(600, 600, "Ball Escape");

    iInitializeSound();

    bgSoundIdx = iPlaySound("assets/sounds/background.wav", true, 50);

    return 0;
}
