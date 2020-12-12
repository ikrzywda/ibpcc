#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Token.hpp"

namespace lxr{

int is_upcase();

class Lexer{
    private:
        std::string *input_buffer;
        std::string *attr_buffer;
        std::string noattr = "0";
        int pos, len;
        char c;
        void error();
        void advance();
        void skip_whitespace();
        void skip_comment();
        tk::Token *number();
        tk::Token *id();
        tk::Token *string();
        tk::Token *op_eq(char ch);
    public:
        Lexer(std::string *buffer);
        unsigned int line_num;
        tk::Token *get_next_token();
};

}

#endif
