#ifndef MVM_MVM_H
#define MVM_MVM_H

#include <vector>
#include <string>

#define MEM_SIZE 1<<20

namespace moon_vm
{
    typedef unsigned char BYTE;
    typedef unsigned short WORD;
    typedef BYTE INST;
    struct vm
    {
        void translate(std::vector<std::string> outs)
        {
            do
            {
                outs.push_back(translate_one());
            } while (1);
        }
        std::string translate_one();
        INST cur_inst() { return *(memory_+(16*CS_+IP_));}
        INST peek_inst() { return *(memory_+(16*CS_+IP_+1)); }
        void next_inst() { IP_++; }  //ip move 1

        BYTE memory_[MEM_SIZE]{0};
        WORD CS_{0};
        WORD IP_{0};

    private:
        std::string read_as_str(bool is_word);
        friend struct ModRegRm;
    };
}

#endif