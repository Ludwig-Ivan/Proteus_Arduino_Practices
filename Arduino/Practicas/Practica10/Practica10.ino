// const int filas[4] = {2, 3, 4, 5};   // Pines de filas
// const int columnas[4] = {6, 7, 8, 9};   // Pines de columnas

// char teclas[4][4] = {  // Mapeo de teclas
//   {'1', '2', '3', 'A'},
//   {'6', '5', '4', 'B'},
//   {'7', '8', '9', 'C'},
//   {'*', '0', '#', 'D'}
// };

// void setup() {
//   Serial.begin(9600);

//   // Configurar las filas como salidas y ponerlas en HIGH
//   for (int i = 0; i < 4; i++) {
//     pinMode(filas[i], OUTPUT);
//     digitalWrite(filas[i], HIGH);
//   }
//   // Configurar las columnas como entradas con pull-up
//   for (int i = 0; i < 4; i++) {
//     pinMode(columnas[i], INPUT_PULLUP);
//   }
//   pinMode(12, INPUT_PULLUP);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   for (int i = 0; i < 4; i++) {  // Recorrer las filas
//     digitalWrite(filas[i], LOW); // Activar la fila actual

//     for (int j = 0; j < 4; j++) { // Recorrer las columnas
//       if (digitalRead(columnas[j]) == LOW) { // Si la columna está en LOW
//         Serial.println(teclas[i][j]);  // Imprimir la tecla presionada
//         delay(300);  // Pequeño retardo para evitar repeticiones
//       }
//     }

//     digitalWrite(filas[i], HIGH); // Desactivar la fila
//   }
// }

#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'6','5','4', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key){
    Serial.println(key);
  }
}
