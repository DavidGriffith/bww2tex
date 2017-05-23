/* token semantic values for bww2tex
   version 2.01
   by Walt Innes {walt@slac.stanford.edu)
*/
char *reprmorceau="\\reprmorceau\n";
char *suspmorceau="\\suspmorceau\n%\n";
char *xbarre="\\xbarre\n";
char *leftrepeatsymbol="\\leftrepeatsymbol\n";
char *alaligne="";
char *setdoublebar="\\setdoublebar";
char *setrightrepeat="\\setrightrepeat";
char *doublebar="\\setdoublebar\\xbarre\n";
char *itenu="\\itenu0";
char *tten="\\tten0";
char *triolet="\\triolet F";
char *meterC="\\meterC";
char *allabreve="\\allabreve";
char *first="\\setprimavolta";
char *second="\\setsecondavolta";
char *sing="\\Uptext{$\\vert$S}";
char *doub="\\Uptext{$\\vert$D}";
char *bis="\\Uptext{$\\vert$\\it bis}";
char *endfs="\\rlap{\\fsk\\Uptext{$\\vert$}}";
char *signature="\\generalsignature";
char *realwide="\\realwidewidth\n";

char *N="N" ;
char *a="a" ;
char *b="b" ;
char *c="c" ;
char *d="d" ;
char *e="e" ;
char *f="f" ;
char *g="g" ;
char *hh="h" ;

char *wh="wh" ;
char *ql="ql" ;
char *s="s"  ;
char *t="t"  ;
char *sf="sf" ;

char *r="r"  ;
char *l="l"  ;


char *gra="\\gra";
char *grb="\\grb";
char *grc="\\grc";
char *grd="\\grd";
char *gre="\\gre";
char *grf="\\grf";
char *grg="\\grg";
char *grh="\\grh";

char *gr="\\gr" ;
char *echo="\\echo";
char *them="\\them";
char *ddgr="\\ddgr";
char *edgr="\\edgr";
char *fdgr="\\fdgr";
char *gdgr="\\gdgr";
char *tdgr="\\tdgr";
char *dstr="\\dstr";
char *gdstr="\\gdstr";
char *tdstr="\\tdstr";
char *hdstr="\\hdstr";
char *tstr="\\tstr";
char *gtstr="\\gtstr";
char *ttstr="\\ttstr";
char *htstr="\\htstr";
char *dbl="\\dbl";
char *tdbl="\\tdbl";
char *hdbl="\\hdbl";
char *hslur="\\hslur";
char *hshk="\\hshk";
char *slur="\\slur";
char *shk="\\shk";
char *tslur="\\tslur";
char *tshk="\\tshk";
char *pel="\\pel" ;
char *lpel="\\lpel" ;
char *tpel="\\tpel";
char *ltpel="\\ltpel";
char *hpel="\\hpel";
char *catch="\\catch";
char *scatch="\\scatch";
char *tcatch="\\tcatch";


char *ldstrd="\\ldstrd";
char *ltstrd="\\ltstrd";
char *thrwd="\\thrwd";
char *gripthrwd="\\gripthrwd";
char *hthrwd="\\hthrwd";
char *hgripthrwd="\\hgripthrwd";
char *tra="\\tra";
char *trac="\\trac";
char *htra="\\hshkd";
char *wbirl="\\wbirl";
char *birl="\\birl";
char *sbirl="\\sbirl";
char *tbirl="\\tbirl";
char *grip="\\grip";
char *hgrip="\\hslurd";
char *dgrip="\\dgrip";
char *Ngrip="\\Ngrip";
char *deda="\\deda";
char *taor="\\taor";
char *dtaor="\\dtaor";
char *htaor="\\htaor";
char *Ntaor="\\Ntaor";
char *ahtaor="\\ahtaor";
char *ahtaorb="\\ahtaorb";
char *crun="\\crun";
char *dcrun="\\dcrun";
char *ahcrun="\\ahcrun";
char *crunbr="\\crunbr";
char *dcrunbr="\\dcrunbr";
char *hcrunbr="\\hcrunbr";
char *ahcrunbr="\\ahcrunbr";
char *Nhcrun="\\Nhcrun";
char *darodo="\\darodo";
char *Ndarodo="\\Ndarodo";
char *darodos="\\darodos";

char *edre="\\edre";
char *edreb="\\edreb";
char *edrec="\\edrec";
char *edred="\\edred";
char *dare="\\dare";
char *hedari="\\hedari";
char *dbstf="\\dbstf";
char *dbsth="\\dbsth";
char *gedre="\\gedre";
char *gdare="\\gdare";
char *tedre="\\tedre";
char *tdare="\\tdare";
char *tchechere="\\tchechere";
char *hchechere="\\hchechere";
char *hdre="\\hdre";
char *hedale="\\hedale";
char *hiharin="\\hiharin";
char *chelalho="\\chelalho";

char *cadged="\\cadged";
char *cadge="\\cadge";
char *cadgf="\\cadgf";
char *caded="\\caded";
char *cadaed="\\cadaed";
char *cadae="\\cadae";
char *fcadged="\\fcadged";
char *fcadge="\\fcadge";
char *fcadgf="\\fcadgf";
char *fcaded="\\fcaded";
char *fcadaed="\\fcadaed";
char *fcadae="\\fcadae";
char *fcade="\\fcade";

char *hgrpb="\\hgrpb";
char *hgrpc="\\hgrpc";
char *scatchb="\\scatchb";
char *scatchc="\\scatchc";
char *tcatchb="\\tcatchb";
char *tcatchc="\\tcatchc";

char *enbain="\\enbain";
char *otro="\\otro";
char *odro="\\odro";
char *adela="\\adela";
char *genbain="\\genbain";
char *gotro="\\gotro";
char *godro="\\godro";
char *gadela="\\gadela";
char *tenbain="\\tenbain";
char *totro="\\totro";
char *todro="\\todro";
char *tadela="\\tadela";

/* avoid function namespace conflict with pause(2) in unistd.h */
char *_pause="\\pause";
char *hpause="\\hpause";
char *soupir="\\soupir";
char *dsoupir="\\dsoupir";
char *quantsoupir="\\quantsoupir";
char *huitsoupir="\\huitsoupir";

char *pointdorgue="\\pointdorgue ";
char *fermat="\\backput{\\pointdorgue ";
char *pince="\\pince f";
char *pdare="\\pince h";
char *trille="\\uptext{\\it tr}";
char *turn="\\turn f";
char *upz="\\upz f";
char *abrleum="\\backput{\\Downtext{L}}";
char *abrleumbr="\\backput{\\Downtext{L}}\\pointdorgue e";
char *abrtaor="\\backput{\\Downtext{T}}";
char *abrtaorbr="\\backput{\\Downtext{'T}}";
char *abrtaorm="\\backput{\\Downtext{T'}}";
char *abrcrun="\\backput{\\Downtext{C}}";
char *abrcrunbr="\\backput{\\Downtext{'C}}";
char *abrcrunm="\\backput{\\Downtext{C'}}";
char *abrtrip="\\Downtext{3}";

char *na="\\na ";
char *fl="\\fl ";
char *shp="\\shp ";

char *fine="\\Uptext{\\it fine}";
char *segno="\\segno h";
char *coda="\\coda";
char *dalsegno="\\notes\\downtext{\\it D.S.}\\enotes";
char *dacapoalfine="\\notes\\Downtext{\\ \\ \\it D.C. al fine}\\enotes";
char *dacapoalcoda="\\notes\\Downtext{\\ \\ \\ \\it D.C. al coda}\\enotes";

char *one="1";
char *two="2";
