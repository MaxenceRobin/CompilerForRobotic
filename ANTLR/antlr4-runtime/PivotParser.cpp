
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

std::vector<tree::TerminalNode *> PivotParser::FileContext::NEWLINE() {
  return getTokens(PivotParser::NEWLINE);
}

tree::TerminalNode* PivotParser::FileContext::NEWLINE(size_t i) {
  return getToken(PivotParser::NEWLINE, i);
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
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::NEWLINE) {
      setState(46);
      match(PivotParser::NEWLINE);
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    statements();
    setState(53);
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
    setState(60);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(55);
        statement();
        setState(56);
        match(PivotParser::NEWLINE); 
      }
      setState(62);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(64);
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
      setState(63);
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
    setState(73);
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
        setState(66);
        action();
        break;
      }

      case PivotParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(67);
        declaration();
        break;
      }

      case PivotParser::VARIABLE: {
        enterOuterAlt(_localctx, 3);
        setState(68);
        assignment();
        break;
      }

      case PivotParser::LOOP: {
        enterOuterAlt(_localctx, 4);
        setState(69);
        loop();
        break;
      }

      case PivotParser::WHILE: {
        enterOuterAlt(_localctx, 5);
        setState(70);
        while_loop();
        break;
      }

      case PivotParser::UNTIL: {
        enterOuterAlt(_localctx, 6);
        setState(71);
        until_loop();
        break;
      }

      case PivotParser::IF: {
        enterOuterAlt(_localctx, 7);
        setState(72);
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

PivotParser::Numeric_expressionContext* PivotParser::ActionContext::numeric_expression() {
  return getRuleContext<PivotParser::Numeric_expressionContext>(0);
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

tree::TerminalNode* PivotParser::ActionContext::LED() {
  return getToken(PivotParser::LED, 0);
}

tree::TerminalNode* PivotParser::ActionContext::RGB() {
  return getToken(PivotParser::RGB, 0);
}

PivotParser::Special_colorContext* PivotParser::ActionContext::special_color() {
  return getRuleContext<PivotParser::Special_colorContext>(0);
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
    setState(89);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::FORWARD:
      case PivotParser::BACKWARD:
      case PivotParser::LEFT:
      case PivotParser::RIGHT: {
        enterOuterAlt(_localctx, 1);
        setState(75);
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
        setState(78);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PivotParser::NORMAL:
          case PivotParser::SLOW:
          case PivotParser::FAST: {
            setState(76);
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

          case PivotParser::VERYCLOSE:
          case PivotParser::CLOSE:
          case PivotParser::SENSOR_ONE:
          case PivotParser::SENSOR_TWO:
          case PivotParser::SENSOR_THREE:
          case PivotParser::SENSOR_FOUR:
          case PivotParser::LPAR:
          case PivotParser::MINUS:
          case PivotParser::NUMBER:
          case PivotParser::VARIABLE: {
            setState(77);
            numeric_expression();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case PivotParser::STOP: {
        enterOuterAlt(_localctx, 2);
        setState(80);
        match(PivotParser::STOP);
        break;
      }

      case PivotParser::WAIT: {
        enterOuterAlt(_localctx, 3);
        setState(81);
        match(PivotParser::WAIT);
        setState(82);
        dynamic_cast<ActionContext *>(_localctx)->duration = numeric_expression();
        break;
      }

      case PivotParser::LED: {
        enterOuterAlt(_localctx, 4);
        setState(83);
        match(PivotParser::LED);
        setState(87);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PivotParser::RGB: {
            setState(84);
            match(PivotParser::RGB);
            break;
          }

          case PivotParser::RANDOMCOLOR: {
            setState(85);
            special_color();
            break;
          }

          case PivotParser::VARIABLE: {
            setState(86);
            match(PivotParser::VARIABLE);
            break;
          }

        default:
          throw NoViableAltException(this);
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

//----------------- Special_colorContext ------------------------------------------------------------------

PivotParser::Special_colorContext::Special_colorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::Special_colorContext::RANDOMCOLOR() {
  return getToken(PivotParser::RANDOMCOLOR, 0);
}


size_t PivotParser::Special_colorContext::getRuleIndex() const {
  return PivotParser::RuleSpecial_color;
}

antlrcpp::Any PivotParser::Special_colorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitSpecial_color(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Special_colorContext* PivotParser::special_color() {
  Special_colorContext *_localctx = _tracker.createInstance<Special_colorContext>(_ctx, getState());
  enterRule(_localctx, 8, PivotParser::RuleSpecial_color);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(PivotParser::RANDOMCOLOR);
   
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
  enterRule(_localctx, 10, PivotParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(PivotParser::VAR);
    setState(94);
    dynamic_cast<DeclarationContext *>(_localctx)->variableToken = match(PivotParser::VARIABLE);
    dynamic_cast<DeclarationContext *>(_localctx)->var_name.push_back(dynamic_cast<DeclarationContext *>(_localctx)->variableToken);
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::COMMA) {
      setState(95);
      match(PivotParser::COMMA);
      setState(96);
      dynamic_cast<DeclarationContext *>(_localctx)->variableToken = match(PivotParser::VARIABLE);
      dynamic_cast<DeclarationContext *>(_localctx)->var_name.push_back(dynamic_cast<DeclarationContext *>(_localctx)->variableToken);
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(102);
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
  enterRule(_localctx, 12, PivotParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(PivotParser::VARIABLE);
    setState(105);
    match(PivotParser::AFF);
    setState(106);
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
  enterRule(_localctx, 14, PivotParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(108);
      numeric_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(109);
      boolean_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(110);
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
  enterRule(_localctx, 16, PivotParser::RuleLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(PivotParser::LOOP);
    setState(114);
    dynamic_cast<LoopContext *>(_localctx)->repetition_number = numeric_expression();
    setState(115);
    match(PivotParser::SEP);
    setState(116);
    match(PivotParser::NEWLINE);
    setState(117);
    statements();
    setState(118);
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
  enterRule(_localctx, 18, PivotParser::RuleWhile_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(PivotParser::WHILE);
    setState(121);
    dynamic_cast<While_loopContext *>(_localctx)->condition = boolean_expression();
    setState(122);
    match(PivotParser::SEP);
    setState(123);
    match(PivotParser::NEWLINE);
    setState(124);
    statements();
    setState(125);
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
  enterRule(_localctx, 20, PivotParser::RuleUntil_loop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(PivotParser::UNTIL);
    setState(128);
    dynamic_cast<Until_loopContext *>(_localctx)->condition = boolean_expression();
    setState(129);
    match(PivotParser::SEP);
    setState(130);
    match(PivotParser::NEWLINE);
    setState(131);
    statements();
    setState(132);
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
  enterRule(_localctx, 22, PivotParser::RuleNumeric_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
    dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::PLUS

    || _la == PivotParser::MINUS) {
      setState(135);
      dynamic_cast<Numeric_expressionContext *>(_localctx)->_tset855 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == PivotParser::PLUS

      || _la == PivotParser::MINUS)) {
        dynamic_cast<Numeric_expressionContext *>(_localctx)->_tset855 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      dynamic_cast<Numeric_expressionContext *>(_localctx)->op.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->_tset855);
      setState(136);
      dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext = numeric_mul_div();
      dynamic_cast<Numeric_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_expressionContext *>(_localctx)->numeric_mul_divContext);
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
  enterRule(_localctx, 24, PivotParser::RuleNumeric_mul_div);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
    dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
    setState(147);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::DIV

    || _la == PivotParser::STAR) {
      setState(143);
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->_tset879 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == PivotParser::DIV

      || _la == PivotParser::STAR)) {
        dynamic_cast<Numeric_mul_divContext *>(_localctx)->_tset879 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->op.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->_tset879);
      setState(144);
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext = numeric_pow();
      dynamic_cast<Numeric_mul_divContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_mul_divContext *>(_localctx)->numeric_powContext);
      setState(149);
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
  enterRule(_localctx, 26, PivotParser::RuleNumeric_pow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext = numeric_inversion();
    dynamic_cast<Numeric_powContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext);
    setState(155);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::POW) {
      setState(151);
      match(PivotParser::POW);
      setState(152);
      dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext = numeric_inversion();
      dynamic_cast<Numeric_powContext *>(_localctx)->value.push_back(dynamic_cast<Numeric_powContext *>(_localctx)->numeric_inversionContext);
      setState(157);
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
  enterRule(_localctx, 28, PivotParser::RuleNumeric_inversion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::MINUS) {
      setState(158);
      match(PivotParser::MINUS);
    }
    setState(161);
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

PivotParser::Special_numericsContext* PivotParser::Numeric_atomContext::special_numerics() {
  return getRuleContext<PivotParser::Special_numericsContext>(0);
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
  enterRule(_localctx, 30, PivotParser::RuleNumeric_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PivotParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(163);
        match(PivotParser::NUMBER);
        break;
      }

      case PivotParser::VARIABLE: {
        enterOuterAlt(_localctx, 2);
        setState(164);
        match(PivotParser::VARIABLE);
        break;
      }

      case PivotParser::VERYCLOSE:
      case PivotParser::CLOSE:
      case PivotParser::SENSOR_ONE:
      case PivotParser::SENSOR_TWO:
      case PivotParser::SENSOR_THREE:
      case PivotParser::SENSOR_FOUR: {
        enterOuterAlt(_localctx, 3);
        setState(165);
        special_numerics();
        break;
      }

      case PivotParser::LPAR: {
        enterOuterAlt(_localctx, 4);
        setState(166);
        match(PivotParser::LPAR);
        setState(167);
        numeric_expression();
        setState(168);
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

//----------------- Special_numericsContext ------------------------------------------------------------------

PivotParser::Special_numericsContext::Special_numericsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PivotParser::Special_numericsContext::VERYCLOSE() {
  return getToken(PivotParser::VERYCLOSE, 0);
}

tree::TerminalNode* PivotParser::Special_numericsContext::CLOSE() {
  return getToken(PivotParser::CLOSE, 0);
}

tree::TerminalNode* PivotParser::Special_numericsContext::SENSOR_ONE() {
  return getToken(PivotParser::SENSOR_ONE, 0);
}

tree::TerminalNode* PivotParser::Special_numericsContext::SENSOR_TWO() {
  return getToken(PivotParser::SENSOR_TWO, 0);
}

tree::TerminalNode* PivotParser::Special_numericsContext::SENSOR_THREE() {
  return getToken(PivotParser::SENSOR_THREE, 0);
}

tree::TerminalNode* PivotParser::Special_numericsContext::SENSOR_FOUR() {
  return getToken(PivotParser::SENSOR_FOUR, 0);
}


size_t PivotParser::Special_numericsContext::getRuleIndex() const {
  return PivotParser::RuleSpecial_numerics;
}

antlrcpp::Any PivotParser::Special_numericsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PivotVisitor*>(visitor))
    return parserVisitor->visitSpecial_numerics(this);
  else
    return visitor->visitChildren(this);
}

PivotParser::Special_numericsContext* PivotParser::special_numerics() {
  Special_numericsContext *_localctx = _tracker.createInstance<Special_numericsContext>(_ctx, getState());
  enterRule(_localctx, 32, PivotParser::RuleSpecial_numerics);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PivotParser::VERYCLOSE)
      | (1ULL << PivotParser::CLOSE)
      | (1ULL << PivotParser::SENSOR_ONE)
      | (1ULL << PivotParser::SENSOR_TWO)
      | (1ULL << PivotParser::SENSOR_THREE)
      | (1ULL << PivotParser::SENSOR_FOUR))) != 0))) {
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
  enterRule(_localctx, 34, PivotParser::RuleIf_elif_else);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(PivotParser::IF);
    setState(175);
    dynamic_cast<If_elif_elseContext *>(_localctx)->if_condition = boolean_expression();
    setState(176);
    match(PivotParser::SEP);
    setState(177);
    match(PivotParser::NEWLINE);
    setState(178);
    dynamic_cast<If_elif_elseContext *>(_localctx)->if_block = statements();
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::ELIF) {
      setState(179);
      match(PivotParser::ELIF);
      setState(180);
      dynamic_cast<If_elif_elseContext *>(_localctx)->boolean_expressionContext = boolean_expression();
      dynamic_cast<If_elif_elseContext *>(_localctx)->elif_condition.push_back(dynamic_cast<If_elif_elseContext *>(_localctx)->boolean_expressionContext);
      setState(181);
      match(PivotParser::SEP);
      setState(182);
      match(PivotParser::NEWLINE);
      setState(183);
      dynamic_cast<If_elif_elseContext *>(_localctx)->statementsContext = statements();
      dynamic_cast<If_elif_elseContext *>(_localctx)->elif_block.push_back(dynamic_cast<If_elif_elseContext *>(_localctx)->statementsContext);
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(194);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::ELSE) {
      setState(190);
      match(PivotParser::ELSE);
      setState(191);
      match(PivotParser::SEP);
      setState(192);
      match(PivotParser::NEWLINE);
      setState(193);
      dynamic_cast<If_elif_elseContext *>(_localctx)->else_block = statements();
    }
    setState(196);
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
  enterRule(_localctx, 36, PivotParser::RuleBoolean_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext = boolean_and();
    dynamic_cast<Boolean_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext);
    setState(203);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::OR) {
      setState(199);
      match(PivotParser::OR);
      setState(200);
      dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext = boolean_and();
      dynamic_cast<Boolean_expressionContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_expressionContext *>(_localctx)->boolean_andContext);
      setState(205);
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
  enterRule(_localctx, 38, PivotParser::RuleBoolean_and);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext = boolean_comparator();
    dynamic_cast<Boolean_andContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext);
    setState(211);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PivotParser::AND) {
      setState(207);
      match(PivotParser::AND);
      setState(208);
      dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext = boolean_comparator();
      dynamic_cast<Boolean_andContext *>(_localctx)->value.push_back(dynamic_cast<Boolean_andContext *>(_localctx)->boolean_comparatorContext);
      setState(213);
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
  enterRule(_localctx, 40, PivotParser::RuleBoolean_comparator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    dynamic_cast<Boolean_comparatorContext *>(_localctx)->left = boolean_not();
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PivotParser::EQU)
      | (1ULL << PivotParser::DIF)
      | (1ULL << PivotParser::LT)
      | (1ULL << PivotParser::GT)
      | (1ULL << PivotParser::LEQ)
      | (1ULL << PivotParser::GEQ))) != 0)) {
      setState(215);
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
      setState(216);
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
  enterRule(_localctx, 42, PivotParser::RuleBoolean_not);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PivotParser::NOT) {
      setState(219);
      match(PivotParser::NOT);
    }
    setState(222);
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
  enterRule(_localctx, 44, PivotParser::RuleBoolean_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(224);
      match(PivotParser::TRUE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(225);
      match(PivotParser::FALSE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(226);
      match(PivotParser::VARIABLE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(227);
      numeric_expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(228);
      match(PivotParser::LPAR);
      setState(229);
      boolean_expression();
      setState(230);
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
  "file", "statements", "statement", "action", "special_color", "declaration", 
  "assignment", "expression", "loop", "while_loop", "until_loop", "numeric_expression", 
  "numeric_mul_div", "numeric_pow", "numeric_inversion", "numeric_atom", 
  "special_numerics", "if_elif_else", "boolean_expression", "boolean_and", 
  "boolean_comparator", "boolean_not", "boolean_atom"
};

std::vector<std::string> PivotParser::_literalNames = {
  "", "'forward'", "'backward'", "'left'", "'right'", "'stop'", "'duration'", 
  "'normal'", "'slow'", "'fast'", "'wait'", "'loop'", "'end'", "'if'", "'elif'", 
  "'else'", "'true'", "'false'", "'while'", "'until'", "'led'", "'random_color'", 
  "'var'", "'left_sensor'", "'center_sensor'", "'right_sensor'", "'very_close'", 
  "'close'", "'sensor_one'", "'sensor_two'", "'sensor_three'", "'sensor_four'", 
  "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'&&'", "'||'", "'!'", "'='", 
  "'('", "')'", "':'", "'+'", "'-'", "'/'", "'*'", "'^'", "','", "';'", 
  "'.'", "'_'"
};

std::vector<std::string> PivotParser::_symbolicNames = {
  "", "FORWARD", "BACKWARD", "LEFT", "RIGHT", "STOP", "DURATION", "NORMAL", 
  "SLOW", "FAST", "WAIT", "LOOP", "END", "IF", "ELIF", "ELSE", "TRUE", "FALSE", 
  "WHILE", "UNTIL", "LED", "RANDOMCOLOR", "VAR", "LEFT_SENSOR", "CENTER_SENSOR", 
  "RIGHT_SENSOR", "VERYCLOSE", "CLOSE", "SENSOR_ONE", "SENSOR_TWO", "SENSOR_THREE", 
  "SENSOR_FOUR", "EQU", "DIF", "LT", "GT", "LEQ", "GEQ", "AND", "OR", "NOT", 
  "AFF", "LPAR", "RPAR", "SEP", "PLUS", "MINUS", "DIV", "STAR", "POW", "COMMA", 
  "SEMICOLON", "DOT", "UNDERSCORE", "NUMBER", "RGB", "VARIABLE", "NEWLINE", 
  "WHITESPACE"
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
    0x3, 0x3c, 0xed, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x3d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x40, 0xb, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x43, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x4c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x51, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x5a, 0xa, 0x5, 0x5, 0x5, 0x5c, 0xa, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
    0x7, 0x64, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x67, 0xb, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x72, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x8c, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x8f, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x7, 0xe, 0x94, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x97, 0xb, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x9c, 0xa, 0xf, 0xc, 0xf, 0xe, 
    0xf, 0x9f, 0xb, 0xf, 0x3, 0x10, 0x5, 0x10, 0xa2, 0xa, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0xad, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xbc, 0xa, 0x13, 
    0xc, 0x13, 0xe, 0x13, 0xbf, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0xc5, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xcc, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0xcf, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xd4, 0xa, 
    0x15, 0xc, 0x15, 0xe, 0x15, 0xd7, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x5, 0x16, 0xdc, 0xa, 0x16, 0x3, 0x17, 0x5, 0x17, 0xdf, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xeb, 0xa, 0x18, 0x3, 
    0x18, 0x2, 0x2, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x2, 0x8, 0x3, 0x2, 0x3, 0x6, 0x3, 0x2, 0x9, 0xb, 0x3, 0x2, 
    0x2f, 0x30, 0x3, 0x2, 0x31, 0x32, 0x3, 0x2, 0x1c, 0x21, 0x3, 0x2, 0x22, 
    0x27, 0x2, 0xf8, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x71, 0x3, 0x2, 0x2, 0x2, 0x12, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x16, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x88, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x98, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xac, 0x3, 0x2, 0x2, 0x2, 0x22, 0xae, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x28, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xd8, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0xea, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x7, 0x3b, 
    0x2, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x37, 0x5, 0x4, 0x3, 0x2, 0x37, 0x38, 0x7, 0x2, 0x2, 0x3, 0x38, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x6, 0x4, 0x2, 0x3a, 0x3b, 0x7, 
    0x3b, 0x2, 0x2, 0x3b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 0x5, 0x6, 0x4, 0x2, 0x42, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x45, 0x4c, 0x5, 
    0xc, 0x7, 0x2, 0x46, 0x4c, 0x5, 0xe, 0x8, 0x2, 0x47, 0x4c, 0x5, 0x12, 
    0xa, 0x2, 0x48, 0x4c, 0x5, 0x14, 0xb, 0x2, 0x49, 0x4c, 0x5, 0x16, 0xc, 
    0x2, 0x4a, 0x4c, 0x5, 0x24, 0x13, 0x2, 0x4b, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x50, 0x9, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x9, 0x3, 
    0x2, 0x2, 0x4f, 0x51, 0x5, 0x18, 0xd, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x5c, 0x7, 0x7, 0x2, 0x2, 0x53, 0x54, 0x7, 0xc, 0x2, 0x2, 0x54, 
    0x5c, 0x5, 0x18, 0xd, 0x2, 0x55, 0x59, 0x7, 0x16, 0x2, 0x2, 0x56, 0x5a, 
    0x7, 0x39, 0x2, 0x2, 0x57, 0x5a, 0x5, 0xa, 0x6, 0x2, 0x58, 0x5a, 0x7, 
    0x3a, 0x2, 0x2, 0x59, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x53, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x55, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x17, 0x2, 0x2, 0x5e, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x18, 0x2, 0x2, 0x60, 0x65, 0x7, 
    0x3a, 0x2, 0x2, 0x61, 0x62, 0x7, 0x34, 0x2, 0x2, 0x62, 0x64, 0x7, 0x3a, 
    0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x68, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x69, 0x7, 0x35, 0x2, 0x2, 0x69, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 
    0x7, 0x3a, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x2b, 0x2, 0x2, 0x6c, 0x6d, 0x5, 
    0x10, 0x9, 0x2, 0x6d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x72, 0x5, 0x18, 
    0xd, 0x2, 0x6f, 0x72, 0x5, 0x26, 0x14, 0x2, 0x70, 0x72, 0x7, 0x39, 0x2, 
    0x2, 0x71, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x11, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x7, 0xd, 0x2, 0x2, 0x74, 0x75, 0x5, 0x18, 0xd, 0x2, 0x75, 0x76, 
    0x7, 0x2e, 0x2, 0x2, 0x76, 0x77, 0x7, 0x3b, 0x2, 0x2, 0x77, 0x78, 0x5, 
    0x4, 0x3, 0x2, 0x78, 0x79, 0x7, 0xe, 0x2, 0x2, 0x79, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x7, 0x14, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x26, 0x14, 
    0x2, 0x7c, 0x7d, 0x7, 0x2e, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x3b, 0x2, 0x2, 
    0x7e, 0x7f, 0x5, 0x4, 0x3, 0x2, 0x7f, 0x80, 0x7, 0xe, 0x2, 0x2, 0x80, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0x15, 0x2, 0x2, 0x82, 0x83, 
    0x5, 0x26, 0x14, 0x2, 0x83, 0x84, 0x7, 0x2e, 0x2, 0x2, 0x84, 0x85, 0x7, 
    0x3b, 0x2, 0x2, 0x85, 0x86, 0x5, 0x4, 0x3, 0x2, 0x86, 0x87, 0x7, 0xe, 
    0x2, 0x2, 0x87, 0x17, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8d, 0x5, 0x1a, 0xe, 
    0x2, 0x89, 0x8a, 0x9, 0x4, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0x1a, 0xe, 0x2, 
    0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x95, 0x5, 
    0x1c, 0xf, 0x2, 0x91, 0x92, 0x9, 0x5, 0x2, 0x2, 0x92, 0x94, 0x5, 0x1c, 
    0xf, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x9d, 0x5, 0x1e, 0x10, 0x2, 0x99, 0x9a, 0x7, 0x33, 0x2, 0x2, 0x9a, 0x9c, 
    0x5, 0x1e, 0x10, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0xa2, 0x7, 0x30, 0x2, 0x2, 0xa1, 0xa0, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 
    0xa4, 0x5, 0x20, 0x11, 0x2, 0xa4, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xad, 
    0x7, 0x38, 0x2, 0x2, 0xa6, 0xad, 0x7, 0x3a, 0x2, 0x2, 0xa7, 0xad, 0x5, 
    0x22, 0x12, 0x2, 0xa8, 0xa9, 0x7, 0x2c, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x18, 
    0xd, 0x2, 0xaa, 0xab, 0x7, 0x2d, 0x2, 0x2, 0xab, 0xad, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x9, 0x6, 0x2, 0x2, 0xaf, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0xf, 0x2, 0x2, 0xb1, 0xb2, 0x5, 
    0x26, 0x14, 0x2, 0xb2, 0xb3, 0x7, 0x2e, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x3b, 
    0x2, 0x2, 0xb4, 0xbd, 0x5, 0x4, 0x3, 0x2, 0xb5, 0xb6, 0x7, 0x10, 0x2, 
    0x2, 0xb6, 0xb7, 0x5, 0x26, 0x14, 0x2, 0xb7, 0xb8, 0x7, 0x2e, 0x2, 0x2, 
    0xb8, 0xb9, 0x7, 0x3b, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x4, 0x3, 0x2, 0xba, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc1, 0x7, 0x11, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x2e, 0x2, 
    0x2, 0xc2, 0xc3, 0x7, 0x3b, 0x2, 0x2, 0xc3, 0xc5, 0x5, 0x4, 0x3, 0x2, 
    0xc4, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0xe, 0x2, 0x2, 0xc7, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xcd, 0x5, 0x28, 0x15, 0x2, 0xc9, 0xca, 0x7, 
    0x29, 0x2, 0x2, 0xca, 0xcc, 0x5, 0x28, 0x15, 0x2, 0xcb, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd5, 0x5, 0x2a, 0x16, 0x2, 0xd1, 
    0xd2, 0x7, 0x28, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x2a, 0x16, 0x2, 0xd3, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdb, 0x5, 0x2c, 0x17, 
    0x2, 0xd9, 0xda, 0x9, 0x7, 0x2, 0x2, 0xda, 0xdc, 0x5, 0x2c, 0x17, 0x2, 
    0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x7, 0x2a, 0x2, 0x2, 0xde, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x2e, 0x18, 0x2, 0xe1, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0xeb, 0x7, 0x12, 0x2, 0x2, 0xe3, 0xeb, 0x7, 0x13, 0x2, 
    0x2, 0xe4, 0xeb, 0x7, 0x3a, 0x2, 0x2, 0xe5, 0xeb, 0x5, 0x18, 0xd, 0x2, 
    0xe6, 0xe7, 0x7, 0x2c, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x26, 0x14, 0x2, 0xe8, 
    0xe9, 0x7, 0x2d, 0x2, 0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xeb, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x17, 0x33, 0x3e, 0x42, 0x4b, 
    0x50, 0x59, 0x5b, 0x65, 0x71, 0x8d, 0x95, 0x9d, 0xa1, 0xac, 0xbd, 0xc4, 
    0xcd, 0xd5, 0xdb, 0xde, 0xea, 
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
