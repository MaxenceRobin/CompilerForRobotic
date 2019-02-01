
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PivotLexer : public antlr4::Lexer {
public:
  enum {
    FORWARD = 1, BACKWARD = 2, LEFT = 3, RIGHT = 4, STOP = 5, DURATION = 6, 
    NORMAL = 7, SLOW = 8, FAST = 9, WAIT = 10, LOOP = 11, TIMES = 12, END = 13, 
    IF = 14, ELIF = 15, ELSE = 16, TRUE = 17, FALSE = 18, WHILE = 19, UNTIL = 20, 
    LED = 21, RANDOMCOLOR = 22, VAR = 23, NUMBER = 24, RGB = 25, VARIABLE = 26, 
    EQU = 27, DIF = 28, LT = 29, GT = 30, LEQ = 31, GEQ = 32, AND = 33, 
    OR = 34, NOT = 35, AFF = 36, LPAR = 37, RPAR = 38, SEP = 39, PLUS = 40, 
    MINUS = 41, DIV = 42, STAR = 43, POW = 44, COMMA = 45, SEMICOLON = 46, 
    DOT = 47, NEWLINE = 48, WHITESPACE = 49
  };

  PivotLexer(antlr4::CharStream *input);
  ~PivotLexer();

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

