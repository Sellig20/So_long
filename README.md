# So_long 

`100%`

Projet n.6 a 42 Paris.
Utilisation de la minilibx-linux (a renommer pour compiler avec le makefile) pour creer un jeu en 2d.
Liste chainee pour le parsing, char** pour travailler x et y en abscisse et ordonnee. 
Il faut convertir les images choisies en xpm, grace aux fonctions de la mlx.  

Dans mon .h il y a une FONCTION CONSTANTE GLOBALE (pas une variable globale, formellement interdite a 42). Il s'agit d'une lookup table, qui me permet d'eviter une foret de if pour afficher ma map (if (str[i] == '1' -> wall), if (str[i] == 'C' -> collectible)... Je cree donc une enum structure, qui comprend des variables de type void * et qui definissent mes differentes textures a appliquer a ma map. La lookup est tres pratique dans ce sens ou elle enumere dans mon .h directement (tout est CONSTANT a la compilation != variable globale) toutes mes variables necessaires a la creation graphique de ma map (wall, character, ground, exit, collectible). Ma g_lookup est de type t_key_value : c'est en fait une structure qui contient pour chaque ligne ce dont j'ai besoin, a savoir mon str[i] egale aux lettres/chiffres de ma map, mon void * relie, et le decalage en x et y a appliquer une fois que je les propulse sur ma map. Je dois diviser par 2 mon exit puisque c'est ma seule texture qui fait 128 par 64, sinon toutes les autres font 128 par 128.

Pour comprendre comment fonctionne la mlx : cette bibliotheque graphique contient deja toutes les fonctions necessaires pour creer une map. *mlx_xpm_file_to_image* convertit mes images en xpm, *mlx_put_image_to_window* affiche mon image choisie sur l'ecran, *mlx_init* et *mlx_new_window* me creent ma fenetre pour jouer, *mlx_hook* sert a pointer une action de la souris pour quitter la fenetre par ex... sans oublier toutes les fonctions qui permettent de free ou quitter proprement le programme : *mlx_destroy_display*, *mlx_clear_window* ...Au fur et a mesure que mes iimages apparaissent, elles doivent s'ecarter les unes des autres de 128 pixels, ce pq chaque pos[X] et pos[Y] prend 128 int : le decalage doit etre parfait. 

Reste donc a coder les differentes conversion des images en xpm, les touches WASD qui correspondent a telle action sur l'ecran de jeu, la structure du player et ce dernier qui doit bien s deplacer en abscisse et ordonne correspondantes aux touches.

C'est un peu eparpille mais j'ai fait mon parsing en liste chainee, et pour le reste je travaille avec un double tableau de char, bien plus pratique pour manipuler x et y, respectivement abscisse et ordonne.
