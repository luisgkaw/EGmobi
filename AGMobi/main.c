//
//  main.c
//  AGMobi
//
//  Created by Luis Gustavo Kawahara on 02/06/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <modbus.h>
#include <errno.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include "functions.h"
#include "global_variables.h"
#include "constantes.h"
#include "boot.h"

int main(void) {
    
    measure[2].energy = read_in_reg_PTL(2, PT_EA_P);
    measure[2].energy = conv_dec_f(measure[2].energy);
    
    
    while(1)
        {
        if(!flags.boot)
            {
            boot_sec();
            }
        
        if(!date[255].set)
            {
            get_system_date();
            get_PT_date(255);
            
            if(date[254].year  == date[255].year    &&
               date[254].month == date[255].month   &&
               date[254].day   == date[255].day     &&
               date[254].hour  == date[255].hour    &&
               date[254].min   == date[255].min)
                {
                date[255].set = 1;
                }
            else
                {
                set_PT_date();
                date[255].set = 1;
                }
            }
        
        rot_charge();
    }
    
}
