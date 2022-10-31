using namespace std;

class Shape{
        public:
                Shape();
                Shape(int x, int y, int w, int h, string brush_);
                ~Shape();

                double GetArea();
                int GetPerimeter();
                void Draw(int canvas_width, int canvas_height);

        protected:
                int x_, y_, width, height;
                string brush;
                int canvas_w, canvas_h;
                string** canvas;
};

class Square: public Shape{
        public:
                Square(int x, int y, int l, string brush_);
                double GetArea();
                int GetPerimeter();
                void Draw(int canvas_width, int canvas_height);
};

class Rectangle: public Shape{
        public:
                Rectangle(int x, int y, int w, int h, string brush_);
                double GetArea();
                int GetPerimeter();
                void Draw(int canvas_width, int canvas_height);
};

class Diamond: public Shape{
        public:
                Diamond(int x, int y, int dist, string brush_);
                double GetArea();
                int GetPerimeter();
                void Draw(int canvas_width, int canvas_height);
};
