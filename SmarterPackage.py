import socket
from array import array

 #Reponse Codes for Commands   
STATUS_OK = 0x00
STATUS_ALREADY_BREWING = 0x01
STATUS_INVALID_ARGS = 0x04
STATUS_NO_CARAFFE = 0x05
STATUS_NO_WATER = 0x06
STATUS_LOW_WATER = 0x07

   # Commands for Coffee
CMD_START_BREWING = 51
CMD_SET_STRENGTH = 53
CMD_BREW = 55
CMD_SET_CUPS     = 54
CMD_SET_CONFIG   = 56
CMD_ENABLE_WARMING = 62
CMD_DISABLE_WARMING = 74
CMD_END = 126
 
   #Limitations
MAX_NO_OF_CUPS = 12
MIN_NO_OF_CUPS = 1
MIN_WARM_TIME = 5
MAX_WARM_TIME = 35
ZERO_WARM_TIME = 0
MAX_WARM_BREW = 30
MIN_STRENGTH_VALUE = 0
MAX_STRENGTH_VALUE = 2
TYPE_GRIND = 1
TYPE_FILTER = 0


#Exceptions For Coffee Machine limitations

class Error(Exception):
   """Base class for other exceptions"""
   pass
  
class IPAddress(Error):
      "Raised When Ip Address Is not Mentioned"

class CommandValueError(Error):
      "Raised When Command Value Is InValid"

class WarmTimeValueTooSmall(Error):
      "Raised When Coffee Warm Time Value Is Too Low"

class WarmTimeValueTooHigh(Error):
      "Raised When Coffee Warm Time Value Is Too High"

class NoOfCupsValueTooSmall(Error):
      "Raised When NoOfCups Value Is Too Low"

class NoOfCupsValueTooHigh(Error):
      "Raised When NoOfCups Value Is Too High"

class CoffeeStrengthValueTooSmall(Error):
      "Raised When CoffeeStrength Value Is Too Low"

class CoffeeStrengthValueTooHigh(Error):
      "Raised When CoffeeStrength Value Is Too High"

class CoffeeTypeValueError(Error):
      "Raised When Coffee Type Value Is Invalid"


class SmarterCoffee:
      # Commands for Coffee
   CMD_START_BREWING = 51
   CMD_SET_STRENGTH = 53
   CMD_BREW = 55
   CMD_SET_CUPS     = 54
   CMD_SET_CONFIG   = 56
   CMD_ENABLE_WARMING = 62
   CMD_DISABLE_WARMING = 74
   CMD_END = 126
 #Reponse Codes for Commands   
   STATUS_OK = 0x00
   STATUS_ALREADY_BREWING = 0x01
   STATUS_INVALID_ARGS = 0x04
   STATUS_NO_CARAFFE = 0x05
   STATUS_NO_WATER = 0x06
   STATUS_LOW_WATER = 0x07

   #Constructor
   def __init__( self, address = "", port = 2081 ):
        try:
		self.address = address
		self.port = port
		if address == "":
		    raise IPAddress("Please initialize with IP Address Of Coffee Machine")
		self.sock = socket.socket( socket.AF_INET, socket.SOCK_STREAM )
		self.sock.settimeout(10)
        except IPAddress as e :
                               print(e)
        
   #Response Codes For Commands
   def returning_status_codes(self ,status ):
        if status == self.STATUS_OK:
            return 'OK'

        elif status == self.STATUS_ALREADY_BREWING:
            return 'ALREADY BREWING'

        elif status == self.STATUS_NO_CARAFFE:
            return 'NO CARAFFE'

        elif status == self.STATUS_INVALID_ARGS:
            return 'ONE OR MORE CONFIGURATION VALUES ARE INVALID'

        elif status == self.STATUS_NO_WATER:
            return 'NO WATER'

        elif status == self.STATUS_LOW_WATER:
            return 'LOW WATER LEVEL'

        else:
            return "0x%02x" % status

   #Response Code From Coffee machine
   def __consume_response_code( self ):
        size = ord( self.sock.recv(1)[0] )
        status = ord( self.sock.recv(1)[0] )
        data = self.sock.recv( size - 2 )
        self.sock.close()

        if status != self.STATUS_OK:
            #print (status)
            #print "! %s" % self.returning_status_codes(status)
            return self.returning_status_codes(status)
        else:
            #print (status)
            return self.returning_status_codes(status)
   
   #Getting Response Codes Of status Of coffee Machine
   def machine_status_code( self ):
       data = self.sock.recv( 4096 )
       self.sock.close()        
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
       deviceMessage  = b[0]
       statusMessage = b[1]
       waterLevelMessage = b[2]
       strengthMessage = b[4]
       cupsMessage = b[5]
       try:
        		textMessageStatus = 'Status: ' + statusMessageType[statusMessage]
       except:
			textMessageStatus = 'Status: Unknown (' + statusMessage +')'
        
       try:
          textMessageWater = 'Water Level: ' + waterLevelMessageType[waterLevelMessage]
       except:
          textMessageWater = 'Water Level: Unknown (' + waterLevelMessage +')'
        
       try:
      	  textMessageStrength = 'Strength: ' + strengthMessageType[strengthMessage]
       except:
        	textMessageStrength = 'Strength: Unknown (' + strengthMessage +')'
       try:
        	textMessageCups = 'Cups: ' + cupsMessageType[cupsMessage]
       except:
		textMessageCups = 'Cups: Unknown (' + cupsMessage +')'
  
       return (textMessageStatus+" "+textMessageWater+" "+textMessageStrength+" "+textMessageCups)


   #Function to set no of cups
   def set_cup_amount( self, n ):
        try:    
                if n < MIN_NO_OF_CUPS:
                   raise NoOfCupsValueTooSmall("The minimum No Of Cups is One")

                if n > MAX_NO_OF_CUPS:
                   raise NoOfCupsValueTooHigh("The maximum No of Cups is 12")

		self.sock.connect( ( self.address, self.port ) )
		packet = bytearray([ self.CMD_SET_CUPS, n, self.CMD_END ])
		self.sock.send(packet)
		return self.__consume_response_code()

        except NoOfCupsValueTooSmall as e:
                print(e)

        except NoOfCupsValueTooHigh as e:
                print(e)

        except WrongNumberOfArguments as e:
               print(e)

        except:
                print("Please Check The Connection Of Coffee Machine And System") 

   #function to set the strength of coffee
   def set_strength( self, n ):
        try:
                if n < MIN_STRENGTH_VALUE:
                   raise CoffeeStrengthValueTooSmall("The Minimum Strength Of Coffee Is zero")

                if n > MAX_STRENGTH_VALUE:
                   raise CoffeeStrengthValueTooHigh("The maximum Strenght of Coffee Is 2")

		self.sock.connect( ( self.address, self.port ) )
		packet = bytearray([ self.CMD_SET_STRENGTH, n, self.CMD_END ])
		self.sock.send(packet)
		return self.__consume_response_code()

        except CoffeeStrengthValueTooSmall as e:
               print(e)

        except CoffeeStrengthValueTooHigh as e:
               print(e)

        except WrongNumberOfArguments as e:
               print(e)

        except:
               print("Please Check The Connection Of Coffee Machine And System")

   #function to set configuration the coffee machine
   def set_config( self, cups = 5, strength = 2, use_grind = 1, keepwarm_time = 0 ):
       try:
		if cups < MIN_NO_OF_CUPS:
		           raise NoOfCupsValueTooSmall("The minimum No Of Cups is One")

		if cups > MAX_NO_OF_CUPS:
		           raise NoOfCupsValueTooHigh("The maximum No of Cups is 12")

                if strength < MIN_STRENGTH_VALUE:
                   raise CoffeeStrengthValueTooSmall("The Minimum Strength Of Coffee Is zero")

                if strength > MAX_STRENGTH_VALUE:
                   raise CoffeeStrengthValueTooHigh("The maximum Strenght of Coffee Is 2")
 
                if use_grind != TYPE_GRIND and use_grind != TYPE_FILTER:
                   raise CoffeeTypeValueError("Please Enter The Coffee Type Value 1 for Beans or 0 For Filter")

                if keepwarm_time !=ZERO_WARM_TIME and keepwarm_time < MIN_WARM_TIME:
                   raise WarmTimeValueTooSmall("Please Enter The Warm Time Either Zero or Between 5 To 35 in Minutes")

                if keepwarm_time > MAX_WARM_TIME:
                   raise WarmTimeValueTooHigh("Please Enter The Warm Time Either Zero or Between 5 To 35 in Minutes")

		self.sock.connect( ( self.address, self.port ) )
		packet = bytearray([ self.CMD_SET_CONFIG, strength, cups, use_grind, keepwarm_time, self.CMD_END ])
		self.sock.send(packet)
		return self.__consume_response_code()

       except NoOfCupsValueTooSmall as e:
                 print(e)

       except NoOfCupsValueTooHigh as e:
                 print(e)

       except CoffeeStrengthValueTooSmall as e:
                 print(e)

       except CoffeeStrengthValueTooHigh as e:
                 print(e)
 
       except WarmTimeValueTooSmall as e:
                 print(e)
       
       except CoffeeTypeValueError as e:
                 print(e)

       except WarmTimeValueTooHigh as e:
                 print(e)
       except:
             print("Please Check The Connection Of Coffee Machine And System")   

   #function to warm the careffe
   def enable_warming( self, minutes = 5 ):
        try:
                if minutes < MIN_WARM_TIME:
                   raise WarmTimeValueTooSmall("Please Enter The Warm Time Between 5 To 35 in Minutes")

                if minutes > MAX_WARM_TIME:
                   raise WarmTimeValueTooHigh("Please Enter The Warm Time Between 5 To 35 in Minutes")
                
		self.sock.connect( ( self.address, self.port ) )
		packet = bytearray([ self.CMD_ENABLE_WARMING, minutes, self.CMD_END ])
		self.sock.send(packet)
		return self.__consume_response_code()

        except WarmTimeValueTooSmall as e:
               print(e)

        except WarmTimeValueTooHigh as e:
               print(e)

        except:
               print("Please Check The Connection Of Coffee Machine And System")
         

   #function to stop warming the kareffe
   def disable_warming( self ):
        try:
		self.sock.connect( ( self.address, self.port ) )
		packet = bytearray([ self.CMD_DISABLE_WARMING, self.CMD_END ])
		self.sock.send(packet)
		return self.__consume_response_code()
        except:
                print("Please Check The Connection Of Coffee Machine And System")
   
   #function to start brewing
   def start_brewing( self ,cups = 5, strength = 2, use_grind = 1, keepwarm_time = 0 ):
       try:
                if cups < MIN_NO_OF_CUPS:
		           raise NoOfCupsValueTooSmall("The minimum No Of Cups is One")

		if cups > MAX_NO_OF_CUPS:
		           raise NoOfCupsValueTooHigh("The maximum No of Cups is 12")

                if strength < MIN_STRENGTH_VALUE:
                   raise CoffeeStrengthValueTooSmall("The Minimum Strength Of Coffee Is zero")

                if strength > MAX_STRENGTH_VALUE:
                   raise CoffeeStrengthValueTooHigh("The maximum Strenght of Coffee Is 2")
 
                if use_grind != TYPE_GRIND and use_grind != TYPE_FILTER :
                   raise CoffeeTypeValueError("Please Enter The Coffee Type Value 1 for Beans or 0 For Filter")

                if keepwarm_time !=ZERO_WARM_TIME and keepwarm_time < MIN_WARM_TIME:
                   raise WarmTimeValueTooSmall("Please Enter The Warm Time Either Zero or Between 5 To 30 in Minutes")

                if keepwarm_time > MAX_WARM_BREW:
                   raise WarmTimeValueTooHigh("Please Enter The Warm Time Either Zero or Between 5 To 30 in Minutes")
     
		self.sock.connect( ( self.address, self.port ) )
		packet = bytearray([ self.CMD_START_BREWING, cups, strength, keepwarm_time, use_grind, self.CMD_END ])
		self.sock.send(packet)
		return self.__consume_response_code()
       
       except NoOfCupsValueTooSmall as e:
                 print(e)

       except NoOfCupsValueTooHigh as e:
                 print(e)

       except CoffeeStrengthValueTooSmall as e:
                 print(e)

       except CoffeeStrengthValueTooHigh as e:
                 print(e)
 
       except WarmTimeValueTooSmall as e:
                 print(e)
       
       except WarmTimeValueTooHigh as e:
                 print(e)

       except CoffeeTypeValueError as e:
                 print(e)

       except:
             print("Please Check The Connection Of Coffee Machine And System")   

       

   #function to start brewing with preconfigured
   def start_brewing_preconfigured( self  ):
        try:            
		self.sock.connect( ( self.address, self.port ) )
		packet = bytearray([ self.CMD_BREW, self.CMD_END ])
		self.sock.send(packet)
		return self.__consume_response_code()
                

        except:
              print("Please Check The Connection Of Coffee Machine And System") 

   #function to get status of the coffee machine
   def get_coffee_machine_status(self ):
       try:
	       self.sock.connect( ( self.address, self.port ) )
	       return self.machine_status_code()

       except:
             print("Please Check The Connection Of Coffee Machine And System")
