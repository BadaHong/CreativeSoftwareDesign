#include <iostream>
#include <string>
#include "shapes.h"

using namespace std;

int main(){
        int size1, size2;
        cin >> size1 >> size2;
        string input;
        while(1){
                cin >> input;
                if(input == "square"){
                        int x, y, l;
                        string brush;
                        cin >> x >> y >> l >> brush;
                        Square square(x, y, l, brush);
                        cout << "Area: " << square.Square::GetArea() << endl;
                        cout << "Perimeter: " << square.Square::GetPerimeter() << endl;
                        square.Square::Draw(size1, size2);
                }
                else if(input == "rect"){
                        int x, y, w, h;
                        string brush;
                        cin >> x >> y >> w >> h >> brush;
                        Rectangle rect(x, y, w, h, brush);
                        cout << "Area: " << rect.Rectangle::GetArea() << endl;
                        cout << "Perimeter: " << rect.Rectangle::GetPerimeter() << endl;
                        rect.Rectangle::Draw(size1, size2);
                }
                else if(input == "diamond"){
                        int x, y, dist;
                        string brush;
                        cin >> x >> y >> dist >> brush;
                        Diamond dia(x, y, dist, brush);
                        cout << "Area: " << dia.Diamond::GetArea() << endl;
                        cout << "Perimeter: " << dia.Diamond::GetPerimeter() << endl;
                        dia.Diamond::Draw(size1, size2);
                }
                else if(input == "quit"){
                        break;
                }
        }
        return 0;
}
