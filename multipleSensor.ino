#include <ros.h>
#include <std_msgs/Float32.h>
#include "Filter.h"

int trig = 12;
int echo = 11;

int infra = 7;

long park_pulse;

float infra_state;
float park_cm; 

ros::NodeHandle nh;

std_msgs::Float32 flt_msg;
ros::Publisher parkSensorFeedback("parkSensorFeedback", &flt_msg);
ros::Publisher infraSensorFeedback("infraSensorFeedback", &flt_msg);

ExponentialFilter<float> filter(80, 0);

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(infra, INPUT);
  nh.initNode();
  nh.advertise(parkSensorFeedback);
  nh.advertise(infraSensorFeedback);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delay(5);
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  park_pulse = pulseIn(echo, HIGH);
  park_cm = park_pulse * 0.017;
  filter.Filter(park_cm);
  float filtered_cm = filter.Current();
  infra_state = digitalRead(infra);
  flt_msg.data = filtered_cm;
  parkSensorFeedback.publish(&flt_msg);
  flt_msg.data = infra_state;
  infraSensorFeedback.publish(&flt_msg);
  nh.spinOnce();
  delay(100);
  
}
