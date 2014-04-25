#ifndef OUTPUT_H
#define OUTPUT_H
#include <vector>
enum typeVertex {IMAGE,FILTER};
enum typeFilter{NONE,F1,F2,F3,F4,F5,F6};
class Output{
public:
short id;
typeVertex type;
int m;
typeFilter filterId;
};
#endif