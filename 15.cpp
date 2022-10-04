#include <iostream>

using namespace std;

class Circle{
        private:
                double PI = 3.14;
                int x, y, r;
        public:
                double circleArea(int r){return PI * r * r;}
                double circlePeri(int r){return 2 * PI * r;}
};

class Rectangle{
        private:
                int xt, yt, xb, yb;
        public:
                int rectangleArea(int xt, int yt, int xb, int yb){int x = xb - xt; int y = yt - yb; return x * y;}
                int rectanglePeri(int xt, int yt, int xb, int yb){int x = xb - xt; int y = yt - yb; return 2 * (x + y);}
};

int main(){
        while(1){
                char shape;
                cout << "shape?" << endl;
                cin >> shape;

                if(shape == 'C'){
                        int x, y, r;
                        cin >> x >> y >> r;
                        Circle circle;
                        double area = circle.Circle::circleArea(r);
                        double peri = circle.Circle::circlePeri(r);
                        cout << "area: " << area << ", perimeter: " << peri << endl;
                }
                else if(shape == 'R'){
                        int xt, yt, xb, yb;
                        cin >> xt >> yt >> xb >> yb;
                        Rectangle rect;
                        int area = rect.Rectangle::rectangleArea(xt, yt, xb, yb);
                        int peri = rect.Rectangle::rectanglePeri(xt, yt, xb, yb);
                        cout << "area: " << area << ", perimeter: " << peri << endl;
                }
                else if(shape == 'Q'){
                        break;
                }
                cout << endl;
        }
        return 0;
}
