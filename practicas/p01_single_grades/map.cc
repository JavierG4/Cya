#include <iostream>
#include <string.h>
#include <utility>
#include <map>
using namespace std;
int main()
{
map <int, float> Students;
// Store key value pair elements in map student
Students[101] = 50;
Students[104] = 90;
Students[101] = 60;  // duplicate key
Students[103] = 60;  // duplicate value
Students[105] = 88;
Students[102] = 68;
// access value by key in map
cout << "Students[101]=" << Students[101] << endl ;
cout << "Students[104]=" << Students[104] << endl << endl;
cout << "Size of the Map is = " << Students.size() << endl;
cout << "The Store order of the Map is =" << endl;
// iterate elements of student map
for( map<int, float>::iterator i= Students.begin(); i != Students.end(); i++)
{
cout << (*i).first << ": " << (*i).second << endl;
}
return 0;
}