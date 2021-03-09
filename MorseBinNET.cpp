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
	int securityTimer = 0;
	while(securityTimer < 15){
		securityTimer++;
		if(digitalRead(_pinReceive) == HIGH){
			securityTimer = 0;
		}
		delay(1);
	}
	MBSendByte(address,_pinTransmit);
	MBSendByte(_address,_pinTransmit);
	MBSendByte(data1,_pinTransmit);
	MBSendByte(data2,_pinTransmit);	
}
String MorseBinNET::receive(){
	String receivedOutput = "";
	String incomingAddress = MBReceive(_pinReceive);
	if(incomingAddress=="errTimeout"){
		return "errTimeout";
	}
	String senderAddress = MBReceive(_pinReceive);
	if(senderAddress=="errTimeout"){
		return "errTimeout";
	}
	String data1 = MBReceive(_pinReceive);
	if(data1=="errTimeout"){
		return "errTimeout";
	}
	String data2 = MBReceive(_pinReceive);
	if(data2=="errTimeout"){
		return "errTimeout";
	}
	if (incomingAddress==_address){
		receivedOutput = senderAddress + data1 + data2;
		return receivedOutput;
	}
	else{
		return "errWrongAddress";
	}
}