# *Problèmes rencontrés et leurs résolutions*

Après avoir tester la fonction ```functionClef``` permettant de récupérer la clef de hachage d'un point qui été calculé à partir de ses coordonnées, pour de très grandes valeurs de coordonnées, la clef retournait parfois une valeur négative car selon le type (int,double,long...), chaque type n'ont pas la même garantie de données, et donc une plage de valeurs différente. On décide donc de prendre le type primitif ```long long``` pour laquelle il y a une garantie de données de 64 bits.
Après avoir fixer ce problème, on remarque finalement que la reconstitution du réseau par table de hachage est plus performante que l'arbre quaternaire, ce qui est théoriquement exact car les recherches et insertions sont en O(1), tandis que les arbres sont en O(logn).

# *Modifications apportées aux SDD*

Pour la SDD de table de hachage, nous avons décider de créer une sous-structure ```NodeHachage``` pour avoir une composition uniforme. 
Nous nous sommes permis de modifier la SDD du Graphe, dans la structure ```cellule_arete```, finalement elle pointe vers deux ```cellule_arete``` : ```usuiv``` et ```vsuiv```.

