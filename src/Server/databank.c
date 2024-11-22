#include "databank.h"

DataBank *create_DB(int coils_num,int discrete_inputs_num,int inputs_regs_num,int holding_regs_num) {
    DataBank *DB = (DataBank*)malloc(sizeof(DataBank));
    if(DB == NULL) {
        fprintf(stderr, "Failed to allocate memory for new DataBank\n");
        exit(EXIT_FAILURE);
    }
    DB->coils_num = coils_num;    DB->discrete_num = discrete_inputs_num;    
    DB->input_regs_num = inputs_regs_num;    DB->holding_regs_num = holding_regs_num;
    DB->coils = (coils_num > 0) ? (bool*)calloc(coils_num,sizeof(bool)) : NULL;
    DB->discrete_regs = (discrete_inputs_num > 0) ? (bool*)calloc(discrete_inputs_num,sizeof(bool)) : NULL;
    DB->input_regs = (inputs_regs_num > 0) ? (uint16_t*)calloc(inputs_regs_num,sizeof(uint16_t)) : NULL;
    DB->holding_regs = (holding_regs_num > 0) ? (uint16_t*)calloc(holding_regs_num,sizeof(uint16_t)) : NULL;
    if((DB->coils == NULL && coils_num > 0) || (DB->discrete_regs == NULL && discrete_inputs_num > 0) || (DB->input_regs == NULL && inputs_regs_num > 0) || (DB->holding_regs == NULL && holding_regs_num > 0)) {
        fprintf(stderr, "ERROR: Failed to allocate memory for new DataBank\n");
        free(DB);
        exit(EXIT_FAILURE);
    }
    return DB;
}

void Modify_DB(DataBank *DB) {
    // DataBank modification due to write request coming from a client
}