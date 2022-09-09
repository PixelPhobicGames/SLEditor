#include "Gui.hpp"


void EditorInit(){
    EditorData.EditorFont = LoadFont("Fonts/TekoRegular.ttf");

    for (int i = 0 ; i <= 9 ; i ++){
        WindowPos[i].x = 500;
        WindowPos[i].y = 200;
        WindowDimesions[i].x = 500;
        WindowDimesions[i].y = 500;
    }
    WindowDimesions[2].x = 200;
    WindowDimesions[2].y = 500;
}