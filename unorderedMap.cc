/*
 * =====================================================================================
 *
 *       Filename:  unorderedMap.cc
 *
 *    Description:  unorderedMap 
 *
 *        Version:  1.0
 *        Created:  05/12/2015 02:19:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void){

    unordered_map<string,double> mymap = {
        {"mom",5.4},
        {"dad",6.1},
        {"bro",5.9}};
    
    string input;
    cout<<"who?";

    getline(cin,input);

    unordered_map<string,double>::const_iterator got = mymap.find(input);
    if(got == mymap.end())
        cout<< "not found"<<endl;
    else
        cout<< got->first << "is" << got->second << endl;
    
    return 0;
}
