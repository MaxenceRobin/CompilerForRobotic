
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1


#include "PivotVisitor.h"

#include "PivotParser.h"


using namespace antlrcpp;
using namespace antlr4;

PivotParser::PivotParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PivotParser::~PivotParser() {
  delete _interpreter;
}

std::string PivotParser::getGrammarFileName() const {
  return "Pivot.g4";
}

const std::vector<std::string>& PivotParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PivotParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

PivotParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PivotParser::StatementsContext* PivotParser::FileContext::statements() {
  return getRuleContext<PivotParser::StatementsContext>(0);
}

tree::TerminalNode* PivotParser::FileContext::EOF() {
  return getToken(PivotParser::EOF, 0);
}


size_t PivotParser::FileContext::getRuleIndex() const {
  return PivotParser::RuleFile;
}

antlrcpp::Any PivotParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::FileContext* PivotParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, PivotParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    statements();
    setState(29);
    match(PivotParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

PivotParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PivotParser::StatementContext *> PivotParser::StatementsContext::statement() {
  return getRuleContexts<PivotParser::StatementContext>();
}

PivotParser::StatementContext* PivotParser::StatementsContext::statement(size_t i) {
  return getRuleContext<PivotParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> PivotParser::StatementsContext::NEWLINE() {
  return getTokens(PivotParser::NEWLINE);
}

tree::TerminalNode* PivotParser::StatementsContext::NEWLINE(size_t i) {
  return getToken(PivotParser::NEWLINE, i);
}


size_t PivotParser::StatementsContext::getRuleIndex() const {
  return PivotParser::RuleStatements;
}

antlrcpp::Any PivotParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::StatementsContext* PivotParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 2, PivotParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(36);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(31);
        statement();
        setState(32);
        match(PivotParser::NEWLINE); 
      }
      setState(38);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(43);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::FORWARD

    || _la == PivotParser::LOOP) {
      setState(39);
      statement();
      setState(41);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PivotParser::NEWLINE) {
        setState(40);
        match(PivotParser::NEWLINE);
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

//----------------- StatementContext ------------------------------------------------------------------

PivotParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PivotParser::ActionContext* PivotParser::StatementContext::action() {
  return getRuleContext<PivotParser::ActionContext>(0);
}

PivotParser::LoopContext* PivotParser::StatementContext::loop() {
  return getRuleContext<PivotParser::LoopContext>(0);
}


size_t PivotParser::StatementContext::getRuleIndex() const {
  return PivotParser::RuleStatement;
}

antlrcpp::Any PivotParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::StatementContext* PivotParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, PivotParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::FORWARD: {
        enterOuterAlt(_localctx, 1);
        setState(45);
        action();
        break;
      }

      case PivotParser::LOOP: {
        enterOuterAlt(_localctx, 2);
        setState(46);
        loop();
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

//----------------- ActionContext ------------------------------------------------------------------

PivotParser::ActionContext::ActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::ActionContext::FORWARD() {
  return getToken(PivotParser::FORWARD, 0);
}

tree::TerminalNode* PivotParser::ActionContext::DURATION() {
  return getToken(PivotParser::DURATION, 0);
}

std::vector<tree::TerminalNode *> PivotParser::ActionContext::AFF() {
  return getTokens(PivotParser::AFF);
}

tree::TerminalNode* PivotParser::ActionContext::AFF(size_t i) {
  return getToken(PivotParser::AFF, i);
}

std::vector<PivotParser::Numeric_expressionContext *> PivotParser::ActionContext::numeric_expression() {
  return getRuleContexts<PivotParser::Numeric_expressionContext>();
}

PivotParser::Numeric_expressionContext* PivotParser::ActionContext::numeric_expression(size_t i) {
  return getRuleContext<PivotParser::Numeric_expressionContext>(i);
}

tree::TerminalNode* PivotParser::ActionContext::SPEED() {
  return getToken(PivotParser::SPEED, 0);
}


size_t PivotParser::ActionContext::getRuleIndex() const {
  return PivotParser::RuleAction;
}

antlrcpp::Any PivotParser::ActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitAction(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::ActionContext* PivotParser::action() {
  ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, getState());
  enterRule(_localctx, 6, PivotParser::RuleAction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(PivotParser::FORWARD);
    setState(50);
    match(PivotParser::DURATION);
    setState(51);
    match(PivotParser::AFF);
    setState(52);
    dynamic_cast<ActionContext *>(_localctx)->duration = numeric_expression();
    setState(56);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::SPEED) {
      setState(53);
      match(PivotParser::SPEED);
      setState(54);
      match(PivotParser::AFF);
      setState(55);
      dynamic_cast<ActionContext *>(_localctx)->speed = numeric_expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

PivotParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::LoopContext::LOOP() {
  return getToken(PivotParser::LOOP, 0);
}

tree::TerminalNode* PivotParser::LoopContext::TIMES() {
  return getToken(PivotParser::TIMES, 0);
}

tree::TerminalNode* PivotParser::LoopContext::AFF() {
  return getToken(PivotParser::AFF, 0);
}

tree::TerminalNode* PivotParser::LoopContext::SEP() {
  return getToken(PivotParser::SEP, 0);
}

tree::TerminalNode* PivotParser::LoopContext::NEWLINE() {
  return getToken(PivotParser::NEWLINE, 0);
}

PivotParser::StatementsContext* PivotParser::LoopContext::statements() {
  return getRuleContext<PivotParser::StatementsContext>(0);
}

tree::TerminalNode* PivotParser::LoopContext::END() {
  return getToken(PivotParser::END, 0);
}

PivotParser::Numeric_expressionContext* PivotParser::LoopContext::numeric_expression() {
  return getRuleContext<PivotParser::Numeric_expressionContext>(0);
}


size_t PivotParser::LoopContext::getRuleIndex() const {
  return PivotParser::RuleLoop;
}

antlrcpp::Any PivotParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::LoopContext* PivotParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 8, PivotParser::RuleLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(PivotParser::LOOP);
    setState(59);
    match(PivotParser::TIMES);
    setState(60);
    match(PivotParser::AFF);
    setState(61);
    dynamic_cast<LoopContext *>(_localctx)->repetition_number = numeric_expression();
    setState(62);
    match(PivotParser::SEP);
    setState(63);
    match(PivotParser::NEWLINE);
    setState(64);
    statements();
    setState(65);
    match(PivotParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Numeric_expressionContext ------------------------------------------------------------------

PivotParser::Numeric_expressionContext::Numeric_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PivotParser::Numeric_mul_divContext *> PivotParser::Numeric_expressionContext::numeric_mul_div() {
  return getRuleContexts<PivotParser::Numeric_mul_divContext>();
}

PivotParser::Numeric_mul_divContext* PivotParser::Numeric_expressionContext::numeric_mul_div(size_t i) {
  return getRuleContext<PivotParser::Numeric_mul_divContext>(i);
}

std::vector<tree::TerminalNode *> PivotParser::Numeric_expressionContext::PLUS() {
  return getTokens(PivotParser::PLUS);
}

tree::TerminalNode* PivotParser::Numeric_expressionContext::PLUS(size_t i) {
  return getToken(PivotParser::PLUS, i);
}

std::vector<tree::TerminalNode *> PivotParser::Numeric_expressionContext::MINUS() {
  return getTokens(PivotParser::MINUS);
}

tree::TerminalNode* PivotParser::Numeric_expressionContext::MINUS(size_t i) {
  return getToken(PivotParser::MINUS, i);
}


size_t PivotParser::Numeric_expressionContext::getRuleIndex() const {
  return PivotParser::RuleNumeric_expression;
}

antlrcpp::Any PivotParser::Numeric_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitNumeric_expression(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Numeric_expressionContext* PivotParser::numeric_expression() {
  Numeric_expressionContext *_localctx = _tracker.createInstance<Numeric_expressionContext>(_ctx, getState());
  enterRule(_localctx, 10, PivotParser::RuleNumeric_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
    dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::PLUS

    || _la == PivotParser::MINUS) {
      setState(68);
      dynamic_cast<Numeric_expressionContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == PivotParser::PLUS

      || _la == PivotParser::MINUS)) {
        dynamic_cast<Numeric_expressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(69);
      dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
      dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
      setState(74);
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

//----------------- Numeric_mul_divContext ------------------------------------------------------------------

PivotParser::Numeric_mul_divContext::Numeric_mul_divContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PivotParser::Numeric_powContext *> PivotParser::Numeric_mul_divContext::numeric_pow() {
  return getRuleContexts<PivotParser::Numeric_powContext>();
}

PivotParser::Numeric_powContext* PivotParser::Numeric_mul_divContext::numeric_pow(size_t i) {
  return getRuleContext<PivotParser::Numeric_powContext>(i);
}

std::vector<tree::TerminalNode *> PivotParser::Numeric_mul_divContext::STAR() {
  return getTokens(PivotParser::STAR);
}

tree::TerminalNode* PivotParser::Numeric_mul_divContext::STAR(size_t i) {
  return getToken(PivotParser::STAR, i);
}

std::vector<tree::TerminalNode *> PivotParser::Numeric_mul_divContext::DIV() {
  return getTokens(PivotParser::DIV);
}

tree::TerminalNode* PivotParser::Numeric_mul_divContext::DIV(size_t i) {
  return getToken(PivotParser::DIV, i);
}


size_t PivotParser::Numeric_mul_divContext::getRuleIndex() const {
  return PivotParser::RuleNumeric_mul_div;
}

antlrcpp::Any PivotParser::Numeric_mul_divContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitNumeric_mul_div(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Numeric_mul_divContext* PivotParser::numeric_mul_div() {
  Numeric_mul_divContext *_localctx = _tracker.createInstance<Numeric_mul_divContext>(_ctx, getState());
  enterRule(_localctx, 12, PivotParser::RuleNumeric_mul_div);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::DIV

    || _la == PivotParser::STAR) {
      setState(76);
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == PivotParser::DIV

      || _la == PivotParser::STAR)) {
        dynamic_cast<Numeric_mul_divContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(77);
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
      setState(82);
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

//----------------- Numeric_powContext ------------------------------------------------------------------

PivotParser::Numeric_powContext::Numeric_powContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PivotParser::Numeric_inversionContext* PivotParser::Numeric_powContext::numeric_inversion() {
  return getRuleContext<PivotParser::Numeric_inversionContext>(0);
}

tree::TerminalNode* PivotParser::Numeric_powContext::MATH() {
  return getToken(PivotParser::MATH, 0);
}

tree::TerminalNode* PivotParser::Numeric_powContext::DOT() {
  return getToken(PivotParser::DOT, 0);
}

tree::TerminalNode* PivotParser::Numeric_powContext::POW() {
  return getToken(PivotParser::POW, 0);
}

tree::TerminalNode* PivotParser::Numeric_powContext::LPAR() {
  return getToken(PivotParser::LPAR, 0);
}

tree::TerminalNode* PivotParser::Numeric_powContext::COMMA() {
  return getToken(PivotParser::COMMA, 0);
}

tree::TerminalNode* PivotParser::Numeric_powContext::RPAR() {
  return getToken(PivotParser::RPAR, 0);
}

std::vector<PivotParser::Numeric_expressionContext *> PivotParser::Numeric_powContext::numeric_expression() {
  return getRuleContexts<PivotParser::Numeric_expressionContext>();
}

PivotParser::Numeric_expressionContext* PivotParser::Numeric_powContext::numeric_expression(size_t i) {
  return getRuleContext<PivotParser::Numeric_expressionContext>(i);
}


size_t PivotParser::Numeric_powContext::getRuleIndex() const {
  return PivotParser::RuleNumeric_pow;
}

antlrcpp::Any PivotParser::Numeric_powContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitNumeric_pow(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Numeric_powContext* PivotParser::numeric_pow() {
  Numeric_powContext *_localctx = _tracker.createInstance<Numeric_powContext>(_ctx, getState());
  enterRule(_localctx, 14, PivotParser::RuleNumeric_pow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::NUMBER:
      case PivotParser::LPAR:
      case PivotParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(83);
        numeric_inversion();
        break;
      }

      case PivotParser::MATH: {
        enterOuterAlt(_localctx, 2);
        setState(84);
        match(PivotParser::MATH);
        setState(85);
        match(PivotParser::DOT);
        setState(86);
        match(PivotParser::POW);
        setState(87);
        match(PivotParser::LPAR);
        setState(88);
        dynamic_cast<Numeric_powContext *>(_localctx)->first = numeric_expression();
        setState(89);
        match(PivotParser::COMMA);
        setState(90);
        dynamic_cast<Numeric_powContext *>(_localctx)->second = numeric_expression();
        setState(91);
        match(PivotParser::RPAR);
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

//----------------- Numeric_inversionContext ------------------------------------------------------------------

PivotParser::Numeric_inversionContext::Numeric_inversionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PivotParser::Numeric_atomContext* PivotParser::Numeric_inversionContext::numeric_atom() {
  return getRuleContext<PivotParser::Numeric_atomContext>(0);
}

tree::TerminalNode* PivotParser::Numeric_inversionContext::MINUS() {
  return getToken(PivotParser::MINUS, 0);
}


size_t PivotParser::Numeric_inversionContext::getRuleIndex() const {
  return PivotParser::RuleNumeric_inversion;
}

antlrcpp::Any PivotParser::Numeric_inversionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitNumeric_inversion(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Numeric_inversionContext* PivotParser::numeric_inversion() {
  Numeric_inversionContext *_localctx = _tracker.createInstance<Numeric_inversionContext>(_ctx, getState());
  enterRule(_localctx, 16, PivotParser::RuleNumeric_inversion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::MINUS) {
      setState(95);
      match(PivotParser::MINUS);
    }
    setState(98);
    numeric_atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Numeric_atomContext ------------------------------------------------------------------

PivotParser::Numeric_atomContext::Numeric_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::Numeric_atomContext::NUMBER() {
  return getToken(PivotParser::NUMBER, 0);
}

tree::TerminalNode* PivotParser::Numeric_atomContext::LPAR() {
  return getToken(PivotParser::LPAR, 0);
}

PivotParser::Numeric_expressionContext* PivotParser::Numeric_atomContext::numeric_expression() {
  return getRuleContext<PivotParser::Numeric_expressionContext>(0);
}

tree::TerminalNode* PivotParser::Numeric_atomContext::RPAR() {
  return getToken(PivotParser::RPAR, 0);
}


size_t PivotParser::Numeric_atomContext::getRuleIndex() const {
  return PivotParser::RuleNumeric_atom;
}

antlrcpp::Any PivotParser::Numeric_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitNumeric_atom(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Numeric_atomContext* PivotParser::numeric_atom() {
  Numeric_atomContext *_localctx = _tracker.createInstance<Numeric_atomContext>(_ctx, getState());
  enterRule(_localctx, 18, PivotParser::RuleNumeric_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(100);
        match(PivotParser::NUMBER);
        break;
      }

      case PivotParser::LPAR: {
        enterOuterAlt(_localctx, 2);
        setState(101);
        match(PivotParser::LPAR);
        setState(102);
        numeric_expression();
        setState(103);
        match(PivotParser::RPAR);
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

//----------------- Boolean_expressionContext ------------------------------------------------------------------

PivotParser::Boolean_expressionContext::Boolean_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PivotParser::Boolean_andContext *> PivotParser::Boolean_expressionContext::boolean_and() {
  return getRuleContexts<PivotParser::Boolean_andContext>();
}

PivotParser::Boolean_andContext* PivotParser::Boolean_expressionContext::boolean_and(size_t i) {
  return getRuleContext<PivotParser::Boolean_andContext>(i);
}

std::vector<tree::TerminalNode *> PivotParser::Boolean_expressionContext::OR() {
  return getTokens(PivotParser::OR);
}

tree::TerminalNode* PivotParser::Boolean_expressionContext::OR(size_t i) {
  return getToken(PivotParser::OR, i);
}


size_t PivotParser::Boolean_expressionContext::getRuleIndex() const {
  return PivotParser::RuleBoolean_expression;
}

antlrcpp::Any PivotParser::Boolean_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitBoolean_expression(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Boolean_expressionContext* PivotParser::boolean_expression() {
  Boolean_expressionContext *_localctx = _tracker.createInstance<Boolean_expressionContext>(_ctx, getState());
  enterRule(_localctx, 20, PivotParser::RuleBoolean_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    boolean_and();
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::OR) {
      setState(108);
      match(PivotParser::OR);
      setState(109);
      boolean_and();
      setState(114);
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

//----------------- Boolean_andContext ------------------------------------------------------------------

PivotParser::Boolean_andContext::Boolean_andContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PivotParser::Boolean_notContext *> PivotParser::Boolean_andContext::boolean_not() {
  return getRuleContexts<PivotParser::Boolean_notContext>();
}

PivotParser::Boolean_notContext* PivotParser::Boolean_andContext::boolean_not(size_t i) {
  return getRuleContext<PivotParser::Boolean_notContext>(i);
}

std::vector<tree::TerminalNode *> PivotParser::Boolean_andContext::AND() {
  return getTokens(PivotParser::AND);
}

tree::TerminalNode* PivotParser::Boolean_andContext::AND(size_t i) {
  return getToken(PivotParser::AND, i);
}


size_t PivotParser::Boolean_andContext::getRuleIndex() const {
  return PivotParser::RuleBoolean_and;
}

antlrcpp::Any PivotParser::Boolean_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitBoolean_and(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Boolean_andContext* PivotParser::boolean_and() {
  Boolean_andContext *_localctx = _tracker.createInstance<Boolean_andContext>(_ctx, getState());
  enterRule(_localctx, 22, PivotParser::RuleBoolean_and);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    boolean_not();
    setState(120);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::AND) {
      setState(116);
      match(PivotParser::AND);
      setState(117);
      boolean_not();
      setState(122);
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

//----------------- Boolean_notContext ------------------------------------------------------------------

PivotParser::Boolean_notContext::Boolean_notContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PivotParser::Boolean_atomContext* PivotParser::Boolean_notContext::boolean_atom() {
  return getRuleContext<PivotParser::Boolean_atomContext>(0);
}

tree::TerminalNode* PivotParser::Boolean_notContext::NOT() {
  return getToken(PivotParser::NOT, 0);
}


size_t PivotParser::Boolean_notContext::getRuleIndex() const {
  return PivotParser::RuleBoolean_not;
}

antlrcpp::Any PivotParser::Boolean_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitBoolean_not(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Boolean_notContext* PivotParser::boolean_not() {
  Boolean_notContext *_localctx = _tracker.createInstance<Boolean_notContext>(_ctx, getState());
  enterRule(_localctx, 24, PivotParser::RuleBoolean_not);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::NOT) {
      setState(123);
      match(PivotParser::NOT);
    }
    setState(126);
    boolean_atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolean_atomContext ------------------------------------------------------------------

PivotParser::Boolean_atomContext::Boolean_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::Boolean_atomContext::TRUE() {
  return getToken(PivotParser::TRUE, 0);
}

tree::TerminalNode* PivotParser::Boolean_atomContext::FALSE() {
  return getToken(PivotParser::FALSE, 0);
}

tree::TerminalNode* PivotParser::Boolean_atomContext::LPAR() {
  return getToken(PivotParser::LPAR, 0);
}

PivotParser::Boolean_expressionContext* PivotParser::Boolean_atomContext::boolean_expression() {
  return getRuleContext<PivotParser::Boolean_expressionContext>(0);
}

tree::TerminalNode* PivotParser::Boolean_atomContext::RPAR() {
  return getToken(PivotParser::RPAR, 0);
}


size_t PivotParser::Boolean_atomContext::getRuleIndex() const {
  return PivotParser::RuleBoolean_atom;
}

antlrcpp::Any PivotParser::Boolean_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitBoolean_atom(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Boolean_atomContext* PivotParser::boolean_atom() {
  Boolean_atomContext *_localctx = _tracker.createInstance<Boolean_atomContext>(_ctx, getState());
  enterRule(_localctx, 26, PivotParser::RuleBoolean_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(134);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::TRUE: {
        enterOuterAlt(_localctx, 1);
        setState(128);
        match(PivotParser::TRUE);
        break;
      }

      case PivotParser::FALSE: {
        enterOuterAlt(_localctx, 2);
        setState(129);
        match(PivotParser::FALSE);
        break;
      }

      case PivotParser::LPAR: {
        enterOuterAlt(_localctx, 3);
        setState(130);
        match(PivotParser::LPAR);
        setState(131);
        boolean_expression();
        setState(132);
        match(PivotParser::RPAR);
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

// Static vars and initialization.
std::vector<dfa::DFA> PivotParser::_decisionToDFA;
atn::PredictionContextCache PivotParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PivotParser::_atn;
std::vector<uint16_t> PivotParser::_serializedATN;

std::vector<std::string> PivotParser::_ruleNames = {
  "file", "statements", "statement", "action", "loop", "numeric_expression", 
  "numeric_mul_div", "numeric_pow", "numeric_inversion", "numeric_atom", 
  "boolean_expression", "boolean_and", "boolean_not", "boolean_atom"
};

std::vector<std::string> PivotParser::_literalNames = {
  "", "", "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'&&'", "'||'", 
  "'!'", "'='", "'('", "')'", "':'", "'+'", "'-'", "'/'", "'*'", "','", 
  "'.'", "'Math'", "'pow'", "", "", "'forward'", "'true'", "'false'", "'duration'", 
  "'speed'", "'loop'", "'times'", "'end'"
};

std::vector<std::string> PivotParser::_symbolicNames = {
  "", "NUMBER", "EQU", "DIF", "LT", "GT", "LEQ", "GEQ", "AND", "OR", "NOT", 
  "AFF", "LPAR", "RPAR", "SEP", "PLUS", "MINUS", "DIV", "STAR", "COMMA", 
  "DOT", "MATH", "POW", "NEWLINE", "WHITESPACE", "FORWARD", "TRUE", "FALSE", 
  "DURATION", "SPEED", "LOOP", "TIMES", "END"
};

dfa::Vocabulary PivotParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PivotParser::_tokenNames;

PivotParser::Initializer::Initializer() {
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
    0x3, 0x22, 0x8b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x25, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x28, 0xb, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 0xa, 0x3, 0x5, 0x3, 0x2e, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x32, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3b, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x49, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x4c, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 
    0x8, 0x51, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x54, 0xb, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x60, 0xa, 0x9, 0x3, 0xa, 0x5, 0xa, 0x63, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x6c, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 
    0x71, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x74, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x7, 0xd, 0x79, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x7c, 0xb, 0xd, 
    0x3, 0xe, 0x5, 0xe, 0x7f, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x89, 0xa, 0xf, 
    0x3, 0xf, 0x2, 0x2, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 0x4, 0x3, 0x2, 0x11, 0x12, 0x3, 0x2, 
    0x13, 0x14, 0x2, 0x8b, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x8, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x45, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x16, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x75, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x7e, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x88, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x5, 0x4, 0x3, 
    0x2, 0x1f, 0x20, 0x7, 0x2, 0x2, 0x3, 0x20, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x22, 0x5, 0x6, 0x4, 0x2, 0x22, 0x23, 0x7, 0x19, 0x2, 0x2, 0x23, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x24, 0x21, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2b, 0x5, 0x6, 0x4, 0x2, 0x2a, 0x2c, 0x7, 0x19, 0x2, 
    0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2d, 
    0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 
    0x5, 0x8, 0x5, 0x2, 0x30, 0x32, 0x5, 0xa, 0x6, 0x2, 0x31, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x34, 0x7, 0x1b, 0x2, 0x2, 0x34, 0x35, 0x7, 0x1e, 0x2, 
    0x2, 0x35, 0x36, 0x7, 0xd, 0x2, 0x2, 0x36, 0x3a, 0x5, 0xc, 0x7, 0x2, 
    0x37, 0x38, 0x7, 0x1f, 0x2, 0x2, 0x38, 0x39, 0x7, 0xd, 0x2, 0x2, 0x39, 
    0x3b, 0x5, 0xc, 0x7, 0x2, 0x3a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 
    0x20, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x21, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xd, 
    0x2, 0x2, 0x3f, 0x40, 0x5, 0xc, 0x7, 0x2, 0x40, 0x41, 0x7, 0x10, 0x2, 
    0x2, 0x41, 0x42, 0x7, 0x19, 0x2, 0x2, 0x42, 0x43, 0x5, 0x4, 0x3, 0x2, 
    0x43, 0x44, 0x7, 0x22, 0x2, 0x2, 0x44, 0xb, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x4a, 0x5, 0xe, 0x8, 0x2, 0x46, 0x47, 0x9, 0x2, 0x2, 0x2, 0x47, 0x49, 
    0x5, 0xe, 0x8, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x52, 0x5, 0x10, 0x9, 0x2, 0x4e, 0x4f, 0x9, 0x3, 0x2, 0x2, 
    0x4f, 0x51, 0x5, 0x10, 0x9, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0xf, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x60, 0x5, 0x12, 0xa, 0x2, 0x56, 0x57, 0x7, 0x17, 
    0x2, 0x2, 0x57, 0x58, 0x7, 0x16, 0x2, 0x2, 0x58, 0x59, 0x7, 0x18, 0x2, 
    0x2, 0x59, 0x5a, 0x7, 0xe, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0xc, 0x7, 0x2, 
    0x5b, 0x5c, 0x7, 0x15, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0xc, 0x7, 0x2, 0x5d, 
    0x5e, 0x7, 0xf, 0x2, 0x2, 0x5e, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x56, 0x3, 0x2, 0x2, 0x2, 0x60, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x63, 0x7, 0x12, 0x2, 0x2, 0x62, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x65, 0x5, 0x14, 0xb, 0x2, 0x65, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x6c, 0x7, 0x3, 0x2, 0x2, 0x67, 0x68, 0x7, 0xe, 0x2, 0x2, 0x68, 
    0x69, 0x5, 0xc, 0x7, 0x2, 0x69, 0x6a, 0x7, 0xf, 0x2, 0x2, 0x6a, 0x6c, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x15, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x72, 0x5, 0x18, 
    0xd, 0x2, 0x6e, 0x6f, 0x7, 0xb, 0x2, 0x2, 0x6f, 0x71, 0x5, 0x18, 0xd, 
    0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x7a, 
    0x5, 0x1a, 0xe, 0x2, 0x76, 0x77, 0x7, 0xa, 0x2, 0x2, 0x77, 0x79, 0x5, 
    0x1a, 0xe, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0x7f, 0x7, 0xc, 0x2, 0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 
    0x5, 0x1c, 0xf, 0x2, 0x81, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x82, 0x89, 0x7, 
    0x1c, 0x2, 0x2, 0x83, 0x89, 0x7, 0x1d, 0x2, 0x2, 0x84, 0x85, 0x7, 0xe, 
    0x2, 0x2, 0x85, 0x86, 0x5, 0x16, 0xc, 0x2, 0x86, 0x87, 0x7, 0xf, 0x2, 
    0x2, 0x87, 0x89, 0x3, 0x2, 0x2, 0x2, 0x88, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x83, 0x3, 0x2, 0x2, 0x2, 0x88, 0x84, 0x3, 0x2, 0x2, 0x2, 0x89, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x26, 0x2b, 0x2d, 0x31, 0x3a, 0x4a, 
    0x52, 0x5f, 0x62, 0x6b, 0x72, 0x7a, 0x7e, 0x88, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PivotParser::Initializer PivotParser::_init;
