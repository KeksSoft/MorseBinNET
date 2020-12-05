#ifndef MorseBinNET_h
#define MorseBinNET_h
#include "Arduino.h"
#include "MorseBin.h"
	class MorseBinNET {
		public:
			MorseBinNET(String address, int pinTransmit,int pinReceive);
			void send(String address, String data1, String data2);
			string receive();
			//string placeRequest(String address, String data1, String data2);
			//string answerRequest(String data1, String data2)
		private:
			String _address;
			int _pinTransmit;
			int _pinReveive;
	};

#endif
