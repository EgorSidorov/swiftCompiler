
// Generated from modelica.g4 by ANTLR 4.7.2


#include "modelicaVisitor.h"

#include "modelicaParser.h"


using namespace antlrcpp;
using namespace antlr4;

modelicaParser::modelicaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

modelicaParser::~modelicaParser() {
  delete _interpreter;
}

std::string modelicaParser::getGrammarFileName() const {
  return "modelica.g4";
}

const std::vector<std::string>& modelicaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& modelicaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompileUnitContext ------------------------------------------------------------------

modelicaParser::CompileUnitContext::CompileUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::ExprContext* modelicaParser::CompileUnitContext::expr() {
  return getRuleContext<modelicaParser::ExprContext>(0);
}

tree::TerminalNode* modelicaParser::CompileUnitContext::EOF() {
  return getToken(modelicaParser::EOF, 0);
}


size_t modelicaParser::CompileUnitContext::getRuleIndex() const {
  return modelicaParser::RuleCompileUnit;
}


antlrcpp::Any modelicaParser::CompileUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitCompileUnit(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::CompileUnitContext* modelicaParser::compileUnit() {
  CompileUnitContext *_localctx = _tracker.createInstance<CompileUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, modelicaParser::RuleCompileUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    expr();
    setState(9);
    match(modelicaParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

modelicaParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::TermContext *> modelicaParser::ExprContext::term() {
  return getRuleContexts<modelicaParser::TermContext>();
}

modelicaParser::TermContext* modelicaParser::ExprContext::term(size_t i) {
  return getRuleContext<modelicaParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> modelicaParser::ExprContext::PLUS() {
  return getTokens(modelicaParser::PLUS);
}

tree::TerminalNode* modelicaParser::ExprContext::PLUS(size_t i) {
  return getToken(modelicaParser::PLUS, i);
}

std::vector<tree::TerminalNode *> modelicaParser::ExprContext::MINUS() {
  return getTokens(modelicaParser::MINUS);
}

tree::TerminalNode* modelicaParser::ExprContext::MINUS(size_t i) {
  return getToken(modelicaParser::MINUS, i);
}


size_t modelicaParser::ExprContext::getRuleIndex() const {
  return modelicaParser::RuleExpr;
}


antlrcpp::Any modelicaParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::ExprContext* modelicaParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, modelicaParser::RuleExpr);
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
    while (_la == modelicaParser::PLUS

    || _la == modelicaParser::MINUS) {
      setState(12);
      _la = _input->LA(1);
      if (!(_la == modelicaParser::PLUS

      || _la == modelicaParser::MINUS)) {
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

modelicaParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::FactorContext *> modelicaParser::TermContext::factor() {
  return getRuleContexts<modelicaParser::FactorContext>();
}

modelicaParser::FactorContext* modelicaParser::TermContext::factor(size_t i) {
  return getRuleContext<modelicaParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> modelicaParser::TermContext::MULT() {
  return getTokens(modelicaParser::MULT);
}

tree::TerminalNode* modelicaParser::TermContext::MULT(size_t i) {
  return getToken(modelicaParser::MULT, i);
}

std::vector<tree::TerminalNode *> modelicaParser::TermContext::DIV() {
  return getTokens(modelicaParser::DIV);
}

tree::TerminalNode* modelicaParser::TermContext::DIV(size_t i) {
  return getToken(modelicaParser::DIV, i);
}


size_t modelicaParser::TermContext::getRuleIndex() const {
  return modelicaParser::RuleTerm;
}


antlrcpp::Any modelicaParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::TermContext* modelicaParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 4, modelicaParser::RuleTerm);
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
    while (_la == modelicaParser::MULT

    || _la == modelicaParser::DIV) {
      setState(20);
      _la = _input->LA(1);
      if (!(_la == modelicaParser::MULT

      || _la == modelicaParser::DIV)) {
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

modelicaParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::FactorContext::NUMBER() {
  return getToken(modelicaParser::NUMBER, 0);
}


size_t modelicaParser::FactorContext::getRuleIndex() const {
  return modelicaParser::RuleFactor;
}


antlrcpp::Any modelicaParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::FactorContext* modelicaParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 6, modelicaParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    match(modelicaParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> modelicaParser::_decisionToDFA;
atn::PredictionContextCache modelicaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN modelicaParser::_atn;
std::vector<uint16_t> modelicaParser::_serializedATN;

std::vector<std::string> modelicaParser::_ruleNames = {
  "compileUnit", "expr", "term", "factor"
};

std::vector<std::string> modelicaParser::_literalNames = {
  "", "'+'", "'-'", "'*'", "'/'"
};

std::vector<std::string> modelicaParser::_symbolicNames = {
  "", "PLUS", "MINUS", "MULT", "DIV", "COMMENT", "INT", "DOUBLE", "ID", 
  "WS", "NUMBER"
};

dfa::Vocabulary modelicaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> modelicaParser::_tokenNames;

modelicaParser::Initializer::Initializer() {
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

modelicaParser::Initializer modelicaParser::_init;
