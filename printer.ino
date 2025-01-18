// Définition des broches pour chaque axe
#define STEP_X 2     // Broche de l'impulsion pour l'axe X
#define DIR_X 3      // Direction pour l'axe X

#define STEP_Y 4     // Broche de l'impulsion pour l'axe Y
#define DIR_Y 5      // Direction pour l'axe Y

#define STEP_Z 6     // Broche de l'impulsion pour l'axe Z
#define DIR_Z 7      // Direction pour l'axe Z

void setup() {
  // Configuration des broches en sortie
  pinMode(STEP_X, OUTPUT);
  pinMode(DIR_X, OUTPUT);
  pinMode(STEP_Y, OUTPUT);
  pinMode(DIR_Y, OUTPUT);
  pinMode(STEP_Z, OUTPUT);
  pinMode(DIR_Z, OUTPUT);

  // Initialisation de la communication série
  Serial.begin(115200); // Assurez-vous que le baud rate correspond à celui configuré dans UGS
}

void loop() {
  // Vérifiez si des données sont disponibles sur le port série
  if (Serial.available() > 0) {
    // Lire la commande envoyée par UGS
    String command = Serial.readStringUntil('\n');
    command.trim(); // Retirer les espaces ou caractères inutiles

    // Analyse de la commande G-code
    if (command.startsWith("G00") || command.startsWith("G01")) {
      // Mouvement linéaire (G00 pour rapide, G01 pour précis)
      processMoveCommand(command);
    }
  }
}

// Fonction pour traiter une commande G-code
void processMoveCommand(String command) {
  float targetX = 0, targetY = 0, targetZ = 0;
  int feedrate = 0;

  // Extraire les valeurs des axes et du feedrate
  if (command.indexOf('X') != -1) targetX = extractValue(command, 'X');
  if (command.indexOf('Y') != -1) targetY = extractValue(command, 'Y');
  if (command.indexOf('Z') != -1) targetZ = extractValue(command, 'Z');
  if (command.indexOf('F') != -1) feedrate = extractValue(command, 'F');

  // Convertir feedrate en délai entre impulsions
  int delayMicrosecondsPerStep = feedrate > 0 ? (60000 / feedrate) : 800;

  // Effectuer les déplacements des moteurs
  moveAxis(STEP_X, DIR_X, targetX, delayMicrosecondsPerStep);
  moveAxis(STEP_Y, DIR_Y, targetY, delayMicrosecondsPerStep);
  moveAxis(STEP_Z, DIR_Z, targetZ, delayMicrosecondsPerStep);
}

// Fonction pour extraire une valeur après un caractère spécifique (X, Y, Z, F)
float extractValue(String command, char key) {
  int index = command.indexOf(key);
  if (index == -1) return 0;
  int spaceIndex = command.indexOf(' ', index);
  if (spaceIndex == -1) spaceIndex = command.length();
  return command.substring(index + 1, spaceIndex).toFloat();
}

// Fonction pour déplacer un axe donné
void moveAxis(int stepPin, int dirPin, float targetSteps, int delayMicrosecondsPerStep) {
  if (targetSteps > 0) {
    digitalWrite(dirPin, HIGH); // Définir la direction
  } else {
    digitalWrite(dirPin, LOW);  // Inverser la direction
    targetSteps = -targetSteps; // Convertir les pas en positif
  }

  for (int i = 0; i < targetSteps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delayMicrosecondsPerStep);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delayMicrosecondsPerStep);
  }
}
