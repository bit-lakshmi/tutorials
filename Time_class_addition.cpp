#include<iostream>
#include<stdio.h>
#include<conio.h>

class Time{
    int hours;
    int minutes;
    int seconds;
    
    static int time_count;
    public: 
        Time(){
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        Time(int h, int m, int s){
            hours = h;
            minutes = m;
            seconds = s;
        }
        
        void GetTime(){
            
            std::cout << "Enter Hours";
            std::cin >> hours;
            std::cout << "Enter minutes";
            std::cin >> minutes;
            while((minutes > 59 || minutes < 0)){
                std::cout << "are you sane ?, add sane values";
                std::cin >> minutes;
            }
            
            std::cout << "Enter seconds";
            std::cin >> seconds;
            while((seconds > 59 || seconds < 0)){
                std::cout << "are you sane ?, add sane values";
                std::cin >> seconds;
            }
            
        }
        
        void showtime();
        static void time_counter();
        void Add_time(Time a,Time b){
            
            seconds = (a.seconds + b.seconds) % 60;
            minutes = ((a.minutes + b.minutes) % 60) + (a.seconds + b.seconds) / 60;
            hours = ((a.hours + b.hours) % 60) + (a.minutes + b.minutes) / 60;
        }
};

void Time::showtime(){
    std::cout << "Hours = " << hours << " Minutes = " << minutes << " Seconds = " << seconds;
}

void Time::time_counter(){
    std::cout << "Currently Time Objects are made = " << time_count;
}

int Time::time_count = 0;

int main(){
    Time A(5,6,7),B(3,50,20);
    Time C;
    C.GetTime();
    C.showtime();
    std::cout << "\n";
    
    C.Add_time(A,B);
    C.showtime();
    
    
}



