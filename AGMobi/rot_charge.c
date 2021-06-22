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
    if(alarms[2].state & PT_ZERO_CURRENT)
        {
        get_PT_date(2);
        close_relay(2,RELAY_CH1);
        }
    else
        {
        open_relay(2,RELAY_CH1);
        }
    }
