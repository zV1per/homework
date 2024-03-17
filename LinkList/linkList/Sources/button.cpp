#include "button.h"

void button::checkMouseOver(int mouseX, int mouseY)
{
    isMouseOver = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
    if (isMouseOver) scale = 0.9f; 
    else scale = 1.0f; 
}

bool button::checkClick(int mouseX, int mouseY)
{
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
    {
        isMouseOver = false;
        scale = 1.0f;
        return true;
    }
    return false;
}


void button::draw()
{
    int scaledWidth = int(width * scale); 
    int scaledHeight = int(height * scale); 
    int scaledX = x + (width - scaledWidth) / 2; 
    int scaledY = y + (height - scaledHeight) / 2; 
    if (isMouseOver)
    {
        setlinecolor(RGB(0, 120, 215)); 
        setfillcolor(RGB(229, 241, 251)); 
    }
    else
    {
        setlinecolor(RGB(173, 173, 173)); 
        setfillcolor(RGB(225, 225, 225)); 
    }
    fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); 
    settextcolor(BLACK); 
    setbkmode(TRANSPARENT); 
    settextstyle(int(txt_size * scale), 0, _T("Î¢ÈíÑÅºÚ")); 
    int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2; 
    int textY = scaledY + (scaledHeight - textheight(_T("Î¢ÈíÑÅºÚ"))) / 2; 
    outtextxy(textX, textY, text.c_str()); 
}