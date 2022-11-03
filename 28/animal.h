using namespace std;

class Animal{
        public:
                Animal(string name_, int age_);
                virtual void printInfo();
        protected:
                string name;
                int age;
};

class Zebra: public Animal{
        public:
                Zebra(string name_, int age_, int numS);
                virtual void printInfo();
        private:
                int numStripes;
};

class Cat: public Animal{
        public:
                Cat(string name_, int age_, string favToy);
                virtual void printInfo();
        private:
                string favoriteToy;
};

