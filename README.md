# TP2 - Structures de Données : Listes Chaînées

 📋 Description du Projet
Ce projet implémente un programme modulaire en C démontrant les opérations fondamentales sur différentes variantes de listes chaînées. Il sert de référence pour comprendre la manipulation avancée des structures de données linéaires.

 🏗️ Architecture Modulaire

 Fichiers Source
- tp2.h : En-tête contenant les déclarations des structures de données et les prototypes des fonctions
- tp2.c : Implémentation complète des algorithmes de manipulation des listes
- main.c : Programme principal avec menu interactif pour tester toutes les fonctionnalités

 🔧 Fonctionnalités Détaillées

 1. Suppression Complète d'Élément
- Lecture d'un élément depuis l'entrée standard
- Parcours exhaustif de la liste
- Suppression systématique de toutes les occurrences
- Gestion mémoire : libération propre des nœuds supprimés

 2. Insertion Triée - Liste Simplement Chaînée
- Parcours séquentiel jusqu'à trouver la position d'insertion
- Maintenance de l'ordre croissant/décroissant
- Optimisation : insertion en O(n) avec gestion des cas particuliers (tête, queue, liste vide)

 3. Insertion Triée - Liste Doublement Chaînée  
- Navigation bidirectionnelle pour une insertion optimisée
- Mise à jour coordonnée des pointeurs prev et next
- Avantage : possibilité de parcours dans les deux sens

 4. Insertions Circulaires - Liste Simple
- Insertion en tête : 
  - Création du nouveau nœud
  - Redirection du dernier pointeur vers la nouvelle tête
  - Maintien de la circularité
- Insertion en queue :
  - Parcours jusqu'au dernier élément
  - Établissement des liens circulaires

 5. Insertions Circulaires - Liste Double
- Insertion en tête :
  - Gestion des pointeurs prev et next circulaires
  - Mise à jour du précédent de l'ancienne tête
- Insertion en queue :
  - Coordination avec la tête pour maintenir la circularité
  - Optimisation grâce à la double liaison

 🚀 Compilation et Exécution

# Compilation avec tous les warnings activés
gcc -Wall -Wextra -std=c99 -o tp2 main.c tp2.c

# Exécution du programme
./tp2

 💻 Utilisation
Le programme propose un menu interactif permettant de :
1. Choisir le type de liste à manipuler
2. Effectuer les opérations spécifiques à chaque structure
3. Visualiser l'état des listes après chaque opération
4. Tester les cas limites (liste vide, un seul élément, etc.)

 🎯 Objectifs Pédagogiques
- Maîtrise des pointeurs et allocation mémoire en C
- Compréhension approfondie des structures chaînées
- Gestion des cas particuliers en programmation système
- Développement modulaire et maintenable

 📝 Notes Techniques
Toutes les fonctions incluent une gestion d'erreur robuste et une optimisation des performances. Le code respecte les bonnes pratiques de programmation en C.
