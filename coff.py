import socket 
address='192.168.0.54'
port = 2081
STR_DIVIDER = "\x7d"
STATUS_OK = 0x00                
STATUS_ALREADY_BREWING = 0x01
STATUS_INVALID_ARGS = 0x04
STATUS_NO_CARAFFE = 0x06
STATUS_NO_WATER = 0x05
STATUS_LOW_WATER = 0x07
STATUS_FILTER_NOCARAFE=0x20
STATUS_GRIND_NOCARAFE=0x22
STATUS_GRIND_NOWATER=0x23
STATUS_FILTER_DONE=0x45
STATUS_GRIND_DONE=0x47
STATUS_BOILING=0x53
STATUS_FILTERWITHHOTPLATE_NOCARAFE=0x60
STATUS_GRINDWITHHOTPLATE_NOCARAFE=0x62
STATUS_GRINDWITHHOTPLATE_WITHCARAFE=0x63
STATUS_DESCALING=0x51

def status_string(status):
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
	elif status == STATUS_FILTER_NOCARAFE:
            return 'FILTER_NOCARAFE' 
	
	elif status == STATUS_GRIND_NOCARAFE:
            return 'GRIND_NOCARAFE' 
	
	elif status == STATUS_GRIND_NOWATER:
            return 'GRIND_NOWATER' 
	
	elif status == STATUS_FILTER_DONE:
            return 'FILTER_DONE' 
	
	elif status == STATUS_GRIND_DONE:
            return 'GRIND_DONE'  
	
	        
	
	elif status == STATUS_FILTERWITHHOTPLATE_NOCARAFE:
            return 'FILTER_WITH_HOT_PLATE_NO_CARAFE'  	
	
	elif status == STATUS_GRINDWITHHOTPLATE_NOCARAFE:
            return 'GRIND_WITH_HOT_PLATE_NO_CARAFE' 

	elif status == STATUS_GRINDWITHHOTPLATE_WITHCARAFE:
            return 'GRIND_WITH_HOT_PLATE_WITHCARAFE' 
	
	elif status == STATUS_DESCALING:
	    return 'DESCALING'
        
	else:
            return "0x%02x" % status


def response_code(sock):
        size = ord(sock.recv(1)[0])
        status = ord( sock.recv(1)[0] )
        data = sock.recv( size - 2 )
        print(data)

        if status != STATUS_OK:
            print status
            print "!%s" % status_string(status)
            return False
        else:
            print status
            print "!%s" % status_string(status)
            return True

sock = socket.socket( socket.AF_INET, socket.SOCK_STREAM )   #open socket
sock.connect((address,port))                                #connect socket
sock.settimeout(5)

data=bytearray([51,1,1,3,1,126])  
sock.send(data)
response=response_code(sock)
print(response)
sock.close()



