#include<raylib.h>

int main() {
    const int screen_height = 600;
    const int screen_width = 800;
    InitWindow(screen_width,screen_height,"TITLE");
    Color torquoise = {20, 160, 133, 255};
    SetTargetFPS(200);
    int x = 500/2;
    int y = 500/2;
    int r = 15;
    // int move_x, move_y;
    while (!WindowShouldClose())
    {
        // move_x = x;
        // move_y = y;
        if(IsKeyDown(KEY_UP))
        {
            y -= 4;
            // move_y = y;
        }
        else if(IsKeyDown(KEY_DOWN))
        {
            y += 4;
            // move_y = y;
        }
        if(IsKeyDown(KEY_LEFT))
        {
            x -= 4;
            // move_x = x;
        }
        else if(IsKeyDown(KEY_RIGHT))
        {
            x += 4;
            // move_x = x;
        }

        if(x + r >= GetScreenWidth())
        {
            x -= GetScreenWidth();
            // move_x = x;
        }
        else if(x + r <= 0)
        {
            x += GetScreenWidth();
            // move_x = x;
        }

        if(y + r >= GetScreenHeight())
        {
            y -= GetScreenHeight();
            // move_y = y;
        }
        else if(y + r <= 0)
        {
            y += GetScreenHeight();
            // move_y = y;
        }

        // if(!(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT)))
        // {
        //     BeginDrawing();
        //     // move_y++; move_x++;
        //     DrawCircle(move_x, move_y, r, YELLOW);
        //     ClearBackground(torquoise);
        //     EndDrawing();
        //     continue;
        // }
        

        BeginDrawing();
        DrawCircle(x, y, r, YELLOW);

        ClearBackground(torquoise);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}