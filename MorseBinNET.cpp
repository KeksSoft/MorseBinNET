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
void MorseBinNET::receive(){
	String incomingAddress = MBReceive(_pinReceive);
	if(incomingAddress=="errTimeout"){
		MBNETerrorlevel[0]="errTimeout";
	}
	String senderAddress = MBReceive(_pinReceive);
	if(senderAddress=="errTimeout"){
		MBNETerrorlevel[0]="errTimeout";
	}
	String data1 = MBReceive(_pinReceive);
	if(data1=="errTimeout"){
		MBNETerrorlevel[0]="errTimeout";
	}
	String data2 = MBReceive(_pinReceive);
	if(data2=="errTimeout"){
		MBNETerrorlevel[0]="errTimeout";
	}
	if (incomingAddress==_address){
		MBNETerrorlevel[0] = senderAddress;
		MBNETerrorlevel[1] = data1;
		MBNETerrorlevel[2] = data2;
	}
	else{
		MBNETerrorlevel = {"errWrongAddress"};
	}
}