from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
import socket 
import json
import time
from array import array


incommingCommandFirst =""
incommingCommandSecond=""



#coffeemaker 
address='192.168.0.54'
port = 2081

#STATUS_CODES
STATUS_OK = 0x00                
STATUS_ALREADY_BREWING = 0x01
STATUS_INVALID_ARGS = 0x04
STATUS_NO_CARAFFE = 0x05
STATUS_NO_WATER = 0x06
STATUS_LOW_WATER = 0x07

#COMMANDS
CMD_GET_WIFI_APS = 13
CMD_START_BREWING = 51
CMD_SET_STRENGTH = 53
CMD_SET_CUPS     = 54
CMD_START_BREW = 55
CMD_SET_CONFIG   = 56
CMD_ENABLE_WARMING = 62
CMD_DISABLE_WARMING = 74
CMD_END = 126

#mqttclientcode
myAWSIoTMQTTClient = AWSIoTMQTTClient('example')
myAWSIoTMQTTClient.configureEndpoint('a21rlh0j8rhw6m-ats.iot.us-east-1.amazonaws.com', 8883)
myAWSIoTMQTTClient.configureCredentials('/home/inteldk300/Downloads/ex/root-CA.crt', '/home/inteldk300/Downloads/ex/example.private.key', '/home/inteldk300/Downloads/ex/example.cert.pem')
myAWSIoTMQTTClient.configureAutoReconnectBackoffTime(1, 32, 20)
myAWSIoTMQTTClient.configureOfflinePublishQueueing(-1)  # Infinite offline Publish queueing
myAWSIoTMQTTClient.configureDrainingFrequency(2)  # Draining: 2 Hz
myAWSIoTMQTTClient.configureConnectDisconnectTimeout(10)  # 10 sec
myAWSIoTMQTTClient.configureMQTTOperationTimeout(5)  # 5 sec
try:
    myAWSIoTMQTTClient.connect()
    print("Device Is sucessfully Connected To AWSIOT")
except:
    print("Please Check The Internet Connection/Give Correct configureCredentials ")


#function 
def response_code(sock):
        size = ord(sock.recv(1)[0])
        status = ord( sock.recv(1)[0] )
        data = sock.recv( size-2 )
        response = {}
        if status != STATUS_OK:
            print status
            print "!%s" % status_string(status)
	    messageJson = status_string(status)
            response["Status Code"] = status
            response["Status"] = str(status_string(status))
	    message = {"Message":response}
            myAWSIoTMQTTClient.publish("topic",json.dumps(message),0)
            return False     
	else:          
		    response["Status Code"] = status
		    response["Status"] = str(status_string(status))
		    message = {"Message":response}
		    myAWSIoTMQTTClient.publish("topic",json.dumps(message),0)
		    return True


def response_code1(sock):
        data = sock.recv( 4096 )
	        
	response = {}
        statusMessageType = {
	   
    	'0x0' : "Status,OK",
        '0x4' : "Filter, ?",
        '0x5' : "Filter, OK to start",
        '0x6' : "No carafe",
        '0x7' : "Beans, OK to start",
        '0x20' : "Filter, No carafe",
        '0x22' : "Beans, No carafe",
        '0x23' : "Beans, Not enough water",
        '0x45' : "Filter, Done",
        '0x46' : "Beans, No carafe, Hotplate On",
        '0x47' : "Beans, Done",
        '0x53' : "Boiling",
        '0x60' : "Filter, No carafe, Hotplate On",
        '0x61' : "Filter, Hotplate On",
        '0x62' : "Beans, No carafe, Hotplate On",
        '0x63' : "Beans, Hotplate On",
        '0x51' : "Descaling in progress"

	}
        waterLevelMessageType = {
        '0x0' : "Not enough water",
        '0x1' : "Low",
        '0x2' : "Half",
        '0x12' : "Half",
        '0x13' : "Full",
                    }
        strengthMessageType = {
	    '0x0' : "weak",
	    '0x1' : "medium",
	    '0x2' : "strong",
			}
	cupsMessageType = { 
	    '0x1' : "1",
	    '0x2' : "2",
	    '0x3' : "3",
	    '0x4' : "4",
	    '0x5' : "5",
	    '0x6' : "6",
	    '0x7' : "7",
	    '0x8' : "8",
	    '0x9' : "9",
	    '0xa' : "10",
	    '0xb' : "11",
	    '0xc' : "12",
	    '0x21' : "1",
	    '0x22' : "2",
	    '0x23' : "3",
	    '0x24' : "4",
	    '0x25' : "5",
	    '0x26' : "6",
	    '0x27' : "7",
	    '0x28' : "8",
	    '0x29' : "9",
	    '0x2a' : "10",
	    '0x2b' : "11",
	    '0x2c' : "12",
	    '0x31' : "1",
	    '0x32' : "2",
	    '0x33' : "3",
	    '0x34' : "4",
	    '0x35' : "5",
	    '0x36' : "6",
	    '0x37' : "7",
	    '0x38' : "8",
	    '0x39' : "9",
            '0x3a' : "10",
	    '0x3a' : "10",
	    '0x3b' : "11",
	    '0x3c' : "12",
	    '0x61' : "1",
	    '0x62' : "2",
	    '0x63' : "3",
	    '0x64' : "4",
	    '0x65' : "5",
	    '0x66' : "6",
	    '0x67' : "7",
	    '0x68' : "8",
	    '0x69' : "9",
	    '0x6a' : "10",
	    '0x6b' : "11",
	    '0x6c' : "12",
	    '0x81' : "1",
	    '0x82' : "2",
	    '0x83' : "3",
	    '0x84' : "4",
	    '0x85' : "5",
	    '0x86' : "6",
	    '0x87' : "7",
	    '0x88' : "8",
	    '0x89' : "9",
	    '0x8a' : "10",
	    '0x8b' : "11",
	    '0x8c' : "12",
	    '0xc1' : "1",
	    '0xc2' : "2",
	    '0xc3' : "3",
	    '0xc4' : "4",
	    '0xc5' : "5",
	    '0xc6' : "6",
	    '0xc7' : "7",
	    '0xc8' : "8",
	    '0xc9' : "9",
	    '0xca' : "10",
            '0xcb' : "11",
            '0xcc' : "12",
        }
        a = array("B" ,data)
    	b = map(hex, a)
	print b
    	deviceMessage  = b[0]
        statusMessage = b[1]
        waterLevelMessage = b[2]
        strengthMessage = b[4]
	cupsMessage = b[5]
	try:
        		textMessageStatus = 'Status: ' + statusMessageType[statusMessage]
    	except:
			textMessageStatus = 'Status: Unknown (' + statusMessage +')'
        print textMessageStatus
	try:
          textMessageWater = 'Water Level: ' + waterLevelMessageType[waterLevelMessage]
        except:
          textMessageWater = 'Water Level: Unknown (' + waterLevelMessage +')'
        print(textMessageWater)
        try:
      	  textMessageStrength = 'Strength: ' + strengthMessageType[strengthMessage]
    	except:
        	textMessageStrength = 'Strength: Unknown (' + strengthMessage +')'
        print(textMessageStrength)
	try:
        	textMessageCups = 'Cups: ' + cupsMessageType[cupsMessage]
        except:
		textMessageCups = 'Cups: Unknown (' + cupsMessage +')'
        print(textMessageCups)
        response["Status Code"] = statusMessage 
        response["Status"] = textMessageStatus+\n+textMessageWater+\n+textMessageStrength+\n+textMessageCups
	
	message = {"Message":response}
	
        myAWSIoTMQTTClient.publish("topic",json.dumps(message),0)
        return True
        
                
def customCallback(client, userdata, message):
    print("Received a new message: ")
    print(message.payload)
    print("from topic: ")
    print(message.topic)
    print("--------------\n\n")
    STATUS_OK = 0x00
    string = message.payload
    JSON=json.loads(string)
    try:
    	sock =socket.socket( socket.AF_INET, socket.SOCK_STREAM )    #open socket
    	sock.connect((address,port))                                #connect socket
    	sock.settimeout(1000)
    except:
        response = {}
        response["Status Code"] = "Not Connected"
        response["Status"] = "Smarter Is Not Connected to Network/Please Check The Conection"
	message = {"Message":response}
	myAWSIoTMQTTClient.publish("topic",json.dumps(message),0)
        print("Smarter Is Not Connected to Network/Please Check The Conection")
    

    #packet creation on command
    if(JSON["command"] == 51):  	                               #brewing
        if JSON["noofcups"] < 12 and JSON["noofcups"] > 0:
                #if JSON["type"] ==  
		data=bytearray([JSON["command"],JSON["noofcups"],JSON["strength"],0,JSON["type"],126])  
		sock.send(data)
		response=response_code(sock)
		print(response)
        else:
             response = {}
             response["Status Code"] = "INVALID VALUES"
             response["Status"] = "Please Enter No Of Cups In Between 1 To 12"
	     message = {"Message":response}
             myAWSIoTMQTTClient.publish("topic",json.dumps(message),0)
                 
    elif(JSON["command"] == 56):                                                         #configure 
        data=bytearray([JSON["command"],JSON["strength"],JSON["noofcups"],JSON["type"],0,126])
	sock.send(data)
        response=response_code(sock)
        print(response)
    elif(JSON["command"] == 53):                                                          #strength
	data=bytearray([JSON["command"],JSON["strength"],126])
	sock.send(data)
        response=response_code(sock)
        print(response)
    elif(JSON["command"] == 54):
	if JSON["noofcups"] < 12 and JSON["noofcups"] > 0:                               #no of cups   
		data=bytearray([JSON["command"],JSON["noofcups"],126])
		sock.send(data)
        	response=response_code(sock)
        	print(response)
	else:
                response = {}
             	response["Status Code"] = "INVALID VALUES"
             	response["Status"] = "Please enter no of cups between 1 and 12"
	     	message = {"Message":response}
             	myAWSIoTMQTTClient.publish("topic",json.dumps(message),0)
    elif(JSON["command"] == 62): 
	if JSON["warmtime"] > 5 and JSON["warmtime"] < 36: 
        	print JSON["command"],JSON["warmtime"]                                   #Enable Warming	                        
		data=bytearray([JSON["command"],JSON["warmtime"],126])
		sock.send(data)
        	response=response_code(sock)
		print()
	else:
                response = {}
             	response["Status Code"] = "INVALID VALUES"
             	response["Status"] = "Please Enter time between 5 and 36 min"
	     	message = {"Message":response}
             	myAWSIoTMQTTClient.publish("topic",json.dumps(message),0)
    elif(JSON["command"] == 74):                                                         #disable warming
        data=bytearray([JSON["command"],126])
	sock.send(data)
        response=response_code(sock)
        print(response)
    elif(JSON["command"] == 55):                                                         #start brewing  
        data=bytearray([JSON["command"],126])
	sock.send(data)
        response=response_code(sock)
        print(response)
    elif(JSON["command"] == 'status'):                          #getting status
        response=response_code1(sock)
        print(response)
    else:                                                       #close socket 
	sock.close()

def status_string( status ):
        if status == STATUS_OK:
            return 'OK'

        elif status == STATUS_ALREADY_BREWING:
            return 'ALREADY BREWING'

        elif status == STATUS_NO_CARAFFE:
            return 'NO CARAFFE'

        elif status == STATUS_INVALID_ARGS:
            return 'ONE OR MORE CONFIGURATION VALUES ARE INVALID'

        elif status == STATUS_NO_WATER:
            return 'NO WATER'

        elif status == STATUS_LOW_WATER:
            return 'LOW WATER LEVEL'
	else:
            return "0x%02x" % status


myAWSIoTMQTTClient.subscribe("topic_1",1,customCallback)
while True:
    time.sleep(1)
