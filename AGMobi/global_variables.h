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
    unsigned int    energy;
    unsigned int    voltage;
    unsigned int    current;
};
extern struct tag_measure measure;

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
};
extern struct tag_date date[256];

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
};
extern struct tag_alarms alarms[256];

#endif /* global_variables_h */
