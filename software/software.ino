int value;     // Variable pour stocker le signal ppm recu
bool state = false;   // Stocke l'état de l'electro aimant (alimenté ou non)
int threshold = 1500;

int pinElectroAimant = 0;
int pinRecepteur = 2;

void aimanter(bool activer);
int mesureRecepteur(void);

void setup() {
  // put your setup code here, to run once:
  pinMode(pinElectroAimant, OUTPUT);
  pinMode(pinRecepteur, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = mesureRecepteur();

  if (value > threshold)
  {
    aimanter(true);
  }
  else
  {
    aimanter(false);
  }

  delay(10);
}


void aimanter(bool activer)
{
  if (activer && !state)
  {
    digitalWrite(pinElectroAimant, HIGH);
    state = true;
  }
  if (!activer && state)
  {
    digitalWrite(pinElectroAimant, LOW);
    state = false;
  }
}

int mesureRecepteur(void)
{
  return pulseIn(pinRecepteur, HIGH);
}

