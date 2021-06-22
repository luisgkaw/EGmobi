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
        
        alarms[2].state = get_PT_alarm(2);
        /*
        if(alarms[2].state & PT_ZERO_CURRENT)
        {
            get_PT_date(2);
            close_relay(2,RELAY_CH1);
        }
        else
        {
            open_relay(2,RELAY_CH1);
        }

    /*
        teste.flutuante = read_in_reg(2, V_U1);
        
        printf("Tensão U0: %f\n", teste.flutuante);
        
    //    teste.inteira = reset_partial_energy_PTL(2, PT_EAP_RESET);
        
        teste.flutuante = read_in_reg_PTL(2, PT_V_U1);
        
    //    teste.flutuante = conv_ieee754_dec_f(teste.inteira);
        
        printf("Tensão PowerTag: %f\n", teste.flutuante);
    /*
        set_dout(1,1);
        read_digital_status(1, 0, 1);
        set_dout(1,2);
        read_digital_status(1, 0, 2);
        reset_dout(1,1);
        read_digital_status(1, 0, 1);
        reset_dout(1,2);
        read_digital_status(1, 0, 2);
    */
    }
    
}
