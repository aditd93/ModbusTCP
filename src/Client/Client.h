#ifndef CLIENT_H_
#define CLIENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include "../ADU.h"


// Variables and Macros
#define READ_COILS 0x01
#define READ_DISCRETE_INPUTS 0x02
#define READ_MULTIPLE_HOLDING_REGISTERS 0x03
#define READ_INPUT_REGISTERS 0X04
#define WRITE_SINGLE_COIL 0x05
#define WRITE_SINGLE_HOLDING_REGISTER 0X06
#define WRITE_MULTIPLE_COILS 0x0F
#define Write_MULTIPLE_HOLDING_REGISTERS 0x10

typedef struct Client {
    char *Server_IP; // Modbus remote server IP address
    int port;
    int socket;
} Client;

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


// Client's header functions
    /*  Valid registers types are:
        0 - Coils
        1 - Discrete inputs
        2 - Input registers
        3 - Holding registers
    */

#endif /* CLIENT_HEADER_H_ */