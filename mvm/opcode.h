#ifndef MVM_OP_CODE_H
#define MVM_OP_CODE_H

#define MOV_REGISTER_MEMORY_TO_FROM_REGISTER_TO_REG_WORD 0x8B
#define MOV_REGISTER_MEMORY_TO_FROM_REGISTER_FROM_REG_WORD 0x89
#define MOV_REGISTER_MEMORY_TO_FROM_REGISTER_TO_REG_BYTE 0x8A
#define MOV_REGISTER_MEMORY_TO_FROM_REGISTER_FROM_REG_BYTE 0x88
#define MOV_IMMEDIATE_TO_REGISTER_MEMORY_WORD 0xC7
#define MOV_IMMEDIATE_TO_REGISTER_MEMORY_BYTE 0xC6
#define MOV_IMMEDIATE_TO_REGISTER_WORD_AX 0xB8
#define MOV_IMMEDIATE_TO_REGISTER_WORD_CX 0xB9
#define MOV_IMMEDIATE_TO_REGISTER_WORD_DX 0xBA
#define MOV_IMMEDIATE_TO_REGISTER_WORD_BX 0xBB
#define MOV_IMMEDIATE_TO_REGISTER_WORD_SP 0xBC
#define MOV_IMMEDIATE_TO_REGISTER_WORD_BP 0xBD
#define MOV_IMMEDIATE_TO_REGISTER_WORD_SI 0xBE
#define MOV_IMMEDIATE_TO_REGISTER_WORD_DI 0xBF
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_AL 0xB0
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_CL 0xB1
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_DL 0xB2
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_BL 0xB3
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_AH 0xB4
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_CH 0xB5
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_DH 0xB6
#define MOV_IMMEDIATE_TO_REGISTER_BYTE_BH 0xB7
#define MOV_MEMORY_TO_ACCUMULATOR_WORD 0xA1
#define MOV_MEMORY_TO_ACCUMULATOR_BYTE 0xA0
#define MOV_ACCUMULATOR_TO_MEMORY_WORD 0xA3
#define MOV_ACCUMULATOR_TO_MEMORY_BYTE 0xA2
#define MOV_REGISTER_MEMORY_TO_SEGMENT_REGISTER 0x8E
#define MOV_SEGMENT_REGISTER_TO_REGISTER_MEMORY 0x8C
#define PUSH_REGISTER_MEMORY 0xFF
#define PUSH_REGISTER_AX 0x50
#define PUSH_REGISTER_CX 0x51
#define PUSH_REGISTER_DX 0x52
#define PUSH_REGISTER_BX 0x53
#define PUSH_REGISTER_SP 0x54
#define PUSH_REGISTER_BP 0x55
#define PUSH_REGISTER_SI 0x56
#define PUSH_REGISTER_DI 0x57
#define PUSH_SEGMENT_REGISTER_ES 0x06
#define PUSH_SEGMENT_REGISTER_CS 0x0E
#define PUSH_SEGMENT_REGISTER_SS 0x16
#define PUSH_SEGMENT_REGISTER_DS 0x1E
#define POP_REGISTER_MEMORY 0x8F
#define POP_REGISTER_AX 0x58
#define POP_REGISTER_CX 0x59
#define POP_REGISTER_DX 0x5A
#define POP_REGISTER_BX 0x5B
#define POP_REGISTER_SP 0x5C
#define POP_REGISTER_BP 0x5D
#define POP_REGISTER_SI 0x5E
#define POP_REGISTER_DI 0x5F
#define POP_SEGMENT_REGISTER_ES 0x07
#define POP_SEGMENT_REGISTER_CS 0x0F
#define POP_SEGMENT_REGISTER_SS 0x17
#define POP_SEGMENT_REGISTER_DS 0x1F
#define XCHG_REGISTER_MEMORY_WITH_REGISTER_WORD 0x87
#define XCHG_REGISTER_MEMORY_WITH_REGISTER_BYTE 0x86
#define XCHG_REGISTER_WITH_ACCUMULATOR_AX 0x90
#define XCHG_REGISTER_WITH_ACCUMULATOR_CX 0x91
#define XCHG_REGISTER_WITH_ACCUMULATOR_DX 0x92
#define XCHG_REGISTER_WITH_ACCUMULATOR_BX 0x93
#define XCHG_REGISTER_WITH_ACCUMULATOR_SP 0x94
#define XCHG_REGISTER_WITH_ACCUMULATOR_BP 0x95
#define XCHG_REGISTER_WITH_ACCUMULATOR_SI 0x96
#define XCHG_REGISTER_WITH_ACCUMULATOR_DI 0x97
#define IN_FIXED_PORT_WORD 0xE5
#define IN_FIXED_PORT_BYTE 0xE4
#define IN_VARIABLE_PORT_WORD 0xED
#define IN_VARIABLE_PORT_BYTE 0xEC
#define OUT_FIXED_PORT_WORD 0xE7
#define OUT_FIXED_PORT_BYTE 0xE6
#define OUT_VARIABLE_PORT_WORD 0xEF
#define OUT_VARIABLE_PORT_BYTE 0xEE
#define XLAT 0xD7
#define LEA 0x8D
#define LDS 0xC5
#define LES 0xC4
#define LAHF 0x9F
#define SAHF 0x9E
#define PUSHF 0x9C
#define POPF 0x9D
#define ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_WORD 0x03
#define ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_WORD 0x01
#define ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_BYTE 0x02
#define ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_BYTE 0x00
#define ADD_IMMEDIATE_TO_REGISTER_MEMORY_WORD 0x81
#define ADD_IMMEDIATE_TO_REGISTER_MEMORY_BYTE 0x83
#define ADD_IMMEDIATE_TO_ACCUMULATOR_WORD 0x05
#define ADD_IMMEDIATE_TO_ACCUMULATOR_BYTE 0x04
#define ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_WORD 0x13
#define ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_WORD 0x11
#define ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_BYTE 0x12
#define ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_BYTE 0x10
#define ADC_IMMEDIATE_TO_REGISTER_MEMORY_WORD 0x81
#define ADC_IMMEDIATE_TO_REGISTER_MEMORY_BYTE 0x83
#define ADC_IMMEDIATE_TO_ACCUMULATOR_WORD 0x15
#define ADC_IMMEDIATE_TO_ACCUMULATOR_BYTE 0x14
#define INC_REGISTER_MEMORY_WORD 0xFF
#define INC_REGISTER_MEMORY_BYTE 0xFE
#define INC_REGISTER_AX 0x40
#define INC_REGISTER_CX 0x41
#define INC_REGISTER_DX 0x42
#define INC_REGISTER_BX 0x43
#define INC_REGISTER_SP 0x44
#define INC_REGISTER_BP 0x45
#define INC_REGISTER_SI 0x46
#define INC_REGISTER_DI 0x47
#define AAA 0x37
#define BAA 0x27
#define SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD 0x2B
#define SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD 0x29
#define SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE 0x2A
#define SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE 0x28
#define SUB_IMMEDIATE_FROM_REGISTER_MEMORY_WORD 0x81
#define SUB_IMMEDIATE_FROM_REGISTER_MEMORY_BYTE 0x83
#define SUB_IMMEDIATE_FROM_ACCUMULATOR_WORD 0x2D
#define SUB_IMMEDIATE_FROM_ACCUMULATOR_BYTE 0x2C
#define SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD 0x1B
#define SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD 0x19
#define SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE 0x1A
#define SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE 0x18
#define SSB_IMMEDIATE_FROM_REGISTER_MEMORY_WORD 0x81
#define SSB_IMMEDIATE_FROM_REGISTER_MEMORY_BYTE 0x83
#define SSB_IMMEDIATE_FROM_ACCUMULATOR_WORD 0x1D
#define SSB_IMMEDIATE_FROM_ACCUMULATOR_BYTE 0x1C
#define DEC_REGISTER_MEMORY_WORD 0xFF
#define DEC_REGISTER_MEMORY_BYTE 0xFE
#define DEC_REGISTER_AX 0x48
#define DEC_REGISTER_CX 0x49
#define DEC_REGISTER_DX 0x4A
#define DEC_REGISTER_BX 0x4B
#define DEC_REGISTER_SP 0x4C
#define DEC_REGISTER_BP 0x4D
#define DEC_REGISTER_SI 0x4E
#define DEC_REGISTER_DI 0x4F
#define NEG_WORD 0xF7
#define NEG_BYTE 0xF6
#define CMP_REGISTER_MEMORY_AND_REGISTER_TO_REGISTER_WORD 0x3B
#define CMP_REGISTER_MEMORY_AND_REGISTER_FROM_REGISTER_WORD 0x39
#define CMP_REGISTER_MEMORY_AND_REGISTER_TO_REGISTER_BYTE 0x3A
#define CMP_REGISTER_MEMORY_AND_REGISTER_FROM_REGISTER_BYTE 0x38
#define CMP_IMMEDIATE_WITH_REGISTER_MEMORY_WORD 0x81
#define CMP_IMMEDIATE_WITH_REGISTER_MEMORY_BYTE 0x83
#define CMP_IMMEDIATE_WITH_ACCUMULATOR_WORD 0x3D
#define CMP_IMMEDIATE_WITH_ACCUMULATOR_BYTE 0x3C
#define AAS 0x3F
#define DAS 0x2F
#define MUL_WORD 0xF7
#define MUL_BYTE 0xF6
#define IMUL_WORD 0xF7
#define IMUL_BYTE 0xF6
#define AAM 0xD4
#define DIV_WORD 0xF7
#define DIV_BYTE 0xF6
#define IDIV_WORD 0xF7
#define IDIV_BYTE 0xF6
#define AAD 0xD5
#define CBW 0x98
#define CWD 0x99
#define NOT_WORD 0xF7
#define NOT_BYTE 0xF6
#define SHL_SAL_COUNT_1_WORD 0xD1
#define SHL_SAL_COUNT_1_BYTE 0xD0
#define SHL_SAL_COUNT_AL_WORD 0xD3
#define SHL_SAL_COUNT_AL_BYTE 0xD2
#define SHR_COUNT_1_WORD 0xD1
#define SHR_COUNT_1_BYTE 0xD0
#define SHR_COUNT_AL_WORD 0xD3
#define SHR_COUNT_AL_BYTE 0xD2
#define SAR_COUNT_1_WORD 0xD1
#define SAR_COUNT_1_BYTE 0xD0
#define SAR_COUNT_AL_WORD 0xD3
#define SAR_COUNT_AL_BYTE 0xD2
#define ROL_COUNT_1_WORD 0xD1
#define ROL_COUNT_1_BYTE 0xD0
#define ROL_COUNT_AL_WORD 0xD3
#define ROL_COUNT_AL_BYTE 0xD2
#define ROR_COUNT_1_WORD 0xD1
#define ROR_COUNT_1_BYTE 0xD0
#define ROR_COUNT_AL_WORD 0xD3
#define ROR_COUNT_AL_BYTE 0xD2
#define RCL_COUNT_1_WORD 0xD1
#define RCL_COUNT_1_BYTE 0xD0
#define RCL_COUNT_AL_WORD 0xD3
#define RCL_COUNT_AL_BYTE 0xD2
#define RCR_COUNT_1_WORD 0xD1
#define RCR_COUNT_1_BYTE 0xD0
#define RCR_COUNT_AL_WORD 0xD3
#define RCR_COUNT_AL_BYTE 0xD2
#define AND_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD 0x23
#define AND_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD 0x21
#define AND_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE 0x22
#define AND_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE 0x20
#define AND_IMMEDIATE_TO_REGISTER_MEMORY_WORD 0x81
#define AND_IMMEDIATE_TO_REGISTER_MEMORY_BYTE 0x80
#define AND_IMMEDIATE_TO_ACCUMULATOR_WORD 0x25
#define AND_IMMEDIATE_TO_ACCUMULATOR_BYTE 0x24
#define TEST_REGISTER_MEMORY_AND_REGISTER_WORD 0x85
#define TEST_REGISTER_MEMORY_AND_REGISTER_BYTE 0x84
#define TEST_IMMEDIATE_DATA_AND_REGISTER_MEMORY_WORD 0xF7
#define TEST_IMMEDIATE_DATA_AND_REGISTER_MEMORY_BYTE 0xF6
#define TEST_IMMEDIATE_DATA_AND_ACCUMULATOR_WORD 0xA9
#define TEST_IMMEDIATE_DATA_AND_ACCUMULATOR_BYTE 0xA8
#define OR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD 0x0B
#define OR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD 0x09
#define OR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE 0x0A
#define OR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE 0x08
#define OR_IMMEDIATE_TO_REGISTER_MEMORY_WORD 0x81
#define OR_IMMEDIATE_TO_REGISTER_MEMORY_BYTE 0x80
#define OR_IMMEDIATE_TO_ACCUMULATOR_WORD 0x0D
#define OR_IMMEDIATE_TO_ACCUMULATOR_BYTE 0x0C
#define XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD 0x33
#define XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD 0x31
#define XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE 0x32
#define XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE 0x30
#define XOR_IMMEDIATE_TO_REGISTER_MEMORY_WORD 0x81
#define XOR_IMMEDIATE_TO_REGISTER_MEMORY_BYTE 0x80
#define XOR_IMMEDIATE_TO_ACCUMULATOR_WORD 0x35
#define XOR_IMMEDIATE_TO_ACCUMULATOR_BYTE 0x34
#define REP_Z_1 0xF3
#define REP_Z_0 0xF2
#define MOVS_WORD 0xA5
#define MOVS_BYTE 0xA4
#define CMPS_WORD 0xA7
#define CMPS_BYTE 0xA6
#define SCAS_WORD 0xAF
#define SCAS_BYTE 0xAE
#define LODS_WORD 0xAD
#define LODS_BYTE 0xAC
#define STOS_WORD 0xAB
#define STOS_BYTE 0xAA
#define CALL_DIRECT_WITHIN_SEGMENT 0xE8
#define CALL_INDIRECT_WITHIN_SEGMENT 0xFF
#define CALL_DIRECT_INTERSEGMENT 0x9A
#define CALL_INDIRECT_INTERSEGMENT 0xFF
#define JMP_DIRECT_WITHIN_SEGMENT 0xE9
#define JMP_DIRECT_WITHIN_SEGMENT_SHORT 0xEB
#define JMP_INDIRECT_WITHIN_SEGMENT 0xFF
#define JMP_DIRECT_INTERSEGMENT 0xEA
#define JMP_INDIRECT_INTERSEGMENT 0xFF
#define RET_WITHIN_SEGMENT 0xC3
#define RET_WITHIN_SEG_ADDING_IMMED_TO_SP 0xC2
#define RET_INTERSEGMENT 0xCB
#define RET_INTERSEGMENT_ADDING_IMMEDIATE_TO_SP 0xCA
#define JE_JZ 0x74
#define JL_JNGE 0x7C
#define JLE_JNG 0x7E
#define JB_JNAE 0x72
#define JBE_JNA 0x76
#define JP_JNE 0x7A
#define JO 0x70
#define JS 0x78
#define JNE_JNZ 0x75
#define JNL_JGE 0x7D
#define JNLE_JG 0x7F
#define JNB_JAE 0x73
#define JNBE_JA 0x77
#define JNP_JPO 0x7B
#define JNO 0x71
#define JNS 0x79
#define LOOP 0xE2
#define LOOPZ_LOOPE 0xE1
#define LOOPNZ_LOOPNE 0xE0
#define JCXZ 0xE3
#define INT_TYPE_SPEC 0xCD
#define INT_TYPE_3 0xCC
#define INTO 0xCE
#define IRET 0xCF
#define CLC 0xF8
#define CMC 0xF5
#define STC 0xF9
#define CLD 0xFC
#define STD 0xFD
#define CLI 0xFA
#define STI 0xFB
#define HLT 0xF4
#define WAIT 0x9B
#define ESC_0 0xD8
#define ESC_1 0xD9
#define ESC_2 0xDA
#define ESC_3 0xDB
#define ESC_4 0xDC
#define ESC_5 0xDD
#define ESC_6 0xDE
#define ESC_7 0xDF
#define LOCK 0xF0

#endif