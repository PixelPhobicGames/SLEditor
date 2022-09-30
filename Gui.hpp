#include <iostream>
#include <string>
#include <fstream>
#include <raylib.h>

static Color ProGray = {33,33,33,255};
static Color LightProGray = {66,66,66,255};
static Color BloodRed = {115, 9, 9,255};

static int PosCenter = 1;
static int PosRSide = 2;
static int WindowIndex = 0;

static Vector2 WindowPos[10];
static Vector2 WindowDimesions[10];

static bool DraggingWindow = false;

using namespace std;

bool GetCollision(int x, int y , int w, int h, int x2 , int y2 , int w2 , int h2){
    if( y+h <= y2 )
    {
        return false;
    }

    if( y >= y2+h2 )
    {
        return false;
    }

    if( x+w <= x2 )
    {
        return false;
    }

    if( x >= x2+w2 )
    {
        return false;
    }

    return true;

}


class Data{
    public:
        Font EditorFont;
        int SceneId = 0;
};

static Data EditorData;

bool CreateButton(float Size , float Pos , float YOff, const char *Text ){
    int X = 0;
    
    int Y = YOff;

    if (Size == PosCenter){
        X = (1280 / 2) - (Size * 180 / 2);
    }
    if (Size == PosRSide){
        X = 75;
    }
    DrawRectangle(X , Y , Size * 180 , Size * 100 , LightProGray);
    DrawTextEx(EditorData.EditorFont, Text, {X + ((Size * 180) / 2 ) - MeasureTextEx(EditorData.EditorFont, Text , Size * 18 , 2).x / 2 , Y + (( Size * 100 ) / 2) - Size * 10  }, Size * 18, 2, WHITE);

    if (!GetCollision(X , Y , Size * 180 , Size * 100 , GetMouseX() , GetMouseY() , 5 , 5 )){
        DrawRectangleLines(X , Y , Size * 180 , Size * 100 , WHITE);
    }
    else {
        DrawRectangleLines(X , Y , Size * 180 , Size * 100 , GRAY);
    }


    if (IsMouseButtonDown(0) && GetCollision(X , Y , Size * 180 , Size * 100 , GetMouseX() , GetMouseY() , 5 , 5 )){
        return true;
    }
    else {
        return false;
    }
}

bool CreateCustomButton( float PosX , float PosY, float Size , const char *Text ){
    int X = PosX;
    
    int Y = PosY;

    DrawRectangle(X , Y , Size * 100 , Size * 100 , LightProGray);
    DrawTextEx(EditorData.EditorFont, Text, {X + ((Size * 100) / 2 ) - MeasureTextEx(EditorData.EditorFont, Text , Size * 18 , 2).x / 2 , Y + (( Size * 100 ) / 2) - Size * 10  }, Size * 18, 2, WHITE);

    if (!GetCollision(X , Y , Size * 100 , Size * 100 , GetMouseX() , GetMouseY() , 5 , 5 )){
        DrawRectangleLines(X , Y , Size * 100 , Size * 100 , WHITE);
    }
    else {
        DrawRectangleLines(X , Y , Size * 100 , Size * 100 , GRAY);
    }


    if (IsMouseButtonDown(0) && GetCollision(X , Y , Size * 100 , Size * 100 , GetMouseX() , GetMouseY() , 5 , 5 )){
        return true;
    }
    else {
        return false;
    }
}

bool CreateBlankWindow(float Size , int WindowId , const char *Title ){
    int X = WindowPos[WindowId].x;
    
    int Y = WindowPos[WindowId].y;

    DrawRectangle(X , Y ,  WindowDimesions[WindowId].x, WindowDimesions[WindowId].y, BLACK);
    DrawRectangle(X , Y ,  WindowDimesions[WindowId].x, 35, LightProGray);

    DrawTextEx(EditorData.EditorFont, Title, {X + (WindowDimesions[WindowId].x / 2 ) - MeasureTextEx(EditorData.EditorFont, Title , 20 , 2).x / 2 , Y + 8  }, 20, 2, WHITE);

    if (IsMouseButtonDown(0) && GetCollision(X , Y ,  WindowDimesions[WindowId].x, WindowDimesions[WindowId].y - (WindowDimesions[WindowId].y - 35) , GetMouseX() , GetMouseY() , 5 , 5 )){
        if (DraggingWindow){
            WindowPos[WindowId].x = GetMouseX() - 30;
            WindowPos[WindowId].y = GetMouseY() - 15;
            DraggingWindow = false;
        }
        else {
            DraggingWindow = true;
        }
    }
    else {
        
    }

    return true;

}

bool CreateBlankWindowHeader(float Size , int WindowId , const char *Title ){
    int X = WindowPos[WindowId].x;
    
    int Y = WindowPos[WindowId].y;

    DrawRectangle(X , Y ,  WindowDimesions[WindowId].x, 35, LightProGray);

    DrawTextEx(EditorData.EditorFont, Title, {X + (WindowDimesions[WindowId].x / 2 ) - MeasureTextEx(EditorData.EditorFont, Title , 20 , 2).x / 2 , Y + 8  }, 20, 2, WHITE);

    if (IsMouseButtonDown(0) && GetCollision(X , Y ,  WindowDimesions[WindowId].x, WindowDimesions[WindowId].y - (WindowDimesions[WindowId].y - 35) , GetMouseX() , GetMouseY() , 5 , 5 )){
        if (DraggingWindow){
            WindowPos[WindowId].x = GetMouseX() - 30;
            WindowPos[WindowId].y = GetMouseY() - 15;
            DraggingWindow = false;
        }
        else {
            DraggingWindow = true;
        }
    }
    else {
        
    }

    return true;

}