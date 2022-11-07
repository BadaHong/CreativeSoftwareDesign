class Canvas {
        public:
                Canvas(size_t row, size_t col);
                ~Canvas();

                // Change this canvas size to w x h. Preserve already existing shapes on the canvas.
                void Resize(size_t w, size_t h);

                //Dot with thebrush at (x,y). If (x,y) is outside the canvas, just ignore it.
                bool DrawPixel(int x, int y, char brush);

                //Print out the canvas
                void Print();

                // Erase all(initialize with '.')
                void Clear();
        private:
                // Define data member to save drawn shapes(note the resize function)
                int row_, col_;
                char** canvas;
};

class Shape {
        public:
                virtual ~Shape();
                virtual void Draw(Canvas* canvas) {};
        protected:
                // Define common properties of shapes
                int x_, y_, width, height;
                char brush_;
};

class Rectangle : public Shape { /*Define required members*/
        public:
                Rectangle(int x, int y, int w, int h, char brush);
                virtual ~Rectangle();
                virtual void Draw(Canvas* canvas);
};

class UpTriangle : public Shape { /* Define required members*/
        public:
                UpTriangle(int x, int y, int h, char brush);
                virtual ~UpTriangle();
                virtual void Draw(Canvas* canvas);
};

class DownTriangle : public Shape { /* Define required members*/
        public:
                DownTriangle(int x, int y, int h, char brush);
                virtual ~DownTriangle();
                virtual void Draw(Canvas* canvas);
};

class Diamond : public Shape { /* Define required members*/
        public:
                Diamond(int x, int y, int dist, char brush);
                virtual ~Diamond();
                virtual void Draw(Canvas* canvas);
};
