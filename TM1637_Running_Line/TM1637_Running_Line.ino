/*
PROJECT: https://wokwi.com/projects/378181636088343553
AUTHOR:  Anastasia Cheremisova
https://github.com/space13pirate
*/

/*
Eng: Inclusion of the GyverTM1637 library, which allows you to easily manage the TM1637 indicator.
Рус: Включение библиотеки GyverTM1637, которая позволяет легко управлять индикатором TM1637.
*/
#include "GyverTM1637.h"

/*
Eng: Defining 2 constants CLK and DIO and assigning them values 2 and 3 respectively.
Рус: Определение 2 констант CLK и DIO и присваиваивание им значений 2 и 3 соответственно.
*/
#define CLK 2
#define DIO 3

/*
Eng: Creation of a disp object of type GyverTM1637 and initialization indicating the CLK and DIO pins to which the indicator is connected.
Рус: Создание объекта disp типа GyverTM1637 и инициализация с указанием пинов CLK и DIO, к которым подключён индикатор.
*/
GyverTM1637 disp(CLK, DIO);

/*
Eng: The function is executed once when Arduino starts.
Рус: Функция выполняется 1 раз при старте Arduino.
*/
void setup() {
  /*
  Eng: Initializes a serial port connection at 9600 bps (will be used to output debug messages).
  Рус: Инициализация соединения по последовательному порту со скоростью 9600 бит в секунду (будет использоваться для вывода отладочных сообщений).
  */
  Serial.begin(9600);

  /*
  Eng: Set the indicator brightness to 7 (maximum brightness).
  Рус: Установка яркости индикатора равной 7 (максимальная яркость).
  */
  disp.brightness(7);
}

/*
Eng: The function runs indefinitely after the setup() function is executed.
Рус: Функция выполняется бесконечно после выполнения функции setup().
*/
void loop() {
  /*
  Eng: Create an array that contains segment definitions for displaying specific characters.
  Рус: Создание массива, который содержит определения сегментов для отображения определённых символов.
  */
  byte running_line[] = {_E, _n, _J, _O, _Y, _empty,
                        _L, _l, _F, _E};

  /*
  Eng: Calling the runningString function from the GyverTM1637 library to display a “running line” on the indicator.
  Рус: Вызов функции runningString из библиотеки GyverTM1637 для отображения "бегущей строки" на индикаторе.
  */
  disp.runningString(running_line, sizeof(running_line), 300);
}