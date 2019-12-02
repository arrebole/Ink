//词法分析，字符流 -> 记号流
#pragma one
#include <stdbool.h>

// TokenType 词法类型(整形、加法)
enum TokenType{
    ADD, SUB, INT
};

//Token 记号
struct Token{
    enum TokenType type;
    char* value;
};

//TokenSteam 记号流数组
struct TokenSteam{
    int size;
    int capacity;
    struct Token* data;
};

// isOperators 判断字符是否是运算符
bool isOperators(char ch);
// isInt 判断字符是否是整数
bool isInt(char ch);

// lexInt 整形字符转换为记号
struct Token lexInt(char* ch, int size);
// lexOperators 运算字符转换为记号
struct Token lexOperators(char ch);

// lex 词法分析；字符流 -> 记号流
struct TokenSteam lex(char* code, int len);
// push 往记号流中添加标记
struct TokenSteam* push(struct TokenSteam *tokenSteam, struct Token token);


