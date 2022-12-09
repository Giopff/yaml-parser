#include "yaml-parser.h"

std::string TrimFunction(std::string str)
{
    const char *typeOfWhitespaces = " ";
    str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
    str.erase(0, str.find_first_not_of(typeOfWhitespaces));
    return str;
}

std::string isStr(std::string input)
{
    input = TrimFunction(input);
    if (input[input.size() - 1] == '\n')
    {
        input.erase(input.size() - 1, 1);
    }
    if (input[0] == '"' && input[input.size() - 1] == '"')
    {
        return input.substr(1, input.size() - 2);
    }
}

int isInt(std::string input)
{
    int isTrue = 0;
    input = TrimFunction(input);
    if (input[input.size() - 1] == '\n')
    {
        input.erase(input.size() - 1, 1);
    }
    for (char i : input)
    {
        if (isdigit(i))
        {
            isTrue = 1;
        }
        else
        {
            isTrue = 0;
            break;
        }
    }
    if (isTrue)
    {
        return stoi(input);
    }
    else
    {
        return 0;
    }
}
double isFloat(std::string input)
{
    input = TrimFunction(input);
    const std::string copy = input;

    if (input[input.size() - 1] == '\n')
    {
        input.erase(input.size() - 1, 1);
    }
    int isTrue = 0;
    for (char i : input)
        if (i == '.')
        {
            input.erase(input.find('.'), 1);
            for (char i : input)
            {
                if (isdigit(i))
                {
                    isTrue = 1;
                }
                else
                {
                    isTrue = 0;
                    break;
                }
            }
            if (isTrue)
            {
                return stof(copy);
            }
            else
            {
                return 0;
            }
        }
}

int getSpaces(std::string str)
{
    int num = 0;
    int Spaces = 0;
    while (str[num++] == ' ')
        Spaces++;
    return Spaces;
}

std::string dataP(std::string str)
{
    return str.substr(str.find_last_of(":") + 2);
}

std::string findVal(int spaces, std::vector<std::string> name, std::string looped, int num)
{
    if (looped.substr(0, (std::string(spaces, ' ') + name[num]).size()) == (std::string(spaces, ' ') + name[num]))
    {
        return looped;
    }
    return "";
}

std::string parse(std::string name, std::vector<std::string> index)
{
    std::fstream file;
    std::string line;
    file.open(name, std::ios::in);
    int num = 0;
    int len = index.size();
    while (getline(file, line))
    {

        if (findVal(num * 2, index, line, num) != "")
        {

            if (num == index.size() - 1)
            {
                return dataP(findVal(num * 2, index, line, num));
                break;
            }
            num++;
        }
    }

    return "error";
}

std::string parse(std::string name, std::vector<std::string> index, int listIndex)
{
    std::fstream file;
    std::string line;
    file.open(name, std::ios::in);
    int num = 0;
    int counter = 0;
    int len = index.size();
    while (getline(file, line))
    {
        if (findVal(num * 2, index, line, num) != "")
        {
            num++;
        }
        else if (line.substr(0, line.find('-') + 2) == (std::string(num * 2, ' ') + "- "))
        {
            if (counter == listIndex)
            {
                return line.substr(line.find('-') + 2);
            }
            counter++;
        }
    }

    return "error";
}