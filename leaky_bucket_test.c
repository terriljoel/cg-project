#include <stdio.h>
#include <stdlib.h>
#define OUTRATE 25
#define BUCKETSIZE 250


#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void display();

void timer(int);

void init()
{
   glClearColor(0.0,0.0,0.0,1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-500,500,-500,500);
   glMatrixMode(GL_MODELVIEW);

}


int status[100];
int n,j,m;


float y_pos[100],y_pos1[100],x_pos[100],angle[100];
void draw(int x,int y)
 {
  for(j=0;j<n;j++)
   {
    if(y_pos[j]>-510)
     {
       glTranslatef(0,y_pos[j],0);
       glColor3f(1,1,1);
       glBegin(GL_POLYGON);
       glVertex2f(-50,500);
       glVertex2f(-50,400);
       glVertex2f(50,400);
       glVertex2f(50,500);
       glEnd();
       glLoadIdentity();
     }
    else if(status[j]==1)
     {
       glTranslatef(x_pos[j],y_pos[j],0);
       glRotatef(angle[j],0.0f,0.0f,1.0f);
       glColor3f(1,0,0);
       glBegin(GL_POLYGON);
       glVertex2f(-50,500);
       glVertex2f(-50,400);
       glVertex2f(50,400);
       glVertex2f(50,500);
       glEnd();
       glLoadIdentity();
       glClearColor(0,0,0,1);
     }
    }
   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(-170,100);
   glVertex2f(-100,-100);
   glVertex2f(100,-100	);
   glVertex2f(170,100);
   glEnd();
   for(j=0;j<m;j++)
    {
     glTranslatef(0,y_pos1[j],0);
     glColor3f(1,1,1);
     glBegin(GL_POLYGON);
     glVertex2f(-25,25);
     glVertex2f(-25,-25);
     glVertex2f(25,-25);
     glVertex2f(25,25);
     glEnd();
     glLoadIdentity();
    }
 }

void display()
 {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   draw(50,50);
//printf("%f\t%f",y_pos[1],angle[1]);
//glutSwapBuffers();
//printf("%d",m);
   glFlush();
 }

int k=1,l,f=0;
void timer(int x)
 {
    glutPostRedisplay();
    glutTimerFunc(1000/5,timer,0);
    for(j=0;j<=k;j++)
     {
      if(y_pos[j]<-450 && status[j]==1)
       {
        x_pos[j]-=25;
        angle[j]+=10;
       }
      if(j>0&&abs(y_pos[j-1]-y_pos[j])<150)
        continue;
      if(f==0)
       {
        y_pos[j]-=15;
        f=1;
       }
      else
       {
        y_pos[j]-=50;
        f=0;
       } 
     }
   if(y_pos[0]<-500)
    { 
     for(j=0;j<m;j++)
      {
  //if(y_pos[j]>-505){
       if(j>0&&abs(y_pos1[j-1]-y_pos1[j])<70)
         continue;
       y_pos1[j]-=10;
      }
     }
   if(k<n)
      k++;
 }



struct packet{
    int arrtime;
    int weight;
}PACKET[15];

void input(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        //printf("\nEnter the arrival time--");
        //scanf("%d",&PACKET[i].arrtime);
PACKET[i].arrtime=i;
        printf("\nEnter the size of packet %d--",i);
        scanf("%d",&PACKET[i].weight);
    }
}


void lky_bckt()
{
    int rem=0,i,j=0;
    int excess=BUCKETSIZE;
    for(i=0;i<=30;i++)
    {
        if(PACKET[j].arrtime==i)
        {
            if(PACKET[j].weight<=excess)
            {
                rem=rem+PACKET[j].weight;
                excess=excess-PACKET[j].weight;
                  printf("\nAt time=%d: packet %d is inserted into the bucket",i,j+1);
                printf("\nRemaining bucket size is %d",excess);
                j++;
            }
            else
            {
               status[j]=1;
                 printf("\nAt time=%d: packet %d is discarded",i,j+1);
                 printf("\nPacket size is more than available bucket size");
                 j++;
            }
        }
            if(i%5==0)
            {
                if(rem>=OUTRATE)
                {
                    rem=rem-OUTRATE;
                    excess=excess+OUTRATE;
                    printf("\nAt time=%d: 25 KB are transferred",i);
                    printf("\nRemaining bucket size %d",excess);
            	 m++;
                }
                else if(rem>0)
                {
                    excess+=rem;
                     printf("\nAt time=%d: %d KB are transferred",i,rem);
                      printf("\nRemaining bucket size is %d",excess);
                      rem=0;
     			  m++;

                }


        }

    }
    while(rem!=0)
    {
        if(rem>=OUTRATE)
                {
                    rem=rem-OUTRATE;
                    excess=excess+OUTRATE;
                    printf("\nAt time=%d: 25 KB are transferred",i++);
                    printf("\nRemaining bucket size %d",excess);
                    m++;
                }
                else if(rem>0)
                {
                    excess+=rem;
                     printf("\nAt time=%d: %d KB are transferred",i++,rem);
                      printf("\nRemaining bucket size is %d",excess);
                      rem=0;
                      m++;

                }

    }
    printf("\n Bucket is empty");
}
int main(int argc,char **argv)
{
    //int n;
    printf("Enter the number of packets--");
    scanf("%d",&n);
    input(n);
    lky_bckt();

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
//status[1]=1;
//status[2]=1;
    glutInitWindowPosition(0,0);
    glutCreateWindow("Translation");
    glutDisplayFunc(display);
  //glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
   init();
    glutMainLoop();
    return 0;
}
