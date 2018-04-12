# Compiler-Design

<h3>Aim : Design a C Compiler</h3>

<h2> Course : Compiler Design Lab (CO351)</h2>
<h3>Team : </h3>
<h5>1. Arvind Ramachandran - 15CO111<br>
    2. Aswanth P. P. - 15CO112 </h5>

<h3>Module</h3>
<h4> 1. Lexical Analyzer</h4>Lexical Analysis is the first phase of compiler also known as scanner. It converts the input program into a sequence of Tokens.It can be implemented with the Deterministic finite Automata.

<h4> 2. Syntax Analyzer</h4>Syntax Analysis or Parsing is the second phase,i.e. after lexical analysis. It checks the syntactical structure of the given input,i.e. whether the given input is in the correct syntax (of the language in which the input has been written) or not.It does so by building a data structure, called a Parse tree or Syntax tree.The parse tree is constructed by using the pre-defined Grammar of the language and the input string.If the given input string can be produced with the help of the syntax tree (in the derivation process),the input string is found to be in the correct syntax. 

<h4> 3. Semantic Analyzer</h4>Semantic analysis is the task of ensuring that the declarations and statements of a program are semantically correct, i.e,that their meaning is clear and consistent with the way in which control structures and data types are supposed to be used.

<h4> 4. Intermediate Code Generator</h4> The front end of a compiler translates a source program into an independent intermediate code, then the back end of the compiler uses this intermediate code to generate the target code.Intermediate code can be either language specific (e.g., Byte Code for Java) or language independent (three-address code).
<h5>Three-Address Code</h5>
Intermediate code generator receives input from its predecessor phase, semantic analyzer, in the form of an annotated syntax tree. That syntax tree then can be converted into a linear representation, e.g., postfix notation. Intermediate code tends to be machine independent code. Therefore, code generator assumes to have unlimited number of memory storage (register) to generate code.
