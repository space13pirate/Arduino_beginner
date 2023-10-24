/*
  PROJECT: https://wokwi.com/projects/379366705103728641
  AUTHOR:  Anastasia Cheremisova
  https://github.com/space13pirate
*/

const int trigPin = 3; // Pin for sending signal to the ultrasonic sensor (Пин для отправки сигнала на ультразвуковой датчик)
const int echoPin = 2; // Pin for receiving echo signal from the ultrasonic sensor (Пин для приёма эхо-сигнала с ультразвукового датчика)

const int ledPins[] = {8, 9, 10, 11}; // Pins for controlling LEDs (Пины для управления светодиодами)
const int numLEDs = 4;  // Number of LEDs (Количество светодиодов)

long duration;  // Variable to store signal duration (Переменная для хранения длительности сигнала)
int distance;   // Variable to store the measured distance (Переменная для хранения измеренного расстояния)

int currentLED = 0;   // Current active LED (Текущий активный светодиод)

/*
Eng: The function is executed once when Arduino starts.
Рус: Функция выполняется 1 раз при старте Arduino.
*/
void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);  // Set the pins for LEDs as outputs (Настроим пины для светодиодов на вывод)
  }
  pinMode(trigPin, OUTPUT); // Set the pin for sending signal to the ultrasonic sensor as an output (Настроим пин для отправки сигнала на ультразвуковой датчик как выход)
  pinMode(echoPin, INPUT);  // Set the pin for receiving echo signal from the ultrasonic sensor as an input (Настроим пин для приема эхо-сигнала с ультразвукового датчика как вход)
  Serial.begin(9600);       // Initialize serial communication for debugging (Настроим последовательную связь для отладки)
}

/*
Eng: The function runs indefinitely after the setup() function is executed.
Рус: Функция выполняется бесконечно после выполнения функции setup().
*/
void loop() {
  digitalWrite(trigPin, LOW); // Send a short pulse to trigPin to start distance measurement (Отправим короткий импульс на trigPin, чтобы начать измерение расстояния)
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the signal on echoPin, which corresponds to the time of echo return (Измерим длительность сигнала на echoPin, который соответствует времени возвращения эхо)
  duration = pulseIn(echoPin, HIGH);

  // Convert the duration to distance in centimeters using the speed of sound in air and division by 2 (Преобразуем длительность в расстояние в сантиметрах, используя скорость звука в воздухе и деление на 2
  distance = (duration / 2) / 29.1;

  if (distance > 0) {
    // Determine which LED to turn on based on the distance (divided by 100, 1 m = 1 LED) (Определяем, какой светодиод включать на основе расстояния (разделив на 100, 1 м = 1 светодиод))
    int ledToTurnOn = distance / 100;

    if (ledToTurnOn != currentLED) {
      turnOffLEDs(); // If the LED number has changed, turn off all LEDs (Если номер светодиода изменился, выключаем все светодиоды)
      if (ledToTurnOn > 0) {
        digitalWrite(ledPins[ledToTurnOn - 1], HIGH); // // Turn on the required LED (Включаем нужный светодиод)
      }
      currentLED = ledToTurnOn;
    }
  }
}

void turnOffLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);  // Turn off all LEDs (Выключаем все светодиоды)
  }
}