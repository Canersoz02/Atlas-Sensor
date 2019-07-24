#include <ros.h>
#include <std_msgs/Float32.h>
#include <Sensor.h>

ros::NodeHandle nh;

std_msgs::Float32 flt_msg;
ros::Publisher sensorData("sensorData", &flt_msg);,

Sensor sens1(7);

void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(sensorData);

}

void loop() {
  // put your main code here, to run repeatedly:
  flt_msg.data = sens1.retValue();
  sensorData.publish(&flt_msg);
  nh.spinOnce();
  delay(50);
  

}
