/* grammar for bww2tex
   version 2.00
   by Walt Innes {walt@slac.stanford.edu)
*/
%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tokensDat.h"
#define YYMAXDEPTH 1000
#define MAXLEN 2047
#define YYSTYPE char *

/* uncomment the following line for use with DropUNIX on the MAC */
/* #define MAC */

#ifdef MAC
#define alloca malloc
#endif

/* _WIN32 definition added for use with MS VC++ compiler. */
#ifdef _WIN32
#include <malloc.h>
#endif

int firstline=1, ntext=0, page, tiepend=0, tiearmed=0, lbhead;
size_t prelen, nn;
char num[2],den[2];
char *insert(char *, char *);
char *inserts(char*, char *, char *);
char *insertt(char*, char *, char *);
char *inserttie(char*, char *);
char *inserttrip(char*, char*);
char *insertthtrip(char*, char*);
char *insertetn(char *);
char *shorten( char *);
char *sdpnt;

/* FILE *yyout = stderr; */  /* directs unrecognized input to stderr.
                                some loaders don't like this. */
int  i;

%}


%left    TXT ANTXT NUMBER TITLE
%token   CLEFT BEAT BAR EOL METERFRAC METER SIGNATURE COMMENT FORMAT
%token   STARTFS ENDFS EMB EMBP REST REP TREMB TREMBP
%token   BEAM THEME TIME DOT DDOT TUNETYPE COMPOSER
%token   TRIPLET ETIE ENDFILE
%token   TIE TIEBEAT TIEALA TIEDBL TIECLEFT TIEXBAR TIELRBAR TIEDBAR

%%

input:    /* empty */
     | input line
     ;

line: bline ebar { strcat($1,"\\notes");
                         if(tiearmed) { tiearmed=0; strcat($1,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                           printf("%s", strcat(strcat($1,$2),suspmorceau));
                           free($1); free($2);
                        }
     | bline ebar ENDFILE{ strcat($1,"\\notes");
                         if(tiearmed) { tiearmed=0; strcat($1,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                         sdpnt = strrchr($2,'\\');
                         if (sdpnt !="" && strcmp(sdpnt,"\\setrightrepeat") == 0){
                              printf("%s", strcat(strcat($1,$2),"\\suspmorceau"));
                              free($1); free($2); return 1; }
                         else {
                           printf("%s", strcat(strcat($1,$2),"\\finmorceau"));
                           free($1); free($2); return 1; }
                        }
line: bline ebar ebar { strcat($1,"\\notes");
                         if(tiearmed) { tiearmed=0; strcat($1,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                           printf("%s",strcat(strcat(strcat(strcat(strcat
                                ($1,$2),xbarre),"\\notes"),$3),suspmorceau));
                           free($1); free($2); free($3);
                        }
    | bline ebar ebar ENDFILE { strcat($1,"\\notes");
                         if(tiearmed) { tiearmed=0; strcat($1,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                          sdpnt = strrchr($3,'\\');
                         if (sdpnt !="" && strcmp(sdpnt,"\\setrightrepeat") == 0){
                            printf("%s",strcat(strcat(strcat(strcat(strcat
                                ($1,$2),xbarre),"\\notes"),$3),"\\suspmorceau"));
                              free($1); free($2); free($3); return 1; }
                         else {
                          printf("%s",strcat(strcat(strcat(strcat(strcat
                                ($1,$2),xbarre),"\\notes"),$3),"\\finmorceau"));
                           free($1); free($2); free($3); return 1;
                              }
                        }
     | tline { printf("%s%%\n",$1); free($1);}
     | error EOL   { printf("%s\n",$1); }
     ;
bline: bline ebarc { strcat($1,"\\notes");
                     if(tiearmed) { tiearmed=0; strcat($1,"\\tten0"); }
                     if(tiepend) { tiepend=0; tiearmed=1; }
                     printf("%s", strcat($1,$2)); free($1); free($2);
                     $$=malloc(MAXLEN); strcpy($$,reprmorceau);
                   }
bline: bbline      {  $$ = $1;
                   }
     | bline ebar ebarc { strcat($1,"\\notes");
                     if(tiearmed) { tiearmed=0; strcat($1,"\\tten0"); }
                     if(tiepend) { tiepend=0; tiearmed=1; }
                     printf("%s", strcat(strcat(strcat(strcat
                     ($1,$2),xbarre),"\\notes"),$3));
                     free($1); free($2); free($3);
                     $$=malloc(MAXLEN); strcpy($$,reprmorceau);
                        }
     | bline bar     { $$ = strcat($1,$2); free($2);
                     }
/*     | bline bar STARTFS      {
              if ($3==first || $3==second ) $$ = strcat(strcat($1,$3),$2);
              else { $$ = strcat($1,$2); nn=strlen($3);
                     if(nn==1) {strcat($$,"\\notes\\Uptext{"); strcat($$,$3);
                                strcat($$,"}\\enotes");
                                }
                     else { strcat($$,"\\notes\\Uptext{$\\vert$ time ");
                            strncat($$,$3,1); strcat($$," on part(s) ");
                            strncat($$,$3+1,1);
                            for(i=3; i <= (int) nn; i++)
                               {strcat($$,",");strncat($$,$3+i-1,1);
                               }
                             strcat($$,"}\\enotes");
                           }
                     free($3);
                   }
                     free($2); }
     | bline STARTFS bar      {
              if ($2==first || $2==second ) $$ = strcat(strcat($1,$2),$3);
              else { $$ = strcat($1,$3); nn=strlen($2);
                     if(nn==1) {strcat($$,"\\notes\\Uptext{"); strcat($$,$2);
                                strcat($$,"}\\enotes");
                                }
                     else { strcat($$,"\\notes\\Uptext{$\\vert$ time ");
                            strncat($$,$2,1); strcat($$," on part(s) ");
                            strncat($$,$2+1,1);
                            for(i=3; i <= (int) nn; i++)
                               {strcat($$,",");strncat($$,$2+i-1,1);
                               }
                             strcat($$,"}\\enotes");
                          }
                     free($2);
                   }
                     free($3); }
     | bline STARTFS {
           if ($2==first || $2==second) $$ = strcat(strcat($1,$2),"\\xbarre");
           else { $$ = $1; nn=strlen($2);
                  if(nn==1) { strcat($$,"\\notes\\Uptext{repeat ");
                              strcat($$,$2); strcat($$,"}\\enotes");
                            }
                  else {strcat($$,"\\notes\\Uptext{$\\vert$ time ");
                        strncat($$,$2,1);
                        strcat($$," on part(s) "); strncat($$,$2+1,1);
                        for(i=3; i <= (int) nn; i++)
                            {strcat($$,",");strncat($$,$2+i-1,1);
                            }
                         strcat($$,"}\\enotes");
                        }
                  free($2);
                 }
                     }   */
     | bline TIE     { $$ = $1; free($2);
                     }
     | bline tiebeat { $$ = insertetn($1); free($2);
                     }
     | bline mbar { $$ = strcat($1,"\\notes");
                         if(tiearmed) { tiearmed=0; strcat($$,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                         strcat($$,$2); free($2);
                        }
     | bline ebar mbar { $$ = strcat($1,"\\notes");
                         if(tiearmed) { tiearmed=0; strcat($$,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                         strcat($$,$2); strcat($$,xbarre);
                         strcat($$,"\\notes"); strcat($$,$3);
                         free($2); free($3);
                        }
     | bline ENDFS { $$=strcat($1,"\\notes\\Uptext{$\\vert$}\\enotes"); }
     | bline BEAT  { $$=$1; }
     ;

bbline: CLEFT {$$=malloc(MAXLEN);
              if (firstline) { firstline=0;
                               strcpy($$,"\\debutmorceau\n\\setelemq{1.2}%\n");
                             }
              else             strcpy($$,$1);
             }
      | bbline SIGNATURE { $$ = malloc(MAXLEN);
                         strcat(strcat(strcat(strcpy($$,"\\generalsignature{"),
                         $2),"}\n"),$1); free($1);
                       }
      | bbline METER { $$ = malloc(MAXLEN);
                          strcpy($$,"\\generalmeter{");
                          strcat(strcat($$,$2),"}\n"); strcat($$,$1); free($1);
                   }
      | bbline METERFRAC { prelen=strcspn($2,"_") ;
                         strncpy(num,$2,prelen) ; strcpy(num+prelen,"");
                         strcpy(den,$2+prelen+1) ;
                         $$=malloc(MAXLEN);
                         strcat(strcat(strcat(strcat(strcat(strcpy(
                              $$,"\\generalmeter{\\meterfrac{"),
                                   num),"}{"),den),"}}\n"),$1);
                         free($1); free($2);
                       }
      ;

ebar: bcont eol {$$ = strcat(strcat($1,"\\enotes"),$2); free($2);
                }
    | bcont TIE eol { $$ = inserttie($1,$2);
                      strcat(strcat($$,"\\enotes"),$3);
                      tiepend=1; free($1); free($2); free($3);
                    }
    | bcont TIEALA  { $$ = inserttie($1,$2);
                      strcat(strcat($$,"\\enotes"),alaligne);
                      tiepend=1; free($1); free($2);
                    }
    | bcont TIEDBL  { $$ = inserttie($1,$2);
                      strcat(strcat($$,"\\enotes"),setdoublebar);
                      tiepend=1; free($1); free($2);
                    }
    | bcont BEAT eol { $$ = strcat(strcat($1,"\\enotes"),$3);
                                                       free($3);
                     }
    | bcont tiebeat eol {
                         $$ = inserttie($1,$2);
                         strcat(strcat($$,"\\enotes"),$3);
                         tiepend=1; free($1); free($2); free($3);
                        }
    | bcont BEAT ebar {$$ = insertetn($1); strcat($$,$3); free($3);
                      }
    | bcont tiebeat ebar {$$ = inserttie($1,$2); insertetn($$);
                          strcat($$,"\\tten0"); strcat($$,$3);
                          free($1); free($2); free($3);
                         }
    | bcont btheme emb eol {$$ = strcat($1,$2); strcat ($$,$3);
                            strcat($$,"\\enotes"); strcat($$,$4);
                            free($2); free($3); free($4);
                           }
    | btheme emb eol  {$$ = strcat($1,$2);
                             strcat($$,"\\enotes"); strcat($$,$3);
                             free($2); free($3);
                      }
    ;

ebarc: bcont CLEFT {$$ = strcat(strcat($1,"\\enotes"),alaligne);
                    strcat($$,suspmorceau);
                   }
    | bcont TIE CLEFT { $$ = inserttie($1,$2);
                       strcat(strcat($$,"\\enotes"),alaligne);
                       strcat($$,suspmorceau);
                       tiepend=1; free($1); free($2);
                      }
    | bcont TIECLEFT { $$ = inserttie($1,$2);
                      strcat(strcat($$,"\\enotes"),alaligne);
                      strcat($$,suspmorceau);
                      tiepend=1; free($1); free($2);
                     }
    | bcont BEAT CLEFT { $$ = strcat(strcat($1,"\\enotes"),alaligne);
                         strcat($$,suspmorceau);
                       }
    | bcont tiebeat CLEFT {
                           $$ = inserttie($1,$2);
                           strcat(strcat($$,"\\enotes"),alaligne);
                           strcat($$,suspmorceau);
                           tiepend=1; free($1); free($2);
                          }
    | bcont BEAT ebarc {$$ = insertetn($1); strcat($$,$3); free($3);
                       }
    | bcont tiebeat ebarc {$$ = inserttie($1,$2); insertetn($$);
                           strcat($$,"\\tten0"); strcat($$,$3);
                           free($1); free($2); free($3);
                          }
    | bcont btheme emb CLEFT {$$ = strcat($1,$2); strcat ($$,$3);
                              strcat($$,"\\enotes"); strcat($$,alaligne);
                              strcat($$,suspmorceau);
                              free($2); free($3);
                             }
    | btheme emb CLEFT  {$$ = strcat($1,$2);
                         strcat($$,"\\enotes"); strcat($$,alaligne);
                         strcat($$,suspmorceau);
                         free($2);
                        }
    ;

mbar: bcont bar  {$$ = $1; strcat(strcat($$,"\\enotes"),$2); free($2);
                 }
    | bcont TIE bar {$$ = inserttie($1,$2);
                     strcat(strcat($$,"\\enotes"),$3);
                     tiepend=1; free($1); free($2); free($3);
                    }
    | bcont TIEXBAR {$$ = inserttie($1,$2);
                     strcat(strcat($$,"\\enotes"),xbarre);
                     tiepend=1; free($1); free($2);
                    }
    | bcont TIEDBAR {$$ = inserttie($1,$2);
                     strcat(strcat($$,"\\enotes"),setdoublebar);
                     strcat($$,xbarre);
                     tiepend=1; free($1); free($2);
                    }
    | bcont TIELRBAR {$$ = inserttie($1,$2);
                     strcat(strcat($$,"\\enotes"),leftrepeatsymbol);
                     tiepend=1; free($1); free($2);
                    }
    | bcont BEAT bar {$$ = $1; strcat(strcat($$,"\\enotes"),$3); free($3);
                     }
    | bcont tiebeat bar {$$ = inserttie($1,$2);
                         strcat(strcat($$,"\\enotes"),$3);
                         tiepend=1; free($1); free($2);
                        }
    | bcont BEAT mbar {$$ = strcat(insertetn($1),$3); free($3);
                      }
    | bcont tiebeat mbar {$$ = inserttie($1,$2);
                          strcat(strcat(insertetn($$),"\\tten0"),$3);
                          free($1); free($2); free($3);
                         }
    | bcont btheme emb bar {$$ = strcat($1,$2); strcat ($$,$3);
                             strcat($$,"\\enotes"); strcat($$,$4);
                             free($2); free($3); free($4);
                           }
    | btheme emb bar {$$ = strcat($1,$2);
                             strcat($$,"\\enotes"); strcat($$,$3);
                             free($2); free($3);
                     }
    ;


bcont: element  { $$=$1; }
     | bcont element { $$ = strcat($1,$2); free($2); }
     | bcont TIE element { $$=inserttie($1,$2); strcat($$,"\\tten0");
                           strcat($$,$3); free($1); free($2); free($3);
                         }
     ;

element: theme  { $$=$1; }
       | btheme { $$=$1; }
       | emb    { $$=$1; }
       | btheme emb BEAT { $$ = insertetn(strcat($1,$2)); free($2); }
       | btheme theme    { $$ = strcat($1,$2); free($2); }
       | btheme emb theme { $$ = strcat(strcat($1,$2),$3); free($2); free($3); }
       ;

theme: THEME TIME DDOT { $$ =  malloc(MAXLEN); strcpy($$,"\\");
                              strcat(strcat(strcat($$,$2),"pp "),$1);
                       }
     | THEME TIME DOT { $$ =  malloc(MAXLEN); strcpy($$,"\\");
                              strcat(strcat(strcat($$,$2),"p "),$1);
                      }
     | THEME TIME { $$ =  malloc(MAXLEN); strcpy($$,"\\");
                          strcat(strcat($$,$2),$1);
                  }
     | theme TRIPLET { $$=insertthtrip($1,$2); free($1);
                     }
     | theme ETIE    { $$ = malloc(MAXLEN); strcpy($$,$2);
                            strcat($$,$1); free($1);
                     }
     ;

btheme: THEME BEAM TIME DDOT { $$ =  malloc(MAXLEN); strcpy($$,"\\b");
         strcat(strcat(strcat(strcat(strcat($$,$3)," bb3"),"\\b"),$1),"pp");
                            }
      | THEME BEAM TIME DOT { $$ =  malloc(MAXLEN); strcpy($$,"\\b");
         strcat(strcat(strcat(strcat(strcat($$,$3)," bb3"),"\\b"),$1),"p");
                            }
      | THEME BEAM TIME     { $$ = malloc(MAXLEN); strcpy($$,"\\b");
         strcat(strcat(strcat(strcat($$,$3)," bb3"),"\\b"),$1);
                            }
      | btheme THEME BEAM TIME DDOT { $$ = $1;
            strcat(strcat(strcat(insert($$,$4),"\\b"),$2),"pp");
            lbhead = strchr($$,' ')-$$;
            if( lbhead > 6) $$ = shorten($$);
                                   }
      | btheme THEME BEAM TIME DOT { $$ = $1;
            strcat(strcat(strcat(insert($$,$4),"\\b"),$2),"p");
            lbhead = strchr($$,' ')-$$;
            if( lbhead > 6) $$ = shorten($$);
                                   }
      | btheme THEME BEAM TIME { $$ = $1;
            strcat(strcat(insert($$,$4),"\\b"),$2);
            lbhead = strchr($$,' ')-$$;
            if( lbhead > 6) $$ = shorten($$);
                               }
      | btheme emb THEME BEAM TIME DDOT {$$ = $1;
              strcat(strcat(strcat(inserts($1,$5,$2),"\\b"),$3),"pp");
              lbhead = strchr($$,' ')-$$;
              if( lbhead > 6) $$ = shorten($$); free($2);
                                       }
      | btheme emb THEME BEAM TIME DOT {$$ = $1;
              strcat(strcat(strcat(inserts($1,$5,$2),"\\b"),$3),"p");
              lbhead = strchr($$,' ')-$$;
              if( lbhead > 6) $$ = shorten($$); free($2);
                                       }
      | btheme emb THEME BEAM TIME {$$ = $1;
              strcat(strcat(inserts($1,$5,$2),"\\b"),$3);
              lbhead = strchr($$,' ')-$$;
              if( lbhead > 6) $$ = shorten($$); free($2);
                                   }
      | btheme TIE THEME BEAM TIME DDOT {$$ = $1;
              strcat(strcat(strcat(insertt($1,$5,$2),"\\b"),$3),"pp");
              lbhead = strchr($$,' ')-$$;
              if( lbhead > 6) $$ = shorten($$); free($2);
                                       }
      | btheme TIE THEME BEAM TIME DOT {$$ = $1;
              strcat(strcat(strcat(insertt($1,$5,$2),"\\b"),$3),"p");
              lbhead = strchr($$,' ')-$$;
              if( lbhead > 6) $$ = shorten($$); free($2);
                                       }
      | btheme TIE THEME BEAM TIME {$$ = $1;
              strcat(strcat(insertt($1,$5,$2),"\\b"),$3);
              lbhead = strchr($$,' ')-$$;
              if( lbhead > 6) $$ = shorten($$);free($2);
                                   }
/*      | btheme THEME TIME DDOT { $$ = $1;
            if($3==ql || $3 == hh || $3 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(strcat(insert($$,$3),"\\b"),$2),"p");
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$);
                 }              }
      | btheme THEME TIME DOT { $$ = $1;
            if($3==ql || $3 == hh || $3 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(strcat(insert($$,$3),"\\b"),$2),"p");
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$);
                 }                  }
      | btheme THEME TIME { $$ = $1;
            if($3 == ql || $3 == hh || $3 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(insert($$,$3),"\\b"),$2);
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$);
                 }              }
      | btheme emb THEME TIME DDOT {$$ = $1;
            if($4 == ql || $4 == hh || $4 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(strcat(inserts($1,$4,$2),"\\b"),$3),"p");
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$); free($2);
                 }                      }
      | btheme emb THEME TIME DOT {$$ = $1;
            if($4 == ql || $4 == hh || $4 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(strcat(inserts($1,$4,$2),"\\b"),$3),"p");
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$); free($2);
                 }                      }
      | btheme emb THEME TIME {$$ = $1;
            if($4 == ql || $4 == hh || $4 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(inserts($1,$4,$2),"\\b"),$3);
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$); free($2);
                 }                  }
      | btheme TIE THEME TIME DDOT {$$ = $1;
            if($4 == ql || $4 == hh || $4 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(strcat(insertt($1,$4,$2),"\\b"),$3),"pp");
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$); free($2);
                 }                 }
      | btheme TIE THEME TIME DOT {$$ = $1;
            if($4 == ql || $4 == hh || $4 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                  }
            else {
                  strcat(strcat(strcat(insertt($1,$4,$2),"\\b"),$3),"p");
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$); free($2);
                 }                 }
      | btheme TIE THEME TIME {$$ = $1;
            if($4 == ql || $4 == hh || $4 == wh) { $$=$1; free($2);
                 printf("%s","%\n% There is a tab or beam indicator missing."
                        " Will ignore this note.\n");
                                                 }
            else {
                  strcat(strcat(insertt($1,$4,$2),"\\b"),$3);
                  lbhead = strchr($$,' ')-$$;
                  if( lbhead > 6) $$ = shorten($$);free($2);
                 }                  }                                */
      | btheme TRIPLET { $$=inserttrip($1,$2); free($1);
                       }
      | btheme ETIE { $$ = malloc(MAXLEN); strcpy($$,$2);
                            strcat($$,$1); free($1);
                       }
      ;
eol:   EOL       { $$ = malloc(MAXLEN); strcpy($$,$1); }
   |   eol REP   { $$ = malloc(MAXLEN); strcpy($$,$2);
                                        strcat($$,$1); free($1); }
   |   eol ENDFS { $$ = malloc(MAXLEN); strcpy($$,"\\notes"); strcat($$,$2);
                                        strcat(strcat($$,"\\enotes"),$1); free($1); }
   ;
emb: EMBP       { $$ = $1; }
   | EMB        { $$ = malloc(MAXLEN); strcpy($$,$1); }
   | REST       { $$ = malloc(MAXLEN); strcpy($$,$1); }
   | ENDFS      { $$ = malloc(MAXLEN); strcpy($$,$1); }
   | STARTFS    { $$ = malloc(MAXLEN);
                  if      ( $1==first )  strcpy($$,"\\Uptext{$\\vert$ 1.}");
                  else if ( $1==second ) strcpy($$,"\\Uptext{$\\vert$ 2.}");
                  else  {   nn=strlen($1);
                    if(nn==1) { strcpy($$,"\\Uptext{repeat ");
                                strcat($$,$1); strcat($$,"}");
                              }
                    else      { strcpy($$,"\\Uptext{$\\vert$ time ");
                                strncat($$,$1,1);
                                strcat($$," on part(s) "); strncat($$,$1+1,1);
                                for(i=3; i <= (int) nn; i++)
                                   {strcat($$,", and ");strncat($$,$1+i-1,1);
                                   }
                                strcat($$,"}");
                              }
                    free($1);
                         }
                  }
     | METER { $$ = malloc(MAXLEN);
                          strcpy($$,$1);
                   }
     | METERFRAC { prelen=strcspn($1,"_");
                   strncpy(num,$1,prelen) ; strcpy(num+prelen,"");
                   strcpy(den,$1+prelen+1) ;
                   $$=malloc(MAXLEN);
                   strcat(strcat(strcat(strcat(strcpy($$,"\\meterfrac{"),
                                   num),"}{"),den),"}");
                         free($1);
                       }
   | emb EMB     { $$ = strcat($1,$2);          }
   | emb EMBP    { $$ = strcat($1,$2); free($2);}
   | emb emb     { $$ = strcat($1,$2); free($2);}
   ;
tiebeat: TIEBEAT  { $$ = $1; }
       | TIE BEAT { $$ = $1; }
       | BEAT TIE { $$ = $2; }
       | tiebeat BEAT { $$ = $1; }
       | BEAT tiebeat { $$ = $2; }
       ;
 bar: BAR         { $$ = (char *) malloc(MAXLEN); strcpy($$,$1); }
    | BEAT bar    { $$ = $2; }
    | bar BEAT    { $$ = $1; }
    | bar ENDFS { $$ = malloc(MAXLEN); strcpy($$,"\\notes"); strcat($$,$2);
                                        strcat(strcat($$,"\\enotes"),$1); free($1); }
/*    | STARTFS bar { if ($2==first || $2==second) {$$=(char *)malloc(MAXLEN);
                                      strcpy($$,$1); strcat($$,$2); free($2); }
           else { $$ = $2; nn=strlen($1);
                  if(nn==1) { strcat($$,"\\notes\\Uptext{repeat ");
                              strcat($$,$1); strcat($$,"}\\enotes");
                            }
                  else {strcat($$,"\\notes\\Uptext{$\\vert$ time ");
                        strncat($$,$1,1);
                        strcat($$," on part(s) "); strncat($$,$1+1,1);
                        for(i=3; i <= (int) nn; i++)
                            {strcat($$,",");strncat($$,$1+i-1,1);
                            }
                         strcat($$,"}\\enotes");
                        }
                  free($2); free($1); }
                 }
    | bar STARTFS { if ($2==first || $2==second) {$$=(char *)malloc(MAXLEN);
                                        strcpy($$,$2); strcat($$,$1); free($1); }
           else { $$ = $1; nn=strlen($2);
                  if(nn==1) { strcat($$,"\\notes\\Uptext{repeat ");
                              strcat($$,$2); strcat($$,"}\\enotes");
                            }
                  else {strcat($$,"\\notes\\Uptext{$\\vert$ time ");
                        strncat($$,$2,1);
                        strcat($$," on part(s) "); strncat($$,$2+1,1);
                        for(i=3; i <= (int) nn; i++)
                            {strcat($$,",");strncat($$,$2+i-1,1);
                            }
                         strcat($$,"}\\enotes");
                        }
                  free($2); free($1); }
                 }   */
    ;

tline: COMMENT { $$= (char *) malloc(MAXLEN);
                 strcat(strcpy($$,"%"),$1); free($1);
               }
     | FORMAT  { $$ = $1; }
     | text { $$ = (char *) malloc(MAXLEN);
               if( ntext != 4 || strlen($1) > 0)
               { if (ntext == 1) {strcat(strcat(strcpy($$,"\\line{\\moyen "),$1)," \\hss}\n"); free($1);}
                 else {strcat(strcat(strcpy($$,"\\line{"),$1)," \\hss}\n"); free($1);}
               }
               else $$=$1;
            }
     | antext { $$=malloc(MAXLEN); strcat(strcat(strcpy($$,"\\line{"),$1),"}\n");
                            free($1);
              }
     | number { $$=malloc(MAXLEN);
           if(ntext > 4){strcat(strcat(strcpy($$,"\\line{"),$1)," \\hss}\n");
                            free($1);
                        }
           else if(ntext == 4){ if(strlen($1) > 0)
                                     {strcpy($$,"\\pagenumbers\\pageno=");
                                      strcat(strcat($$,$1),"\n"); free($1);
                                     }
                                else { strcpy($$,"%\n"); free($1);
                                     }
                              }
           else               {strcat(strcat(strcpy($$,"%"),$1),"\n"); free($1);
                              }
               }
     | text text { $$=malloc(MAXLEN);
                      if(ntext == 2)
                         {strcat(strcat(strcpy($$,"\\line{\\moyen "),$1)," \\hss}\n"); free($1);}
                      else
                         {strcat(strcat(strcpy($$,"\\line{"),$1)," \\hss}\n"); free($1);}
                      strcat(strcat(strcat($$,"\\line{"),$2)," \\hss}\n"); free($2);
                 }

     | text text text { $$=malloc(MAXLEN);
                       if(ntext == 3)
                         {strcat(strcpy($$,"\\line{\\moyen "),$1);
                         strcat(strcat(strcat(strcat(strcat
                         ($$," \\hss\n\\rm "),$2)," \\hss "),$3),"}\n\\bigskip\n");
                         }
                       else
                         {strcat(strcat(strcpy($$,"\\line{"),$1)," \\hss}\n");
                          strcat(strcat(strcat($$,"\\line{"),$2)," \\hss}\n");
                          strcat(strcat(strcat($$,"\\line{"),$3)," \\hss}\n");
                          }
                       free($1); free($2); free($3);
              }
     ;

text: TXT {$$=$1; ntext++; }
    ;

antext: ANTXT                   { $$=$1; ntext++; }
      | TITLE TUNETYPE COMPOSER { $$=strcat(strcat($1,$2),$3); free($2);
                                   free($3); ntext=ntext+3;
                                }
      | TITLE TUNETYPE          { $$=strcat($1,$2); free($2); ntext=ntext+2;
                                }
      | TITLE COMPOSER          { $$=strcat($1,$2); free($2); ntext=ntext+2;
                                }
      | TUNETYPE COMPOSER       { $$=strcat($1,$2); free($2); ntext=ntext+2;
                                }
      | TITLE                   { $$ = $1; ntext++; }
      | TUNETYPE                { $$ = $1; ntext++; }
      | COMPOSER                { $$ = $1; ntext++; }
      ;

number: NUMBER {$$=$1; ntext++; }
      ;

%%

#include <stdio.h>

int yyerror(char *s){printf("%s\n",s); return 0;}

#ifdef MAC
#include "Main.h"
#endif

int main (int argc, char **argv)

{
    int retcode;
    char *infile;
    char *outfile;
    int inopened=0;
    int outopened=0;

       firstline=1; ntext=0; tiepend=0; tiearmed=0;

    if (argc > 1)   /* if a file was named, open it for reading*/
    {
        if(! strncmp(argv[1],"help",4) || ! strncmp(argv[1],"--help",4)
		|| ! strncmp(argv[1],"-h",4))
        {
            printf("usage: bmw2tex [ input [ output ] ]\n\n"
"Bagpipe Music Writer Gold to BagpipeTeX converter.\n\n"
"If an extension is not specified for the input file, \".bmw\" or \".bww\"\n"
"will be assumed.  If an extension is not specified for the output file,\n"
"\".tex\" is used.  If no file names are given, standard input and\n"
"output are used.\n\n");
            exit(0);
              }

              infile=(char *) malloc(129); strcpy(infile,argv[1]);
              if(!(strstr(infile,".bmw") || strstr(infile,".bww")) ) strcat(infile,".bww");

        if (freopen (infile, "r", stdin) == (FILE *) NULL)
        {
            fprintf (stderr, "cannot open %s\n", infile);
            return 1;   /* terminate abnormally */
        }
              else inopened=1;
        fprintf (stderr, "processing %s...\n", infile);

        if(argc > 2) /* if a second file was named, open it for writing*/
        {
                outfile= (char *) malloc(129); strcpy(outfile,argv[2]);
                if(strcmp(outfile+strlen(outfile)-4,".tex"))
                strcat(outfile,".tex");
        }
        else
        {
                outfile= (char *) malloc(129); strcpy(outfile,"");
            strncat(outfile,infile,strlen(infile)-4);
            strcat(outfile,".tex");
        }

        if (freopen (outfile, "w", stdout) == (FILE *) NULL)
        {
            fprintf (stderr, "cannot open %s\n", outfile);
            return 1;   /* terminate abnormally */
        }
              else outopened=1;
        fprintf (stderr, "writing %s...\n", outfile);
              free(infile); free(outfile);
    }

/* standard initial text output */
printf("%s\n","%&bagpipe\n\\input bagpipe\n%");
printf("%s\n","% Converted from bmw or bww format by bww2tex version 2.01\n%");
printf("%s\n","\\def\\freqbarno{9999}");
printf("%s\n","\\maxlinesinpage=12\n%");
printf("%s\n","\\ifx\\medleyflag\\relax\\else\n"
                "  \\nopagenumbers\\pageno=1\\medtall\\medwidewidth\\fi");
printf("%s\n","\\newpitch\\newgrace\\noautoglue\n%");
printf("%s\n","\\musicsize 16\\relax");

yydebug=0; /* set to 1 to turn on parsing trace */

retcode = yyparse();

/* standard ending text */
printf("%s\n","\\byemedley");
printf("%s\n","\\bye");

if (inopened ) fclose(stdin );
if (outopened) fclose(stdout);

return retcode;

}

char *insert(char *aptr, char *bptr)
/* add a note to a beamed note group head structure */
  {
   char *rptr;
   char rchr[MAXLEN];
   size_t len;

   rptr=rchr;
   len=strcspn(aptr," ");
   strncpy(rptr,aptr,len);
   strcpy(rptr+len,bptr);
   strcat(rptr,aptr+len);
   strcpy(aptr,rptr);
   return aptr;
  }

char *inserts(char *aptr, char *bptr, char *cptr)
/* add an embellishment to a beamed note group
   plus a note to its head structure  */
  {
   char *rptr;
   char rchr[MAXLEN];
   char *sptr;
   char schr[MAXLEN];
   char *dptr;
   size_t lena,lenr,lend;

   rptr=rchr;
   sptr=schr;
   lena=strcspn(aptr," ");
   strncpy(rptr,aptr,lena);
   strcpy(rptr+lena,bptr);
   strcat(rptr,aptr+lena);
   dptr=strrchr(rptr,'\\');
   lenr=strlen(rptr);
   lend=strlen(dptr);
   strncpy(sptr,rptr,lenr-lend);
   strcat(strcat(strcat(strcpy(sptr+lenr-lend,"{"),dptr),cptr),"}");
   strcpy(aptr,sptr);
   return aptr;
  }


char *insertt(char *aptr, char *bptr, char *cptr)
/* add a tie to a beamed note group plus a note to its head structure */
  {
   char *rptr;
   char rchr[MAXLEN];
   char *sptr;
   char schr[MAXLEN];
   char *dptr;
   size_t lena,lenr,lend;

   rptr=rchr;
   sptr=schr;
   lena=strcspn(aptr," ");
   strncpy(rptr,aptr,lena);
   strcpy(rptr+lena,bptr);
   strcat(rptr,aptr+lena);
   dptr=strrchr(rptr,'\\');
   lenr=strlen(rptr);
   lend=strlen(dptr);
   strncpy(sptr,rptr,lenr-lend);
   strcat(strcat(strcpy(sptr+lenr-lend,"{"),cptr),dptr);
   if (*(sptr+strlen(sptr)-1) == 'p') strcat(sptr+lenr-lend,"\\tten0}");
   else                               strcat(sptr+lenr-lend,"\\qsk\\tten0}");
   strcpy(aptr,sptr);
   return aptr;
  }

char *inserttie(char *aptr, char* bptr)
/* add a tie between notes */
  {
   char *retptr; char* tieptr; char *rptr;
   char rchr[MAXLEN];
   int lena, lenh, lent;

   rptr=rchr;
   retptr = (char *) malloc(MAXLEN); strcpy(retptr,"");
   tieptr=strrchr(aptr,'\\');
   lena=strlen(aptr); lent=strlen(tieptr); lenh=lena-lent;
   strncat(retptr,aptr,lenh);
   if( *(tieptr+1) != 'b' )
      {
       strcat(retptr,bptr);
       strcat(retptr,aptr+lenh);
       if(*(aptr+lena-1) != 'p') strcat(retptr,"\\qsk");
      }
   else
      {
       strcat(retptr,"{");
       strcat(retptr,bptr); strcat(retptr,aptr+lenh);
       if( *(aptr+lena) != 'p' ) strcat(retptr,"\\qsk}");
       else                      strcat(retptr,"}");
      }
   return retptr;
  }

char *inserttrip( char *aptr, char* bptr)
/* insert a triplet instruction in a beamed group */
  {
   char *retptr;
   char *rptr;
   char rchr[MAXLEN];
   char *sptr;
   char schr[MAXLEN];
   char *cptr; char *dptr; char *eptr;
   char search;
   size_t lta, lha, ltr, lhr, lts, lhs;

   rptr=rchr; strcpy(rptr,"");
   sptr=schr; strcpy(sptr,"");

   retptr= (char *) malloc(MAXLEN); strcpy(retptr,"");
   cptr=strrchr(aptr,'\\'); lta=strlen(cptr); lha=strlen(aptr)-lta;
   strncat(rptr,aptr,lha);

   if(*(cptr-1)=='}')search='{';
   else search='\\';
   dptr=strrchr(rptr,search); ltr=strlen(dptr); lhr=strlen(rptr)-ltr;
   strncat(sptr,rptr,lhr);

   eptr=strrchr(sptr,'\\'); lts=strlen(eptr); lhs=strlen(sptr)-lts;
   strncat(retptr,sptr,lhs);
   if(*(eptr-1)=='{'){ strcat(retptr,bptr); strcat(retptr,eptr);
                     }
   else              { strcat(retptr,"{"); strcat(retptr,bptr);
                       strcat(strcat(retptr,eptr),"}");
                     }
   strcat(retptr,dptr); strcat(retptr,cptr);

   return retptr;
  }

char *insertthtrip( char *aptr, char* bptr)
/* insert a triplet instruction between notes */
  {
   char *retptr;
   char *cptr;
   size_t lta, lha;

   retptr= (char *) malloc(MAXLEN); strcpy(retptr,"");
   cptr=strrchr(aptr,'\\'); lta=strlen(cptr); lha=strlen(aptr)-lta;
   strncat(retptr,aptr,lha); strcat(retptr,bptr); strcat(retptr,cptr);

   return retptr;
  }

char *insertetn(char *aptr)
/* add some glue  (\etn) between beats */
  { /* char *tieptr; */
    /* tieptr=strrchr(aptr,'\\'); */
    /* if( *(tieptr+1) != 'b' ) */
   strcat(aptr,"\\etn");
   strcat(aptr,"\n");
   return aptr;
  }

char *shorten( char *aptr )
/* try to compress a beamed note group to a beam structure with
   four elements */
  {
    char *sptr; char *bptr; char *cptr; char *retptr;
    int lena, lens, lsh, lbh, i, j;

    lena=strlen(aptr);
    sptr = strchr(aptr, ' ');
    lens=strlen(sptr);
    lsh=lena-lens;
    for ( i=2; i<lsh-2; i++)
      {
         if ( *(aptr+i) == *(aptr+i+1) )
            {
             retptr= (char *) malloc(MAXLEN); strcpy(retptr,"");
             bptr=aptr+i+1;
             lbh = lena-strlen(bptr);
             strncat(retptr,aptr,lbh-1); strncat(retptr,bptr,lsh-lbh+4);
             bptr=sptr+4; cptr=bptr;
             for ( j = 2; j < i; j++)
                {
                 if ( *bptr=='{' ) bptr=strchr(bptr,'}')+1;
                 else
                    {
                     bptr=bptr+3;
                     if( *(bptr) == 'p' ) bptr++ ;
                    }
                }
             lbh=strlen(cptr)-strlen(bptr);
             if (lbh) strncat(retptr,cptr,lbh);
             cptr=bptr;
             if( *bptr=='{' )
                {
                 bptr=strchr(bptr+1,'}');
                 lbh=strlen(cptr)-strlen(bptr);
                 strncat(retptr,cptr,lbh);
                 if( *(bptr+1)=='{' ) strcat(retptr,bptr+2);
                 else
                    {
                     strncat(retptr,bptr+1,3); bptr=bptr+4;
                     if(*bptr=='p')
                        {
                         strncat(retptr,bptr,1); bptr++;
                        }
                      strcat(retptr,"}"); strcat(retptr,bptr);
                     }
                }
             else
                {
                 strcat(retptr,"{");
                 strncat(retptr,bptr,3);
                 bptr=bptr+3;
                 if( *(bptr)=='p' ) { strncat(retptr,bptr,1); bptr++; }
                 if( *bptr != '{')
                    {
                      strncat(retptr,bptr,3); bptr=bptr+3;
                      if( *bptr=='p' ){ strncat(retptr,bptr,1); bptr++ ; }
                      strcat(retptr,"}"); strcat(retptr,bptr);
                    }
                 else strcat(retptr,bptr+1);
                }
             free(aptr);
             return retptr;
            }
        }
    printf("%% can't shorten long beam macro, output file will not TeX ");
    return aptr;
  }
