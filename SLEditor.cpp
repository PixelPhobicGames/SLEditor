#include "Data.hpp"
#include <cstring>
#include <stdio.h>

int main(int argc, char *argv[]){

	InitWindow(1280 , 720 , "SLEditor");
	SetTargetFPS(60);
	EditorInit();

	if (argc != 2){

		#ifdef Windows
		LevelData = LoadFile("C:/Editor/Blank/TileData.pak");
		#endif

		#ifdef Linux
		LevelData = LoadFile("/home/ewan/Editor/Blank/TileData.pak");
		#endif
	}
	else {
		LevelData = LoadFile(argv[1]);
	}

	for ( int i = 0 ; i <= LevelData.size(); i ++){
		if (LevelData[i] == L'|'){
			WorldWidth = i + 1;
			break;
		}
	}
	WorldHeight = LevelData.size() / WorldWidth ;

	char LevelDir[200];

	#ifdef Linux
	for ( int i = 0 ; i <= strlen(argv[1]) - 11; i ++){
		LevelDir[i] = argv[1][i];
	}
	#endif

	#ifdef Windows 
	for ( int i = 0 ; i <= strlen(argv[1]) - 13; i ++){
		LevelDir[i] = argv[1][i];
	}
	#endif

	LevelDir[strlen(LevelDir) - 2] = '\0';

	EditorLoadTiles(LevelDir);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		if (CopyProtection){
		if (Delay == 0){
			ClearBackground(ProGray);

			DrawRectangle(0,0,1280,30,DARKGRAY);
			DrawTextEx(EditorData.EditorFont, "SLEditor - Beta", {10 , 8}, 18, 2, WHITE);

			if (IsKeyDown(KEY_W))CameraY ++;
			if (IsKeyDown(KEY_S))CameraY --;

			if (IsKeyDown(KEY_A))CameraX --;
			if (IsKeyDown(KEY_D))CameraX ++;

			if (CameraY >= 0){
				CameraY = 0;
			}
			if (CameraX <= 0){
				CameraX = 0;
			}
			switch (EditorData.SceneId)
			{
				case 0:

					if (CreateButton(1 , PosCenter , 200 , "Create New Map")){
						for (int i = 0 ; i <= LevelData.size() ; i ++){
							if (LevelData[i] != L'0' && LevelData[i] != L'|'){
								LevelData[i] = L'0';
							}
						}
						EditorData.SceneId = 1;
					}

					if (CreateButton(1 , PosCenter , 320 , "Load Prev. Map")){
						EditorData.SceneId = 1;
					}


					if (CreateButton(1 , PosCenter , 440 , "Settings")){
						EditorData.SceneId = 2;
					}
					break;

				case 2:
					if (CreateCustomButton(GetScreenWidth() / 2 - 150 , 200 , 1 , "Hi Mode"))SetTargetFPS(120);
					if (CreateCustomButton(GetScreenWidth() / 2 - 50 , 200 , 1 , "Nr Mode"))SetTargetFPS(60);
					if (CreateCustomButton(GetScreenWidth() / 2 + 50 , 200 , 1 , "Lo Mode"))SetTargetFPS(30);

					if (CreateCustomButton(GetScreenWidth() / 2 - 50 , 500 , 1 , "Back")){
						EditorData.SceneId = 0;
						Delay = 15;
					}
					break;
				
				case 1:
					DrawTextEx(EditorData.EditorFont, "World Editor", {1280 / 2 - MeasureTextEx(EditorData.EditorFont, "WorldEditor" , 18 , 2).x / 2, 8}, 18, 2, WHITE);

					if (CreateBlankWindow(2 , 1 , "Editor")){
						
						DrawTexture(EditorTiles.Background0 , WindowPos[1].x,WindowPos[1].y + 35,WHITE);
						for (int x = (CameraX / (TileSize / 2 - 1)) - 5; x <= CameraX / (TileSize / 2 ) + WindowDimesions[1].x / (TileSize / 2) ; x++){
							for (int y =  (CameraY / (TileSize / 2)) * -1; y <= -1 * (CameraY / (TileSize / 2) ) + WindowDimesions[1].y / (TileSize / 2); y++){
								switch (LevelData[y * WorldWidth + x])
								{
									case L'1':
										DrawTextureEx(EditorTiles.Tile1 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'2':
										DrawTextureEx(EditorTiles.Tile2 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'3':
										DrawTextureEx(EditorTiles.Tile3 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'4':
										DrawTextureEx(EditorTiles.Tile4 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'5':
										DrawTextureEx(EditorTiles.Tile5 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'6':
										DrawTextureEx(EditorTiles.Tile6 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'7':
										DrawTextureEx(EditorTiles.Tile7 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'8':
										DrawTextureEx(EditorTiles.Tile8 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;
									case L'9':
										DrawTextureEx(EditorTiles.Tile9 , {WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY} , 0 ,  .5, WHITE);
										break;	
									default:
										if (ShowLines)DrawRectangleLines(WindowPos[1].x + (x * (TileSize / 2)) - CameraX , WindowPos[1].y + 35 + ( y * (TileSize / 2)) + CameraY, (TileSize / 2) , (TileSize / 2) , BLACK);
										break;
								}
							}
						}
						
						
						int YOff = ((WindowPos[1].y + 30));
						
						if (RectPenSelect){
							DrawRectangleLines(RectPenOldX - CameraX , RectPenOldY + CameraY  , GetMouseX() - WindowPos[1].x, GetMouseY() - YOff , RED);
						}

						DrawRectangle(WindowPos[1].x + WindowDimesions[1].x, WindowPos[1].y , 1280 , 720 , ProGray );
						DrawRectangle(WindowPos[1].x, WindowPos[1].y + WindowDimesions[1].y , 1280 , 720 , ProGray );
						DrawRectangle(WindowPos[1].x - WindowDimesions[1].x, WindowPos[1].y, 500, 500, ProGray );
						DrawRectangle(WindowPos[1].x - WindowDimesions[1].x, WindowPos[1].y + WindowDimesions[1].y, 500, 500, ProGray );



						if(GetCollision(WindowPos[1].x, WindowPos[1].y + 35 , WindowDimesions[1].x, WindowDimesions[1].y, GetMouseX() , GetMouseY() , 5 , 5) && IsMouseButtonDown(0)){
							switch (PenMode){
								case 1:
									LevelData[(((GetMouseY() - CameraY) - YOff) / (TileSize / 2)) * WorldWidth + (((GetMouseX()+ CameraX )- WindowPos[1].x) / (TileSize / 2))] = EditorTile;
									break;
								case 2:
									LevelData[(((GetMouseY() - CameraY) - YOff) / (TileSize / 2)) * WorldWidth + (((GetMouseX()+ CameraX )- WindowPos[1].x) / (TileSize / 2))] = EditorTile;
									LevelData[(((GetMouseY() - CameraY) - YOff) / (TileSize / 2) + 1) * WorldWidth + (((GetMouseX()+ CameraX )- WindowPos[1].x) / (TileSize / 2))] = EditorTile;
									LevelData[(((GetMouseY() - CameraY) - YOff) / (TileSize / 2) + 1) * WorldWidth + ((((GetMouseX()+ CameraX )- WindowPos[1].x) + 1) / (TileSize / 2))] = EditorTile;
									LevelData[(((GetMouseY() - CameraY) - YOff) / (TileSize / 2)) * WorldWidth + ((((GetMouseX()+ CameraX )- WindowPos[1].x) + 1 )/ (TileSize / 2))] = EditorTile;
									break;
							}
						}
						CreateBlankWindowHeader(2 , 1 , "Editor");
						

					}

					
					if (CreateBlankWindow(2 , 2 , "Tiles")){

					}
					if (CreateCustomButton(WindowPos[2].x, WindowPos[2].y + 35 , .5 , "Blank"))EditorTile = L'0';
					if (CreateCustomButton(WindowPos[2].x + 50, WindowPos[2].y + 35 , .5 , "Tile 1"))EditorTile = L'1';
					if (CreateCustomButton(WindowPos[2].x + 100, WindowPos[2].y + 35 , .5 , "Tile 2"))EditorTile = L'2';
					if (CreateCustomButton(WindowPos[2].x + 150, WindowPos[2].y + 35 , .5 , "Tile 3"))EditorTile = L'3';

					if (CreateCustomButton(WindowPos[2].x, WindowPos[2].y + 35 + 50 , .5 , "Tile 4"))EditorTile = L'4';
					if (CreateCustomButton(WindowPos[2].x + 50, WindowPos[2].y + 35 + 50, .5 , "Tile 5"))EditorTile = L'5';
					if (CreateCustomButton(WindowPos[2].x + 100, WindowPos[2].y + 35 + 50, .5 , "Tile 6"))EditorTile = L'6';
					if (CreateCustomButton(WindowPos[2].x + 150, WindowPos[2].y + 35 + 50, .5 , "Tile 7"))EditorTile = L'7';

					if (CreateCustomButton(WindowPos[2].x, WindowPos[2].y + 35 + 100 , .5 , "Tile 8"))EditorTile = L'8';
					if (CreateCustomButton(WindowPos[2].x + 50, WindowPos[2].y + 35 + 100, .5 , "Tile 9"))EditorTile = L'9';
					if (CreateCustomButton(WindowPos[2].x + 100, WindowPos[2].y + 35 + 100, .5 , "Collision"))EditorTile = L'Z';
					if (CreateCustomButton(WindowPos[2].x + 150, WindowPos[2].y + 35 + 100, .5 , "Plyr Spwn"))EditorTile = L'%';

					if (CreateCustomButton(WindowPos[2].x, WindowPos[2].y + 35 + 150 , .5 , "Damage T"))EditorTile = L'X';
					if (CreateCustomButton(WindowPos[2].x + 50, WindowPos[2].y + 35 + 150, .5 , "Transition"))EditorTile = L'T';
					if (CreateCustomButton(WindowPos[2].x + 100, WindowPos[2].y + 35 + 150, .5 , "Event 1"))EditorTile = L'O';
					if (CreateCustomButton(WindowPos[2].x + 150, WindowPos[2].y + 35 + 150, .5 , "Event 2"))EditorTile = L'P';

					if (CreateBlankWindow(2 , 3 , "Rend. Settings")){
						if(CreateCustomButton(WindowPos[3].x, WindowPos[3].y + 35 , .65 , "TileSize +")){
							TileSize ++;
						}
						if(CreateCustomButton(WindowPos[3].x + 67, WindowPos[3].y + 35 , .65 , "TileSize -")){
							if (TileSize != 10)TileSize --;
						}
						if(CreateCustomButton(WindowPos[3].x + (65 * 2) + 5, WindowPos[3].y + 35 , .65 , "Tog. Lines")){
							if (ShowLines){
								Delay = 5;
								ShowLines = false;
							}
							else {
								Delay = 5;
								ShowLines = true;
							}
						}

					}

					if (CreateBlankWindow(2 , 4, "Pen Mode")){
						if(CreateCustomButton(WindowPos[4].x, WindowPos[4].y + 35 , .5 , "T. Pen"))PenMode = 1;
						if(CreateCustomButton(WindowPos[4].x + 50, WindowPos[4].y + 35 , .5 , "Square"))PenMode = 2;

					}

					
					if (CreateBlankWindow(2 , 5, "File")){
						if(CreateCustomButton(WindowPos[5].x, WindowPos[5].y + 35 , .65 , "Save")){
							wofstream Outfile;
							Outfile.open(argv[1]);
							Outfile << LevelData << "\n";

							cout << "Level Saved :)" << "\n";

							Delay = 5;
						}
						if(CreateCustomButton(WindowPos[5].x + 65, WindowPos[5].y + 35 , .65 , "Restore")){
							LevelData = LoadFile(argv[1]);
						}
						if(CreateCustomButton(WindowPos[5].x + 65 * 2, WindowPos[5].y + 35 , .65 , "Wipe")){
							for (int i = 0 ; i <= LevelData.size() ; i ++){
								if (LevelData[i] != L'0' && LevelData[i] != L'|'){
									LevelData[i] = L'0';
								}
							}
						}
						if(CreateCustomButton(WindowPos[5].x + 65 * 3, WindowPos[5].y + 35 , .65 , "Backup")){
							int Random = GetRandomValue(1, 10000);
							system(FormatText("cp %s C:/Editor/Backups/%i.pak" , argv[1] , Random));
						}
						if(CreateCustomButton(WindowPos[5].x + 65 * 3, WindowPos[5].y + 35 , .65 , "Fix File")){
							for (int i = 0 ; i <= LevelData.size() ; i ++){
								if (LevelData[i] != L'0' && LevelData[i] != L'|' && LevelData[i] != L'1' && LevelData[i] != L'2' && LevelData[i] != L'3' && LevelData[i] != L'4' && LevelData[i] != L'5' && LevelData[i] != L'6' && LevelData[i] != L'7' && LevelData[i] != L'8' && LevelData[i] != L'9' && LevelData[i] != L'Z' && LevelData[i] != L'X' && LevelData[i] != L']' && LevelData[i] != L'%' && LevelData[i] != L'|'){
									LevelData[i] = L'0';
								}
							}
						}
					}

					if (CreateBlankWindow(2 , 6, "Para. Script")){
						if(CreateCustomButton(WindowPos[6].x, WindowPos[6].y + 35 , .65 , "Editor")){
							EditorData.SceneId = 4;
						}
						if(CreateCustomButton(WindowPos[6].x + 65, WindowPos[6].y + 35 , .65 , "Save")){

						}
					}

					break;

				case 4:
					// Script Editor
					if (CreateBlankWindow(2 , 7, "Para. Script")){
						DrawRectangle(WindowPos[7].x , WindowPos[7].y + 35 , WindowDimesions[7].x , WindowDimesions[7].y - 35 , BloodRed);

						if(CreateCustomButton( 50, 150 , .65 , "Back")){
							EditorData.SceneId = 1;
						}

						

					}

					break;
				default:
					break;
			}

			DrawTextEx(EditorData.EditorFont, "PixelPhobicGames", {10 , 700}, 18, 2, WHITE);
		}
		else {
			Delay --;
		}
		}
		else {
			ClearBackground(BLACK);
			DrawText("You Do Not have Acess to this Software.." , GetScreenWidth() / 2 - MeasureText("You Do Not have Acess to this Software.." , 20) / 2 , 100 , 20 , WHITE);
			DrawText("Delete This Software Now" , GetScreenWidth() / 2 - MeasureText("Delete This Software Now" , 20) / 2 , 150 , 20 , WHITE);
		}
		EndDrawing();
	}
	CloseWindow();
	
}

