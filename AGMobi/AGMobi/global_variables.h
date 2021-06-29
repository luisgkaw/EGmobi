#ifndef global_variables_h
#define global_variables_h

#include <stdio.h>

enum {
    fSTX,
    fTAM,
    fGRP,
    fEND,
    fCMD,
    fFLG
};

enum {
    seqANO,
    seqMES,
    seqDIA,
    seqHORA,
    seqMIN,
    seqSEG
};

struct tag_comms
{
    unsigned short  session_open:1;
    unsigned int    cs_adds;
    
    struct
    {
        unsigned char   buffer[200];
        unsigned char   le[16];
    }rx, tx;
};
extern struct tag_comms comms;

struct tag_measure
{
    unsigned char   serial_num;
    unsigned int    date;
    unsigned int    pot;
    uint64_t        energy;
    unsigned int    voltage;
    unsigned int    current;
    uint64_t        start_energy;
};
extern struct tag_measure measure[247];

struct tag_ids
{
    unsigned int    MAC[3];
    unsigned int    serial;
};
extern struct tag_ids ids;

struct tag_teste
{
    unsigned char   caractere;
    unsigned int    inteira;
    float           flutuante;
    uint8_t         ascii[10];
};
extern struct tag_teste teste;

struct tag_date
{
    uint8_t         year;
    uint8_t         month;
    uint8_t         day;
    uint8_t         hour;
    uint8_t         min;
    uint8_t         sec;
    uint8_t         weekday;
    uint8_t         start_day;
    uint8_t         start_hour;
    uint8_t         start_min;
    unsigned int    set:1;
};
extern struct tag_date date[256];

/*---VETORES DE DATAS---//
 USADO PARA ARMAZENAR INÍCIO E FINAL DE CARREGAMENTO DE
 CADA POWERTAG, MAS SOMENTE O POWERTAG LINK TEM A INFORMAÇÃO.
 
 1 A 247 - POWERTAGS
 255 - POWERTAG LINK
 254 - SISTEMA
 253 - TEMPORARIO
 */

struct tag_alarms
{
    unsigned int    state;
    unsigned int    voltage_loss:1;
    unsigned int    ol_at_voltage_loss:1;
    unsigned int    overload_45:1;
    unsigned int    zero_current:1;
    unsigned int    overvoltage_120:1;
    unsigned int    undervoltage_80:1;
    unsigned int    low_battery:1;
    unsigned int    previous;
};
extern struct tag_alarms alarms[256];

struct tag_relay
{
    unsigned int    kron_state:1;
    unsigned int    board:1;
};
extern struct tag_relay relay[17];

struct tag_flags
{
    unsigned int    boot:1;
};
extern struct tag_flags flags;

struct tag_charge
{
    unsigned int    state:1;
    unsigned int    duration;
    uint64_t        energy;
};
extern struct tag_charge charge[247];

struct tag_cnt
{
    unsigned int    powertag;
};
extern struct tag_cnt cnt;


#endif /* global_variables_h */
