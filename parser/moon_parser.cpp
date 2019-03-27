#include "moon_parser.h"
#include "moon_parser_bison.h"
#include "moon_parser_flex.h"

namespace moon_parser {
    bool parse_moon(const std::string& sql, ParseResult* result)
    {
        yyscan_t scanner;
        YY_BUFFER_STATE state;

        if (yylex_init_extra(result, &scanner)) {
            //fprintf(stderr, "SQLParser2003: Error when initializing lexer!\n");
            return false;
        }

        const char* text = sql.c_str();
        state = yy_scan_string(text, scanner);

        // Parse the tokens.
        // If parsing fails, the result will contain an error object.
        yyparse(result, scanner);
        yy_delete_buffer(state, scanner);
        yylex_destroy(scanner);

        return result->accept;
    }

    bool tokenize(const std::string& sql, std::vector<int16_t>* tokens) {
        // Initialize the scanner.
        yyscan_t scanner;
        if (yylex_init(&scanner)) {
            fprintf(stderr, "SQLParser: Error when initializing lexer!\n");
            return false;
        }

        YY_BUFFER_STATE state;
        state = yy_scan_string(sql.c_str(), scanner);

        YYSTYPE yylval;
        YYLTYPE yylloc;

        // Step through the string until EOF is read.
        // Note: hsql_lex returns int, but we know that its range is within 16 bit.
        int16_t token = yylex(&yylval, &yylloc, scanner);
        while (token != END_P) {
            tokens->push_back(token);
            token = yylex(&yylval, &yylloc, scanner);
        }

        yy_delete_buffer(state, scanner);
        yylex_destroy(scanner);
        return true;
    }
}
