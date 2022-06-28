#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

int spd = 50;

int start=0;
int gameover=0;
int level = 0;

int score = 0;
int point = 0;

int dist = 0 ;

int rocket = 0;
int rocket1 = 0;
int dist1=0;
int rocket2 = +35;
int dist2=0;
int rocket3 = +70;
int dist3=0;

const int font=(int)GLUT_BITMAP_HELVETICA_18 ;


char s[30];
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void startGame(){
    //Star
    glColor3ub(255, 255, 255);
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2f(10, 55);
        glVertex2f(35, 10);
        glVertex2f(58, 30);
        glVertex2f(55, 40);
        glVertex2f(63, 39);
        glVertex2f(79, 36);
        glVertex2f(15, 65);
        glVertex2f(30, 50);
        glVertex2f(25, 75);
        glVertex2f(74, 70);
        glVertex2f(90, 25);
        glVertex2f(87, 70);
        glVertex2f(20, 15);
        glVertex2f(94, 90);
        glVertex2f(85, 74);
        glVertex2f(10, 93);
        glVertex2f(58, 70);
        glVertex2f(10, 15);
        glVertex2f(57, 80);
        glVertex2f(64, 15);
    glEnd();
    //Left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(23,100);
    glVertex2f(23,0);
    glEnd();
    //Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77,0);
    glVertex2f(77,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();
    //Score
    point++;
    if(point>30){
        point =0;
        score++;
    }

    //Print Score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(80.5,14,(void *)font,buffer);
    //Speed Print
    char buffer1 [50];
    sprintf (buffer1, "SPEED: %d", spd);
    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(80.5,10,(void *)font,buffer1);
    //level Print
    char level_buffer [50];
    sprintf (level_buffer, "LEVEL: %d", level);
    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(80.5,18,(void *)font,level_buffer);

    //Increase minimum Speed
    if(score % 10 == 0){
        int last = score /10;
        if(last!=level){
            level = score /10;
            spd=spd+5;
        }
    }

    //rocket utama
    glColor3f(0.000, 1.000, 1.000); //left wing
    glBegin(GL_POLYGON);
    glVertex2f(dist+24,rocket+1);
    glVertex2f(dist+24,rocket+4);
    glVertex2f(dist+26,rocket+6);
    glVertex2f(dist+26,rocket+3);
    glEnd();
    glColor3f(0.000, 1.000, 1.000); //right wing
    glBegin(GL_POLYGON);
    glVertex2f(dist+32,rocket+1);
    glVertex2f(dist+32,rocket+4);
    glVertex2f(dist+30,rocket+6);
    glVertex2f(dist+30,rocket+3);
    glEnd();
    glColor3f(1.000, 1.000, 1.000); //Body
    glBegin(GL_POLYGON);
    glVertex2f(dist+26,rocket+3);
    glVertex2f(dist+26,rocket+8);
    glVertex2f(dist+28,rocket+11);
    glVertex2f(dist+30,rocket+8);
    glVertex2f(dist+30,rocket+3);
    glEnd();


    //rocket 1
    glColor3f(1.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist1+24,rocket1+101);
    glVertex2f(dist1+24,rocket1+104);
    glVertex2f(dist1+26,rocket1+106);
    glVertex2f(dist1+26,rocket1+103);
    glEnd();
    glColor3f(1.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist1+32,rocket1+101);
    glVertex2f(dist1+32,rocket1+104);
    glVertex2f(dist1+30,rocket1+106);
    glVertex2f(dist1+30,rocket1+103);
    glEnd();
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist1+26,rocket1+103);
    glVertex2f(dist1+26,rocket1+108);
    glVertex2f(dist1+28,rocket1+111);
    glVertex2f(dist1+30,rocket1+108);
    glVertex2f(dist1+30,rocket1+103);
    glEnd();
    rocket1--;
    if(rocket1<-100){
        rocket1=0;
        dist1=dist;
    }
    //destroy check rocket 1
    if((abs(dist-dist1)<8) && (rocket1+100<rocket+8)){
            start = 0;
            gameover=1;
    }
    //rocket 2
    glColor3f(0.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist2+24,rocket2+101);
    glVertex2f(dist2+24,rocket2+104);
    glVertex2f(dist2+26,rocket2+106);
    glVertex2f(dist2+26,rocket2+103);
    glEnd();
    glColor3f(0.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist2+32,rocket2+101);
    glVertex2f(dist2+32,rocket2+104);
    glVertex2f(dist2+30,rocket2+106);
    glVertex2f(dist2+30,rocket2+103);
    glEnd();
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist2+26,rocket2+103);
    glVertex2f(dist2+26,rocket2+108);
    glVertex2f(dist2+28,rocket2+111);
    glVertex2f(dist2+30,rocket2+108);
    glVertex2f(dist2+30,rocket2+103);
    glEnd();
    rocket2--;
    if(rocket2<-100){
        rocket2=0;
        dist2=dist;
    }
    //destroy check rocket2
    if((abs(dist-dist2)<8) && (rocket2+100<rocket+8)){
            start = 0;
            gameover=1;
    }


    //rocket 3
    glColor3f(0.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist3+24,rocket3+101);
    glVertex2f(dist3+24,rocket3+104);
    glVertex2f(dist3+26,rocket3+106);
    glVertex2f(dist3+26,rocket3+103);
    glEnd();
    glColor3f(0.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist3+32,rocket3+101);
    glVertex2f(dist3+32,rocket3+104);
    glVertex2f(dist3+30,rocket3+106);
    glVertex2f(dist3+30,rocket3+103);
    glEnd();
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(dist3+26,rocket3+103);
    glVertex2f(dist3+26,rocket3+108);
    glVertex2f(dist3+28,rocket3+111);
    glVertex2f(dist3+30,rocket3+108);
    glVertex2f(dist3+30,rocket3+103);
    glEnd();
    rocket3--;
    if(rocket3<-100){
        rocket3=0;
        dist3=dist;
    }
    //destroy check rocket3
    if((abs(dist-dist3)<8) && (rocket3+100<rocket+8)){
            start = 0;
            gameover=1;
    }

}

void mainMenu(){
    //Star
    glColor3ub(255, 255, 255);
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2f(10, 55);
        glVertex2f(35, 10);
        glVertex2f(58, 30);
        glVertex2f(55, 40);
        glVertex2f(63, 39);
        glVertex2f(79, 36);
        glVertex2f(15, 65);
        glVertex2f(30, 50);
        glVertex2f(25, 75);
        glVertex2f(74, 70);
        glVertex2f(90, 25);
        glVertex2f(87, 70);
        glVertex2f(20, 15);
        glVertex2f(94, 90);
        glVertex2f(85, 74);
        glVertex2f(10, 93);
        glVertex2f(58, 70);
        glVertex2f(10, 15);
        glVertex2f(57, 80);
        glVertex2f(64, 15);
    glEnd();
    //rocket
    glColor3f(0.000, 1.000, 1.000); //left wing
    glBegin(GL_POLYGON);
    glVertex2f(24+25,1+30);
    glVertex2f(24+25,4+30);
    glVertex2f(26+25,6+30);
    glVertex2f(26+25,3+30);
    glEnd();
    glColor3f(0.000, 1.000, 1.000); //right wing
    glBegin(GL_POLYGON);
    glVertex2f(32+25,1+30);
    glVertex2f(32+25,4+30);
    glVertex2f(30+25,6+30);
    glVertex2f(30+25,3+30);
    glEnd();
    glColor3f(1.000, 1.000, 1.000); //Body
    glBegin(GL_POLYGON);
    glVertex2f(26+25,3+30);
    glVertex2f(26+25,8+30);
    glVertex2f(28+25,11+30);
    glVertex2f(30+25,8+30);
    glVertex2f(30+25,3+30);
    glEnd();
    //rocket1
    glColor3f(1.000, 0.000, 0.000); //left wing
    glBegin(GL_POLYGON);
    glVertex2f(24,1+40);
    glVertex2f(24,4+40);
    glVertex2f(26,6+40);
    glVertex2f(26,3+40);
    glEnd();
    glColor3f(1.000, 0.000, 0.000); //right wing
    glBegin(GL_POLYGON);
    glVertex2f(32,1+40);
    glVertex2f(32,4+40);
    glVertex2f(30,6+40);
    glVertex2f(30,3+40);
    glEnd();
    glColor3f(1.000, 1.000, 1.000); //Body
    glBegin(GL_POLYGON);
    glVertex2f(26,3+40);
    glVertex2f(26,8+40);
    glVertex2f(28,11+40);
    glVertex2f(30,8+40);
    glVertex2f(30,3+40);
    glEnd();
    //rocket2
    glColor3f(0.000, 1.000, 0.000); //left wing
    glBegin(GL_POLYGON);
    glVertex2f(24+50,1+40);
    glVertex2f(24+50,4+40);
    glVertex2f(26+50,6+40);
    glVertex2f(26+50,3+40);
    glEnd();
    glColor3f(0.000, 1.000, 0.000); //right wing
    glBegin(GL_POLYGON);
    glVertex2f(32+50,1+40);
    glVertex2f(32+50,4+40);
    glVertex2f(30+50,6+40);
    glVertex2f(30+50,3+40);
    glEnd();
    glColor3f(1.000, 1.000, 1.000); //Body
    glBegin(GL_POLYGON);
    glVertex2f(26+50,3+40);
    glVertex2f(26+50,8+40);
    glVertex2f(28+50,11+40);
    glVertex2f(30+50,8+40);
    glVertex2f(30+50,3+40);
    glEnd();
    //rocket3
    glColor3f(0.000, 0.000, 1.000); //left wing
    glBegin(GL_POLYGON);
    glVertex2f(24+25,1+55);
    glVertex2f(24+25,4+55);
    glVertex2f(26+25,6+55);
    glVertex2f(26+25,3+55);
    glEnd();
    glColor3f(0.000, 0.000, 1.000); //right wing
    glBegin(GL_POLYGON);
    glVertex2f(32+25,1+55);
    glVertex2f(32+25,4+55);
    glVertex2f(30+25,6+55);
    glVertex2f(30+25,3+55);
    glEnd();
    glColor3f(1.000, 1.000, 1.000); //Body
    glBegin(GL_POLYGON);
    glVertex2f(26+25,3+55);
    glVertex2f(26+25,8+55);
    glVertex2f(28+25,11+55);
    glVertex2f(30+25,8+55);
    glVertex2f(30+25,3+55);
    glEnd();
        //Text Information
        if(gameover==1){
            glColor3f(1.000, 0.000, 0.000);
            renderBitmapString(40,50,(void *)font,"GAME OVER");
            glColor3f(1.000, 0.000, 0.000);
            char buffer2 [50];
            sprintf (buffer2, "Your Score is : %d", score);
            renderBitmapString(37,46,(void *)font,buffer2);
        }
        glColor3f(1.000, 1.000, 0.000);
        renderBitmapString(40,80,(void *)font,"Rocket Game ");

        glColor3f(0.000, 1.000, 0.000);
        renderBitmapString(33,20,(void *)font,"Press SPACE to START");
        renderBitmapString(33,17,(void *)font,"Press ESC to Exit");
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    if(start==1){
        glClearColor(0.000, 0.000, 0.000,1);
        startGame();
    }
    else{
        mainMenu();
    }
    glFlush();
    glutSwapBuffers();
}
void specialkey(int key, int x, int y){
        switch (key) {
        case GLUT_KEY_PAGE_UP:
            spd=spd+2;
        case GLUT_KEY_PAGE_DOWN:
            if(spd>(50+(level*5)))
            spd=spd-2;
            break;
        case GLUT_KEY_DOWN:
            if(rocket>0)
            rocket=rocket-2;
            break;
        case GLUT_KEY_UP:
            if(rocket<100)
            rocket=rocket+2;
            break;
        case GLUT_KEY_LEFT:
            if(dist>=0){
                dist = dist - (spd/10);
                if(dist<0){
                    dist=-1;
                }
            }
            break;
        case GLUT_KEY_RIGHT:
            if(dist<=44){
                dist = dist + (spd/10);
                if(dist>44){
                    dist = 45;
                }
            }
            break;

        default:
                break;
        }

}

void processKeys(unsigned char key, int x, int y) {

      switch (key)
            {
                case ' ':
            if(start==0){
                start = 1;
                gameover = 0;
                spd = 50;
                point = 0;
                dist = 0 ;
                rocket = 0;
                rocket1 = 0;
                dist1=0;
                rocket2 = +35;
                dist2=0;
                rocket3 = +70;
                dist3=0;
                score=0;
                level=0;
            }
             break;

             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/spd,timer,0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,650);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Rocket Game");

    glutDisplayFunc(display);
    glutSpecialFunc(specialkey);
    glutKeyboardFunc(processKeys );

    glOrtho(0,100,0,100,-1,1);
     glClearColor(0,0,0,0);

    glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}
