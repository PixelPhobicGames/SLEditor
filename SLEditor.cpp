#include "Data.hpp"


int main(void){

	InitWindow(1280 , 720 , "SLEditor v.1");
	SetTargetFPS(60);
	EditorInit();


	while (!WindowShouldClose())
	{
		/* code */
		BeginDrawing();
		ClearBackground(ProGray);

		DrawRectangle(0,0,1280,30,DARKGRAY);
		DrawTextEx(EditorData.EditorFont, "SLEditor", {10 , 8}, 18, 2, WHITE);

		switch (EditorData.SceneId)
		{
			case 0:

				if (CreateButton(1 , PosCenter , 200 , "Create New Map")){
					EditorData.SceneId = 1;
				}

				if (CreateButton(1 , PosCenter , 320 , "Load Prev. Map")){
					EditorData.SceneId = 1;
				}


				if (CreateButton(1 , PosCenter , 440 , "Settings")){
					EditorData.SceneId = 2;
				}
				break;
			
			case 1:
				DrawTextEx(EditorData.EditorFont, "World Editor", {1280 / 2 - MeasureTextEx(EditorData.EditorFont, "WorldEditor" , 18 , 2).x / 2, 8}, 18, 2, WHITE);

				if (CreateBlankWindow(2 , 1 , "Editor")){

				}
				if (CreateBlankWindow(2 , 2 , "Tiles")){

				}
				CreateCustomButton(WindowPos[2].x, WindowPos[2].y + 35 , 1 , "Tile 1");
				CreateCustomButton(WindowPos[2].x + 100, WindowPos[2].y + 35 , 1 , "Tile 2");
				break;
			default:
				break;
		}

		DrawTextEx(EditorData.EditorFont, "PixelPhobicGames", {10 , 700}, 18, 2, WHITE);

		EndDrawing();
	}
	CloseWindow();
	
}