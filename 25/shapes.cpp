#include <iostream>
#include <cmath>
#include <string>
#include "shapes.h"

using namespace std;

Shape::Shape(){}

Shape::~Shape(){
        for(int i = 0; i < canvas_h; i++){
                delete[] canvas[i];
        }
        delete[] canvas;
}

Shape::Shape(int x, int y, int w, int h, string brush_){
        x_ = x;
        y_ = y;
        width = w;
        height = h;
        brush = brush_;
}

double Shape::GetArea(){
        return double(width) * double(height);
}

int Shape::GetPerimeter(){
        return 2 * (width + height);
}

void Shape::Draw(int canvas_width, int canvas_height){
        canvas_w = canvas_width+1;
        canvas_h = canvas_height+1;
        canvas = new string*[canvas_h];
        for(int i = 0; i < canvas_h; i++){
                canvas[i] = new string[canvas_w];
        }
        canvas[0][0] = " ";
        for(int i = 1; i < canvas_h; i++){
                canvas[i][0] = to_string(i-1);
        }
        for(int i = 1; i < canvas_w; i++){
                canvas[0][i] = to_string(i-1);
        }
        for(int i = 1; i < canvas_h; i++){
                for(int j = 1; j < canvas_w; j++){
                        canvas[i][j] = ".";
                }
        }
}

Square::Square(int x, int y, int l, string brush_): Shape(x, y, l, l, brush_){}

double Square::GetArea(){
        return Shape::GetArea();
}

int Square::GetPerimeter(){
        return Shape::GetPerimeter();
}
void Square::Draw(int canvas_width, int canvas_height){
        Shape::Draw(canvas_width, canvas_height);
        int w = x_ + width + 1;
        int h = y_ + height + 1;
        if(h > canvas_h){
                h = canvas_h;
        }
        if(w > canvas_w){
                w = canvas_w;
        }
        for(int i = y_+1; i < h; i++){
                for(int j = x_+1; j < w; j++){
                        canvas[i][j] = brush;
                }
        }
        for(int i = 0; i < canvas_h; i++){
                for(int j = 0; j < canvas_w; j++){
                        cout << canvas[i][j];
                }
                cout << endl;
        }
}

Rectangle::Rectangle(int x, int y, int w, int h, string brush_): Shape(x, y, w, h, brush_){}

double Rectangle::GetArea(){
        return Shape::GetArea();
}

int Rectangle::GetPerimeter(){
        return Shape::GetPerimeter();
}

void Rectangle::Draw(int canvas_width, int canvas_height){
        Shape::Draw(canvas_width, canvas_height);
        int w = x_ + width + 1;
        int h = y_ + height + 1;
        if(h > canvas_h){
                h = canvas_h;
        }
        if(w > canvas_w){
                w = canvas_w;
        }
        for(int i = y_+1; i < h; i++){
                for(int j = x_+1; j < w; j++){
                        canvas[i][j] = brush;
                }
        }
        for(int i = 0; i < canvas_h; i++){
                for(int j = 0; j < canvas_w; j++){
                        cout << canvas[i][j];
                }
                cout << endl;
        }
}

Diamond::Diamond(int x, int y, int dist, string brush_): Shape(x, y, dist, dist, brush_){}

double Diamond::GetArea(){
        double w = (double)width;
        double h = (double)height;
        return ((2*w+1)*(2*h+1)) / 2;
}

int Diamond::GetPerimeter(){
        return 4 * (width+1);
}
void Diamond::Draw(int canvas_width, int canvas_height){
        Shape::Draw(canvas_width, canvas_height);
        int count = 1;
        int count2 = 1;
        for(int i = y_+1; i <= y_ + width + 1; i++){
                if(i >= canvas_h){
                        continue;
                }
                else{
                        int c = 0;
                        for(int j = x_+1; j >= x_ - width + 1; j--){
                                if(j < 1){
                                        continue;
                                }
                                else if(c < count){
                                        canvas[i][j] = brush;
                                        c++;
                                }
                        }
                        count++;
                        int c2 = 0;
                        for(int k = x_+1; k <= x_ + width + 1; k++){
                                if(k >= canvas_w){
                                        continue;
                                }
                                else if(c2 < count2){
                                        canvas[i][k] = brush;
                                        c2++;
                                }
                        }
                        count2++;
                }
        }
        int count3 = width+1;
        int count4 = width+1;
        for(int i = y_ + width + 1; i <= y_ + 2*width + 1; i++){
                if(i >= canvas_h){
                        continue;
                }
                else{
                        int c = 0;
                        for(int j = x_ + 1; j >= x_ - width +1; j--){
                                if(j < 1){
                                        continue;
                                }
                                else if(c < count3){
                                        canvas[i][j] = brush;
                                        c++;
                                }
                        }
                        count3--;
                        int c2 = 0;
                        for(int k = x_+1; k <= x_ + width + 1; k++){
                                if(k >= canvas_w){
                                        continue;
                                }
                                else if(c2 < count4){
                                        canvas[i][k] = brush;
                                        c2++;
                                }
                        }
                        count4--;
                }
        }
        for(int i = 0; i < canvas_h; i++){
                for(int j = 0; j < canvas_w; j++){
                        cout << canvas[i][j];
                }
                cout << endl;
        }
}
