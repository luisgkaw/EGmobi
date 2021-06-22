//
//  rot_charge.c
//  AGMobi
//
//  Created by Luis Gustavo Kawahara on 22/06/21.
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

void rot_charge(void)
    {
    for(cnt.powertag = 0; cnt.powertag < 20; cnt.powertag++)
        {
        alarms[cnt.powertag].state = get_PT_alarm(cnt.powertag);
        if((alarms[cnt.powertag].state & PT_ZERO_CURRENT))
            {
            if(charge[cnt.powertag].state)
                {
                get_PT_date(cnt.powertag);
                
                if(date[cnt.powertag].day == date[cnt.powertag].start_day)
                    {
                    charge[cnt.powertag].duration = (date[cnt.powertag].hour - date[cnt.powertag].start_hour)*60 + (date[cnt.powertag].min - date[cnt.powertag].start_min);
                    }
                else
                    {
                    charge[cnt.powertag].duration = (24 - date[cnt.powertag].start_hour + date[cnt.powertag].hour)*60 + (date[cnt.powertag].min - date[cnt.powertag].start_min);
                    }
                measure[cnt.powertag].energy = read_in_reg_PTL(cnt.powertag, PT_EA_P);
                
                charge[cnt.powertag].energy = measure[cnt.powertag].energy - measure[cnt.powertag].start_energy;
                
                printf("Recarga encerrada em:\n%02d/%02d/%02d às %02d:%02d\n", date[cnt.powertag].day, date[cnt.powertag].month, date[cnt.powertag].year, date[cnt.powertag].hour, date[cnt.powertag].min);
                printf("Duração: %d minutos\nEnergia total: %d Wh\n\n", charge[cnt.powertag].duration, charge[cnt.powertag].energy);
                
                charge[cnt.powertag].state = 0;
                }
            }
        else
            {
            if(!charge[cnt.powertag].state)
                {
                get_PT_date(cnt.powertag);
                date[cnt.powertag].start_day = date[cnt.powertag].day;
                date[cnt.powertag].start_hour = date[cnt.powertag].hour;
                date[cnt.powertag].start_min = date[cnt.powertag].min;
                
                measure[cnt.powertag].start_energy = read_in_reg_PTL(cnt.powertag, PT_EA_P);
                
                charge[cnt.powertag].state = 1;
                printf("Recarga iniciada em:\n%02d/%02d/%02d às %02d:%02d\n\n", date[cnt.powertag].day, date[cnt.powertag].month, date[cnt.powertag].year, date[cnt.powertag].hour, date[cnt.powertag].min);
                }
            }
        }
    }
