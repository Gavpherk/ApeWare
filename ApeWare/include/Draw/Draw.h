#pragma once

void DrawRect(int x, int y, int w, int h, RGBA color, int thickness);
void DrawCircle(int x, int y, int radius, RGBA* color, int segments, float thickness = 1.00f);
void DrawFilledRect(int x, int y, int w, int h, RGBA color);
void DrawCornerBox(int x, int y, int w, int h, int borderPx, RGBA color);
void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness);
void DrawLine(Vector2 from, Vector2 to, RGBA* color, int thickness);
void DrawString(char* string, int x, int y, RGBA* color);
bool LabeledSelectableList(const char* label, bool* changed, bool* opened, int* selected, const char* const items[], int items_count, float x);
namespace colors
{
    static RGBA red = RGBA(255, 0, 0, 255);
    static RGBA green = RGBA(0, 255, 0, 255);
    static RGBA blue = RGBA(0, 0, 255, 255);
    static RGBA white = RGBA(255, 255, 255, 255);
    static RGBA black = RGBA(0, 0, 0, 255);
}