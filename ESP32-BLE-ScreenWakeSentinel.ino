#include <BleConnectionStatus.h>
#include <BleMouse.h>

//https://github.com/T-vK/ESP32-BLE-Mouse

unsigned long connectedMillis = 0; // delay actions until after connected for 10 seconds, because apple is dumb
int move_interval = 3;
int loop_interval = 1000;//60*1000; //ms

BleMouse bleMouse("M772", "Logitech", 100);


void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void loop()
{
  // Start, apple is dumb.
  if(bleMouse.isConnected()) {
    if (connectedMillis == 0) {
      connectedMillis = millis();
    }
    
  }
  
  if (millis() < connectedMillis + (10 * 1000)) {
    return;
  }
  // End, apple is dumb.
  
  if(bleMouse.isConnected()) {
    int distance = random(800, 2000);

    int x = random(3) - 1;
    int y = random(3) - 1;
    for (int i = 0; i < distance; i++) {
      bleMouse.move(x, y, 0);
      delay(move_interval);
    }
    delay(loop_interval);


  }
}
