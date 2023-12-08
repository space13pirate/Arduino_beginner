/*
  PROJECT: https://wokwi.com/projects/383512459724321793
  AUTHOR:  Anastasia Cheremisova
  https://github.com/space13pirate
*/

#include <Adafruit_ILI9341.h>   // Include the Adafruit ILI9341 library for TFT display (Подключение библиотеки Adafruit ILI9341 для TFT-дисплея)
#include <Adafruit_NeoPixel.h>  // Include the Adafruit NeoPixel library for controlling NeoPixels (Подключение библиотеки Adafruit NeoPixel для управления NeoPixel)
#include <DHT.h>                // Include the DHT library for DHT sensors (Подключение библиотеки DHT для датчика DHT)

// Connecting a button (Подключение кнопки)
#define BUTTON_PIN 3            // Defining the digital pin for a button (Определение цифрового пина для кнопки)

// Connecting the DHT22 sensor (Подключение датчика температуры DHT22)
#define DHTPIN 2                // Defining the digital pin for the DHT sensor (Определение цифрового контакта для датчика DHT)
#define DHTTYPE DHT22           // Defining the type of DHT sensor (Определение типа датчика DHT)
DHT dht(DHTPIN, DHTTYPE);       // Creating a DHT Object (Создание объекта DHT)

// Connecting NeoPixel LED Ring (Подключение NeoPixel LED Ring)
#define NEOPIXEL_PIN 6          // Defining the digital pin for the NeoPixel LED Ring (Определение цифрового контакта для светодиодного кольца NeoPixel)
#define NEOPIXEL_NUMPIXELS 16   // Defining the number of NeoPixels in the ring (Определение количества NeoPixels в кольце)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NEOPIXEL_NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800); // Creating a NeoPixel object (Создание объекта NeoPixel)

// Connecting a piezo emitter (Подключение пьезоизлучателя)
#define BUZZER_PIN 5            // Defining the digital pin for the piezo buzzer (Определение цифрового контакта для пьезоизлучателя)

// Connecting a TFT display (Подключение TFT-дисплея)
#define TFT_CS 10               // Defining the chip select pin for the TFT display (Определение контакта выбора пина для TFT-дисплея)
#define TFT_DC 9                // Defining the data/command pin for the TFT display (Определение вывода данных/команды для TFT-дисплея)
#define TFT_RST 8               // Defining the reset pin for the TFT display (Определение контакта сброса для TFT-дисплея)
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST); // Creating a TFT display object (Cоздание объекта TFT-дисплея)

// Kettle condition (Состояние чайника)
bool isOn = false;                    // Variable to store the state of the kettle (on/off) (Переменная для хранения состояния чайника (вкл/выкл))
float previousTemperature = -1;       // Variable to store the previous temperature reading (Переменная для хранения предыдущих показаний температуры)
int buttonState = LOW;                // Variable to store the current state of the button (Переменная для хранения текущего состояния кнопки)
int lastButtonState = LOW;            // Variable to store the previous state of the button (Переменная для хранения предыдущего состояния кнопки)
unsigned long lastDebounceTime = 0;   // Variable to store the last time the button was debounced (Переменная для хранения последнего времени, когда кнопка была обездвижена)
unsigned long debounceDelay = 50;     // Debounce delay time in milliseconds (Задержка для подавления дребезга кнопки в миллисекундах)

/*
  Eng: The function is executed once when Arduino starts.
  Рус: Функция выполняется 1 раз при старте Arduino.
*/
void setup() {
  Serial.begin(9600);           // Start serial communication for debugging (Запуск последовательной связи для отладки)

  pinMode(BUTTON_PIN, INPUT);   // Setup button (Настройка кнопки)

  pixels.begin();               // Setup NeoPixel (Настройка NeoPixel)

  dht.begin();                  // Setup temperature sensor (Настройка датчика температуры)

  tft.begin();                  // Setup TFT display (Настройка TFT-дисплея)

  // tft.setRotation(3);        // Rotate the display by 180 degrees (Поворот дисплея на 180 градусов)

  turnOff();                    // Turn off the kettle initially (Выключение чайника изначально)
}

/*
  Eng: The function runs indefinitely after the setup() function is executed.
  Рус: Функция выполняется бесконечно после выполнения функции setup().
*/
void loop() {
  // Button handling (Обработка кнопки)
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        // Turn the kettle on or off when the button is pressed (Включение или выключение чайника при нажатии кнопки)
        if (!isOn) {
          turnOn();
        } else {
          turnOff();
        }
      }
    }
  }

  lastButtonState = reading;

  // Data processing when the kettle is on (Обработка данных при включенном чайнике)
  if (isOn) {
    // Measure temperature (Измерение температуры)
    float temperature = dht.readTemperature();
    
    // Check for temperature change before updating (Проверка изменения температуры перед обновлением)
    if (temperature != previousTemperature) {
      // Display temperature on the screen (Отображение температуры на экране)
      tft.fillScreen(ILI9341_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.print("ON");

      tft.setCursor(0, 30);
      tft.setTextSize(2);
      tft.print("Temp: ");
      tft.print(temperature);
      tft.print(" C");

      // Control NeoPixel backlight based on temperature (Управление подсветкой NeoPixel в зависимости от температуры)
      updateNeoPixel(temperature);

      // Play melody when temperature is above 70 degrees (Воспроизведение мелодии при температуре больше 70 градусов)
      if (temperature > 70) {
        playMelody();
      }

      // Save the current temperature value (Сохранение текущего значения температуры)
      previousTemperature = temperature;
    }
    
    delay(1000);  // Delay for data update (Задержка обновления данных)
  }
}

void turnOn() {
  isOn = true;
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_WHITE);
  tft.print("ON");
  delay(500);   // Delay to eliminate button debounce (Задержка для устранения дребезга кнопок)
}

void turnOff() {
  isOn = false;
  tft.fillScreen(ILI9341_BLACK);
  pixels.clear();
  pixels.show();
  noTone(BUZZER_PIN);

  tft.setCursor(0, 0);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_WHITE);
  tft.println("OFF");
  delay(500);   // Delay to eliminate button debounce (Задержка для устранения дребезга кнопок)
}

void updateNeoPixel(float temperature) {
  if (temperature >= 0 && temperature < 30) {
    pixels.fill(pixels.Color(0, 0, 255));   // Blue color (Синий цвет)
  } else if (temperature >= 30 && temperature < 70) {
    pixels.fill(pixels.Color(255, 165, 0)); // Orange color (Оранжевый цвет)
  } else if (temperature >= 70 && temperature <= 80) {
    pixels.fill(pixels.Color(255, 0, 0));   // Red color (Красный цвет)
  } else {
    pixels.clear(); // Turn off backlight (Выключение подсветки)
  }
  pixels.show();
}

void playMelody() {
  tone(BUZZER_PIN, 1000, 2000); // Play a short melody (Проигрывание короткой мелодии)
  delay(200);                   // Delay to avoid melody overlap (Задержка, чтобы избежать наложения мелодии)
  noTone(BUZZER_PIN);
}