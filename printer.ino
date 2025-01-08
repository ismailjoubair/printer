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
}

void loop() {
  // Mouvement de l'axe X dans une direction
  digitalWrite(DIR_X, HIGH); // Définir la direction
  for (int i = 0; i < 200; i++) { // 200 pas (1 tour complet pour un moteur 1.8°/pas)
    digitalWrite(STEP_X, HIGH);
    delayMicroseconds(800); // Ajuster pour la vitesse
    digitalWrite(STEP_X, LOW);
    delayMicroseconds(800);
  }
  delay(1000); // Pause de 1 seconde

  // Mouvement de l'axe Y dans l'autre direction
  digitalWrite(DIR_Y, LOW); // Définir la direction
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_Y, HIGH);
    delayMicroseconds(800);
    digitalWrite(STEP_Y, LOW);
    delayMicroseconds(800);
  }
  delay(1000); // Pause de 1 seconde

  // Mouvement de l'axe Z dans une direction
  digitalWrite(DIR_Z, HIGH); // Définir la direction
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_Z, HIGH);
    delayMicroseconds(800);
    digitalWrite(STEP_Z, LOW);
    delayMicroseconds(800);
  }
  delay(1000); // Pause de 1 seconde
}
