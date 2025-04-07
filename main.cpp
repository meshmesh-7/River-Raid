void player_plane() {
    window w(2000, 1000, 5, 5);
    w.ChangeTitle("Plane Movement Test");

    int x = 960; // Starting X
    int y = 770; // Starting Y
    int speed = 10;

    while (true) {
        
        w.SetBrush(WHITE);    // or whatever your background color is
        w.SetPen(WHITE);      // match the pen too, in case any outlines show
        w.DrawRectangle(0, 0, 2000, 1000, FILLED); // fill the whole screen


        // Draw the plane at current (x, y)
        w.SetPen(LIGHTGRAY, 5);
        w.DrawLine(x, y, x + 80, y); // wingspan
        w.SetPen(BLACK);
        w.SetBrush(GRAY);
        w.DrawRectangle(x + 20, y + 30, x + 61, y + 81); // body
        w.DrawArc(x + 20, y + 60, x + 60, y, 0, 180, FILLED); // nose
        w.DrawTriangle(x + 20, y + 80, x + 60, y + 80, x + 40, y + 120); // tail
        w.DrawTriangle(x + 33, y + 105, x + 33, y + 130, x - 10, y + 130); // left back wing
        w.DrawTriangle(x + 47, y + 105, x + 47, y + 130, x + 90, y + 130); // right back wing
        w.DrawRectangle(x + 33, y + 105, x + 48, y + 131); // mid-wing connector

        // Left wing
        int ipX[] = { x + 20, x + 20, x - 60, x - 60 };
        int ipY[] = { y + 35, y + 75, y + 60, y + 50 };
        w.DrawPolygon(ipX, ipY, 4, FILLED);

        // Right wing
        int ipm[] = { x + 60, x + 60, x + 140, x + 140 };
        int ipn[] = { y + 35, y + 75, y + 60, y + 50 };
        w.DrawPolygon(ipm, ipn, 4, FILLED);

        if (GetKeyState(87)) {
            y -= speed; // Move up
        }
        if (GetKeyState(83)) {
            y += speed; // Move down
        }
        if (GetKeyState(65)) {
            x -= speed; // Move left
        }
        if (GetKeyState(68)) {
            x += speed; // Move right
        }
     

        w.UpdateBuffer();
        Pause(30);
      
    }
   
}
