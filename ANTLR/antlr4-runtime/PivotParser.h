
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PivotParser : public antlr4::Parser {
public:
  enum {
    FORWARD = 1, BACKWARD = 2, LEFT = 3, RIGHT = 4, STOP = 5, DURATION = 6, 
    NORMAL = 7, SLOW = 8, FAST = 9, WAIT = 10, LOOP = 11, END = 12, IF = 13, 
    ELIF = 14, ELSE = 15, TRUE = 16, FALSE = 17, WHILE = 18, UNTIL = 19, 
    LED = 20, RANDOMCOLOR = 21, VAR = 22, NUMBER = 23, RGB = 24, VARIABLE = 25, 
    EQU = 26, DIF = 27, LT = 28, GT = 29, LEQ = 30, GEQ = 31, AND = 32, 
    OR = 33, NOT = 34, AFF = 35, LPAR = 36, RPAR = 37, SEP = 38, PLUS = 39, 
    MINUS = 40, DIV = 41, STAR = 42, POW = 43, COMMA = 44, SEMICOLON = 45, 
    DOT = 46, NEWLINE = 47, WHITESPACE = 48
  };

  enum {
    RuleFile = 0, RuleStatements = 1, RuleStatement = 2, RuleAction = 3, 
    RuleDeclaration = 4, RuleAssignment = 5, RuleExpression = 6, RuleLoop = 7, 
    RuleWhile_loop = 8, RuleUntil_loop = 9, RuleNumeric_expression = 10, 
    RuleNumeric_mul_div = 11, RuleNumeric_pow = 12, RuleNumeric_inversion = 13, 
    RuleNumeric_atom = 14, RuleIf_elif_else = 15, RuleBoolean_expression = 16, 
    RuleBoolean_and = 17, RuleBoolean_comparator = 18, RuleBoolean_not = 19, 
    RuleBoolean_atom = 20
  };

  PivotParser(antlr4::TokenStream *input);
  ~PivotParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class StatementsContext;
  class StatementContext;
  class ActionContext;
  class DeclarationContext;
  class AssignmentContext;
  class ExpressionContext;
  class LoopContext;
  class While_loopContext;
  class Until_loopContext;
  class Numeric_expressionContext;
  class Numeric_mul_divContext;
  class Numeric_powContext;
  class Numeric_inversionContext;
  class Numeric_atomContext;
  class If_elif_elseContext;
  class Boolean_expressionContext;
  class Boolean_andContext;
  class Boolean_comparatorContext;
  class Boolean_notContext;
  class Boolean_atomContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementsContext *statements();
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementsContext* statements();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ActionContext *action();
    DeclarationContext *declaration();
    AssignmentContext *assignment();
    LoopContext *loop();
    While_loopContext *while_loop();
    Until_loopContext *until_loop();
    If_elif_elseContext *if_elif_else();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *move_type = nullptr;;
    antlr4::Token *move_speed = nullptr;;
    PivotParser::Numeric_expressionContext *duration = nullptr;;
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORWARD();
    antlr4::tree::TerminalNode *BACKWARD();
    antlr4::tree::TerminalNode *LEFT();
    antlr4::tree::TerminalNode *RIGHT();
    antlr4::tree::TerminalNode *SLOW();
    antlr4::tree::TerminalNode *NORMAL();
    antlr4::tree::TerminalNode *FAST();
    antlr4::tree::TerminalNode *STOP();
    antlr4::tree::TerminalNode *WAIT();
    Numeric_expressionContext *numeric_expression();
    antlr4::tree::TerminalNode *LED();
    antlr4::tree::TerminalNode *RGB();
    antlr4::tree::TerminalNode *RANDOMCOLOR();
    antlr4::tree::TerminalNode *VARIABLE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *AFF();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Numeric_expressionContext *numeric_expression();
    Boolean_expressionContext *boolean_expression();
    antlr4::tree::TerminalNode *RGB();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  LoopContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Numeric_expressionContext *repetition_number = nullptr;;
    LoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *SEP();
    antlr4::tree::TerminalNode *NEWLINE();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *END();
    Numeric_expressionContext *numeric_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopContext* loop();

  class  While_loopContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Boolean_expressionContext *condition = nullptr;;
    While_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *SEP();
    antlr4::tree::TerminalNode *NEWLINE();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *END();
    Boolean_expressionContext *boolean_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_loopContext* while_loop();

  class  Until_loopContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Boolean_expressionContext *condition = nullptr;;
    Until_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNTIL();
    antlr4::tree::TerminalNode *SEP();
    antlr4::tree::TerminalNode *NEWLINE();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *END();
    Boolean_expressionContext *boolean_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Until_loopContext* until_loop();

  class  Numeric_expressionContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Numeric_mul_divContext *numeric_mul_divContext = nullptr;;
    std::vector<Numeric_mul_divContext *> value;;
    antlr4::Token *op = nullptr;;
    Numeric_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Numeric_mul_divContext *> numeric_mul_div();
    Numeric_mul_divContext* numeric_mul_div(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Numeric_expressionContext* numeric_expression();

  class  Numeric_mul_divContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Numeric_powContext *numeric_powContext = nullptr;;
    std::vector<Numeric_powContext *> value;;
    antlr4::Token *op = nullptr;;
    Numeric_mul_divContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Numeric_powContext *> numeric_pow();
    Numeric_powContext* numeric_pow(size_t i);
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Numeric_mul_divContext* numeric_mul_div();

  class  Numeric_powContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Numeric_inversionContext *numeric_inversionContext = nullptr;;
    std::vector<Numeric_inversionContext *> value;;
    Numeric_powContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Numeric_inversionContext *> numeric_inversion();
    Numeric_inversionContext* numeric_inversion(size_t i);
    std::vector<antlr4::tree::TerminalNode *> POW();
    antlr4::tree::TerminalNode* POW(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Numeric_powContext* numeric_pow();

  class  Numeric_inversionContext : public antlr4::ParserRuleContext {
  public:
    Numeric_inversionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Numeric_atomContext *numeric_atom();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Numeric_inversionContext* numeric_inversion();

  class  Numeric_atomContext : public antlr4::ParserRuleContext {
  public:
    Numeric_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *LPAR();
    Numeric_expressionContext *numeric_expression();
    antlr4::tree::TerminalNode *RPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Numeric_atomContext* numeric_atom();

  class  If_elif_elseContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Boolean_expressionContext *if_condition = nullptr;;
    PivotParser::StatementsContext *if_block = nullptr;;
    PivotParser::Boolean_expressionContext *boolean_expressionContext = nullptr;;
    std::vector<Boolean_expressionContext *> elif_condition;;
    PivotParser::StatementsContext *statementsContext = nullptr;;
    std::vector<StatementsContext *> elif_block;;
    PivotParser::StatementsContext *else_block = nullptr;;
    If_elif_elseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<antlr4::tree::TerminalNode *> SEP();
    antlr4::tree::TerminalNode* SEP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    antlr4::tree::TerminalNode *END();
    std::vector<Boolean_expressionContext *> boolean_expression();
    Boolean_expressionContext* boolean_expression(size_t i);
    std::vector<StatementsContext *> statements();
    StatementsContext* statements(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELIF();
    antlr4::tree::TerminalNode* ELIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_elif_elseContext* if_elif_else();

  class  Boolean_expressionContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Boolean_andContext *boolean_andContext = nullptr;;
    std::vector<Boolean_andContext *> value;;
    Boolean_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Boolean_andContext *> boolean_and();
    Boolean_andContext* boolean_and(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_expressionContext* boolean_expression();

  class  Boolean_andContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Boolean_comparatorContext *boolean_comparatorContext = nullptr;;
    std::vector<Boolean_comparatorContext *> value;;
    Boolean_andContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Boolean_comparatorContext *> boolean_comparator();
    Boolean_comparatorContext* boolean_comparator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_andContext* boolean_and();

  class  Boolean_comparatorContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Boolean_notContext *left = nullptr;;
    antlr4::Token *comparator = nullptr;;
    PivotParser::Boolean_notContext *right = nullptr;;
    Boolean_comparatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Boolean_notContext *> boolean_not();
    Boolean_notContext* boolean_not(size_t i);
    antlr4::tree::TerminalNode *EQU();
    antlr4::tree::TerminalNode *DIF();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *GEQ();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_comparatorContext* boolean_comparator();

  class  Boolean_notContext : public antlr4::ParserRuleContext {
  public:
    Boolean_notContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolean_atomContext *boolean_atom();
    antlr4::tree::TerminalNode *NOT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_notContext* boolean_not();

  class  Boolean_atomContext : public antlr4::ParserRuleContext {
  public:
    Boolean_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *VARIABLE();
    Numeric_expressionContext *numeric_expression();
    antlr4::tree::TerminalNode *LPAR();
    Boolean_expressionContext *boolean_expression();
    antlr4::tree::TerminalNode *RPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_atomContext* boolean_atom();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

