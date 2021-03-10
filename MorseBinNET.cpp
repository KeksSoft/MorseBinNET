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
String MorseBinNET::placeRequest(String address, String data1, String data2) {
	send(address, data1, data2);
	String senderAddress = "";
	String senderData1;
	String senderData2;
	int timeoutCounter = 0;
	int wrongAddressCounter = 0;
	while(senderAddress != address){
		String received = receive();
		if (received != "errWrongAddress" && received != "errTimeout") {
			senderAddress = received.substring(0,8);
			senderData1 = received.substring(8,16);
			senderData2 = received.substring(16,24);
		} else {
			if (received == "errTimeout"){
				timeoutCounter++;
				if(timeoutCounter >= 6){
					return "errTimeout";
				}
			}
			if (received == "errWrongAddress"){
				wrongAddressCounter++;
				if(wrongAddressCounter >= 20){
					return "errTimeout";
				}
			}
		}
	}
	String toBeReturnd = senderAddress + senderData1 + senderData2;
	return toBeReturnd;
}