/*Import this produced file as raw data using Audacity with settings:

  Encoding:  Unsigned 8-bit PCM
Byte order:  Little-endian
  Channels:  1 Channel (Mono)

Then export as mp3.   */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	out_stream.open("untitled.raw");
	//Writes silence.
	for(int a = 0; a < 40000; a++) {out_stream.put(127);}
	
	//Number of bytes to produce (repeats this pattern n times, currently set to 1kB.)
	for(int n = 0; n < 1000; n++)
	{	out_stream.put(-118); for(int a = 0; a < 19; a++) {out_stream.put(127);} //Spike, long  wait = 0
		out_stream.put(-118); for(int a = 0; a < 19; a++) {out_stream.put(127);} //Spike, long  wait = 0
		out_stream.put(-115); for(int a = 0; a <  9; a++) {out_stream.put(127);} //Spike, short wait = 1
		out_stream.put(-118); for(int a = 0; a < 19; a++) {out_stream.put(127);} //Spike, long  wait = 0
		out_stream.put(-115); for(int a = 0; a <  9; a++) {out_stream.put(127);} //Spike, short wait = 1
		out_stream.put(-118); for(int a = 0; a < 19; a++) {out_stream.put(127);} //Spike, long  wait = 0
		out_stream.put(-115); for(int a = 0; a <  9; a++) {out_stream.put(127);} //Spike, short wait = 1
		out_stream.put(-115); for(int a = 0; a <  9; a++) {out_stream.put(127);} //Spike, short wait = 1
	}
	
	//Writes one '0' bit at the end to signify end-of-stream in RICIN 3.
	out_stream.put(-118); for(int a = 0; a < 19; a++) {out_stream.put(127);} //Spike, long wait =  0
	
	//Writes silence.
	for(int a = 0; a < 10000; a++) {out_stream.put(127);}
	out_stream.close();
}
