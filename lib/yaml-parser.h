#ifndef YAML_PARSER
#define YAML_PARSER

#pragma once

//includes 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string TrimFunction(std::string str);

std::string isStr(std::string input);

int isInt(std::string input);
double isFloat(std::string input);

int getSpaces(std::string str);

std::string dataP(std::string str);

std::string findVal(int spaces, std::vector<std::string> name, std::string looped, int num);

std::string parse(std::string name, std::vector<std::string> index);

std::string parse(std::string name, std::vector<std::string> index, int listIndex);

#endif