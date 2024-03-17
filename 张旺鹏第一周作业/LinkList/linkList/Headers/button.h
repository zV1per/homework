#pragma once
#include <graphics.h>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class button
{
private:
    int x; 
    int y; 
    int width; 
    int height; 
    int txt_size;
    float scale; 
    bool isMouseOver; 
    wstring text; 

public:

    button(int x, int y, int width, int height, const wstring& text, int txt_size)
        : x(x), y(y), width(width), height(height), text(text), scale(1.0f), isMouseOver(false), txt_size(txt_size)
    {}

    void checkMouseOver(int mouseX, int mouseY);

    bool checkClick(int mouseX, int mouseY);

    void draw();
};