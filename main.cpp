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
	//programmet kan tage lidt tid da der er sleep kommandoer
	//cout linjerne er for at se at programmet kører

	cout << "program starting" << endl;

	//file pointer
	FILE *fs;

	//absolut sti til gpio registret der bliver brugt
	fs = fopen("/sys/devices/platform/ocp/4804c000.gpio/gpiochip1/gpio/gpio59/direction", "w");
	cout << "file opened" << endl;

	//fseek for at sætte pointeren tilbage til start i filen
	fseek(fs,0,SEEK_SET);

	//fprintf for at sætte en ny værdi ind i registret/filen
	fprintf(fs,"out");

	//fclose for at gøre den klar til næste fil der skal sættes
	fclose(fs);


	cout << "direction set" << endl << endl;
	sleep(1);

	cout << "opening value setting" << endl;
	fs = fopen("/sys/devices/platform/ocp/4804c000.gpio/gpiochip1/gpio/gpio59/value", "w");
	fseek(fs,0,SEEK_SET);
	sleep(2);
	while(1)
	{
		//for hver ny værdi der bliver indsat ind i den samme fil,
		//skal pointeren sættes tilbage til starten af filen med evt. fseek

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

