// 3 sensörlü çizgi izleyen projesi
// siyah zemin üstünde beyaz çizgi ya da beyaz zemin üstünde siyah çizgide çalışabilir.

int mod = 0; // sadece çizgi izleyen modu

// ÇİZGİ İZLEYEN SENSÖR BAĞLANTILARI VE DEĞİŞKENLERİ
#define sol_sensor 4
#define orta_sensor 3
#define sag_sensor 2

int sol;
int orta;
int sag;

// TCRT 5000 SENSÖRÜNDE RENK siyah ise alınan değer 0
//                      RENK beyaz ise alınan değer 1'dir
int siyah = 0;
int beyaz = 1;
// beyaz üstü siyah

int yol = siyah;
int cizgi = beyaz;

// MOTOR SÜRÜCÜ PİNLERİ
#define sol_motor_ileri 9
#define sol_motor_geri 10
#define sag_motor_ileri 6
#define sag_motor_geri 5

void setup() {
    pinMode(sol_sensor, INPUT);
    pinMode(orta_sensor, INPUT);
    pinMode(sag_sensor, INPUT);

    pinMode(sol_motor_ileri, OUTPUT);  
    pinMode(sol_motor_geri, OUTPUT);
    pinMode(sag_motor_ileri, OUTPUT);
    pinMode(sag_motor_geri, OUTPUT);    

    Serial.begin(9600); 
}

void loop() {
    while (mod == 0) { // çizgi izleyen modu
        sol = digitalRead(sol_sensor);
        orta = digitalRead(orta_sensor);
        sag = digitalRead(sag_sensor);

        Serial.print(sol); Serial.print(orta); Serial.println(sag);

        if (sol == yol && orta == cizgi && sag == yol) {
            digitalWrite(sol_motor_ileri, 1);
            digitalWrite(sag_motor_ileri, 1);
        }
        else if (sol == cizgi && orta == yol && sag == yol) {
            digitalWrite(sol_motor_ileri, 0);
            digitalWrite(sag_motor_ileri, 1);
        }
        else if (sol == yol && orta == yol && sag == cizgi) {
            digitalWrite(sol_motor_ileri, 1);
            digitalWrite(sag_motor_ileri, 0);
        }
    }
}
