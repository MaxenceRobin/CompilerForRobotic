
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PivotParser : public antlr4::Parser {
public:
  enum {
    NUMBER = 1, EQU = 2, DIF = 3, LT = 4, GT = 5, LEQ = 6, GEQ = 7, AND = 8, 
    OR = 9, NOT = 10, AFF = 11, LPAR = 12, RPAR = 13, SEP = 14, PLUS = 15, 
    MINUS = 16, DIV = 17, STAR = 18, COMMA = 19, DOT = 20, MATH = 21, POW = 22, 
    NEWLINE = 23, WHITESPACE = 24, FORWARD = 25, TRUE = 26, FALSE = 27, 
    DURATION = 28, SPEED = 29, LOOP = 30, TIMES = 31, END = 32
  };

  enum {
    RuleFile = 0, RuleStatements = 1, RuleStatement = 2, RuleAction = 3, 
    RuleLoop = 4, RuleNumeric_expression = 5, RuleNumeric_mul_div = 6, RuleNumeric_pow = 7, 
    RuleNumeric_inversion = 8, RuleNumeric_atom = 9, RuleBoolean_expression = 10, 
    RuleBoolean_and = 11, RuleBoolean_not = 12, RuleBoolean_atom = 13
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
  class LoopContext;
  class Numeric_expressionContext;
  class Numeric_mul_divContext;
  class Numeric_powContext;
  class Numeric_inversionContext;
  class Numeric_atomContext;
  class Boolean_expressionContext;
  class Boolean_andContext;
  class Boolean_notContext;
  class Boolean_atomContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementsContext *statements();
    antlr4::tree::TerminalNode *EOF();

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
    LoopContext *loop();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Numeric_expressionContext *duration = nullptr;;
    PivotParser::Numeric_expressionContext *speed = nullptr;;
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORWARD();
    antlr4::tree::TerminalNode *DURATION();
    std::vector<antlr4::tree::TerminalNode *> AFF();
    antlr4::tree::TerminalNode* AFF(size_t i);
    std::vector<Numeric_expressionContext *> numeric_expression();
    Numeric_expressionContext* numeric_expression(size_t i);
    antlr4::tree::TerminalNode *SPEED();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();

  class  LoopContext : public antlr4::ParserRuleContext {
  public:
    PivotParser::Numeric_expressionContext *repetition_number = nullptr;;
    LoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *AFF();
    antlr4::tree::TerminalNode *SEP();
    antlr4::tree::TerminalNode *NEWLINE();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *END();
    Numeric_expressionContext *numeric_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopContext* loop();

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
    PivotParser::Numeric_expressionContext *first = nullptr;;
    PivotParser::Numeric_expressionContext *second = nullptr;;
    Numeric_powContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Numeric_inversionContext *numeric_inversion();
    antlr4::tree::TerminalNode *MATH();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<Numeric_expressionContext *> numeric_expression();
    Numeric_expressionContext* numeric_expression(size_t i);

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
    antlr4::tree::TerminalNode *LPAR();
    Numeric_expressionContext *numeric_expression();
    antlr4::tree::TerminalNode *RPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Numeric_atomContext* numeric_atom();

  class  Boolean_expressionContext : public antlr4::ParserRuleContext {
  public:
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
    Boolean_andContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Boolean_notContext *> boolean_not();
    Boolean_notContext* boolean_not(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_andContext* boolean_and();

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

