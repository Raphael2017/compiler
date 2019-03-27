#include "mvm.h"
#include <assert.h>
#include "opcode.h"

namespace moon_vm
{
    BYTE BIT_543(INST inst) { BYTE ret = 0; ret = inst << 2;ret = ret >> 5; return ret; }
    BYTE BIT_76(INST inst) { return inst >> 6; }
    BYTE BIT_210(INST inst) {  BYTE ret = 0; ret = inst << 5;ret = ret >> 5; return ret; }
    bool IS_WORD_0(INST inst) { BYTE ret = 0; ret = inst << 7;ret = ret >> 7; return ret==1; }
    bool IS_WORD_3(INST inst) { BYTE ret = 0; ret = inst << 4;ret = ret >> 7; return ret==1; }
    bool IS_TO_REG(INST inst) { BYTE ret = 0; ret = inst << 6;ret = ret >> 7; return ret==1; }
    std::string GET_OP(INST inst)
    {
        switch (inst)
        {
            case MOV_IMMEDIATE_TO_REGISTER_MEMORY_WORD:
            case MOV_IMMEDIATE_TO_REGISTER_MEMORY_BYTE:
                return "MOV ";
            case CMP_IMMEDIATE_WITH_ACCUMULATOR_WORD:
            case CMP_IMMEDIATE_WITH_ACCUMULATOR_BYTE:
                return "CMP ";
            case PUSH_SEGMENT_REGISTER_ES:
            case PUSH_SEGMENT_REGISTER_CS:
            case PUSH_SEGMENT_REGISTER_SS:
            case PUSH_SEGMENT_REGISTER_DS:
                return "PUSH ";
            case POP_SEGMENT_REGISTER_ES:
            case POP_SEGMENT_REGISTER_CS:
            case POP_SEGMENT_REGISTER_SS:
            case POP_SEGMENT_REGISTER_DS:
                return "POP ";
            case PUSH_REGISTER_AX:
            case PUSH_REGISTER_CX:
            case PUSH_REGISTER_DX:
            case PUSH_REGISTER_BX:
            case PUSH_REGISTER_SP:
            case PUSH_REGISTER_BP:
            case PUSH_REGISTER_SI:
            case PUSH_REGISTER_DI:
                return "PUSH ";
            case POP_REGISTER_AX:
            case POP_REGISTER_CX:
            case POP_REGISTER_DX:
            case POP_REGISTER_BX:
            case POP_REGISTER_SP:
            case POP_REGISTER_BP:
            case POP_REGISTER_SI:
            case POP_REGISTER_DI:
                return "POP ";
            case INC_REGISTER_AX:
            case INC_REGISTER_CX:
            case INC_REGISTER_DX:
            case INC_REGISTER_BX:
            case INC_REGISTER_SP:
            case INC_REGISTER_BP:
            case INC_REGISTER_SI:
            case INC_REGISTER_DI:
                return "INC ";
            case DEC_REGISTER_AX:
            case DEC_REGISTER_CX:
            case DEC_REGISTER_DX:
            case DEC_REGISTER_BX:
            case DEC_REGISTER_SP:
            case DEC_REGISTER_BP:
            case DEC_REGISTER_SI:
            case DEC_REGISTER_DI:
                return "DEC ";
            case LAHF:
                return "LAHF ";
            case SAHF:
                return "SAHF ";
            case PUSHF:
                return "PUSHF ";
            case POPF:
                return "POPF ";
            case LEA:
                return "LEA ";
            case LDS:
                return "LDS ";
            case LES:
                return "LES ";
            case XLAT:
                return "XLATB ";
            case AAA:
                return "AAA ";
            case BAA:
                return "BAA ";
            case AAS:
                return "AAS ";
            case DAS:
                return "DAS ";
            case AAM:
                return "AAM ";
            case AAD:
                return "AAD ";
            case CBW:
                return "CBW ";
            case CWD:
                return "CWD ";
            case REP_Z_1:
                return "REPE (unused)";
            case REP_Z_0:
                return "REPNE (unused)";
            case MOVS_WORD:
                return "MOVSW ";
            case MOVS_BYTE:
                return "MOVSB ";
            case CMPS_WORD:
                return "CMPSW ";
            case CMPS_BYTE:
                return "CMPSB ";
            case SCAS_WORD:
                return "SCASW ";
            case SCAS_BYTE:
                return "SCASB ";
            case LODS_WORD:
                return "LODSW ";
            case LODS_BYTE:
                return "LODSB ";
            case STOS_WORD:
                return "STOSW ";
            case STOS_BYTE:
                return "STOSB ";
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_TO_REG_BYTE:
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_TO_REG_WORD:
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_FROM_REG_WORD:
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_FROM_REG_BYTE:
                return "MOV ";
            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_WORD:
            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_WORD:
            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_BYTE:
            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_BYTE:
                return "ADD ";
            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_WORD:
            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_WORD:
            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_BYTE:
            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_BYTE:
                return "ADC ";
            case ADD_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case ADD_IMMEDIATE_TO_ACCUMULATOR_BYTE:
                return "ADD ";
            case ADC_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case ADC_IMMEDIATE_TO_ACCUMULATOR_BYTE:
                return "ADC ";
            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:
                return "SUB ";
            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:
                return "SSB ";
            case CMP_REGISTER_MEMORY_AND_REGISTER_TO_REGISTER_WORD:
            case CMP_REGISTER_MEMORY_AND_REGISTER_FROM_REGISTER_WORD:
            case CMP_REGISTER_MEMORY_AND_REGISTER_TO_REGISTER_BYTE:
            case CMP_REGISTER_MEMORY_AND_REGISTER_FROM_REGISTER_BYTE:
                return "CMP ";
            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:
                return "AND ";
            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:
                return "OR ";
            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:
                return "XOR ";
            case SUB_IMMEDIATE_FROM_ACCUMULATOR_WORD:
            case SUB_IMMEDIATE_FROM_ACCUMULATOR_BYTE:
                return "SUB ";
            case SSB_IMMEDIATE_FROM_ACCUMULATOR_WORD:
            case SSB_IMMEDIATE_FROM_ACCUMULATOR_BYTE:
                return "SSB ";
            case AND_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case AND_IMMEDIATE_TO_ACCUMULATOR_BYTE:
                return "AND ";
            case OR_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case OR_IMMEDIATE_TO_ACCUMULATOR_BYTE:
                return "OR ";
            case XOR_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case XOR_IMMEDIATE_TO_ACCUMULATOR_BYTE:
                return "XOR ";
            default:
                assert(false);
        }
    }
    std::string TO_REG(BYTE byt, bool word_flag)
    {
        switch (byt)
        {
            case 0x00:
            {
                if (word_flag)
                    return "AX";
                else
                    return "AL";
            }
                break;
            case 0x01:
            {
                if (word_flag)
                    return "CX";
                else
                    return "CL";
            }
                break;
            case 0x02:
            {
                if (word_flag)
                    return "DX";
                else
                    return "DL";
            }
                break;
            case 0x03:
            {
                if (word_flag)
                    return "BX";
                else
                    return "BL";
            }
                break;
            case 0x04:
            {
                if (word_flag)
                    return "SP";
                else
                    return "AH";
            }
                break;
            case 0x05:
            {
                if (word_flag)
                    return "BP";
                else
                    return "CH";
            }
                break;
            case 0x06:
            {
                if (word_flag)
                    return "SI";
                else
                    return "DH";
            }
                break;
            case 0x07:
            {
                if (word_flag)
                    return "DI";
                else
                    return "BH";
            }
                break;
            default:
                assert(false);
        }
    }
    std::string TO_SEG_REG(BYTE byt)
    {
        switch (byt)
        {
            case 0x00:
                return "ES";
            case 0x01:
                return "CS";
            case 0x02:
                return "SS";
            case 0x03:
                return "DS";
            default:
                assert(false);
        }
    }
    std::string ACCU(bool word_flag)
    {
        if (word_flag)
            return "AX";
        else
            return "AL";
    }
    std::string TO_MEM(BYTE byt)
    {
        switch (byt)
        {
            case 0x00:
            {
                return "BX+SI";
            }
                break;
            case 0x01:
            {
                return "BX+DI";
            }
                break;
            case 0x02:
            {
                return "BP+SI";
            }
                break;
            case 0x03:
            {
                return "BP+DI";
            }
                break;
            case 0x04:
            {
                return "SI";
            }
                break;
            case 0x05:
            {
                return "DI";
            }
                break;
            case 0x06:
            {
                return "BP";
            }
                break;
            case 0x07:
            {
                return "BX";
            }
                break;
            default:
                assert(false);
        }
    }
    std::string TO_0XSTR(BYTE byt)
    {
        char buf[4] = { 0 };
        snprintf(buf, 4, "%02X", byt);
        return buf;
    }
    struct ModRegRm {
        void parse1(vm &mm, bool is_word) {
            auto inst = mm.cur_inst();
            BYTE mod = BIT_76(inst);
            BYTE reg_ = BIT_543(inst);
            auto reg = TO_REG(reg_, is_word);
            auto rm = TO_MEM(BIT_210(inst));
            switch (mod) {
                case 0x00: {
                    if (BIT_210(inst) == 0x06) {
                        auto DISP = mm.read_as_str(true);
                        A = reg;
                        B = "[" + DISP + "]";
                    } else {
                        A = reg;
                        B = "[" + rm + "]";
                    }
                }
                    break;
                case 0x01: {
                    auto DISP = mm.read_as_str(false);
                    A = reg;
                    B = "[" + rm + "+" + DISP + "]";
                }
                    break;
                case 0x02: {
                    auto DISP = mm.read_as_str(true);
                    A = reg;
                    B = "[" + rm + "+" + DISP + "]";
                }
                    break;
                case 0x03: {
                    A = TO_REG(BIT_543(inst), is_word);
                    B = TO_REG(BIT_210(inst), is_word);
                }
                    break;
                default:
                    assert(false);
            }
        }
        void parse2(vm &mm, bool is_word) {
            auto inst = mm.cur_inst();
            BYTE mod = BIT_76(inst);
            BYTE reg_ = BIT_543(inst);
            assert(reg_ == 0 || reg_ == 6 || reg_ == 7);
            BYTE rm_ = BIT_210(inst);
            auto rm = TO_MEM(BIT_210(inst));
            switch (mod) {
                case 0x00: {

                    if (BIT_210(inst) == 0x06) {
                        auto DISP = mm.read_as_str(true);
                        A = "[" + DISP + "]";
                    } else {
                        A = "[" + rm + "]";
                    }
                    if (is_word)
                        A = "WORD PTR " + A;
                    else
                        A = "BYTE PTR " + A;
                }
                    break;
                case 0x01: {
                    auto DISP = mm.read_as_str(false);
                    A = "[" + rm + "+" + DISP + "]";
                    if (is_word)
                        A = "WORD PTR " + A;
                    else
                        A = "BYTE PTR " + A;
                }
                    break;
                case 0x02: {
                    auto DISP = mm.read_as_str(true);
                    A = "[" + rm + "+" + DISP + "]";
                    if (is_word)
                        A = "WORD PTR " + A;
                    else
                        A = "BYTE PTR " + A;
                }
                    break;
                case 0x03: {
                    A = TO_REG(rm_, is_word);
                }
                    break;
                default:
                    assert(false);
            }
        }
        void parse3(vm &mm) {
            auto inst = mm.cur_inst();
            BYTE mod = BIT_76(inst);
            BYTE reg_ = BIT_543(inst);
            assert(reg_ < 4);
            auto reg = TO_SEG_REG(reg_);
            auto rm = TO_MEM(BIT_210(inst));
            switch (mod) {
                case 0x00: {
                    if (BIT_210(inst) == 0x06) {
                        auto DISP = mm.read_as_str(true);
                        A = reg;
                        B = "[" + DISP + "]";
                    } else {
                        A = reg;
                        B = "[" + rm + "]";
                    }
                    B = "WORD PTR "+B;
                }
                    break;
                case 0x01: {
                    auto DISP = mm.read_as_str(false);
                    A = reg;
                    B = "[" + rm + "+" + DISP + "]";
                    B = "WORD PTR "+B;
                }
                    break;
                case 0x02: {
                    auto DISP = mm.read_as_str(true);
                    A = reg;
                    B = "[" + rm + "+" + DISP + "]";
                    B = "WORD PTR "+B;
                }
                    break;
                case 0x03: {
                    A = TO_REG(BIT_543(inst), true);
                    B = TO_REG(BIT_210(inst), true);
                    B = "WORD PTR "+B;
                }
                    break;
                default:
                    assert(false);
            }
        }
        std::string A;
        std::string B;
    };
    std::string vm::read_as_str(bool is_word)
    {
        std::string DATA;
        INST inst;
        if (is_word)
        {
            next_inst();
            inst = cur_inst();
            auto d_low = TO_0XSTR(inst);
            next_inst();
            inst = cur_inst();
            auto d_high = TO_0XSTR(inst);
            DATA = d_high+d_low;
        }
        else
        {
            next_inst();
            inst = cur_inst();
            auto d_low = TO_0XSTR(inst);
            DATA = d_low;
        }
        return DATA;
    }
    std::string vm::translate_one()
    {
        INST inst = cur_inst();
        bool is_word = false;
        bool is_to_reg = false;
        std::string REG;
        std::string result;
        switch (inst)
        {
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_TO_REG_BYTE:
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_TO_REG_WORD:
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_FROM_REG_WORD:
            case MOV_REGISTER_MEMORY_TO_FROM_REGISTER_FROM_REG_BYTE:

            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_WORD:
            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_WORD:
            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_BYTE:
            case ADD_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_BYTE:

            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_WORD:
            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_WORD:
            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_TO_REG_BYTE:
            case ADC_REG_MEMORY_WITH_REGISTER_TO_EITHER_FROM_REG_BYTE:

            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case SUB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:

            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case SSB_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:

            case CMP_REGISTER_MEMORY_AND_REGISTER_TO_REGISTER_WORD:
            case CMP_REGISTER_MEMORY_AND_REGISTER_FROM_REGISTER_WORD:
            case CMP_REGISTER_MEMORY_AND_REGISTER_TO_REGISTER_BYTE:
            case CMP_REGISTER_MEMORY_AND_REGISTER_FROM_REGISTER_BYTE:

            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case AND_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:

            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case OR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:

            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_WORD:
            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_WORD:
            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_TO_REGISTER_BYTE:
            case XOR_REG_MEMORY_AND_REGISTER_TO_EITHER_FROM_REGISTER_BYTE:
            {
                is_to_reg = IS_TO_REG(inst);
                is_word = IS_WORD_0(inst);
                auto op = GET_OP(inst);
                next_inst();
                ModRegRm tmp;
                tmp.parse1(*this, is_word);
                result = is_to_reg ? op + tmp.A+","+tmp.B : op + tmp.B+","+tmp.A;
            }
                break;
            case MOV_IMMEDIATE_TO_REGISTER_MEMORY_WORD:
            case MOV_IMMEDIATE_TO_REGISTER_MEMORY_BYTE:

            case CMP_IMMEDIATE_WITH_ACCUMULATOR_WORD:
            case CMP_IMMEDIATE_WITH_ACCUMULATOR_BYTE:
            {
                is_word = IS_WORD_0(inst);
                next_inst();
                auto op = GET_OP(inst);
                ModRegRm tmp;
                tmp.parse2(*this, is_word);
                result = op+tmp.A+","+read_as_str(is_word);
            }
                break;
            case MOV_IMMEDIATE_TO_REGISTER_WORD_AX:
            case MOV_IMMEDIATE_TO_REGISTER_WORD_CX:
            case MOV_IMMEDIATE_TO_REGISTER_WORD_DX:
            case MOV_IMMEDIATE_TO_REGISTER_WORD_BX:
            case MOV_IMMEDIATE_TO_REGISTER_WORD_SP:
            case MOV_IMMEDIATE_TO_REGISTER_WORD_BP:
            case MOV_IMMEDIATE_TO_REGISTER_WORD_SI:
            case MOV_IMMEDIATE_TO_REGISTER_WORD_DI:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_AL:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_CL:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_DL:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_BL:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_AH:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_CH:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_DH:
            case MOV_IMMEDIATE_TO_REGISTER_BYTE_BH:
            {
                is_word = IS_WORD_3(inst);
                result = "MOV "+TO_REG(BIT_210(inst), is_word)+","+read_as_str(true);
            }
                break;
            case MOV_MEMORY_TO_ACCUMULATOR_WORD:
            case MOV_MEMORY_TO_ACCUMULATOR_BYTE:
            case MOV_ACCUMULATOR_TO_MEMORY_WORD:
            case MOV_ACCUMULATOR_TO_MEMORY_BYTE:
            {
                bool flag = false;
                if (inst == MOV_MEMORY_TO_ACCUMULATOR_WORD ||
                    inst == MOV_MEMORY_TO_ACCUMULATOR_BYTE)
                    flag = true;
                auto A = ACCU(is_word);
                auto DISP = read_as_str(true);
                DISP = "["+DISP+"]";
                result = flag ? "MOV "+A+","+DISP :"MOV "+DISP+","+A;
            }
                break;
            case MOV_REGISTER_MEMORY_TO_SEGMENT_REGISTER:
            case MOV_SEGMENT_REGISTER_TO_REGISTER_MEMORY:
            {
                bool flag = false;
                if (inst == MOV_REGISTER_MEMORY_TO_SEGMENT_REGISTER)
                    flag = true;
                next_inst();
                ModRegRm tmp;
                tmp.parse3(*this);
                auto A = tmp.A;
                auto B = tmp.B;
                result = flag ? "MOV " + A+","+B : "MOV " + B+","+A;
            }
                break;
            case PUSH_REGISTER_AX:
            case PUSH_REGISTER_CX:
            case PUSH_REGISTER_DX:
            case PUSH_REGISTER_BX:
            case PUSH_REGISTER_SP:
            case PUSH_REGISTER_BP:
            case PUSH_REGISTER_SI:
            case PUSH_REGISTER_DI:

            case POP_REGISTER_AX:
            case POP_REGISTER_CX:
            case POP_REGISTER_DX:
            case POP_REGISTER_BX:
            case POP_REGISTER_SP:
            case POP_REGISTER_BP:
            case POP_REGISTER_SI:
            case POP_REGISTER_DI:

            case INC_REGISTER_AX:
            case INC_REGISTER_CX:
            case INC_REGISTER_DX:
            case INC_REGISTER_BX:
            case INC_REGISTER_SP:
            case INC_REGISTER_BP:
            case INC_REGISTER_SI:
            case INC_REGISTER_DI:

            case DEC_REGISTER_AX:
            case DEC_REGISTER_CX:
            case DEC_REGISTER_DX:
            case DEC_REGISTER_BX:
            case DEC_REGISTER_SP:
            case DEC_REGISTER_BP:
            case DEC_REGISTER_SI:
            case DEC_REGISTER_DI:
            {
                auto op = GET_OP(inst);
                auto reg = TO_REG(BIT_210(inst), true);
                result = op+reg;
            }
                break;
            case PUSH_SEGMENT_REGISTER_ES:
            case PUSH_SEGMENT_REGISTER_CS:
            case PUSH_SEGMENT_REGISTER_SS:
            case PUSH_SEGMENT_REGISTER_DS:

            case POP_SEGMENT_REGISTER_ES:
            case POP_SEGMENT_REGISTER_CS:
            case POP_SEGMENT_REGISTER_SS:
            case POP_SEGMENT_REGISTER_DS:
            {
                auto t = BIT_543(inst);
                auto op = GET_OP(inst);
                assert(t < 4);
                auto sreg = TO_SEG_REG(t);
                result = op+sreg;
            }
                break;
            case POP_REGISTER_MEMORY:
            {
                next_inst();
                ModRegRm tmp;
                tmp.parse2(*this, true);
                auto A = tmp.A;
                result = "POP "+A;
            }
                break;

            case XCHG_REGISTER_MEMORY_WITH_REGISTER_WORD:
            case XCHG_REGISTER_MEMORY_WITH_REGISTER_BYTE:
            {
                is_word = IS_WORD_0(inst);
                next_inst();
                ModRegRm tmp;
                tmp.parse1(*this, is_word);
                result = "XCHG " + tmp.A+","+tmp.B;
            }
                break;
            case XCHG_REGISTER_WITH_ACCUMULATOR_AX:
            case XCHG_REGISTER_WITH_ACCUMULATOR_CX:
            case XCHG_REGISTER_WITH_ACCUMULATOR_DX:
            case XCHG_REGISTER_WITH_ACCUMULATOR_BX:
            case XCHG_REGISTER_WITH_ACCUMULATOR_SP:
            case XCHG_REGISTER_WITH_ACCUMULATOR_BP:
            case XCHG_REGISTER_WITH_ACCUMULATOR_SI:
            case XCHG_REGISTER_WITH_ACCUMULATOR_DI:
            {
                auto reg = TO_REG(BIT_210(inst), true);
                result = "XCHG AX,"+reg;
            }
                break;
            case IN_FIXED_PORT_WORD:
            case IN_FIXED_PORT_BYTE:
            {
                is_word = IS_WORD_0(inst);
                auto acc = ACCU(is_word);
                auto port = read_as_str(false);
                result = "IN "+acc+","+port;
            }
                break;
            case IN_VARIABLE_PORT_WORD:
            case IN_VARIABLE_PORT_BYTE:
            {
                is_word = IS_WORD_0(inst);
                auto acc = ACCU(is_word);
                result = "IN "+acc+","+"DX";
            }
                break;
            case OUT_FIXED_PORT_WORD:
            case OUT_FIXED_PORT_BYTE:
            {
                is_word = IS_WORD_0(inst);
                auto acc = ACCU(is_word);
                auto port = read_as_str(false);
                result = "out "+port+","+acc;
            }
                break;
            case OUT_VARIABLE_PORT_WORD:
            case OUT_VARIABLE_PORT_BYTE:
            {
                if (inst == OUT_VARIABLE_PORT_WORD)
                    is_word = true;
                auto acc = ACCU(is_word);
                result = "OUT DX,"+acc;
            }
                break;
            case LEA:
            case LDS:
            case LES:
            {
                std::string OP = GET_OP(inst);
                ModRegRm tmp;
                auto p_inst = peek_inst();
                assert(BIT_76(p_inst) != 0x00);
                next_inst();
                tmp.parse1(*this, true);
                result = OP + tmp.A+","+tmp.B;
            }
                break;
            case CBW:
            case CWD:
            case AAS:
            case DAS:
            case AAA:
            case BAA:
            case XLAT:
            case LAHF:
            case SAHF:
            case PUSHF:
            case POPF:
            case REP_Z_1:
            case REP_Z_0:
            case MOVS_WORD:
            case MOVS_BYTE:
            case CMPS_WORD:
            case CMPS_BYTE:
            case SCAS_WORD:
            case SCAS_BYTE:
            case LODS_WORD:
            case LODS_BYTE:
            case STOS_WORD:
            case STOS_BYTE:
            {
                result = GET_OP(inst);
            }
                break;
            case ADD_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case ADD_IMMEDIATE_TO_ACCUMULATOR_BYTE:
            case ADC_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case ADC_IMMEDIATE_TO_ACCUMULATOR_BYTE:
            case SUB_IMMEDIATE_FROM_ACCUMULATOR_WORD:
            case SUB_IMMEDIATE_FROM_ACCUMULATOR_BYTE:
            case SSB_IMMEDIATE_FROM_ACCUMULATOR_WORD:
            case SSB_IMMEDIATE_FROM_ACCUMULATOR_BYTE:
            case AND_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case AND_IMMEDIATE_TO_ACCUMULATOR_BYTE:
            case OR_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case OR_IMMEDIATE_TO_ACCUMULATOR_BYTE:
            case XOR_IMMEDIATE_TO_ACCUMULATOR_WORD:
            case XOR_IMMEDIATE_TO_ACCUMULATOR_BYTE:
            {
                is_word = IS_WORD_0(inst);
                auto op = GET_OP(inst);
                auto acc = ACCU(is_word);
                auto DATA = read_as_str(is_word);
                result = op +acc+","+DATA;
            }
                break;
            case AAD:
            case AAM:
            {
                result = GET_OP(inst)+read_as_str(false);
            }
                break;
            case TEST_REGISTER_MEMORY_AND_REGISTER_WORD:
            {/*todo*/}
                break;
            case TEST_REGISTER_MEMORY_AND_REGISTER_BYTE:
            {/*todo*/}
                break;
            case TEST_IMMEDIATE_DATA_AND_ACCUMULATOR_WORD:
            {/*todo*/}
                break;
            case TEST_IMMEDIATE_DATA_AND_ACCUMULATOR_BYTE:
            {/*todo*/}
                break;
            case CALL_DIRECT_WITHIN_SEGMENT:
            {}
                break;
            case CALL_DIRECT_INTERSEGMENT:
            {}
                break;
            case JMP_DIRECT_WITHIN_SEGMENT:
            {}
                break;
            case JMP_DIRECT_WITHIN_SEGMENT_SHORT:
            {}
                break;
            case JMP_DIRECT_INTERSEGMENT:
            {}
                break;
            case RET_WITHIN_SEGMENT:
            {}
                break;
            case RET_WITHIN_SEG_ADDING_IMMED_TO_SP:
            {}
                break;
            case RET_INTERSEGMENT:
            {}
                break;
            case RET_INTERSEGMENT_ADDING_IMMEDIATE_TO_SP:
            {}
                break;
            case JE_JZ:
            {}
                break;
            case JL_JNGE:
            {}
                break;
            case JLE_JNG:
            {}
                break;
            case JB_JNAE:
            {}
                break;
            case JBE_JNA:
            {}
                break;
            case JP_JNE:
            {}
                break;
            case JO:
            {}
                break;
            case JS:
            {}
                break;
            case JNE_JNZ:
            {}
                break;
            case JNL_JGE:
            {}
                break;
            case JNLE_JG:
            {}
                break;
            case JNB_JAE:
            {}
                break;
            case JNBE_JA:
            {}
                break;
            case JNP_JPO:
            {}
                break;
            case JNO:
            {}
                break;
            case JNS:
            {}
                break;
            case LOOP:
            {}
                break;
            case LOOPZ_LOOPE:
            {}
                break;
            case LOOPNZ_LOOPNE:
            {}
                break;
            case JCXZ:
            {}
                break;
            case INT_TYPE_SPEC:
            {}
                break;
            case INT_TYPE_3:
            {}
                break;
            case INTO:
            {}
                break;
            case IRET:
            {}
                break;
            case CLC:
            {}
                break;
            case CMC:
            {}
                break;
            case STC:
            {}
                break;
            case CLD:
            {}
                break;
            case STD:
            {}
                break;
            case CLI:
            {}
                break;
            case STI:
            {}
                break;
            case HLT:
            {}
                break;
            case WAIT:
            {}
                break;
            case ESC_0:
            {}
                break;
            case ESC_1:
            {}
                break;
            case ESC_2:
            {}
                break;
            case ESC_3:
            {}
                break;
            case ESC_4:
            {}
                break;
            case ESC_5:
            {}
                break;
            case ESC_6:
            {}
                break;
            case ESC_7:
            {}
                break;
            case LOCK:
            {}
                break;
            case 0x80:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x04:  // case AND_IMMEDIATE_TO_REGISTER_MEMORY_BYTE(3)
                    {

                    }
                        break;
                    case 0x01:  // case OR_IMMEDIATE_TO_REGISTER_MEMORY_BYTE(3)
                    {

                    }
                        break;
                    case 0x06:  // case XOR_IMMEDIATE_TO_REGISTER_MEMORY_BYTE(3)
                    {

                    }
                        break;
                }
            }
                break;
            case 0x81:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x00:  // case ADD_IMMEDIATE_TO_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    case 0x02:  // case ADC_IMMEDIATE_TO_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    case 0x05:  // case SUB_IMMEDIATE_FROM_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    case 0x03:  // case SSB_IMMEDIATE_FROM_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    case 0x07:  // case CMP_IMMEDIATE_WITH_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    case 0x04:  // case AND_IMMEDIATE_TO_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    case 0x01:  // case OR_IMMEDIATE_TO_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    case 0x06:  // case XOR_IMMEDIATE_TO_REGISTER_MEMORY_WORD(4)
                    {}
                        break;
                    default:
                        assert(false);
                }

            }
                break;
            case 0x83:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x00:  // case ADD_IMMEDIATE_TO_REGISTER_MEMORY_BYTE(3)
                    {}
                        break;
                    case 0x02:  // case ADC_IMMEDIATE_TO_REGISTER_MEMORY_BYTE(3)
                    {}
                        break;
                    case 0x05:  // case SUB_IMMEDIATE_FROM_REGISTER_MEMORY_BYTE(3)
                    {}
                        break;
                    case 0x03:  // case SSB_IMMEDIATE_FROM_REGISTER_MEMORY_BYTE(3)
                    {}
                        break;
                    case 0x07:  // case CMP_IMMEDIATE_WITH_REGISTER_MEMORY_BYTE(3)
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xD0:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x04:  // case SHL_SAL_COUNT_1_BYTE(2)
                    {}
                        break;
                    case 0x05:  // case SHR_COUNT_1_BYTE(2)
                    {}
                        break;
                    case 0x07:  // case SAR_COUNT_1_BYTE(2)
                    {}
                        break;
                    case 0x00:  // case ROL_COUNT_1_BYTE(2)
                    {}
                        break;
                    case 0x01:  // case ROR_COUNT_1_BYTE(2)
                    {}
                        break;
                    case 0x02:  // case RCL_COUNT_1_BYTE(2)
                    {}
                        break;
                    case 0x03:  // case RCR_COUNT_1_BYTE(2)
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xD1:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x04:  // case SHL_SAL_COUNT_1_WORD(2)
                    {}
                        break;
                    case 0x05:  // case SHR_COUNT_1_WORD(2)
                    {}
                        break;
                    case 0x07:  // case SAR_COUNT_1_WORD(2)
                    {}
                        break;
                    case 0x00:  // case ROL_COUNT_1_WORD(2)
                    {}
                        break;
                    case 0x01:  // case ROR_COUNT_1_WORD(2)
                    {}
                        break;
                    case 0x02:  // case RCL_COUNT_1_WORD(2)
                    {}
                        break;
                    case 0x03:  // case RCR_COUNT_1_WORD(2)
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xD2:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x04:  // case SHL_SAL_COUNT_AL_BYTE(2)
                    {}
                        break;
                    case 0x05:  // case SHR_COUNT_AL_BYTE(2)
                    {}
                        break;
                    case 0x07:  // case SAR_COUNT_AL_BYTE(2)
                    {}
                        break;
                    case 0x00:  // case ROL_COUNT_AL_BYTE(2)
                    {}
                        break;
                    case 0x01:  // case ROR_COUNT_AL_BYTE(2)
                    {}
                        break;
                    case 0x02:  // case RCL_COUNT_AL_BYTE(2)
                    {}
                        break;
                    case 0x03:  // case RCR_COUNT_AL_BYTE(2)
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xD3:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x04:  // case SHL_SAL_COUNT_AL_WORD(2)
                    {}
                        break;
                    case 0x05:  // case SHR_COUNT_AL_WORD(2)
                    {}
                        break;
                    case 0x07:  // case SAR_COUNT_AL_WORD(2)
                    {}
                        break;
                    case 0x00:  // case ROL_COUNT_AL_WORD(2)
                    {}
                        break;
                    case 0x01:  // case ROR_COUNT_AL_WORD(2)
                    {}
                        break;
                    case 0x02:  // case RCL_COUNT_AL_WORD(2)
                    {}
                        break;
                    case 0x03:  // case RCR_COUNT_AL_WORD(2)
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xF6:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x03:  // case NEG_BYTE(2)
                    {}
                        break;
                    case 0x04:  // case MUL_BYTE(2)
                    {}
                        break;
                    case 0x05:  // case IMUL_BYTE(2)
                    {}
                        break;
                    case 0x06:  // case DIV_BYTE(2)
                    {}
                        break;
                    case 0x07:  // case IDIV_BYTE(2)
                    {}
                        break;
                    case 0x02:  // case NOT_BYTE(2)
                    {}
                        break;
                    case 0x00:  // case TEST_IMMEDIATE_DATA_AND_REGISTER_MEMORY_BYTE(3) /*todo*/
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xF7:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x03:  // case NEG_WORD(2)
                    {}
                        break;
                    case 0x04:  // case MUL_WORD(2)
                    {}
                        break;
                    case 0x05:  // case IMUL_WORD(2)
                    {}
                        break;
                    case 0x06:  // case DIV_WORD(2)
                    {}
                        break;
                    case 0x07:  // case IDIV_WORD(2)
                    {}
                        break;
                    case 0x02:  // case NOT_WORD(2)
                    {}
                        break;
                    case 0x00:  // case TEST_IMMEDIATE_DATA_AND_REGISTER_MEMORY_WORD(4) /*todo*/
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xFE:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x00:  // case INC_REGISTER_MEMORY_BYTE(2)
                    {}
                        break;
                    case 0x01:  // case DEC_REGISTER_MEMORY_BYTE(2)
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            case 0xFF:
            {
                next_inst();
                inst = cur_inst();
                BYTE bit543 = BIT_543(inst);
                switch (bit543)
                {
                    case 0x06:  // case PUSH_REGISTER_MEMORY(2)
                    {
                        ModRegRm tmp;
                        tmp.parse2(*this, true);
                        auto A = tmp.A;
                        return "PUSH "+A;
                    }
                        break;
                    case 0x00:  // case INC_REGISTER_MEMORY_WORD(2)
                    {}
                        break;
                    case 0x01:  // case DEC_REGISTER_MEMORY_WORD(2)
                    {}
                        break;
                    case 0x02:  // case CALL_INDIRECT_WITHIN_SEGMENT(2)
                    {}
                        break;
                    case 0x03:  // case CALL_INDIRECT_INTERSEGMENT(2)
                    {}
                        break;
                    case 0x04:  // case JMP_INDIRECT_WITHIN_SEGMENT(2)
                    {}
                        break;
                    case 0x05:  // case JMP_INDIRECT_INTERSEGMENT(2)
                    {}
                        break;
                    default:
                        assert(false);
                }
            }
                break;
            default:
                assert(false);
        }
        next_inst();
        return result;
    }
}