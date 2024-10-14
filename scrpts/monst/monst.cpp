#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib> 
#include <chrono>
#include <thread>

using namespace std;

void timedate(){
    system("clear"); // refresh display

    time_t now = time(nullptr); // current time
    tm* localTime = localtime(&now);// local time
    char time[50]; // time
    strftime(time, sizeof(time), "%H:%M:%S", localTime);
    char date[50]; // date
    strftime(date, sizeof(date), "%Y %b %d", localTime);

    printf("Current local time: \n\t\t%s\n\t\t%s\n\n", date, time);
}

void battery(){
    int chargestatus = system("cat /sys/class/power_supply/BAT1/status");
    int chargepercent = system("cat /sys/class/power_supply/BAT1/capacity");
    int chargemax = system("cat /sys/class/power_supply/BAT1/charge_control_end_threshold");

    // float outOf10 = (chargepercent/chargemax)*10; // tells how much the bar should be filled up
    // char batbar[10]; // bar init
    // for(int i = 0; i < 10; i++){
    //     if (i < outOf10){
    //         batbar[i] = '#';
    //     } else if ( (outOf10-int(outOf10)) >= 0.5) {
    //         batbar[i] = '+';
    //     } else {
    //         batbar[i] = '-';
    //     }
    // }
    // if (outOf10 > 90.75){
    //     batbar[9] = '#'; // rounding up
    // }
    // string bar(batbar);

    // rintf("Battery Status: \n\t\t%n\n\t\t%n/%n\n\t\t", chargestatus, chargepercent, chargemax);
}

int main() {

    while(true) {

        timedate();

        battery();

        printf("\033[2J\033[1;1H"); // put cursor back to beginning

        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return 0;
}