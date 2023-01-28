Localization
-------------

A critical aspect of localization is that you should never put any native-language string literals in your source code, except maybe for debug strings targetd at the developer. 

If there is any chance that your program will be used in a non-Western character set context (hint: there is!), you should use wide characters from the beginning.

wchar_t do not have a standardized size. Most compilers will use either 16 or 32 bits. To help solve this, there exists char16_t and
char32_t. 

The Universal Character Set (UCS)—defined by the International Standard ISO 10646—and Unicode are both standardized sets of characters. They contain around one hundred thousand abstract characters, each identified by an unambiguous name and a code point. The same characters with the same numbers exist in both standards. Both have specific encodings that you can use. For example, UTF-8 is an example of a Unicode encoding where Unicode characters are encoded using one to four 8-bit bytes. UTF-16 encodes Unicode characters as one or two 16-bit values, and UTF-32 encodes Unicode characters as exactly 32 bits.


Regular Expressions
---------------------

Terminology
============
* Pattern: The actual regular expression is a pattern represented by a string.
* Match: Determines whether there is a match between a given regular expression and all of the characters in a given sequence [first, last).
* Search: Determines whether there is some substring within a given sequence [first, last) that matches a given regular expression.
* Replace: Identifies substrings in a given sequence, and replaces them with a corresponding new substring computed from another pattern, called a substitution pattern.

Anchors
=======
* ^ characer matches the position immediately following a line termination character. 
* $ matches the position of a line termination character. 
Example: ^test$ matches only the string test, and not strings that
contain test somewhere in the line. 

Wildcards
=========
* . can be used to match any character except a newline character. 
Example a.c will match abc, a5c but not ab5c, ac, etc. 

Alternation
===========
* The | character can be used to specify the "or" relationship. For example a|b matches a or b. 

Grouping
========
* () are used to mark subexpressions. 
Example (.)(ab|cd)(.) is a four character expression. The first character can be anything, the second and third characters are either 'ab' or 'cd' and the last character can be anything. 

Repetition
===========
* \* matches the preceding part zero or more times. a*b
* \+ matches the preceding part one or more times. 
* ? matches the preceding part zero or one time.
* \{...} represents a bounded remeat. a{n} matches a repeatedly exactly n times; a{n,} matches n or more times, and a{n,m}. 

Character Set Matches
=====================
[c2c2c3...cn] is a character set that means any of these character. 
[^c1c2c3...cn] is a character set that means any but these characters.
[a-zA-z] range sets. 

you can also use character classes specified as [:class:] to get a set
as [[:class:]]. Common classes are digit, alpha, alum, lower, upper, etc. 

Word Boundaries
================
They are the characters [A-Za-z0-9_]

Back References
===============
Allows you to reference a captured group inside the regurlat expression itself. \n refers to the nth captured group.

Lookahead
=========
A lookahead allows you to match a pattern based on the next character beyond the pattern.

?= positive lookahead
?! negative lookahead

Example a(?=b) contains a positive lookahead to match a letter a followed by a b, but b is not consumed so it does not become part of the match. 

Regular Expressions and Raw String Literals
===========================================
Use raw strings since c++ has its own special characters for strings. 
R""

regex_replace escape sequences
===============================
* $n The string matching the n-th capture group
* $& The string matching the entire regular expression
* $` The part of the input sequence that appears to the left of the substring matching the regular expression.
* $' The par of the input sequence that appears to the right of the substring matching the regular expression
* $$ A single dollar sign. 

As a first example, take the following HTML source string,


     <body><h1>Header</h1><p>Some text</p></body>
and the regular expression,


     <h1>(.*)</h1><p>(.*)</p>

* $1 replaced with Header
* $2 replaced with Some text
* $& <h1>Header</h1><p>Some text</p>
* $` <body>
* $' </body>