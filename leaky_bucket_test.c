#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define OUTRATE 25
#define BUCKETSIZE 250


#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

char uc[2],rc[2],dc[2],unreg[25]="Unregulated packets=",reg[25]="Regulated packets=",dis[25]="Discarded packets=";
void display();
void lky_bckt();
void timer(int);
int a=0,m;
//int g[100],bucket_size[100],e=0,st[100];

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


void drawBitmapText( float x, float y, float z,char *string)
{
    char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++)
    {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void init()
{
   glClearColor(.1,1,.8,1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0,1000,0,600);
   glMatrixMode(GL_MODELVIEW);

}


int status[100];
int n,j,z=0;

float y_pos[100],y_pos1[100],x_pos[100],angle[100];
void draw(int x,int y)
 {
 
  for(j=0;j<n;j++)
   {
    if(y_pos[j]>-210)
     {
       glTranslatef(0,y_pos[j],0);
       glColor3f(1,0,1);
       glBegin(GL_POLYGON);
       glVertex2f(270,550);
       glVertex2f(270,500);
       glVertex2f(330,500);
       glVertex2f(330,550);
       glEnd();
       glLoadIdentity();
     }
    else if(status[j]==1)
     {
 char ch1[30]="Packet ";
char str2[2],str1[20]=" discarded";
str2[0]=j+48;
glClear(GL_COLOR_BUFFER_BIT);
  strcat(ch1,str2);
strcat(ch1,str1);
     glColor3f(0,0,1);
drawBitmapText(750,450,0,ch1);
       glTranslatef(x_pos[j],y_pos[j],0);
       glRotatef(angle[j],0.0f,0.0f,1.0f);
       glColor3f(1,0,0);
       glBegin(GL_POLYGON);
       glVertex2f(270,550);
       glVertex2f(270,500);
       glVertex2f(330,500);
       glVertex2f(330,550);
       glEnd();
       glLoadIdentity();
       glClearColor(0.8,1,.1,1);
     }


    }
glColor3f(0,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(250,599);
   glVertex2f(250,550);
   glVertex2f(350,550);
   glVertex2f(350,599);
   glEnd();
    glColor3f(0,0,1);
drawBitmapText(352,580,0,"HOST COMPUTER");
 glColor3f(0,0,1);
drawBitmapText(352,400,0,"UNREGULATED FLOW");


 
glColor3f(0,0,1);
drawBitmapText(750,400,0,unreg);

 
  glColor3f(0,0,1);

drawBitmapText(750,350,0,reg);

glColor3f(0,0,1);
drawBitmapText(750,300,0,dis);

   
   for(j=0;j<m;j++)
    {
     glTranslatef(0,y_pos1[j],0);
     glColor3f(0,1,0);
     glBegin(GL_POLYGON);
     glVertex2f(290,250);
     glVertex2f(290,220);
     glVertex2f(310,220);
     glVertex2f(310,250);
     glEnd();
     glLoadIdentity();
    }
  glColor3f(0,0,1);
drawBitmapText(352,150,0,"REGULATED FLOW");
glColor3f(0,0,1);
drawBitmapText(750,500,0,"Bucket size 250");
glColor3f(0,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(250,300);
   glVertex2f(270,200);
   glVertex2f(330,200	);
   glVertex2f(350,300);
   glEnd();
 
 }
void show1()
 {
                  glClear(GL_COLOR_BUFFER_BIT);
	           glLoadIdentity();
                int const w = glutGet(GLUT_WINDOW_WIDTH);
		int const h = glutGet(GLUT_WINDOW_HEIGHT);
       //  printf("\n%d--%d",w,h);
	
		glColor3f(0,0,1);
		drawBitmapText(3*w/10+50,4*h/4+60,0,"NMAM INSTITUTE OF TECHNOLOGY");
		glColor3f(0.7,0,1);
		drawBitmapText(3*w/10-20,6*h/6+30,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
		glColor3f(1,0.5,0);
		drawBitmapText(4*w/10,8*h/12+30,0.0,"A MINI PROJECT ON:");
		glColor3f(1,0,0);
		drawBitmapText(4*w/10,7*h/12+30,0.0,"Leaky Bucket Algorithm");
		glColor3f(1,0.5,0);
		drawBitmapText(5,180,0.0,"BY:");
		glColor3f(0.5,0,0.5);
		drawBitmapText(20,155,0.0,"1)SWEATHA P (USN:4NM16CS161)");
		drawBitmapText(20,130,0.0,"2)TERRIL J NAZARETH (USN:4NM16CS162)");
		drawBitmapText(20,105,0.0,"3)THRUPTHI D (USN:4NM16CS163)");
		glColor3f(0.5,0.2,0.2);
		drawBitmapText(7*w/10+10,150,0.0,"GUIDE NAME: Mrs. Shilpa MK");
		
		glColor3f(1,0.1,1);
		drawBitmapText(50,50,0.0,"PRESS 'C' TO START");
                glColor3f(1,0.1,1);
		drawBitmapText(50,10,0.0,"PRESS 'E' TO EXIT");
		glMatrixMode(GL_MODELVIEW);
 }



void display()
 {
if(z==0)
   { 
   show1();
   }
  else{
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   draw(50,50);
//printf("%f\t%f",y_pos[1],angle[1]);
//glutSwapBuffers();
//printf("%d",m);
}
   glFlush();
 }

int k=1,l,f=0;
void ke(unsigned char key,int x,int y){
  if(key=='c')
   {
   
     z=1;
printf("Enter the number of packets--");
    scanf("%d",&n);
    input(n);
    lky_bckt();
 uc[0]=n+48;
rc[0]=m+48;
dc[0]=a+48;
    strcat(unreg,uc);
   strcat(reg,rc);
   strcat(dis,dc);

glClearColor(0.8,1,.1,1);
    display();
   }
if(key=='e')
   exit(0);
 }
void timer(int x)
 {
  
glutPostRedisplay();
    glutTimerFunc(1000/5,timer,0);
    
if(z!=0){  
  
    for(j=0;j<=k;j++)
     {
      if(y_pos[j]<-250 && status[j]==1)
       {
        x_pos[j]-=25;
        angle[j]+=10;
       }
      if(j>0&&abs(y_pos[j-1]-y_pos[j])<100)
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
   if(y_pos[0]<-210)
    { 
     for(j=0;j<m;j++)
      {
  //if(y_pos[j]>-505){
       if(j>0&&abs(y_pos1[j-1]-y_pos1[j])<70)
         continue;
       y_pos1[j]-=10;
if(y_pos1[m-1]<-300)
       exit(0);

      }
     }
   if(k<n)
      k++;
  
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
            //bucket_size[j]=excess;
            }
            else
            {
               status[j]=1;
             a++;
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
                  //  bucket_size[j]=excess;
            	 m++;
                }
                else if(rem>0)
                {
                    excess+=rem;
                     printf("\nAt time=%d: %d KB are transferred",i,rem);
                      printf("\nRemaining bucket size is %d",excess);
                      //bucket_size[j]=excess;
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
    //int i;
  

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(1000,480);
//status[1]=1;
//status[2]=1;
    glutInitWindowPosition(0,0);
    glutCreateWindow("Leaky Bucket Algorithm");
   glutKeyboardFunc(ke);
    glutDisplayFunc(display);
  //glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
   init();
    glutMainLoop();
    return 0;
}
