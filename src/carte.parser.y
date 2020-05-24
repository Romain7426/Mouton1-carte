%{ /* Header */
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

//CMap *carte = NULL;
#define this yycarte_global_objet_being_filled_up_while_parsing


void carte_parser_reset(void) {
  /* Nothing to do. */
}

%}

/* Le type de yylval. */
/* Attention !!!!!!!!
   Si problème de définition de type, bien regardé le makefile,
   mais surtout avant chaque #include "parser.h"
   avoir mis un #include "le fichier de description des types.h"
*/
%union {
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
}

%token <yybooleen> Token_Booleen
%token <yyentier>  Token_Entier
%token <yyreel>    Token_Reel
%token <yychaine>  Token_Chaine
%token <yyident>   Token_Ident

%type <yynom> nom

%token Token_Assign
//%token Token_Plus Token_Moins
//%token Token_Mult Token_Div

%token Token_OpenPar Token_OpenBrace Token_OpenBracket
%token Token_ClosePar Token_CloseBrace Token_CloseBracket

%token Token_Ptvirg Token_Virgule
%token Token_EOF

%token Token_Zone 
%token Token_Evenement Token_Genere Token_Par Token_Traitement
%token Token_Objet Token_Objets Token_Angle
%token Token_Qui Token_X Token_Y Token_Z
%token Token_Tous Token_Aucun
%token Token_Image

%token Token_Physique Token_Gameplay Token_Graphique

%token Token_Texture Token_Textures Token_Anime Token_Niveau Token_De
%token Token_Fichier Token_Indice Token_Position Token_Arme


%token Token_Musique Token_Eau Token_Vie Token_Teleportation Token_Dimension
%token Token_Longueur Token_Largeur Token_Hauteur Token_Direction Token_Parcours
%token Token_Destination Token_Gauche Token_Droite Token_Haut Token_Bas


%type <yyentier> expr_entier expr_entier1 expr_entier2 
%token Token_PlusEntier Token_MoinsEntier Token_MultEntier Token_DivEntier Token_ModEntier

%type <yyreel> expr_reel expr_reel1 expr_reel2
//%token Token_ZSol
%token Token_PlusReel Token_MoinsReel Token_MultReel Token_DivReel

%token Token_Procedure

%token Token_Lattice Token_width Token_height Token_Over Token_Spanning 



%type <dir> direction

%type <code> code
%type <genere> genere
//%type <texture> texture
//%type <objet> objet
%type <yyevent> evenement 

//%type <yyliste> liste_objet
//%type <yyliste> liste_texture
%type <yyliste> liste_evenement

/*
  %type <physique> physique 
  %type <gameplay> gameplay 
  %type <graphique> graphique
  %type <carte> main
*/

%start main

%%

main: physique gameplay graphique {
  carte_mess("Le parser a reconnu un fichier de type .carte. Victoire !");
  return 0;
};

physique: 
Token_Physique Token_OpenBrace
Token_CloseBrace
{
  carte_mess("Le parser a reconnu la partie physique d'un .carte.");
};

gameplay:
Token_Gameplay Token_OpenBrace 
   Token_Longueur                Token_Assign expr_reel      Token_Ptvirg 
   Token_Largeur                 Token_Assign expr_reel      Token_Ptvirg 
   Token_Spanning Token_Longueur Token_Assign expr_reel      Token_Ptvirg 
   Token_Spanning Token_Largeur  Token_Assign expr_reel      Token_Ptvirg 
   Token_Arme                    Token_Assign Token_Booleen  Token_Ptvirg 
   Token_Musique                 Token_Assign Token_Chaine   Token_Ptvirg 
   Token_Niveau Token_Eau        Token_Assign expr_reel      Token_Ptvirg 
//Token_Couleur Token_Eau        Token_Assign Token_VCouleur Token_Ptvirg 
   Token_Vie    Token_Eau        Token_Assign expr_reel      Token_Ptvirg 
   liste_teleportation
   liste_evenement
Token_CloseBrace
{
  carte_mess("Le parser a reconnu la partie gameplay d'un .carte.");
  this -> lattice_width   =  $5; 
  this -> lattice_height  =  $9; 
  this -> over_spanning_w = $14; 
  this -> over_spanning_h = $19; 
  this -> arme            = $23; 
  this -> musique = strcopy($27); 
  this -> niveau_eau = $32; 
  this -> vie_eau    = $37; 
};

graphique:
Token_Graphique Token_OpenBrace 
  Token_Fichier Token_De Token_Zone Token_De Token_Niveau  Token_Assign Token_Chaine Token_Ptvirg
  Token_Fichier Token_De Token_Zone Token_De Token_Texture Token_Assign Token_Chaine Token_Ptvirg
  liste_texture
  liste_objet
Token_CloseBrace
{
#if 1
  this -> fichier_de_zone_de_niveau  = strcopy($9); 
  this -> fichier_de_zone_de_texture = strcopy($17); 
#else 
  carte_mess("Chargement du fichier de niveau \"%s\".", $9);
  carte -> ChargerZ($9);
  carte_mess("Chargement terminé.");

  carte_mess("Le parser a reconnu la partie graphique d'un .carte.");
  carte_mess("Chargement du fichier de description des textures du sol \"%s\".", $17);
  carte -> ChargerIndiceTextureBitmap($17);
  carte_mess("Chargement terminé.");
  carte_mess("Au fait, c'est la première texture qui est chargée par le programme pour le sol, étant donné que pour l'instant ça ne supporte pas une multiplicité de textures.");
#endif 
};



liste_teleportation:
  liste_teleportation teleportation {}
| {}
;

teleportation:
Token_Teleportation nom Token_OpenBrace
 Token_Destination Token_Assign Token_Chaine Token_Ptvirg
 Token_Position Token_Assign Token_OpenBrace
  Token_X Token_Assign expr_reel Token_Ptvirg
  Token_Y Token_Assign expr_reel Token_Ptvirg
  Token_Z Token_Assign expr_reel Token_Ptvirg
 Token_CloseBrace Token_Ptvirg
 Token_Dimension Token_Assign Token_OpenBrace
  Token_Longueur Token_Assign expr_reel Token_Ptvirg
  Token_Largeur Token_Assign expr_reel Token_Ptvirg
  Token_Hauteur Token_Assign expr_reel Token_Ptvirg
 Token_CloseBrace Token_Ptvirg
 Token_Direction Token_Parcours Token_Assign direction Token_Ptvirg
 Token_Destination Token_Position Token_Assign Token_OpenBrace
  Token_X Token_Assign expr_reel Token_Ptvirg
  Token_Y Token_Assign expr_reel Token_Ptvirg
  Token_Z Token_Assign expr_reel Token_Ptvirg
 Token_CloseBrace Token_Ptvirg
 Token_Destination Token_Direction Token_Parcours Token_Assign direction Token_Ptvirg
Token_CloseBrace
{
#if 1
  carte__teleportation_push(this, /*nom*/$2, /*destination*/$6, /*x*/$13, /*y*/$17, /*z*/$21, /*longueur*/$30, /*largeur*/$34, /*hauteur*/$38, /*direction*/$45, /*dest_x*/$53, /*dest_y*/$57, /*dest_z*/$61, /*dest_direction*/$69); 
#else 
  carte_mess("Ajout de la zone de téléportation %s", $2);
  carte->AjouterZoneTeleportation(
				  Point3D((float)$13,(float)$17,(float)$21), // position
				  Point3D((float)$30,(float)$34,(float)$38), // dimension
				  $45, // direction
				  $6, // la carte de destination
				  Point3D((float)$53,(float)$57,(float)$61), // position d'arrivée
				  $69); // direction d'arrivée
				  
				  
  
  carte_mess("Zone de téléportation ajoutée.");
#endif
}
;

direction: 
  Token_Gauche {$$ = CARTE_DESC_DIRECTION_GAUCHE;} 
| Token_Droite {$$ = CARTE_DESC_DIRECTION_DROITE;} 
| Token_Haut   {$$ = CARTE_DESC_DIRECTION_DOS;} 
| Token_Bas    {$$ = CARTE_DESC_DIRECTION_FACE;} 
;



liste_evenement:
liste_evenement evenement {}
| {}
;

evenement:
Token_Evenement nom Token_OpenBrace
 Token_Genere Token_Par Token_Assign Token_Entier Token_Ptvirg
 Token_Traitement       Token_Assign code         Token_Ptvirg
Token_CloseBrace
{
#if 1
  carte__events_push(this, /*nom*/$2, /*genere_id*/$7, /*gestion_fichier*/this -> temp_code_fichier, /*genere_proc*/this -> temp_code_proc);  
#else 
//   $$ = carte_new_event();
//   VERIF_NOT_NULL($$,-9)

//   $$->genere = $7->type;
//   if ($7->type == CODE) {
//     $$->par = NULL;
//   }

//   else {
//     $$->par = $7->code;
//   }

//   carte_del_sgenere(&($7));
//   $$->traitement = $11;
  //extern void AddTraitementEvenement(type_evt t, const char* nom_fichier, const char* proc);
  AddTraitementEvenement((type_evt)$7, $11->fichier, $11->nom);
  carte_del_code($11);
#endif 
};


liste_texture:
  liste_texture texture {}
| {}
;

texture:
Token_Texture nom Token_OpenBrace
   Token_Image  Token_Assign Token_Chaine Token_Ptvirg 
   Token_Indice Token_Assign expr_entier  Token_Ptvirg 
Token_CloseBrace
{
#if 1
  carte__texture_push(this, /*nom*/$2, /*image*/$6, /*indice*/$10);  
#else 
  carte_mess("Reconnaissance d'un champ de description de texture par le parser. Cette texture s'appelle \"%s\".", $2);
  carte_mess("Chargement de la texture en mémoire (image = \"%s\", couleur associée = %d).", $6, $10);
  //carte->TextureSol = gestionTexture.prendre($6);
  if (carte->nb_texture < NB_MAX_TEXTURESOL) {
    carte_mess("C'est bon. Il y a assez de places pour mettre la texture.");
    //carte->indices_dans_bitmap[carte->nb_texture] = $10;
    //carte->TextureSol[(carte->nb_texture)++] = gestionTexture.prendre($6);
    carte->AjouterTextureSol($6, $10);
  }
  else {
    carte_err("Il n'y pas assez de place pour mettre la texture. Il faut changer NB_MAX_TEXTURESOL.");
  }
  carte_mess("[nb_textures = %d][NB_MAX_TEXTURES = %d]", carte->nb_texture, NB_MAX_TEXTURESOL);

  carte_mess("Fin du traitement de la texture \"%s\".", $2);
#endif 
};


liste_objet:
  liste_objet objet {}
| {}
;

objet:
Token_Objet nom Token_OpenBrace
  Token_Anime    Token_Assign Token_Booleen Token_Ptvirg
  Token_Fichier  Token_Assign Token_Chaine  Token_Ptvirg
  Token_Position Token_Assign Token_OpenBrace
    Token_X             Token_Assign expr_reel Token_Ptvirg
    Token_Y             Token_Assign expr_reel Token_Ptvirg
    Token_Z             Token_Assign expr_reel Token_Ptvirg
    Token_Angle Token_X Token_Assign expr_reel Token_Ptvirg
    Token_Angle Token_Y Token_Assign expr_reel Token_Ptvirg
    Token_Angle Token_Z Token_Assign expr_reel Token_Ptvirg
  Token_CloseBrace Token_Ptvirg 
Token_CloseBrace
{
#if 1
  carte__objet_push(this, /*nom*/$2, /*anime_huh*/$6, /*fichier*/$10, /*x*/$17, /*y*/$21, /*z*/$25, /*angle_x*/$30, /*angle_y*/$35, /*angle_z*/$40); 
#else 
  carte_mess("Le parser a reconnu un champ objet. Il s'appelle \"%s\".", $2);
  if ($6) {
    carte_mess("C'est un objet animé.");
    carte_mess("Chargement du fichier \"%s\".", $10);
    CBonhomme *bonhomme = new CBonhomme($10);
    carte_mess("Chargement du fichier terminé. On positionne les autres attributs (x, y, z).");
    TPoint3D pos;
    pos.x = $17;
    pos.y = $21;
    pos.z = $25;
    bonhomme->SetPosition(pos);
    carte_mess("Done. Ajout de l'objet à la carte.");
    carte->AjouterObjet($2, bonhomme);
    carte_mess("Done. Les paramètres d'angles ne sont pas encore utilisés.");
  }

  else {
    carte_mess("C'est un objet non animé.");
    carte_mess("Chargement du fichier \"%s\".", $10);
    CObjNonAnime* o = new CObjNonAnime($10);
    carte_mess("Chargement du fichier terminé. On positionne les autres attributs (x, y, z).");
    TPoint3D pos;
    pos.x = $17;
    pos.y = $21;
    pos.z = $25;
    o->SetPosition(pos);
    carte_mess("Done. Ajout de l'objet à la carte.");
    carte->AjouterObjet($2, o);
    carte_mess("Done. Les paramètres d'angles ne sont pas encore utilisés.");
  }

  /*  
      $$->angle_x = $30;
      $$->angle_y = $35;
      $$->angle_z = $40;
  */
#endif 
};



code:
Token_OpenBrace 
Token_Fichier   Token_Assign Token_Chaine Token_Ptvirg 
Token_Procedure Token_Assign Token_Chaine Token_Ptvirg 
Token_CloseBrace
{ 
#if 1 
  this -> temp_code_fichier = $4;
  this -> temp_code_proc = $8; 
#else 
  $$ = carte_new_code(); $$->fichier = $4; $$->nom = $8; 
#endif 
};

nom:
  Token_Chaine { $$ = $1; }
| Token_Ident  { $$ = $1; }






expr_entier:
  expr_entier Token_PlusEntier  expr_entier1 { $$ = $1 + $3; }
| expr_entier Token_MoinsEntier expr_entier1 { $$ = $1 - $3; }
| expr_entier1 { $$= $1; }
;

expr_entier1:
  expr_entier1 Token_MultEntier expr_entier2 { $$ = $1 * $3; }
| expr_entier1 Token_DivEntier  expr_entier2 { $$ = $1 / $3; }
| expr_entier1 Token_ModEntier  expr_entier2 { $$ = $1 % $3; }
| expr_entier2 { $$ = $1; }
;

expr_entier2:
  Token_Entier                                 { $$ =   $1; }
| Token_PlusEntier  expr_entier2               { $$ =   $2; }
| Token_MoinsEntier expr_entier2               { $$ = - $2; }
| Token_OpenPar     expr_entier Token_ClosePar { $$ =   $2; }
;


expr_reel:
  expr_reel Token_PlusReel    expr_reel1 { $$ = $1 + $3; }
| expr_reel Token_PlusEntier  expr_reel1 { $$ = $1 + $3; }
| expr_reel Token_MoinsReel   expr_reel1 { $$ = $1 - $3; }
| expr_reel Token_MoinsEntier expr_reel1 { $$ = $1 - $3; }
| expr_reel1 { $$= $1; }
;

expr_reel1:
  expr_reel1 Token_MultReel   expr_reel2 { $$ = $1 * $3; }
| expr_reel1 Token_MultEntier expr_reel2 { $$ = $1 * $3; }
| expr_reel1 Token_DivReel    expr_reel2 { $$ = $1 / $3; }
| expr_reel1 Token_DivEntier  expr_reel2 { $$ = $1 / $3; }
| expr_reel2 { $$ = $1; }
;

expr_reel2:
  Token_Reel   { $$ = $1; }
| Token_Entier { $$ = $1; }
| Token_PlusReel    expr_reel2 { $$ = $2; }
| Token_PlusEntier  expr_reel2 { $$ = $2; }
| Token_MoinsReel   expr_reel2 { $$ = - $2; }
| Token_MoinsEntier expr_reel2 { $$ = - $2; }
| Token_OpenPar expr_reel Token_ClosePar { $$ = $2; }
;






%%

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

