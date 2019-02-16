
// Generated from .\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PivotLexer : public antlr4::Lexer {
public:
  enum {
    FORWARD = 1, BACKWARD = 2, LEFT = 3, RIGHT = 4, STOP = 5, DURATION = 6, 
    NORMAL = 7, SLOW = 8, FAST = 9, WAIT = 10, LOOP = 11, END = 12, IF = 13, 
    ELIF = 14, ELSE = 15, TRUE = 16, FALSE = 17, WHILE = 18, UNTIL = 19, 
    LED = 20, RANDOMCOLOR = 21, VAR = 22, LEFT_SENSOR = 23, CENTER_SENSOR = 24, 
    RIGHT_SENSOR = 25, VERYCLOSE = 26, CLOSE = 27, EQU = 28, DIF = 29, LT = 30, 
    GT = 31, LEQ = 32, GEQ = 33, AND = 34, OR = 35, NOT = 36, AFF = 37, 
    LPAR = 38, RPAR = 39, SEP = 40, PLUS = 41, MINUS = 42, DIV = 43, STAR = 44, 
    POW = 45, COMMA = 46, SEMICOLON = 47, DOT = 48, UNDERSCORE = 49, NUMBER = 50, 
    RGB = 51, VARIABLE = 52, NEWLINE = 53, WHITESPACE = 54
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

