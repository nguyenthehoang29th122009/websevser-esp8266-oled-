# websevser-esp8266-oled-
Regarding installing Arduino IDE, please refer to Google because it is too basic. After installation is complete, we integrate the esp8266 library into the arduino ide as follows:
Go to File→Preferences, go to the Additional Board Manager URLs textbox and add this link:

http://arduino.esp8266.com/stable/package_esp8266com_index.json

Click OK to accept

Next go to Tool→Board→Boards Manager

Wait a moment for the program to search. We scroll down and click on ESP8266 by ESP8266 Community, click on Install. Wait for the software to automatically download and install.
Webserver design
HTML language
HTML is the abbreviation for Hypertext Markup Language. It helps users create and structure elements in a website or application, dividing paragraphs, headings, links, blockquotes...

When working with HTML, we will use simple code structures (tags and attributes) to mark up the web page. For example, we can create a paragraph by placing text within the opening and closing text tags <p> and </p>

Please find out more for yourself.

Before going into programming, we will write the html code for the web server using the computer first. Introduce to you Sublime Text software. This is a text editor tool that I really like. The interface is beautiful, professional, and has a system. The command prompt system is very good! I will write demo html code on this software!

Go to File -> New to create a new file and save it with the extension .html, here I save the file with the name index.html
Web server in Access Point mode
In Access Point mode, I will let the wifi automatically emit wifi for other devices to connect to
After including the necessary library files, in line 3, I create a server object that operates on port 80.
Note: At the beginning and end of each line, add a double quote ' and all double quotes inside must be converted to single quotes '
Load program:
3.3V	3.3V
GND	GND
RX	TX
TX	RX
CH_PD	3.3V
GPIO0	GND
After connecting as above, we can then plug the uart module into the computer

Go to Tool -> Port to select the corresponding COM port
Then press the download button
After loading the code, remove GPIO0 from the ground and reset the esp8266 (re-apply power or click GND on the reset pin).

Now take out the computer, connect it to the ESP8266 WiFI wifi with password 12345678
Then open the browser and type the server's default address 192.168.4.1

We have results
Web server in Station mode
In station mode, the esp8266 will no longer broadcast wifi but access wifi at home
In which yourSSID and YourPass are your home wifi account and password!

OK now the esp8266 will automatically connect to your home wifi and print out the IP address of the form 192.168.1.xxx This is the IP address that your network modem allocates to it, you just need to type the ip address into the browser. web is the website as above will appear
The ESP8266 and the access device must be connected to the same wifi network
AT PORT
We can access the esp8266 server through the home LAN, however, it is only a server that operates locally in the home, if you want to go out and control it, you need to bring it in. out into the vast world of the internet.

Local IP and Public IP
You can see in the demo video above, my home network modem has allocated the esp8266 the address 192.168.1.11, this is the local IP that the modem has allocated to the esp8266 to distinguish it from other devices on the same wifi network. (Phones, laptops, smart TVs are all given their own IP, no one shares it with anyone else)
The regular wifi modem itself will take the address 192.168.1.1 or 192.168.0.1 as the default local IP! If it is registered for the internet with the network operator (Viettel, Vina...) - meaning there is a fiber optic cable attached to it - then the network provider will provide the modem with a public IP, this is the unique IP address to distinguish the modem. Your home with billions of internet devices around the world. Thus, all devices on the LAN that want to communicate with the outside must go through the modem.
