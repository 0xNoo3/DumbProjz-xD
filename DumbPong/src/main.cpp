#include<raylib.h>

class Ball
{
public:
    float x, y;
    float r;
    float xSpeed, ySpeed;

public:
    Ball(float x, float y, float r, float xs, float ys) : x(x) , y(y) , r(r) , xSpeed(xs) , ySpeed(ys) {}

    void Draw()
    {
        DrawCircle(x, y, r, WHITE);
    }

    void Update()
    {
        x += xSpeed;
        y += ySpeed;

        if(y + r >= GetScreenHeight() || y - r <= 0)
        {
            ySpeed *= -1;
        }
        if(x + r >= GetScreenWidth() || x - r <= 0)
        {
            xSpeed *= -1;
        }
    }

    float getDistance_ofBall()
    {
        return x;
    }
    float getHeight_ofBall()
    {
        return y;
    }
    float getRadius()
    {
        return r;
    }
    float getSpeedX()
    {
        return xSpeed;
    }
};

class Paddle
{
public:
    float x, y;
    float height, width;
    int speed;
protected:
    void LimitMovement()
    {
        if(y <= 0)
        {
            y = 0;
        }
        if(y + 120 >= GetScreenHeight())    // Why height is not working!
        {
            y = GetScreenHeight() - 120;
        }
    }
public:
    Paddle(int x, int y, float h, float w, int s) : x(x) , y(y) , height(h) , width(w) , speed(s) {}

    void Draw()
    {
        DrawRectangle(x, y, height, width, WHITE);
    }
    void Update()
    {
        if(IsKeyDown(KEY_UP))
        {
            y -= speed;
        }
        if(IsKeyDown(KEY_DOWN))
        {
            y += speed;
        }
        LimitMovement();
    }
    float xGet()
    {
        return x;
    }
    float yGet()
    {
        return y;
    }
    float getHeight()
    {
        return height;
    }
    float getWidth()
    {
        return width;
    }
};

class CPU_Paddle : public Paddle
{
public:
    CPU_Paddle(int x, int y, float h, float w, int s) : Paddle(x, y, h, w, s) {}

    void Update(int ball_y)
    {
        if(y + height/2 < ball_y)
        {
            y -= speed;
        }
        if(y + height/2 >= ball_y)
        {
            y += speed;
        }
        LimitMovement();
    }
};

int main()  {
    const int screen_height = 650;
    const int screen_width = 1200;
    InitWindow(screen_width, screen_height, "\t\tPong Game");
    int Xball = screen_width / 2;
    int Yball = screen_height / 2;
    Ball ball(Xball, Yball, 16, 7, 7);
    Paddle paddle(screen_width - 35, (screen_height/2) - (130/2), 25, 130, 10);
    CPU_Paddle cpu_paddle(10, (screen_height/2) - (130/2), 25, 200, 7);
    //10, (screen_height/2) - (130/2), 25, 130, 10
    //screen_width - 35, (screen_height/2) - (130/2), 25, 130, 7
    SetTargetFPS(70);
    Color torquoise = {20, 160, 133, 255};
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        DrawLine(Xball, 0, Xball, screen_height, WHITE);
        // float ball_x = ball.getDistance_ofBall();
        float ball_y = ball.getHeight_ofBall();
        // float r = ball.getRadius();
        // float speed = ball.getSpeedX();
        // float x = paddle.xGet();
        // float y = paddle.yGet();
        // float h = paddle.getHeight();
        // float w = paddle.getWidth();

        ball.Update();
        paddle.Update();
        cpu_paddle.Update(ball.y);

        if(CheckCollisionCircleRec(Vector2{ball.x , ball.y}, ball.r, Rectangle{paddle.x,paddle.y,paddle.width,paddle.height}))
        {
            ball.xSpeed *= -1;
        }

        // if(CheckCollisionCircleRec(Vector2{ball_x , ball_y}, r, Rectangle{x,y,w,h}))
        // {
        //     speed *= -1;
        // }

        // x = cpu_paddle.xGet();
        // y = cpu_paddle.yGet();
        // h = cpu_paddle.getHeight();
        // w = cpu_paddle.getWidth();

        // if(CheckCollisionCircleRec(Vector2{ball_x , ball_y}, r, Rectangle{x,y,w,h}))
        // {
        //     speed *= -1;
        // }

        ClearBackground(torquoise);
        paddle.Draw();
        // DrawCircle(Xball, Yball, 16, WHITE);
        ball.Draw();
        // DrawRectangle(screen_width - 35, (screen_height/2) - (130/2), 25, 130, WHITE);
        cpu_paddle.Draw();
        // DrawRectangle(10, (screen_height/2) - (130/2), 25, 130, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}