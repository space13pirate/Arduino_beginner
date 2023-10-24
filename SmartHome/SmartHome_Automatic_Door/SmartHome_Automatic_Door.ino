/*
  PROJECT: https://wokwi.com/projects/379427443143016449
  AUTHOR:  Anastasia Cheremisova
  https://github.com/space13pirate
*/

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

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
      lcd.print("Enter code:");
    } else if (key == 'A') {
      setNewCode();
    } else {
      if (codeIndex < codeLength) {
        enteredCode[codeIndex] = key;
        lcd.setCursor(codeIndex, 1);
        lcd.print('*');
        codeIndex++;
      }
    }
  }
}