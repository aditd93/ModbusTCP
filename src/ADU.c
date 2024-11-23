#include "ADU.h"

ADU *Request(char mode,int reg_type, int start, int offset) {
    // Initiate request to a server by client

    switch(mode) {
        case 'r':
        ADU *adu = Request_read(reg_type, start, offset);
        break;

        case 'w':
        ADU *adu = Request_write(reg_type, start, offset);
        break;

        default:
        break;
    }
}

ADU *Request_read(int reg_type, uint16_t start, uint16_t offset) {
    // receives transation ID from user
    PDU *pdu = (PDU*)malloc(sizeof(PDU));
    MBAP *mbap = (MBAP*)malloc(sizeof(MBAP));
    ADU *adu = (ADU*)malloc(sizeof(ADU));
    if(pdu == NULL || mbap == NULL || adu == NULL) {
        fprintf(stderr, "Failed to allocate memort for PDU/MBAP/ADU Read Request\n");
        exit(EXIT_FAILURE); // Maybe just return NULL and an error 
    }
    // Encode the requested PDU
    pdu->function_code = reg_type + 1; // according to first enumaration
    pdu->data = (uint16_t*)malloc(sizeof(uint16_t)*2); // [Starting address], [Quantity of registers]
    if(pdu->data == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for PDU\n");
        exit(EXIT_FAILURE); // or return NULL
    }
    uint16_t data[2] = {start,offset};
    memcpy(pdu->data,&data, 2);

    // MBAP encoding
    mbap->Protocol_ID = PROTOCOL_ID; 
    mbap->Unit_ID = UNIT_ID;
    mbap->length = sizeof(mbap->Unit_ID) + sizeof(pdu);

    // ADU encoding
    adu->mbap = mbap;
    adu->pdu;

    return adu;
}