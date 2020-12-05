#include "Arduino.h"
#include "MorseBinNET.h"
#include "MorseBin.h"
MorseBinNET::MorseBinNET(string adress, int pinTransmit,int pinReceive){
	_pinTransmit = pinTransmit;
	_pinReceive = pinReceive;
	_address = adress;
	pinMode(_pinTransmit,OUTPUT);
	pinMode(_pinReceive,INPUT);
}
MorseBinNET::void send(string address, string data1, string data2){
	MBSendByte(address);
	MBSendByte(_address);
	MBSendByte(data1);
	MBSendByte(data2);	
}
MorseBinNET::string receive(){
	string incomingAddress = MBReceive(_pinReceive);
	if(incomingAddress=="errTimeout"){
		return "errTimeout"
	}
	string senderAddress = MBReceive(_pinReceive);
	if(senderAddress=="errTimeout"){
		return "errTimeout"
	}
	string data1 = MBReceive(_pinReceive);
	if(data1=="errTimeout"){
		return "errTimeout"
	}
	string data2 = MBReceive(_pinReceive);
	if(data2=="errTimeout"){
		return "errTimeout"
	}
	if (incomingAddress==_address){
		string dataoutput = {senderAddress,data1,data2}
		return dataoutput;
	}
	else{
		return "errWrongAddress"
	}
	
}