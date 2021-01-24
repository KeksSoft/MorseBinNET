# MorseBinNET
MorseBinNet is a networked version of MorseBin. No adresses are reserved, so you can just pick one! In addition, it uses two pins, one for transmitting, and one for receiving. MorseBin is MANDATORY! if you have MorseBin not installed and "#included" it, MorseBinNet will not work! in other words, MorseBin is a dependency!
# MorseBinNET(String address, int pinTransmit,int pinReceive);
  This is the constructor. if you're new to object-oriented programming, i would recommend watching a short tutorial on how to use an object. put the adress you're going to use in "adress". Important: This NEEDS to be a MorseBin formatted string!
  # void send(String address, String data1, String data2);
  this is a method of the class MorseBinNet. it sends your data to the address you specified in the first parameter, which NEEDS to be a MorseBin formatted string. "data1" and "data2" are also MorseBin formatted strings, which is the data you're going to send.
