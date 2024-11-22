#ifndef DATABANK_H_
#define DATABANK_H_
#include "../ADU.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

// Variables and Macros
#define READ_COILS 0x01
#define READ_DISCRETE_INPUTS 0x02
#define READ_MULTIPLE_HOLDING_REGISTERS 0x03
#define READ_INPUT_REGISTERS 0X04
#define WRITE_SINGLE_COIL 0x05
#define WRITE_SINGLE_HOLDING_REGISTER 0X06

// Server's databank of registers

typedef struct DataBank {
    int coils_num, discrete_num, input_regs_num, holding_regs_num;
    bool *coils;            // Read/Write discrete inputs
    bool *discrete_regs;    // Read only discrete inputs
    uint16_t *input_regs;   // Read only 16-bits registers
    uint16_t *holding_regs; // Read/Write 16-bits registers
} DataBank;

/*  
    Notes:
    |                         - MBAP -               |       - PDU -        |
    =========================================================================
    | Transaction ID| Protocol ID | Length | Unit ID | Fucntion code | Data |
    =========================================================================
    |                                - ADU -                                |
*/

// functions
DataBank *create_DB(int coils_num,int discrete_inputs_num,int inputs_regs_num,int holding_regs_num);
void Modify_DB(DataBank *DB);


#endif /* DATABANK_HEADER_H_ */