

#define GEAR_IN_PIN PIN_PA0
#define D1_PIN PIN_PA1
#define D2_PIN PIN_PA2
#define D3_PIN PIN_PA3
#define D4_PIN PIN_PA4
#define D5_PIN PIN_PA5
#define D6_PIN PIN_PA6
#define RPM_IN_PIN PIN_PA7
// 0 0.8 1.7 2.5 3.3 4.1

uint16_t GearDetectionTable[6] = {930, 757, 593, 429, 255, 81};


void setup() {
  // put your setup code here, to run once:
  pinMode(GEAR_IN_PIN, INPUT);
  pinMode(RPM_IN_PIN, INPUT);
  pinMode(D1_PIN, OUTPUT);
  pinMode(D2_PIN, OUTPUT);
  pinMode(D3_PIN, OUTPUT);
  pinMode(D4_PIN, OUTPUT);
  pinMode(D5_PIN, OUTPUT);
  pinMode(D6_PIN, OUTPUT);
  for (int i = 0; i < 2; i++)
  {
    for (int index = 1; index < 7; index++)
    {
      PORTA = (0x80 >> index) & 0x7e;
      delay(50);
    }
    for (int index = 1; index < 7; index++)
    {
      PORTA = (0x01 << index) & 0x7e;
      delay(50);
    }
  }
}

void loop()
{
  uint8_t currentgear = getGear(analogRead(GEAR_IN_PIN));
  if ( currentgear >= 0 && currentgear <= 6)
  {
    PORTA = (0x80 >> getGear(analogRead(GEAR_IN_PIN))) & 0x7e;
  }
  else PORTA = 0;
  delay(10);
}

uint8_t getGear(uint16_t analogValue)
{
  if (analogValue > GearDetectionTable[0]) return 0;

  for (int i = 1; i < 6; i++)
  {
    if ( analogValue > GearDetectionTable[i]) return 7 - i;
  }
  return 1;
}
