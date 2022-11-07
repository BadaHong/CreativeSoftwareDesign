#include <iostream>
#include "canvas.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col){
        row_ = row+1;
        col_ = col+1;
        canvas = new char*[row_];
        for(int i = 0; i < row_; i++){
                canvas[i] = new char[col_];
        }
        canvas[0][0] = ' ';
        for(int i = 1; i < row_; i++){
                int num = i % 10;
                if(num == 0){
                        canvas[i][0] = '9';
                }
                else{
                        canvas[i][0] = num+47;
                }
        }
        for(int i = 1; i < col_; i++){
                int num = i % 10;
                if(num == 0){
                        canvas[0][i] = '9';
                }
                else{
                        canvas[0][i] = num+47;
                }
        }
        for(int i = 1; i < row_; i++){
                for(int j = 1; j < col_; j++){
                        canvas[i][j] = '.';
                }
        }
}

Canvas::~Canvas(){
        for(int i = 0; i < row_; i++){
                delete[] canvas[i];
        }
        delete[] canvas;
}

void Canvas::Resize(size_t w, size_t h){
        row_ = h+1;
        col_ = w+1;
        canvas = new char*[row_];
        for(int i = 0; i < row_; i++){
                canvas[i] = new char[col_];
        }
        canvas[0][0] = ' ';
        for(int i = 1; i < row_; i++){
                int num = i % 10;
                if(num == 0){
                        canvas[i][0] = '9';
                }
                else{
                        canvas[i][0] = num+47;
                }
        }
        for(int i = 1; i < col_; i++){
                int num = i % 10;
                if(num == 0){
                        canvas[0][i] = '9';
                }
                else{
                        canvas[0][i] = num+47;
                }
        }
        for(int i = 1; i < row_; i++){
                for(int j = 1; j < col_; j++){
                        canvas[i][j] = '.';
                }
        }
}

bool Canvas::DrawPixel(int x, int y, char brush){
        if(x > 0 && x < col_ && y > 0 &&  y < row_){
                canvas[y][x] = brush;
                return true;
        }
        return false;
}

void Canvas::Print(){
        for(int i = 0; i < row_; i++){
                for(int j = 0; j < col_; j++){
                        cout << canvas[i][j];
                }
                cout << endl;
        }
}

void Canvas::Clear(){
        for(int i = 1; i < row_; i++){
                for(int j = 1; j < col_; j++){
                        canvas[i][j] = '.';
                }
        }
}

Shape::~Shape(){}

Rectangle::Rectangle(int x, int y, int w, int h, char brush){
        x_ = x;
        y_ = y;
        width = w;
        height = h;
        brush_ = brush;
}

Rectangle::~Rectangle(){}

void Rectangle::Draw(Canvas* canvas){
        for(int i = y_+1; i < y_+height+1; i++){
                for(int j = x_+1; j < x_+width+1; j++){
                        canvas->DrawPixel(j, i, brush_);
                }
        }
}

UpTriangle::UpTriangle(int x, int y, int h, char brush){
        x_ = x;
        y_ = y;
        height = h;
        width = h;
        brush_ = brush;
}

UpTriangle::~UpTriangle(){}

void UpTriangle::Draw(Canvas* canvas){
        int count = 1;
        int count2 = 1;
        for(int i = y_+1; i < y_ + height + 1; i++){
                int c = 0;
                for(int j = x_+1; j > x_ - height + 1; j--){
                        if(c < count){
                                canvas->DrawPixel(j, i, brush_);
                                c++;
                        }
                }
                count++;
                int c2 = 0;
                for(int k = x_+1; k < x_ + height + 1; k++){
                        if(c2 < count2){
                                canvas->DrawPixel(k, i, brush_);
                                c2++;
                        }
                }
                count2++;
        }
}

DownTriangle::DownTriangle(int x, int y, int h, char brush){
        x_ = x;
        y_ = y;
        height = h;
        width = h;
        brush_ = brush;
}

DownTriangle::~DownTriangle(){}

void DownTriangle::Draw(Canvas* canvas){
        int count = 1;
        int count2 = 1;
        for(int i = y_ + 1; i > y_ - height + 1; i--){
                int c = 0;
                for(int j = x_+1; j > x_ - height + 1; j--){
                        if(c < count){
                                canvas->DrawPixel(j, i, brush_);
                                c++;
                        }
                }
                count++;
                int c2 = 0;
                for(int k = x_+1; k < x_ + height + 1; k++){
                        if(c2 < count2){
                                canvas->DrawPixel(k, i, brush_);
                                c2++;
                        }
                }
                count2++;
        }
}

Diamond::Diamond(int x, int y, int dist, char brush){
        x_ = x;
        y_ = y;
        height = dist;
        width = dist;
        brush_ = brush;
}

Diamond::~Diamond(){}

void Diamond::Draw(Canvas* canvas){
        int count = 1;
        int count2 = 1;
        for(int i = y_+1; i <= y_ + height + 1; i++){
                int c = 0;
                for(int j = x_+1; j >= x_ - height + 1; j--){
                        if(c < count){
                                canvas->DrawPixel(j, i, brush_);
                                c++;
                        }
                }
                count++;
                int c2 = 0;
                for(int k = x_+1; k <= x_ + height + 1; k++){
                        if(c2 < count2){
                                canvas->DrawPixel(k, i, brush_);
                                c2++;
                        }
                }
                count2++;
        }

        int count3 = height+1;
        int count4 = height+1;
        for(int i = y_ + height + 1; i <= y_ + 2*height + 1; i++){
                int c = 0;
                for(int j = x_+1; j >= x_ - height + 1; j--){
                        if(c < count3){
                                canvas->DrawPixel(j, i, brush_);
                                c++;
                        }
                }
                count3--;
                int c2 = 0;
                for(int k = x_+1; k <= x_ + width + 1; k++){
                        if(c2 < count4){
                                canvas->DrawPixel(k, i, brush_);
                                c2++;
                        }
                }
                count4--;
        }
}

