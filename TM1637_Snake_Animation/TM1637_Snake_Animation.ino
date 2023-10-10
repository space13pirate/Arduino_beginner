/*
PROJECT: https://wokwi.com/projects/378093853668193281
AUTHOR:  Anastasia Cheremisova
https://github.com/space13pirate
*/

/*
Eng: Including the "TM1637TinyDisplay" library.
Рус: Включение библиотеки "TM1637TinyDisplay".
*/
#include <TM1637TinyDisplay.h>

/*
Eng: Defining 2 constants CLK and DIO and assigning them values 2 and 3 respectively.
Рус: Определение 2 констант CLK и DIO и присваиваивание им значений 2 и 3 соответственно.
*/
#define CLK 2
#define DIO 3

TM1637TinyDisplay display(CLK, DIO);

/*
Eng: Defining an animation array, which is a sequence of animation frames.
Рус: Определение массива анимации, который представляет собой последовательность кадров анимации.
*/
const uint8_t ANIMATION_SNAKE[20][4] = {
// Movement to the right (движение вправо)
{ 0x01, 0x01, 0x01, 0x00 }, 
{ 0x00, 0x01, 0x01, 0x01 },
// Turning (поворот)
{ 0x00, 0x00, 0x01, 0x03 },
{ 0x00, 0x00, 0x00, 0x43 },
{ 0x00, 0x00, 0x40, 0x42 },
// Movement to the left (движение влево)
{ 0x00, 0x40, 0x40, 0x40 }, 
{ 0x40, 0x40, 0x40, 0x00 },
// Turning (поворот)
{ 0x50, 0x40, 0x00, 0x00 },
{ 0x58, 0x00, 0x00, 0x00 },
{ 0x18, 0x08, 0x00, 0x00 }, 
// Movement to the right (движение вправо)
{ 0x08, 0x08, 0x08, 0x00 },
{ 0x00, 0x08, 0x08, 0x08 },
// Turning (поворот)
{ 0x00, 0x00, 0x08, 0x0c }, 
{ 0x00, 0x00, 0x00, 0x4c },
{ 0x00, 0x00, 0x40, 0x44 },
// Movement to the left (движение влево)
{ 0x00, 0x40, 0x40, 0x40 }, 
{ 0x40, 0x40, 0x40, 0x00 },
 // Turning (поворот)
{ 0x60, 0x40, 0x00, 0x00 }, 
{ 0x61, 0x00, 0x00, 0x00 },
{ 0x21, 0x01, 0x00, 0x00 },
};

/*
Eng: The function is executed once when Arduino starts.
Рус: Функция выполняется 1 раз при старте Arduino.
*/
void setup() {
  /*
  Eng: Initializing the indicator using the begin() method of the display object.
  Рус: Инициализация индикатора с помощью метода begin() объекта display.
  */
  display.begin();
}

/*
Eng: The function runs indefinitely after the setup() function is executed.
Рус: Функция выполняется бесконечно после выполнения функции setup().
*/
void loop() {
/*
Eng: Displaying an Animation Sequence
ANIMATION_SNAKE - array with a sequence of animation frames
FRAMES(ANIMATION_SNAKE) - number of animation frames calculated using the FRAMES() macro
TIME_MS(ms) - time interval between animation frames (200 milliseconds)

Рус: Отображение последовательности анимации
ANIMATION_SNAKE - массив с последовательностью кадров анимации
FRAMES(ANIMATION_SNAKE) - количество кадров анимации, вычисляемое с помощью макроса FRAMES()
TIME_MS(ms) - интервал времени между кадрами анимации (200 миллисекунд)
*/
display.showAnimation(ANIMATION_SNAKE, FRAMES(ANIMATION_SNAKE), TIME_MS(200));
}