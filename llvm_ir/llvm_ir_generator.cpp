#include "llvm_ir_generator.h"
#include <cctype>
#include <iostream>
#include "vector"
llvm_ir_generator::llvm_ir_generator()
{
    addMain = true;
    values_stack.push_back(std::list<value_t>());
    program = "";
    program.append("@.strdouble = private unnamed_addr constant [5 x i8] c\"%lf\\0A\\00\", align 1\n"
            "@.strint = private unnamed_addr constant [4 x i8] c\"%d\\0A\\00\", align 1\n"
            "@.str = private unnamed_addr constant [4 x i8] c\"%s\\0A\\00\", align 1\n"

            "define i32 @printdouble(double %value) {\n"
            "entry:\n"
            "  call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.strdouble, i64 0, i64 0), double %value)\n"
            "  ret i32 0\n"
            "}\n"

            "define i32 @printint(i32 %value) {\n"
            "entry:\n"
            "  call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.strint, i64 0, i64 0), i32 %value)\n"
            "  ret i32 0\n"
            "}\n"

            "declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #1\n"
            "declare i32 @puts(i8*)\n"

            "define i32 @main() local_unnamed_addr {\n");
    //add function cast to int
    std::vector<value_t> args_int;
    value_t arg_int;
    arg_int.t_name = "value";
    arg_int.t_source_number = "value";
    arg_int.t_type = value_t_type::DOUBLE;
    args_int.push_back(arg_int);
    beginAddFunction("Int",value_t_type::INT,args_int);
    addProgram("\n%0 = fptosi double %value to i32\n"
               "ret i32 %0");
    endAddFunction();

    //add function cast to double
    std::vector<value_t> args_double;
    value_t arg_double;
    arg_double.t_name = "value";
    arg_double.t_source_number = "value";
    arg_double.t_type = value_t_type::INT;
    args_double.push_back(arg_double);
    beginAddFunction("Double",value_t_type::DOUBLE,args_double);
    addProgram("\n%0 = sitofp i32 %value to double\n"
               "ret double %0");
    endAddFunction();
}

std::string llvm_ir_generator::getProgram()
{
    std::string return_program = program;
    return_program.append(" \n ret i32 0 \n }");
    return return_program;
}

void llvm_ir_generator::addProgram(std::string value)
{
    if(addMain)
        program.append(value);
    else{
        program.insert(numberSymbolAdd,value);
        numberSymbolAdd+=value.length();
    }

}
