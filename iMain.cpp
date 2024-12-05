# include "iGraphics.h"

int /*x = 300, y = 300, r = 15,*/i,n=3,R=254,G=254,B=254,t=0,r1=0,g1=0,b1=200,r2,g2,b2,j,showOrhide=1,ith,press=0,curveth=-1,
showith[10]={1,1,1,1,1,1,1,1,1},cball=1 ;
double f[10]={0.02,0.028,0.02,0.01,0.05,0.06,0.01,0.07,0.02},
       A[10]={15,25,15,15,10,14,5,9,36},
       phase[10]={1.5708,0,0,1.5708,0,1.5708,-0.7854,1.047,1.04},
       a,b=300,c=10,d[10]={},dc=8,s,speed=3,k=0,radius=8,
       red[10]={255,10,10,200,0,232,100,152,200},
       green[10]={10,255,10,255,255,0,232,165,140},
       blue[10]={10,10,255,0,255,232,80,80},
       /*color[10][3]*/Am=3,fm=3,ath;


/*
	function iDraw() is called again and again by the system.
*/
void iBall() {
    for(i=0;i<n;i++)
    {
       /* ith=i;
        if(i == ballNumber[ith])
            continue;*/
        iSetColor(red[i],green[i],blue[i]);

        if(showith[i])
        iFilledCircle(c,d[i],radius,1000);

    }

    /*iSetColor(10,10,255);
    iFilledCircle(c,d[1],8,1000);
    iSetColor(10,255,100);
    iFilledCircle(c,d[2],8,1000);
    iSetColor(100,255,255);
    iFilledCircle(c,d[3],8,1000);*/


    iSetColor(r1,g1,b1);
    if(cball)
    iFilledCircle(c,t,radius,100);
}

void iDraw()
{
    //place your drawing codes here
    iClear();
    /*iSetColor(20,200,255);
    iFilledCircle(x,y,r);*/
    iSetColor(20,255,200);
    iText(80,520,"Press p for pause and resume, f,a,n for increasing frequency ,Amplitude and number of waves",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(80,480,"And their upper cases for decrement.Use s to show or hide the lines and curves and vice versa.",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(80,440,"Use + and - key to control speed and up and down key to move the system vertically.",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(80,400,"Use R and r to control radius of the ball ,left and right key to change phase and press q to exit.",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(R,G,B);
    iLine(0,b,1200,b);
    for(a=0;a<1200;a=a+0.2)
    {
         k=0;
         for(i=0;i<n;i++)
         {
               iSetColor(R,G,B);
               iPoint(a,b+Am*A[i]*sin(fm*f[i]*(a)+phase[i]));
               k=k+Am*A[i]*sin(fm*f[i]*(a)+phase[i]);
         }
         iSetColor(R-127,G-127,B-127);
         iPoint(a,b+k);

    }
    if(showOrhide)
        iBall();
}

void iMotion()
{
    c+=speed*dc;
    t=0;

    for(i=0;i<n;i++)
    {
         d[i]=b+Am*A[i]*sin(fm*f[i]*(c)+phase[i]);
         t+=Am*A[i]*sin(fm*f[i]*(c)+phase[i]);
         /*red[i]=rand()%255;
         green[i]=rand()%255;
         blue[i]=rand()%255;*/
    }
    t+=b;
    if(c>=1195||c<=0)
    {
        dc=dc*(-1);
    }

}
/*void h()
{

    r1=rand()%255;
    g1=rand()%255;
    b1=rand()%255;

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/



void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
   /* for(a=0;a<=1600;a++)
        for(i=0;i<n;i++)
        {
            if(mx == a && my == b+Am*A[i]*sin(fm*f[i]*a+phase[i]))
                 A[i] =(my-b)/(Am*sin(fm*f[i]*a+phase[i]));

        }*/
        if (press ==1)
            A[curveth]=(my-b)/(Am*sin(fm*f[curveth]*ath+phase[curveth]));

        else if (press ==2)
        {
           /* f[curveth]=f[curveth]*ath/mx;*/
           if(mx> ath)
            {
               f[curveth]/=1.01;
               ath=mx;
            }
           else if(mx<ath)
            {
               f[curveth]*=1.01;
               ath=mx;
            }
        }
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
        press=0;
        for(a=0;a<=1200;a=a+1)
        for(i=0;i<n;i++)
        {
            if((mx == a) && (my >= b+Am*A[i]*sin(fm*f[i]*a+phase[i])-15) && (my <= b+Am*A[i]*sin(fm*f[i]*a+phase[i])+15))
                 {
                     curveth=i;
                     ath=a;
                     if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
                           press=1;
                     else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
                           press=2;

                 }
        }
   /* if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        x += 5;
        y += 5;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 5;
        y -= 5;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
}
void iKeyboard(unsigned char key)
{
    if(key == 'F')
        /*for(i=0;i<n;i++)
            f[i]-=0.005;*/
        fm/=1.25;
    if(key == 'A')
        for(i=0;i<n;i++)
            A[i]-=5;
        /*Am/=1.25;*/
    if(key == 'f')
        /*for(i=0;i<n;i++)
                f[i]+=0.005;*/
        fm*=1.25;
    if(key == 'a')
        for(i=0;i<n;i++)
                A[i]+=5;
       /* Am*=1.25;*/
    if(key == 's')
    {
        if((R%127 == 0) &&( G%127 == 0 )&&(B%127 == 0))
        {
            R=1;
            G=1;
            B=1;
        }
        else if(R==1 && G==1 && B==1)
        {
            R=254;
            G=254;
            B=254;
        }
    }
    if(key == 'p')
    {
        if(dc != 0)
        {
            s=dc;
            dc=0;
        }
        else if(dc == 0)
            dc=s;
    }
    if(key == 'R')
        radius*=1.2;
    if(key == 'r')
        radius/=1.2;
    if(key == 'n')
        n+=1;
    if(key == 'N')
        n-=1;
    if(key == '-')
    {
        speed/=1.2;
    }
    if(key == '+')
        speed*=1.2;
    if(key == 'b')
    {
        for(ith=0;ith<n;ith++)
            if(!showith[ith])
                showith[ith]=1;
            if(!cball)
                cball =1;
        if (showOrhide)
            showOrhide=0;
        else
            showOrhide=1;
        /*if(!showOrhide)
            for(ith=0; ith<n;ith++)
                ballNumber[ith]=ith;
        else
           for(ith=0; ith<n;ith++)
                ballNumber[ith]=-1;*/

    }
    if(key >= '1' && key <= '9')
    {

        ith= key- '1';
        if (!showOrhide)
            showOrhide=1;

        /*if(ballNumber[ith] == ith)
            ballNumber[ith] = -1;
        else
            ballNumber[ith] = ith;*/
        if(ith<n)
        {
            if(showith[ith])
                showith[ith] =0;
            else
                showith[ith] =1;
        }
        if(ith ==n)
        {
            if(cball)
                cball=0;
            else
                cball=1;
        }


        /*if(red[ith]!=0 && green[ith]!=0 && blue[ith]!=0)
        {
            color[ith][0]=red[ith];
            color[ith][1]=green[ith];
            color[ith][2]=blue[ith];
            red[ith]=0;
            green[ith]=0;
            blue[ith]=0;
        }
        else
        {
            red[ith]=color[ith][0];
            green[ith]=color[ith][1];
            blue[ith]=color[ith][2];
        }*/
    }
    /*if( key =='g')
        {
             if (cball)
               cball=0;
             else
                cball=1;

        }*/
   /* if(key == 't')
        iSetTimer(50,h);
    if(key == 'T')*/
    if(key == 'q')
    {
        exit(0);
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
    if(key == GLUT_KEY_UP)
    {
        b+=20;
    }
    if(key == GLUT_KEY_DOWN)
        b-=20;
    if(key == GLUT_KEY_LEFT)
    {
        for(i=0;i<n;i++)
            phase[i]+=1;
    }
    if(key == GLUT_KEY_RIGHT)
        for(i=0;i<n;i++)
            phase[i]-=1;
}


int main()
{
    //place your own initialization codes here.
    iSetTimer(50,iMotion);

    iInitialize(1200, 600, "Demo!");

    return 0;
}
