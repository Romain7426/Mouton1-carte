#ifndef CARTE_H
#define CARTE_H



enum { carte_teleportation_size = 15 }; 
enum { carte_events_size = 15 }; 
enum { carte_texture_size = 15 }; 
enum { carte_objet_size = 2048 }; 
enum { carte_membres_size = 15 }; 
enum { carte_racines_size = carte_membres_size }; 

enum { CARTE_DESC_DIRECTION_GAUCHE, CARTE_DESC_DIRECTION_DROITE, CARTE_DESC_DIRECTION_DOS, CARTE_DESC_DIRECTION_FACE }; 
struct carte_t; 
typedef struct carte_t carte_t; 
struct carte_t {
  char * filename; 
  
  //physique;
  // NOTHING 
  
  //carte_tgameplay gameplay; 
  int lattice_width; 
  int lattice_height; 
  int over_spanning_w; 
  int over_spanning_h; 
  int         arme; 
  char *   musique; 
  float niveau_eau; 
  int      vie_eau; 

  char * teleportation_nom[carte_teleportation_size];
  char * teleportation_destination[carte_teleportation_size];
  float teleportation_x[carte_teleportation_size];
  float teleportation_y[carte_teleportation_size];
  float teleportation_z[carte_teleportation_size];
  float teleportation_longueur[carte_teleportation_size];
  float teleportation_largeur[carte_teleportation_size];
  float teleportation_hauteur[carte_teleportation_size];
  int teleportation_direction[carte_teleportation_size];
  float teleportation_destination_x[carte_teleportation_size];
  float teleportation_destination_y[carte_teleportation_size];
  float teleportation_destination_z[carte_teleportation_size];
  int teleportation_destination_direction[carte_teleportation_size];
  int teleportation_nb;

  char * events_nom[carte_events_size]; 
  int events_genere[carte_events_size]; 
  char * events_gestion_fichier[carte_events_size]; 
  char * events_gestion_proc[carte_events_size]; 
  int events_nb;

  // -- Graphique -- 
  char * fichier_de_zone_de_niveau; 
  char * fichier_de_zone_de_texture; 
  
  char * texture_nom[carte_texture_size];
  char * texture_image[carte_texture_size];
  int texture_indice[carte_texture_size];
  int texture_nb;
  
  char * objet_nom[carte_objet_size]; 
  int objet_anime_huh[carte_objet_size]; 
  char * objet_fichier[carte_objet_size]; 
  float objet_x[carte_objet_size]; 
  float objet_y[carte_objet_size]; 
  float objet_z[carte_objet_size]; 
  float objet_angle_x[carte_objet_size]; 
  float objet_angle_y[carte_objet_size]; 
  float objet_angle_z[carte_objet_size]; 
  int objet_nb; 
  
  
  
  const char * temp_code_fichier; 
  const char * temp_code_proc; 
  
  int temp_events_genere_type;
  const char * temp_events_genere_code_fichier;
  const char * temp_events_genere_code_proc; 

  const char * temp_events_par_code_fichier; 
  const char * temp_events_par_code_proc; 
  
  const char * temp_events_traitement_code_fichier; 
  const char * temp_events_traitement_code_proc; 
};

extern carte_t * carte_make           (void);  
extern void      carte_delete         (carte_t * this);  
extern carte_t * carte_make_from_file (const char * filename, const char * log_filename);  
extern int       carte__fill_from_file(carte_t * this, const char * filename, const char * log_filename);  

extern void carte__teleportation_push(carte_t * this, const char * nom, const char * destination, const float x, const float y, const float z, const float longueur, const float largeur, const float hauteur, const int direction, const float dest_x, const float dest_y, const float dest_z, const int dest_direction); 
extern void carte__events_push (carte_t * this, const char * nom, const int genere_id, const char * gestion_fichier, const char * genere_proc);  
extern void carte__texture_push(carte_t * this, const char * nom, const char *  image, const int indice);  
extern void carte__objet_push  (carte_t * this, const char * nom, const int anime_huh, const char * fichier, const float x, const float y, const float z, const float angle_x, const float angle_y, const float angle_z); 







#endif /* CARTE_H */
