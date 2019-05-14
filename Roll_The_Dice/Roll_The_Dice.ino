  #include "LedControl.h"

  LedControl lc = LedControl(12,10,11,1);
  
  const int ButtonPin = 2; // number of the button pin
  const int f = 9;
  const int g = 8;
  const int e = 7;
  const int d = 6;
  const int c = 5;
  const int b = 4;
  const int a = 3;

  int ButtonState = 0;
  int count[6] = {0, 0, 0, 0, 0, 0};

  const byte limpa[8] = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
  
  const byte sym_one[8] = {B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000};
  const byte sym_two[8] = {B00000000, B00000110, B00000110, B00000000, B00000000, B01100000, B01100000, B00000000};
  const byte sym_three[8] = {B00000000, B00000110, B00000110, B00011000, B00011000, B01100000, B01100000, B00000000};
  const byte sym_four[8] = {B00000000, B01100110, B01100110, B00000000, B00000000, B01100110, B01100110, B00000000};
  const byte sym_five[8] = {B00000000, B01100110, B01100110, B00011000, B00011000, B01100110, B01100110, B00000000};
  const byte sym_six[8] = {B00000000, B11011011, B11011011, B00000000, B00000000, B11011011, B11011011, B00000000};
  
  const byte num_one[8] = {B00000000, B00000000, B00000000, B00000001, B11111111, B01000001, B00000000, B00000000};
  const byte num_two[8] = {B00000000, B00000000, B01110001, B10001001, B10000101, B10000011, B01000001, B00000000};
  const byte num_three[8] = {B00000000, B00000000, B01101110, B10010001, B10010001, B10000001, B01000010, B00000000};
  const byte num_four[8] = {B00000000, B00000000, B11111111, B01000100, B00100100, B00010100, B00001100, B00000000};
  const byte num_five[8] = {B00000000, B00000000, B10001110, B10010001, B10010001, B10010001, B11110010, B00000000};
  const byte num_six[8] = {B00000000, B00000000, B01001110, B10010001, B10010001, B10010001, B01111110, B00000000};


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(ButtonPin, INPUT);

  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
  
  lc.shutdown(0,false);
  lc.setIntensity(0,10);
  lc.clearDisplay(0); 
}

void Turn_Led(int add, int x, int y, bool sign)
{
  lc.setLed(add, x, y, sign);
  delay(25);
}
void Shaking_Dice()
{
  /*int limit = 7;
  int xx, yy;
  for(int init = 0; init < 4; init++)
  {
    for(xx = init, yy = init; xx <= limit; xx++)
      Turn_Led(0, xx, yy, true);

    for(yy = init; yy <= limit; yy++)
      Turn_Led(0, xx, yy, true);

    for(xx = limit; xx >= init; xx--)
      Turn_Led(0, xx, yy, true);

    for(yy = limit; yy >= init; yy--)
      Turn_Led(0,xx, yy, true);

    limit--;
  }*/

  Turn_Led(0, 0, 0, true);
  Turn_Led(0, 1, 0, true);
  Turn_Led(0, 2, 0, true);
  Turn_Led(0, 3, 0, true);
  Turn_Led(0, 4, 0, true);
  Turn_Led(0, 5, 0, true);
  Turn_Led(0, 6, 0, true);
  Turn_Led(0, 7, 0, true);
  
  Turn_Led(0, 7, 1, true);
  Turn_Led(0, 7, 2, true);
  Turn_Led(0, 7, 3, true);
  Turn_Led(0, 7, 4, true);
  Turn_Led(0, 7, 5, true);
  Turn_Led(0, 7, 6, true);
  Turn_Led(0, 7, 7, true);
  
  Turn_Led(0, 6, 7, true);
  Turn_Led(0, 5, 7, true);
  Turn_Led(0, 4, 7, true);
  Turn_Led(0, 3, 7, true);
  Turn_Led(0, 2, 7, true);
  Turn_Led(0, 1, 7, true);
  Turn_Led(0, 0, 7, true);
  
  Turn_Led(0, 0, 6, true);
  Turn_Led(0, 0, 5, true);
  Turn_Led(0, 0, 4, true);
  Turn_Led(0, 0, 3, true);
  Turn_Led(0, 0, 2, true);
  Turn_Led(0, 0, 1, true);
  
  Turn_Led(0, 1, 1, true);
  Turn_Led(0, 2, 1, true);
  Turn_Led(0, 3, 1, true);
  Turn_Led(0, 4, 1, true);
  Turn_Led(0, 5, 1, true);
  Turn_Led(0, 6, 1, true);
  
  Turn_Led(0, 6, 2, true);
  Turn_Led(0, 6, 3, true);
  Turn_Led(0, 6, 4, true);
  Turn_Led(0, 6, 5, true);
  Turn_Led(0, 6, 6, true);
  
  Turn_Led(0, 5, 6, true);
  Turn_Led(0, 4, 6, true);
  Turn_Led(0, 3, 6, true);
  Turn_Led(0, 2, 6, true);
  Turn_Led(0, 1, 6, true);
  
  Turn_Led(0, 1, 5, true);
  Turn_Led(0, 1, 4, true);
  Turn_Led(0, 1, 3, true);
  Turn_Led(0, 1, 2, true);
  
  Turn_Led(0, 2, 2, true);
  Turn_Led(0, 3, 2, true);
  Turn_Led(0, 4, 2, true);
  Turn_Led(0, 5, 2, true);
  
  Turn_Led(0, 5, 3, true);
  Turn_Led(0, 5, 4, true);
  Turn_Led(0, 5, 5, true);
  
  Turn_Led(0, 4, 5, true);
  Turn_Led(0, 3, 5, true);
  Turn_Led(0, 2, 5, true);
  
  Turn_Led(0, 2, 4, true);
  Turn_Led(0, 2, 3, true);

  Turn_Led(0, 3, 3, true);
  Turn_Led(0, 4, 3, true);

  Turn_Led(0, 4, 4, true);
  Turn_Led(0, 3, 4, true);


  Turn_Led(0, 3, 4, false);
  Turn_Led(0, 4, 4, false);

  Turn_Led(0, 4, 3, false);
  Turn_Led(0, 3, 3, false);

  Turn_Led(0, 2, 3, false);
  Turn_Led(0, 2, 4, false);

  Turn_Led(0, 2, 5, false);
  Turn_Led(0, 3, 5, false);
  Turn_Led(0, 4, 5, false);

  Turn_Led(0, 5, 5, false);
  Turn_Led(0, 5, 4, false);
  Turn_Led(0, 5, 3, false);

  Turn_Led(0, 5, 2, false);
  Turn_Led(0, 4, 2, false);
  Turn_Led(0, 3, 2, false);
  Turn_Led(0, 2, 2, false);

  Turn_Led(0, 1, 2, false);
  Turn_Led(0, 1, 3, false);
  Turn_Led(0, 1, 4, false);
  Turn_Led(0, 1, 5, false);

  Turn_Led(0, 1, 6, false);
  Turn_Led(0, 2, 6, false);
  Turn_Led(0, 3, 6, false);
  Turn_Led(0, 4, 6, false);
  Turn_Led(0, 5, 6, false);

  Turn_Led(0, 6, 6, false);
  Turn_Led(0, 6, 5, false);
  Turn_Led(0, 6, 4, false);
  Turn_Led(0, 6, 3, false);
  Turn_Led(0, 6, 2, false);

  Turn_Led(0, 6, 1, false);
  Turn_Led(0, 5, 1, false);
  Turn_Led(0, 4, 1, false);
  Turn_Led(0, 3, 1, false);
  Turn_Led(0, 2, 1, false);
  Turn_Led(0, 1, 1, false);

  Turn_Led(0, 0, 1, false);
  Turn_Led(0, 0, 2, false);
  Turn_Led(0, 0, 3, false);
  Turn_Led(0, 0, 4, false);
  Turn_Led(0, 0, 5, false);
  Turn_Led(0, 0, 6, false);

  Turn_Led(0, 0, 7, false);
  Turn_Led(0, 1, 7, false);
  Turn_Led(0, 2, 7, false);
  Turn_Led(0, 3, 7, false);
  Turn_Led(0, 4, 7, false);
  Turn_Led(0, 5, 7, false);
  Turn_Led(0, 6, 7, false);

  Turn_Led(0, 7, 7, false);
  Turn_Led(0, 7, 6, false);
  Turn_Led(0, 7, 5, false);
  Turn_Led(0, 7, 4, false);
  Turn_Led(0, 7, 3, false);
  Turn_Led(0, 7, 2, false);
  Turn_Led(0, 7, 1, false);

  Turn_Led(0, 7, 0, false);
  Turn_Led(0, 6, 0, false);
  Turn_Led(0, 5, 0, false);
  Turn_Led(0, 4, 0, false);
  Turn_Led(0, 3, 0, false);
  Turn_Led(0, 2, 0, false);
  Turn_Led(0, 1, 0, false);
  Turn_Led(0, 0, 0, false); 
}

void Update_7Seg()
{
  int aux = -1;
  int maxi = 0;

  for(int i = 0; i < 6; i++)
  {
    if(count[i] > maxi)
    {
      aux = i;
      maxi = count [aux];     
    }
  }
  if(aux == -1)
    return;

  switch (aux)
  {
    case 0:
      Show_1S();
    break;

    case 1:
      Show_2S();
    break;

    case 2:
      Show_3S();
    break;

    case 3:
      Show_4S();
    break;

    case 4:
      Show_5S();
    break;

    case 5:
      Show_6S();
    break;
  }

  
}

void Show_1S()
{
  digitalWrite(a,0); 
  digitalWrite(b,1);  
  digitalWrite(c,1);  
  digitalWrite(d,0);  
  digitalWrite(e,0);  
  digitalWrite(f,0);  
  digitalWrite(g,0);
}

void Show_2S()
{
  digitalWrite(a,1); 
  digitalWrite(b,1);  
  digitalWrite(c,0);  
  digitalWrite(d,1);  
  digitalWrite(e,1);  
  digitalWrite(f,0);  
  digitalWrite(g,1);
}

void Show_3S()
{
   digitalWrite(a,1); 
  digitalWrite(b,1);  
  digitalWrite(c,1);  
  digitalWrite(d,1);  
  digitalWrite(e,0);  
  digitalWrite(f,0);  
  digitalWrite(g,1);
}

void Show_4S()
{
  digitalWrite(a,0); 
  digitalWrite(b,1);  
  digitalWrite(c,1);  
  digitalWrite(d,0);  
  digitalWrite(e,0);  
  digitalWrite(f,1);  
  digitalWrite(g,1);
}

void Show_5S()
{
  digitalWrite(a,1); 
  digitalWrite(b,0);  
  digitalWrite(c,1);  
  digitalWrite(d,1);  
  digitalWrite(e,0);  
  digitalWrite(f,1);  
  digitalWrite(g,1);
}

void Show_6S()
{
  digitalWrite(a,0); 
  digitalWrite(b,0);  
  digitalWrite(c,1);  
  digitalWrite(d,1);  
  digitalWrite(e,1);  
  digitalWrite(f,1);  
  digitalWrite(g,1); 
}


void Clear_Matrix()
{
  Render(limpa);
}

void Render(byte * num)
{
  for(int i = 0; i < 8; i ++)
  {
    lc.setRow(0, i, num[i]);
  }
}

void Show_Result(int num)
{
  switch (num)
  {
    case 1:
      show_one();
    break;

    case 2:
      show_two();
    break;

    case 3:
      show_three();
    break;

    case 4:
      show_four();
    break;

    case 5:
      show_five();
    break;

    case 6:
      show_six();
    break;
  }
}

void show_one()
{
  ButtonState = digitalRead(ButtonPin);
  Update_7Seg();
  while(ButtonState == LOW)
  {
    Render(sym_one);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
    if(ButtonState == HIGH)
      break;
    Render(num_one);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
  }
}

void show_two()
{
  ButtonState = digitalRead(ButtonPin);
  Update_7Seg();
  while(ButtonState == LOW)
  {
    Render(sym_two);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
    if(ButtonState == HIGH)
      break;
    Render(num_two);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
  }
}

void show_three()
{
  ButtonState = digitalRead(ButtonPin);
  Update_7Seg();
  while(ButtonState == LOW)
  {
    Render(sym_three);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
    if(ButtonState == HIGH)
      break;
    Render(num_three);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
  }
}

void show_four()
{
  ButtonState = digitalRead(ButtonPin);
  Update_7Seg();
  while(ButtonState == LOW)
  {
    Render(sym_four);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
    if(ButtonState == HIGH)
      break;
    Render(num_four);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
  }
}

void show_five()
{
  ButtonState = digitalRead(ButtonPin);
  Update_7Seg();
  while(ButtonState == LOW)
  {
    Render(sym_five);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
    if(ButtonState == HIGH)
      break;
    Render(num_five);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
  }
}

void show_six()
{
  ButtonState = digitalRead(ButtonPin);
  Update_7Seg();
  while(ButtonState == LOW)
  {
    Render(sym_six);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
    if(ButtonState == HIGH)
      break;
    Render(num_six);
    delay(1000);
    ButtonState = digitalRead(ButtonPin);
  }
}

int Gen_rand()
{
  return random(1, 7);
}

void loop() {
  ButtonState = digitalRead(ButtonPin);
  
  
  if(ButtonState == HIGH)
  {
    int num = Gen_rand();
    Serial.println(num);
    count[num - 1] ++;
    for(int i = 0; i < 6; i++)
      Serial.println(count[i]);

    Serial.println();
    Clear_Matrix();
    Shaking_Dice();
    Show_Result(num);
  }
}
