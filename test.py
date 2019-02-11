from SmarterPackage import SmarterCoffee

s = SmarterCoffee("192.168.0.54")
status = s.get_coffee_machine_status()
print(status)


