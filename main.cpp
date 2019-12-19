/*
 * main.cpp
 *
 *  Created on: 12 Nov 2019
 *      Author: jinxluck
 */

#include<iostream>
#include<fstream>
#include<string.h>
#include<unistd.h>
#include<stdio.h>

using namespace std;

int main(void)
{
	cout << "program starting" << endl;

	FILE *fs;

	fs = fopen("/sys/devices/platform/ocp/4804c000.gpio/gpiochip1/gpio/gpio59/direction", "w");
	cout << "file opened" << endl;
	fseek(fs,0,SEEK_SET);
	fprintf(fs,"out");
	fclose(fs);


	cout << "direction set" << endl << endl;
	sleep(1);

	cout << "opening value setting" << endl;
	fs = fopen("/sys/devices/platform/ocp/4804c000.gpio/gpiochip1/gpio/gpio59/value", "w");
	fseek(fs,0,SEEK_SET);
	sleep(2);
	while(1)
	{
		fseek(fs,0,SEEK_SET);
		fprintf(fs,"1");
		cout << "on" << endl;
		sleep(1);
		fseek(fs,0,SEEK_SET);
		fprintf(fs,"0");
		cout << "off" << endl;
		sleep(1);
	}


	return 0;
}

