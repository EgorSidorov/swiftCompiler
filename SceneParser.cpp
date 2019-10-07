
// Generated from Scene.g4 by ANTLR 4.7.2


#include "SceneListener.h"

#include "SceneParser.h"


using namespace antlrcpp;
using namespace antlr4;

SceneParser::SceneParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SceneParser::~SceneParser() {
  delete _interpreter;
}

std::string SceneParser::getGrammarFileName() const {
  return "Scene.g4";
}

const std::vector<std::string>& SceneParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SceneParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

SceneParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SceneParser::ExpressionContext *> SceneParser::ProgramContext::expression() {
  return getRuleContexts<SceneParser::ExpressionContext>();
}

SceneParser::ExpressionContext* SceneParser::ProgramContext::expression(size_t i) {
  return getRuleContext<SceneParser::ExpressionContext>(i);
}

tree::TerminalNode* SceneParser::ProgramContext::EOF() {
  return getToken(SceneParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SceneParser::ProgramContext::END_EXPR() {
  return getTokens(SceneParser::END_EXPR);
}

tree::TerminalNode* SceneParser::ProgramContext::END_EXPR(size_t i) {
  return getToken(SceneParser::END_EXPR, i);
}


size_t SceneParser::ProgramContext::getRuleIndex() const {
  return SceneParser::RuleProgram;
}

void SceneParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void SceneParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

SceneParser::ProgramContext* SceneParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SceneParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    expression();
    setState(25);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SceneParser::END_EXPR) {
      setState(21);
      match(SceneParser::END_EXPR);
      setState(22);
      expression();
      setState(27);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(28);
    match(SceneParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Math_expressionContext ------------------------------------------------------------------

SceneParser::Math_expressionContext::Math_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::Math_expressionContext::LEFT_BRACKET() {
  return getToken(SceneParser::LEFT_BRACKET, 0);
}

std::vector<SceneParser::Math_expressionContext *> SceneParser::Math_expressionContext::math_expression() {
  return getRuleContexts<SceneParser::Math_expressionContext>();
}

SceneParser::Math_expressionContext* SceneParser::Math_expressionContext::math_expression(size_t i) {
  return getRuleContext<SceneParser::Math_expressionContext>(i);
}

tree::TerminalNode* SceneParser::Math_expressionContext::RIGHT_BRACKET() {
  return getToken(SceneParser::RIGHT_BRACKET, 0);
}

tree::TerminalNode* SceneParser::Math_expressionContext::PLUS() {
  return getToken(SceneParser::PLUS, 0);
}

tree::TerminalNode* SceneParser::Math_expressionContext::MINUS() {
  return getToken(SceneParser::MINUS, 0);
}

tree::TerminalNode* SceneParser::Math_expressionContext::MULT() {
  return getToken(SceneParser::MULT, 0);
}

tree::TerminalNode* SceneParser::Math_expressionContext::DIV() {
  return getToken(SceneParser::DIV, 0);
}


size_t SceneParser::Math_expressionContext::getRuleIndex() const {
  return SceneParser::RuleMath_expression;
}

void SceneParser::Math_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMath_expression(this);
}

void SceneParser::Math_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMath_expression(this);
}


SceneParser::Math_expressionContext* SceneParser::math_expression() {
   return math_expression(0);
}

SceneParser::Math_expressionContext* SceneParser::math_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SceneParser::Math_expressionContext *_localctx = _tracker.createInstance<Math_expressionContext>(_ctx, parentState);
  SceneParser::Math_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, SceneParser::RuleMath_expression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SceneParser::LEFT_BRACKET: {
        setState(31);
        match(SceneParser::LEFT_BRACKET);
        setState(32);
        math_expression(0);
        setState(33);
        match(SceneParser::RIGHT_BRACKET);
        break;
      }

      case SceneParser::PLUS:
      case SceneParser::MINUS: {
        setState(35);
        dynamic_cast<Math_expressionContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == SceneParser::PLUS

        || _la == SceneParser::MINUS)) {
          dynamic_cast<Math_expressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(36);
        math_expression(3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(47);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(45);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Math_expressionContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleMath_expression);
          setState(39);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(40);
          dynamic_cast<Math_expressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == SceneParser::MULT

          || _la == SceneParser::DIV)) {
            dynamic_cast<Math_expressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(41);
          dynamic_cast<Math_expressionContext *>(_localctx)->right = math_expression(3);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Math_expressionContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleMath_expression);
          setState(42);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(43);
          dynamic_cast<Math_expressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == SceneParser::PLUS

          || _la == SceneParser::MINUS)) {
            dynamic_cast<Math_expressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(44);
          dynamic_cast<Math_expressionContext *>(_localctx)->right = math_expression(2);
          break;
        }

        } 
      }
      setState(49);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SceneParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SceneParser::Math_expressionContext* SceneParser::ExpressionContext::math_expression() {
  return getRuleContext<SceneParser::Math_expressionContext>(0);
}

SceneParser::AssignContext* SceneParser::ExpressionContext::assign() {
  return getRuleContext<SceneParser::AssignContext>(0);
}

SceneParser::Function_callContext* SceneParser::ExpressionContext::function_call() {
  return getRuleContext<SceneParser::Function_callContext>(0);
}


size_t SceneParser::ExpressionContext::getRuleIndex() const {
  return SceneParser::RuleExpression;
}

void SceneParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SceneParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

SceneParser::ExpressionContext* SceneParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 4, SceneParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(50);
      math_expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(51);
      assign();
      setState(52);
      math_expression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(54);
      function_call();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

SceneParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::AssignContext::INIT() {
  return getToken(SceneParser::INIT, 0);
}

tree::TerminalNode* SceneParser::AssignContext::ID() {
  return getToken(SceneParser::ID, 0);
}

tree::TerminalNode* SceneParser::AssignContext::INIT_TYPE() {
  return getToken(SceneParser::INIT_TYPE, 0);
}

tree::TerminalNode* SceneParser::AssignContext::EQUI() {
  return getToken(SceneParser::EQUI, 0);
}


size_t SceneParser::AssignContext::getRuleIndex() const {
  return SceneParser::RuleAssign;
}

void SceneParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void SceneParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

SceneParser::AssignContext* SceneParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 6, SceneParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(57);
      match(SceneParser::INIT);
      setState(58);
      match(SceneParser::ID);
      setState(59);
      match(SceneParser::INIT_TYPE);
      setState(60);
      match(SceneParser::EQUI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(61);
      match(SceneParser::ID);
      setState(62);
      match(SceneParser::EQUI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(63);
      match(SceneParser::INIT);
      setState(64);
      match(SceneParser::ID);
      setState(65);
      match(SceneParser::EQUI);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

SceneParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::Function_callContext::ID() {
  return getToken(SceneParser::ID, 0);
}

tree::TerminalNode* SceneParser::Function_callContext::LEFT_BRACKET() {
  return getToken(SceneParser::LEFT_BRACKET, 0);
}

tree::TerminalNode* SceneParser::Function_callContext::RIGHT_BRACKET() {
  return getToken(SceneParser::RIGHT_BRACKET, 0);
}

std::vector<SceneParser::Function_argumentContext *> SceneParser::Function_callContext::function_argument() {
  return getRuleContexts<SceneParser::Function_argumentContext>();
}

SceneParser::Function_argumentContext* SceneParser::Function_callContext::function_argument(size_t i) {
  return getRuleContext<SceneParser::Function_argumentContext>(i);
}


size_t SceneParser::Function_callContext::getRuleIndex() const {
  return SceneParser::RuleFunction_call;
}

void SceneParser::Function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call(this);
}

void SceneParser::Function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call(this);
}

SceneParser::Function_callContext* SceneParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 8, SceneParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(SceneParser::ID);
    setState(69);
    match(SceneParser::LEFT_BRACKET);
    setState(76);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(70);
        function_argument();
        setState(72);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SceneParser::T__0) {
          setState(71);
          match(SceneParser::T__0);
        } 
      }
      setState(78);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(79);
    match(SceneParser::RIGHT_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_argumentContext ------------------------------------------------------------------

SceneParser::Function_argumentContext::Function_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SceneParser::Math_expressionContext* SceneParser::Function_argumentContext::math_expression() {
  return getRuleContext<SceneParser::Math_expressionContext>(0);
}

tree::TerminalNode* SceneParser::Function_argumentContext::STRING() {
  return getToken(SceneParser::STRING, 0);
}


size_t SceneParser::Function_argumentContext::getRuleIndex() const {
  return SceneParser::RuleFunction_argument;
}

void SceneParser::Function_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_argument(this);
}

void SceneParser::Function_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_argument(this);
}

SceneParser::Function_argumentContext* SceneParser::function_argument() {
  Function_argumentContext *_localctx = _tracker.createInstance<Function_argumentContext>(_ctx, getState());
  enterRule(_localctx, 10, SceneParser::RuleFunction_argument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SceneParser::PLUS:
      case SceneParser::MINUS:
      case SceneParser::LEFT_BRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(81);
        math_expression(0);
        break;
      }

      case SceneParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(82);
        match(SceneParser::STRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mult_divContext ------------------------------------------------------------------

SceneParser::Mult_divContext::Mult_divContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::Mult_divContext::MULT() {
  return getToken(SceneParser::MULT, 0);
}

tree::TerminalNode* SceneParser::Mult_divContext::DIV() {
  return getToken(SceneParser::DIV, 0);
}


size_t SceneParser::Mult_divContext::getRuleIndex() const {
  return SceneParser::RuleMult_div;
}

void SceneParser::Mult_divContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult_div(this);
}

void SceneParser::Mult_divContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult_div(this);
}

SceneParser::Mult_divContext* SceneParser::mult_div() {
  Mult_divContext *_localctx = _tracker.createInstance<Mult_divContext>(_ctx, getState());
  enterRule(_localctx, 12, SceneParser::RuleMult_div);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    _la = _input->LA(1);
    if (!(_la == SceneParser::MULT

    || _la == SceneParser::DIV)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Plus_minusContext ------------------------------------------------------------------

SceneParser::Plus_minusContext::Plus_minusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::Plus_minusContext::PLUS() {
  return getToken(SceneParser::PLUS, 0);
}

tree::TerminalNode* SceneParser::Plus_minusContext::MINUS() {
  return getToken(SceneParser::MINUS, 0);
}


size_t SceneParser::Plus_minusContext::getRuleIndex() const {
  return SceneParser::RulePlus_minus;
}

void SceneParser::Plus_minusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlus_minus(this);
}

void SceneParser::Plus_minusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlus_minus(this);
}

SceneParser::Plus_minusContext* SceneParser::plus_minus() {
  Plus_minusContext *_localctx = _tracker.createInstance<Plus_minusContext>(_ctx, getState());
  enterRule(_localctx, 14, SceneParser::RulePlus_minus);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    _la = _input->LA(1);
    if (!(_la == SceneParser::PLUS

    || _la == SceneParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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

SceneParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SceneParser::FactorContext *> SceneParser::TermContext::factor() {
  return getRuleContexts<SceneParser::FactorContext>();
}

SceneParser::FactorContext* SceneParser::TermContext::factor(size_t i) {
  return getRuleContext<SceneParser::FactorContext>(i);
}

std::vector<SceneParser::Mult_divContext *> SceneParser::TermContext::mult_div() {
  return getRuleContexts<SceneParser::Mult_divContext>();
}

SceneParser::Mult_divContext* SceneParser::TermContext::mult_div(size_t i) {
  return getRuleContext<SceneParser::Mult_divContext>(i);
}


size_t SceneParser::TermContext::getRuleIndex() const {
  return SceneParser::RuleTerm;
}

void SceneParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void SceneParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

SceneParser::TermContext* SceneParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 16, SceneParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    factor();
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SceneParser::MULT

    || _la == SceneParser::DIV) {
      setState(90);
      mult_div();
      setState(91);
      factor();
      setState(97);
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

SceneParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SceneParser::FactorContext::NUMBER() {
  return getToken(SceneParser::NUMBER, 0);
}

tree::TerminalNode* SceneParser::FactorContext::ID() {
  return getToken(SceneParser::ID, 0);
}

SceneParser::Function_callContext* SceneParser::FactorContext::function_call() {
  return getRuleContext<SceneParser::Function_callContext>(0);
}


size_t SceneParser::FactorContext::getRuleIndex() const {
  return SceneParser::RuleFactor;
}

void SceneParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void SceneParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SceneListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

SceneParser::FactorContext* SceneParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 18, SceneParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(98);
      match(SceneParser::NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(99);
      match(SceneParser::ID);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(100);
      function_call();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SceneParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return math_expressionSempred(dynamic_cast<Math_expressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SceneParser::math_expressionSempred(Math_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SceneParser::_decisionToDFA;
atn::PredictionContextCache SceneParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SceneParser::_atn;
std::vector<uint16_t> SceneParser::_serializedATN;

std::vector<std::string> SceneParser::_ruleNames = {
  "program", "math_expression", "expression", "assign", "function_call", 
  "function_argument", "mult_div", "plus_minus", "term", "factor"
};

std::vector<std::string> SceneParser::_literalNames = {
  "", "','", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'='", "", "", "", 
  "", "'var '", "", "", "", "", "", "'for '", "' '"
};

std::vector<std::string> SceneParser::_symbolicNames = {
  "", "", "PLUS", "MINUS", "MULT", "DIV", "LEFT_BRACKET", "RIGHT_BRACKET", 
  "EQUI", "COMMENT", "DOUBLE", "INT", "END_EXPR", "INIT", "TYPE", "INIT_TYPE", 
  "ID", "CHAR", "STRING", "FOR_LOOP", "WHITESPACE", "NUMBER"
};

dfa::Vocabulary SceneParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SceneParser::_tokenNames;

SceneParser::Initializer::Initializer() {
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
    0x3, 0x17, 0x6a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1a, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x1d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x28, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x30, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x33, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3a, 0xa, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x45, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x4b, 0xa, 0x6, 0x7, 0x6, 0x4d, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x50, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x56, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x60, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x63, 
    0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x68, 0xa, 0xb, 0x3, 
    0xb, 0x3, 0x4e, 0x3, 0x4, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x2, 0x4, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0x6, 0x7, 0x2, 0x6d, 
    0x2, 0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x27, 0x3, 0x2, 0x2, 0x2, 0x6, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 0xa, 0x46, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x55, 0x3, 0x2, 0x2, 0x2, 0xe, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x59, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1b, 0x5, 0x6, 0x4, 0x2, 0x17, 0x18, 
    0x7, 0xe, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x6, 0x4, 0x2, 0x19, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x2, 0x2, 0x3, 
    0x1f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x8, 0x3, 0x1, 0x2, 0x21, 
    0x22, 0x7, 0x8, 0x2, 0x2, 0x22, 0x23, 0x5, 0x4, 0x3, 0x2, 0x23, 0x24, 
    0x7, 0x9, 0x2, 0x2, 0x24, 0x28, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x9, 
    0x2, 0x2, 0x2, 0x26, 0x28, 0x5, 0x4, 0x3, 0x5, 0x27, 0x20, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x2a, 0xc, 0x4, 0x2, 0x2, 0x2a, 0x2b, 0x9, 0x3, 0x2, 0x2, 
    0x2b, 0x30, 0x5, 0x4, 0x3, 0x5, 0x2c, 0x2d, 0xc, 0x3, 0x2, 0x2, 0x2d, 
    0x2e, 0x9, 0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 0x3, 0x4, 0x2f, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x5, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x3a, 0x5, 0x4, 0x3, 0x2, 0x35, 0x36, 0x5, 0x8, 0x5, 0x2, 
    0x36, 0x37, 0x5, 0x4, 0x3, 0x2, 0x37, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x3a, 0x5, 0xa, 0x6, 0x2, 0x39, 0x34, 0x3, 0x2, 0x2, 0x2, 0x39, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0xf, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x12, 
    0x2, 0x2, 0x3d, 0x3e, 0x7, 0x11, 0x2, 0x2, 0x3e, 0x45, 0x7, 0xa, 0x2, 
    0x2, 0x3f, 0x40, 0x7, 0x12, 0x2, 0x2, 0x40, 0x45, 0x7, 0xa, 0x2, 0x2, 
    0x41, 0x42, 0x7, 0xf, 0x2, 0x2, 0x42, 0x43, 0x7, 0x12, 0x2, 0x2, 0x43, 
    0x45, 0x7, 0xa, 0x2, 0x2, 0x44, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x44, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x41, 0x3, 0x2, 0x2, 0x2, 0x45, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x12, 0x2, 0x2, 0x47, 0x4e, 0x7, 0x8, 
    0x2, 0x2, 0x48, 0x4a, 0x5, 0xc, 0x7, 0x2, 0x49, 0x4b, 0x7, 0x3, 0x2, 
    0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x9, 0x2, 0x2, 0x52, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x56, 0x5, 0x4, 0x3, 0x2, 0x54, 0x56, 0x7, 0x14, 0x2, 
    0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0xd, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x9, 0x3, 0x2, 0x2, 0x58, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x9, 0x2, 0x2, 0x2, 0x5a, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x61, 0x5, 0x14, 0xb, 0x2, 0x5c, 0x5d, 0x5, 
    0xe, 0x8, 0x2, 0x5d, 0x5e, 0x5, 0x14, 0xb, 0x2, 0x5e, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x60, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x13, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x68, 0x7, 0x17, 0x2, 0x2, 0x65, 0x68, 0x7, 0x12, 0x2, 0x2, 0x66, 0x68, 
    0x5, 0xa, 0x6, 0x2, 0x67, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xd, 0x1b, 0x27, 0x2f, 0x31, 0x39, 0x44, 0x4a, 0x4e, 0x55, 
    0x61, 0x67, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SceneParser::Initializer SceneParser::_init;
