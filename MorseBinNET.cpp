#include "Arduino.h"
#include "MorseBinNET.h"
#include "MorseBin.h"
MorseBinNET::MorseBinNET(String address, int pinTransmit,int pinReceive){
	_pinTransmit = pinTransmit;
	_pinReceive = pinReceive;
	_address = address;
	pinMode(_pinTransmit,OUTPUT);
	pinMode(_pinReceive,INPUT);
}
void MorseBinNET::send(String address, String data1, String data2){
	MBSendByte(address,_pinReceive);
	MBSendByte(_address,_pinReceive);
	MBSendByte(data1,_pinReceive);
	MBSendByte(data2,_pinReceive);	
}
char** MorseBinNET::receive(){
	String incomingAddress = MBReceive(_pinReceive);
	if(incomingAddress=="errTimeout"){
		static char *dataoutput[] = {"errTimeout"};
		return dataoutput;
	}
	String senderAddress = MBReceive(_pinReceive);
	if(senderAddress=="errTimeout"){
		static char *dataoutput[] = {"errTimeout"};
		return dataoutput;
	}
	String data1 = MBReceive(_pinReceive);
	if(data1=="errTimeout"){
		static char *dataoutput[] = {"errTimeout"};
		return dataoutput;
	}
	String data2 = MBReceive(_pinReceive);
	if(data2=="errTimeout"){
		static char *dataoutput[] = {"errTimeout"};
		return dataoutput;
	}
	if (incomingAddress==_address){
		static char *dataoutput[] = {senderAddress, data1, data2};
		return dataoutput;
	}
	else{
		static char *dataoutput[] = {"errWrongAddress"};
		return dataoutput;
	}
}