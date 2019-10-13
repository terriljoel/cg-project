#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void display();
void reshape(int,int);
void timer(int);
int i=10,j,m=5;
void init()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-500,500,-500,500);
   glMatrixMode(GL_MODELVIEW);

}

int status[100];
//

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
 glutInitWindowSize(500,500);
status[1]=1;
status[2]=1;
  glutInitWindowPosition(0,0);
  glutCreateWindow("Translation");
  glutDisplayFunc(display);
  //glutReshapeFunc(reshape);
  glutTimerFunc(0,timer,0);
  init();
  glutMainLoop();
  }
 float y_pos[100],y_pos1[100],x_pos[100],angle[100];
int status[100];
//status[1]=1;
void draw(int x,int y)
{
for(j=0;j<=i;j++){
if(y_pos[j]>-510){
glTranslatef(0,y_pos[j],0);
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
glBegin(GL_POLYGON);

    glVertex2f(-50,500);
	glVertex2f(-50,400);
	glVertex2f(50,400);
	glVertex2f(50,500);
glEnd();
glLoadIdentity();
   
}
}
glBegin(GL_POLYGON);

    glVertex2f(-170,100);
	glVertex2f(-100,-100);
	glVertex2f(100,-100	);
	glVertex2f(170,100);
glEnd();
   for(j=0;j<=m;j++){
glTranslatef(0,y_pos1[j],0);
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
printf("%f\t%f",y_pos[1],angle[1]);
//glutSwapBuffers();
glFlush();
}
/*void reshape(int w,int h)
{
   glViewport(0,0,(GLsize)w,(GLsize)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-10,10,-10,10);
   glMatrixMode(GL_MODELVIEW);
   }*/
int k=1,l,f=0;
void timer(int x)
{
   glutPostRedisplay();
  glutTimerFunc(1000/5,timer,0);
  /*if(y_pos!=-505){
    y_pos-=15;
printf("%f",y_pos);
}
else
   y_pos=500;
*/
for(j=0;j<=k;j++)
{
if(y_pos[j]<-510 && status[j]==1){
  x_pos[j]-=25;
  angle[j]+=10; }
  //if(y_pos[j]>-505){
   if(j>0&&abs(y_pos[j-1]-y_pos[j])<150)
   continue;
  if(f==0){
         y_pos[j]-=15;
         f=1;
         }
   else
      {
       y_pos[j]-=50;
       f=0;
      }

 

    }
if(y_pos[0]<-500){
for(j=0;j<=m;j++)
{
  //if(y_pos[j]>-505){
   if(j>0&&abs(y_pos1[j-1]-y_pos1[j])<70)
   continue;

         y_pos1[j]-=10;
   }}
if(k<=i)
  k++;
}
