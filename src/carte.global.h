#ifndef CARTE_GLOBAL_HPP
#define CARTE_GLOBAL_HPP

/* Fonctions du lexer. */
extern int carte_get_nb_lignes(void);
extern int carte_get_nb_chars(void);
extern int carte_get_nb_chars_tot(void);
extern int carte_get_yyleng(void);
extern char * carte_get_yytext(void);
extern int yycartelex(void);
extern void yycarterestart(FILE * new_file);
extern void carte_restart_lexer(void);

extern FILE * yycartein;
extern FILE * yycarteout;
#define stderr_FILE stderr


#define MALLOC_BZERO(ctype_t,this) ctype_t * this = NULL; this = (ctype_t *) malloc(sizeof(*this)); bzero(this, sizeof(*this)); 

// RL: We can't declare it 'extern' otherwise it will be in the library and it will collide with libraries which provide the same function... 
// RL: However, if for any reason, no external library provide such a function, we then have to provide it. 
//extern char * strcopy(const char * str); 
extern char * carte_strcopy(const char * str); 
#ifndef strcopy 
#define strcopy carte_strcopy 
#endif 


extern carte_t * yycarte_global_objet_being_filled_up_while_parsing; 

/* Fonction du parser. */

extern int yycarteparse(void);
extern void carte_parser_reset(void);

#define BIGLIB_STRING(s) BIGLIB_STRINGX(s)
#define BIGLIB_STRINGX(s) #s

/* Fonction de message. */
#if 0 
extern void carte_mess(const char * mess, ...);
extern void carte_err(const char * mess, ...);
#else 
#define carte_mess(...)							\
  fprintf(yycarteout == NULL ? stderr_FILE : yycarteout, "CARTE_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " BIGLIB_STRING(__func__) ": "  __VA_ARGS__); 
//putc('\n', yycarteout); 
//#define carte_err(format_mess,...)  fprintf(yycarteout, "ERREUR: " "CARTE_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " BIGLIB_STRING(__func__) ": " format_mess "\n", __VA_ARGS__);
#define carte_err(...)							\
  if (!yycarteout) fprintf(yycarteout , "ERREUR: " "CARTE_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " BIGLIB_STRING(__func__) ": " __VA_ARGS__) ; \
  fprintf(                 stderr_FILE,            "CARTE_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " BIGLIB_STRING(__func__) ": " __VA_ARGS__); \
  //putc('\n', yycarteout); 
#endif 
#define message carte_mess




enum booleen {faux = 0, vrai = -1};
typedef enum booleen booleen;

#define  pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068;
#define  e  2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427;





#if 0 
#include <stdio.h>
#include <stdarg.h>
#include "map.hpp"
#include "messages.hpp"

extern CMap * carte;



typedef float corps;

/*
const static corps pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068;

const static corps e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427;
*/

/* Maintenant, on va mettre une sémantique au programme.
   Pour cela on déclare les structures objets. */

/* La structure de liste. */
struct liste {
  void *contenu;
  struct liste *suivant;
};

//typedef struct liste *liste;

extern liste * liste_vide(void);
extern liste * mp(void *, liste *);
extern void raz(liste * *);



/* Un point ou un vecteur, c'est la même chose. */
union tvecteur {
  corps coord[3];
  struct {corps x, y, z;} proj;
};

//typedef union tvecteur *tvecteur;

extern tvecteur* new_vecteur(void);
extern void del_vecteur(tvecteur* *);


/* La partie physique. */
struct carte_tphysique {
};

//typedef struct tphysique *tphysique;

extern carte_tphysique* carte_new_physique(void);
extern void carte_del_physique(carte_tphysique* *);



/* Problème de la définition du code. */
//typedef int *carte_tcode;
struct carte_tcode {
  const char *nom, *fichier;
};
extern carte_tcode* carte_new_code(void);
extern void carte_del_code(carte_tcode *(&code));

/* Maintenant, la gestion du 'genere par' d'un évènement. */
enum carte_tgenere {TOUS, AUCUN, CODE};
typedef enum carte_tgenere carte_tgenere;
struct carte_sgenere {
  carte_tgenere type;
  carte_tcode * code;
};
//typedef struct sgenere *sgenere;
extern carte_sgenere * carte_new_sgenere(void);
extern void carte_del_sgenere(carte_sgenere * *);

/* On peut passer à la définition des évènements. */
struct carte_tevent {
  carte_tgenere genere;
  carte_tcode * par;
  carte_tcode * traitement;
};

//typedef struct tevent *tevent;

extern carte_tevent* carte_new_event(void);
extern void carte_del_event(carte_tevent* *);


/* La partie gameplay. */
struct carte_tgameplay {
  booleen arme;
  liste events;
};

//typedef struct tgameplay *tgameplay;

extern carte_tgameplay * carte_new_gameplay(void);
extern void carte_del_gameplay(carte_tgameplay * *);



struct carte_ttexture {
  char *image;
  unsigned int indice;
};
//typedef struct ttexture *ttexture;
extern carte_ttexture * carte_new_texture(void);
extern void carte_del_texture(carte_ttexture * *);


struct carte_tobjet {
  booleen anime;
  char * fichier;
  corps x, y, z;
  corps angle_x, angle_y, angle_z;
};
//typedef struct tobjet *tobjet;
extern carte_tobjet * carte_new_objet(void);
extern void carte_del_objet(carte_tobjet * *);

/* La partie graphique. */
struct carte_tgraphique {
  char * niveau;
  char * texture;
  liste textures;
  liste objets;
};
  
//typedef struct tgraphique *tgraphique;
extern carte_tgraphique* carte_new_graphique(void);
extern void carte_del_graphique(carte_tgraphique* *);


/* Et enfin, l'aboutissement. */
struct carte_tcarte {
  carte_tphysique physique;
  carte_tgameplay gameplay;
  carte_tgraphique graphique;
};

//typedef struct tcarte *tcarte;
extern carte_tcarte* carte_new_carte(void);
extern void carte_del_carte(carte_tcarte* *);


#endif 

#endif /* CARTE_GLOBAL_HPP */
