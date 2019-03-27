#ifndef MOON_PARSER
#define MOON_PARSER

#include <string>
#include <vector>
struct ParseResult;
namespace moon_parser
{
    bool parse_moon(const std::string& sql, ParseResult* result);
    bool tokenize(const std::string& sql, std::vector<int16_t>* tokens);
}

#endif