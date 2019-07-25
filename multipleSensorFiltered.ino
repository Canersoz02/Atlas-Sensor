#include <ros.h>
#include <std_msgs/Float32.h>
#include <Sensor.h>
#include "Filter.h"

ros::NodeHandle nh;

std_msgs::Float32 flt_msg;
ros::Publisher sensor1Feedback("sensor1Feedback", &flt_msg);
ros::Publisher sensor2Feedback("sensor2Feedback", &flt_msg);

Sensor sens1(7);
Sensor sens2(6);

ExponentialFilter<float> sensor1Filter(80, 0);
ExponentialFilter<float> sensor2Filter(80, 0);

void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(sensorData);

}

void loop() {
  // put your main code here, to run repeatedly:
  sens1Filter.Filter(sens1.retValue());
  sens2Filter.Filter(sens2.retValue());
  flt_msg.data = sens1Filter.Current();
  sensor1Feedback.publish(&flt_msg);
  flt_msg.data = sens2Filter.Current();
  sensor2Feedback.publish(&flt_msg);
  nh.spinOnce();
  delay(50);
  

}
