/* lexical rules for bww2tex
   version 2.0
   by Walt Innes {walt@slac.stanford.edu}
*/
/* {QSTRING},[\(][TYMFIX][RLCN],{ANMB}*,{ANMB}*,[ a-zA-z]*,{ANMB}*,{ANMB}*,[0-9,]*[\)]{TSEP}*  */
%{
#define MAXLEN 1000
#define YYSTYPE char*
#include "y.tab.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "tokens.h"

/* _WIN32 definition added for use with MS VC++ compiler. */
#ifdef _WIN32
#include <stdlib.h>
#include <malloc.h>
#include <io.h>
#endif

char *addpit( char *, size_t, char * );
void unpitch( char *, size_t );
static int tiepending = 0;
static int letpending = 0;
char txttype, align;
char *font;
char *asciitext;
int pfx, pfy, fontsize, fontstyle;
char sh, sv, scf, jus, ori;
int mrl, mrr, mrt, mrb;
%}


TSEP [ \a\n\t\r\f\v\b\032\xA]
NNSEP [ \a\t\r\f\v\b\032]
SEP [ \a\n\r\f\v\b\032\xA]
NBLINE [a-zA-Z\^_\.,!0-9\']
/* THEME ["THEME"] */
LPITCH ([bcdefBCDEF]|([lhLH][gaGA]))
LCPITCH ([bcdef]|([lh][ga]))
UCPITCH ([BCDEF]|([LH][GA]))
NEPITCH ([bcdfBCDEF]|([lhLH][gaGA]))
QSTRING \"[^\"\n]*\"
NNQSTRING \"[^\"\n]+\"
ANMB [0-9]
ALET [a-zA-Z]
FMATTER ((Mappings)|(Durations)|(FontSizes))
AFM (Bagpipe|MIDI|Frequency|Grace|Font|Tune|Variation)
LREP (dalsegno|dacapoalfine|dacapoalcoda|_\'|bis_\')[ \a\n\t\r\f\v\b\032\xA]+

%%

{NNSEP}*{ALET}*{FMATTER},[\(][0-9,]*[\)]{TSEP}*   {                                  }
{NNSEP}*"FontSizes,"[\(][0-9,]*[\)][\n]           {                                  }
{NNSEP}*"TuneTempo,"{ANMB}*[\n]     {yylval = (char *) malloc(MAXLEN);
    strncpy(yylval,yytext,yyleng-1); strcpy(yylval+yyleng-1,"");     return COMMENT; }
{NNSEP}*"VariationTempo,"[\(][0-9,]*[\)]{TSEP}*   {                                  }
{NNSEP}*"TuneFormat,"[\(][a-zA-Z0-9,]*[\)]{TSEP}* { asciitext = (char *) malloc(MAXLEN);
    if(sscanf(yytext,"%[^,],(%c,%c,%c,%c,%i,%i,%i,%i,%c",asciitext,&sh,&sv,&scf,&jus,&mrl,&mrr,&mrt,&mrb,&ori) != EOF )
          { if( ori == 'L' ) { yylval = (char *) malloc(MAXLEN);
                               strcpy(yylval,realwide);              return FORMAT;  }
          }              free(asciitext);  }
{NNSEP}*"Bagpipe Reader:"[0-9\.]*{TSEP}*     {yylval = (char *) malloc(MAXLEN);
    strncpy(yylval,yytext,yyleng-1); strcpy(yylval+yyleng-1,"");     return COMMENT; }
{NNSEP}*"Bagpipe Music Writer Gold:"[0-9\.]*{TSEP}* {yylval = (char *) malloc(MAXLEN);
    strncpy(yylval,yytext,yyleng-1); strcpy(yylval+yyleng-1,"");     return COMMENT; }
{NNSEP}*"Bagpipe Musicworks Gold:"[0-9\.:]*{TSEP}*  {yylval = (char *) malloc(MAXLEN);
    strncpy(yylval,yytext,yyleng-1); strcpy(yylval+yyleng-1,"");     return COMMENT; }
{TSEP}*"Bagpipe"{TSEP}*                           {   unput(' ');                    }
{TSEP}*"Gold"{TSEP}*                              {   unput(' ');                    }
{TSEP}*"Writer"{TSEP}*                            {   unput(' ');                    }
{TSEP}*"Works"{TSEP}*                             {   unput(' ');                    }
[\t]{TSEP}*     {unput(' ');                             return BEAT;      }
[\"]{ANMB}+[\"] {yylval = (char *) malloc(MAXLEN);
                     strncpy(yylval,yytext+1,yyleng-2);
                     strcpy(yylval+yyleng-2,"");         return NUMBER;    }
{QSTRING}       {yylval = (char *) malloc(MAXLEN);
                     strncpy(yylval,yytext+1,yyleng-2);
                     strcpy(yylval+yyleng-2,"");         return TXT;       }
{NNQSTRING},\(.*\){TSEP}*            {
    asciitext = (char *) malloc(MAXLEN); font = (char *) malloc(MAXLEN);
    if(sscanf(yytext,"\"%[^\"]\",(%c,%c,%i,%i,%[a-zA-Z ],%i,%i",asciitext,&txttype,&align,&pfx,&pfy,font,&fontsize,&fontstyle) != EOF )
                       { yylval = (char *) malloc(MAXLEN);    *yylval = '\0' ;
                         if( align == 'R' || align == 'C' ) strcat(yylval,"\\hss ");
                         if( fontsize > 14 )                 strcat(yylval,"\\moyen ");
                         else                                 strcat(yylval,"\\rm ");
                                                              strcat(yylval,asciitext);
                         if( align != 'R' )                  strcat(yylval,"\\hss ");
                         if( txttype == 'T' )                return TITLE;
                         else if ( txttype == 'Y' )          return TUNETYPE;
                         else if ( txttype == 'M' )          return COMPOSER;
                         else                                 return ANTXT;
                       }  free(asciitext); free(font);                     }
,[\(].*[\)]{TSEP}*                          {                              }
{TSEP}*[&]/{TSEP}*    {yylval=reprmorceau;               return CLEFT;     }
{TSEP}+"^"[tT]{NEPITCH}{TSEP}+[&]/{TSEP}*  {
     yylval=addpit(yytext, yyleng, itenu);               return TIECLEFT;  }
{TSEP}+"^te"{TSEP}+[&]/{TSEP}*  {
     if(tiepending){ tiepending = 0; yylval=tten; unput(' ');
                     unput('&'); unput(' ');             return ETIE;      }
     else        { yylval=addpit(yytext, yyleng, itenu); return TIECLEFT; }}
[!]/{TSEP}*    {yylval=xbarre;                           return BAR;       }
{TSEP}+"I!''"/{TSEP}* {yylval=leftrepeatsymbol;          return BAR;       }
{TSEP}+"^"[tT]{NEPITCH}{TSEP}+[!]/{TSEP}*  {
       yylval=addpit(yytext, yyleng, itenu);             return TIEXBAR;   }
{TSEP}+"^te"{TSEP}+[!]/{TSEP}*  {
     if(tiepending){ tiepending = 0; yylval=tten; unput(' ');
                     unput('!'); unput(' ');             return ETIE;      }
     else          {
       yylval=addpit(yytext, yyleng, itenu);             return TIEXBAR; } }
{TSEP}+"^"[tT]{NEPITCH}{TSEP}+"I!''"/{TSEP}* {
       yylval=addpit(yytext, yyleng, itenu);             return TIELRBAR;  }
{TSEP}+"^te"{TSEP}+"I!''"/{TSEP}* {
     if(tiepending){ tiepending = 0; yylval=tten; unput(' '); unput('\'');
        unput('\''); unput('!'); unput('I');              return ETIE;    }
     else          {
       yylval=addpit(yytext, yyleng, itenu); unput(' ');   return TIELRBAR; }}
{TSEP}+"!"[tT]{TSEP}*    {yylval=alaligne; unput(' ');       return EOL;    }


{TSEP}+(!I|!!){TSEP}+/{LREP}+([&\"]|{AFM}) {yylval=setdoublebar; unput(' '); return EOL;   }
{TSEP}+"''!I"{TSEP}+/{LREP}+([&\"]|{AFM}) {yylval=setrightrepeat; unput(' '); return EOL;  }

{TSEP}+(!I|!!){TSEP}*{TSEP}+/{LREP}+[^ &\"\a\n\t\r\f\v\b\032\xA] {yylval=setdoublebar; unput(' ');  return BAR; }
{TSEP}+"''!I"{TSEP}*{TSEP}+/{LREP}+[^ &\"\a\n\t\r\f\v\b\032\xA] {yylval=setrightrepeat; unput(' '); return BAR; }

{TSEP}+(!I|!!){TSEP}*/{LREP}+ {yylval=setdoublebar; unput(' ');         return EOL;    }
{TSEP}+"''!I"{TSEP}*/{LREP}+ {yylval=setrightrepeat; unput(' ');        return EOL;    }

{TSEP}+(!I|!!){TSEP}+/([&\"]|{AFM}) {yylval=setdoublebar; unput(' '); return EOL;   }
{TSEP}+"''!I"{TSEP}+/([&\"]|{AFM}) {yylval=setrightrepeat; unput(' '); return EOL;  }

{TSEP}+(!I|!!){TSEP}*{TSEP}+/[^ &\"\a\n\t\r\f\v\b\032\xA] {yylval=setdoublebar; unput(' ');         return BAR; }
{TSEP}+"''!I"{TSEP}*{TSEP}+/[^ &\"\a\n\t\r\f\v\b\032\xA] {yylval=setrightrepeat; unput(' ');        return BAR; }

{TSEP}+(!I|!!){TSEP}* {yylval=setdoublebar; unput(' ');         return EOL;    }
{TSEP}+"''!I"{TSEP}* {yylval=setrightrepeat; unput(' ');        return EOL;    }


{TSEP}+"^"[tT]{NEPITCH}{TSEP}+"!t" {yylval=addpit(yytext, yyleng, itenu);
                                                         return TIEALA;    }
{TSEP}+"^te"{TSEP}+"!t" {
     if(tiepending){ tiepending = 0; yylval=tten; unput(' '); unput('!');
                          unput('t');  unput(' ');       return ETIE;   }
     else          {
                 yylval=addpit(yytext, yyleng, itenu);   return TIEALA; }  }
{TSEP}+"^"[tT]{NEPITCH}{TSEP}+"!I" {
                   yylval=addpit(yytext, yyleng, itenu); return TIEDBL;    }
{TSEP}+"^te"{TSEP}+"!I" {
     if(tiepending){ tiepending = 0; yylval=tten; unput(' '); unput('!');
                          unput('I');  unput(' ');       return ETIE;   }
     else          {
                   yylval=addpit(yytext, yyleng, itenu); return TIEDBL; }  }
{TSEP}+"I!"/{TSEP}* {yylval=doublebar;                   return BAR;       }
{TSEP}+"^"[tT]{NEPITCH}{TSEP}+"I!"/{TSEP}* {
       yylval=addpit(yytext, yyleng, itenu);             return TIEDBAR;   }
{TSEP}+"^te"{TSEP}+"I!"/{TSEP}* {
     if(tiepending){ tiepending = 0; yylval=tten; unput(' '); unput('I');
                          unput('!');                      return ETIE;    }
     else          {
       yylval=addpit(yytext, yyleng, itenu);             return TIEDBAR; } }
{SEP}*[\t]{TSEP}*"^t"{NEPITCH}  {yylval = addpit(yytext, yyleng, itenu);
                                                         return TIEBEAT;   }
{SEP}*[\t]{TSEP}*"^te"  {
     if(tiepending){ tiepending = 0;  unput(' '); unput('e');
                     unput('t'); unput('^'); unput(' '); return BEAT;   }
     else          {
                yylval = addpit(yytext, yyleng, itenu);  return TIEBEAT;}  }
{TSEP}*"^"[tT]{NEPITCH}{SEP}*[\t]/{TSEP}*  {
    yylval = addpit(yytext, yyleng, itenu);  unput(' '); return TIEBEAT;   }
{TSEP}*"^te"{SEP}*[\t]/{TSEP}*  {
     if(tiepending){ tiepending = 0;  unput(' '); unput('\t');
                    yylval=tten;                          return ETIE;     }
     else          { yylval = addpit(yytext, yyleng, itenu);
                                             unput(' '); return TIEBEAT; } }
{SEP}+"^"[tT]{NEPITCH} {yylval = addpit(yytext, yyleng, itenu); return TIE;}
{SEP}+"^te" {
     if(tiepending){ tiepending = 0;  yylval=tten;            return ETIE; }
     else      { yylval = addpit(yytext, yyleng, itenu); return TIE;  }    }
{SEP}+"^ts"{SEP}+{LPITCH} {yylval = addpit(yytext, yyleng, itenu);
                  tiepending = 1; unpitch(yytext, yyleng);  return EMBP;   }
{SEP}+"^3s"        {yylval = triolet; letpending=1;      return EMB;       }
{SEP}+"^3"{NEPITCH} {yylval=triolet;                     return TRIPLET;   }
{SEP}+"^3e" {
            if (letpending) { letpending=0; }
            else            {yylval=triolet;             return TRIPLET; } }
{SEP}+"\'1"    {yylval=first;                            return STARTFS;   }
{SEP}+"\'2"    {yylval= second;                          return STARTFS;   }
{SEP}+"\'si"   {yylval=sing;                             return EMB;       }
{SEP}+"\'do"   {yylval=doub;                             return EMB;       }
{SEP}+"\'bis"  {yylval=bis;                              return EMB;       }
{SEP}+"coda"   {yylval=coda;                             return EMB;       }
{SEP}+"segno"  {yylval=segno;                            return EMB;       }
{SEP}+"fine"   {yylval=fine;                             return EMB;       }
{SEP}+"dalsegno" {yylval=dalsegno;                       return REP;       }
{SEP}+"dacapoalfine" {yylval=dacapoalfine;               return REP;       }
{SEP}+"dacapoalcoda" {yylval=dacapoalcoda;               return REP;       }
{SEP}+"\'"[12]{ANMB}+ {yylval=(char *) malloc(MAXLEN);
     strncpy(yylval,yytext+2,yyleng-1);
                           strcpy(yylval+yyleng-1,"");   return STARTFS;   }
{SEP}+"_\'"     { yylval=endfs;                          return ENDFS;     }
{SEP}+"bis_\'"  { yylval=endfs;                          return ENDFS;     }
{TSEP}+"sharpf"{TSEP}+ { unput(' '); yylval = one;       return SIGNATURE; }
{TSEP}+"sharpf"{TSEP}+"sharpc"{TSEP}+ {
                               unput(' '); yylval = two; return SIGNATURE; }
[0-9]+"_"[0-9]+/{TSEP}+ { yylval = (char *) malloc(MAXLEN);
                  strncpy(yylval,yytext,yyleng+1);
                  strcat(yylval+yyleng+1,"");            return METERFRAC; }
{TSEP}+[Cc]/{TSEP}+  {yylval=meterC;                     return METER;     }
{TSEP}+[Cc]_/{TSEP}+ {yylval=allabreve;                  return METER;     }
{TSEP}+"space"/{TSEP}+  {                                                  }

"_1"  {yylval=wh ; return TIME; }
"_2"  {yylval=hh ; return TIME; }
"_4"  {yylval=ql ; return TIME; }
"_8"  {yylval=c  ; return TIME; }
"_16" {yylval=s  ; return TIME; }
"_32" {yylval=t  ; return TIME; }
"_64" {yylval=sf ; return TIME; }

[rR]  {yylval=r  ; return BEAM; }
[lL]  {yylval=l  ; return BEAM; }


{SEP}+[Ll][Gg]  { yylval=N  ; return THEME; }
{SEP}+[Ll][Aa]  { yylval=a  ; return THEME; }
{SEP}+[Bb]     { yylval=b  ; return THEME; }
{SEP}+[Cc]     { yylval=c  ; return THEME; }
{SEP}+[Dd]     { yylval=d  ; return THEME; }
{SEP}+[Ee]     { yylval=e  ; return THEME; }
{SEP}+[Ff]     { yylval=f  ; return THEME; }
{SEP}+[Hh][Gg]  { yylval=g  ; return THEME; }
{SEP}+[Hh][Aa]  { yylval=hh ; return THEME; }

{SEP}+"REST_1"  {yylval=_pause ;       return REST; }
{SEP}+"REST_2"  {yylval=hpause ;      return REST; }
{SEP}+"REST_4"  {yylval=soupir ;      return REST; }
{SEP}+"REST_8"  {yylval=dsoupir ;     return REST; }
{SEP}+"REST_16" {yylval=quantsoupir ; return REST; }
{SEP}+"REST_32" {yylval=huitsoupir ;  return REST; }

{SEP}+[a][g] {yylval=gra; return EMB; }
{SEP}+[b][g] {yylval=grb; return EMB; }
{SEP}+[c][g] {yylval=grc; return EMB; }
{SEP}+[d][g] {yylval=grd; return EMB; }
{SEP}+[e][g] {yylval=gre; return EMB; }
{SEP}+[f][g] {yylval=grf; return EMB; }
{SEP}+[g][g] {yylval=grg; return EMB; }
{SEP}+[t][g] {yylval=grh; return EMB; }

{SEP}*"'"{LPITCH}/{TSEP}            {             return DOT;  }
{SEP}*[\t]{TSEP}*"'"{LPITCH}/{TSEP} {unput('\t'); return DOT;  }
{SEP}*"''"{LPITCH}                  {             return DDOT; }
{SEP}*[\t]{TSEP}*"''"{LPITCH}       {unput('\t'); return DDOT; }

{SEP}+"d"{LCPITCH}    {yylval=addpit(yytext,yyleng,ddgr);   return EMBP; }
{SEP}+"e"{LCPITCH}    {yylval=addpit(yytext,yyleng,edgr);   return EMBP; }
{SEP}+"f"{LCPITCH}    {yylval=addpit(yytext,yyleng,fdgr);   return EMBP; }
{SEP}+"g"{LCPITCH}    {yylval=addpit(yytext,yyleng,gdgr);   return EMBP; }
{SEP}+"t"{LCPITCH}    {yylval=addpit(yytext,yyleng,tdgr);   return EMBP; }
{SEP}+"str"{LPITCH}   {yylval=addpit(yytext,yyleng,gr);     return EMBP; }
{SEP}+"echo"{LPITCH}  {yylval=addpit(yytext,yyleng,echo);   return EMBP; }
{SEP}+"them"{LPITCH}  {yylval=addpit(yytext,yyleng,them);   return EMBP; }
{SEP}+"st2"{LPITCH}   {yylval=addpit(yytext,yyleng,dstr);   return EMBP; }
{SEP}+"gst2"{LPITCH}  {yylval=addpit(yytext,yyleng,gdstr);  return EMBP; }
{SEP}+"tst2"{LPITCH}  {yylval=addpit(yytext,yyleng,tdstr);  return EMBP; }
{SEP}+"hst2"{LPITCH}  {yylval=addpit(yytext,yyleng,hdstr);  return EMBP; }
{SEP}+"st3"{LPITCH}   {yylval=addpit(yytext,yyleng,tstr);   return EMBP; }
{SEP}+"gst3"{LPITCH}  {yylval=addpit(yytext,yyleng,gtstr);  return EMBP; }
{SEP}+"tst3"{LPITCH}  {yylval=addpit(yytext,yyleng,ttstr);  return EMBP; }
{SEP}+"hst3"{LPITCH}  {yylval=addpit(yytext,yyleng,htstr);  return EMBP; }
{SEP}+"db"{LPITCH}    {yylval=addpit(yytext,yyleng,dbl);    return EMBP; }
{SEP}+"tdb"{LPITCH}   {yylval=addpit(yytext,yyleng,tdbl);   return EMBP; }
{SEP}+"hdb"{LPITCH}   {yylval=addpit(yytext,yyleng,hdbl);   return EMBP; }
{SEP}+"hst"{LPITCH}   {yylval=addpit(yytext,yyleng,hslur);  return EMBP; }
{SEP}+"lhst"{LPITCH}  {yylval=addpit(yytext,yyleng,hshk);   return EMBP; }
{SEP}+"gst"{LPITCH}   {yylval=addpit(yytext,yyleng,slur);   return EMBP; }
{SEP}+"lgst"{LPITCH}  {yylval=addpit(yytext,yyleng,shk);    return EMBP; }
{SEP}+"tst"{LPITCH}   {yylval=addpit(yytext,yyleng,tslur);  return EMBP; }
{SEP}+"ltst"{LPITCH}  {yylval=addpit(yytext,yyleng,tshk);   return EMBP; }
{SEP}+"pel"{LPITCH}   {yylval=addpit(yytext,yyleng,pel);    return EMBP; }
{SEP}+"lpel"{LPITCH}  {yylval=addpit(yytext,yyleng,lpel);   return EMBP; }
{SEP}+"tpel"{LPITCH}  {yylval=addpit(yytext,yyleng,tpel);   return EMBP; }
{SEP}+"ltpel"{LPITCH} {yylval=addpit(yytext,yyleng,ltpel);  return EMBP; }
{SEP}+"hpel"{LPITCH}  {yylval=addpit(yytext,yyleng,hpel);   return EMBP; }
{SEP}+"hgrp"{LPITCH}  {yylval=addpit(yytext,yyleng,catch);  return EMBP; }
{SEP}+"ggrp"{LPITCH}  {yylval=addpit(yytext,yyleng,scatch); return EMBP; }
{SEP}+"tgrp"{LPITCH}  {yylval=addpit(yytext,yyleng,tcatch); return EMBP; }
{SEP}+"cade"          {yylval=(char *)malloc(MAXLEN); strcpy(yylval,them);
                           strcat(yylval,e);                return EMBP; }
{SEP}+"dili"          {yylval=(char *)malloc(MAXLEN); strcpy(yylval,dbl);
                           strcat(yylval,hh);               return EMBP; }
{SEP}+"din"           {yylval=(char *)malloc(MAXLEN); strcpy(yylval,echo);
                           strcat(yylval,N);                return EMBP; }
{SEP}+"hlemla"        {yylval=(char *)malloc(MAXLEN); strcpy(yylval,ddgr);
                           strcat(yylval,a);                return EMBP; }
{SEP}+"hlemlg"        {yylval=(char *)malloc(MAXLEN); strcpy(yylval,ddgr);
                           strcat(yylval,N);                return EMBP; }
{SEP}+"lembrea"       {yylval=(char *)malloc(MAXLEN); strcpy(yylval,grip);
           strcat(yylval,pointdorgue); strcat(yylval," e"); return EMBP; }
{SEP}+"lembbrea"      {yylval=(char *)malloc(MAXLEN); strcpy(yylval,dgrip);
           strcat(yylval,pointdorgue); strcat(yylval," e"); return EMBP; }
{SEP}+"lemlabrea"     {yylval=(char *)malloc(MAXLEN); strcpy(yylval,ddgr);
                          strcat(yylval,a); strcat(yylval,pointdorgue);
                                       strcat(yylval," e"); return EMBP; }


{SEP}+"lst2"[dD]   {yylval=ldstrd;     return EMB;    }
{SEP}+"lst3"[dD]   {yylval=ltstrd;     return EMB;    }
{SEP}+"thr"[dD]    {yylval=thrwd;      return EMB;    }
{SEP}+"hthr"[dD]   {yylval=hthrwd;     return EMB;    }
{SEP}+"hvthr"[dD]  {yylval=gripthrwd;  return EMB;    }
{SEP}+"hhvthr"[dD] {yylval=hgripthrwd; return EMB;    }
{SEP}+"pdili"      {yylval=trille;     return EMB;    }
{SEP}+"tra"        {yylval=tra;        return EMB;    }
{SEP}+"tra8"       {yylval=trac;       return EMB;    }
{SEP}+"htra"       {yylval=htra;       return EMB;    }
{SEP}+"ptra"       {yylval=trille;     return EMB;    }
{SEP}+"ptra8"      {yylval=trille;     return EMB;    }
{SEP}+"phtra"      {yylval=trille;     return EMB;    }
{SEP}+"brl"        {yylval=wbirl;      return EMB;    }
{SEP}+"abr"        {yylval=birl;       return EMB;    }
{SEP}+"gbr"        {yylval=sbirl;      return EMB;    }
{SEP}+"tbr"        {yylval=tbirl;      return EMB;    }
{SEP}+"grp"        {yylval=grip;       return EMB;    }
{SEP}+"pgrp"       {yylval=trille;     return EMB;    }
{SEP}+"lem"        {yylval=grip;       return EMB;    }
{SEP}+"pl"         {yylval=abrleum;    return EMB;    }
{SEP}+"plb"        {yylval=abrleum;    return EMB;    }
{SEP}+"phlla"      {yylval=abrleum;    return EMB;    }
{SEP}+"plbrea"     {yylval=abrleumbr;  return EMB;    }
{SEP}+"plbbrea"    {yylval=abrleumbr;  return EMB;    }
{SEP}+"phllabrea"  {yylval=abrleumbr;  return EMB;    }
{SEP}+"hgrp"       {yylval=Ngrip;      return EMB;    }
{SEP}+"grp"[bB]    {yylval=dgrip;      return EMB;    }
{SEP}+"lem"[bB]    {yylval=dgrip;      return EMB;    }
{SEP}+"rodin"      {yylval=dgrip;      return EMB;    }
{SEP}+"hiharin"    {yylval=hiharin;    return EMB;    }
{SEP}+"phiharin"   {yylval=pince;      return EMB;    }
{SEP}+"chelalho"   {yylval=chelalho;   return EMB;    }
{SEP}+"deda"       {yylval=deda;       return EMB;    }
{SEP}+"tar"        {yylval=taor;       return EMB;    }
{SEP}+"htar"       {yylval=htaor;      return EMB;    }
{SEP}+"tar"[bB]    {yylval=dtaor;      return EMB;    }
{SEP}+"tarbrea"    {yylval=taor;       return EMB;    }
{SEP}+"tarbbrea"   {yylval=Ntaor;      return EMB;    }
{SEP}+"htarlabrea" {yylval=ahtaorb;    return EMB;    }
{SEP}+"htarla"     {yylval=ahtaor;     return EMB;    }
{SEP}+"htarlg"     {yylval=Ntaor;      return EMB;    }
{SEP}+"pt"         {yylval=abrtaor;    return EMB;    }
{SEP}+"ptb"        {yylval=abrtaor;    return EMB;    }
{SEP}+"phtla"      {yylval=abrtaor;    return EMB;    }
{SEP}+"ptla"       {yylval=abrtaor;    return EMB;    }
{SEP}+"ptlg"       {yylval=abrtaor;    return EMB;    }
{SEP}+"ptbrea"     {yylval=abrtaorbr;  return EMB;    }
{SEP}+"ptbbrea"    {yylval=abrtaorbr;  return EMB;    }
{SEP}+"phtlabrea"  {yylval=abrtaorbr;  return EMB;    }
{SEP}+"ptm"{LPITCH} {yylval=abrtaorm;  return EMB;    }
{SEP}+"bubly"      {yylval=darodo;     return EMB;    }
{SEP}+"darodo"     {yylval=darodo;     return EMB;    }
{SEP}+"darodos"    {yylval=darodos;    return EMB;    }
{SEP}+"pdarodo"    {yylval=turn;       return EMB;    }
{SEP}+"pdarodos"   {yylval=turn;       return EMB;    }
{SEP}+"hbubly"     {yylval=Ndarodo;    return EMB;    }
{SEP}+"hdarodo"    {yylval=Ndarodo;    return EMB;    }
{SEP}+"phdarodo"   {yylval=turn;       return EMB;    }
{SEP}+"cadged"     {yylval=cadged;     return EMB;    }
{SEP}+"cadged"     {yylval=cadged;     return EMB;    }
{SEP}+"cadge"      {yylval=cadge;      return EMB;    }
{SEP}+"cadgf"      {yylval=cadgf;      return EMB;    }
{SEP}+"cadaed"     {yylval=cadaed;     return EMB;    }
{SEP}+"cadae"      {yylval=cadae;      return EMB;    }
{SEP}+"fcadged"    {yylval=fcadged;    return EMB;    }
{SEP}+"fcadged"    {yylval=fcadged;    return EMB;    }
{SEP}+"fcadge"     {yylval=fcadge;     return EMB;    }
{SEP}+"fcadgf"     {yylval=fcadgf;     return EMB;    }
{SEP}+"fcadaed"    {yylval=fcadaed;    return EMB;    }
{SEP}+"fcadae"     {yylval=fcadae;     return EMB;    }
{SEP}+"fcade"      {yylval=fcade;      return EMB;    }

{SEP}+"dre"          {yylval=hdre;    return EMB;    }
{SEP}+"edre"         {yylval=edre;    return EMB;    }
{SEP}+"edre"[bB]     {yylval=edreb;   return EMB;    }
{SEP}+"edre"[cC]     {yylval=edrec;   return EMB;    }
{SEP}+"edre"[dD]     {yylval=edred;   return EMB;    }
{SEP}+"edrelg"       {yylval=scatchb; return EMB;    }
{SEP}+"edrela"       {yylval=scatchc; return EMB;    }
{SEP}+"pedre"        {yylval=pince;   return EMB;    }
{SEP}+"pedre"[bB]    {yylval=upz;     return EMB;    }
{SEP}+"pedre"[cC]    {yylval=upz;     return EMB;    }
{SEP}+"pedre"[dD]    {yylval=upz;     return EMB;    }
{SEP}+"pedrelg"      {yylval=abrcrunm; return EMB;   }
{SEP}+"pedrela"      {yylval=abrcrunm; return EMB;   }
{SEP}+"dare"         {yylval=dare;    return EMB;    }
{SEP}+"pdare"        {yylval=pdare;   return EMB;    }
{SEP}+"gedre"        {yylval=gedre;   return EMB;    }
{SEP}+"gdare"        {yylval=gdare;   return EMB;    }
{SEP}+"tedre"        {yylval=tedre;   return EMB;    }
{SEP}+"tdare"        {yylval=tdare;   return EMB;    }
{SEP}+"tchechere"    {yylval=tchechere; return EMB;  }
{SEP}+"hchechere"    {yylval=hchechere; return EMB;  }
{SEP}+"embari"       {yylval=edre;    return EMB;    }
{SEP}+"endari"       {yylval=edre;    return EMB;    }
{SEP}+"chedari"      {yylval=dare;    return EMB;    }
{SEP}+"chedare"      {yylval=dare;    return EMB;    }
{SEP}+"pembari"      {yylval=pince;   return EMB;    }
{SEP}+"pendari"      {yylval=pince;   return EMB;    }
{SEP}+"pchedari"     {yylval=pince;   return EMB;    }
{SEP}+"chedari"      {yylval=dare;    return EMB;    }
{SEP}+"hedari"       {yylval=hedari;  return EMB;    }
{SEP}+"phedari"      {yylval=pince;   return EMB;    }
{SEP}+"hedale"       {yylval=hedale;  return EMB;    }
{SEP}+"dbst"[Ff]     {yylval=dbstf;   return EMB;    }
{SEP}+"dbst"[hH][gG] {yylval=dbsth;   return EMB;    }
{SEP}+"enbain"       {yylval=enbain;  return EMB;    }
{SEP}+"otro"         {yylval=otro;    return EMB;    }
{SEP}+"odro"         {yylval=odro;    return EMB;    }
{SEP}+"adela"        {yylval=adela;   return EMB;    }
{SEP}+"penbain"      {yylval=pince;   return EMB;    }
{SEP}+"potro"        {yylval=pince;   return EMB;    }
{SEP}+"podro"        {yylval=pince;   return EMB;    }
{SEP}+"padela"       {yylval=pince;   return EMB;    }
{SEP}+"genbain"      {yylval=genbain; return EMB;    }
{SEP}+"gotro"        {yylval=gotro;   return EMB;    }
{SEP}+"godro"        {yylval=godro;   return EMB;    }
{SEP}+"gadela"       {yylval=gadela;  return EMB;    }
{SEP}+"tenbain"      {yylval=tenbain; return EMB;    }
{SEP}+"totro"        {yylval=totro;   return EMB;    }
{SEP}+"todro"        {yylval=todro;   return EMB;    }
{SEP}+"tadela"       {yylval=tadela;  return EMB;    }
{SEP}+"crunl"        {yylval=crun;    return EMB;    }
{SEP}+"crunlb"       {yylval=dcrun;   return EMB;    }
{SEP}+"hcrunlla"     {yylval=ahcrun;  return EMB;    }
{SEP}+"crunllg"      {yylval=Nhcrun;  return EMB;    }
{SEP}+"hcrunllg"     {yylval=Nhcrun;  return EMB;    }
{SEP}+"crunlbbrea"   {yylval=dcrunbr; return EMB;    }
{SEP}+"crunllabrea"  {yylval=hcrunbr; return EMB;    }
{SEP}+"pc"           {yylval=abrcrun; return EMB;    }
{SEP}+"pcb"          {yylval=abrcrun; return EMB;    }
{SEP}+"phcla"        {yylval=abrcrun; return EMB;    }
{SEP}+"pclg"         {yylval=abrcrun; return EMB;    }
{SEP}+"pcbrea"       {yylval=abrcrunbr; return EMB;  }
{SEP}+"pcbbrea"      {yylval=abrcrunbr; return EMB;  }
{SEP}+"phclabrea"    {yylval=abrcrunbr; return EMB;  }
{SEP}+"pcm"{LPITCH}  {yylval=abrcrunm;  return EMB;  }
{SEP}+"ptrip"{LPITCH} {yylval=abrtrip; return EMB;   }
{SEP}+"pttrip"{LPITCH} {yylval=abrtrip; return EMB;  }
{SEP}+"phtrip"{LPITCH} {yylval=abrtrip; return EMB;  }
{SEP}+"p"{LPITCH}    {yylval=upz;     return EMB;    }

{SEP}+"st"{LPITCH}      {yylval=addpit(yytext,yyleng,hslur); return EMBP; }
{SEP}+"lst"{LPITCH}     {yylval=addpit(yytext,yyleng,hshk);  return EMBP; }

{SEP}+"flat"{LPITCH}    {yylval=addpit(yytext,yyleng,fl);    return EMBP; }
{SEP}+"natural"{LPITCH} {yylval=addpit(yytext,yyleng,na);    return EMBP; }
{SEP}+"sharp"{LPITCH}   {yylval=addpit(yytext,yyleng,shp);   return EMBP; }

{SEP}+"fermat"{LPITCH} {yylval=strcat(addpit(yytext,yyleng,fermat),"}");
                                                             return EMBP; }

{SEP}+"thr"    {yylval=thrwd;   return EMB;    }
{SEP}+"bub"    {yylval=dgrip;   return EMB;    }
{SEP}+"tad"    {yylval=dtaor;   return EMB;    }
{SEP}+"hub"    {yylval=darodo;  return EMB;    }
{SEP}+"lhub"   {yylval=Ndarodo; return EMB;    }
{SEP}+"dstf"   {yylval=dbstf;   return EMB;    }
{SEP}+"dsthg"  {yylval=dbsth;   return EMB;    }

{SEP}+"bgrp"   {yylval=hgrpb;   return EMB;    }
{SEP}+"cgrp"   {yylval=hgrpc;   return EMB;    }
{SEP}+"gbgrp"  {yylval=scatchb; return EMB;    }
{SEP}+"gcgrp"  {yylval=scatchc; return EMB;    }
{SEP}+"tbgrp"  {yylval=tcatchb; return EMB;    }
{SEP}+"tcgrp"  {yylval=tcatchc; return EMB;    }

<<EOF>>       { return ENDFILE;   }

[a-z]         { ECHO; unput(' '); }
[A-Z]         { ECHO; unput(' '); }
[0-9]         { ECHO; unput(' '); }
[.,:]         { ECHO; unput(' '); }
{SEP}/{SEP}+  {                   }
{SEP}*[\n]    {                   }
{TSEP}        {                   }

%%

yywrap(){return (int)1;}

char *addpit( char *yyt, size_t yyl, char *tok )
  { char *retptr;

    retptr = (char *) malloc(MAXLEN);
    strcpy(retptr,tok);

    while( *(yyt+yyl-1) != 'b' &&
           *(yyt+yyl-1) != 'c' &&
           *(yyt+yyl-1) != 'd' &&
           *(yyt+yyl-1) != 'e' &&
           *(yyt+yyl-1) != 'f' &&
           *(yyt+yyl-1) != 'g' &&
           *(yyt+yyl-1) != 'a' &&
           *(yyt+yyl-1) != 'B' &&
           *(yyt+yyl-1) != 'C' &&
           *(yyt+yyl-1) != 'D' &&
           *(yyt+yyl-1) != 'E' &&
           *(yyt+yyl-1) != 'F' &&
           *(yyt+yyl-1) != 'G' &&
           *(yyt+yyl-1) != 'A' &&
           yyl > 1               ) yyl--;

    if       ( *(yyt+yyl-1) == 'b' ||
               *(yyt+yyl-1) == 'B'    ) strcat(retptr,b);
    else if  ( *(yyt+yyl-1) == 'c' ||
               *(yyt+yyl-1) == 'C'    ) strcat(retptr,c);
    else if  ( *(yyt+yyl-1) == 'd' ||
               *(yyt+yyl-1) == 'D'    ) strcat(retptr,d);
    else if  ( *(yyt+yyl-1) == 'e' ||
               *(yyt+yyl-1) == 'E'    ) strcat(retptr,e);
    else if  ( *(yyt+yyl-1) == 'f' ||
               *(yyt+yyl-1) == 'F'    ) strcat(retptr,f);
    else if  ( (*(yyt+yyl-1) == 'g' || *(yyt+yyl-1) == 'G')
            && (*(yyt+yyl-2) == 'h' || *(yyt+yyl-2) == 'H')) strcat(retptr,g);
    else if  ( (*(yyt+yyl-1) == 'g' || *(yyt+yyl-1) == 'G')
            && (*(yyt+yyl-2) == 'l' || *(yyt+yyl-2) == 'L')) strcat(retptr,N);
    else if  ( (*(yyt+yyl-1) == 'a' || *(yyt+yyl-1) == 'A')
            && (*(yyt+yyl-2) == 'l' || *(yyt+yyl-2) == 'L')) strcat(retptr,a);
    else if  ( (*(yyt+yyl-1) == 'a' || *(yyt+yyl-1) == 'A')
            && (*(yyt+yyl-2) == 'h' || *(yyt+yyl-2) == 'H')) strcat(retptr,hh);

    return retptr;
  }

void unpitch( char *yyt, size_t yyl)
  {
    if       ( *(yyt+yyl-1) == 'b' ||
               *(yyt+yyl-1) == 'B'    ) unput('B');
    else if  ( *(yyt+yyl-1) == 'c' ||
               *(yyt+yyl-1) == 'C'    ) unput('C');
    else if  ( *(yyt+yyl-1) == 'd' ||
               *(yyt+yyl-1) == 'D'    ) unput('D');
    else if  ( *(yyt+yyl-1) == 'e' ||
               *(yyt+yyl-1) == 'E'    ) unput('E');
    else if  ( *(yyt+yyl-1) == 'f' ||
               *(yyt+yyl-1) == 'F'    ) unput('F');
    else if  ( (*(yyt+yyl-1) == 'g' || *(yyt+yyl-1) == 'G')
            && (*(yyt+yyl-2) == 'h' || *(yyt+yyl-2) == 'H')) {unput('G'); unput('H');}
    else if  ( (*(yyt+yyl-1) == 'g' || *(yyt+yyl-1) == 'G')
            && (*(yyt+yyl-2) == 'l' || *(yyt+yyl-2) == 'L')) {unput('G'); unput('L');}
    else if  ( (*(yyt+yyl-1) == 'a' || *(yyt+yyl-1) == 'A')
            && (*(yyt+yyl-2) == 'l' || *(yyt+yyl-2) == 'L')) {unput('A'); unput('L');}
    else if  ( (*(yyt+yyl-1) == 'a' || *(yyt+yyl-1) == 'A')
            && (*(yyt+yyl-2) == 'h' || *(yyt+yyl-2) == 'H')) {unput('A'); unput('H');}
    unput(' ');
    return;
  }
