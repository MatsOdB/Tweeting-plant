import sys
print(sys.version)
import time
from time import sleep
import tweepy
import serial
from tweepy import api

access_token = "TOKEN"
access_token_secret = "TOKEN"
consumer_key = "TOKEN"
consumer_secret = "TOKEN"
ser = serial.Serial('DEVICE', baudrate = 9600, timeout = 1)

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)
time.sleep(2)

while 1:
    arduinoData = ser.readline().decode('ascii')
    api.update_status(arduinoData)
    print(arduinoData + ' was posted on twitter')
    time.sleep(900)
