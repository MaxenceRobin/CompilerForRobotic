
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PivotLexer : public antlr4::Lexer {
public:
  enum {
    FORWARD = 1, BACKWARD = 2, LEFT = 3, RIGHT = 4, STOP = 5, DURATION = 6, 
    NORMAL = 7, SLOW = 8, FAST = 9, WAIT = 10, LOOP = 11, END = 12, IF = 13, 
    ELIF = 14, ELSE = 15, TRUE = 16, FALSE = 17, WHILE = 18, UNTIL = 19, 
    LED = 20, RANDOMCOLOR = 21, VAR = 22, LEFT_SENSOR = 23, CENTER_SENSOR = 24, 
    RIGHT_SENSOR = 25, VERYCLOSE = 26, CLOSE = 27, SENSOR_ONE = 28, SENSOR_TWO = 29, 
    SENSOR_THREE = 30, SENSOR_FOUR = 31, EQU = 32, DIF = 33, LT = 34, GT = 35, 
    LEQ = 36, GEQ = 37, AND = 38, OR = 39, NOT = 40, AFF = 41, LPAR = 42, 
    RPAR = 43, SEP = 44, PLUS = 45, MINUS = 46, DIV = 47, STAR = 48, POW = 49, 
    COMMA = 50, SEMICOLON = 51, DOT = 52, UNDERSCORE = 53, NUMBER = 54, 
    RGB = 55, VARIABLE = 56, NEWLINE = 57, WHITESPACE = 58
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

