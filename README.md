# printer
code arduino pour un printer 3d qui command 3 moteurs
# README - Contrôle de moteurs pas à pas avec Arduino

## Description
Ce programme permet de contrôler trois moteurs pas à pas (X, Y, Z) à l'aide d'une carte Arduino. Chaque moteur est commandé par une paire de broches : une pour l'impulsion (STEP) et une pour la direction (DIR).

Le programme effectue les opérations suivantes :
1. Mouvement de l'axe X dans une direction (200 pas, soit un tour complet pour un moteur de 1,8°/pas).
2. Mouvement de l'axe Y dans la direction opposée (200 pas).
3. Mouvement de l'axe Z dans une direction (200 pas).

Chaque mouvement est suivi d'une pause d'une seconde.

## Matériel requis
- Une carte Arduino (UNO, Mega ou autre compatible).
- Trois moteurs pas à pas.
- Trois drivers pour moteurs pas à pas (ex : A4988, DRV8825 ou similaires).
- Une alimentation externe pour les moteurs (si nécessaire).
- Câbles de connexion.

## Schéma de connexion
Pour chaque moteur pas à pas :
1. Connectez les broches STEP et DIR du driver à l'Arduino selon la configuration suivante :
   - **Axe X** :
     - STEP : Pin 2
     - DIR : Pin 3
   - **Axe Y** :
     - STEP : Pin 4
     - DIR : Pin 5
   - **Axe Z** :
     - STEP : Pin 6
     - DIR : Pin 7
2. Connectez les bornes de puissance du driver (VCC, GND, moteurs) selon les spécifications du driver et des moteurs.
3. Assurez-vous que l'alimentation externe des moteurs correspond à leurs besoins.

## Instructions pour l'utilisation
1. **Configuration** :
   - Chargez le programme sur votre carte Arduino en utilisant l'IDE Arduino.
   - Assurez-vous que toutes les connexions sont correctes.

2. **Exécution** :
   - Une fois le programme téléversé et la carte connectée, le programme exécutera en boucle les mouvements définis pour chaque axe.

3. **Ajustements** :
   - **Vitesse** : Modifiez les délais dans les fonctions `delayMicroseconds(800)` pour régler la vitesse des moteurs.
   - **Nombre de pas** : Ajustez la valeur de la boucle `for (int i = 0; i < 200; i++)` pour contrôler le nombre de pas effectués.

## Exemple de sortie
- L'axe X effectue un tour complet dans une direction.
- L'axe Y effectue un tour complet dans la direction opposée.
- L'axe Z effectue un tour complet dans une direction.
- Les mouvements sont répétés en boucle avec des pauses d'une seconde entre chaque mouvement.

## Remarques
- Assurez-vous de ne pas dépasser les limites de courant de vos drivers de moteur pas à pas.
- Si les moteurs vibrent ou ne tournent pas correctement, vérifiez les connexions et la configuration des drivers.
- Vous pouvez utiliser une bibliothèque comme "AccelStepper" pour des contrôles plus avancés.

## Auteur
Ce programme a été conçu comme exemple pour le contrôle de moteurs pas à pas avec Arduino.

## Licence
Ce code est fourni sous licence MIT. Vous êtes libre de l'utiliser, de le modifier et de le redistribuer.

