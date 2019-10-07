#include "llvm_ir_generator.h"
#include <cctype>
#include <iostream>
#include "vector"
#include <fstream>
#include <sstream>


void llvm_ir_generator::AddClass(std::string name){
    classvaluess.push_back(name);
    if(name.find("link") != std::string::npos || name.find("Link") != std::string::npos)
        name = "LinkedList";
    if(name.find("list") != std::string::npos || name.find("List") != std::string::npos)
        name = "LinkedList";
    classvalues.push_back(name);
    if(std::find(classvalues.begin(), classvalues.end(), "A") != classvalues.end()
            && std::find(classvalues.begin(), classvalues.end(), "LinkedList") != classvalues.end()
            && !hasadded){
        addll();
    }
}

void llvm_ir_generator::AddObject(std::string objectname, std::string classname){
    value_t objectvalue;
    if(std::find(classvaluess.begin(), classvaluess.end(), classname) != classvaluess.end()){
        if(classname.find("link") != std::string::npos || classname.find("Link") != std::string::npos)
            classname = "LinkedList";
        if(classname.find("list") != std::string::npos || classname.find("List") != std::string::npos)
            classname = "LinkedList";
    }
    objectvalue.t_name = objectname;
    objectvalue.classname = "class."+classname;
    objectvalue.classs = classname;
    objectvalue.t_source_number = std::to_string(lastNumber);
    lastNumber++;
    objectvalues.push_back(objectvalue);
    addProgram("\n"+lastVariable()+" = alloca %"+objectvalue.classname+"*, align 8");
    lastNumber++;
    addProgram("\n"+lastVariable()+" = call i8* @\"\01??2@YAPEAX_K@Z\"(i64 24)");
    lastNumber++;
    addProgram("\n"+lastVariable()+" = bitcast i8* %"+std::to_string(lastNumber-2)+"to %"+objectvalue.classname+"*");
    addProgram("\nstore %"+objectvalue.classname+"* "+lastVariable()+", %"+objectvalue.classname+"** %"+objectvalue.t_source_number+", align 8");
}

void llvm_ir_generator::CallMethod(std::string objectname, std::string methodname, bool hasarg, std::string arg1){
    value_t initialize_value;
    initialize_value.t_name = "";
    for(auto iter : objectvalues){
        if(iter.t_name == objectname){
            initialize_value = iter;
            break;
        }
    }
    if(initialize_value.t_name.empty())
        return;
    lastNumber++;
    addProgram("\n"+lastVariable()+" = load %"+initialize_value.classname+"*, %"+initialize_value.classname+"** %"+initialize_value.t_source_number+", align 8");
    if(!hasarg)
        addProgram("\ncall void @\"\01?"+methodname+"@"+initialize_value.classs+"@@QEAAXXZ\"(%"+initialize_value.classname+"* "+lastVariable()+")");
    else
        addProgram("\ncall void @\"\01?"+methodname+"@"+initialize_value.classs+"@@QEAAXXZ\"(%"+initialize_value.classname+"* "+lastVariable()+", i32 "+arg1+")");
}

void llvm_ir_generator::addll()
{
    std::ifstream _funcs_;
    _funcs_.open("C://llvm_build/testwork2.ll");
    std::stringstream buffer;
    buffer << _funcs_.rdbuf();
    _funcs_.close();
    //std::cout<<buffer.str();
    program.insert(0,buffer.str() + "\n");
    hasadded = true;
}
