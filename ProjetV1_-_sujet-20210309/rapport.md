# **Rapport Projet : Réorganisation d'un réseau de fibres optiques**

## **Comparaison des trois structure**

Les trois structures sont la liste chaînée, la table de hachage et l'arbre quartenaire.
Rappel des paramètres à prendre en compte : Une chaîne est crée aléatoirement pour tester la reconstitution du réseau selon la structure. Une chaine est composée d'un ensemble de chaînes constitué de 100 points (dont les coordonnées (x,y) sont généré aléatoirement entre 0 et 5000) par chaîne.

### **Liste chaînée**

![chaine](time_list.svg)

Ce graphe nous révèle donc bien que la liste chaînée avec une quantité de données très volumineuse est beaucoup trop coûteuse en temps. Plus le nombre de chaîne augmente, et plus la reconstitution du réseau est conséquente en temps.

### **Table de hachage et Arbre quartenaire**

![chaine](time_hash_arbre.svg)

