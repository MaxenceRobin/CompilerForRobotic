
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PivotLexer : public antlr4::Lexer {
public:
  enum {
    NUMBER = 1, EQU = 2, DIF = 3, LT = 4, GT = 5, LEQ = 6, GEQ = 7, AND = 8, 
    OR = 9, NOT = 10, AFF = 11, LPAR = 12, RPAR = 13, SEP = 14, PLUS = 15, 
    MINUS = 16, DIV = 17, STAR = 18, POW = 19, COMMA = 20, DOT = 21, NEWLINE = 22, 
    WHITESPACE = 23, FORWARD = 24, DURATION = 25, SPEED = 26, LOOP = 27, 
    TIMES = 28, END = 29, IF = 30, ELIF = 31, ELSE = 32, TRUE = 33, FALSE = 34
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

