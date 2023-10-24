/*
  PROJECT: https://wokwi.com/projects/379374334442918913
  AUTHOR:  Anastasia Cheremisova
  https://github.com/space13pirate
*/

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


/*
  Eng: The function is executed once when Arduino starts.
  Рус: Функция выполняется 1 раз при старте Arduino.
*/
void setup() {
  Serial.begin(9600); // Initialize serial communication at a baud rate of 9600 (Инициализация последовательной связи с скоростью 9600 бит/с)
  pinMode(buzzerPin, OUTPUT); // Set the buzzerPin as an output pin (Установка пина для пьезоизлучателя как выходного)
  pinMode(buttonPin, INPUT_PULLUP); // Set the buttonPin as an input with internal pull-up resistor (Установка пина для кнопки с встроенным подтягивающим резистором)

  /*
    Eng: Prompt the user for the doorbell melody selection
    Рус: Запрос у пользователя выбора мелодии для дверного звонка
  */
  Serial.println("Select a doorbell melody:\n1) Jingle Bells \n2) Calm Melody");
  while (!Serial.available()) {
    // Wait until the user enters data (Ждём, пока пользователь не введёт данные)
  }
  selectedMelody = Serial.parseInt(); // Reading user selection as an integer (Считывание выбора пользователя как целого числа)

  /*
    Eng: Clear the input buffer to prevent issues with extra characters
    Рус: Очистка буфера ввода, чтобы избежать проблем с дополнительными символами
  */
  while (Serial.available()) {
    Serial.read();
  }

  Serial.println("Doorbell melody set to " + String(selectedMelody)); // Print the selected melody (Вывод выбранной мелодии)
}


/*
  Eng: The function runs indefinitely after the setup() function is executed.
  Рус: Функция выполняется бесконечно после выполнения функции setup().
*/
void loop() {
  int buttonState = digitalRead(buttonPin); // Read the state of the button (Считываем состояние кнопки)

  if (buttonState == LOW) {
    Serial.print("\nSomeone is ringing the doorbell. "); // Display a message indicating the button press (Выводим сообщение о нажатии кнопки)
    Serial.println("Melody " + String(selectedMelody) + " is playing..."); // Display the current melody being played (Выводим сообщение о текущей мелодии)

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