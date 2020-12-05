#ifndef MorseBinNET_h
#define MorseBinNET_h
#include "Arduino.h"
#include "MorseBin.h"
	class MorseBinNET {
		public:
		MorseBinNET(string adress, int pinTransmit,int pinReceive);
		void send(string address, string data1, string data2);
		string receive();
		//string placeRequest(string address, string data1, string data2);
		//string answerRequest(string data1, string data2)
	}

#endif
