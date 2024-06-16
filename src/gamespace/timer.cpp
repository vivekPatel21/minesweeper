class Time{
    int seconds;
    
    Time(int seconds):seconds(seconds){};

    private:
        void increment(){
            seconds += 1;
        }
};
