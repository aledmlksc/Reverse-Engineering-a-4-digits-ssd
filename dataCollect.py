import PySimpleGUI as sg
import serial

output = serial.Serial("COM3",9600)

def decode(data) :
	data_str_rev = ''.join(map(str,data))
	data_str=data_str_rev[::-1]
	return data_str.encode()

def devide(inp):

	if inp >= 1:
		units = round(inp%10) #units
	else : units=0

	if inp>=10:
		tens = round((inp%100 - inp%10)/10) #tens
	else : tens=0

	if inp>=100:
		hundreds = round((inp%1000 - (inp%100 - inp%10) - (inp%10))/100) #hundreds
	else: hundreds=0

	if inp>=1000:
		thousands = round((inp%10000  - ((inp%1000 - (inp%100 - inp%10) - (inp%10)))-((inp%100 - inp%10))-((inp%10)))/1000) #thousands
	else: thousands=0

	data = [units,tens,hundreds,thousands]
	
	
	return data


sg.theme('GreenTan')


layout =[
			[sg.Input()],
			[sg.Text('',justification = 'right' ,expand_x = True , pad = (10,20), key='-TEXT-' )],
			[sg.B('Clear', expand_x = True) ,sg.B('Enter' ,expand_x = True )],
		]

window = sg.Window('Input Data',layout)




while True:

	event , values = window.read()


	

	if event == sg.WIN_CLOSED:
		break

	if event == 'Enter':

		input_value=values[0]


		output_val=round(eval(input_value)) #do not accept strings , do not accept leading integers
		window['-TEXT-'].update(decode(devide(output_val)))
		output.write(decode(devide(output_val)))
			
		
		


	if event == 'Clear' :
		window['-TEXT-'].update('')
		output_val=0
		output.write(decode(devide(output_val)))


window.close()

