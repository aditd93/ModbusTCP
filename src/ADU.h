#ifndef ADU_H_
#define ADU_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include "../Client/Client.c"

// Variables and Macros
#define READ_COILS 0x01
#define READ_DISCRETE_INPUTS 0x02
#define READ_MULTIPLE_HOLDING_REGISTERS 0x03
#define READ_INPUT_REGISTERS 0X04
#define WRITE_SINGLE_COIL 0x05
#define WRITE_SINGLE_HOLDING_REGISTER 0X06
#define WRITE_MULTIPLE_COILS 0x0F
#define Write_MULTIPLE_HOLDING_REGISTERS 0x10
#define PROTOCOL_ID 0x00
#define UNIT_ID 0xFF

enum reg_type{COIL, DISCRETE, I_REG, H_REG};

typedef struct PDU {
    uint8_t function_code;
    void* data;
} PDU;

// MBAP header 
typedef struct MBAP {
    uint16_t Transaction_ID; // 
    uint16_t Protocol_ID; // =0x00 Modbus protocol
    uint16_t length;    // Frame bytes counter: Unit_ID [1] + Function_code [1] + HIGH+LOW register start address [2] + number of registers to read/write [2]
    uint8_t Unit_ID; // =0xFF

} MBAP;

typedef struct ADU {
    MBAP *mbap;     // Modbus application header
    PDU *pdu;       // if need
} ADU;

/*  
    Notes:
    |                         - MBAP -               |       - PDU -        |
    =========================================================================
    | Transaction ID| Protocol ID | Length | Unit ID | Fucntion code | Data |
    =========================================================================
    |                                - ADU -                                |

    Client / Server Model
    * Modbus Request        |   Client -- > Server
    * Modbus Indication     |   Server internal
    * Modbus Response       |   Server -- > Client
    * Modbus Confirmation   |   Client internal
*/

// functions

// Server's header functions
ADU *Indication();
ADU *Response();

// Client's header functions
    /*  Valid registers types are:
        0 - Coils
        1 - Discrete inputs
        2 - Input registers
        3 - Holding registers
    */
ADU *Request(char mode, int reg_type, int start, int offset);
ADU *Request_read(int reg_type, int start, int offset);
ADU *Request_write(int reg_type, uint16_t start, uint16_t offset);
ADU *Confirmation();


#endif /* ADU_HEADER_H_ */