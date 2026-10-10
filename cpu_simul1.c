#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_reg_index(char *reg) {
    if (strcmp(reg, "R0") == 0) return 0;
    if (strcmp(reg, "R1") == 0) return 1;
    if (strcmp(reg, "R2") == 0) return 2;
    if (strcmp(reg, "R3") == 0) return 3;
    return -1; 
}

int main(int argc, char *argv[])
{
    char instructions[100][100]; 
    int count = 0;               

    if (argc < 2) {
        printf("Error: Missing input file argument.\n");
        return 1;
    }

    FILE *p = fopen(argv[1], "r");
    if (p == NULL) {
        printf("Error: Could not open file %s.\n", argv[1]);
        return 1;
    }

    
    while (count < 100 && fgets(instructions[count], 100, p) != NULL) {
        if (instructions[count][0] != '\0' && instructions[count][0] != '\n') {
            count++;
        }
    }
    fclose(p);

    int R[4] = {0, 0, 0, 0}; 
    int PC = 0;              
    int step_count = 0;      

while (PC < count) {
    if (step_count >= 10000) {
        printf("Error: Infinite loop detected (exceeded 10000 steps).\n");
        return 1;
    }

    char op[10] = "", arg1[10] = "", arg2[10] = "";
    int num_args = sscanf(instructions[PC], "%s %s %s", op, arg1, arg2);

    if (num_args <= 0) {
        PC++;
        continue;
    }


    if (strcmp(op, "HALT") == 0) {
        break;
    }
    
    else if (strcmp(op, "SET") == 0) {
        int reg = get_reg_index(arg1);
        if (reg == -1) {
            printf("Error at instruction %d: Invalid register %s\n", PC, arg1);
            return 1;
        }
        R[reg] = atoi(arg2); 
        PC++;
    }
    
    else if (strcmp(op, "ADD") == 0) {
        int r1 = get_reg_index(arg1);
        int r2 = get_reg_index(arg2);
        if (r1 == -1 || r2 == -1) {
            printf("Error at instruction %d: Invalid register\n", PC);
            return 1;
        }
        R[r1] += R[r2]; 
        PC++;
    }
    

    else if (strcmp(op, "SUB") == 0) {
        int r1 = get_reg_index(arg1);
        int r2 = get_reg_index(arg2);
        if (r1 == -1 || r2 == -1) {
            printf("Error at instruction %d: Invalid register\n", PC);
            return 1;
        }
        R[r1] -= R[r2]; 
        PC++;
    }

    else if (strcmp(op, "PRINT") == 0) {
        int reg = get_reg_index(arg1);
        if (reg == -1) {
            printf("Error at instruction %d: Invalid register %s\n", PC, arg1);
            return 1;
        }
        printf("%d\n", R[reg]);
        PC++;
    }
    
    else if (strcmp(op, "JMP") == 0) {
        int target = atoi(arg1);
        if (target < 0 || target >= count) {
            printf("Error at instruction %d: Invalid jump address %d\n", PC, target);
            return 1;
        }
        PC = target;
    }
    
    else if (strcmp(op, "JNZ") == 0) {
        int reg = get_reg_index(arg1);
        int target = atoi(arg2);
        if (reg == -1 || target < 0 || target >= count) {
            printf("Error at instruction %d: Invalid arguments for JNZ\n", PC);
            return 1;
        }
        if (R[reg] != 0) {
            PC = target;
        } else {
            PC++;
        }
    }
    
    else {
        printf("Error at instruction %d: Unknown instruction %s\n", PC, op);
        return 1;
    }

    step_count++;
}

    return 0;
}
