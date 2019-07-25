#!/usr/bin/env python

import rospy
import math
import array
import time
from std_msgs.msg import Float32

class SensData:
    def __init__(self):
        self.data = 1
        self.flag = False
        rospy.init_node('sensorOptimise', anonymous=True)
        self.pub = rospy.Publisher('optimisedData', Float32, queue_size = 10)
        rospy.Subscriber('sensorData', Float32, self.update_value)

    def update_value(self, msg):
        self.data = msg.data

def stdDev(arr):
    n = len(arr)
    mean, sd = avg(arr), 0.0
    for i in arr:
        sd += (float(i) - mean)**2
    sd = math.sqrt(sd / float(n-1))
    if(sd > 4 or lowest(arr) > 640):
        return 0
    return lowest(arr)

def avg(arr):
    n, mean = len(arr), 0.0
    if n <= 1:
        return ls[0]
    for i in arr:
        mean = mean + float(i)
    mean = mean / float(n)
    return mean

def lowest(arr):
    lst = 650
    for i in arr:
        if(i < lst):
            lst = i
    if(lst > 640):
        return(0)
    return(lst)

def inRange(arr):
    for i in arr:
        if(i > 0 and i < 20 or i > 644):
            return(True)
    
if __name__ == '__main__':
    arr = []
    a = SensData()
    r = rospy.Rate(20)
    r2 = rospy.Rate(5)

    while not rospy.is_shutdown():
        for i in range(5):
            arr.append(a.data)
            r.sleep()
        rospy.loginfo(arr)
        rospy.loginfo(stdDev(arr))
        a.pub.publish(lowest(arr))

        del arr[:]
