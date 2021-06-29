//
//  functions.h
//  AGMobi
//
//  Created by Luis Gustavo Kawahara on 02/06/21.
//

#ifndef functions_h
#define functions_h

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

void rot_charge(void);

static inline uint16_t concat_816(uint8_t a, uint8_t b) //CONCATENA DUAS VARIAVEIS 16-BIT EM UMA DE 32-BIT
{
    uint16_t c = (uint16_t) a << 8 | b;

    return c;
}

static inline uint32_t concat_1632(uint16_t a, uint16_t b) //CONCATENA DUAS VARIAVEIS 16-BIT EM UMA DE 32-BIT
{
    uint32_t c = (uint32_t) a << 16 | b;

    return c;
}

static inline uint64_t concat_3264(uint32_t a, uint32_t b) //CONCATENA DUAS VARIAVEIS 32-BIT EM UMA DE 64-BIT
{
    uint64_t c = (uint64_t) a << 32 | b;

    return c;
}

static inline uint32_t conv_floatinv_ieee754(uint32_t a) //CONVERTE VARIAVEL EM FORMATO FLOAT INVERT PARA IEEE 754 E VICE-VERSA
{
    int i = 0;
    uint8_t b = 0;
    uint32_t c = 0;
    
    for(i = 0; i < 32; i+=8)
    {
        b = (a >> i) & 0xff;
        c |= b << (32 - 8 - i);
    };
    
    return c;
}

static inline float conv_dec_f(uint32_t a)//CONVERTE VARIAVEL PARA FLOAT DECIMAL
{
    int sign;
    int mantissa;
    int exp;
    float result;
    
    sign = a >> 31;                            // 0
    mantissa = (a & 0x7FFFFF) | 0x800000;      // 11244903
    exp = ((a >> 23) & 0xFF) - 127 - 23;       // -15
    result = mantissa * pow(2.0, exp);         // 343.1672
    
    return result;
}

static inline float read_in_reg(int slave_num, uint16_t reg_addr)
{
    int i=0;
    int rd;
    uint16_t reg_size;
    uint16_t tab_reg[64];
    uint32_t result_concat;
    float    result_float;
    
    modbus_t *ctx;

    //REGISTRADORES COM TAMANHO 1
    if(reg_addr == THD_U1N      || reg_addr == THD_U2N          || reg_addr == THD_U3N      || reg_addr == THD_I1N  ||
       reg_addr == THD_I2N      || reg_addr == THD_I3N          || reg_addr == THD_U1       || reg_addr == THD_U2   ||
       reg_addr == THD_U3       || reg_addr == THD_I1           || reg_addr == THD_I2       || reg_addr == THD_I3   ||
       reg_addr == TCP_CON_QTY  || reg_addr == TCP_CON_QTY_MAX  || reg_addr == HTTP_CON_QTY || reg_addr == MBTCP_CON_QTY)
    {
        reg_size = 0x0001;
    }
    else
    if(reg_addr == MAC_ADDR)
    {
        reg_size = 0x0003;
    }
    else
    {
        reg_size = 0x0002;
    }
 
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 2);
//    ctx = modbus_new_tcp("10.0.0.102", 502);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    
    
//--------------INICIO DA AREA DE TESTE----------------//
    
    
    
    
//    rd = modbus_read_input_registers(ctx, 0x0BD3, 0x0002, tab_reg); //LE TENSAO U0
    
    
    
    
//--------------FIM DA AREA DE TESTE----------------//
    
    
    rd = modbus_read_input_registers(ctx, reg_addr, reg_size, tab_reg); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    
    for (i=0; i < rd; i++) {
        printf("reg[%d]=%d (0x%X)\n", i, tab_reg[i], tab_reg[i]);
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    //REGISTRADORES UINT 32-BIT
    if(reg_addr == SN)
    {
        printf("1\n");
        
        ids.serial = concat_1632(tab_reg[0], tab_reg[1]);
        printf("Serial number: 0x%X (%d)\n", ids.serial, ids.serial);
        
        return 0;
    }
    else //LEITURA DO MAC ADRESS
    if(reg_addr == MAC_ADDR)
    {
        printf("2\n");
        
        ids.MAC[0] = tab_reg[0];
        ids.MAC[1] = tab_reg[1];
        ids.MAC[2] = tab_reg[2];
        
        return 0;
    }
    else //REGISTRADORES UINT 16-BIT
    if (reg_addr == THD_U1N     || reg_addr == THD_U2N      || reg_addr == THD_U3N      || reg_addr == THD_I1N      ||
        reg_addr == THD_I2N     || reg_addr == THD_I3N      || reg_addr == THD_U1       || reg_addr == THD_U2       ||
        reg_addr == THD_U3      || reg_addr == THD_I1       || reg_addr == THD_I2       || reg_addr == THD_I3       ||
        reg_addr == ERR_CODES   || reg_addr == TCP_CON_QTY  || reg_addr == TCP_CON_QTY  || reg_addr == TCP_CON_QTY  ||
        reg_addr == TCP_CON_QTY)
    {
        printf("3\n");
        
        result_concat = tab_reg[0];
        result_float = result_concat * 0.01;

        return result_float;
    }
    else
    {
        printf("4\n");
        
        result_concat = concat_1632(tab_reg[0], tab_reg[1]);
        printf("result_concat: 0x%X (%d)\n", result_concat, result_concat);
       
        result_concat = conv_floatinv_ieee754(result_concat);
        printf("IEEE754: 0x%X (%d)\n", result_concat, result_concat); //VARIAVEL NO PADRÃO IEEE754
        
        result_float = conv_dec_f(result_concat);
        printf("result_float: %f\n", result_float); //VARIAVEL NO PADRAO FLOAT INVERT
        
        return result_float;
    }
}

static inline float read_in_reg_PTL(int slave_num, uint16_t reg_addr) //LER REGISTRO DO POWERTAGLINK
{
    int i=0;
    int rd;
    int is_ascii=0;
    uint16_t reg_size;
    uint16_t tab_reg[64];
    uint8_t  tab_reg8[64];
    uint32_t result_concat;
    uint32_t result_concat1;
    uint32_t result_concat2;
    uint64_t result_concat64;
    float    result_float;
    
    modbus_t *ctx;

    if(reg_addr == PT_APP_NAME)//ASCII 10 ESPACOS
    {
        is_ascii = 1;
        reg_size = 0x000A;
    }
    else
    if(reg_addr == PT_CIRC_NAME)//ASCII 3 ESPACOS
    {
        is_ascii = 1;
        reg_size = 0x0003;
    }
    else
    if(reg_addr == PT_EA_T      || reg_addr == PT_EA_P      || reg_addr == PT_DATE)
    {
        reg_size = 0x0004;
    }
    else
    if(reg_addr == PT_PH_SEQ)
    {
        reg_size = 0x0001;
    }
    else
    {
        reg_size = 0x0002;
    }

    ctx = modbus_new_tcp("10.0.0.101", 502);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }

    modbus_set_slave(ctx, slave_num);
    
    
    
//--------------INICIO DA AREA DE TESTE----------------//
    
    
    
    
//    rd = modbus_read_input_registers(ctx, 0x0BD3, 0x0002, tab_reg); //LE TENSAO U0
    
    
    
    
//--------------FIM DA AREA DE TESTE----------------//
    
    
    rd = modbus_read_input_registers(ctx, reg_addr, reg_size, tab_reg); //LE INPUT REGISTER
//    rd = modbus_read_input_registers(ctx, reg_addr, 0x0002, tab_reg); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    
/*    for (i=0; i < rd; i++) {
        printf("reg[%d]=%d (0x%X)\n", i, tab_reg[i], tab_reg[i]);
    }
*/    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    //REGISTRADORES INT 64-BITS
    if(is_ascii)
    {
        for(i=0; i < rd; i++)
        {
            tab_reg8[2*i] = tab_reg[i] >> 8;
            tab_reg8[2*i + 1] = tab_reg[i];
            printf("reg8[%d]=(0x%X)\n", 2*i, tab_reg8[2*i]);
            printf("reg8[%d]=(0x%X)\n", 2*i+1, tab_reg8[2*i+1]);
            teste.ascii[2*i] = tab_reg8[2*i];
            teste.ascii[2*i+1] = tab_reg8[2*i + 1];
        }
        return 10;
    }
    else
    if (reg_size == 0x0004)
    {
        result_concat1 = concat_1632(tab_reg[0], tab_reg[1]);
//        printf("result_concat1: 0x%X (%d)\n", result_concat1, result_concat1);
       
        result_concat2 = concat_1632(tab_reg[2], tab_reg[3]);
//        printf("result_concat2: 0x%X (%d)\n", result_concat2, result_concat2);
    
        result_concat64 = concat_3264(result_concat1, result_concat2);
//        printf("result_concat64: 0x%llX\n", result_concat64);
        
//        result_float = result_concat64 * 0.001;

        return result_concat64;
    }
    else
    if(reg_size == 1)
    {
        result_float = tab_reg[0];
        
        return result_float;
    }
    else //REGISTRADORES FLOAT 32
    {
        result_concat = concat_1632(tab_reg[0], tab_reg[1]);
        
        if(reg_addr == PT_OP_TIME)
        {
            result_float = result_concat / 60;
        }
        else
        {
            result_float = conv_dec_f(result_concat);
        }
        
        return result_float;
    }
}

static inline void set_dout(int slave_num, int port_number)
{
    int rd;
    int addr=0;
    
    modbus_t *ctx;
    
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 2);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to create the libmodbus context\n");
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    if(port_number == 1) addr = 0x001E;
    else if(port_number == 2) addr = 0x001F;
    
    rd = modbus_write_bit(ctx, addr, 0x0001);
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        
    }
    sleep(1);
}

static inline void reset_dout(int slave_num, int port_number)
{
    int rd;
    int addr=0;
    
    modbus_t *ctx;
    
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 2);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to create the libmodbus context\n");
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    if(port_number == 1) addr = 0x001E;
    else if(port_number == 2) addr = 0x001F;
    
    rd = modbus_write_bit(ctx, addr, 0x0000);
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
    }
    sleep(1);
}

static inline int read_digital_status(int slave_num, int in_out, int port_number) //LEITURA DAS SAIDAS E ENTRADAS DIGITAIS DO KONECT
{
    int rd;
    int addr=0;
    uint8_t tab_reg[64];
    
    modbus_t *ctx;
    
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 2);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to create the libmodbus context\n");
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    rd = modbus_read_input_bits(ctx, 0x0000, 0x0005, tab_reg);
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
/*    for (i=0; i < rd; i++) {
        printf("reg[%d]=%d (0x%X)\n", i, tab_reg[i], tab_reg[i]);
    }
*/
    sleep(1);
    
    if(in_out == 0)
    {
        if(port_number == 1)      addr = 2;
        else if(port_number == 2) addr = 3;
    }
    if(in_out == 1)
    {
        if(port_number == 1)      addr = 0;
        else if(port_number == 2) addr = 1;
    }
    
    
    if(tab_reg[addr] == 1)
    {
        if(in_out == 0) printf("A saída %d do Kron está ligada\n", port_number);
        else            printf("A entrada %d do Kron está ligada\n", port_number);
        
        relay[port_number].kron_state = 1;
        
        return 1;
    }
    else
    {
        if(in_out == 0) printf("A saída %d do Kron está desligada\n", port_number);
        else            printf("A entrada %d do Kron está desligada\n", port_number);
        
        relay[port_number].kron_state = 0;
            
        return 0;
    }
}

static inline int reset_partial_energy_PTL(int slave_num, uint16_t reg_addr) //RESETA ENERGIA PARCIAL DO POWERTAG
{
    int rd;
    int i=0;
    uint16_t reg_size;
    uint16_t tab_reg[64];
    
    modbus_t *ctx;

    //REGISTRADORES COM TAMANHO 1
    if(reg_addr == PT_EA_P_RESET)
    {
        reg_size = 4;
    }
    else
    {
        reg_size = 2;
    }
    
    for (i=0; i < reg_size; i++) tab_reg[i] = 0;

    ctx = modbus_new_tcp("10.0.0.101", 502);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    rd = modbus_write_registers(ctx, reg_addr, reg_size, tab_reg); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    return rd;
}

static inline int get_system_date(void) //CAPTURA A DATA DO SISTEMA (RASP, LINUX, MAC, WIN, ETC.)
{
    char buf[BUF_LEN] = {0};
        
    time_t rawtime = time(NULL);
    
    if (rawtime == -1) {
        
        puts("The time() function failed");
        return 1;
    }
    
    struct tm *ptm = localtime(&rawtime);
    
    if (ptm == NULL) {
     
        puts("The localtime() function failed");
        return 1;
    }
    
    puts(buf);
    
    memset(buf, 0, BUF_LEN);
    
    puts(buf);
    
    date[254].year    = ptm->tm_year - 100;
    date[254].month   = ptm->tm_mon + 1;
    date[254].day     = ptm->tm_mday;
    date[254].hour    = ptm->tm_hour;
    date[254].min     = ptm->tm_min;
    date[254].sec     = ptm->tm_sec;
    date[254].weekday = ptm->tm_wday;
    
    printf("Data do sistema: %02d/%02d/%02d \nHora do sistema: %d:%02d\n", date[254].day, date[254].month, date[254].year, date[254].hour, date[254].min);
    
    return 0;
}

static inline int set_PT_date(void) //SETA A DATA DO POWERTAG CO BASE NO VALOR SALVO NAS VARIAVEIS DA ESTRUTURA "DATE"
{
    int rd;
    uint16_t ano;
    uint16_t mes_dia;
    uint16_t hora_min;
    uint16_t milisec;
    uint16_t tab_reg[4];
    
    modbus_t *ctx;
    
    ctx = modbus_new_tcp("10.0.0.101", 502);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, 255);
    
    //COPIA VALORES DO SISTEMA PARA AS TABELA DO FRAME
    
    ano      = date[254].year;
    mes_dia  = concat_816(date[254].month, date[254].day);
    hora_min = concat_816(date[254].hour, date[254].min);
    milisec  = date[254].sec * 1000;
    
    tab_reg[0] = ano;
    tab_reg[1] = mes_dia;
    tab_reg[2] = hora_min;
    tab_reg[3] = milisec;
    
    rd = modbus_write_registers(ctx, PT_DATE, 0x0004, tab_reg); //ANO
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    return 0;
}

static inline int get_PT_date(int slave_num) //REQUISITA A DATA CONFIGURADA NO POWERTAG LINK
{
    int rd;
    uint16_t tab_reg[4];
    
    modbus_t *ctx;
    
    ctx = modbus_new_tcp("10.0.0.101", 502);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, 255);
    
    rd = modbus_read_input_registers(ctx, PT_DATE, 0x0004, tab_reg); //ANO
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    sleep(1);
    
    date[slave_num].year = tab_reg[0];
    
    date[slave_num].month = tab_reg[1] >> 8;
    if(date[slave_num].month > 0x0c) date[slave_num].month = 0x0f & date[slave_num].month;
    
    date[slave_num].day = tab_reg[1];
    if(date[slave_num].day > 0x1f) date[slave_num].day = 0x1f & date[slave_num].day;
    
    date[slave_num].hour = tab_reg[2] >> 8;
    if(date[slave_num].hour > 0x17) date[slave_num].hour = 0x1f & date[slave_num].hour;
    
    date[slave_num].min = tab_reg[2];
    if(date[slave_num].min > 0x3b) date[slave_num].min = 0x3f & date[slave_num].min;
    
//    printf("Data do PowerTag: %02d/%02d/%02d \nHora do PowerTag: %d:%02d\n", date[slave_num].day, date[slave_num].month, date[slave_num].year, date[slave_num].hour, date[slave_num].min);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    return 0;
}

static inline int open_relay(int slave_num, int relay_addr) //COMANDO PARA ABERTURA DE RELÉ DA PLACA DE RELÉS
{
    int rd;
    
    modbus_t *ctx;
    
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    
    rd = modbus_write_register(ctx, relay_addr, 0x0200); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    return 0;
}

static inline int close_relay(int slave_num, int relay_addr) //COMANDO PARA FECHAMENTO DE RELÉ DA PLACA DE RELÉS
{
    int rd;
    
    modbus_t *ctx;
    
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    rd = modbus_write_register(ctx, relay_addr, 0x0100); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    return 0;
}

static inline int read_relay_status(int slave_num, uint32_t relay_addr) //LE STATUS DO RELE
{
    int rd;
    uint16_t tab_reg[1];
    
    modbus_t *ctx;
    
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    rd = modbus_read_registers(ctx, relay_addr, 0x0001, tab_reg); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    if(tab_reg[0] == 1)
    {
        relay[relay_addr].board = 1;
        printf("A saída %d da placa está ligada\n", relay_addr);
    }
    else
    {
        relay[relay_addr].board = 0;
        printf("A saída %d da placa está desligada\n", relay_addr);
    }
    
    return tab_reg[0];
}

static inline int read_all_relay_status(int slave_num) //LE O STATUS DE TODOS OS RELES DE UMA VEZ
{
    int i=0;
    int rd;
    uint16_t tab_reg[16];
    
    modbus_t *ctx;
    
    ctx = modbus_new_rtu("/dev/tty.usbserial-1420", 9600, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    rd = modbus_read_registers(ctx, 0x0001, 0x0010, tab_reg); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    
    for (i=0; i < rd; i++) {
        printf("reg[%d]=%d (0x%X)\n", i, tab_reg[i], tab_reg[i]);
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    return 0;
}

static inline int get_PT_alarm(int slave_num) //
{
    int rd;
    uint16_t reg_size=0x0001;
    uint16_t tab_reg[1];
    
    modbus_t *ctx;
    
    ctx = modbus_new_tcp("10.0.0.101", 502);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return -1;
    }
    
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }

    modbus_set_slave(ctx, slave_num);
    
    rd = modbus_read_registers(ctx, PT_ALARMS, reg_size, tab_reg); //LE INPUT REGISTER
    if (rd == -1) {
        fprintf(stderr, "%s\n", modbus_strerror(errno));
        return -1;
    }
    sleep(1);
    
    modbus_close(ctx);
    modbus_free(ctx);
    
    if(tab_reg[slave_num] == 0xFFFF)
        {
        printf("PT %d retornou um valor inválido\n\n", slave_num);
        alarms[slave_num].previous = tab_reg[0];
        }
    else
        {
        if(alarms[slave_num].previous != tab_reg[0])
            {
            if(tab_reg[0] & PT_VOLTAGE_LOSS)    printf("ALARME PT %d: Perda de tensão\n\n", slave_num);
            if(tab_reg[0] & PT_OL_AT_VL)        printf("ALARME PT %d: Sobrecarga na perda de tensão\n\n", slave_num);
            if(tab_reg[0] & PT_OL_45)           printf("ALARME PT %d: Carga acima de 45%%\n\n", slave_num);
            if(tab_reg[0] & PT_ZERO_CURRENT)    printf("ALARME PT %d: Carga desligada\n\n", slave_num);
            if(tab_reg[0] & PT_OV_120)          printf("ALARME PT %d: Sobretensão acima de 120%%\n\n", slave_num);
            if(tab_reg[0] & PT_UV_80)           printf("ALARME PT %d: Subtensão abaixo de 80%%\n\n", slave_num);
            if(tab_reg[0] & PT_LOW_BAT)         printf("ALARME PT %d: Bateria baixa\n\n", slave_num);
            if(tab_reg[0] == 0)                 printf("PT %d: Sem alarmes\n\n", slave_num);
            
            alarms[slave_num].previous = tab_reg[0];
            }
        }
    
    return tab_reg[0];
}


#endif /* functions_h */
