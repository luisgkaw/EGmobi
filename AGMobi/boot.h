//
//  boot.h
//  AGMobi
//
//  Created by Luis Gustavo Kawahara on 22/06/21.
//

#ifndef boot_h
#define boot_h

#include "functions.h"
#include "global_variables.h"
#include "constantes.h"

void boot_sec(void)
{
    date[255].set = 0;
    flags.boot = 1;
}


#endif /* boot_h */
