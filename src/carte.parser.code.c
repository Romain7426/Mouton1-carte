#include <stdlib.h>
#include <string.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
#define yyparse yycarteparse
#define yylex yycartelex
#define yyerror yycarteerror
#define yychar yycartechar
#define yyval yycarteval
#define yylval yycartelval
#define yydebug yycartedebug
#define yynerrs yycartenerrs
#define yyerrflag yycarteerrflag
#define yyss yycartess
#define yysslim yycartesslim
#define yyssp yycartessp
#define yyvs yycartevs
#define yyvsp yycartevsp
#define yystacksize yycartestacksize
#define yylhs yycartelhs
#define yylen yycartelen
#define yydefred yycartedefred
#define yydgoto yycartedgoto
#define yysindex yycartesindex
#define yyrindex yycarterindex
#define yygindex yycartegindex
#define yytable yycartetable
#define yycheck yycartecheck
#define yyname yycartename
#define yyrule yycarterule
#define YYPREFIX "yycarte"
#line 1 "src/carte.parser.y"
 /* Header */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include "carte.h"
#include "carte.global.h"
#include "carte.parser.tab.h"

static void yyerror(const char * s);

#define VERIF_NOT_NULL(a,b) {if (a == NULL) {yyerror("Manque de mémoire."); return b;}}

/*CMap *carte = NULL;*/
#define this yycarte_global_objet_being_filled_up_while_parsing


void carte_parser_reset(void) {
  /* Nothing to do. */
}

#line 31 "src/carte.parser.y"
#ifndef YYSTYPE_DEFINED
#define YYSTYPE_DEFINED
typedef union {
booleen yybooleen;
int yyentier;
double yyreel;
char *yychaine;
char *yyident;
int dir;
char * yynom;


#if 0 
carte_tcode *code;
carte_sgenere *genere;
carte_tobjet *objet;
carte_ttexture *texture;
carte_tevent *yyevent;
liste *yyliste;
carte_tphysique *physique;
carte_tgameplay *gameplay;
carte_tgraphique *graphique;
carte_tcarte *carte;
TDirection dir;
#endif 
} YYSTYPE;
#endif /* YYSTYPE_DEFINED */
#line 90 "src/carte.parser.code.c"
#define Token_Booleen 257
#define Token_Entier 258
#define Token_Reel 259
#define Token_Chaine 260
#define Token_Ident 261
#define Token_Assign 262
#define Token_OpenPar 263
#define Token_OpenBrace 264
#define Token_OpenBracket 265
#define Token_ClosePar 266
#define Token_CloseBrace 267
#define Token_CloseBracket 268
#define Token_Ptvirg 269
#define Token_Virgule 270
#define Token_EOF 271
#define Token_Zone 272
#define Token_Evenement 273
#define Token_Genere 274
#define Token_Par 275
#define Token_Traitement 276
#define Token_Objet 277
#define Token_Objets 278
#define Token_Angle 279
#define Token_Qui 280
#define Token_X 281
#define Token_Y 282
#define Token_Z 283
#define Token_Tous 284
#define Token_Aucun 285
#define Token_Image 286
#define Token_Physique 287
#define Token_Gameplay 288
#define Token_Graphique 289
#define Token_Texture 290
#define Token_Textures 291
#define Token_Anime 292
#define Token_Niveau 293
#define Token_De 294
#define Token_Fichier 295
#define Token_Indice 296
#define Token_Position 297
#define Token_Arme 298
#define Token_Musique 299
#define Token_Eau 300
#define Token_Vie 301
#define Token_Teleportation 302
#define Token_Dimension 303
#define Token_Longueur 304
#define Token_Largeur 305
#define Token_Hauteur 306
#define Token_Direction 307
#define Token_Parcours 308
#define Token_Destination 309
#define Token_Gauche 310
#define Token_Droite 311
#define Token_Haut 312
#define Token_Bas 313
#define Token_PlusEntier 314
#define Token_MoinsEntier 315
#define Token_MultEntier 316
#define Token_DivEntier 317
#define Token_ModEntier 318
#define Token_PlusReel 319
#define Token_MoinsReel 320
#define Token_MultReel 321
#define Token_DivReel 322
#define Token_Procedure 323
#define Token_Lattice 324
#define Token_width 325
#define Token_height 326
#define Token_Over 327
#define Token_Spanning 328
#define genere 329
#define YYERRCODE 256
#define YYTABLESIZE 423
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 329
extern const short yylhs[];
extern const short yylen[];
extern const short yydefred[];
extern const short yydgoto[];
extern const short yysindex[];
extern const short yyrindex[];
extern const short yygindex[];
extern const short yytable[];
extern const short yycheck[];
#if YYDEBUG
extern const char *const yyname[];
extern const char *const yyrule[];
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
/* LINTUSED */
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
unsigned int yystacksize;
int yyparse(void);
#line 453 "src/carte.parser.y"


/*extern void yyerror(char *msg);*/
#include <stdio.h>
static void yyerror(const char * s) {
  int a, b, c;
  a = carte_get_nb_chars();
  b = carte_get_nb_chars_tot();
  c = carte_get_yyleng();
  //carte_err("%s: Erreur d'analyse syntaxique sur le lexème \"%s\" à la ligne %d (caractères %d (%d) à %d (%d)) [%s]\n", this -> filename, carte_get_yytext(), carte_get_nb_lignes() + 1, a - c, b - c, a - 1, b - 1, s);
  carte_err("%s:%d:%d-%d: Erreur d'analyse syntaxique sur le lexème \"%s\" [%s]\n", this -> filename, carte_get_nb_lignes() + 1, a - c, a - 1, carte_get_yytext(), s);
}

#line 224 "src/carte.parser.code.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    unsigned int newsize;
    long sslen;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    sslen = yyssp - yyss;
#ifdef SIZE_MAX
#define YY_SIZE_MAX SIZE_MAX
#else
#define YY_SIZE_MAX 0xffffffffU
#endif
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newss)
        goto bail;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss); /* overflow check above */
    if (newss == NULL)
        goto bail;
    yyss = newss;
    yyssp = newss + sslen;
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newvs)
        goto bail;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs); /* overflow check above */
    if (newvs == NULL)
        goto bail;
    yyvs = newvs;
    yyvsp = newvs + sslen;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
bail:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return -1;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif /* YYDEBUG */

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 128 "src/carte.parser.y"
{
  carte_mess("Le parser a reconnu un fichier de type .carte. Victoire !");
  return 0;
}
break;
case 2:
#line 136 "src/carte.parser.y"
{
  carte_mess("Le parser a reconnu la partie physique d'un .carte.");
}
break;
case 3:
#line 154 "src/carte.parser.y"
{
  carte_mess("Le parser a reconnu la partie gameplay d'un .carte.");
  this -> lattice_width   =  yyvsp[-36].yyreel; 
  this -> lattice_height  =  yyvsp[-32].yyreel; 
  this -> over_spanning_w = yyvsp[-27].yyreel; 
  this -> over_spanning_h = yyvsp[-22].yyreel; 
  this -> arme            = yyvsp[-18].yybooleen; 
  this -> musique = strcopy(yyvsp[-14].yychaine); 
  this -> niveau_eau = yyvsp[-9].yyreel; 
  this -> vie_eau    = yyvsp[-4].yyreel; 
}
break;
case 4:
#line 173 "src/carte.parser.y"
{
#if 1
  this -> fichier_de_zone_de_niveau  = strcopy(yyvsp[-12].yychaine); 
  this -> fichier_de_zone_de_texture = strcopy(yyvsp[-4].yychaine); 
#else 
  carte_mess("Chargement du fichier de niveau \"%s\".", yyvsp[-12].yychaine);
  carte -> ChargerZ(yyvsp[-12].yychaine);
  carte_mess("Chargement terminé.");

  carte_mess("Le parser a reconnu la partie graphique d'un .carte.");
  carte_mess("Chargement du fichier de description des textures du sol \"%s\".", yyvsp[-4].yychaine);
  carte -> ChargerIndiceTextureBitmap(yyvsp[-4].yychaine);
  carte_mess("Chargement terminé.");
  carte_mess("Au fait, c'est la première texture qui est chargée par le programme pour le sol, étant donné que pour l'instant ça ne supporte pas une multiplicité de textures.");
#endif 
}
break;
case 5:
#line 193 "src/carte.parser.y"
{}
break;
case 6:
#line 194 "src/carte.parser.y"
{}
break;
case 7:
#line 218 "src/carte.parser.y"
{
#if 1
  carte__teleportation_push(this, /*nom*/yyvsp[-69].yynom, /*destination*/yyvsp[-65].yychaine, /*x*/yyvsp[-58].yyreel, /*y*/yyvsp[-54].yyreel, /*z*/yyvsp[-50].yyreel, /*longueur*/yyvsp[-41].yyreel, /*largeur*/yyvsp[-37].yyreel, /*hauteur*/yyvsp[-33].yyreel, /*direction*/yyvsp[-26].dir, /*dest_x*/yyvsp[-18].yyreel, /*dest_y*/yyvsp[-14].yyreel, /*dest_z*/yyvsp[-10].yyreel, /*dest_direction*/yyvsp[-2].dir); 
#else 
  carte_mess("Ajout de la zone de téléportation %s", yyvsp[-69].yynom);
  carte->AjouterZoneTeleportation(
				  Point3D((float)yyvsp[-58].yyreel,(float)yyvsp[-54].yyreel,(float)yyvsp[-50].yyreel), /* position*/
				  Point3D((float)yyvsp[-41].yyreel,(float)yyvsp[-37].yyreel,(float)yyvsp[-33].yyreel), /* dimension*/
				  yyvsp[-26].dir, /* direction*/
				  yyvsp[-65].yychaine, /* la carte de destination*/
				  Point3D((float)yyvsp[-18].yyreel,(float)yyvsp[-14].yyreel,(float)yyvsp[-10].yyreel), /* position d'arrivée*/
				  yyvsp[-2].dir); /* direction d'arrivée*/
				  
				  
  
  carte_mess("Zone de téléportation ajoutée.");
#endif
}
break;
case 8:
#line 239 "src/carte.parser.y"
{yyval.dir = CARTE_DESC_DIRECTION_GAUCHE;}
break;
case 9:
#line 240 "src/carte.parser.y"
{yyval.dir = CARTE_DESC_DIRECTION_DROITE;}
break;
case 10:
#line 241 "src/carte.parser.y"
{yyval.dir = CARTE_DESC_DIRECTION_DOS;}
break;
case 11:
#line 242 "src/carte.parser.y"
{yyval.dir = CARTE_DESC_DIRECTION_FACE;}
break;
case 12:
#line 248 "src/carte.parser.y"
{}
break;
case 13:
#line 249 "src/carte.parser.y"
{}
break;
case 14:
#line 257 "src/carte.parser.y"
{
#if 1
  carte__events_push(this, /*nom*/yyvsp[-11].yynom, /*genere_id*/yyvsp[-6].yyentier, /*gestion_fichier*/this -> temp_code_fichier, /*genere_proc*/this -> temp_code_proc);  
#else 
/*   $$ = carte_new_event();*/
/*   VERIF_NOT_NULL($$,-9)*/

/*   $$->genere = $7->type;*/
/*   if ($7->type == CODE) {*/
/*     $$->par = NULL;*/
/*   }*/

/*   else {*/
/*     $$->par = $7->code;*/
/*   }*/

/*   carte_del_sgenere(&($7));*/
/*   $$->traitement = $11;*/
  /*extern void AddTraitementEvenement(type_evt t, const char* nom_fichier, const char* proc);*/
  AddTraitementEvenement((type_evt)yyvsp[-6].yyentier, yyvsp[-2].code->fichier, yyvsp[-2].code->nom);
  carte_del_code(yyvsp[-2].code);
#endif 
}
break;
case 15:
#line 283 "src/carte.parser.y"
{}
break;
case 16:
#line 284 "src/carte.parser.y"
{}
break;
case 17:
#line 292 "src/carte.parser.y"
{
#if 1
  carte__texture_push(this, /*nom*/yyvsp[-10].yynom, /*image*/yyvsp[-6].yychaine, /*indice*/yyvsp[-2].yyentier);  
#else 
  carte_mess("Reconnaissance d'un champ de description de texture par le parser. Cette texture s'appelle \"%s\".", yyvsp[-10].yynom);
  carte_mess("Chargement de la texture en mémoire (image = \"%s\", couleur associée = %d).", yyvsp[-6].yychaine, yyvsp[-2].yyentier);
  /*carte->TextureSol = gestionTexture.prendre($6);*/
  if (carte->nb_texture < NB_MAX_TEXTURESOL) {
    carte_mess("C'est bon. Il y a assez de places pour mettre la texture.");
    /*carte->indices_dans_bitmap[carte->nb_texture] = $10;*/
    /*carte->TextureSol[(carte->nb_texture)++] = gestionTexture.prendre($6);*/
    carte->AjouterTextureSol(yyvsp[-6].yychaine, yyvsp[-2].yyentier);
  }
  else {
    carte_err("Il n'y pas assez de place pour mettre la texture. Il faut changer NB_MAX_TEXTURESOL.");
  }
  carte_mess("[nb_textures = %d][NB_MAX_TEXTURES = %d]", carte->nb_texture, NB_MAX_TEXTURESOL);

  carte_mess("Fin du traitement de la texture \"%s\".", yyvsp[-10].yynom);
#endif 
}
break;
case 18:
#line 316 "src/carte.parser.y"
{}
break;
case 19:
#line 317 "src/carte.parser.y"
{}
break;
case 20:
#line 333 "src/carte.parser.y"
{
#if 1
  carte__objet_push(this, /*nom*/yyvsp[-42].yynom, /*anime_huh*/yyvsp[-38].yybooleen, /*fichier*/yyvsp[-34].yychaine, /*x*/yyvsp[-27].yyreel, /*y*/yyvsp[-23].yyreel, /*z*/yyvsp[-19].yyreel, /*angle_x*/yyvsp[-14].yyreel, /*angle_y*/yyvsp[-9].yyreel, /*angle_z*/yyvsp[-4].yyreel); 
#else 
  carte_mess("Le parser a reconnu un champ objet. Il s'appelle \"%s\".", yyvsp[-42].yynom);
  if (yyvsp[-38].yybooleen) {
    carte_mess("C'est un objet animé.");
    carte_mess("Chargement du fichier \"%s\".", yyvsp[-34].yychaine);
    CBonhomme *bonhomme = new CBonhomme(yyvsp[-34].yychaine);
    carte_mess("Chargement du fichier terminé. On positionne les autres attributs (x, y, z).");
    TPoint3D pos;
    pos.x = yyvsp[-27].yyreel;
    pos.y = yyvsp[-23].yyreel;
    pos.z = yyvsp[-19].yyreel;
    bonhomme->SetPosition(pos);
    carte_mess("Done. Ajout de l'objet à la carte.");
    carte->AjouterObjet(yyvsp[-42].yynom, bonhomme);
    carte_mess("Done. Les paramètres d'angles ne sont pas encore utilisés.");
  }

  else {
    carte_mess("C'est un objet non animé.");
    carte_mess("Chargement du fichier \"%s\".", yyvsp[-34].yychaine);
    CObjNonAnime* o = new CObjNonAnime(yyvsp[-34].yychaine);
    carte_mess("Chargement du fichier terminé. On positionne les autres attributs (x, y, z).");
    TPoint3D pos;
    pos.x = yyvsp[-27].yyreel;
    pos.y = yyvsp[-23].yyreel;
    pos.z = yyvsp[-19].yyreel;
    o->SetPosition(pos);
    carte_mess("Done. Ajout de l'objet à la carte.");
    carte->AjouterObjet(yyvsp[-42].yynom, o);
    carte_mess("Done. Les paramètres d'angles ne sont pas encore utilisés.");
  }

  /*  
      $$->angle_x = $30;
      $$->angle_y = $35;
      $$->angle_z = $40;
  */
#endif 
}
break;
case 21:
#line 383 "src/carte.parser.y"
{ 
#if 1 
  this -> temp_code_fichier = yyvsp[-6].yychaine;
  this -> temp_code_proc = yyvsp[-2].yychaine; 
#else 
  yyval.code = carte_new_code(); yyval.code->fichier = yyvsp[-6].yychaine; yyval.code->nom = yyvsp[-2].yychaine; 
#endif 
}
break;
case 22:
#line 393 "src/carte.parser.y"
{ yyval.yynom = yyvsp[0].yychaine; }
break;
case 23:
#line 394 "src/carte.parser.y"
{ yyval.yynom = yyvsp[0].yyident; }
break;
case 24:
#line 402 "src/carte.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier + yyvsp[0].yyentier; }
break;
case 25:
#line 403 "src/carte.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier - yyvsp[0].yyentier; }
break;
case 26:
#line 404 "src/carte.parser.y"
{ yyval.yyentier= yyvsp[0].yyentier; }
break;
case 27:
#line 408 "src/carte.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier * yyvsp[0].yyentier; }
break;
case 28:
#line 409 "src/carte.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier / yyvsp[0].yyentier; }
break;
case 29:
#line 410 "src/carte.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier % yyvsp[0].yyentier; }
break;
case 30:
#line 411 "src/carte.parser.y"
{ yyval.yyentier = yyvsp[0].yyentier; }
break;
case 31:
#line 415 "src/carte.parser.y"
{ yyval.yyentier =   yyvsp[0].yyentier; }
break;
case 32:
#line 416 "src/carte.parser.y"
{ yyval.yyentier =   yyvsp[0].yyentier; }
break;
case 33:
#line 417 "src/carte.parser.y"
{ yyval.yyentier = - yyvsp[0].yyentier; }
break;
case 34:
#line 418 "src/carte.parser.y"
{ yyval.yyentier =   yyvsp[-1].yyentier; }
break;
case 35:
#line 423 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel + yyvsp[0].yyreel; }
break;
case 36:
#line 424 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel + yyvsp[0].yyreel; }
break;
case 37:
#line 425 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel - yyvsp[0].yyreel; }
break;
case 38:
#line 426 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel - yyvsp[0].yyreel; }
break;
case 39:
#line 427 "src/carte.parser.y"
{ yyval.yyreel= yyvsp[0].yyreel; }
break;
case 40:
#line 431 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel * yyvsp[0].yyreel; }
break;
case 41:
#line 432 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel * yyvsp[0].yyreel; }
break;
case 42:
#line 433 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel / yyvsp[0].yyreel; }
break;
case 43:
#line 434 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel / yyvsp[0].yyreel; }
break;
case 44:
#line 435 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 45:
#line 439 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 46:
#line 440 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[0].yyentier; }
break;
case 47:
#line 441 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 48:
#line 442 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 49:
#line 443 "src/carte.parser.y"
{ yyval.yyreel = - yyvsp[0].yyreel; }
break;
case 50:
#line 444 "src/carte.parser.y"
{ yyval.yyreel = - yyvsp[0].yyreel; }
break;
case 51:
#line 445 "src/carte.parser.y"
{ yyval.yyreel = yyvsp[-1].yyreel; }
break;
#line 759 "src/carte.parser.code.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (1);
yyaccept:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (0);
}
