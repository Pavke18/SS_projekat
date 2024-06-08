#ifndef CODE_H
#define CODE_H

#include<iostream>
#include <map>
#include <vector>

using namespace std;
extern int red;

enum TipRell{ABS, PCREL};

struct Simbol{ 
    string naziv;
    int vrednost;
    string sekcija;
    int velicina;
    bool globalan;

    Simbol(){ 
        this->velicina=0;
        this->sekcija="UNDF";
        this->vrednost=0;
    }
    Simbol(string naziv, int vrednost=0, string sekcija="UND", int velicina=0, bool globalan=false){
        this->naziv=naziv;
        this->vrednost=vrednost;
        this->sekcija=sekcija;
        this->velicina=velicina;
        this->globalan=globalan;
    }
};

struct Relok{ 
    int offset;
    string simbol;
    string sekcija;
    TipRell tip;
   
    Relok(int offset, string simbol, string sekcija, int tip){
        this->offset=offset;
        this->simbol=simbol;
        this->sekcija=sekcija;
        this->tip=(TipRell)tip; 
    }
};

struct Sekcija{
    string nazivSekcije;
    vector<unsigned char> code;
    Sekcija(){
        
    }
    Sekcija(string nazivSekcije,vector<unsigned char> code){
        this->nazivSekcije=nazivSekcije;
        this->code=code;
    }
};


class Code{
public:
    map<string, Simbol> tabelaSimbola;
    map<string, Sekcija> tabelaSekcija;
    map<string, vector<Relok>> tabelaRelok;
    string trenSekcija;
    vector<unsigned char> trenCode;

    Code();
    void dodajByte(unsigned char b);
    void dodajWord(unsigned short w);

    void dodajSimbol(string naziv,string sekcija, int vrednost, bool globalan);
    void promeniVelicinu(string naziv, int vel);
    bool postojiSimbol(string naziv);

    void dodajRel(string simbol, string sekcija, int pc, int tip);

    void dodajSekciju();

    void upisiUFajl(const char* nazivFajla);
};

#endif