
// Generated from Scene.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SceneLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, PLUS = 2, MINUS = 3, MULT = 4, DIV = 5, LEFT_BRACKET = 6, 
    RIGHT_BRACKET = 7, EQUI = 8, COMMENT = 9, DOUBLE = 10, INT = 11, END_EXPR = 12, 
    INIT = 13, TYPE = 14, INIT_TYPE = 15, ID = 16, CHAR = 17, STRING = 18, 
    FOR_LOOP = 19, WHITESPACE = 20, NUMBER = 21
  };

  SceneLexer(antlr4::CharStream *input);
  ~SceneLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

