#include<iostream>
#include <graphics.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class circle_shapes{
public:
    int a,b,radius;
    int A,B,Xradius,Yradius,StartAngle,EndAngle;
    virtual void show(){
        circle(a,b,radius);
    }
};

class maincircle:public circle_shapes{
public:
    maincircle(int x,int y,int z){
        a=x;
        b=y;
        radius=z;
    }
    void show(){
        circle(a,b,radius);
    }
};

class HEllipse:public circle_shapes{
public:
    HEllipse(int t,int u,int w,int x){
        A=t;
        B=u;
        Xradius=w;
        Yradius=x;
        //StartAngle=y;
        //EndAngle=z;
    }
    void show(){
       // ellipse(A,B,StartAngle,EndAngle,Xradius,Yradius);
        fillellipse(A,B,Xradius,Yradius);
    }
};

class line_shapes{
public:
    int A,B,C,D;

    virtual void Print(){
        line(A,B,C,D);
    }
};

class HLine:public line_shapes{
public:
    HLine(int a,int b,int c,int d){
        A=a;
        B=b;
        C=c;
        D=d;
    }
    void Print(){
        line(A,B,C,D);
    }
};

class VLine:public line_shapes{
public:
    VLine(int a,int b,int c,int d){
        A=a;
        B=b;
        C=c;
        D=d;
    }
    void Print(){
        line(A,B,C,D);
    }
};

class polygon{
public:
    //int A,B,C,D,E,F,G,H;
    int points[8];
    virtual void display(){
        drawpoly(4,points);
    }
};

class triangle:public polygon{
public:
    triangle(int a,int b,int c,int d,int e,int f,int g,int h){
        points[0]=a;
        points[1]=b;
        points[2]=c;
        points[3]=d;
        points[4]=e;
        points[5]=f;
        points[6]=g;
        points[7]=h;
    }
    void display(){
        drawpoly(4,points);
    }
};

class rectangle_shapes{
public:
        int A,B,C,D;
        virtual void exhibit(){
            rectangle(A,B,C,D);
        }
};
class square:public rectangle_shapes{
public:
    square(int a,int b,int c,int d){
        A=a;
        B=b;
        C=c;
        D=d;
    }
    void exhibit(){
        rectangle(A,B,C,D);
    }
};

int main()
{
    cout<<"\t\t=====================INSTRUCTIONS====================="<<endl<<endl;
    cout<<"\t\t=====================CHALK TOOL====================="<<endl;
    cout<<"Hold press on small 'd' and click your mouse's left-key.(size 8 pixels)"<<endl;
    cout<<"Hold press on capital 'D' and click your mouse's left-key.(size 15 pixels)"<<endl<<endl;

    cout<<"\t\t=====================CIRCLE TOOL====================="<<endl;
    cout<<"Hold press on small 'c' and click your mouse's left-key.(radius 20 pixels )"<<endl;
    cout<<"Hold press on capital 'C' and click your mouse's left-key.(radius 40 pixels)"<<endl<<endl;

    cout<<"\t\t=====================ELLIPSE TOOL====================="<<endl;
    cout<<"Hold press on small 'q' and click your mouse's left-key.(Xradius 40 pixels,Yradius 10 pixels)"<<endl;
    cout<<"Hold press on capital 'Q' and click your mouse's left-key.(Xradius 60 pixels,Yradius 20 pixels)"<<endl<<endl;

    cout<<"\t\t=====================VERTICAL LINE TOOL====================="<<endl;
    cout<<"Hold press on small 'v' and click your mouse's left-key.(size 20 pixels)"<<endl;
    cout<<"Hold press on capital 'V' and click your mouse's left-key.(size maxdisplay/4 pixels)"<<endl<<endl;

    cout<<"\t\t=====================HORIZONTAL LINE TOOL====================="<<endl;
    cout<<"Hold press on small 'h' and click your mouse's left-key.(size 8 pixels)"<<endl;
    cout<<"Hold press on capital 'H' and click your mouse's left-key.(size maxdisplay/4 pixels)"<<endl<<endl;

    cout<<"\t\t=====================TRIANGLE TOOL====================="<<endl;
    cout<<"Hold press on small 't' and click your mouse's left-key for smaller triangle."<<endl;
    cout<<"Hold press on capital 'T' and click your mouse's left-key for bigger triangle."<<endl<<endl;

    cout<<"\t\t=====================SQUARE TOOL====================="<<endl;
    cout<<"Hold press on small 's' and click your mouse's left-key.(size 40 pixels)"<<endl;
    cout<<"Hold press on capital 'S' and click your mouse's left-key.(size 80 pixels)"<<endl<<endl;

    cout<<"\t\t=====================HORIZONTAL RECTANGLE TOOL====================="<<endl;
    cout<<"Hold press on small 'r' and click your mouse's left-key.(width 100 pixels,height 50 pixels)"<<endl;
    cout<<"Hold press on capital 'R' and click your mouse's left-key.(width 200 pixels,height 100 pixels)"<<endl<<endl;

    cout<<"\t\t=====================VERTICAL RECTANGLE TOOL====================="<<endl;
    cout<<"Hold press on small 'f' and click your mouse's left-key.(width 50 pixels,height 100 pixels)"<<endl;
    cout<<"Hold press on capital 'F' and click your mouse's left-key.(width 100 pixels,height 200 pixels)"<<endl<<endl;

    cout<<"\t\t=====================DUSTER TOOL====================="<<endl;
    cout<<"Hold press on small 'e' and click your mouse's left-key for smaller duster."<<endl;
    cout<<"Hold press on capital 'E' and click your mouse's left-key for bigger duster."<<endl<<endl;

    cout<<"\t\tPress small 'x' to toggle between the tools everytime"<<endl<<endl;

    cout<<"\t\tPress spacebar(' ') to save the chalkboard art"<<endl<<endl;

    cout<<"\t\ttPress capital 'L' to clear the whole chalkboard"<<endl<<endl;

    cout<<"\t\tPress capital 'P; to terminate the program"<<endl<<endl;


    cout<<"\t\tPress any key to start your sketch on the chalkboard!"<<endl;

    if(_getch()>=0 && _getch()<=255){
    char ch1,ch2;
    int mX,mY;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, " ",-3,-3);

    POINT cursorPosition;

    int mXX=getmaxx();
    int mYY=getmaxy();

    while(1){
    step1:ch1=getch();
    if(ch1=='d'){      //press 'p' to use smaller pencil tool
        while(ch1=='d'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                bar(mX,mY,mX+8,mY+8);
                delay(0);
            }
                if(getch()=='x'){   //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='D'){ //press 'P' to use bigger pencil tool
        while(ch1=='D'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                bar(mX,mY,mX+15,mY+15);
                delay(0);
            }
                if(getch()=='x'){   //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='c'){ //press small 'c' for smaller circle(radius 20)
        while(ch1=='c'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                setcolor(WHITE);
                maincircle C(mX,mY,20);
                C.show();
                delay(10);
            }
                if(getch()=='x')  //press 'x' to change tool
                    {
                        goto step1;
                }
        }
        getch();
    }
    else if(ch1=='C'){ // press capital 'C' to draw bigger circle(radius 40)
        while(ch1=='C'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                setcolor(WHITE);
                maincircle C(mX,mY,40);
                C.show();
                delay(10);
            }
                if(getch()=='x')  //press 'x' to change tool
                    {
                        goto step1;
                }
        }
        getch();
    }
    else if(ch1=='q'){ //press small 'q' to draw smaller ellipse(xradius 40,yradius 10)
        while(ch1=='q'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                HEllipse H(mX,mY,40,10);
                H.show();
                delay(10);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='Q'){ //press capital 'Q' to draw bigger ellipse(xradius 60,yradius 20)
        while(ch1=='Q'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                HEllipse H(mX,mY,60,20);
                H.show();
                delay(10);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='e'){ //press small 'e' for smaller eraser
        while(ch1=='e'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                for(int i=0;i<21;i++){
                    for(int j=0;j<21;j++){
                        putpixel(mX+i, mY+j, BLACK);
                    }
                }
                delay(0);
            }
            if(getch()=='x'){ //press 'x' to change tool
                goto step1;
            }
        }
    getch();
    }
    else if(ch1=='E'){ //press capital 'E' for bigger eraser
        while(ch1=='E'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                for(int i=0;i<41;i++){
                    for(int j=0;j<41;j++){
                        putpixel(mX+i, mY+j, BLACK);
                    }
                }
                delay(0);
            }
            if(getch()=='x'){ //press 'x' to change tool
                goto step1;
            }
        }
    getch();
    }
    else if(ch1=='v'){ //press small 'v' for smaller vertical line
        while(ch1=='v'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                VLine VL(mX,mY,mX,mY+20);
                VL.Print();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='V'){ //press capital 'V' for bigger vertical line
        while(ch1=='V'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                VLine VL(mX,mY,mX,(mYY/4));
                VL.Print();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='h'){ //press small 'h' for smaller horizontal line
        while(ch1=='h'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                HLine HL(mX,mY,mX+20,mY);
                HL.Print();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='H'){ //press capital 'H' for bigger horizontal line
        while(ch1=='H'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                HLine HL(mX,mY,(mXX/4),mY);
                HL.Print();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='t'){ //press small 't' for smaller triangle
        while(ch1=='t'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                triangle T(mX,mY,(mX+46),(mY+75),(mX-38),(mY+75),mX,mY);
                T.display();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='T'){ //press capital 'T' for bigger triangle
        while(ch1=='T'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                triangle T(mX,mY,(mX+93),(mY+150),(mX-77),(mY+150),mX,mY);
                T.display();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
        //closegraph();
    }
    else if(ch1=='s'){ //press small 's' for smaller square
        while(ch1=='s'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                square S(mX,mY,mX+40,mY+40);
                S.exhibit();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='S'){ //press capital 'S' for bigger square
        while(ch1=='S'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                square S(mX,mY,mX+80,mY+80);
                S.exhibit();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='r'){ //press small 'r' for smaller horizontal rectangle
        while(ch1=='r'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                square S(mX,mY,mX+100,mY+50);
                S.exhibit();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='R'){ //press capital 'R' for horizontal rectangle
        while(ch1=='R'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                square S(mX,mY,mX+200,mY+100);
                S.exhibit();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='f'){ //press small 'f' for smaller vertical rectangle
        while(ch1=='f'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                square S(mX,mY,mX+50,mY+100);
                S.exhibit();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1=='F'){ //press capital 'F' for bigger vertical rectangle
        while(ch1=='F'){
            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;
            if(GetAsyncKeyState(VK_LBUTTON)){
                square S(mX,mY,mX+100,mY+200);
                S.exhibit();
                delay(0);
            }
                if(getch()=='x'){  //press 'x' to change tool
                    goto step1;
                }
        }
        getch();
    }
    else if(ch1==' '){ //press spacebar to save image
        writeimagefile("image.jpg",0,0,mXX,mYY);    //for generating snapshot
        getch();
    }
    else if(ch1=='L'){ //press capital 'L' to clear the whole chalkboard
        cleardevice();
    }
    else if(ch1=='P'){ //press capital 'P' to terminate the program
        closegraph();
        return 0;
    }
   }
  }
  return 0;
}
