#ifndef COMPILER_TEMP_H
#define COMPILER_TEMP_H

#include "utils.h"

/*
 * functions to create and manipulate temporary variables which are
 * used in the IR tree representation before it has been determined
 * which variables are to go into registers
 **/

namespace compiler
{
    struct Symbol;
    typedef Symbol* Temp_label;
}



#endif