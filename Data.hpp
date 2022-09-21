#include "Gui.hpp"

#define Linux



static wstring LevelData;

static float TileSize = 240;

static int WorldWidth = 0;
static int WorldHeight = 0;

static int BackgroundCount = 0;

static bool ShowLines = true;

static wchar_t EditorTile = L'1';

static int Delay = 0;


static float CameraX = 0;
static float CameraY = 0;

static int PenMode = 1;

static int RectPenOldX = 0;
static int RectPenOldY = 0;

static int RectPenSelect = false;

static bool CopyProtection = true;

class Tiles{
    public:
        Texture2D Tile1;
        Texture2D Tile2;
        Texture2D Tile3;
        Texture2D Tile4;
        Texture2D Tile5;
        Texture2D Tile6;
        Texture2D Tile7;
        Texture2D Tile8;
        Texture2D Tile9;

        Texture2D Background0;


};

static Tiles EditorTiles;

wstring LoadFile(const char *Path){
    wstring Data;
    wifstream OutFile;
    OutFile.open(Path);
    OutFile >> Data;
    return Data;
}
auto PullConfigValue(const char *Path , int ValueIndex){

    wstring Data = LoadFile(Path);
    int Counter = 0;
    bool KillLoop = false;
    
    int Value = 0;
    int Place = 1;

    for (int i = 0 ; i <= Data.size(); i++){

        if (Counter == ValueIndex){
            for (int x = i ; x <= Data.size() ; x++){
                switch (Data[x]){
                    case L'0':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        break;
                    case L'1':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 1;
                        break;
                    case L'2':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 2;
                        break;
                    case L'3':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 3;
                        break;
                    case L'4':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 4;
                        break;
                    case L'5':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 5;
                        break;
                    case L'6':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 6;
                        break;
                    case L'7':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 7;
                        break;
                    case L'8':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 8;
                        break;
                    case L'9':
                        Value = Value * Place;
                        if (Place != 10)Place = Place * 10;
                        Value += 9;
                        break;

                }

                if (Data[x] == L'|'){
                    KillLoop = true;
                    break;
                }
            }
        }
        if (Data[i] == L'|'){
            Counter ++;
        }

        if (KillLoop)break;

    }

    return Value;

}



void EditorInit(){
    #ifdef Windows 
        EditorData.EditorFont = LoadFont("C:/Editor/Fonts/TekoRegular.ttf");
    #endif
    #ifdef Linux
        EditorData.EditorFont = LoadFont("/home/ewan/Editor/Fonts/TekoRegular.ttf");
    #endif

    for (int i = 0 ; i <= 9 ; i ++){
        WindowPos[i].x = 500;
        WindowPos[i].y = 200;
        WindowDimesions[i].x = 500;
        WindowDimesions[i].y = 500;
    }
    WindowPos[1].x = 400;
    WindowPos[1].y = 50;

    WindowPos[2].x = 100;
    WindowPos[2].y = 50;
    WindowDimesions[2].x = 200;
    WindowDimesions[2].y = 500;

    WindowDimesions[3].x = 200;
    WindowDimesions[3].y = 100;
    WindowPos[3].x = 950;
    WindowPos[3].y = 450;

    WindowDimesions[4].x = 100;
    WindowDimesions[4].y = 350;
    WindowPos[4].x = 1000;
    WindowPos[4].y = 50;

    WindowDimesions[5].x = 450;
    WindowDimesions[5].y = 100;
    WindowPos[5].x = 100;
    WindowPos[5].y = 580;
}

void EditorLoadTiles(char LevelDir[200]){
    EditorTiles.Tile1 = LoadTexture(FormatText("%sTiles/Tile1.png" , LevelDir));
    EditorTiles.Tile2 = LoadTexture(FormatText("%sTiles/Tile2.png" , LevelDir));
    EditorTiles.Tile3 = LoadTexture(FormatText("%sTiles/Tile3.png" , LevelDir));
    EditorTiles.Tile4 = LoadTexture(FormatText("%sTiles/Tile4.png" , LevelDir));
    EditorTiles.Tile5 = LoadTexture(FormatText("%sTiles/Tile5.png" , LevelDir));
    EditorTiles.Tile6 = LoadTexture(FormatText("%sTiles/Tile6.png" , LevelDir));
    EditorTiles.Tile7 = LoadTexture(FormatText("%sTiles/Tile7.png" , LevelDir));
    EditorTiles.Tile8 = LoadTexture(FormatText("%sTiles/Tile8.png" , LevelDir));
    EditorTiles.Tile9 = LoadTexture(FormatText("%sTiles/Tile9.png" , LevelDir));

    #ifdef Windows 
        EditorTiles.Background0 = LoadTexture("C:/Editor/Assets/Test.png");
    #endif
    #ifdef Linux
        EditorTiles.Background0 = LoadTexture("/home/ewan/Editor/Assets/Test.png");
    #endif
    TileSize = PullConfigValue(FormatText("%sConfig/TileSize.slconf",LevelDir) , 0);
    BackgroundCount = PullConfigValue(FormatText("%sConfig/Background.slconf",LevelDir), 0);

}