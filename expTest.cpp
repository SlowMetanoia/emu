#include <exprtk.hpp>
#include <string>
#include <cstdio>
#include <QDebug>

template <typename T>
void testExp(){
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>   expression_t;
    typedef exprtk::parser<T>       parser_t;

    const std::string expression_string =
                      "clamp(-1.0,sin(2 * pi * x) + cos(x / 2 * pi),+1.0";

    T x;

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);
    bool isValid = exprtk::is_valid<T>(expression);
    //qDebug()<<isValid;
    for (x = T(-5); x <= T(+5); x += T(0.001))
    {
       const T y = expression.value();
       //qDebug()<<"x ="<<x<<"y ="<<y;
       printf("%19.15f\t%19.15f\n", x, y);
    }
}
