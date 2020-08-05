#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Tokenizer
{
public:
    static vector<string> split(const string haystack, string separator);
    static string join(vector<string> tokens, string connector = "");
};
#endif