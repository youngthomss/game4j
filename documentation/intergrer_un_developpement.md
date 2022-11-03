On définit deux rôles :
- A (Assignee) : qui est la ou le port·euse·eur de la mise à jour et qui est en charge
de la défendre devant les reviewers ;
- R (Reviewer) :  qui emet des commentaires techniques sur
la qualité du code : suit les conventions de style du projet, passe les tests et
est maintenable. 

Le flow est le suivant :

1. A commit du code dans une nouvelle branche.
2. Le premier message de commit doit commencer par la mention [WIP] dans
3. le cas où la branche n'est pas prête à être passée en revue.
4. A pousse la branche sur le dépôt.
5. A crée une merge request (MR) pour cette branche en s'assignant le rôle assignee.
6. Cela est une manière d'annoncer le travail en cours auprès des autres développ·euse·eur·s.
7. A marque le MR comme ready quand celle-ci est prête et assigne un·e ou plusieur·e·s
reviewer(s).
8. R passe en revue (voir l'exemple de processus ci-dessous) et
fait des commentaires (thread).
9. A merge (sans squash) le code quand les conditions suivantes sont remplies :

    - tous les threads ont trouvé une réponse et ont été clos ;
    - la branche a été rebase sur main ;
    - il n'y a aucun conflit ; et
    -le pipeline de la CI est passé.



Un exemple de processus de revue :

1. git checkout en local
2. tester la nouvelle fonctionnalité
3. lire le code
4. poser des questions sur la MR (thread)
5. approuver le MR
