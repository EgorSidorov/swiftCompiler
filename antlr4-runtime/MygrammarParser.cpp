
// Generated from Mygrammar.g4 by ANTLR 4.7.2


#include "MygrammarVisitor.h"

#include "MygrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

MygrammarParser::MygrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MygrammarParser::~MygrammarParser() {
  delete _interpreter;
}

std::string MygrammarParser::getGrammarFileName() const {
  return "Mygrammar.g4";
}

const std::vector<std::string>& MygrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MygrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompileUnitContext ------------------------------------------------------------------

MygrammarParser::CompileUnitContext::CompileUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MygrammarParser::ExprContext* MygrammarParser::CompileUnitContext::expr() {
  return getRuleContext<MygrammarParser::ExprContext>(0);
}

tree::TerminalNode* MygrammarParser::CompileUnitContext::EOF() {
  return getToken(MygrammarParser::EOF, 0);
}


size_t MygrammarParser::CompileUnitContext::getRuleIndex() const {
  return MygrammarParser::RuleCompileUnit;
}


antlrcpp::Any MygrammarParser::CompileUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MygrammarVisitor*>(visitor))
    return parserVisitor->visitCompileUnit(this);
  else
    return visitor->visitChildren(this);
}

MygrammarParser::CompileUnitContext* MygrammarParser::compileUnit() {
  CompileUnitContext *_localctx = _tracker.createInstance<CompileUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, MygrammarParser::RuleCompileUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    expr();
    setState(9);
    match(MygrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MygrammarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MygrammarParser::TermContext *> MygrammarParser::ExprContext::term() {
  return getRuleContexts<MygrammarParser::TermContext>();
}

MygrammarParser::TermContext* MygrammarParser::ExprContext::term(size_t i) {
  return getRuleContext<MygrammarParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> MygrammarParser::ExprContext::PLUS() {
  return getTokens(MygrammarParser::PLUS);
}

tree::TerminalNode* MygrammarParser::ExprContext::PLUS(size_t i) {
  return getToken(MygrammarParser::PLUS, i);
}

std::vector<tree::TerminalNode *> MygrammarParser::ExprContext::MINUS() {
  return getTokens(MygrammarParser::MINUS);
}

tree::TerminalNode* MygrammarParser::ExprContext::MINUS(size_t i) {
  return getToken(MygrammarParser::MINUS, i);
}


size_t MygrammarParser::ExprContext::getRuleIndex() const {
  return MygrammarParser::RuleExpr;
}


antlrcpp::Any MygrammarParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MygrammarVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

MygrammarParser::ExprContext* MygrammarParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, MygrammarParser::RuleExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11);
    term();
    setState(16);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MygrammarParser::PLUS

    || _la == MygrammarParser::MINUS) {
      setState(12);
      _la = _input->LA(1);
      if (!(_la == MygrammarParser::PLUS

      || _la == MygrammarParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(13);
      term();
      setState(18);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

MygrammarParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MygrammarParser::FactorContext *> MygrammarParser::TermContext::factor() {
  return getRuleContexts<MygrammarParser::FactorContext>();
}

MygrammarParser::FactorContext* MygrammarParser::TermContext::factor(size_t i) {
  return getRuleContext<MygrammarParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> MygrammarParser::TermContext::MULT() {
  return getTokens(MygrammarParser::MULT);
}

tree::TerminalNode* MygrammarParser::TermContext::MULT(size_t i) {
  return getToken(MygrammarParser::MULT, i);
}

std::vector<tree::TerminalNode *> MygrammarParser::TermContext::DIV() {
  return getTokens(MygrammarParser::DIV);
}

tree::TerminalNode* MygrammarParser::TermContext::DIV(size_t i) {
  return getToken(MygrammarParser::DIV, i);
}


size_t MygrammarParser::TermContext::getRuleIndex() const {
  return MygrammarParser::RuleTerm;
}


antlrcpp::Any MygrammarParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MygrammarVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

MygrammarParser::TermContext* MygrammarParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 4, MygrammarParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19);
    factor();
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MygrammarParser::MULT

    || _la == MygrammarParser::DIV) {
      setState(20);
      _la = _input->LA(1);
      if (!(_la == MygrammarParser::MULT

      || _la == MygrammarParser::DIV)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(21);
      factor();
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

MygrammarParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MygrammarParser::FactorContext::NUMBER() {
  return getToken(MygrammarParser::NUMBER, 0);
}


size_t MygrammarParser::FactorContext::getRuleIndex() const {
  return MygrammarParser::RuleFactor;
}


antlrcpp::Any MygrammarParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MygrammarVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

MygrammarParser::FactorContext* MygrammarParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 6, MygrammarParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    match(MygrammarParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> MygrammarParser::_decisionToDFA;
atn::PredictionContextCache MygrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MygrammarParser::_atn;
std::vector<uint16_t> MygrammarParser::_serializedATN;

std::vector<std::string> MygrammarParser::_ruleNames = {
  "compileUnit", "expr", "term", "factor"
};

std::vector<std::string> MygrammarParser::_literalNames = {
  "", "'+'", "'-'", "'*'", "'/'"
};

std::vector<std::string> MygrammarParser::_symbolicNames = {
  "", "PLUS", "MINUS", "MULT", "DIV", "COMMENT", "INT", "DOUBLE", "ID", 
  "WS", "NUMBER"
};

dfa::Vocabulary MygrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MygrammarParser::_tokenNames;

MygrammarParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xc, 0x20, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x11, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x14, 0xb, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x19, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x1c, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 
    0x2, 0x4, 0x6, 0x8, 0x2, 0x4, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 
    0x2, 0x1d, 0x2, 0xa, 0x3, 0x2, 0x2, 0x2, 0x4, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 
    0x5, 0x4, 0x3, 0x2, 0xb, 0xc, 0x7, 0x2, 0x2, 0x3, 0xc, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0xd, 0x12, 0x5, 0x6, 0x4, 0x2, 0xe, 0xf, 0x9, 0x2, 0x2, 0x2, 
    0xf, 0x11, 0x5, 0x6, 0x4, 0x2, 0x10, 0xe, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x12, 0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x13, 0x5, 0x3, 0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 
    0x2, 0x2, 0x2, 0x15, 0x1a, 0x5, 0x8, 0x5, 0x2, 0x16, 0x17, 0x9, 0x3, 
    0x2, 0x2, 0x17, 0x19, 0x5, 0x8, 0x5, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0xc, 0x2, 0x2, 0x1e, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x12, 0x1a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MygrammarParser::Initializer MygrammarParser::_init;
