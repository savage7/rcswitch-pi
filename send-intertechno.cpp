/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "NewRemoteTransmitter.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    unsigned long systemCode = atol(argv[1]);
    int unitCode = atoi(argv[2]);
    int command  = atoi(argv[3]);
    
    if (wiringPiSetup () == -1) return 1;
    NewRemoteTransmitter transmitter(systemCode, PIN, 254);
    
    switch(command) {
        case 1:
            transmitter.sendUnit(unitCode, 1);
            break;
        case 0:
            transmitter.sendUnit(unitCode, 0);
            break;
        default:
            printf("command[%i] is unsupported\n", command);
            return -1;
    }
    return 0;
}

