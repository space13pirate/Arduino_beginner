/*
  PROJECT: https://wokwi.com/projects/379436329013013505
  AUTHOR:  Anastasia Cheremisova
  https://github.com/space13pirate
*/

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

/*
  Eng: Define constants for notes that are used to specify the frequency of each note on the piezoelectric buzzer.
  Here, all the semitones from low B0 to high D8 are represented.
  Each constant defines the frequency (in hertz) of the corresponding note.

  Рус: Определяем константы для нот, которые используются для задания частоты звучания каждой ноты на пьезоизлучателе.
  Здесь представлены все полутона от низких B0 до высоких D8.
  Каждая константа определяет частоту (в герцах) соответствующей ноты.
*/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


// 1) jingle bells

/*
  Eng: Define an array 'melody1' representing the sequence of notes for "jingle bells".
  Рус: Определяем массив 'melody1', представляющий последовательность нот для "Jingle Bells".
*/
int melody1[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

/*
  Eng: Calculate the length of the 'melody1' array by dividing the total size by the size of one element.
  Рус: Рассчитываем длину массива 'melody1', разделив общий размер на размер одного элемента.
*/
int melodyLength1 = sizeof(melody1) / sizeof(melody1[0]);

/*
  Eng: Define an array 'noteDurations1' representing the duration of each note in 'melody1'.
  Рус: Определяем массив 'noteDurations1', представляющий длительность каждой ноты в 'melody1'.
*/
int noteDurations1[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};


// 2) Calm Melody

int melody2[] = {
  NOTE_E5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_G4,
  NOTE_A4, NOTE_C5, NOTE_C5, NOTE_B4,

  NOTE_E5, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_G4,
  NOTE_A4, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_G4,
  NOTE_A4, NOTE_C5, NOTE_C5, NOTE_B4
};

int melodyLength2 = sizeof(melody2) / sizeof(melody2[0]);

int noteDurations2[] = {
  2, 8, 8, 8, 8, 2, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 4, 2,

  8, 8, 4, 2, 8, 8, 4, 2, 8, 8, 4, 2, 8, 8, 4, 2, 8, 8, 4, 2, 8, 8, 4, 2, 8, 8, 4, 2, 8, 8, 4, 2
};


const int buzzerPin = 13;  // The pin to which the piezoelectric buzzer is connected (Пин, к которому подключен пьезоизлучатель)
const int buttonPin = 8;   // The pin to which the button is connected (Пин, к которому подключена кнопка)

int selectedMelody = 1; // A variable to select the melody, the initial value is 1 (Переменная для выбора мелодии, начальное значение - 1)



// Initializing LCD with address 0x27 and size 16x2 characters (Инициализация LCD с адресом 0x27 и размером 16x2 символа)
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo1;
Servo servo2;

// Keypad setup (Настройка клавиатуры)
const byte KEYPAD_ROWS = 4; // Number of rows (Количество строк)
const byte KEYPAD_COLS = 4; // Number of columns (Количество столбцов)

// Defining the keyboard layout (Определение раскладки клавиатуры)
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2};     // Pins connected to keyboard rows (Пины, подключенные к строкам клавиатуры)
byte colPins[KEYPAD_COLS] = {A3, A2, A1, A0}; // Pins connected to keyboard columns (Пины, подключенные к столбцам клавиатуры)

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS); // Initializing the keyboard (Инициализация клавиатуры)

const int codeLength = 4; // Access code length (Длина кода досутпа)
char accessCode[codeLength] = "0000"; // Setting the initial access code (Установка начального кода доступа)


/*
  Eng: Welcome message on the LCD display when starting the program
  Рус: Приветственное сообщение на LCD-дисплее при запуске программы
*/
void showStartupMessage() {
  lcd.setCursor(3, 0); // Setting the cursor position on the first row (Установка позиции курсора на первой строке)
  lcd.print("Welcome to");
  delay(1000);

  lcd.setCursor(1, 1);
  String message = "the Smart Home";
  // Gradual message output (Постепенный вывод сообщения)
  for (byte i = 0; i < message.length(); i++) {
    lcd.print(message[i]);
    delay(100);
  }

  delay(1000);

  lcd.clear(); // Cleaning the screen (Очистка экрана)
}


/*
  Eng: Opening and closing the door
  Рус: Открытие и закрытие двери
*/
void unlockDoors() {
  // Rotate the servo to open the door (Поворот сервопривода для открытия двери)
  servo1.write(0);
  servo2.write(0);
}

void lockDoors() {
  // Rotate the servo to close the door (Поворот сервопривода для закрытия двери)
  servo1.write(90);
  servo2.write(90);
}

byte doorOpenedSymbol[8] = {
  0b01110,
  0b10000,
  0b10000,
  0b11111,
  0b11011,
  0b11011,
  0b11111,
};

byte doorClosedSymbol[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b11111,
  0b11011,
  0b11011,
  0b11111,
};


/*
  Eng: Setting a new password
  Рус: Задание нового пароля
*/
void setNewCode() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter old code:");

  char enteredCode[codeLength];
  int codeIndex = 0;

  while (codeIndex < codeLength) {
    char key = keypad.getKey();
    if (key >= '0' && key <= '9') {
      lcd.setCursor(codeIndex, 1);
      lcd.print('*');
      enteredCode[codeIndex] = key;
      codeIndex++;
    }
  }

  bool oldCodeCorrect = true;
  for (int i = 0; i < codeLength; i++) {
    if (enteredCode[i] != accessCode[i]) {
      oldCodeCorrect = false;
      break;
    }
  }

  if (oldCodeCorrect) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Set new code:");

    char newCode[codeLength];
    codeIndex = 0;

    while (codeIndex < codeLength) {
      char key = keypad.getKey();
      if (key >= '0' && key <= '9') {
        lcd.setCursor(codeIndex, 1);
        lcd.print('*');
        newCode[codeIndex] = key;
        codeIndex++;
      }
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Confirm new code:");
    codeIndex = 0;

    char confirmCode[codeLength];
    while (codeIndex < codeLength) {
      char key = keypad.getKey();
      if (key >= '0' && key <= '9') {
        lcd.setCursor(codeIndex, 1);
        lcd.print('*');
        confirmCode[codeIndex] = key;
        codeIndex++;
      }
    }

    bool codesMatch = true;
    for (int i = 0; i < codeLength; i++) {
      if (newCode[i] != confirmCode[i]) {
        codesMatch = false;
        break;
      }
    }

    if (codesMatch) {
      for (int i = 0; i < codeLength; i++) {
        accessCode[i] = newCode[i];
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("New code set!");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter code:");
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Code mismatch");
      lcd.setCursor(0, 1);
      lcd.print("New code not set!");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter code:");
    }
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wrong old code");
    lcd.setCursor(0, 1);
    lcd.print("New code not set!");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter code:");
  }
}


/*
  Eng: The function is executed once when Arduino starts.
  Рус: Функция выполняется 1 раз при старте Arduino.
*/
void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzerPin as an output pin (Установка пина для пьезоизлучателя как выходного)
  pinMode(buttonPin, INPUT_PULLUP); // Set the buttonPin as an input with internal pull-up resistor (Установка пина для кнопки с встроенным подтягивающим резистором)

  servo1.attach(9);   // Connecting servo 1 to pin 9 (Подключение сервопривода 1 к пину 9)
  servo2.attach(10);  // Connecting servo 2 to pin 10 (Подключение сервопривода к пину 10)

  lcd.init();
  lcd.backlight();    // Turning on the screen backlight (Включение подсветки экрана)

  // Creating symbols for a closed and open door (Создание символов для закрытой и открытой двери)
  lcd.createChar(0, doorClosedSymbol);
  lcd.createChar(1, doorOpenedSymbol);

  showStartupMessage(); // Display welcome messages (Отображение приветственных сообщений)

  lcd.setCursor(0, 0);
  lcd.write(byte(0)); // Closed door symbol (Символ закрытой двери)
  lcd.print(" Enter code:");
}


/*
  Eng: The function runs indefinitely after the setup() function is executed.
  Рус: Функция выполняется бесконечно после выполнения функции setup().
*/
void loop() {
  static char enteredCode[codeLength];
  static int codeIndex = 0;
  static bool doorOpen = false; // The door is initially closed (Изначально дверь закрыта)

  char key = keypad.getKey();

  if (key != NO_KEY) {
    if (key == '#') {
      if (strncmp(enteredCode, accessCode, codeLength) == 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        if (doorOpen) {
          lcd.write(byte(0)); // Closed door symbol (Символ закрытой двери)
          lcd.print(" Door closed");
          lockDoors();
        } else {
          lcd.write(byte(1)); // Open door symbol (Символ открытой двери)
          lcd.print(" Door opened");
          unlockDoors();
        }
        doorOpen = !doorOpen; // Door state switching (Переключение состояния двери)
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        byte doorSymbol = doorOpen ? lcd.write(byte(1)) : lcd.write(byte(0));
        lcd.print(" Enter code:"); // Вывод надписи "Enter code:"
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access denied");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        byte doorSymbol = doorOpen ? lcd.write(byte(1)) : lcd.write(byte(0));
        lcd.print(" Enter code:");
      }
      codeIndex = 0;
      memset(enteredCode, 0, sizeof(enteredCode)); // Reset entered code (Сброс введенного кода)
    } else if (key == '*') {
      codeIndex = 0;
      memset(enteredCode, 0, sizeof(enteredCode)); // Reset entered code (Сброс введенного кода)
      lcd.clear();
      lcd.setCursor(0, 0);
      byte doorSymbol = doorOpen ? lcd.write(byte(1)) : lcd.write(byte(0));
      lcd.print(" Enter code:");
    } else if (key == 'A') {
      setNewCode();
    } else if (key == 'C') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Set melody (1/2)");
      codeIndex = 0;
      memset(enteredCode, 0, sizeof(enteredCode)); // Сброс введенного кода
      while (codeIndex < 1) {
        char melodyKey = keypad.getKey();
        if (melodyKey >= '1' && melodyKey <= '2') {
          enteredCode[codeIndex] = melodyKey;
          lcd.setCursor(codeIndex, 1);
          lcd.print(enteredCode[codeIndex]);
          delay(1000);
          codeIndex++;
        }
      }
      selectedMelody = atoi(enteredCode); // Преобразование введенной строки в целое число
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.write(byte(0)); // Закрытая дверь
      lcd.print(" Enter code:");
    } else {
      if (codeIndex < codeLength) {
        enteredCode[codeIndex] = key;
        lcd.setCursor(codeIndex, 1);
        lcd.print('*');
        codeIndex++;
      }
    }
  }

  int buttonState = digitalRead(buttonPin); // Read the state of the button (Считываем состояние кнопки)

  if (buttonState == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("..knock-knock..");
    lcd.setCursor(4, 1);
    lcd.print("Melody " + String(selectedMelody));

    if (selectedMelody == 1) {
      playMelody(melody1, melodyLength1, noteDurations1);
    } else if (selectedMelody == 2) {
      playMelody(melody2, melodyLength2, noteDurations2);
    }

    delay(1000); // Pause for 1 second between playing melodies (Пауза в 1 секунду между воспроизведением мелодий)
  }
}

/*
  Eng: Function to play a melody on the piezoelectric buzzer
  Рус: Функция для воспроизведения мелодии на пьезоизлучателе
*/
void playMelody(int melody[], int melodyLength, int noteDurations[]) {
  for (int i = 0; i < melodyLength; i++) {

    int noteDuration = 1000 / noteDurations[i]; // Calculate the duration of the current note based on the selected note duration
    // Вычисляем длительность текущей ноты, основываясь на выбранной длительности

    tone(buzzerPin, melody[i], noteDuration); // Play the current note on the piezoelectric buzzer (Воспроизводим текущую ноту на пьезоизлучателе)

    delay(noteDuration * 1.3);  // Pause between notes to create a rhythmic melody (Пауза между нотами для создания ритмичной мелодии)

    noTone(buzzerPin); // Turn off the piezoelectric buzzer after the note duration (Отключаем пьезоизлучатель после окончания ноты)

    delay(100); // Short pause between notes (Короткая пауза между нотами)
  }
}