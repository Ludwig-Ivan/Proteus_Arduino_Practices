// ---------------- Notas Musicales ----------------- //
// Octava 0
#define LA0 27
#define LAB0 29
#define SI0 31
#define DOB1 31

// Octava 1
#define DO1 33
#define DOS1 35
#define REB1 35
#define RE1 37
#define RES1 39
#define MIB1 39
#define MI1 41
#define FAB1 41
#define FA1 44
#define FAS1 46
#define SOLB1 46
#define SOL1 49
#define SOLS1 52
#define LAB1 52
#define LA1 55
#define LAS1 58
#define SIB1 58
#define SI1 62
#define DOB2 62

// Octava 2
#define DO2 65
#define DOS2 69
#define REB2 69
#define RE2 73
#define RES2 78
#define MIB2 78
#define MI2 82
#define FAB2 82
#define FA2 87
#define FAS2 93
#define SOLB2 93
#define SOL2 98
#define SOLS2 104
#define LAB2 104
#define LA2 110
#define LAS2 117
#define SIB2 117
#define SI2 123
#define DOB3 123

// Octava 3
#define DO3 131
#define DOS3 139
#define REB3 139
#define RE3 147
#define RES3 156
#define MIB3 156
#define MI3 165
#define FAB3 165
#define FA3 175
#define FAS3 185
#define SOLB3 185
#define SOL3 196
#define SOLS3 208
#define LAB3 208
#define LA3 220
#define LAS3 233
#define SIB3 233
#define SI3 247
#define DOB4 247

// Octava 4
#define DO4 262
#define DOS4 277
#define REB4 277
#define RE4 294
#define RES4 311
#define MIB4 311
#define MI4 330
#define FAB4 330
#define FA4 349
#define FAS4 370
#define SOLB4 370
#define SOL4 392
#define SOLS4 415
#define LAB4 415
#define LA4 440
#define LAS4 466
#define SIB4 466
#define SI4 494
#define DOB5 494

// Octava 5
#define DO5 523
#define DOS5 554
#define REB5 554
#define RE5 587
#define RES5 622
#define MIB5 622
#define MI5 659
#define FAB5 659
#define FA5 698
#define FAS5 740
#define SOLB5 740
#define SOL5 784
#define SOLS5 831
#define LAB5 831
#define LA5 880
#define LAS5 932
#define SIB5 932
#define SI5 988
#define DOB6 988

// Octava 6
#define DO6 1047
#define DOS6 1109
#define REB6 1109
#define RE6 1175
#define RES6 1245
#define MIB6 1245
#define MI6 1319
#define FAB6 1319
#define FA6 1397
#define FAS6 1480
#define SOLB6 1480
#define SOL6 1568
#define SOLS6 1661
#define LAB6 1661
#define LA6 1760
#define LAS6 1865
#define SIB6 1865
#define SI6 1976
#define DOB7 1976

// Octava 7
#define DO7 2093
#define DOS7 2217
#define REB7 2217
#define RE7 2349
#define RES7 2489
#define MIB7 2489
#define MI7 2637
#define FAB7 2637
#define FA7 2794
#define FAS7 2960
#define SOLB7 2960
#define SOL7 3136
#define SOLS7 3322
#define LAB7 3322
#define LA7 3520
#define LAS7 3729
#define SIB7 3729
#define SI7 3951
#define DOB8 3951

// Octava 8
#define DO8 4186

// -------------- Mi Sostenidos (extra) ---------------- //

#define MIS1 44   // MI♯1 = FA1
#define MIS2 87   // MI♯2 = FA2
#define MIS3 175  // MI♯3 = FA3
#define MIS4 349  // MI♯4 = FA4
#define MIS5 698  // MI♯5 = FA5
#define MIS6 1397 // MI♯6 = FA6
#define MIS7 2794 // MI♯7 = FA7

// ------------------------- Duracion de Notas ------------------------- //

#define REDONDA 1 // 1 duracion
#define BLANCA 2  // 1/2 duracion
#define NEGRA 4   // 1/4 duracion
#define COR 8     // 1/8 duracion
#define SCOR 16   // 1/16 duracion
#define FUSA 32   // 1/32 duracion
#define SFUSA 64  // 1/64 duracion

// Notas con puntillo (1.5x duración)
#define DOTTED_BLANCA 3  // Blanca con puntillo (2 * 1.5 = 3)
#define DOTTED_NEGRA 6   // Negra con puntillo (4 * 1.5 = 6)
#define DOTTED_COR 12    // Corchea con puntillo (8 * 1.5 = 12)
#define DOTTED_SCOR 24   // Semicorchea con puntillo (16 * 1.5 = 24)
#define DOTTED_FUSA 48   // Fusa con puntillo (32 * 1.5 = 48)

// ------------------------- Macros y Pines ----------------------------- //

#define LEN(x) (sizeof(x)/sizeof(x[0])) // Macro para el largo de una melodia
#define pinBuzzer1 11                   // Pin del Buzzer
#define pinBuzzer2 10                   // Pin del Buzzer
#define pinLed1 3                        // Pin del Led
#define pinLed2 2

// ----------------------- Melodias y Tiempos -------------------------- //
// Melodia 1 --> Mano Derecha
// Armaduras de la melodia: LAB, SIB, MIB 
const int melody1[] PROGMEM = {
    LAB4, SOL4,
    DO5, SIB4, SOL5,
    DO5, RE5,
    MIB5,
    LAB3, FA4, MIB4, RE4,

    DO4, 0, RE4, RE4, FA4, SOL4, RE4,
    LAB3, FA4, SOL4, SI4, 0, SI4,
    MIB4,
    MIB4, RE5, RE4, SOL4,
    MIB4, RE4, SOL4,
    DO5, RE5,
    MIB5, 0, DO4,
};

const byte tempo1[] PROGMEM = {
    BLANCA, BLANCA,
    BLANCA, NEGRA, NEGRA,
    BLANCA, BLANCA,
    REDONDA,
    DOTTED_NEGRA, SCOR, SCOR, BLANCA,

    DOTTED_NEGRA, SCOR, SCOR, COR, COR, COR, COR,
    DOTTED_NEGRA, SCOR, SCOR, DOTTED_NEGRA, SCOR, SCOR,
    REDONDA,
    DOTTED_NEGRA, COR, DOTTED_NEGRA, COR,
    BLANCA, NEGRA, NEGRA,
    BLANCA, BLANCA,
    DOTTED_BLANCA, COR, COR, 
};

// Melodia 2 --> Mano Izquierda
// Armaduras de la melodia: MIB, SIB, LAB
const int melody2[] PROGMEM = {
    LAB3, MIB4, LAB4, SOL3, RE4, SOL4,
    DO4, SOL4, DO5, SIB3, FA4, SIB4,
    LAB3, MIB4, LAB4, SOL3, RE4, SOL4,
    DO3, SOL3, DO4, RE4, MIB4,
    LAB3, FA4, MIB4, RE4,
};

const byte tempo2[] PROGMEM = {
    COR, COR, NEGRA, COR, COR, NEGRA,
    COR, COR, NEGRA, COR, COR, NEGRA,
    COR, COR, NEGRA, COR, COR, NEGRA,
    COR, COR, COR, COR, BLANCA,
    DOTTED_NEGRA, SCOR, SCOR, BLANCA,
};

// ------------------------- Logica --------------------------------- //

void setup(void) {
    Serial.begin(9600);
    pinMode(pinBuzzer1, OUTPUT);
    pinMode(pinBuzzer2, OUTPUT);
    pinMode(pinLed1, OUTPUT);
    pinMode(pinLed2, OUTPUT);
}


void loop() {
    sing();
}

void sing_duo(){
    // Determino el largo de cada melodia y identifico la mas grande
    int len1 = LEN(melody1);
    int len2 = LEN(melody2);
    int maxLen = max(len1, len2);

    for (int i = 0; i < maxLen; i++) {
        // Controla si la melodia excedio su largo, colocar silencios o nota si es el caso contrario
        int note1 = i < len1 ? pgm_read_word_near(melody1 + i) : 0;
        int note2 = i < len2 ? pgm_read_word_near(melody2 + i) : 0;

        // Controla la duracion de los silencion excedidos, o las notas si las encuentra
        int duration1 = i < len1 ? 1000 / pgm_read_byte_near(tempo1 + i) : 0;
        int duration2 = i < len2 ? 1000 / pgm_read_byte_near(tempo2 + i) : 0;

        // Determina cual de las notas dura mas
        int duration = max(duration1, duration2);

        // toca ambas notas simultáneamente
        if (note1 > 0) {
          buzz(pinBuzzer1, note1, duration1, pinLed1);
        }
        if (note2 > 0) {
          buzz(pinBuzzer2, note2, duration2, pinLed2);
        }

        int pauseBetweenNotes = duration * 1.30; // pausa entre notas
        delay(pauseBetweenNotes);

        buzz(pinBuzzer1, 0, duration1, pinLed1);
        buzz(pinBuzzer2, 0, duration2, pinLed2);
    }
}

// Metodo para reproducir una cancion
void sing(){
    Serial.println("'Determination'");
    int size = LEN(melody2); // Obtiene el tamaño de la melodia

    for (int thisNote = 0; thisNote < size; thisNote++)
    {
        // Calcula la duracion de la nota, tomando un segundo y dividiendolo entre el tipo de nota
        //e.j. 1/4 de nota = 1000 / 4, un octavo de nota = 1000/8, etc.
        int noteDuration = 1000 / pgm_read_byte_near(tempo2 + thisNote);
        buzz(pinBuzzer2, pgm_read_word_near(melody2 + thisNote), noteDuration, pinLed2);
            
        // Distingue las notas, pone un minimo de tiempo entre ellas
        // La duracion de la nota es + 30% donde parece funcionar bien
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        // Detiene la reproduccion de la nota:
        buzz(pinBuzzer2, 0, noteDuration, pinLed2);
    }
}

void buzz(int targetPin, long frequency, long length, int led){
    digitalWrite(led, HIGH);
    long delayValue = 1000000 / frequency / 2; // Calcula el valor del delay entre transiciones
    // 1 segundo convertido a microsegundos, dividido entre la frecuencia, entre 2
    // Hay dos fases en cada ciclo
    long numCycles = frequency * length / 1000; // Calcular el número de ciclos para una sincronización adecuada
    // Multiplica la frecuencia, que en realidad son ciclos por segundo, por el número de segundos para obtener el número total de ciclos a producir.
    for (long i = 0; i < numCycles; i++) { // Para calcular la cantidad de tiempo...
        digitalWrite(targetPin, HIGH); // Escriba el pin del zumbador en alto para empujar el diafragma hacia afuera
        delayMicroseconds(delayValue); // Espere el valor de delay calculado
        digitalWrite(targetPin, LOW); // Gire el pasador del zumbador hacia abajo para tirar hacia atrás el diafragma
        delayMicroseconds(delayValue); // Espere de nuevo o el valor de delay calculado
    }
    digitalWrite(led, LOW);
}
