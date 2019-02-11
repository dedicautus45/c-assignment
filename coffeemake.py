from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
import socket 
import json
import time
STATUS_OK = 0x00

def customCallback(client, userdata, message):
    print("Received a new message: ")
    print(message.payload)
    print("from topic: ")
    print(message.topic)
    print("--------------\n\n")
    STATUS_OK = 0x00
    string = message.payload
    JSON=json.loads(string)
    
    sock =socket.socket( socket.AF_INET, socket.SOCK_STREAM )   #open socket
    sock.connect((address,port))                                #connect socket
    sock.settimeout(5)
    data=bytearray([56,1,0,0,0,126])
    #if(JSON["command"] == 51):
     #   data=bytearray([JSON["command"],JSON["noofcups"],JSON["strength"],JSON["type"],0,126])  
    #else:
     #   data=bytearray([JSON["command"],JSON["strength"],JSON["noofcups"],JSON["type"],0,126])
    sock.send(data)
    status=ord(sock.recv(1))



#coffeemaker 
address='192.168.0.54'
port = 2081

STATUS_OK = 0x00                
STATUS_ALREADY_BREWING = 0x01
STATUS_INVALID_ARGS = 0x04
STATUS_NO_CARAFFE = 0x05
STATUS_NO_WATER = 0x06
STATUS_LOW_WATER = 0x07
CMD_GET_WIFI_APS = 13
CMD_START_BREWING = 51
CMD_SET_STRENGTH = 53
CMD_SET_CUPS     = 54
CMD_SET_CONFIG   = 56
CMD_ENABLE_WARMING = 62
CMD_DISABLE_WARMING = 74
CMD_END = 126


#mqttclientcode
myAWSIoTMQTTClient = None
myAWSIoTMQTTClient = AWSIoTMQTTClient('example')
myAWSIoTMQTTClient.configureEndpoint('a21rlh0j8rhw6m-ats.iot.us-east-1.amazonaws.com', 8883)
myAWSIoTMQTTClient.configureCredentials('/home/inteldk300/Downloads/ex/root-CA.crt', '/home/inteldk300/Downloads/ex/example.private.key', '/home/inteldk300/Downloads/ex/example.cert.pem')
myAWSIoTMQTTClient.configureAutoReconnectBackoffTime(1, 32, 20)
myAWSIoTMQTTClient.configureOfflinePublishQueueing(-1)  # Infinite offline Publish queueing
myAWSIoTMQTTClient.configureDrainingFrequency(2)  # Draining: 2 Hz
myAWSIoTMQTTClient.configureConnectDisconnectTimeout(10)  # 10 sec
myAWSIoTMQTTClient.configureMQTTOperationTimeout(5)  # 5 sec
myAWSIoTMQTTClient.connect()
myAWSIoTMQTTClient.subscribe("topic_1",1,customCallback)
time.sleep(1000)














