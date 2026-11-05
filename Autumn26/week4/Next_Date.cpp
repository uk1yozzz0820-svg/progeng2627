#include <iostream>

bool leap_year(int year){
    bool ly;

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        ly = true;
    }
    else{
        ly = false;
    }

    return ly;
}

void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    int days_in_month;

    if(m1 == 2){
        if(leap_year(y1)){
            days_in_month = 29;
        }
        else{
            days_in_month = 28;
        }
    }
    else if(m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11){
        days_in_month = 30;
    }
    else{
        days_in_month = 31;
    }

    d2 = d1 + 1;
    m2 = m1;
    y2 = y1;

    if(d2 > days_in_month){
        d2 = 1;
        m2 = m1 + 1;
    }

    if(m2 > 12){
        m2 = 1;
        y2 = y1 + 1;
    }
}

int main(){
    int d1, m1, y1, d2, m2, y2;

    std::cout << "please enter a date (day month year):" << std::endl;
    std::cin >> d1 >> m1 >> y1;

    next_date(d1, m1, y1, d2, m2, y2);

    std::cout << "the next day is " << d2 << "/" << m2 << "/" << y2 << std::endl;
}
