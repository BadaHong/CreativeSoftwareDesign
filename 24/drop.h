class Planet{
        public:
                Planet(float gravity);// Implement to store necessary data as member variable
                float drop(float height);// Returns the time elapsed to drop an objectfrom a specific height
        protected:
                float gravity_, time;
};

class Earth: public Planet{
        public:
                Earth();// Implement to call the parent class's constructor properly
        void simulate(float height);// Print  out  information  about this  object  (ex. \u2018Earth  gravity  =  9.81\u2019)and  the  result  of  drop simulation(\u2018Drop from 30m, 2.4731 seconds.\u2019).
};

class Moon: public Planet{
        public:
                Moon();// Implement  to  call  the  parent  class's  constructor properly
                void simulate(float height);// Print  out  information  about this object(ex.  'Moongravity  =  1.62')and  the  result  of  drop simulation(\u2018Drop from 30m, 6.08581 seconds.\u2019).
};
