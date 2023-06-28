
#include "heshWithSalt.h"
#include <stdlib.h.>
string normalLine = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~}|\\{[]^-`:;<=>?@!\"#$%&\'()*+,-./";
string cryptedLine = "mdl|cajoz~{wpyrusvktqhei`bnxf}gUHF[WPMR^GCAITY\_]OEXSBJNKQ@VDLZ.\"*?<-50&$;/:%'#2,7(>!8)14=3+69";

string crypt(string line)
{
    int i = 0;
    string result = "";
    for (i = 0; i < line.size(); i++)
        result.push_back(cryptedLine[normalLine.find(line[i])]);

    return result;
}


void generateSalt(string& resul) {

    srand(time(NULL)); 
    while (resul.length() < 16) {
        
        char c = rand() % 94 + 33;
        resul += c;
    }
  

}