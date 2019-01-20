
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
    setState(36);
    statements();
    setState(37);
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
    setState(44);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(39);
        statement();
        setState(40);
        match(PivotParser::NEWLINE); 
      }
      setState(46);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PivotParser::FORWARD)
      | (1ULL << PivotParser::BACKWARD)
      | (1ULL << PivotParser::LEFT)
      | (1ULL << PivotParser::RIGHT)
      | (1ULL << PivotParser::STOP)
      | (1ULL << PivotParser::WAIT)
      | (1ULL << PivotParser::LOOP)
      | (1ULL << PivotParser::IF)
      | (1ULL << PivotParser::WHILE)
      | (1ULL << PivotParser::UNTIL))) != 0)) {
      setState(47);
      statement();
      setState(49);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PivotParser::NEWLINE) {
        setState(48);
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

PivotParser::While_loopContext* PivotParser::StatementContext::while_loop() {
  return getRuleContext<PivotParser::While_loopContext>(0);
}

PivotParser::Until_loopContext* PivotParser::StatementContext::until_loop() {
  return getRuleContext<PivotParser::Until_loopContext>(0);
}

PivotParser::If_elif_elseContext* PivotParser::StatementContext::if_elif_else() {
  return getRuleContext<PivotParser::If_elif_elseContext>(0);
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
    setState(58);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::FORWARD:
      case PivotParser::BACKWARD:
      case PivotParser::LEFT:
      case PivotParser::RIGHT:
      case PivotParser::STOP:
      case PivotParser::WAIT: {
        enterOuterAlt(_localctx, 1);
        setState(53);
        action();
        break;
      }

      case PivotParser::LOOP: {
        enterOuterAlt(_localctx, 2);
        setState(54);
        loop();
        break;
      }

      case PivotParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(55);
        while_loop();
        break;
      }

      case PivotParser::UNTIL: {
        enterOuterAlt(_localctx, 4);
        setState(56);
        until_loop();
        break;
      }

      case PivotParser::IF: {
        enterOuterAlt(_localctx, 5);
        setState(57);
        if_elif_else();
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

tree::TerminalNode* PivotParser::ActionContext::FORWARD() {
  return getToken(PivotParser::FORWARD, 0);
}

tree::TerminalNode* PivotParser::ActionContext::BACKWARD() {
  return getToken(PivotParser::BACKWARD, 0);
}

tree::TerminalNode* PivotParser::ActionContext::LEFT() {
  return getToken(PivotParser::LEFT, 0);
}

tree::TerminalNode* PivotParser::ActionContext::RIGHT() {
  return getToken(PivotParser::RIGHT, 0);
}

tree::TerminalNode* PivotParser::ActionContext::SPEED() {
  return getToken(PivotParser::SPEED, 0);
}

tree::TerminalNode* PivotParser::ActionContext::STOP() {
  return getToken(PivotParser::STOP, 0);
}

tree::TerminalNode* PivotParser::ActionContext::WAIT() {
  return getToken(PivotParser::WAIT, 0);
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
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::FORWARD:
      case PivotParser::BACKWARD:
      case PivotParser::LEFT:
      case PivotParser::RIGHT: {
        enterOuterAlt(_localctx, 1);
        setState(60);
        dynamic_cast<ActionContext *>(_localctx)->move_type = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PivotParser::FORWARD)
          | (1ULL << PivotParser::BACKWARD)
          | (1ULL << PivotParser::LEFT)
          | (1ULL << PivotParser::RIGHT))) != 0))) {
          dynamic_cast<ActionContext *>(_localctx)->move_type = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(61);
        match(PivotParser::DURATION);
        setState(62);
        match(PivotParser::AFF);
        setState(63);
        dynamic_cast<ActionContext *>(_localctx)->duration = numeric_expression();
        setState(67);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PivotParser::SPEED) {
          setState(64);
          match(PivotParser::SPEED);
          setState(65);
          match(PivotParser::AFF);
          setState(66);
          dynamic_cast<ActionContext *>(_localctx)->speed = numeric_expression();
        }
        break;
      }

      case PivotParser::STOP: {
        enterOuterAlt(_localctx, 2);
        setState(69);
        match(PivotParser::STOP);
        break;
      }

      case PivotParser::WAIT: {
        enterOuterAlt(_localctx, 3);
        setState(70);
        match(PivotParser::WAIT);
        setState(71);
        match(PivotParser::DURATION);
        setState(72);
        match(PivotParser::AFF);
        setState(73);
        dynamic_cast<ActionContext *>(_localctx)->duration = numeric_expression();
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
    setState(76);
    match(PivotParser::LOOP);
    setState(77);
    match(PivotParser::TIMES);
    setState(78);
    match(PivotParser::AFF);
    setState(79);
    dynamic_cast<LoopContext *>(_localctx)->repetition_number = numeric_expression();
    setState(80);
    match(PivotParser::SEP);
    setState(81);
    match(PivotParser::NEWLINE);
    setState(82);
    statements();
    setState(83);
    match(PivotParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_loopContext ------------------------------------------------------------------

PivotParser::While_loopContext::While_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::While_loopContext::WHILE() {
  return getToken(PivotParser::WHILE, 0);
}

tree::TerminalNode* PivotParser::While_loopContext::SEP() {
  return getToken(PivotParser::SEP, 0);
}

tree::TerminalNode* PivotParser::While_loopContext::NEWLINE() {
  return getToken(PivotParser::NEWLINE, 0);
}

PivotParser::StatementsContext* PivotParser::While_loopContext::statements() {
  return getRuleContext<PivotParser::StatementsContext>(0);
}

tree::TerminalNode* PivotParser::While_loopContext::END() {
  return getToken(PivotParser::END, 0);
}

PivotParser::Boolean_expressionContext* PivotParser::While_loopContext::boolean_expression() {
  return getRuleContext<PivotParser::Boolean_expressionContext>(0);
}


size_t PivotParser::While_loopContext::getRuleIndex() const {
  return PivotParser::RuleWhile_loop;
}

antlrcpp::Any PivotParser::While_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitWhile_loop(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::While_loopContext* PivotParser::while_loop() {
  While_loopContext *_localctx = _tracker.createInstance<While_loopContext>(_ctx, getState());
  enterRule(_localctx, 10, PivotParser::RuleWhile_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(PivotParser::WHILE);
    setState(86);
    dynamic_cast<While_loopContext *>(_localctx)->condition = boolean_expression();
    setState(87);
    match(PivotParser::SEP);
    setState(88);
    match(PivotParser::NEWLINE);
    setState(89);
    statements();
    setState(90);
    match(PivotParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Until_loopContext ------------------------------------------------------------------

PivotParser::Until_loopContext::Until_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::Until_loopContext::UNTIL() {
  return getToken(PivotParser::UNTIL, 0);
}

tree::TerminalNode* PivotParser::Until_loopContext::SEP() {
  return getToken(PivotParser::SEP, 0);
}

tree::TerminalNode* PivotParser::Until_loopContext::NEWLINE() {
  return getToken(PivotParser::NEWLINE, 0);
}

PivotParser::StatementsContext* PivotParser::Until_loopContext::statements() {
  return getRuleContext<PivotParser::StatementsContext>(0);
}

tree::TerminalNode* PivotParser::Until_loopContext::END() {
  return getToken(PivotParser::END, 0);
}

PivotParser::Boolean_expressionContext* PivotParser::Until_loopContext::boolean_expression() {
  return getRuleContext<PivotParser::Boolean_expressionContext>(0);
}


size_t PivotParser::Until_loopContext::getRuleIndex() const {
  return PivotParser::RuleUntil_loop;
}

antlrcpp::Any PivotParser::Until_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitUntil_loop(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Until_loopContext* PivotParser::until_loop() {
  Until_loopContext *_localctx = _tracker.createInstance<Until_loopContext>(_ctx, getState());
  enterRule(_localctx, 12, PivotParser::RuleUntil_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(PivotParser::UNTIL);
    setState(93);
    dynamic_cast<Until_loopContext *>(_localctx)->condition = boolean_expression();
    setState(94);
    match(PivotParser::SEP);
    setState(95);
    match(PivotParser::NEWLINE);
    setState(96);
    statements();
    setState(97);
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
  enterRule(_localctx, 14, PivotParser::RuleNumeric_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
    dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::PLUS

    || _la == PivotParser::MINUS) {
      setState(100);
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
      setState(101);
      dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
      dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
      setState(106);
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
  enterRule(_localctx, 16, PivotParser::RuleNumeric_mul_div);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::DIV

    || _la == PivotParser::STAR) {
      setState(108);
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
      setState(109);
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
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

//----------------- Numeric_powContext ------------------------------------------------------------------

PivotParser::Numeric_powContext::Numeric_powContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PivotParser::Numeric_inversionContext *> PivotParser::Numeric_powContext::numeric_inversion() {
  return getRuleContexts<PivotParser::Numeric_inversionContext>();
}

PivotParser::Numeric_inversionContext* PivotParser::Numeric_powContext::numeric_inversion(size_t i) {
  return getRuleContext<PivotParser::Numeric_inversionContext>(i);
}

std::vector<tree::TerminalNode *> PivotParser::Numeric_powContext::POW() {
  return getTokens(PivotParser::POW);
}

tree::TerminalNode* PivotParser::Numeric_powContext::POW(size_t i) {
  return getToken(PivotParser::POW, i);
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
  enterRule(_localctx, 18, PivotParser::RuleNumeric_pow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext = numeric_inversion();
    dynamic_cast<Numeric_powContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext);
    setState(120);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::POW) {
      setState(116);
      match(PivotParser::POW);
      setState(117);
      dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext = numeric_inversion();
      dynamic_cast<Numeric_powContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext);
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
  enterRule(_localctx, 20, PivotParser::RuleNumeric_inversion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::MINUS) {
      setState(123);
      match(PivotParser::MINUS);
    }
    setState(126);
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
  enterRule(_localctx, 22, PivotParser::RuleNumeric_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(128);
        match(PivotParser::NUMBER);
        break;
      }

      case PivotParser::LPAR: {
        enterOuterAlt(_localctx, 2);
        setState(129);
        match(PivotParser::LPAR);
        setState(130);
        numeric_expression();
        setState(131);
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

//----------------- If_elif_elseContext ------------------------------------------------------------------

PivotParser::If_elif_elseContext::If_elif_elseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::If_elif_elseContext::IF() {
  return getToken(PivotParser::IF, 0);
}

std::vector<tree::TerminalNode *> PivotParser::If_elif_elseContext::SEP() {
  return getTokens(PivotParser::SEP);
}

tree::TerminalNode* PivotParser::If_elif_elseContext::SEP(size_t i) {
  return getToken(PivotParser::SEP, i);
}

std::vector<tree::TerminalNode *> PivotParser::If_elif_elseContext::NEWLINE() {
  return getTokens(PivotParser::NEWLINE);
}

tree::TerminalNode* PivotParser::If_elif_elseContext::NEWLINE(size_t i) {
  return getToken(PivotParser::NEWLINE, i);
}

tree::TerminalNode* PivotParser::If_elif_elseContext::END() {
  return getToken(PivotParser::END, 0);
}

std::vector<PivotParser::Boolean_expressionContext *> PivotParser::If_elif_elseContext::boolean_expression() {
  return getRuleContexts<PivotParser::Boolean_expressionContext>();
}

PivotParser::Boolean_expressionContext* PivotParser::If_elif_elseContext::boolean_expression(size_t i) {
  return getRuleContext<PivotParser::Boolean_expressionContext>(i);
}

std::vector<PivotParser::StatementsContext *> PivotParser::If_elif_elseContext::statements() {
  return getRuleContexts<PivotParser::StatementsContext>();
}

PivotParser::StatementsContext* PivotParser::If_elif_elseContext::statements(size_t i) {
  return getRuleContext<PivotParser::StatementsContext>(i);
}

std::vector<tree::TerminalNode *> PivotParser::If_elif_elseContext::ELIF() {
  return getTokens(PivotParser::ELIF);
}

tree::TerminalNode* PivotParser::If_elif_elseContext::ELIF(size_t i) {
  return getToken(PivotParser::ELIF, i);
}

tree::TerminalNode* PivotParser::If_elif_elseContext::ELSE() {
  return getToken(PivotParser::ELSE, 0);
}


size_t PivotParser::If_elif_elseContext::getRuleIndex() const {
  return PivotParser::RuleIf_elif_else;
}

antlrcpp::Any PivotParser::If_elif_elseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitIf_elif_else(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::If_elif_elseContext* PivotParser::if_elif_else() {
  If_elif_elseContext *_localctx = _tracker.createInstance<If_elif_elseContext>(_ctx, getState());
  enterRule(_localctx, 24, PivotParser::RuleIf_elif_else);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(PivotParser::IF);
    setState(136);
    dynamic_cast<If_elif_elseContext *>(_localctx)->if_condition = boolean_expression();
    setState(137);
    match(PivotParser::SEP);
    setState(138);
    match(PivotParser::NEWLINE);
    setState(139);
    dynamic_cast<If_elif_elseContext *>(_localctx)->if_block = statements();
    setState(148);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::ELIF) {
      setState(140);
      match(PivotParser::ELIF);
      setState(141);
      dynamic_cast<If_elif_elseContext *>(_localctx)->boolean_expressionContext = boolean_expression();
      dynamic_cast<If_elif_elseContext *>(_localctx)->elif_condition.push_back(dynamic_cast<If_elif_elseContext *>(_localctx)->boolean_expressionContext);
      setState(142);
      match(PivotParser::SEP);
      setState(143);
      match(PivotParser::NEWLINE);
      setState(144);
      dynamic_cast<If_elif_elseContext *>(_localctx)->statementsContext = statements();
      dynamic_cast<If_elif_elseContext *>(_localctx)->elif_block.push_back(dynamic_cast<If_elif_elseContext *>(_localctx)->statementsContext);
      setState(150);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::ELSE) {
      setState(151);
      match(PivotParser::ELSE);
      setState(152);
      match(PivotParser::SEP);
      setState(153);
      match(PivotParser::NEWLINE);
      setState(154);
      dynamic_cast<If_elif_elseContext *>(_localctx)->else_block = statements();
    }
    setState(157);
    match(PivotParser::END);
   
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
  enterRule(_localctx, 26, PivotParser::RuleBoolean_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext = boolean_and();
    dynamic_cast<Boolean_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext);
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::OR) {
      setState(160);
      match(PivotParser::OR);
      setState(161);
      dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext = boolean_and();
      dynamic_cast<Boolean_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext);
      setState(166);
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

std::vector<PivotParser::Boolean_comparatorContext *> PivotParser::Boolean_andContext::boolean_comparator() {
  return getRuleContexts<PivotParser::Boolean_comparatorContext>();
}

PivotParser::Boolean_comparatorContext* PivotParser::Boolean_andContext::boolean_comparator(size_t i) {
  return getRuleContext<PivotParser::Boolean_comparatorContext>(i);
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
  enterRule(_localctx, 28, PivotParser::RuleBoolean_and);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext = boolean_comparator();
    dynamic_cast<Boolean_andContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext);
    setState(172);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::AND) {
      setState(168);
      match(PivotParser::AND);
      setState(169);
      dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext = boolean_comparator();
      dynamic_cast<Boolean_andContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext);
      setState(174);
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

//----------------- Boolean_comparatorContext ------------------------------------------------------------------

PivotParser::Boolean_comparatorContext::Boolean_comparatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PivotParser::Boolean_notContext *> PivotParser::Boolean_comparatorContext::boolean_not() {
  return getRuleContexts<PivotParser::Boolean_notContext>();
}

PivotParser::Boolean_notContext* PivotParser::Boolean_comparatorContext::boolean_not(size_t i) {
  return getRuleContext<PivotParser::Boolean_notContext>(i);
}

tree::TerminalNode* PivotParser::Boolean_comparatorContext::EQU() {
  return getToken(PivotParser::EQU, 0);
}

tree::TerminalNode* PivotParser::Boolean_comparatorContext::DIF() {
  return getToken(PivotParser::DIF, 0);
}

tree::TerminalNode* PivotParser::Boolean_comparatorContext::LT() {
  return getToken(PivotParser::LT, 0);
}

tree::TerminalNode* PivotParser::Boolean_comparatorContext::GT() {
  return getToken(PivotParser::GT, 0);
}

tree::TerminalNode* PivotParser::Boolean_comparatorContext::LEQ() {
  return getToken(PivotParser::LEQ, 0);
}

tree::TerminalNode* PivotParser::Boolean_comparatorContext::GEQ() {
  return getToken(PivotParser::GEQ, 0);
}


size_t PivotParser::Boolean_comparatorContext::getRuleIndex() const {
  return PivotParser::RuleBoolean_comparator;
}

antlrcpp::Any PivotParser::Boolean_comparatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitBoolean_comparator(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Boolean_comparatorContext* PivotParser::boolean_comparator() {
  Boolean_comparatorContext *_localctx = _tracker.createInstance<Boolean_comparatorContext>(_ctx, getState());
  enterRule(_localctx, 30, PivotParser::RuleBoolean_comparator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    dynamic_cast<Boolean_comparatorContext *>(_localctx)->left = boolean_not();
    setState(178);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PivotParser::EQU)
      | (1ULL << PivotParser::DIF)
      | (1ULL << PivotParser::LT)
      | (1ULL << PivotParser::GT)
      | (1ULL << PivotParser::LEQ)
      | (1ULL << PivotParser::GEQ))) != 0)) {
      setState(176);
      dynamic_cast<Boolean_comparatorContext *>(_localctx)->comparator = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PivotParser::EQU)
        | (1ULL << PivotParser::DIF)
        | (1ULL << PivotParser::LT)
        | (1ULL << PivotParser::GT)
        | (1ULL << PivotParser::LEQ)
        | (1ULL << PivotParser::GEQ))) != 0))) {
        dynamic_cast<Boolean_comparatorContext *>(_localctx)->comparator = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(177);
      dynamic_cast<Boolean_comparatorContext *>(_localctx)->right = boolean_not();
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
  enterRule(_localctx, 32, PivotParser::RuleBoolean_not);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::NOT) {
      setState(180);
      match(PivotParser::NOT);
    }
    setState(183);
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
  enterRule(_localctx, 34, PivotParser::RuleBoolean_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::TRUE: {
        enterOuterAlt(_localctx, 1);
        setState(185);
        match(PivotParser::TRUE);
        break;
      }

      case PivotParser::FALSE: {
        enterOuterAlt(_localctx, 2);
        setState(186);
        match(PivotParser::FALSE);
        break;
      }

      case PivotParser::LPAR: {
        enterOuterAlt(_localctx, 3);
        setState(187);
        match(PivotParser::LPAR);
        setState(188);
        boolean_expression();
        setState(189);
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
  "file", "statements", "statement", "action", "loop", "while_loop", "until_loop", 
  "numeric_expression", "numeric_mul_div", "numeric_pow", "numeric_inversion", 
  "numeric_atom", "if_elif_else", "boolean_expression", "boolean_and", "boolean_comparator", 
  "boolean_not", "boolean_atom"
};

std::vector<std::string> PivotParser::_literalNames = {
  "", "", "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'&&'", "'||'", 
  "'!'", "'='", "'('", "')'", "':'", "'+'", "'-'", "'/'", "'*'", "'^'", 
  "','", "'.'", "'<-'", "", "", "'forward'", "'backward'", "'left'", "'right'", 
  "'stop'", "'duration'", "'speed'", "'wait'", "'loop'", "'times'", "'end'", 
  "'if'", "'elif'", "'else'", "'true'", "'false'", "'while'", "'until'"
};

std::vector<std::string> PivotParser::_symbolicNames = {
  "", "NUMBER", "EQU", "DIF", "LT", "GT", "LEQ", "GEQ", "AND", "OR", "NOT", 
  "AFF", "LPAR", "RPAR", "SEP", "PLUS", "MINUS", "DIV", "STAR", "POW", "COMMA", 
  "DOT", "SET", "NEWLINE", "WHITESPACE", "FORWARD", "BACKWARD", "LEFT", 
  "RIGHT", "STOP", "DURATION", "SPEED", "WAIT", "LOOP", "TIMES", "END", 
  "IF", "ELIF", "ELSE", "TRUE", "FALSE", "WHILE", "UNTIL"
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
    0x3, 0x2c, 0xc4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x30, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x34, 0xa, 0x3, 0x5, 0x3, 
    0x36, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x3d, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x46, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4d, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x69, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0x6c, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x71, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0x74, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x79, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x7c, 0xb, 0xb, 0x3, 0xc, 
    0x5, 0xc, 0x7f, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x88, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x95, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x98, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x9e, 0xa, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xa5, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xa8, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x7, 0x10, 0xad, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xb0, 0xb, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xb5, 0xa, 0x11, 0x3, 
    0x12, 0x5, 0x12, 0xb8, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xc2, 0xa, 
    0x13, 0x3, 0x13, 0x2, 0x2, 0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 
    0x6, 0x3, 0x2, 0x1b, 0x1e, 0x3, 0x2, 0x11, 0x12, 0x3, 0x2, 0x13, 0x14, 
    0x3, 0x2, 0x4, 0x9, 0x2, 0xc8, 0x2, 0x26, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x4e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x65, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x75, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x87, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x22, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x5, 0x4, 0x3, 0x2, 
    0x27, 0x28, 0x7, 0x2, 0x2, 0x3, 0x28, 0x3, 0x3, 0x2, 0x2, 0x2, 0x29, 
    0x2a, 0x5, 0x6, 0x4, 0x2, 0x2a, 0x2b, 0x7, 0x19, 0x2, 0x2, 0x2b, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x35, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x33, 0x5, 0x6, 0x4, 0x2, 0x32, 0x34, 0x7, 0x19, 0x2, 0x2, 
    0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x31, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x5, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3d, 0x5, 
    0x8, 0x5, 0x2, 0x38, 0x3d, 0x5, 0xa, 0x6, 0x2, 0x39, 0x3d, 0x5, 0xc, 
    0x7, 0x2, 0x3a, 0x3d, 0x5, 0xe, 0x8, 0x2, 0x3b, 0x3d, 0x5, 0x1a, 0xe, 
    0x2, 0x3c, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x38, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 
    0x9, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x20, 0x2, 0x2, 0x40, 0x41, 0x7, 
    0xd, 0x2, 0x2, 0x41, 0x45, 0x5, 0x10, 0x9, 0x2, 0x42, 0x43, 0x7, 0x21, 
    0x2, 0x2, 0x43, 0x44, 0x7, 0xd, 0x2, 0x2, 0x44, 0x46, 0x5, 0x10, 0x9, 
    0x2, 0x45, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 
    0x46, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4d, 0x7, 0x1f, 0x2, 0x2, 0x48, 
    0x49, 0x7, 0x22, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x20, 0x2, 0x2, 0x4a, 0x4b, 
    0x7, 0xd, 0x2, 0x2, 0x4b, 0x4d, 0x5, 0x10, 0x9, 0x2, 0x4c, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x23, 0x2, 
    0x2, 0x4f, 0x50, 0x7, 0x24, 0x2, 0x2, 0x50, 0x51, 0x7, 0xd, 0x2, 0x2, 
    0x51, 0x52, 0x5, 0x10, 0x9, 0x2, 0x52, 0x53, 0x7, 0x10, 0x2, 0x2, 0x53, 
    0x54, 0x7, 0x19, 0x2, 0x2, 0x54, 0x55, 0x5, 0x4, 0x3, 0x2, 0x55, 0x56, 
    0x7, 0x25, 0x2, 0x2, 0x56, 0xb, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 
    0x2b, 0x2, 0x2, 0x58, 0x59, 0x5, 0x1c, 0xf, 0x2, 0x59, 0x5a, 0x7, 0x10, 
    0x2, 0x2, 0x5a, 0x5b, 0x7, 0x19, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x4, 0x3, 
    0x2, 0x5c, 0x5d, 0x7, 0x25, 0x2, 0x2, 0x5d, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x5f, 0x7, 0x2c, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x1c, 0xf, 0x2, 0x60, 
    0x61, 0x7, 0x10, 0x2, 0x2, 0x61, 0x62, 0x7, 0x19, 0x2, 0x2, 0x62, 0x63, 
    0x5, 0x4, 0x3, 0x2, 0x63, 0x64, 0x7, 0x25, 0x2, 0x2, 0x64, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x6a, 0x5, 0x12, 0xa, 0x2, 0x66, 0x67, 0x9, 0x3, 
    0x2, 0x2, 0x67, 0x69, 0x5, 0x12, 0xa, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6a, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x72, 0x5, 0x14, 0xb, 0x2, 0x6e, 0x6f, 
    0x9, 0x4, 0x2, 0x2, 0x6f, 0x71, 0x5, 0x14, 0xb, 0x2, 0x70, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x7a, 0x5, 0x16, 0xc, 0x2, 
    0x76, 0x77, 0x7, 0x15, 0x2, 0x2, 0x77, 0x79, 0x5, 0x16, 0xc, 0x2, 0x78, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7f, 0x7, 0x12, 
    0x2, 0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x5, 0x18, 0xd, 0x2, 
    0x81, 0x17, 0x3, 0x2, 0x2, 0x2, 0x82, 0x88, 0x7, 0x3, 0x2, 0x2, 0x83, 
    0x84, 0x7, 0xe, 0x2, 0x2, 0x84, 0x85, 0x5, 0x10, 0x9, 0x2, 0x85, 0x86, 
    0x7, 0xf, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x83, 0x3, 0x2, 0x2, 0x2, 0x88, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8a, 0x7, 0x26, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x1c, 0xf, 
    0x2, 0x8b, 0x8c, 0x7, 0x10, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x19, 0x2, 0x2, 
    0x8d, 0x96, 0x5, 0x4, 0x3, 0x2, 0x8e, 0x8f, 0x7, 0x27, 0x2, 0x2, 0x8f, 
    0x90, 0x5, 0x1c, 0xf, 0x2, 0x90, 0x91, 0x7, 0x10, 0x2, 0x2, 0x91, 0x92, 
    0x7, 0x19, 0x2, 0x2, 0x92, 0x93, 0x5, 0x4, 0x3, 0x2, 0x93, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x95, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9a, 0x7, 0x28, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x10, 0x2, 0x2, 0x9b, 
    0x9c, 0x7, 0x19, 0x2, 0x2, 0x9c, 0x9e, 0x5, 0x4, 0x3, 0x2, 0x9d, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x25, 0x2, 0x2, 0xa0, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0xa6, 0x5, 0x1e, 0x10, 0x2, 0xa2, 0xa3, 0x7, 0xb, 0x2, 
    0x2, 0xa3, 0xa5, 0x5, 0x1e, 0x10, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0xae, 0x5, 0x20, 0x11, 0x2, 0xaa, 0xab, 0x7, 
    0xa, 0x2, 0x2, 0xab, 0xad, 0x5, 0x20, 0x11, 0x2, 0xac, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb4, 0x5, 0x22, 0x12, 0x2, 0xb2, 
    0xb3, 0x9, 0x5, 0x2, 0x2, 0xb3, 0xb5, 0x5, 0x22, 0x12, 0x2, 0xb4, 0xb2, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0xc, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0xba, 0x5, 0x24, 0x13, 0x2, 0xba, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xc2, 0x7, 0x29, 0x2, 0x2, 0xbc, 0xc2, 0x7, 0x2a, 0x2, 0x2, 0xbd, 
    0xbe, 0x7, 0xe, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x1c, 0xf, 0x2, 0xbf, 0xc0, 
    0x7, 0xf, 0x2, 0x2, 0xc0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x14, 0x2e, 0x33, 0x35, 0x3c, 
    0x45, 0x4c, 0x6a, 0x72, 0x7a, 0x7e, 0x87, 0x96, 0x9d, 0xa6, 0xae, 0xb4, 
    0xb7, 0xc1, 
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
