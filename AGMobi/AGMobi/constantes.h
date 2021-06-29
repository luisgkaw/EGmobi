#ifndef constantes_h
#define constantes_h

#include <stdio.h>

#define FALSE           0
#define TRUE            1
#define BUF_LEN         256

//---RELAYS---//

#define RELAY_CH1       0x0001
#define RELAY_CH2       0x0002
#define RELAY_CH3       0x0003
#define RELAY_CH4       0x0004
#define RELAY_CH5       0x0005
#define RELAY_CH6       0x0006
#define RELAY_CH7       0x0007
#define RELAY_CH8       0x0008
#define RELAY_CH9       0x0009
#define RELAY_CH10      0x000A
#define RELAY_CH11      0x000B
#define RELAY_CH12      0x000C
#define RELAY_CH13      0x000D
#define RELAY_CH14      0x000E
#define RELAY_CH15      0x000F
#define RELAY_CH16      0x0010

//---KRON KONECT---//

//---INPUT REGISTERS---//

//---GRANDEZAS ELETRICAS---//

#define SN              0x0000 //UINT 32-BIT
#define V_U0            0x0002 //IEEE 754
#define V_U12           0x0004 //IEEE 754
#define V_U23           0x0005 //IEEE 754
#define V_U31           0x0007 //IEEE 754
#define V_U1            0x000A //IEEE 754
#define V_U2            0x000C //IEEE 754
#define V_U3            0x000E //IEEE 754
#define I_I0            0x0010 //IEEE 754
#define I_IN            0x0012 //IEEE 754
#define I_I1            0x0014 //IEEE 754
#define I_I2            0x0016 //IEEE 754
#define I_I3            0x0018 //IEEE 754
#define F_F1            0x001A //IEEE 754
#define F_F2            0x001C //IEEE 754
#define F_F3            0x001E //IEEE 754
#define F_FIEC          0x0020 //IEEE 754
#define P_P0            0x0022 //IEEE 754
#define P_P1            0x0024 //IEEE 754
#define P_P2            0x0026 //IEEE 754
#define P_P3            0x0028 //IEEE 754
#define P_Q0            0x002A //IEEE 754
#define P_Q1            0x002C //IEEE 754
#define P_Q2            0x002E //IEEE 754
#define P_Q3            0x0030 //IEEE 754
#define P_S0            0x0032 //IEEE 754
#define P_S1            0x0034 //IEEE 754
#define P_S2            0x0036 //IEEE 754
#define P_S3            0x0038 //IEEE 754
#define P_FP0           0x003A //IEEE 754
#define P_FP1           0x003C //IEEE 754
#define P_FP2           0x003E //IEEE 754
#define P_FP3           0x0040 //IEEE 754
#define P_FP0D          0x0042 //IEEE 754
#define P_FP1D          0x0044 //IEEE 754
#define P_FP2D          0x0046 //IEEE 754
#define P_FP3D          0x0048 //IEEE 754
#define V_FD            0x004A //IEEE 754
#define V_FK1           0x004C //IEEE 754
#define V_FK2           0x004E //IEEE 754
#define V_FK3           0x0050 //IEEE 754


//---GRANDEZAS ELETRICAS (MINIMOS)---//

#define U0_MIN          0x03EA //IEEE 754
#define U12_MIN         0x03EC //IEEE 754
#define U23_MIN         0x03EE //IEEE 754
#define U31_MIN         0x03F0 //IEEE 754
#define U1_MIN          0x03F2 //IEEE 754
#define U2_MIN          0x03F4 //IEEE 754
#define U3_MIN          0x03F6 //IEEE 754
#define I0_MIN          0x03F8 //IEEE 754
#define IN_MIN          0x03FA //IEEE 754
#define I1_MIN          0x03FC //IEEE 754
#define I2_MIN          0x03FE //IEEE 754
#define I3_MIN          0x0400 //IEEE 754
#define F0_MIN          0x0402 //IEEE 754
#define F1_MIN          0x0404 //IEEE 754
#define F2_MIN          0x0406 //IEEE 754
#define F3_MIN          0x0408 //IEEE 754
#define P0_MIN          0x040A //IEEE 754
#define P1_MIN          0x040C //IEEE 754
#define P2_MIN          0x040E //IEEE 754
#define P3_MIN          0x0410 //IEEE 754
#define Q0_MIN          0x0412 //IEEE 754
#define Q1_MIN          0x0414 //IEEE 754
#define Q2_MIN          0x0416 //IEEE 754
#define Q3_MIN          0x0418 //IEEE 754
#define S0_MIN          0x041A //IEEE 754
#define S1_MIN          0x041C //IEEE 754
#define S2_MIN          0x041E //IEEE 754
#define S3_MIN          0x0420 //IEEE 754
#define FP0_MIN         0x0422 //IEEE 754
#define FP1_MIN         0x0424 //IEEE 754
#define FP2_MIN         0x0426 //IEEE 754
#define FP3_MIN         0x0428 //IEEE 754
#define FP0D_MIN        0x042A //IEEE 754
#define FP1D_MIN        0x042C //IEEE 754
#define FP2D_MIN        0x042E //IEEE 754
#define FP3D_MIN        0x0430 //IEEE 754
#define FD_MIN          0x0432 //IEEE 754
#define FK1_MIN         0x0434 //IEEE 754
#define FK2_MIN         0x0436 //IEEE 754
#define FK3_MIN         0x0438 //IEEE 754


//---GRANDEZAS ELETRICAS (MAXIMOS)---//

#define U0_MAX          0x07D2 //IEEE 754
#define U12_MAX         0x07D4 //IEEE 754
#define U23_MAX         0x07D6 //IEEE 754
#define U31_MAX         0x07D8 //IEEE 754
#define U1_MAX          0x07DA //IEEE 754
#define U2_MAX          0x07DC //IEEE 754
#define U3_MAX          0x07DE //IEEE 754
#define I0_MAX          0x07E0 //IEEE 754
#define IN_MAX          0x07E2 //IEEE 754
#define I1_MAX          0x07E4 //IEEE 754
#define I2_MAX          0x07E6 //IEEE 754
#define I3_MAX          0x07E8 //IEEE 754
#define F0_MAX          0x07EA //IEEE 754
#define F1_MAX          0x07EC //IEEE 754
#define F2_MAX          0x07EE //IEEE 754
#define F3_MAX          0x07F0 //IEEE 754
#define P0_MAX          0x07F2 //IEEE 754
#define P1_MAX          0x07F4 //IEEE 754
#define P2_MAX          0x07F6 //IEEE 754
#define P3_MAX          0x07F8 //IEEE 754
#define Q0_MAX          0x07FA //IEEE 754
#define Q1_MAX          0x07FC //IEEE 754
#define Q2_MAX          0x07FE //IEEE 754
#define Q3_MAX          0x0800 //IEEE 754
#define S0_MAX          0x0802 //IEEE 754
#define S1_MAX          0x0804 //IEEE 754
#define S2_MAX          0x0806 //IEEE 754
#define S3_MAX          0x0808 //IEEE 754
#define FP0_MAX         0x080A //IEEE 754
#define FP1_MAX         0x080C //IEEE 754
#define FP2_MAX         0x080E //IEEE 754
#define FP3_MAX         0x0810 //IEEE 754
#define FP0D_MAX        0x0812 //IEEE 754
#define FP1D_MAX        0x0814 //IEEE 754
#define FP2D_MAX        0x0816 //IEEE 754
#define FP3D_MAX        0x0818 //IEEE 754
#define FD_MAX          0x081A //IEEE 754
#define FK1_MAX         0x081C //IEEE 754
#define FK2_MAX         0x081E //IEEE 754
#define FK3_MAX         0x0820 //IEEE 754


//---ENTRADAS DIGITAIS---//

#define EDP1            0x005E
#define EDP2            0x0060
#define EDP3            0x0062


//---ENERGIAS E DEMANDAS---//

#define EA_POS          0x00C8 //IEEE 754
#define ER_POS          0x00CA //IEEE 754
#define EA_NEG          0x00CC //IEEE 754
#define ER_NEG          0x00CE //IEEE 754
#define EA_D_MAX        0x00D0 //IEEE 754
#define EA_D            0x00D2 //IEEE 754
#define ES_D_MAX        0x00D4 //IEEE 754
#define ES_D            0x00D6 //IEEE 754


//---THD---//

#define THD_U1N         0x0BB8 //INT 16-BIT
#define THD_U2N         0x0BB9 //INT 16-BIT
#define THD_U3N         0x0BBA //INT 16-BIT
#define THD_I1N         0x0BBB //INT 16-BIT
#define THD_I2N         0x0BBC //INT 16-BIT
#define THD_I3N         0x0BBD //INT 16-BIT
#define THD_U1          0x0BBE //INT 16-BIT
#define THD_U2          0x0BBF //INT 16-BIT
#define THD_U3          0x0BC0 //INT 16-BIT
#define THD_I1          0x0BC1 //INT 16-BIT
#define THD_I2          0x0BC2 //INT 16-BIT
#define THD_I3          0x0BC3 //INT 16-BIT


//---THD (MINIMOS)---//

#define THD_U1N_MIN     0x0C80
#define THD_U2N_MIN     0x0C81
#define THD_U3N_MIN     0x0C82
#define THD_I1N_MIN     0x0C83
#define THD_I2N_MIN     0x0C84
#define THD_I3N_MIN     0x0C85
#define THD_U1_MIN      0x0C86
#define THD_U2_MIN      0x0C87
#define THD_U3_MIN      0x0C88
#define THD_I1_MIN      0x0C89
#define THD_I2_MIN      0x0C8A
#define THD_I3_MIN      0x0C8B


//---THD (MAXIMOS)---//

#define THD_U1N_MAX     0x0D48
#define THD_U2N_MAX     0x0D49
#define THD_U3N_MAX     0x0D4A
#define THD_I1N_MAX     0x0D4B
#define THD_I2N_MAX     0x0D4C
#define THD_I3N_MAX     0x0D4D
#define THD_U1_MAX      0x0D4E
#define THD_U2_MAX      0x0D4F
#define THD_U3_MAX      0x0D50
#define THD_I1_MAX      0x0D51
#define THD_I2_MAX      0x0D52
#define THD_I3_MAX      0x0D53


//---AGRUPAMENTO DE HARMONICOS (TENSAO FASE 1)---//

#define U1_HD_1         0x0FA0 //IEEE 754
#define U1_HD_2         0x0FA2 //IEEE 754
#define U1_HD_3         0x0FA4 //IEEE 754
#define U1_HD_4         0x0FA6 //IEEE 754
#define U1_HD_5         0x0FA8 //IEEE 754
#define U1_HD_6         0x0FAA //IEEE 754
#define U1_HD_7         0x0FAC //IEEE 754
#define U1_HD_8         0x0FAE //IEEE 754
#define U1_HD_9         0x0FB0 //IEEE 754
#define U1_HD_10        0x0FB2 //IEEE 754
#define U1_HD_11        0x0FB4 //IEEE 754
#define U1_HD_12        0x0FB6 //IEEE 754
#define U1_HD_13        0x0FB8 //IEEE 754
#define U1_HD_14        0x0FBA //IEEE 754
#define U1_HD_15        0x0FBC //IEEE 754
#define U1_HD_16        0x0FBE //IEEE 754
#define U1_HD_17        0x0FC0 //IEEE 754
#define U1_HD_18        0x0FC2 //IEEE 754
#define U1_HD_19        0x0FC4 //IEEE 754
#define U1_HD_20        0x0FC6 //IEEE 754
#define U1_HD_21        0x0FC8 //IEEE 754
#define U1_HD_22        0x0FCA //IEEE 754
#define U1_HD_23        0x0FCC //IEEE 754
#define U1_HD_24        0x0FCE //IEEE 754
#define U1_HD_25        0x0FD0 //IEEE 754
#define U1_HD_26        0x0FD2 //IEEE 754
#define U1_HD_27        0x0FD4 //IEEE 754
#define U1_HD_28        0x0FD6 //IEEE 754
#define U1_HD_29        0x0FD8 //IEEE 754
#define U1_HD_30        0x0FDA //IEEE 754
#define U1_HD_31        0x0FDC //IEEE 754
#define U1_HD_32        0x0FDE //IEEE 754
#define U1_HD_33        0x0FE0 //IEEE 754
#define U1_HD_34        0x0FE2 //IEEE 754
#define U1_HD_35        0x0FE4 //IEEE 754
#define U1_HD_36        0x0FE6 //IEEE 754
#define U1_HD_37        0x0FE8 //IEEE 754
#define U1_HD_38        0x0FEA //IEEE 754
#define U1_HD_39        0x0FEC //IEEE 754
#define U1_HD_40        0x0FEE //IEEE 754


//---AGRUPAMENTO DE HARMONICOS (TENSAO FASE 2)---//

#define U2_HD_1         0x0FF0 //IEEE 754
#define U2_HD_2         0x0FF2 //IEEE 754
#define U2_HD_3         0x0FF4 //IEEE 754
#define U2_HD_4         0x0FF6 //IEEE 754
#define U2_HD_5         0x0FF8 //IEEE 754
#define U2_HD_6         0x0FFA //IEEE 754
#define U2_HD_7         0x0FFC //IEEE 754
#define U2_HD_8         0x0FFE //IEEE 754
#define U2_HD_9         0x1000 //IEEE 754
#define U2_HD_10        0x1002 //IEEE 754
#define U2_HD_11        0x1004 //IEEE 754
#define U2_HD_12        0x1006 //IEEE 754
#define U2_HD_13        0x1008 //IEEE 754
#define U2_HD_14        0x100A //IEEE 754
#define U2_HD_15        0x100C //IEEE 754
#define U2_HD_16        0x100E //IEEE 754
#define U2_HD_17        0x1010 //IEEE 754
#define U2_HD_18        0x1012 //IEEE 754
#define U2_HD_19        0x1014 //IEEE 754
#define U2_HD_20        0x1016 //IEEE 754
#define U2_HD_21        0x1018 //IEEE 754
#define U2_HD_22        0x101A //IEEE 754
#define U2_HD_23        0x101C //IEEE 754
#define U2_HD_24        0x101E //IEEE 754
#define U2_HD_25        0x1020 //IEEE 754
#define U2_HD_26        0x1022 //IEEE 754
#define U2_HD_27        0x1024 //IEEE 754
#define U2_HD_28        0x1026 //IEEE 754
#define U2_HD_29        0x1028 //IEEE 754
#define U2_HD_30        0x102A //IEEE 754
#define U2_HD_31        0x102C //IEEE 754
#define U2_HD_32        0x102E //IEEE 754
#define U2_HD_33        0x1030 //IEEE 754
#define U2_HD_34        0x1032 //IEEE 754
#define U2_HD_35        0x1034 //IEEE 754
#define U2_HD_36        0x1036 //IEEE 754
#define U2_HD_37        0x1038 //IEEE 754
#define U2_HD_38        0x103A //IEEE 754
#define U2_HD_39        0x103C //IEEE 754
#define U2_HD_40        0x103E //IEEE 754


//---AGRUPAMENTO DE HARMONICOS (TENSAO FASE 3)---//

#define U3_HD_1         0x1040 //IEEE 754
#define U3_HD_2         0x1042 //IEEE 754
#define U3_HD_3         0x1044 //IEEE 754
#define U3_HD_4         0x1046 //IEEE 754
#define U3_HD_5         0x1048 //IEEE 754
#define U3_HD_6         0x104A //IEEE 754
#define U3_HD_7         0x104C //IEEE 754
#define U3_HD_8         0x104E //IEEE 754
#define U3_HD_9         0x1050 //IEEE 754
#define U3_HD_10        0x1052 //IEEE 754
#define U3_HD_11        0x1054 //IEEE 754
#define U3_HD_12        0x1056 //IEEE 754
#define U3_HD_13        0x1058 //IEEE 754
#define U3_HD_14        0x105A //IEEE 754
#define U3_HD_15        0x105C //IEEE 754
#define U3_HD_16        0x105E //IEEE 754
#define U3_HD_17        0x1060 //IEEE 754
#define U3_HD_18        0x1062 //IEEE 754
#define U3_HD_19        0x1064 //IEEE 754
#define U3_HD_20        0x1066 //IEEE 754
#define U3_HD_21        0x1068 //IEEE 754
#define U3_HD_22        0x106A //IEEE 754
#define U3_HD_23        0x106C //IEEE 754
#define U3_HD_24        0x106E //IEEE 754
#define U3_HD_25        0x1070 //IEEE 754
#define U3_HD_26        0x1072 //IEEE 754
#define U3_HD_27        0x1074 //IEEE 754
#define U3_HD_28        0x1076 //IEEE 754
#define U3_HD_29        0x1078 //IEEE 754
#define U3_HD_30        0x107A //IEEE 754
#define U3_HD_31        0x107C //IEEE 754
#define U3_HD_32        0x107E //IEEE 754
#define U3_HD_33        0x1080 //IEEE 754
#define U3_HD_34        0x1082 //IEEE 754
#define U3_HD_35        0x1084 //IEEE 754
#define U3_HD_36        0x1086 //IEEE 754
#define U3_HD_37        0x1088 //IEEE 754
#define U3_HD_38        0x108A //IEEE 754
#define U3_HD_39        0x108C //IEEE 754
#define U3_HD_40        0x108E //IEEE 754


//---AGRUPAMENTO DE HARMONICOS (CORRENTE FASE 1)---//

#define I1_HD_1         0x1090 //IEEE 754
#define I1_HD_2         0x1092 //IEEE 754
#define I1_HD_3         0x1094 //IEEE 754
#define I1_HD_4         0x1096 //IEEE 754
#define I1_HD_5         0x1098 //IEEE 754
#define I1_HD_6         0x109A //IEEE 754
#define I1_HD_7         0x109C //IEEE 754
#define I1_HD_8         0x109E //IEEE 754
#define I1_HD_9         0x10A0 //IEEE 754
#define I1_HD_10        0x10A2 //IEEE 754
#define I1_HD_11        0x10A4 //IEEE 754
#define I1_HD_12        0x10A6 //IEEE 754
#define I1_HD_13        0x10A8 //IEEE 754
#define I1_HD_14        0x10AA //IEEE 754
#define I1_HD_15        0x10AC //IEEE 754
#define I1_HD_16        0x10AE //IEEE 754
#define I1_HD_17        0x10B0 //IEEE 754
#define I1_HD_18        0x10B2 //IEEE 754
#define I1_HD_19        0x10B4 //IEEE 754
#define I1_HD_20        0x10B6 //IEEE 754
#define I1_HD_21        0x10B8 //IEEE 754
#define I1_HD_22        0x10BA //IEEE 754
#define I1_HD_23        0x10BC //IEEE 754
#define I1_HD_24        0x10BE //IEEE 754
#define I1_HD_25        0x10C0 //IEEE 754
#define I1_HD_26        0x10C2 //IEEE 754
#define I1_HD_27        0x10C4 //IEEE 754
#define I1_HD_28        0x10C6 //IEEE 754
#define I1_HD_29        0x10C8 //IEEE 754
#define I1_HD_30        0x10CA //IEEE 754
#define I1_HD_31        0x10CC //IEEE 754
#define I1_HD_32        0x10CE //IEEE 754
#define I1_HD_33        0x10D0 //IEEE 754
#define I1_HD_34        0x10D2 //IEEE 754
#define I1_HD_35        0x10D4 //IEEE 754
#define I1_HD_36        0x10D6 //IEEE 754
#define I1_HD_37        0x10D8 //IEEE 754
#define I1_HD_38        0x10DA //IEEE 754
#define I1_HD_39        0x10DC //IEEE 754
#define I1_HD_40        0x10DE //IEEE 754


//---AGRUPAMENTO DE HARMONICOS (CORRENTE FASE 2)---//

#define I2_HD_1         0x10E0 //IEEE 754
#define I2_HD_2         0x10E2 //IEEE 754
#define I2_HD_3         0x10E4 //IEEE 754
#define I2_HD_4         0x10E6 //IEEE 754
#define I2_HD_5         0x10E8 //IEEE 754
#define I2_HD_6         0x10EA //IEEE 754
#define I2_HD_7         0x10EC //IEEE 754
#define I2_HD_8         0x10EE //IEEE 754
#define I2_HD_9         0x10F0 //IEEE 754
#define I2_HD_10        0x10F2 //IEEE 754
#define I2_HD_11        0x10F4 //IEEE 754
#define I2_HD_12        0x10F6 //IEEE 754
#define I2_HD_13        0x10F8 //IEEE 754
#define I2_HD_14        0x10FA //IEEE 754
#define I2_HD_15        0x10FC //IEEE 754
#define I2_HD_16        0x10FE //IEEE 754
#define I2_HD_17        0x1100 //IEEE 754
#define I2_HD_18        0x1102 //IEEE 754
#define I2_HD_19        0x1104 //IEEE 754
#define I2_HD_20        0x1106 //IEEE 754
#define I2_HD_21        0x1108 //IEEE 754
#define I2_HD_22        0x110A //IEEE 754
#define I2_HD_23        0x110C //IEEE 754
#define I2_HD_24        0x110E //IEEE 754
#define I2_HD_25        0x1110 //IEEE 754
#define I2_HD_26        0x1112 //IEEE 754
#define I2_HD_27        0x1114 //IEEE 754
#define I2_HD_28        0x1116 //IEEE 754
#define I2_HD_29        0x1118 //IEEE 754
#define I2_HD_30        0x111A //IEEE 754
#define I2_HD_31        0x111C //IEEE 754
#define I2_HD_32        0x111E //IEEE 754
#define I2_HD_33        0x1120 //IEEE 754
#define I2_HD_34        0x1122 //IEEE 754
#define I2_HD_35        0x1124 //IEEE 754
#define I2_HD_36        0x1126 //IEEE 754
#define I2_HD_37        0x1128 //IEEE 754
#define I2_HD_38        0x112A //IEEE 754
#define I2_HD_39        0x112C //IEEE 754
#define I2_HD_40        0x112E //IEEE 754


//---AGRUPAMENTO DE HARMONICOS (CORRENTE FASE 3)---//

#define I3_HD_1         0x1130 //IEEE 754
#define I3_HD_2         0x1132 //IEEE 754
#define I3_HD_3         0x1134 //IEEE 754
#define I3_HD_4         0x1136 //IEEE 754
#define I3_HD_5         0x1138 //IEEE 754
#define I3_HD_6         0x113A //IEEE 754
#define I3_HD_7         0x113C //IEEE 754
#define I3_HD_8         0x113E //IEEE 754
#define I3_HD_9         0x1140 //IEEE 754
#define I3_HD_10        0x1142 //IEEE 754
#define I3_HD_11        0x1144 //IEEE 754
#define I3_HD_12        0x1146 //IEEE 754
#define I3_HD_13        0x1148 //IEEE 754
#define I3_HD_14        0x114A //IEEE 754
#define I3_HD_15        0x114C //IEEE 754
#define I3_HD_16        0x114E //IEEE 754
#define I3_HD_17        0x1150 //IEEE 754
#define I3_HD_18        0x1152 //IEEE 754
#define I3_HD_19        0x1154 //IEEE 754
#define I3_HD_20        0x1156 //IEEE 754
#define I3_HD_21        0x1158 //IEEE 754
#define I3_HD_22        0x115A //IEEE 754
#define I3_HD_23        0x115C //IEEE 754
#define I3_HD_24        0x115E //IEEE 754
#define I3_HD_25        0x1160 //IEEE 754
#define I3_HD_26        0x1162 //IEEE 754
#define I3_HD_27        0x1164 //IEEE 754
#define I3_HD_28        0x1166 //IEEE 754
#define I3_HD_29        0x1168 //IEEE 754
#define I3_HD_30        0x116A //IEEE 754
#define I3_HD_31        0x116C //IEEE 754
#define I3_HD_32        0x116E //IEEE 754
#define I3_HD_33        0x1170 //IEEE 754
#define I3_HD_34        0x1172 //IEEE 754
#define I3_HD_35        0x1174 //IEEE 754
#define I3_HD_36        0x1176 //IEEE 754
#define I3_HD_37        0x1178 //IEEE 754
#define I3_HD_38        0x117A //IEEE 754
#define I3_HD_39        0x117C //IEEE 754
#define I3_HD_40        0x117E //IEEE 754


//---STATUS DA CONEXAO ETHERNET---//

#define TCP_CON_QTY     0x0DAC //UINT 16-BIT
#define TCP_CON_QTY_MAX 0x0DAD //UINT 16-BIT
#define HTTP_CON_QTY    0x0DAE //UINT 16-BIT
#define MBTCP_CON_QTY   0x0DAF //UINT 16-BIT


//---CODIGOS DE ERRO---//

#define ERR_CODES       0x0F3C


//---STATUS - MEMORIA DE MASSA---//

#define CTRL_BLOCK_0    0x0F5A
#define CTRL_BLOCK_1    0x0F5B
#define CTRL_BLOCK_2    0x0F5C
#define CTRL_BLOCK_3    0x0F5D
#define SIZE_SECTOR_0   0x0F5E
#define SIZE_SECTOR_1   0x0F5F
#define SIZE_SECTOR_2   0x0F60
#define SIZE_SECTOR_3   0x0F61
#define SIZE_SECTOR_4   0x0F62
#define SIZE_SECTOR_5   0x0F63
#define SIZE_SECTOR_6   0x0F64
#define SIZE_SECTOR_7   0x0F65
#define SIZE_SECTOR_8   0x0F66
#define SIZE_SECTOR_9   0x0F67
#define SIZE_SECTOR_10  0x0F68
#define SIZE_SECTOR_11  0x0F69
#define SIZE_SECTOR_12  0x0F6A
#define SIZE_SECTOR_13  0x0F6B
#define SIZE_SECTOR_14  0x0F6C
#define SIZE_SECTOR_15  0x0F6D
#define SIZE_SECTOR_16  0x0F6E
#define SIZE_SECTOR_17  0x0F6F
#define SIZE_SECTOR_18  0x0F70
#define SIZE_SECTOR_19  0x0F71
#define SIZE_SECTOR_20  0x0F72
#define SIZE_SECTOR_21  0x0F73
#define SIZE_SECTOR_22  0x0F74
#define SIZE_SECTOR_23  0x0F75
#define SIZE_SECTOR_24  0x0F76
#define SIZE_SECTOR_25  0x0F77
#define SIZE_SECTOR_26  0x0F78
#define SIZE_SECTOR_27  0x0F79
#define SIZE_SECTOR_28  0x0F7A
#define SIZE_SECTOR_29  0x0F7B
#define SIZE_SECTOR_30  0x0F7C
#define SIZE_SECTOR_31  0x0F7D
#define SIZE_SECTOR_32  0x0F7E
#define SIZE_SECTOR_33  0x0F7F
#define SIZE_SECTOR_34  0x0F80


//---TEMPERATURAS---//

#define TEMP_VALUE      0x2328
#define TEMP_ADC        0x232A


//---ENTRADAS ANALOGICAS---//

#define VALUE_AIN1      0x233C
#define ADC_AIN1        0x233F
#define VALUE_AIN2      0x2341
#define ADC_AIN2        0x2343

//---MAC ADDRESS---//

#define MAC_ADDR        0x251C



//---POWERTAG LINK---//

//---GERAIS---//

#define PT_DATE         0x0073 //DATA DO POWERTAG LINK

//---CONFIGURACOES---//

#define PT_APP_NAME     0x7918 //NOME DA APLICACAO
#define PT_CIRC_NAME    0x7922 //NOME DO CIRCUITO
#define PT_PH_SEQ       0x7926 //FASE DO POWERTAG

//---GRANDEZAS ELETRICAS---//

#define PT_I_I1         0x0BB7 //CORRENTE NA FASE 1
#define PT_I_I2         0x0BB9 //CORRENTE NA FASE 2
#define PT_I_I3         0x0BBC //CORRENTE NA FASE 3

#define PT_V_U12        0x0BCB //TENSAO DE LINHA 1-2
#define PT_V_U23        0x0BCD //TENSAO DE LINHA 2-3
#define PT_V_U31        0x0BCF //TENSAO DE LINHA 3-1
    
#define PT_V_U1         0x0BD3 //TENSAO DE FASE 1
#define PT_V_U2         0x0BD5 //TENSAO DE FASE 2
#define PT_V_U3         0x0BD7 //TENSAO DE FASE 3
    
#define PT_P_P1         0x0BED //POTENCIA DA FASE 1
#define PT_P_P2         0x0BEF //POTENCIA DA FASE 2
#define PT_P_P3         0x0BF1 //POTENCIA DA FASE 3
#define PT_P_PT         0x0BF3 //POTENCIA TOTAL
    
#define PT_P_FP         0x0C0B //FATOR DE POTENCIA
    
#define PT_EA_T         0x0C83 //ENERGIA ATIVA TOTAL (NAO RESETAVEL)
#define PT_EA_P         0x0CB7 //ENERGIA ATIVA PARCIAL (RESETAVEL)
    
#define PT_EA_P_RESET   0x0CBB //ENDERECO PARA RESET DA ENERGIA ATIVA PARCIAL

#define PT_ALARMS       0x0CE3 //ENDERECO COM BITS DE ALARME

#define PT_OP_TIME      0x0CEB //TEMPO DE OPERACAO DESDE O ULTIMO RESET


//---ALARMES DO POWERTAG---//

#define PT_VOLTAGE_LOSS 0x0001 //PERDA DE TENSAO
#define PT_OL_AT_VL     0x0002 //SOBRECARGA NO MOMENTO DA PERDA DE TENSAO
#define PT_OL_45        0x0008 //CARGA ACIMA DE 45% DA NOMINAL
#define PT_ZERO_CURRENT 0x0010 //CORRENTE ZERADA
#define PT_OV_120       0x0020 //SOBRETENSAO ACIMA DE 120%
#define PT_UV_80        0x0040 //SUBTENSAO ABAIXO DE 80%
#define PT_LOW_BAT      0x0080 //BATERIA DO POWERTAG BAIXA

#endif /* constantes_h */
