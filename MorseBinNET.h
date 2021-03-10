#ifndef MorseBinNET_h
#define MorseBinNET_h
#include "Arduino.h"
#include "MorseBin.h"
	class MorseBinNET {
		public:
			MorseBinNET(String address, int pinTransmit,int pinReceive);
			void send(String address, String data1, String data2);
			String receive();
			String placeRequest(String address, String data1, String data2);
			//String answerRequest(String data1, String data2)
		private:
			String _address;
			int _pinTransmit;
			int _pinReceive;
	};
#endif
