#ifndef RUN_H
#define RUN_H


/*//////////////////////////////////////////////////////////

FP SP

stack unit is INT
_ _ _ _ xxx yyy | is a description of stack

LOC             12      ; _ _ _ _ | ==> _ _ _ _ 12 |
LOA      offset(-5)     ; _ _ _ _ | ==> _ _ _ _ FP+offset
        STO                     ; _ _ _ _ data(12) addr(10) | ==> _ _ _ _ |
MEM(addr) = 12
LOV      offset(-5)     ; _ _ _ _ | -> _ _ _ _ MEM(FP+offset) |   means: LOA offset; IND 0;
STN                     ; _ _ _ _ data(12) addr(5) | ==> _ _ _ _ data(12)
MEM(addr) = 12
LAB             L1      ;
JMP             L1      ;
CJMP            L1      ; _ _ _ _ data(12) | ==> _ _ _ _ |
IF(data(12)==0) JMP L1
IND             3       ; _ _ _ _ 12 | ==> _ _ _ _ MEM(12+3)
ADD                     ; _ _ _ _ l r | ==> _ _ _ _ l+r |
SUB                     ; _ _ _ _ l r | ==> _ _ _ _ l-r |
MPI                     ; _ _ _ _ l r | ==> _ _ _ _ l*r |
DIV                     ; _ _ _ _ l r | ==> _ _ _ _ l/r |
GT                      ;
GTE                     ;
LTE                     ;
LT                      ;
EQ                      ;
NEQ                     ;
CALL            L1      ;_ _ return_value p2 p1 | ==> _ _ return_value p2 p1 NEXT(this_inst) FP reserverd1 |
FP = SP
RET                     ;_ _ return_value p2 p1 NEXT(this_inst) FP reserverd1 | ==> _ _ return_value |
recover the next instruction and FP
        RETN                    ;_ _ return_value ... p2 p1 CNT NEXT(this_inst) FP reserverd1 | ==> _ _ return_value |
ALC             3       ;_ _ | ==> _ _ _ _ _ |
DALC            1       ;_ _ _ | ==> _ _ |

///////////////////////////////////////////////////////////*/

struct InstList;



bool load_insts(InstList *src);

#endif