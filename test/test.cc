#include "../lib/yaml-parser.h"


using namespace std;
int main()
{
    cout << isInt(parse("test.yaml", {"ID", "children"}, 2)) + 2 << endl;
    cout << isFloat(parse("test.yaml", {"ID", "wife", "age"})) + 0.3 << endl;
    cout << isStr(parse("test.yaml", {"ID", "wife", "surname"})) + "2" << endl;
    cout << parse("test.yaml", {"ID", "wife", "surname"}).size() << endl;
}