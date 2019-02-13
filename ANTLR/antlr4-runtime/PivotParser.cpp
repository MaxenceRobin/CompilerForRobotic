
// Generated from .\Pivot.g4 by ANTLR 4.7.1


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

tree::TerminalNode* PivotParser::FileContext::NEWLINE() {
  return getToken(PivotParser::NEWLINE, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::NEWLINE) {
      setState(42);
      match(PivotParser::NEWLINE);
    }
    setState(45);
    statements();
    setState(46);
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
    setState(53);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(48);
        statement();
        setState(49);
        match(PivotParser::NEWLINE); 
      }
      setState(55);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(57);
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
      | (1ULL << PivotParser::UNTIL)
      | (1ULL << PivotParser::LED)
      | (1ULL << PivotParser::VAR)
      | (1ULL << PivotParser::VARIABLE))) != 0)) {
      setState(56);
      statement();
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

PivotParser::DeclarationContext* PivotParser::StatementContext::declaration() {
  return getRuleContext<PivotParser::DeclarationContext>(0);
}

PivotParser::AssignmentContext* PivotParser::StatementContext::assignment() {
  return getRuleContext<PivotParser::AssignmentContext>(0);
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
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::FORWARD:
      case PivotParser::BACKWARD:
      case PivotParser::LEFT:
      case PivotParser::RIGHT:
      case PivotParser::STOP:
      case PivotParser::WAIT:
      case PivotParser::LED: {
        enterOuterAlt(_localctx, 1);
        setState(59);
        action();
        break;
      }

      case PivotParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(60);
        declaration();
        break;
      }

      case PivotParser::VARIABLE: {
        enterOuterAlt(_localctx, 3);
        setState(61);
        assignment();
        break;
      }

      case PivotParser::LOOP: {
        enterOuterAlt(_localctx, 4);
        setState(62);
        loop();
        break;
      }

      case PivotParser::WHILE: {
        enterOuterAlt(_localctx, 5);
        setState(63);
        while_loop();
        break;
      }

      case PivotParser::UNTIL: {
        enterOuterAlt(_localctx, 6);
        setState(64);
        until_loop();
        break;
      }

      case PivotParser::IF: {
        enterOuterAlt(_localctx, 7);
        setState(65);
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

tree::TerminalNode* PivotParser::ActionContext::SLOW() {
  return getToken(PivotParser::SLOW, 0);
}

tree::TerminalNode* PivotParser::ActionContext::NORMAL() {
  return getToken(PivotParser::NORMAL, 0);
}

tree::TerminalNode* PivotParser::ActionContext::FAST() {
  return getToken(PivotParser::FAST, 0);
}

tree::TerminalNode* PivotParser::ActionContext::STOP() {
  return getToken(PivotParser::STOP, 0);
}

tree::TerminalNode* PivotParser::ActionContext::WAIT() {
  return getToken(PivotParser::WAIT, 0);
}

PivotParser::Numeric_expressionContext* PivotParser::ActionContext::numeric_expression() {
  return getRuleContext<PivotParser::Numeric_expressionContext>(0);
}

tree::TerminalNode* PivotParser::ActionContext::LED() {
  return getToken(PivotParser::LED, 0);
}

tree::TerminalNode* PivotParser::ActionContext::RGB() {
  return getToken(PivotParser::RGB, 0);
}

tree::TerminalNode* PivotParser::ActionContext::RANDOMCOLOR() {
  return getToken(PivotParser::RANDOMCOLOR, 0);
}

tree::TerminalNode* PivotParser::ActionContext::VARIABLE() {
  return getToken(PivotParser::VARIABLE, 0);
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
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::FORWARD:
      case PivotParser::BACKWARD:
      case PivotParser::LEFT:
      case PivotParser::RIGHT: {
        enterOuterAlt(_localctx, 1);
        setState(68);
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
        setState(69);
        dynamic_cast<ActionContext *>(_localctx)->move_speed = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PivotParser::NORMAL)
          | (1ULL << PivotParser::SLOW)
          | (1ULL << PivotParser::FAST))) != 0))) {
          dynamic_cast<ActionContext *>(_localctx)->move_speed = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case PivotParser::STOP: {
        enterOuterAlt(_localctx, 2);
        setState(70);
        match(PivotParser::STOP);
        break;
      }

      case PivotParser::WAIT: {
        enterOuterAlt(_localctx, 3);
        setState(71);
        match(PivotParser::WAIT);
        setState(72);
        dynamic_cast<ActionContext *>(_localctx)->duration = numeric_expression();
        break;
      }

      case PivotParser::LED: {
        enterOuterAlt(_localctx, 4);
        setState(73);
        match(PivotParser::LED);
        setState(74);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PivotParser::RANDOMCOLOR)
          | (1ULL << PivotParser::RGB)
          | (1ULL << PivotParser::VARIABLE))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
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

//----------------- DeclarationContext ------------------------------------------------------------------

PivotParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::DeclarationContext::VAR() {
  return getToken(PivotParser::VAR, 0);
}

tree::TerminalNode* PivotParser::DeclarationContext::SEMICOLON() {
  return getToken(PivotParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> PivotParser::DeclarationContext::VARIABLE() {
  return getTokens(PivotParser::VARIABLE);
}

tree::TerminalNode* PivotParser::DeclarationContext::VARIABLE(size_t i) {
  return getToken(PivotParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> PivotParser::DeclarationContext::COMMA() {
  return getTokens(PivotParser::COMMA);
}

tree::TerminalNode* PivotParser::DeclarationContext::COMMA(size_t i) {
  return getToken(PivotParser::COMMA, i);
}


size_t PivotParser::DeclarationContext::getRuleIndex() const {
  return PivotParser::RuleDeclaration;
}

antlrcpp::Any PivotParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::DeclarationContext* PivotParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, PivotParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(PivotParser::VAR);
    setState(78);
    dynamic_cast<DeclarationContext *>(_localctx)->variableToken = match(PivotParser::VARIABLE);
    dynamic_cast<DeclarationContext *>(_localctx)->var_name.push_back(dynamic_cast<DeclarationContext *>(_localctx)->variableToken);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::COMMA) {
      setState(79);
      match(PivotParser::COMMA);
      setState(80);
      dynamic_cast<DeclarationContext *>(_localctx)->variableToken = match(PivotParser::VARIABLE);
      dynamic_cast<DeclarationContext *>(_localctx)->var_name.push_back(dynamic_cast<DeclarationContext *>(_localctx)->variableToken);
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(86);
    match(PivotParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

PivotParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::AssignmentContext::VARIABLE() {
  return getToken(PivotParser::VARIABLE, 0);
}

tree::TerminalNode* PivotParser::AssignmentContext::AFF() {
  return getToken(PivotParser::AFF, 0);
}

PivotParser::ExpressionContext* PivotParser::AssignmentContext::expression() {
  return getRuleContext<PivotParser::ExpressionContext>(0);
}


size_t PivotParser::AssignmentContext::getRuleIndex() const {
  return PivotParser::RuleAssignment;
}

antlrcpp::Any PivotParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::AssignmentContext* PivotParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 10, PivotParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(PivotParser::VARIABLE);
    setState(89);
    match(PivotParser::AFF);
    setState(90);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PivotParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PivotParser::Numeric_expressionContext* PivotParser::ExpressionContext::numeric_expression() {
  return getRuleContext<PivotParser::Numeric_expressionContext>(0);
}

PivotParser::Boolean_expressionContext* PivotParser::ExpressionContext::boolean_expression() {
  return getRuleContext<PivotParser::Boolean_expressionContext>(0);
}

tree::TerminalNode* PivotParser::ExpressionContext::RGB() {
  return getToken(PivotParser::RGB, 0);
}


size_t PivotParser::ExpressionContext::getRuleIndex() const {
  return PivotParser::RuleExpression;
}

antlrcpp::Any PivotParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::ExpressionContext* PivotParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 12, PivotParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      numeric_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(93);
      boolean_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(94);
      match(PivotParser::RGB);
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

//----------------- LoopContext ------------------------------------------------------------------

PivotParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::LoopContext::LOOP() {
  return getToken(PivotParser::LOOP, 0);
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
  enterRule(_localctx, 14, PivotParser::RuleLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(PivotParser::LOOP);
    setState(98);
    dynamic_cast<LoopContext *>(_localctx)->repetition_number = numeric_expression();
    setState(99);
    match(PivotParser::SEP);
    setState(100);
    match(PivotParser::NEWLINE);
    setState(101);
    statements();
    setState(102);
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
  enterRule(_localctx, 16, PivotParser::RuleWhile_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(PivotParser::WHILE);
    setState(105);
    dynamic_cast<While_loopContext *>(_localctx)->condition = boolean_expression();
    setState(106);
    match(PivotParser::SEP);
    setState(107);
    match(PivotParser::NEWLINE);
    setState(108);
    statements();
    setState(109);
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
  enterRule(_localctx, 18, PivotParser::RuleUntil_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(PivotParser::UNTIL);
    setState(112);
    dynamic_cast<Until_loopContext *>(_localctx)->condition = boolean_expression();
    setState(113);
    match(PivotParser::SEP);
    setState(114);
    match(PivotParser::NEWLINE);
    setState(115);
    statements();
    setState(116);
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
  enterRule(_localctx, 20, PivotParser::RuleNumeric_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
    dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::PLUS

    || _la == PivotParser::MINUS) {
      setState(119);
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
      setState(120);
      dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
      dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
      setState(125);
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
  enterRule(_localctx, 22, PivotParser::RuleNumeric_mul_div);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::DIV

    || _la == PivotParser::STAR) {
      setState(127);
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
      setState(128);
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
      setState(133);
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
  enterRule(_localctx, 24, PivotParser::RuleNumeric_pow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext = numeric_inversion();
    dynamic_cast<Numeric_powContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext);
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::POW) {
      setState(135);
      match(PivotParser::POW);
      setState(136);
      dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext = numeric_inversion();
      dynamic_cast<Numeric_powContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext);
      setState(141);
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
  enterRule(_localctx, 26, PivotParser::RuleNumeric_inversion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::MINUS) {
      setState(142);
      match(PivotParser::MINUS);
    }
    setState(145);
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

tree::TerminalNode* PivotParser::Numeric_atomContext::VARIABLE() {
  return getToken(PivotParser::VARIABLE, 0);
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
  enterRule(_localctx, 28, PivotParser::RuleNumeric_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(147);
        match(PivotParser::NUMBER);
        break;
      }

      case PivotParser::VARIABLE: {
        enterOuterAlt(_localctx, 2);
        setState(148);
        match(PivotParser::VARIABLE);
        break;
      }

      case PivotParser::LPAR: {
        enterOuterAlt(_localctx, 3);
        setState(149);
        match(PivotParser::LPAR);
        setState(150);
        numeric_expression();
        setState(151);
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
  enterRule(_localctx, 30, PivotParser::RuleIf_elif_else);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(PivotParser::IF);
    setState(156);
    dynamic_cast<If_elif_elseContext *>(_localctx)->if_condition = boolean_expression();
    setState(157);
    match(PivotParser::SEP);
    setState(158);
    match(PivotParser::NEWLINE);
    setState(159);
    dynamic_cast<If_elif_elseContext *>(_localctx)->if_block = statements();
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::ELIF) {
      setState(160);
      match(PivotParser::ELIF);
      setState(161);
      dynamic_cast<If_elif_elseContext *>(_localctx)->boolean_expressionContext = boolean_expression();
      dynamic_cast<If_elif_elseContext *>(_localctx)->elif_condition.push_back(dynamic_cast<If_elif_elseContext *>(_localctx)->boolean_expressionContext);
      setState(162);
      match(PivotParser::SEP);
      setState(163);
      match(PivotParser::NEWLINE);
      setState(164);
      dynamic_cast<If_elif_elseContext *>(_localctx)->statementsContext = statements();
      dynamic_cast<If_elif_elseContext *>(_localctx)->elif_block.push_back(dynamic_cast<If_elif_elseContext *>(_localctx)->statementsContext);
      setState(170);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(175);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::ELSE) {
      setState(171);
      match(PivotParser::ELSE);
      setState(172);
      match(PivotParser::SEP);
      setState(173);
      match(PivotParser::NEWLINE);
      setState(174);
      dynamic_cast<If_elif_elseContext *>(_localctx)->else_block = statements();
    }
    setState(177);
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
  enterRule(_localctx, 32, PivotParser::RuleBoolean_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext = boolean_and();
    dynamic_cast<Boolean_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::OR) {
      setState(180);
      match(PivotParser::OR);
      setState(181);
      dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext = boolean_and();
      dynamic_cast<Boolean_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext);
      setState(186);
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
  enterRule(_localctx, 34, PivotParser::RuleBoolean_and);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext = boolean_comparator();
    dynamic_cast<Boolean_andContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext);
    setState(192);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::AND) {
      setState(188);
      match(PivotParser::AND);
      setState(189);
      dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext = boolean_comparator();
      dynamic_cast<Boolean_andContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext);
      setState(194);
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
  enterRule(_localctx, 36, PivotParser::RuleBoolean_comparator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    dynamic_cast<Boolean_comparatorContext *>(_localctx)->left = boolean_not();
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PivotParser::EQU)
      | (1ULL << PivotParser::DIF)
      | (1ULL << PivotParser::LT)
      | (1ULL << PivotParser::GT)
      | (1ULL << PivotParser::LEQ)
      | (1ULL << PivotParser::GEQ))) != 0)) {
      setState(196);
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
      setState(197);
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
  enterRule(_localctx, 38, PivotParser::RuleBoolean_not);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::NOT) {
      setState(200);
      match(PivotParser::NOT);
    }
    setState(203);
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

tree::TerminalNode* PivotParser::Boolean_atomContext::VARIABLE() {
  return getToken(PivotParser::VARIABLE, 0);
}

PivotParser::Numeric_expressionContext* PivotParser::Boolean_atomContext::numeric_expression() {
  return getRuleContext<PivotParser::Numeric_expressionContext>(0);
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
  enterRule(_localctx, 40, PivotParser::RuleBoolean_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(205);
      match(PivotParser::TRUE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(206);
      match(PivotParser::FALSE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(207);
      match(PivotParser::VARIABLE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(208);
      numeric_expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(209);
      match(PivotParser::LPAR);
      setState(210);
      boolean_expression();
      setState(211);
      match(PivotParser::RPAR);
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

// Static vars and initialization.
std::vector<dfa::DFA> PivotParser::_decisionToDFA;
atn::PredictionContextCache PivotParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PivotParser::_atn;
std::vector<uint16_t> PivotParser::_serializedATN;

std::vector<std::string> PivotParser::_ruleNames = {
  "file", "statements", "statement", "action", "declaration", "assignment", 
  "expression", "loop", "while_loop", "until_loop", "numeric_expression", 
  "numeric_mul_div", "numeric_pow", "numeric_inversion", "numeric_atom", 
  "if_elif_else", "boolean_expression", "boolean_and", "boolean_comparator", 
  "boolean_not", "boolean_atom"
};

std::vector<std::string> PivotParser::_literalNames = {
  "", "'forward'", "'backward'", "'left'", "'right'", "'stop'", "'duration'", 
  "'normal'", "'slow'", "'fast'", "'wait'", "'loop'", "'end'", "'if'", "'elif'", 
  "'else'", "'true'", "'false'", "'while'", "'until'", "'led'", "'randomColor'", 
  "'var'", "", "", "", "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'&&'", 
  "'||'", "'!'", "'='", "'('", "')'", "':'", "'+'", "'-'", "'/'", "'*'", 
  "'^'", "','", "';'", "'.'"
};

std::vector<std::string> PivotParser::_symbolicNames = {
  "", "FORWARD", "BACKWARD", "LEFT", "RIGHT", "STOP", "DURATION", "NORMAL", 
  "SLOW", "FAST", "WAIT", "LOOP", "END", "IF", "ELIF", "ELSE", "TRUE", "FALSE", 
  "WHILE", "UNTIL", "LED", "RANDOMCOLOR", "VAR", "NUMBER", "RGB", "VARIABLE", 
  "EQU", "DIF", "LT", "GT", "LEQ", "GEQ", "AND", "OR", "NOT", "AFF", "LPAR", 
  "RPAR", "SEP", "PLUS", "MINUS", "DIV", "STAR", "POW", "COMMA", "SEMICOLON", 
  "DOT", "NEWLINE", "WHITESPACE"
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
    0x3, 0x32, 0xda, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x5, 0x2, 0x2e, 0xa, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x36, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x39, 0xb, 0x3, 0x3, 0x3, 0x5, 0x3, 0x3c, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x45, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4e, 0xa, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x54, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x57, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x62, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x7c, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0x7f, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x84, 0xa, 0xd, 
    0xc, 0xd, 0xe, 0xd, 0x87, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 
    0xe, 0x8c, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x8f, 0xb, 0xe, 0x3, 0xf, 0x5, 
    0xf, 0x92, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x9c, 0xa, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xa9, 0xa, 0x11, 
    0xc, 0x11, 0xe, 0x11, 0xac, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0xb2, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xb9, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
    0xbc, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xc1, 0xa, 
    0x13, 0xc, 0x13, 0xe, 0x13, 0xc4, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0xc9, 0xa, 0x14, 0x3, 0x15, 0x5, 0x15, 0xcc, 0xa, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xd8, 0xa, 0x16, 0x3, 
    0x16, 0x2, 0x2, 0x17, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2, 0x8, 0x3, 0x2, 0x3, 0x6, 0x3, 0x2, 0x9, 0xb, 0x4, 0x2, 0x17, 0x17, 
    0x1a, 0x1b, 0x3, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x1c, 
    0x21, 0x2, 0xe3, 0x2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x44, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x4f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5a, 0x3, 0x2, 0x2, 0x2, 0xe, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x63, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x71, 0x3, 0x2, 0x2, 0x2, 0x16, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x80, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x91, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x22, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x28, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e, 0x7, 
    0x31, 0x2, 0x2, 0x2d, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x5, 0x4, 0x3, 
    0x2, 0x30, 0x31, 0x7, 0x2, 0x2, 0x3, 0x31, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x33, 0x5, 0x6, 0x4, 0x2, 0x33, 0x34, 0x7, 0x31, 0x2, 0x2, 0x34, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x32, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x3c, 0x5, 0x6, 0x4, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x3d, 0x45, 0x5, 0x8, 0x5, 0x2, 0x3e, 0x45, 0x5, 0xa, 0x6, 0x2, 0x3f, 
    0x45, 0x5, 0xc, 0x7, 0x2, 0x40, 0x45, 0x5, 0x10, 0x9, 0x2, 0x41, 0x45, 
    0x5, 0x12, 0xa, 0x2, 0x42, 0x45, 0x5, 0x14, 0xb, 0x2, 0x43, 0x45, 0x5, 
    0x20, 0x11, 0x2, 0x44, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x44, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x44, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x7, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x9, 0x2, 0x2, 0x2, 0x47, 0x4e, 0x9, 0x3, 0x2, 0x2, 0x48, 0x4e, 
    0x7, 0x7, 0x2, 0x2, 0x49, 0x4a, 0x7, 0xc, 0x2, 0x2, 0x4a, 0x4e, 0x5, 
    0x16, 0xc, 0x2, 0x4b, 0x4c, 0x7, 0x16, 0x2, 0x2, 0x4c, 0x4e, 0x9, 0x4, 
    0x2, 0x2, 0x4d, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x18, 0x2, 0x2, 0x50, 
    0x55, 0x7, 0x1b, 0x2, 0x2, 0x51, 0x52, 0x7, 0x2e, 0x2, 0x2, 0x52, 0x54, 
    0x7, 0x1b, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x59, 0x7, 0x2f, 0x2, 0x2, 0x59, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5b, 0x7, 0x1b, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x25, 0x2, 0x2, 0x5c, 
    0x5d, 0x5, 0xe, 0x8, 0x2, 0x5d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x62, 
    0x5, 0x16, 0xc, 0x2, 0x5f, 0x62, 0x5, 0x22, 0x12, 0x2, 0x60, 0x62, 0x7, 
    0x1a, 0x2, 0x2, 0x61, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x64, 0x7, 0xd, 0x2, 0x2, 0x64, 0x65, 0x5, 0x16, 0xc, 0x2, 
    0x65, 0x66, 0x7, 0x28, 0x2, 0x2, 0x66, 0x67, 0x7, 0x31, 0x2, 0x2, 0x67, 
    0x68, 0x5, 0x4, 0x3, 0x2, 0x68, 0x69, 0x7, 0xe, 0x2, 0x2, 0x69, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x14, 0x2, 0x2, 0x6b, 0x6c, 0x5, 
    0x22, 0x12, 0x2, 0x6c, 0x6d, 0x7, 0x28, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x31, 
    0x2, 0x2, 0x6e, 0x6f, 0x5, 0x4, 0x3, 0x2, 0x6f, 0x70, 0x7, 0xe, 0x2, 
    0x2, 0x70, 0x13, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x15, 0x2, 0x2, 
    0x72, 0x73, 0x5, 0x22, 0x12, 0x2, 0x73, 0x74, 0x7, 0x28, 0x2, 0x2, 0x74, 
    0x75, 0x7, 0x31, 0x2, 0x2, 0x75, 0x76, 0x5, 0x4, 0x3, 0x2, 0x76, 0x77, 
    0x7, 0xe, 0x2, 0x2, 0x77, 0x15, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7d, 0x5, 
    0x18, 0xd, 0x2, 0x79, 0x7a, 0x9, 0x5, 0x2, 0x2, 0x7a, 0x7c, 0x5, 0x18, 
    0xd, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x85, 0x5, 0x1a, 0xe, 0x2, 0x81, 0x82, 0x9, 0x6, 0x2, 0x2, 0x82, 0x84, 
    0x5, 0x1a, 0xe, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x19, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x8d, 0x5, 0x1c, 0xf, 0x2, 0x89, 0x8a, 0x7, 0x2d, 0x2, 0x2, 
    0x8a, 0x8c, 0x5, 0x1c, 0xf, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 0x2a, 0x2, 0x2, 0x91, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x93, 0x94, 0x5, 0x1e, 0x10, 0x2, 0x94, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x95, 0x9c, 0x7, 0x19, 0x2, 0x2, 0x96, 0x9c, 0x7, 0x1b, 0x2, 0x2, 0x97, 
    0x98, 0x7, 0x26, 0x2, 0x2, 0x98, 0x99, 0x5, 0x16, 0xc, 0x2, 0x99, 0x9a, 
    0x7, 0x27, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x9b, 0x96, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0xf, 0x2, 
    0x2, 0x9e, 0x9f, 0x5, 0x22, 0x12, 0x2, 0x9f, 0xa0, 0x7, 0x28, 0x2, 0x2, 
    0xa0, 0xa1, 0x7, 0x31, 0x2, 0x2, 0xa1, 0xaa, 0x5, 0x4, 0x3, 0x2, 0xa2, 
    0xa3, 0x7, 0x10, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x22, 0x12, 0x2, 0xa4, 0xa5, 
    0x7, 0x28, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x31, 0x2, 0x2, 0xa6, 0xa7, 0x5, 
    0x4, 0x3, 0x2, 0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa2, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x11, 0x2, 0x2, 0xae, 
    0xaf, 0x7, 0x28, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x31, 0x2, 0x2, 0xb0, 0xb2, 
    0x5, 0x4, 0x3, 0x2, 0xb1, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0xe, 
    0x2, 0x2, 0xb4, 0x21, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xba, 0x5, 0x24, 0x13, 
    0x2, 0xb6, 0xb7, 0x7, 0x23, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x24, 0x13, 0x2, 
    0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc2, 0x5, 
    0x26, 0x14, 0x2, 0xbe, 0xbf, 0x7, 0x22, 0x2, 0x2, 0xbf, 0xc1, 0x5, 0x26, 
    0x14, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0x25, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xc8, 0x5, 0x28, 0x15, 0x2, 0xc6, 0xc7, 0x9, 0x7, 0x2, 0x2, 0xc7, 0xc9, 
    0x5, 0x28, 0x15, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xc9, 0x27, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x7, 0x24, 
    0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x2a, 0x16, 0x2, 
    0xce, 0x29, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd8, 0x7, 0x12, 0x2, 0x2, 0xd0, 
    0xd8, 0x7, 0x13, 0x2, 0x2, 0xd1, 0xd8, 0x7, 0x1b, 0x2, 0x2, 0xd2, 0xd8, 
    0x5, 0x16, 0xc, 0x2, 0xd3, 0xd4, 0x7, 0x26, 0x2, 0x2, 0xd4, 0xd5, 0x5, 
    0x22, 0x12, 0x2, 0xd5, 0xd6, 0x7, 0x27, 0x2, 0x2, 0xd6, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd0, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x15, 
    0x2d, 0x37, 0x3b, 0x44, 0x4d, 0x55, 0x61, 0x7d, 0x85, 0x8d, 0x91, 0x9b, 
    0xaa, 0xb1, 0xba, 0xc2, 0xc8, 0xcb, 0xd7, 
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
