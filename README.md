# ft_p
Network &amp; system administration, Unix

note finale :
92 / 100

Ce projet consiste à faire un client et un serveur FTP (File Transfert Protocol) qui
permettent d’envoyer et recevoir des fichiers entre un ou plusieurs clients et le serveur.
Vous êtes néammoins libre du choix du protocole à utiliser (vous n’êtes pas obligé
de respecter les RFC définissant FTP, vous pouvez inventer votre propre protocole de
transfert de fichier). Vous devrez par contre quelque soit votre choix absolument obtenir
une cohérence entre votre client et votre serveur. Ils doivent communiquer correctement
ensemble.
La communication entre le client et le serveur se fera en TCP/IP (v4).

Le serveur doit supporter plusieurs clients simultanément par l’intermédiaire d’un fork.
Si vous êtes très à l’aise avec select(2), vous pouvez l’utiliser. Néammoins vous aurez
l’occasion de l’utiliser pour le projet irc, donc profitez de ce projet pour apprendre à faire
un serveur qui fork.
Si vous utilisez select(2), faites les choses correctement jusqu’au bout :
• select(2) en lecture + écriture (vous ne comprenez pas ? utilisez fork(2))
• serveur absolument non bloquant (vous ne comprenez pas ? utilisez fork(2)).
Si votre serveur est mal conçu parce que vous avez voulu utiliser select(2) au lieu de
fork(2), vous perdrez beaucoup de points en soutenance.

Le client doit comprendre les commandes suivantes :
• ls : liste le répertoire courant du serveur
• cd : change le répertoire courant du serveur
• get _file_ : récupère le fichier _file_ du serveur vers le client
• put _file_ : envoi le fichier _file_ du client vers le serveur
• pwd : affiche le chemin du répertoire courant sur le serveur
• quit : coupe la connection + sort du programme
et répondre aux exigences ci-dessous :
• Un prompt spécifique au client (pour le distinguer du Shell)
• Impossibilité de descendre à un niveau inférieur au répertoire d’exécution du serveur
(à moins qu’un paramètre spécifié au serveur indique un autre répertoire de
départ)
• affichage sur le client des messages SUCCESS ou ERROR + explication après
chaque requête.
