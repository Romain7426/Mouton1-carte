#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <stdarg.h>
#include "carte.h"
#include "carte.global.h"
#include "carte.parser.tab.h"



carte_t * carte_make(void) {  
  MALLOC_BZERO(carte_t,this); 
  return this; 
};  

void carte_delete(carte_t * this) {  
  for (int i = 0; i < this -> objet_nb; i++) { 
    free(this -> objet_nom[i]); 
    free(this -> objet_fichier[i]); 
  }; 
 
  for (int i = 0; i < this -> texture_nb; i++) { 
    free(this -> texture_nom[i]); 
    free(this -> texture_image[i]); 
  }; 

  free(this -> fichier_de_zone_de_niveau); 
  free(this -> fichier_de_zone_de_texture); 
  
  for (int i = 0; i < this -> events_nb; i++) { 
    free(this -> events_nom[i]); 
    free(this -> events_gestion_fichier[i]); 
    free(this -> events_gestion_proc[i]); 
  }; 

  for (int i = 0; i < this -> events_nb; i++) { 
    free(this -> teleportation_nom[i]); 
    free(this -> teleportation_destination[i]); 
  }; 
  
  free(this -> musique); 
  free(this -> filename); 
  
  free(this); 
};  

carte_t * carte_make_from_file(const char * filename, const char * log_filename) {  
  MALLOC_BZERO(carte_t,this); 
  const int retval = carte__fill_from_file(this, filename, log_filename); 
  if (retval < 0) { 
    free(this); 
    return NULL; 
  }; 
  return this; 
};  

void carte__teleportation_push(carte_t * this, const char * nom, const char * destination, const float x, const float y, const float z, const float longueur, const float largeur, const float hauteur, const int direction, const float dest_x, const float dest_y, const float dest_z, const int dest_direction) { 
  assert(this -> teleportation_nb < carte_teleportation_size); 
  const int i = this -> teleportation_nb; 
  this -> teleportation_nom[i] = strcopy(nom); 
  this -> teleportation_destination[i] = strcopy(destination);
  this -> teleportation_x[i] = x; 
  this -> teleportation_y[i] = y; 
  this -> teleportation_z[i] = z; 
  this -> teleportation_longueur[i] = longueur; 
  this -> teleportation_largeur[i] = largeur; 
  this -> teleportation_hauteur[i] = hauteur; 
  this -> teleportation_direction[i] = direction; 
  this -> teleportation_destination_x[i] = dest_x; 
  this -> teleportation_destination_y[i] = dest_y; 
  this -> teleportation_destination_z[i] = dest_z; 
  this -> teleportation_destination_direction[i] = dest_direction; 
  this -> teleportation_nb++; 
}; 

void carte__events_push(carte_t * this, const char * nom, const int genere_id, const char * gestion_fichier, const char * gestion_proc) { 
  assert(this -> events_nb < carte_events_size); 
  const int i = this -> events_nb; 
  this -> events_nom[i] = strcopy(nom); 
  this -> events_genere[i] = genere_id; 
  this -> events_gestion_fichier[i] = strcopy(gestion_fichier); 
  this -> events_gestion_proc[i] = strcopy(gestion_proc); 
  this -> events_nb++; 
};  

void carte__texture_push(carte_t * this, const char * nom, const char * image, const int indice) { 
  assert(this -> texture_nb < carte_texture_size); 
  const int i = this -> texture_nb; 
  this -> texture_nom[i] = strcopy(nom); 
  this -> texture_image[i] = strcopy(image); 
  this -> texture_indice[i] = indice; 
  this -> texture_nb++; 
};  

void carte__objet_push(carte_t * this, const char * nom, const int anime_huh, const char * fichier, const float x, const float y, const float z, const float angle_x, const float angle_y, const float angle_z) { 
  //carte_err("%s: " "nom: %s - anime_huh: %d - fichier: %s " "\n", __func__, nom, anime_huh, fichier); 
  assert(this -> objet_nb < carte_objet_size); 
  const int i = this -> objet_nb; 
  this -> objet_nom[i] = strcopy(nom); 
  this -> objet_fichier[i] = strcopy(fichier); 
  this -> objet_anime_huh[i] = anime_huh; 
  this -> objet_x[i] = x; 
  this -> objet_y[i] = y; 
  this -> objet_z[i] = z; 
  this -> objet_angle_x[i] = angle_x; 
  this -> objet_angle_y[i] = angle_y; 
  this -> objet_angle_z[i] = angle_z; 
  this -> objet_nb++; 
  //carte_err("%s: " "IDX: %d -- nom: %s - anime_huh: %d - fichier: %s " "\n", __func__, i, this -> objet_nom[i], this -> objet_anime_huh[i], this -> objet_fichier[i]); 
};  










void carte__print(const carte_t * this, FILE * out_stream) { 
  //fprintf(out_stream, "filename = '%s'" "\n", NULL); 
  fprintf(out_stream, "filename = '%s'" "\n", this -> filename); 

  fprintf(out_stream, " " "\n"); 

#if 0 
  fprintf(out_stream, "physique { " "\n"); 
  fprintf(out_stream, "\t" "choc_longueur = %f" "\n", this -> choc_longueur); 
  fprintf(out_stream, "\t" "choc_largeur  = %f" "\n", this -> choc_largeur); 
  fprintf(out_stream, "\t" "choc_hauteur  = %f" "\n", this -> choc_hauteur); 
  fprintf(out_stream, "\t" "masse         = %f" "\n", this -> masse); 
  fprintf(out_stream, "}; " "\n"); 

  fprintf(out_stream, " " "\n"); 

  fprintf(out_stream, "gameplay { " "\n"); 
  fprintf(out_stream, "\t" "vie        = %d" "\n", this -> vie); 
  fprintf(out_stream, "\t" "invincible = %d" "\n", this -> invincible); 
  fprintf(out_stream, "\t" "hostile    = %d" "\n", this -> hostile); 
  fprintf(out_stream, "}; " "\n"); 

  fprintf(out_stream, " " "\n"); 
  


  fprintf(out_stream, "graphique { " "\n"); 
  fprintf(out_stream, "\t" " " "\n"); 
  fprintf(out_stream, "\t" "racines[%d] =  " "\n", this -> racines_nb); 
  for (int i = 0; i < this -> racines_nb; i++) { 
    fprintf(out_stream, "\t" "\t" "{ qui = %s \t\t ; x := %f ; y := %f ; z := %f ; angle y := %f ;}," "\n", this -> racines_qui[i], this -> racines_x[i], this -> racines_y[i], this -> racines_z[i], this -> racines_angle_y[i]); 
  }; 
  fprintf(out_stream, "\t" "; " "\n"); 

  fprintf(out_stream, "\t" " " "\n"); 

  fprintf(out_stream, "\t" "membres[%d] =  " "\n", this -> membres_nb); 
  for (int i = 0; i < this -> membres_nb; i++) { 
    fprintf(out_stream, "\t" "\t" "{ nom = %s \t\t ; image := %s \t\t ; largeur := %f ; hauteur := %f ; angle y max := %f ;}," "\n", this -> membres_nom[i], this -> membres_image[i], this -> membres_largeur[i], this -> membres_hauteur[i], this -> membres_angle_max_y[i]); 
  }; 
  fprintf(out_stream, "\t" "; " "\n"); 

  fprintf(out_stream, "}; " "\n"); 

  fprintf(out_stream, " " "\n"); 

#endif 
  
  
}; 












#define SUFF_CARTE_OUT ".lexing.out"

//carte_t * carte__fill_from_file(carte_t * this, const char * filename, const char * log_filename) {  
int carte__fill_from_file(carte_t * this, const char * filename, const char * log_filename) {  
  if (filename == NULL) { carte_err("Erreur: impossible 'filename' est le pointeur NULL.\n"); return -1; }; 
  
  this -> filename = strcopy(filename); 
  
  // log file 
  if (NULL == log_filename) { 
    char carte_log[strlen(filename) + strlen(SUFF_CARTE_OUT) + 1];
    strcat(strcpy(carte_log, filename), SUFF_CARTE_OUT);
    message("On essaye d'ouvrir en écriture le fichier '%s'." "\n", carte_log);
    yycarteout = fopen(carte_log, "wb");
    if (yycarteout == NULL) {
      carte_err("Erreur: impossible d'ouvrir en écriture le fichier \"%s\".\n", carte_log);
      return -2;
    }; 
  } 
  else {
    message("On essaye d'ouvrir en écriture le fichier '%s'." "\n", log_filename);
    yycarteout = fopen(log_filename, "wb");
    if (yycarteout == NULL) {
      carte_err("Erreur: impossible d'ouvrir en écriture le fichier \"%s\".\n", log_filename);
      return -3;
    }; 
  };
  
  //yycartein
  FILE * entrin = NULL;
  { 
#if 0 
    char carte_fullpath[strlen(filename) + strlen(dir) + 1];
    carte_fullpath = strcat(strcpy(carte_fullpath, dir), filename);
#else 
    const char * carte_fullpath = filename; 
#endif 
    entrin = fopen(carte_fullpath, "rb");
    if (entrin == NULL) {
      carte_err("Erreur: impossible d'ouvrir en lecture le fichier \"%s\".\n", filename);
      (void) fclose(yycarteout);
      return -4;
    }; 
  }; 

  carte_restart_lexer();
  yycarterestart(entrin);
  carte_parser_reset();

  //* L'analyse elle-même. */
  int res; 
  yycarte_global_objet_being_filled_up_while_parsing = this; 
#if 1
  res = yycarteparse();
#else
  res = 0;
#endif

  fprintf(yycarteout, "\n" "\n"  "---------------------------------------"  "\n" "\n"); 

  //* On match. */
  switch (res) {
  case 0:  (void) fprintf(yycarteout, "Analyse réussie !!!\n"); break; 
  default: (void) fprintf(yycarteout, "Analyse ratée...\n"); break; 
  };

  if (0 == res) { 
    fprintf(yycarteout, "\n\n" "==============================================================================" "\n" "\n"); 
    carte__print(this, yycarteout);   
  }; 
  
  //* On ferme les flux. */
  (void) fclose(yycarteout); 
  (void) fclose(yycartein);
  
  
  return (0 == res) ? 0 : -5; 
};  





















#if 0 
#define CARTE_OUT_SUFFIXE ".lexing.out"

/* Valeur de retour.
   0 : OK
   < 0 : erreur
   -1 : filename est NULL
   -2 : impossible d'ouvrir en écriture le fichier de sortie.
   -3 : impossible d'ouvrir en lecture le fichier d'entrée.
   < -128 : erreur lors du parsing.
   regarder dans carte/carte.parse.y et chercher l'erreur (res + 128).
*/

//int CMap::parse(const char * filename) {
int CMap::parse(const char * dir, const char * filename) {
  int res;
  FILE *cartein;
  char *carte_out;
  size_t taille;

  message("On entre dans la fonction CMap::parse.");

  message("Teste si filename est NULL.");
  if (filename == NULL) {
    messerr("CMap::parse: filename est le pointeur NULL. On quitte.");
    return -1;
  }
  message("Test reussi.");


  //noncarte_out = strcat(strcpy(new char[strlen(filename) + strlen(SUFF_NONCARTEOUT) + 1], filename), SUFF_NONCARTEOUT);
  carte_out = STRCAT3_(LOGDIR,filename,CARTE_OUT_SUFFIXE);
#if 0
  carte_err("fout = %s\n", noncarte_out);
  yynoncarteout = fopen(noncarte_out, "wb");
  assert(yynoncarteout != NULL);
  assert(false);
#endif

#if 0
  message("On essaye de créer le fichier de sortie pour l'analyse.");
  (void) (taille = strlen(filename) + strlen(CARTE_OUT_SUFFIXE));
  (void) (carte_out = new char[taille + 1]);
  (void) strcat(strcpy(carte_out, filename), CARTE_OUT_SUFFIXE);
  message("Création du fichier \"%s\".", carte_out);
  message("On essaye de l'ouvrir en écriture.");
#endif

  (void) (yycarteout = fopen(carte_out, "wb"));
  if (yycarteout == NULL) {
    messerr("CMap::parse: impossible d'ouvrir en écriture le fichier \"%s\". On arrête l'analyse du fichier.", carte_out);
    delete[] carte_out;
    return -2;
  }
  carte_mess("Ouverture en écriture réussie du fichier \"%s\" !", carte_out);


  filename = STRCAT2_(dir, filename);
  carte_mess("On essaye d'ouvrir en lecture le fichier \"%s\".", filename);
  (void) (cartein = fopen(filename, "rb"));
  if (cartein == NULL) {
    carte_err("Impossible d'ouvrir en lecture le fichier \"%s\" ! On arrête l'analyse.", filename);
    (void) fclose(yycarteout);
    delete[] carte_out;
    return -3;
  }

  carte_mess("Ouverture en lecture du fichier \"%s\" réussie.", filename);
  carte_mess("Initialisation du lexer et parser.");
  carte_parser_reset();
  carte_restart_lexer();
  yycarterestart(cartein);
  carte = this;

  carte_mess("Démarrage de l'analyse.");

  (void) (res = yycarteparse());
  switch (res) {
  case 0: 
    carte_mess("Analyse réussie du fichier \"%s\".", filename);
    break;
  default:
    carte_err("Analyse raté du fichier \"%s\".", filename);
    res -= 128;
  }

  carte_mess("Fermeture des flots d'entrée et de sortie.");
  (void) fclose(cartein);
  (void) fclose(yycarteout);
  message("Flots fermés.");
  message("On quitte CMap::parse avec comme argument \"%s\".", filename);
  delete[] carte_out;
  return res;
  
}

#endif 
