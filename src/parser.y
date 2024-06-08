%{
    #include<cstdio>
    #include<string>
    #include<iostream>
    #include<vector>

    #include "code.h"

    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;
    extern Code code;

    void yyerror(const char* s);

    struct sym_lit{ //koriste literali i simboli kod word direktive
	    bool jesteSimbol;
	    string simbol;
	    int vrednost;
    };

    extern int red; 
    unsigned int pc=0;
    vector<string> symList; //lista simbola 
    vector<sym_lit> symLitList; //lista simbola i literala
    

    extern bool gotovo;
    extern bool prviProlaz;

    enum ADDR{
        NEPOSR=0, REGDIR=1, REGIND=2, REGINDPOM=3, MEM=4, REGDIRPOM=5
    };

    typedef struct Operand{
        int reg;
        unsigned short vrednost;
        int up; 
        ADDR adresiranje;
        bool jesteSimbol=false;
        string simbol;
        int tipRel;
    } Operand;
   
    Operand trenOp;
%}

%union {
	int ival;
	char *sval;
}

%token GLOBAL EXTERN SECTION WORD SKIP EQU END
%token<sval> SYMBOL 
%token<ival> NUMBER
%token<ival> REG
%token PLUS MINUS
%token COLON DOT COMMA STAR COMMENT DOLLAR PERCENT BRACKET_L BRACKET_R SQBRACKET_L SQBRACKET_R MULTIP 
%token NOVI_RED QUIT 
%token JMP JEQ JNE JGT CALL   //jmp_instr
%token PUSH POP INT NOT  //instr1
%token HALT RET IRET  //instr0
%token XCHG ADD SUB MUL DIV CMP AND OR XOR TEST SHL SHR //instr2
%token LDR STR

%left PLUS MINUS
%left MULTIP DIVIDE
%type Instrukcija
%type Direktiva
%type sym_list
%type instr0
%type instr1
%type instr2
%type jmp_instr
%type instr_mem
%type<ival> Literal 
%start program

%%

program:
	line 
	| line program
;

line:
  label
  | inst_dir
  | label inst_dir
  | COMMENT
  | NOVI_RED;

label:
     SYMBOL COLON { //cout<<"Labelaa red="<<red<<endl;
     if(prviProlaz) code.dodajSimbol(string($1), code.trenSekcija, pc, false); };

inst_dir:
  Instrukcija
  | DOT Direktiva;

Direktiva:
  GLOBAL sym_list {
        if(!prviProlaz){
            for(std::string simb:symList){
                code.tabelaSimbola[simb].globalan=true;
            }
        } }
  | EXTERN sym_list {
          if(!prviProlaz){
              for(std::string simb:symList){
                  if(!code.postojiSimbol(simb)) code.dodajSimbol(simb, "UNDEF", 0, true); 
              }
          }}
  | SECTION SYMBOL { 
      if(!prviProlaz){
          //cout<<".SEKCIJA "<<$2<<"drugiProlaz red="<<red<<" pc="<<pc<<" trenSekcija="<<code.trenSekcija<<endl;
          code.dodajSekciju(); //dodajem prethodnu sekciju
          code.trenSekcija=$2;
          pc=0;
      }
      else{
          //cout<<".SEKCIJA "<<$2<<"prviProlaz red="<<red<<" pc="<<pc<<" trenSekcija="<<code.trenSekcija<<endl;
          code.promeniVelicinu(code.trenSekcija, pc); //postavlja velicinu prethodne sekcije
          code.trenSekcija=$2; //i menjam da je sada trenutna sekcija ova $2
          pc=0;
          code.dodajSimbol($2,$2,0, false); //dodajem sekciju u tabelu simbola
      }
  }
  | WORD sym_lit_list {
    for(sym_lit i:symLitList){
        //cout<<".WORD jesteSimbol="<<i.jesteSimbol<<" vrednost "<<i.vrednost<<" simbol="<<i.simbol<<" red="<<red<<endl;
        if(!prviProlaz){ //u drugom prolazu
            if(i.jesteSimbol){
                //cout<<"DODAJEM SIMBOL U TABELU REALOKACIJA "<<i.simbol<<endl;
                code.dodajRel(i.simbol, code.trenSekcija, pc, 0); //za simbole se dodaje apsolutna realokacija 
            }
            else{
                unsigned short w=(unsigned short) i.vrednost;
                code.dodajWord(w); //asemblerska direktiva alocirani prostor inicijalizujje vrednoscu literala
            }
        }
        pc+=2;
    } 
  }
  | SKIP Literal { 
      pc+=$2;
      //cout<<".SKIP "<<$2<<" red"<<red<<endl;
      if(!prviProlaz){
          for(int i=0; i<$2; i++){
              code.dodajByte(0); //asemblerska direktiva alocirani prostor inicijalizuje nulama
          }
      }
  }
  | EQU SYMBOL COMMA Literal { 
      //cout<<".EQU "<<$2<<" "<<$4<<" red="<<red<<endl;
      if(prviProlaz) code.dodajSimbol($2, "ABS", $4, false);
   }
  | END{
      if(prviProlaz){
        //cout<<"END U PRVOM PROLAZU"<<" red="<<red<<" pc="<<pc<<endl;
        code.promeniVelicinu(code.trenSekcija, pc); //menjam velicinu zadnje sekcije
      }
      else{
        //cout<<"END U DRUGOM PROLAZU"<<" red="<<red<<" pc="<<pc<<endl;
        code.dodajSekciju(); //dodajem poslednju sekciju
      }
      YYACCEPT;
  };

Instrukcija:
  instr0 { pc += 1; }
  | jmp_instr operand_jmp { 
      pc+=3;
      if(!prviProlaz){
        code.dodajByte(trenOp.reg | 0xF0); //F0=1111 0000
        code.dodajByte(trenOp.adresiranje | (trenOp.up << 4));
        if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
            if(trenOp.jesteSimbol){
                code.dodajRel(trenOp.simbol,code.trenSekcija, (unsigned char) pc, trenOp.tipRel);
            }
            else{
              code.dodajWord(trenOp.vrednost);
            }
        }
      }
       if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
           pc+=2;
       }
    }
  | instr1 REG { pc+=2; if(!prviProlaz) code.dodajByte(0x0F | ($2 << 4)); }
  | instr2 REG COMMA REG { 
   
   pc+=2; if(!prviProlaz) code.dodajByte($4 | ($2<<4)); }
  | instr_mem REG COMMA operand_mem { 
      pc+=3;
      if(!prviProlaz){
        code.dodajByte(trenOp.reg | ($2 << 4));
        code.dodajByte(trenOp.adresiranje | (trenOp.up << 4));
        if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
            if(trenOp.jesteSimbol){
                code.dodajRel(trenOp.simbol, code.trenSekcija, (unsigned char)pc, trenOp.tipRel);
            }
            else{
                code.dodajWord(trenOp.vrednost);
            }
        }
      }
      if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
        pc+=2;          
      }
    }
  | push_pop REG { 
      pc+=3;
      if(!prviProlaz){
          code.dodajByte(0x6 | ($2 << 4)); //sp=r6
          code.dodajByte(REGIND | (trenOp.up << 4));
      }
    };

instr0:
  HALT    { if(!prviProlaz) code.dodajByte(0x00); }
  | IRET  { if(!prviProlaz) code.dodajByte(0x20); }
  | RET   { if(!prviProlaz) code.dodajByte(0x40); };

jmp_instr:
  CALL    { if(!prviProlaz)code.dodajByte(0x30); }
  | JMP   { if(!prviProlaz)code.dodajByte(0x50); }
  | JEQ   { if(!prviProlaz)code.dodajByte(0x51); }
  | JNE   { if(!prviProlaz)code.dodajByte(0x52); }
  | JGT   { if(!prviProlaz)code.dodajByte(0x53); };

instr1: 
       INT  { if(!prviProlaz) code.dodajByte(0x10); }
       | NOT  { if(!prviProlaz) code.dodajByte(0x80); };

instr2:
       XCHG   { if(!prviProlaz) code.dodajByte(0x60); }
       | ADD  { if(!prviProlaz) code.dodajByte(0x70); }
       | SUB  { if(!prviProlaz) code.dodajByte(0x71); }
       | MUL  { if(!prviProlaz) code.dodajByte(0x72); }
       | DIV  { if(!prviProlaz) code.dodajByte(0x73); }
       | CMP  { if(!prviProlaz) code.dodajByte(0x74); }
       | AND  { if(!prviProlaz) code.dodajByte(0x81); }
       | OR   { if(!prviProlaz) code.dodajByte(0x82); }
       | XOR  { if(!prviProlaz) code.dodajByte(0x83); }
       | TEST { if(!prviProlaz) code.dodajByte(0x84); }
       | SHL  { if(!prviProlaz) code.dodajByte(0x90); }
       | SHR  { if(!prviProlaz) code.dodajByte(0x91); };

instr_mem:
  LDR   { if(!prviProlaz) code.dodajByte(0xA0); }
  | STR { if(!prviProlaz) code.dodajByte(0xB0); };

push_pop:
   PUSH  { if(!prviProlaz) {code.dodajByte(0xB0); trenOp.up=0x1;} }
  | POP  { if(!prviProlaz) {code.dodajByte(0xA0); trenOp.up=0x4;} };

operand_jmp:
  NUMBER { trenOp.adresiranje=NEPOSR; trenOp.vrednost=$1; trenOp.reg=0xF; trenOp.jesteSimbol=false; }
  | SYMBOL { trenOp.adresiranje=NEPOSR; trenOp.reg=0xF; trenOp.jesteSimbol=true; trenOp.simbol=$1; trenOp.tipRel=0; }
  | PERCENT SYMBOL { trenOp.adresiranje=REGDIRPOM; trenOp.reg=7; trenOp.simbol=$2; trenOp.jesteSimbol=true; trenOp.tipRel=1; }
  | MULTIP NUMBER { trenOp.adresiranje=MEM; trenOp.vrednost=$2; trenOp.reg=0xF; trenOp.jesteSimbol=false; }
  | MULTIP SYMBOL { trenOp.adresiranje=MEM; trenOp.reg=0xF; trenOp.simbol=$2; trenOp.jesteSimbol=true; trenOp.tipRel=0; }
  | MULTIP REG { trenOp.adresiranje=REGDIR; trenOp.reg=$2; trenOp.vrednost=0xFF; trenOp.jesteSimbol=false; }
  | MULTIP SQBRACKET_L REG SQBRACKET_R { trenOp.adresiranje=REGIND; trenOp.reg=$3; trenOp.vrednost=0xFF; trenOp.up=0; trenOp.jesteSimbol=false; }
  | MULTIP SQBRACKET_L REG PLUS NUMBER SQBRACKET_R { trenOp.adresiranje=REGINDPOM; trenOp.reg=$3; trenOp.vrednost=$5; trenOp.up=0; trenOp.jesteSimbol=false; }
  | MULTIP SQBRACKET_L REG PLUS SYMBOL SQBRACKET_R { trenOp.adresiranje=REGINDPOM; trenOp.reg=$3; trenOp.jesteSimbol=true; trenOp.up=0; trenOp.simbol=$5; trenOp.tipRel=0; };

operand_mem:
  DOLLAR NUMBER { trenOp.adresiranje=NEPOSR; trenOp.simbol=$2; trenOp.reg=0xF; trenOp.up=0; trenOp.jesteSimbol=false; }
  | DOLLAR SYMBOL { trenOp.adresiranje=NEPOSR; trenOp.simbol=$2; trenOp.tipRel=0; trenOp.reg=0xF; trenOp.jesteSimbol=false; }
  | NUMBER { trenOp.adresiranje=MEM; trenOp.vrednost=$1; trenOp.reg=0xF; trenOp.jesteSimbol=false; }
  | SYMBOL { trenOp.adresiranje=MEM; trenOp.reg=0x0F; trenOp.jesteSimbol=true; trenOp.simbol=$1; trenOp.tipRel=0; }
  | PERCENT SYMBOL { trenOp.adresiranje=REGINDPOM; trenOp.reg=7; trenOp.up=0; trenOp.tipRel=1; trenOp.simbol=$2; trenOp.jesteSimbol=true; }
  | REG { trenOp.adresiranje=REGDIR; trenOp.reg=$1; trenOp.jesteSimbol=false; }
  | SQBRACKET_L REG SQBRACKET_R { trenOp.adresiranje=REGIND; trenOp.reg=$2; trenOp.up=0; trenOp.jesteSimbol=false; }
  | SQBRACKET_L REG PLUS Literal SQBRACKET_R { trenOp.adresiranje=REGINDPOM; trenOp.up=0; trenOp.reg=$2; trenOp. vrednost=$4; trenOp.jesteSimbol=false; }
  | SQBRACKET_L REG PLUS SYMBOL SQBRACKET_R { trenOp.adresiranje=REGINDPOM; trenOp.up=0; trenOp.reg=$2; trenOp.jesteSimbol=true; trenOp.simbol=$4; trenOp.tipRel=0; };

sym_list: //jedan simbol ili lista simbola
  SYMBOL { symList.clear(); symList.push_back(string($1)); }
  | sym_list COMMA SYMBOL { symList.push_back(string($3)); };

Literal:
    NUMBER { $$=$1; }
    | PLUS NUMBER { $$=$2; }
    | MINUS NUMBER { $$=-1*$2; };

sym_lit_list: //1 simbol ili 1 literal, ili vise njih odvojeni zarezom
  SYMBOL{
      sym_lit sym={true,$1};
      symLitList.clear();
      symLitList.push_back(sym);
  }
  | Literal{
      sym_lit lit={false, "", $1};
      lit.vrednost=$1;
      symLitList.clear();
      symLitList.push_back(lit);
  }
  | sym_lit_list COMMA SYMBOL{
      sym_lit sym={true, $3, 0};
      symLitList.push_back(sym);
  }
  | sym_lit_list COMMA Literal{
      sym_lit lit={false, "", $3};
      lit.vrednost=$3;
      symLitList.push_back(lit);
  };


%%

void yyerror(const char* s){
    cout << "Parse error on line " << red << ":" << s << endl;
    exit(-1);
}