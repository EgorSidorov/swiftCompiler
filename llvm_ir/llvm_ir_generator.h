#ifndef LLVM_IR_GENERATOR_H
#define LLVM_IR_GENERATOR_H


#include <llvm_ir_types.h>
#include "list"
#include "stack"
#include "vector"

class llvm_ir_generator
{
    private:
    llvm_ir_generator();
public:
    static llvm_ir_generator* getGenerator( ){
        static llvm_ir_generator instance;
        return &instance;
    }
    std::string getProgram();

    bool AddVariable(std::string t_name, value_t_type t_type);
    bool CallFunction(std::string func_name, std::vector<std::string> args_input, value_t_type &return_value_type);
    bool InitializeVariable(std::string t_name);
    bool InitializeVariable(std::string t_name, std::string value);
    bool OperationVariable(value_op_type,value_t_type&,std::string variable1, std::string variable2);
    void lifetime_string_start(std::string vartiable);
    std::string lastVariable();

    bool printf(std::string value);
    void end_all_lifetimes();
    void lifetime_string_end(std::string variable);
    void InitializeStringConst(std::string t_name, std::string value);
    value_t_type get_type_var(std::string value);

    std::string beginIF(std::string var1, std::string var2, std::string op);
    void endIF(std::string begin_if_label);
    void endWHILE(std::string begin_if_label, std::string variable1, std::string variable2, std::string op);
    std::string beginWHILE();
    void beginAddFunction(std::string name, value_t_type return_type, std::vector<value_t> input_values);
    void addProgram(std::string value);
    void endAddFunction();
    void AddReturn(value_t_type type, std::string value);
    std::list<value_t*> GetValues();
    std::string result_operation;
    bool AddMass(std::string t_name, value_t_type t_type, int count);
    bool InitMass(std::string t_name, std::string number, std::string value);
    std::string GetMassElem(std::string t_name, std::string number, value_t_type &outputttype);
    void AddClass(std::string name);
    void AddObject(std::string objectname, std::string classname);
    void CallMethod(std::string objectname, std::string methodname, bool hasarg, std::string arg1);
    bool hasadded = false;
    void addll();
private:
    std::string program;
    std::list<function_t> functions;
    std::list<value_t> values_lifetime;
    std::vector<std::list<value_t>> values_stack;
    std::vector<std::list<value_t>> copy_values_stack;
    int lastNumber = 1;
    bool addMain;
    int numberSymbolAdd;
    std::list<value_t> objectvalues;
    std::list<std::string> classvalues;
    std::list<std::string> classvaluess;
};

#endif // LLVM_IR_GENERATOR_H
