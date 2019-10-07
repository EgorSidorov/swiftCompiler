#include <iostream>
#include <fstream>
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/MygrammarLexer.h"
#include "antlr4-runtime/SceneLexer.h"
#include "antlr4-runtime/SceneListener.h"
#include "llvm_ir_generator.h"
#include "expression.h"

using namespace std;
using namespace antlr4;

class MyErrorListener : public ANTLRErrorListener{

public:
    virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine, const string &msg, exception_ptr e) override{
        if(msg.find("extraneous") != -1){
            cout<<msg;
            exit(1);
        }
    }

    // ANTLRErrorListener interface
public:
    virtual void reportAmbiguity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact, const antlrcpp::BitSet &ambigAlts, atn::ATNConfigSet *configs) override{}
    virtual void reportAttemptingFullContext(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, const antlrcpp::BitSet &conflictingAlts, atn::ATNConfigSet *configs) override{}
    virtual void reportContextSensitivity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, size_t prediction, atn::ATNConfigSet *configs) override{}
};

int main(int argc, const char* argv[]) {
    //ANTLRInputStream input("/*var b:Int=3+3*(3/3+3);*/"
                           /*"var b:Double=3.0+3.0*6.0-7.0/7.1;"
                           "b=3.0+3.0*6.0;"
                           "b=3.0+3.0*(3.0/3.1+3.0)\n"
                           "var c:Double=4.0*b;"
                           "var d = 3 * mas[5]\n"
                           "var ii = 12\n"
                           "var k = Double(d) * 3.1\n"
                           "var str = \"MyString\"\n"
                           "while d>ii{"
                           "ii=ii+1;"
                           "print(ii);};"
                           "print(b,c,d,k)\n");*/
    /*ANTLRInputStream input(
                           //"var masselem = test[2];         "
                            "var i1=1+3+2+1*(10+5-3*2);     "
                           "var i2=7;                       "
                           "var i3=4;                       "
                           "var i4=11;                      "
                           //"var buff=0;                   "
                           "var iterbegin=0;                "
                           "var iterend=3;                  "
                           "while iterbegin<iterend{        "
                           "    if i1<i2{                   "
                           "        var buff=i1;            "
                           "        i1=i2;                  "
                           "        i2=buff;};              "
                           "    if i2<i3{                   "
                           "        var buff=i2;            "
                           "        i2=i3;                  "
                           "        i3=buff;};              "
                           "    if i3<i4{                   "
                           "        var buff=i3;            "
                           "        i3=i4;                  "
                           "        i4=buff;};              "
                           "    iterbegin = iterbegin+1;    "
                           "};                              "
                           "var i1double=Double(i1);        "
                           "var i1=Int(i1double);           "
                           "print(i1,i2,i3,i4);             "
                           "var test=[1,2,3];               "
                            "test[0] = 4;                   "
                            "var massivel:Int = test[0];"
                           "print(massivel);    "
                );*/
    /*std::string start_program = "var test=[8.1,-11.1,-11.9,6.1,18.1]\n     "
            "var buff:Int = test[0];"
            "buff = 0-buff;"
            "test[0]=buff;"
            "buff = test[1];"
            "buff = 0-buff;"
            "test[1]=buff;"
           "test[0] = test[0];"
           "var iterbegin=0\n                "
           "var iterend=5\n                  "
           "while iterbegin<iterend{        "
            "var iterbegin2=1;                                  "
            "while iterbegin2<iterend{        "
            "var massivellast:Double = test[iterbegin2-1]\n"
            "var massivelcurrent:Double = test[iterbegin2]\n"
            "if massivellast<massivelcurrent{"
            "test[iterbegin2-1] = massivelcurrent\n"
            "test[iterbegin2] = massivellast\n"
            "}\n"
            //"print(massivellast);"
             "    iterbegin2 = iterbegin2+1\n    "
            "}\n                              "
            "    iterbegin = iterbegin+1\n    "
             "}\n                              "
            "iterbegin=0\n"
            "while iterbegin<iterend{        "
            "var massivelcurrent:Double = test[iterbegin]\n"
            "print(massivelcurrent)\n"
             "    iterbegin = iterbegin+1\n    "
              "}\n                              "
            "class A{"
             "var haslast = 0;"
            "var hasnext = 0;"
            "var value = 0;"
            "var next : A?;"
            "var last : A?;"
            "func somefunc(){var a = 2;};"
            "func somefunc2(_ value : Int){var a = 2;};"
             "};";*/
    ifstream start_program;
    //start_program.open("C://llvm_build/bubblesortdouble.swift");
    start_program.open("C://llvm_build/bubblesortint.swift");
    //start_program.open("C://llvm_build/linkedlist.swift");
    ANTLRInputStream input(start_program);
    SceneLexer lexer(&input);
    //lexer.skip();
    CommonTokenStream tokens(&lexer);
    SceneParser parser(&tokens);
    MyErrorListener errorlistener;
    parser.addErrorListener(&errorlistener);
    SceneParser::ProgramContext* tree = parser.program();
    cout<<"begin\n"<<tree->getText()<<"\n";
    for(auto expr : tree->expression()){
        parse_expr(expr);
    }
    ofstream myfile;
    myfile.open ("C://llvm_build/test.ll");
    myfile << llvm_ir_generator::getGenerator()->getProgram();
    myfile.close();
    //myfile.open ("C://llvm_build/startprogram.swift");
    //myfile << start_program;
    //myfile.close();
    //cout << generator.getProgram();
    return 0;
}
