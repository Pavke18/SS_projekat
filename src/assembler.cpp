#include "../inc/code.h"
#include<iostream>
#include<cstring>

using namespace std;

extern FILE* yyin;
extern int yyparse();
extern int red;
Code code;
bool prviProlaz;
bool gotovo=false;

int main(int argc, char* argv[]){
    const char* izlazniFajl=nullptr;
    if(argc<2){
        cout<<"Unesite naziv fajla";
        return -1;
    }
    else{
        if(argc==4 && strcmp(argv[1], "-o")==0){
            izlazniFajl=argv[2];
            yyin=fopen(argv[3], "r");
        }
        else{
            yyin=fopen(argv[2], "r");
        }
        if(yyin==nullptr){
            cout<<"Ulazni fajl "<<argv[3]<<" nije moguce otvoriti";
            return -2;
        }
    }

    //prvi prolaz
    prviProlaz=true;
    yyparse();
    fseek(yyin, 0, SEEK_SET);
    //drugi prolaz
    red=0;
    prviProlaz=false;
    yyparse();

    if(izlazniFajl!=nullptr)
        code.upisiUFajl(izlazniFajl);
    else{
        cout<<"Niste uneli izlazni fajl! ";
        return -3;
    }
    return 0;
}