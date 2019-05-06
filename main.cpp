#include<windows.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define mac(x,y) ((mat[x][y])+48)
void drawbox(int,int,int,int);

char str1[2000]="algorithm",str2[2000]="altruistic";
int mat[31][31],i,j,mini,m,n,k,count=-1,bcount=0,flag,col=0,smallalp=0;
char st[4]={0,0,0,0};
float xsz=12,ysz=8,xcof=-0.9,ycof=0.78,posbar=0.6;
int pstate=0,alstate=0,sp=500;

void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void mouse_click(int button, int state, int x, int y)//CHANGESTATE______________________
{

    if(button == GLUT_LEFT_BUTTON && state== GLUT_UP)
    {
        printf("%d %d \n",x,y);
        if(x>1215 && x<1297 && y>47 && y<72){pstate=3-pstate;glColor3f(1,1,1);drawbox(1215,47,1297,72);}
        if(x>945 && x<1148 && y>35 && y<62){posbar=(float)(x-945)/680+0.4;sp=950-(((double)x-945)*4.5);}
        if(x>1215 && x<1278 && y>114 && y<142){
                if(alstate==1){pstate=2;count++;}
                else if(alstate==2){pstate=2;bcount++;}
                glColor3f(1,1,1);drawbox(1212,114,1278,142);}
        if(x>1215 && x<1347 && y>185 && y<209){if(alstate==1)if(count>0)count--;
                else if(alstate==2){
                    if(bcount>0)bcount--;else alstate=1;
                }}
        if(x>1215 && x<1293 && y>255 && y<279){count=-1;bcount=0;alstate=1;pstate=2;}
    }
    //else if(button == GLUT_LEFT_BUTTON && state== GLUT_DOWN)
        //if(x>945 && x<1148 && y>35 && y<62){posbar=(float)(x-945)/680+0.4;sp=2000-(((double)x-945)*9.75);}
        //drawbox(1215,185,1347,209);
    //drawbox(1215,255,1293,279);
        glutSwapBuffers();

}
//_________________________________________________________DISPLAY
void drawline(int i,int j,int k,int n)
{


    if(i==k+1 && n==j)
    {
    glBegin(GL_TRIANGLES);//printf("yes");
        glVertex2f((float)j/xsz+xcof+0.02,ycof-(float)i/ysz+0.05);
        glVertex2f((float)n/xsz+xcof+0.02,ycof-(float)k/ysz);
        glVertex2f((float)n/xsz+xcof+0.03,ycof-(float)k/ysz);
        //glVertex2f((float)j/xsz+xcof,ycof-(float)i/ysz+0.03);
    glEnd();
    }
    else{
    glBegin(GL_QUADS);//printf("yes");
        glVertex2f((float)j/xsz+xcof,ycof-(float)i/ysz+0.02);
        glVertex2f((float)n/xsz+xcof+0.03,ycof-(float)k/ysz+0.02);
        glVertex2f((float)n/xsz+xcof+0.04,ycof-(float)k/ysz+0.03);
        glVertex2f((float)j/xsz+xcof,ycof-(float)i/ysz+0.03);
    glEnd();
    }
}
void drawsqr(int i,int j)
{
    glColor3f(0.5,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f((float)j/xsz+xcof,ycof-(float)i/ysz-0.02);
        glVertex2f((float)j/xsz+xcof,ycof-(float)i/ysz+0.08);
        glVertex2f((float)j/xsz+xcof+0.05,ycof-(float)i/ysz+0.08);
        glVertex2f((float)j/xsz+xcof+0.05,ycof-(float)i/ysz-0.02);

    glEnd();
}

void drawbox(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINE_LOOP);
        glVertex2f((double)x1*2/1350-1,2-(double)y1*2/690-1);
        glVertex2f((double)x1*2/1350-1,2-(double)y2*2/690-1);
        glVertex2f((double)x2*2/1350-1,2-(double)y2*2/690-1);
        glVertex2f((double)x2*2/1350-1,2-(double)y1*2/690-1);


    glEnd();
}


void draw()//___________________________________DRAW_____________
{

int k=0;
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glBegin(GL_LINES);
        glVertex2f(0.4,0.85);
        glVertex2f(0.7,0.85);
        glVertex2f(0.7,0.80);
        glVertex2f(0.7,0.90);
        glVertex2f(0.4,0.80);
        glVertex2f(0.4,0.90);
    glEnd();
    glColor3f(0.8,0,0);
    glBegin(GL_QUADS);
        glVertex2f(posbar+0.01,0.89);
        glVertex2f(posbar+0.01,0.81);
        glVertex2f(posbar-0.01,0.81);
        glVertex2f(posbar-0.01,0.89);
    glEnd();
    glPopMatrix();
    glColor3f(1,1,1);
    //glRasterPos2f(ycof,0.4);
    //glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'K');

    drawbox(1215,47,1297,72);
    drawbox(1215,114,1278,142);
    drawbox(1215,185,1347,209);
    drawbox(1215,255,1293,279);
    drawbox(950,300,1349,688);
    if(pstate==1)
    renderBitmapString(0.8,0.8,GLUT_BITMAP_TIMES_ROMAN_24,"PAUSE");
    else if(pstate==2)renderBitmapString(0.8,0.8,GLUT_BITMAP_TIMES_ROMAN_24,"PLAY");
    renderBitmapString(0.8,0.6,GLUT_BITMAP_TIMES_ROMAN_24,"STEP");
    renderBitmapString(0.8,0.4,GLUT_BITMAP_TIMES_ROMAN_24,"STEP BACK");
    renderBitmapString(0.8,0.2,GLUT_BITMAP_TIMES_ROMAN_24,"RESET");
    renderBitmapString(0.43,0.92,GLUT_BITMAP_HELVETICA_18,"ANIMATION SPEED");
    renderBitmapString(0.65,0.05,GLUT_BITMAP_HELVETICA_18,"REMARKS");
    glColor3f(0,1,0);
    for(i=0;i<=m;i++)
    {
        st[1]=(mat[i][0]%10)+48;
            st[0]=mat[i][0]/10?mat[i][0]/10+48:' ';
            renderBitmapString(+xcof,ycof-(float)i/ysz,GLUT_BITMAP_TIMES_ROMAN_24,st);
        glRasterPos2f(xcof-0.07+((float)smallalp/40),ycof+0.02-(float)i/ysz );
        if(i)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i-1]);
    }

    glColor3f(1,0,0);
    for(j=0;j<=n;j++)
    {
        st[1]=(mat[0][j]%10)+48;
            st[0]=mat[0][j]/10?mat[0][j]/10+48:' ';
            renderBitmapString((float)j/xsz+xcof,ycof,GLUT_BITMAP_TIMES_ROMAN_24,st);
        glRasterPos2f((float)j/xsz+xcof+0.02,ycof+0.13-((float)smallalp/40) );


        if(j)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[j-1]);
    }
//________________________________________________________________PROGRESSION
if(alstate==1)
{

if(pstate==1)count++;
if(count>=m*n)alstate=2;

}
if(alstate==2)
{
    if(pstate==1)
    bcount++;
}
flag=1;
    if(count!=-1)
    for(i=1;i<=m && flag;i++)
    for(j=1;j<=n && flag;j++)
    {
        if((i-1)==count/n && (j-1)==count%n)
            {
                flag=0;drawsqr(i-1,j-1);drawsqr(i-1,j);drawsqr(i,j-1);drawsqr(i,-1);drawsqr(-1,j);

                glColor3f(1,1,0);

            st[1]=(mat[i][j]%10)+48;
            st[0]=mat[i][j]/10?mat[i][j]/10+48:' ';
            renderBitmapString((float)j/xsz+xcof,ycof-(float)i/ysz,GLUT_BITMAP_TIMES_ROMAN_24,st);
            mini=min(min(mat[i-1][j-1],mat[i-1][j]),mat[i][j-1]);
            if(str1[i-1]==str2[j-1]){drawline(i,j,i-1,j-1);}
            else if(mini==mat[i-1][j]){drawline(i,j,i-1,j);}
            else if(mini==mat[i][j-1]){drawline(i,j,i,j-1);}
            else if(mini==mat[i-1][j-1]){drawline(i,j,i-1,j-1);}

    //WRITE EVERY STEPS BEING TAKEN HERE.................................................................
    if(str1[i-1]==str2[j-1]){renderBitmapString(0.45,-0.6,GLUT_BITMAP_HELVETICA_18,"characters being compared");
    renderBitmapString(0.45,-0.65,GLUT_BITMAP_HELVETICA_18,"are equal");}
    else{renderBitmapString(0.45,-0.65,GLUT_BITMAP_HELVETICA_18,"Characters are different");}

            break;
        }

        glColor3f(1,1,1);

            st[1]=(mat[i][j]%10)+48;
            st[0]=mat[i][j]/10?mat[i][j]/10+48:' ';

            renderBitmapString((float)j/xsz+xcof,ycof-(float)i/ysz,GLUT_BITMAP_TIMES_ROMAN_24,st);

    }
    i=m;j=n;k=bcount;//BACKTRACKING>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    while((i>0 || j>0) &&k--)
    {
        drawsqr(i,j);
        mini=min(min(mat[i-1][j-1],mat[i-1][j]),mat[i][j-1]);
        if(i!=0 && j!=0 && mat[i-1][j-1]==mini){drawline(i,j,i-1,j-1);drawsqr(i-1,j-1);i=i-1;j=j-1;}
        else if(j!=0 && mat[i][j-1]==mini){drawline(i,j,i,j-1);drawsqr(i,j-1);j=j-1;}
        else if(i!=0 ){drawline(i,j,i-1,j);drawsqr(i-1,j);i=i-1;}
    }
    if(i==0&&j==0)alstate=3;
    printf("%d %d %d \n",alstate,bcount,j);
    glColor3f(1,1,1);
    if(alstate==2)renderBitmapString(0.45,-0.3,GLUT_BITMAP_HELVETICA_18,"BACKTRACKING");
    if(alstate==3){renderBitmapString(0.45,-0.4,GLUT_BITMAP_HELVETICA_18,"Editions required to convert");
    renderBitmapString(0.45,-0.45,GLUT_BITMAP_HELVETICA_18,"one string to another is = ");
    st[1]=(mat[m][n]%10)+48;
            st[0]=mat[m][n]/10?mat[m][n]/10+48:' ';
    renderBitmapString(0.8,-0.45,GLUT_BITMAP_TIMES_ROMAN_24,st);}
    glutSwapBuffers();
}

void anim(int t)
{
    glutPostRedisplay();
    glutTimerFunc(sp,anim,1);
}

//_________________________________________________________MAIN

int main(int argc,char** argv)
{

    scanf("%s %s",str1,str2);//change it.............................
    while(strlen(str1)>22 || strlen(str2)>22)
    {
        printf("Enter Strings of lesser length : ");
        scanf("%s %s",str1,str2);
    }
    m=strlen(str1),n=strlen(str2);
    if(m>16 || n>14)
        {smallalp=1;xsz=18;ysz=12;}
    printf("     ");
    k=m*n;
    for(i=0;i<=m;i++)mat[i][0]=i;
    for(j=0;j<n;j++)printf("%c ",str2[j]);printf("\n\n  ");
    for(j=0;j<=n;j++)printf(" %d",mat[0][j]=j);printf("\n");

    for(i=1;i<=m;i++)
    {
        printf("%c  %d",str1[i-1],mat[i][0]);
        for(j=1;j<=n;j++)
        {
            mini=min(min(mat[i-1][j-1],mat[i-1][j]),mat[i][j-1]);
            if(str1[i-1]==str2[j-1])mat[i][j]=mat[i-1][j-1];
            else mat[i][j]=mini+1;
            printf(" %d",mat[i][j]);
        }
        printf("\n");
    }
    i=m;j=n;

    alstate=1;
    pstate=2;
   //--------------------------GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1350,690);
    glutInitWindowPosition(0,0);
    glutCreateWindow("EDIT DISTANCE");


    glClearColor(0,0.2,0,1);
    glEnable(GL_DEPTH_TEST);


    glutDisplayFunc(draw);
    glutMouseFunc(mouse_click);
    glutTimerFunc(1000,anim,1);



    glutMainLoop();
    return 0;
}

//_________________________________________________________MOUSE
