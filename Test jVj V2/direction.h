

typedef enum { NORD, NORDEST, EST, SUDEST, SUD, SUDOUEST, OUEST, NORDOUEST } t_direction;
const int NB_DIRECTION=8;

int direction_avancer(int i, int j, t_direction dir, int nb_pas, int *ni, int*nj);

t_direction direction_suivante(t_direction dir);

t_direction direction_debut(){ return NORD;}

