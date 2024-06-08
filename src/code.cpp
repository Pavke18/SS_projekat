#include "../inc/code.h"
#include <iomanip>
#include <fstream>
extern int red;
 
Code::Code(){
    this->trenSekcija="UNDEFINED";
    Simbol s=Simbol("UNDF", 0,"UNDEFINED",0,true);
    tabelaSimbola["UNDF"]=s;
}

void Code::dodajByte(unsigned char b){
    trenCode.push_back(b);
}

void Code::dodajWord(unsigned short w){
    char w1=(char)w;
    char visi=((w1 >> 8) & 0xff);
    char nizi=(w1 & 0x00ff);
    trenCode.push_back(nizi);
    trenCode.push_back(visi);
}

void Code::dodajSimbol(string naziv,string sekcija, int vrednost, bool globalan){
    if(tabelaSimbola.find(naziv)!= tabelaSimbola.end()){
        cout<<"Greska na liniji "<<red<<" Simbol "<<naziv<<" je vec definisan"<<endl;
        exit(-1);
    }
    Simbol s=Simbol(naziv, vrednost,sekcija,0,globalan);
    tabelaSimbola[naziv]=s;
}

void Code::promeniVelicinu(string naziv, int vel){
    tabelaSimbola[naziv].velicina=vel;
}

bool Code::postojiSimbol(string naziv){
    return (tabelaSimbola.find(naziv)!=tabelaSimbola.end());
}


void Code::dodajRel(string simbol, string sekcija, int pc, int tip){ //ovu fju pozivam u drugom prolazu!
    Simbol *s;
    if(postojiSimbol(simbol)){
        s=&tabelaSimbola[simbol];
        if(s->sekcija=="ABS"){
            dodajWord(s->vrednost);
            return;
        }
    }
    else{
        dodajSimbol(simbol,"UNDEF", pc, true);
        s=&tabelaSimbola[simbol]; 
    }

    Relok r=Relok(pc,simbol,sekcija, tip);
    if(tip==0){ //apsolutno adresiranje
        if(s->globalan){
            dodajWord(0);
        }
        else{
            dodajWord(s->vrednost);
            r.simbol=s->sekcija;
        }
    }
    else if(tip==1){ //pc relativno adresiranje
        if(s->globalan){
            dodajWord(-2);
        }
        else{
            if(s->sekcija==sekcija){
                dodajWord(s->vrednost-2);
                return;
            }
            else{
                dodajWord(s->vrednost-2);
                r.simbol=s->sekcija;
            }
        }
    }
    if(tabelaRelok.find(sekcija)==tabelaRelok.end())
        tabelaRelok[sekcija]=vector<Relok>();
    tabelaRelok[sekcija].push_back(r);
}

void Code::dodajSekciju(){
    Sekcija sec=Sekcija(trenSekcija,trenCode);
    tabelaSekcija[trenSekcija]=sec;
    trenCode.clear();
}

void Code::upisiUFajl(const char* nazivFajla){
    ofstream out;
    out.open(nazivFajla);
    out<<"Tabela simbola:"<< endl;
    out<<left<<setw(15)<<"Naziv"<<left<<setw(15)<<"Vrednost"<<left<<setw(15)<<"Sekcija"<<left<<setw(5)<<"l/g"<<left<<setw(15)<<"Velicina"<< endl;
    for(auto i=tabelaSimbola.begin(); i!=tabelaSimbola.end();++i){
        Simbol s=i->second;
        if(i==tabelaSimbola.begin()){}
        else{
        out<<left<<setw(15)<<s.naziv<<left<<setw(15)<<s.vrednost<<left<<setw(15)<<s.sekcija<<left<<setw(5)<<(s.globalan?'g':'l')<<left<<setw(15)<<s.velicina<<endl;
        }
    }

    out<<"\n";
    out<<"Tabela realokacija"<<endl;
    for(auto i =tabelaRelok.begin(); i!=tabelaRelok.end();i++){
       out<< "[."<<i->first<<"]"<<endl;
       out<<left<<setw(15)<<"Simbol"<<left<<setw(15)<<"Sekcija"<<left<<setw(10)<<"Offset"<<left<<setw(5)<<"Tip"<<endl;
       for(Relok r:i->second){
           out<<left<<setw(15)<<r.simbol<<left<<setw(15)<<r.sekcija<<left<<setw(10)<<r.offset<<left<<setw(5)<<(r.tip==0?"ABS":(r.tip==1?"PCREL":"UNKNOWN"))<<endl;
       }
    }

    out<<"\n";
    out<<"Sadrzaj:"<<endl;
    for(auto i=tabelaSekcija.begin();i!=tabelaSekcija.end();++i){
        out<<i->first<<":";
        for(unsigned char b:i->second.code){
            out<<setw(2)<<setfill('0')<<hex<<(int)b<<" ";
        }
        out<<endl;
    }

    out<<"\n";
    out.close();
}