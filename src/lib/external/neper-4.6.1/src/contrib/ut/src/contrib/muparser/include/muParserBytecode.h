/*
                 __________                                      
    _____   __ __\______   \_____  _______  ______  ____ _______ 
   /     \ |  |  \|     ___/\__  \ \_  __ \/  ___/_/ __ \\_  __ \
  |  Y Y  \|  |  /|    |     / __ \_|  | \/\___ \ \  ___/ |  | \/
  |__|_|  /|____/ |____|    (____  /|__|  /____  > \___  >|__|   
        \/                       \/            \/      \/        
  Copyright (C) 2004-2013 Ingo Berg

  Permission is hereby granted, free of charge, to any person obtaining a copy of this 
  software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify, 
  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
  permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or 
  substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
*/ 
  
#ifndef MU_PARSER_BYTECODE_H
#define MU_PARSER_BYTECODE_H
  
#include <cassert>
#include <string>
#include <stack>
#include <vector>
  
#include "muParserDef.h"
#include "muParserError.h"
#include "muParserToken.h"
  
/** \file
    \brief Definition of the parser bytecode class.
*/ 
  
{
  
  {
    
    
     
    {
      
      {
        
        
        
      
       
      {
        
          // Note: generic_fun_type is merely a placeholder. The real type could be 
          //       anything between gun_type1 and fun_type9. I can't use a void
          //       pointer due to constraints in the ANSI standard which allows
          //       data pointers and function pointers to differ in size.
        generic_fun_type ptr;
        
         
       
       
      {
        
        
       
     
   
  
  /** \brief Bytecode implementation of the Math Parser.

  The bytecode contains the formula converted to revers polish notation stored in a continious
  memory area. Associated with this data are operator codes, variable pointers, constant 
  values and function pointers. Those are necessary in order to calculate the result.
  All those data items will be casted to the underlying datatype of the bytecode.

  \author (C) 2004-2013 Ingo Berg 
*/ 
    class ParserByteCode 
  {
  
    /** \brief Token type for internal use only. */ 
    typedef ParserToken < value_type, string_type > token_type;
    
    /** \brief Token vector for storing the RPN. */ 
    typedef std::vector < SToken > rpn_type;
    
    /** \brief Position in the Calculation array. */ 
    unsigned m_iStackPos;
    
    /** \brief Maximum size needed for the stack. */ 
      std::size_t m_iMaxStackSize;
    
    /** \brief The actual rpn storage. */ 
      rpn_type m_vRPN;
    
    
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  



#endif  /* 
  