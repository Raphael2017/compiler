#include "moon_parser.h"
#include "syntax_tree.h"
#include "symbol.h"
#include "frame.h"
#include "type_info.h"
#include "translate.h"
#include <fstream>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

std::string readFileContents(const std::string& file_path)
{
    std::ifstream t(file_path);
    std::string text((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    return text;
}


int main() {
    char *out = nullptr;
    long int cc = strtol("12", &out, 0);
    int aaaa = sizeof(void*);

    ParseResult result;
    std::string moon_script = readFileContents("/home/qwerty/github/compiler/script.moon");
    moon_parser::parse_moon(moon_script, &result);
    SyntaxMoonStmtsList *stmts = result.moon_stmts_list_;
    if (result.accept == false || !stmts)
    {
        printf(result.errDetail.c_str());
        return -1;
    }

    translate(stmts);
    return 0;
}


