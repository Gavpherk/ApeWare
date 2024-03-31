#include "../../include/includes.h"
#include "Custom.h"

void ImGui::CentertedText(const char* text, ImVec2 size)
{
    ImVec2 p = ImGui::GetCursorPos();
    ImVec2 textsize = ImGui::CalcTextSize(text);
    ImGui::SetCursorPos(ImVec2{ size.x / 2 - textsize.x / 2 + p.x, size.y / 2 - textsize.y / 2 + p.y });
    ImGui::Text(text);
}

void ImGui::ColorWave(float speed, float ms, ImVec4 min, ImVec4 max, ImVec4* col)
{
    static std::chrono::steady_clock::time_point currentTime;
    static std::chrono::steady_clock::time_point lastTime;

    currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime);

    if (col->x < min.x)
        col->x = min.x;
    if (col->y < min.y)
        col->y = min.y;
    if (col->z < min.z)
        col->z = min.z;

    if (col->x > max.x)
        col->x = max.x;
    if (col->y > max.y)
        col->y = max.y;
    if (col->z > max.z)
        col->z = max.z;

    static int colqueue = 0;
    switch (colqueue)
    {
    case 0:
        if (col->z != max.z && col->y == min.y)
        {
            col->z += speed;
            if (timePassed.count() < ms)
                return;
        }

        lastTime = std::chrono::high_resolution_clock::now();
        colqueue++;
        break;
    case 1:
        if (col->z == max.z && col->x != min.x)
        {
            col->x -= speed;
            if (timePassed.count() < ms)
                return;
        }

        lastTime = std::chrono::high_resolution_clock::now();
        colqueue++;
        break;
    case 2:
        if (col->z == max.z && col->y != max.y && col->x == min.x)
        {
            col->y += speed;
            if (timePassed.count() < ms)
                return;
        }

        lastTime = std::chrono::high_resolution_clock::now();
        colqueue++;
        break;
    case 3:
        if (col->y == max.y && col->z != min.z)
        {
            col->z -= speed;
            if (timePassed.count() < ms)
                return;
        }

        lastTime = std::chrono::high_resolution_clock::now();
        colqueue++;
        break;
    case 4:
        if (col->z == min.z && col->x != max.x)
        {
            col->x += speed;
            if (timePassed.count() < ms)
                return;
        }

        lastTime = std::chrono::high_resolution_clock::now();
        colqueue++;
        break;
    case 5:
        if (col->x == max.x && col->y != min.y)
        {
            col->y -= speed;
            if (timePassed.count() < ms)
                return;
        }

        lastTime = std::chrono::high_resolution_clock::now();
        colqueue = 0;
        break;
    }
}

bool ImGui::ColorPicker3(const char* label, RGBA* col, ImGuiColorEditFlags flags)
{
    float col4[4] = { col->r, col->g, col->b, 1.0f };
    if (!ImGui::ColorPicker4(label, col4, flags | ImGuiColorEditFlags_NoAlpha))
        return false;
    col->r = col4[0]; col->g = col4[1]; col->b = col4[2];
    return true;
}

void ImGui::URLButton(const char* label, const char* url)
{
    std::string linkOpenFormat = std::string(std::string{ "explorer " } + (char)(34) + std::string{ url } + (char)(34)); //explorer "url"
    if (ImGui::Button(label))
        system(linkOpenFormat.c_str());
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Open %s in browser", url);
}